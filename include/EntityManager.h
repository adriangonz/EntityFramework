#pragma once

#include <string>

#include "TagMap.h"
#include "Entity.h"
#include "IJsonSerializable.h"

namespace EF {
	//Class that holds a set of Entitys
	class EntityManager : public IJsonSerializable {
	public:
		//Constructors
		EntityManager();
		EntityManager(const EntityManager& em);
		EntityManager& operator=(const EntityManager& em);
		~EntityManager();

		//Adders/Getters/Removers
		void addEntity(std::string identifier, const Entity& en);
		Entity getEntity(std::string identifier) const;
		bool rmEntity(std::string identifier);

		//Serializers
		Json::Value serialize() const;
		void deserialize(const Json::Value& root);

	private:
		//TagMap that holds the entities
		TagMap<Entity> _entities;

		//copy method
		void copy(const EntityManager& em);
	};
}

