/*
 * IJsonSerializable.h
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */

#pragma once

#include "json/json.h"


namespace EF {

	class IJsonSerializable {
	public:
		virtual ~IJsonSerializable() {};
		virtual Json::Value serialize() const = 0;
		virtual void deserialize(const Json::Value& root) = 0;
	};

} /* namespace EF */
