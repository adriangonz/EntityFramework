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