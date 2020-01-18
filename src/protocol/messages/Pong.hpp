//  Copyright (c) 2017-2020 TKEY DMCC LLC & Tkeycoin Dao. All rights reserved.
//  Website: www.tkeycoin.com
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.


// Pong.hpp

#pragma once


#include <protocol/types/Message.hpp>

namespace protocol::message
{
// The pong message replies to a ping message, proving to the
// pinging node that the ponging node is still alive.
class Pong final : public Message
{
	DECLARE_MESSAGE(Pong);

public:
	Pong() = default; // Default-constructor

	explicit Pong(uint64_t nonce)
	: _nonce(nonce)
	{
	}

private:
	uint64_t _nonce = 0;
};

}



