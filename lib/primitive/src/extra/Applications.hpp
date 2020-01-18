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


// Applications.hpp


#pragma once


#include <map>
#include <mutex>
#include "Application.hpp"

class Applications final
{
public:
	Applications(const Applications&) = delete;
    Applications& operator=(const Applications&) = delete;
	Applications(Applications&&) noexcept = delete;
	Applications& operator=(Applications&&) noexcept = delete;

private:
	Applications() = default;
	~Applications() = default;

	static Applications &getInstance()
	{
		static Applications instance;
		return instance;
	}

	std::map<std::string, const std::shared_ptr<Application>> _apps;
	std::mutex _mutex;

public:
	static std::shared_ptr<Application> add(const Setting& setting, bool replace = false);

	static std::shared_ptr<Application> get(const std::string& appId);

	static void del(const std::string& appId);
};
