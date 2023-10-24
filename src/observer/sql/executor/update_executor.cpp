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
// Created by Wangyunlai on 2023/6/13.
//

#include "sql/executor/update_executor.h"

#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/stmt/update_stmt.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/db/db.h"

RC UpdateTableExecutor::execute(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  // Stmt *stmt = sql_event->stmt();
  // Session *session = sql_event->session_event()->session();
  // ASSERT(stmt->type() == StmtType::UPDATE, 
  //        "update table executor can not run this command: %d", static_cast<int>(stmt->type()));

  // UpdateStmt *update_stmt = static_cast<UpdateStmt *>(stmt);

  // Table *table = update_stmt->table();
  // const FieldMeta *fieldmeta = update_stmt->fieldmeta();
  // const Value *values = update_stmt->values();
  // std::vector<ConditionSqlNode> conditions = update_stmt->conditions();
  // rc = table->update_record(table,fieldmeta,values,conditions);
  return rc;
}