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


// MysqlResult.hpp


#pragma once


#include "../DbResult.hpp"
#include "MysqlRow.hpp"

#include <mysql.h>

class MysqlResult final : public DbResult
{
private:
	MYSQL_RES* _data;

public:
	MysqlResult(const MysqlResult&) = delete;
	MysqlResult& operator=(const MysqlResult&) = delete;
	MysqlResult(MysqlResult&&) noexcept = delete;
	MysqlResult& operator=(MysqlResult&&) noexcept = delete;

	MysqlResult()
	: _data(nullptr)
	{
	}

	~MysqlResult() override
	{
		mysql_free_result(_data);
	}

	void free()
	{
		set(nullptr);
	}

	void set(MYSQL_RES* value)
	{
		if (_data != nullptr)
		{
			mysql_free_result(_data);
		}
		_data = value;
	}

	MYSQL_RES* get()
	{
		return _data;
	}

	bool fetchRow(DbRow& row) override
	{
		if (_data == nullptr)
		{
			return false;
		}
		auto mysqlRow = mysql_fetch_row(_data);
		if (!mysqlRow)
		{
			return false;
		}
		auto& row_ = dynamic_cast<MysqlRow&>(row);
		row_.set(mysqlRow);
		return true;
	}
};
