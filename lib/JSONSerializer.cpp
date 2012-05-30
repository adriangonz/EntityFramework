/*
 * JSONSerializer.cpp
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */

#include "JSONSerializer.h"

namespace EF {

JSONSerializer::JSONSerializer() {}

bool
JSONSerializer::serialize(const IJsonSerializable* pObj, std::string& output){
	bool correcto = false;

	if(pObj != NULL) {
		Json::StyledWriter writer;
		output = writer.write(pObj->serialize());

		correcto = true;
	}

	return correcto;
}

bool
JSONSerializer::serializeFast(const IJsonSerializable* pObj, std::string& output){
	bool correcto = false;

	if(pObj != NULL) {
		Json::FastWriter writer;
		output = writer.write(pObj->serialize());

		correcto = true;
	}

	return correcto;
}

bool
JSONSerializer::deserialize(IJsonSerializable* pObj, std::string& input) {
	bool correcto = false;

	if(pObj != NULL){
		Json::Reader reader;
		Json::Value deserRoot;
		if(reader.parse(input, deserRoot)) {
			pObj->deserialize(deserRoot);
			correcto = true;
		}
	}

	return correcto;
}

} /* namespace EF */
