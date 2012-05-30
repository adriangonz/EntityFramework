#pragma once

#include <list>
#include <string>

#include "Component.h"
#include "IJsonSerializable.h"
#include "json/json.h"

namespace EF{
	class Entity : public IJsonSerializable {
	public:
		//Static attrib
		static const int InvalidID;

		//Canonical form
		Entity(int id = -1);
		Entity(int id, std::list<Component> comps);
		Entity(const Entity& en);
		Entity& operator=(const Entity& en);
		~Entity();

		//Getters/Setters/Adders/Removers...
		void addComponent(const Component& comp);
		Component getComponent(int idComp) const;
		bool rmComponent(int idComp);

		//Serialize
		Json::Value serialize() const;
		void deserialize(Json::Value& root);

	private:
		//List of components
		std::list<Component> _components;

		//Unique ID for entity
		int _id;

		//init/destroy/copy methods
		void copy(const Entity& en);
		void destroy();
	};
}
