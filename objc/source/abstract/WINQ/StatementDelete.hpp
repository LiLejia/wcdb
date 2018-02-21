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

#ifndef StatementDelete_hpp
#define StatementDelete_hpp

#include <WINQ/Describable.hpp>
#include <WINQ/Statement.hpp>

namespace WCDB {

class StatementDelete : public CRUDStatementWithLang<lang::DeleteSTMT> {
public:
    StatementDelete &with(const WithClause &withClause);
    StatementDelete &deleteFrom(const QualifiedTableName &qualifiedTableName);
    StatementDelete &where(const Expression &condition);
    StatementDelete &orderBy(const OrderingTerm &orderingTerm);
    StatementDelete &orderBy(const std::list<OrderingTerm> &orderingTerms);
    StatementDelete &limit(const Expression &from, const Expression &to);
    StatementDelete &limit(const Expression &limit);
    StatementDelete &offset(const Expression &offset);
    virtual Type getType() const override;
};

} // namespace WCDB

#endif /* StatementDelete_hpp */