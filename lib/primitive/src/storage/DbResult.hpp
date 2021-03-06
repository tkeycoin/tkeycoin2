//  Copyright (c) 2017-2019 Tkeycoin Dao. All rights reserved.
//  Copyright (c) 2019-2020 TKEY DMCC LLC & Tkeycoin Dao. All rights reserved.
//  Website: www.tkeycoin.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//


// DbResult.hpp


#pragma once

#include "DbRow.hpp"

class DbResult
{
public:
	DbResult(DbResult&&) noexcept = delete; // Move-constructor
	DbResult(const DbResult&) = delete; // Copy-constructor
	DbResult& operator=(DbResult&&) noexcept = delete; // Move-assignment
	DbResult& operator=(const DbResult&) = delete; // Copy-assignment

	DbResult() = default; // Default-constructor
	virtual ~DbResult() = default; // Destructor

	virtual bool fetchRow(DbRow& row) = 0;
};
