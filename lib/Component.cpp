#include "Component.h"

namespace EF {
	const int Component::InvalidID = -1;

	Component::Component(int id) {
		init(id);
	}

	Component::~Component() {
		destroy();
	}

	Component::Component(const Component& cp) {
		copy(cp);
	}

	Component&
	Component::operator=(const Component& cp) {
		if(this != &cp){
			destroy();
			copy(cp);
		}

		return *this;
	}

	int 
	Component::getID() const {
		return _id;
	}

	void 
	Component::setID(int id) {
		_id = id;
	}

	Json::Value
	Component::serialize() const {
		Json::Value val;
		val["id"] = _id;
		/*
		typedef std::map<Tag, CData> MyMap;

		MyMap::const_iterator it, it_end;
		for(it = _data.begin(), it_end = _data.end(); it != it_end; it++) {
			val["data"].append(it->second.serialize());
		}
		*/
		val["attributes"] = _attributes.serialize();

		return val;
	}

	void
	Component::deserialize(const Json::Value& root) {
		_id = root.get("id", InvalidID).asInt();

		Json::Value vector = root.get("attributes", "");
		/*
		if(vector.isArray()) {
			int size = vector.size();
			for(int i = 0; i < size; i++){
				CData c;
				c.deserialize(vector[i]);
				_data[c.getTag()] = c;
			}
		}
		*/
		_attributes.deserialize(vector);
	}

	void
	Component::addData(std::string identifier, const CData& data) {
		_attributes.add(identifier, data);
	}

	CData
	Component::getData(std::string identifier) {
		return _attributes.get(identifier);
	}

	bool Component::rmData(std::string identifier) {
		return (_attributes.rm(identifier));
	}

	void
	Component::copy(const Component& cp){
		_id = cp._id;
		_attributes = cp._attributes;
	}

	void
	Component::init(int id){
		_id = id;
	}

	void
	Component::destroy(){
		_id = InvalidID;
	}
}
