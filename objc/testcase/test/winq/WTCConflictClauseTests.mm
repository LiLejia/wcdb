/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "WTCWINQTestCase.h"

@interface WTCConflictClauseTests : WTCWINQTestCase

@end

@implementation WTCConflictClauseTests

- (void)testConflictClause
{
    WINQAssertEqual(WCDB::TableConstraint(self.class.constraintName)
                        .withPrimaryKey(self.class.indexedColumn)
                        .onConflict(WCDB::ConflictClause::Rollback),
                    @"CONSTRAINT testConstraint PRIMARY KEY(testColumn) ON CONFLICT ROLLBACK");

    WINQAssertEqual(WCDB::TableConstraint(self.class.constraintName)
                        .withPrimaryKey(self.class.indexedColumn)
                        .onConflict(WCDB::ConflictClause::Abort),
                    @"CONSTRAINT testConstraint PRIMARY KEY(testColumn) ON CONFLICT ABORT");

    WINQAssertEqual(WCDB::TableConstraint(self.class.constraintName)
                        .withPrimaryKey(self.class.indexedColumn)
                        .onConflict(WCDB::ConflictClause::Fail),
                    @"CONSTRAINT testConstraint PRIMARY KEY(testColumn) ON CONFLICT FAIL");

    WINQAssertEqual(WCDB::TableConstraint(self.class.constraintName)
                        .withPrimaryKey(self.class.indexedColumn)
                        .onConflict(WCDB::ConflictClause::Ignore),
                    @"CONSTRAINT testConstraint PRIMARY KEY(testColumn) ON CONFLICT IGNORE");

    WINQAssertEqual(WCDB::TableConstraint(self.class.constraintName)
                        .withPrimaryKey(self.class.indexedColumn)
                        .onConflict(WCDB::ConflictClause::Replace),
                    @"CONSTRAINT testConstraint PRIMARY KEY(testColumn) ON CONFLICT REPLACE");
}

@end