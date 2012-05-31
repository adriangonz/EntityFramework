#pragma once

#include <list>
#include <string>

#include "Component.h"
#include "IJsonSerializable.h"
#include "TagMap.h"
#include "ITagged.h"
#include "json/json.h"

namespace EF{
	class Entity : public IJsonSerializable, public ITagged {
	public:
		//Static attrib
		static const int InvalidID;

		//Canonical form
		Entity(int id = -1);
		Entity(int id, TagMap<Component> comps);
		Entity(const Entity& en);
		Entity& operator=(const Entity& en);
		~Entity();

		//Getters/Setters/Adders/Removers...
		void addComponent(std::string compType, const Component& comp);
		Component getComponent(std::string compType) const;
		bool rmComponent(std::string compType);

		//Serialize
		Json::Value serialize() const;
		void deserialize(const Json::Value& root);

	private:
		//List of components
		//std::list<Component> _components;
		TagMap<Component> _components; 

		//Unique ID for entity
		int _id;

		//init/destroy/copy methods
		void copy(const Entity& en);
		void destroy();
	};
}
