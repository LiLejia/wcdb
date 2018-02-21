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

#ifndef ResultColumn_hpp
#define ResultColumn_hpp

#include <WINQ/Describable.hpp>

namespace WCDB {

class ResultColumn : public DescribableWithLang<lang::ResultColumn> {
public:
    static const ResultColumn All;
    static ResultColumn AllInTable(const std::string &tableName);
    ResultColumn(const Expression &expression);
    ResultColumn &as(const std::string &columnAlias);

protected:
    ResultColumn(const lang::ResultColumn::Type &type);
    ResultColumn(const std::string &tableName);
};

} // namespace WCDB

#endif /* ResultColumn_hpp */