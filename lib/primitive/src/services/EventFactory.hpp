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


// EventFactory.hpp


#pragma once


#include <string>
#include <map>
#include <memory>
#include "Event.hpp"
#include "../transport/ServerTransport.hpp"

class EventFactory final
{
private:
	EventFactory() = default;

	EventFactory(EventFactory const&) = delete;

	EventFactory& operator=(const EventFactory&) = delete;

	static EventFactory& getInstance()
	{
		static EventFactory instance;
		return instance;
	}

	std::map<std::string, std::shared_ptr<Event>(*)(const std::shared_ptr<Context>&, const SVal*)> _creators;

public:
	static bool reg(
		const std::string& name,
		std::shared_ptr<Event>(* creator)(const std::shared_ptr<Context>&, const SVal*)
	) noexcept;
	static std::shared_ptr<Event> create(
		const std::string& name,
		const std::shared_ptr<Context>& context,
		const SVal* input
	);
};
