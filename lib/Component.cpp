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

		typedef std::map<Tag, CData> MyMap;

		MyMap::const_iterator it, it_end;
		for(it = _data.begin(), it_end = _data.end(); it != it_end; it++) {
			val["data"].append(it->second.serialize());
		}

		return val;
	}

	void
	Component::deserialize(Json::Value& root) {
		_id = root.get("id", InvalidID).asInt();

		Json::Value vector = root.get("data", "");
		if(vector.isArray()) {
			int size = vector.size();
			for(int i = 0; i < size; i++){
				CData c;
				c.deserialize(vector[i]);
				_data[c.getTag()] = c;
			}
		}
	}

	void
	Component::addData(std::string identifier, CData data) {
		Tag t(identifier);
		data.setTag(t);
		_data[t] = data;
	}

	CData
	Component::getData(std::string identifier) {
		return _data[Tag(identifier)];
	}

	bool Component::rmData(std::string identifier) {
		return (_data.erase(Tag(identifier)) >= 1);
	}

	void
	Component::copy(const Component& cp){
		_id = cp._id;
		_data = cp._data;
	}

	void
	Component::init(int id){
		_id = id;
	}

	void
	Component::destroy(){
		_id = InvalidID;

		_data.clear();
	}
}
