#include "Entity.h"

namespace EF {
	const int Entity::InvalidID = -1;

	Entity::Entity(int id) {
		_id = id;
	}

	Entity::Entity(int id, std::list<Component> comps) {
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
	Entity::addComponent(const Component& comp) {
		_components.push_front(comp);
	}

	Component
	Entity::getComponent(int id) const {
		Component comp;

		std::list<Component>::const_iterator it;
		std::list<Component>::const_iterator it_end;

		for(it = _components.begin(), it_end = _components.end(); it != it_end; it++) {
			if(it->getID() == id){
				comp = *it;
				break;
			}
		}

		return comp;
	}

	bool
	Entity::rmComponent(int id) {
		bool erased = false;

		std::list<Component>::iterator it;
		std::list<Component>::iterator it_end;

		for(it = _components.begin(), it_end = _components.end(); it != it_end; it++) {
			if(it->getID() == id){
				it = _components.erase(it);
				erased = true;
				break;
			}
		}

		return erased;
	} 

	Json::Value
	Entity::serialize() const {
		Json::Value value;

		value["id"] = _id;

		std::list<Component>::const_iterator it;
		std::list<Component>::const_iterator it_end;

		for(it = _components.begin(), it_end = _components.end(); it != it_end; it++) {
			value["components"].append(it->serialize());
		}

		return value;
	}

	void
	Entity::deserialize(const Json::Value& root) {
		destroy();

		_id = root.get("id", Entity::InvalidID).asInt();

		Json::Value vector = root.get("components", "");
		if(vector.isArray()) {
			int size = vector.size();
			for(int i = 0; i < size; i++){
				Component c;
				c.deserialize(vector[i]);
				_components.push_front(c);
			}
		}
	}

	void
	Entity::copy(const Entity& en){
		_id = en._id;
		_components = en._components;
	}

	void
	Entity::destroy(){
		_id = InvalidID;
		_components.clear();
	}
}
