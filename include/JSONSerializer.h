/*
 * JSONSerializer.h
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */

#pragma once

#include "IJsonSerializable.h"

namespace EF {

	class JSONSerializer {
	public:
		//serializer and deserializer methods
		static bool serialize(const IJsonSerializable* pObj, std::string& output);
		static bool serializeFast(const IJsonSerializable* pObj, std::string& output);
		static bool deserialize(IJsonSerializable* pObj, std::string& input);

	private:
		//Lo ponemos en private para que sea una clase estatica
		JSONSerializer();
	};

} /* namespace EF */
