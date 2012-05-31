#include "CData.h"

namespace EF {
	CData::CData() {
		init();
	}

	CData::CData(int intVal) {
		init();
		_iVal = intVal;
		_type = Int;
	}

	CData::CData(double dobVal) {
		init();
		_dVal = dobVal;
		_type = Double;
	}

	CData::CData(bool boolVal) {
		init();
		_bVal = boolVal;
		_type = Bool;
	}

	CData::CData(std::string stringVal) {
		init();
		_sVal = stringVal;
		_type = String;
	}

	CData::CData(char* stringVal) {
		init();
		_sVal = stringVal;
		_type = String;
	}

	CData::~CData() {
		init();
	}

	CData::CData(const CData& cd) {
		copy(cd);
	}

	CData&
	CData::operator=(const CData& cd) {
		if(this != &cd) {
			init();
			copy(cd);
		}

		return *this;
	}

	void
	CData::set(int intVal) {
		init();
		_iVal = intVal;
		_type = Int;
	}

	void
	CData::set(double dobVal) {
		init();
		_dVal = dobVal;
		_type = Double;
	}

	void
	CData::set(bool boolVal) {
		init();
		_bVal = boolVal;
		_type = Bool;
	}

	void
	CData::set(std::string stringVal) {
		init();
		_sVal = stringVal;
		_type = String;
	}

	void
	CData::set(char* stringVal) {
		init();
		_sVal = stringVal;
		_type = String;
	}

	int
	CData::getInt() const {
		return _iVal;
	}

	double
	CData::getDouble() const {
		return _dVal;
	}

	bool
	CData::getBool() const {
		return _bVal;
	}

	std::string
	CData::getString() const {
		return _sVal;
	}

	Json::Value
	CData::serialize() const {
		Json::Value val;
		val["tag"] = getTag();

		std::string type = "";

		val["type"] = _type;

		switch (_type)
		{
		case EF::CData::Int:
			val["value"] = _iVal;
			break;
		case EF::CData::Double:
			val["value"] = _dVal;
			break;
		case EF::CData::Bool:
			val["value"] = _bVal;
			break;
		case EF::CData::String:
			val["value"] = _sVal;
			break;
		case EF::CData::None:
			break;
		default:
			break;
		}

		return val;
	}

	void
	CData::deserialize(const Json::Value& root) {
		init();

		setTag(Tag(root.get("tag", "").asString()));
		
		Json::Value aux = root.get("type", "");
		int type = None;
		if(aux.isInt()) {
			type = aux.asInt();		
		}

		if(type >= 0 && type <= None) {
			_type = DataType(type);
		}else{
			_type = None;
		}

		switch (_type)
		{
		case EF::CData::Int:
			aux = root.get("value", "");
			if(aux.isInt())
				_iVal = aux.asInt();
			break;
		case EF::CData::Double:
			aux = root.get("value", "");
			if(aux.isDouble())
				_dVal = aux.asDouble();
			break;
		case EF::CData::Bool:
			aux = root.get("value", "");
			if(aux.isBool())
				_dVal = aux.asBool();
			break;
		case EF::CData::String:
			aux = root.get("value", "");
			if(aux.isString())
				_sVal = aux.asString();
			break;
		case EF::CData::None:
			break;
		default:
			break;
		}
	}

	void
	CData::init() {
		_type = None;
		_iVal = 0;
		_dVal = 0.0;
		_bVal = false;
		_sVal = "";
	}

	void
	CData::copy(const CData& cd) {
		init();
		ITagged::copy(cd);
		_type = cd._type;

		switch (_type)
		{
		case EF::CData::Int:
			_iVal = cd._iVal;
			break;
		case EF::CData::Double:
			_dVal = cd._dVal;
			break;
		case EF::CData::Bool:
			_bVal = cd._bVal;
			break;
		case EF::CData::String:
			_sVal = cd._sVal;
			break;
		case EF::CData::None:

			break;
		default:

			break;
		}
	}
}