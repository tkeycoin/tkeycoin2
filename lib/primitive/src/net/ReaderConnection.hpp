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


// ReaderConnection.hpp


#pragma once

#include "../utils/Buffer.hpp"
#include "../utils/Reader.hpp"

class ReaderConnection: public Reader
{
protected:
	/// Буфер ввода
	Buffer _inBuff;

public:
	inline const char * dataPtr() const override
	{
		return _inBuff.dataPtr();
	}
	inline size_t dataLen() const override
	{
		return _inBuff.dataLen();
	}

	inline bool show(void *data, size_t length) const override
	{
		return _inBuff.show(data, length);
	}
	inline bool skip(size_t length) override
	{
		return _inBuff.skip(length);
	}
	inline bool read(void *data, size_t length) override
	{
		return _inBuff.read(data, length);
	}
};