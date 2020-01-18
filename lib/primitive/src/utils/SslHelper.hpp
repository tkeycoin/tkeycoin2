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


// SslHelper.hpp


#pragma once

#include <openssl/ossl_typ.h>
#include <memory>

class SslHelper final
{
public:
	SslHelper(const SslHelper&) = delete;
	SslHelper& operator=(const SslHelper&) = delete;
	SslHelper(SslHelper&&) noexcept = delete;
	SslHelper& operator=(SslHelper&&) noexcept = delete;

private:
	SslHelper();
	~SslHelper();

	static SslHelper &getInstance()
	{
		static SslHelper instance;
		return instance;
	}

	std::shared_ptr<SSL_CTX> _serverContext;

public:
	static std::shared_ptr<SSL_CTX> getServerContext()
	{
		return getInstance()._serverContext;
	}

	static std::shared_ptr<SSL_CTX> getClientContext();
};