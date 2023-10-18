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

#include "sql/executor/update_table_executor.h"

#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/stmt/update_table_stmt.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/db/db.h"

RC UpdateTableExecutor::execute(SQLStageEvent *sql_event)
{
  // Stmt *stmt = sql_event->stmt();
  // Session *session = sql_event->session_event()->session();
  // ASSERT(stmt->type() == StmtType::UPDATE_TABLE, 
  //        "update table executor can not run this command: %d", static_cast<int>(stmt->type()));

  // UpdateTableStmt *update_table_stmt = static_cast<UpdateTableStmt *>(stmt);

  // const char *table_name = update_table_stmt->table_name().c_str();
  // RC rc = session->get_current_db()->update_table(table_name, attribute_count, update_table_stmt->attr_infos().data());

  // return rc;
  return RC::SUCCESS;
}