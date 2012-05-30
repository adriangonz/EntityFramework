/*
 * ComponentData.cpp
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */

#include "ComponentData.h"

namespace EF {

ComponentData::ComponentData() {
	init();
	_dataType = None;
}

ComponentData::ComponentData(int _int){
	init();
	_dataType = Int;
	_integerValue = _int;
}

ComponentData::ComponentData(double _double){
	init();
	_dataType = Double;
	_doubleValue = _double;
}

ComponentData::ComponentData(std::string _string){
	init();
	_dataType = String;
	_stringValue = _string;
}

ComponentData::ComponentData(char* _string){
	init();
	_dataType = String;
	_stringValue = _string;
}

ComponentData::ComponentData(bool _bool){
	init();
	_dataType = Bool;
	_boolValue = _bool;
}

ComponentData::~ComponentData(){
	init();
}

ComponentData::ComponentData(const ComponentData & cd){
	copy(cd);
}

ComponentData &
ComponentData::operator =(const ComponentData & cd) {
	if(this != &cd) {
		init();
		copy(cd);
	}

	return *this;
}

void
ComponentData::init() {
	_dataType = None;
	_integerValue = 0;
	_doubleValue = 0.0;
	_stringValue = "";
	_boolValue = false;
}

void
ComponentData::copy(const ComponentData& cd) {
	switch(_dataType) {
	case Int:
		_integerValue = cd._integerValue;
		break;

	case Double:
		_doubleValue = cd._doubleValue;
		break;

	case String:
		_stringValue = cd._stringValue;
		break;

	case Bool:
		_boolValue = cd._boolValue;
		break;

	case None:
		init();
		break;

	default:
		init();
		break;
	}
}

void
ComponentData::set(int _int) {
	init();
	_dataType = Int;
	_integerValue = _int;
}

void
ComponentData::set(double _double) {
	init();
	_dataType = Double;
	_doubleValue = _double;
}

void
ComponentData::set(std::string _string) {
	init();
	_dataType = String;
	_stringValue = _string;
}

void
ComponentData::set(char *_string) {
	init();
	_dataType = String;
	_stringValue = _string;
}

void
ComponentData::set(bool _bool) {
	init();
	_dataType = Bool;
	_boolValue = _bool;
}

int
ComponentData::getInt() const {
	return _integerValue;
}

double
ComponentData::getDouble() const {
	return _doubleValue;
}

bool
ComponentData::getBool() const {
	return _boolValue;
}

std::string
ComponentData::getString() const {
	return _stringValue;
}

std::string
ComponentData::print() const {
	std::stringstream ss;
	ss << "[ComponentData.cpp] ";
	switch(_dataType) {
		case Int:
			ss << "Integer : " << _integerValue;
			break;

		case Double:
			ss << "Double : " << _doubleValue;
			break;

		case String:
			ss << "String : " << _stringValue;
			break;

		case Bool:
			ss << "Bool : " << _boolValue;
			break;

		case None:
			ss << "None";
			break;

		default:
			ss << "Error";
			break;
	}

	return ss.str();
}

} /* namespace EF */
