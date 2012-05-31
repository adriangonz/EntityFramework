#include "Entity.h"

namespace EF {
	const int Entity::InvalidID = -1;

	Entity::Entity(int id) {
		_id = id;
	}

	Entity::Entity(int id, TagMap<Component> comps) {
		_id = id;
		_components = comps;
	}

	Entity::~Entity() {
		destroy();
	}

	Entity::Entity(const Entity& en) {
		copy(en);
	}

	Entity&
	Entity::operator=(const Entity& en) {
		if(this != &en) {
			destroy();
			copy(en);
		}

		return *this;
	}

	void
	Entity::addComponent(std::string compType, const Component& comp) {
		_components.add(compType, comp);

		//std::cout << "[Entity.cpp] Add... " << _components.get(compType).getTag() << std::endl;
	}

	Component
	Entity::getComponent(std::string compType) const {
		return _components.get(compType);
	}

	bool
	Entity::rmComponent(std::string compType) {
		return _components.rm(compType);
	} 

	Json::Value
	Entity::serialize() const {
		Json::Value value;

		//value["id"] = _id;
		value["tag"] = getTag();
		value["components"] = _components.serialize();

		return value;
	}

	void
	Entity::deserialize(const Json::Value& root) {
		destroy();

		_id = root.get("id", Entity::InvalidID).asInt();
		setTag(Tag(root.get("tag", "").asString()));
		
		Json::Value vector = root.get("components", "");
		_components.deserialize(vector);
	}

	void
	Entity::copy(const Entity& en){
		_id = en._id;
		_components = en._components;
		ITagged::copy(en);
	}

	void
	Entity::destroy(){
		_id = InvalidID;
	}
}
