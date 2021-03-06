//  Copyright (c) 2018-2019 Tkeycoin Dao
//  Copyright (c) 2020 TKEY DMCC LLC & Tkeycoin Dao. All rights reserved.
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


// DoAtExitScope.hpp


#pragma once

#include <functional>

class DoAtExitScope final
{
private:
	std::function<void()> _func;

public:
	DoAtExitScope(std::function<void()>&& func)
	: _func(std::move(func))
	{
	}

	DoAtExitScope() = delete; // Copy-constructor
	DoAtExitScope(const DoAtExitScope&) = delete; // Copy-constructor
	DoAtExitScope& operator=(const DoAtExitScope&) = delete; // Copy-assignment
	DoAtExitScope(DoAtExitScope&&) noexcept = delete; // Move-constructor
	DoAtExitScope& operator=(DoAtExitScope&&) noexcept = delete; // Move-assignment

	~DoAtExitScope()
	{
		_func();
	}
};
