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

#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field_meta.h"

class Table;
class FilterStmt;

/**
 * @brief 更新语句
 * @ingroup Statement
 */
class UpdateStmt : public Stmt 
{
public:
  UpdateStmt() = default;

  //插入数据需要表，插入的值即可
  //UpdateStmt(Table *table, Value *values, int value_amount);

  //更新表需要表名、字段、更改的值以及过滤的条件
  UpdateStmt(Table *table, const FieldMeta *fieldmeta, const Value *values, FilterStmt *filter_stmt);

public:
  static RC create(Db *db, const UpdateSqlNode &update_sql, Stmt *&stmt);

public:
  Table *table() const
  {
    return table_;
  }
  const FieldMeta *fieldmeta() const
  {
    return fieldmeta_;
  }
  const Value *values() const
  {
    return values_;
  }
  FilterStmt *filter_stmt() const
  {
    return filter_stmt_;
  }
  StmtType type() const override
  {
    return StmtType::UPDATE;
  }

private:
  //表名、字段、更改的值以及过滤的条件
  Table *table_ = nullptr;
  const FieldMeta *fieldmeta_= nullptr;
  const Value *values_ = nullptr;
  FilterStmt *filter_stmt_ = nullptr;
};
