/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_table_stmt.h"
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

// UpdateStmt::UpdateStmt(Table *table, Value *values, int value_amount)
//     : table_(table), values_(values), value_amount_(value_amount)
// {}

// UpdateStmt::UpdateStmt(Table *table, FieldMeta *fieldmeta, Value *values, std::vector<ConditionSqlNode> conditions)
//     : table_(table),fieldmeta_(fieldmeta), values_(values),conditions_(conditions)
// {}

UpdateStmt::UpdateStmt(Table *table,const FieldMeta *fieldmeta,const Value *values,std::vector<ConditionSqlNode> conditions)
    : table_(table),fieldmeta_(fieldmeta), values_(values), conditions_(conditions)
{}

RC UpdateStmt::create(Db *db, const UpdateSqlNode &update, Stmt *&stmt)
{
  const char *table_name = update.relation_name.c_str();
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  //无序映射，将表名和表插入到table_map中，方便接下来查找表
  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  //找字段
  const char *field_name = update.attribute_name.c_str();
  const FieldMeta *field_meta = table->table_meta().field(field_name);
   if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
  }

  //创建过滤器，过滤不符合where后面条件的选项
  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(
      db, table, &table_map, update.conditions.data(), static_cast<int>(update.conditions.size()), filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  std::vector<ConditionSqlNode> conditions = update.conditions;
  const Value *values = &(update.value);

  stmt = new UpdateStmt(table, field_meta, values, conditions);
  return RC::SUCCESS;
}
