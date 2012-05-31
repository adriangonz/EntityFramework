#include "EntityManager.h"

namespace EF{
EntityManager::EntityManager() {

}


EntityManager::~EntityManager() {

}

EntityManager::EntityManager(const EntityManager& em) {
	copy(em);
}

EntityManager&
EntityManager::operator=(const EntityManager& em) {
	if(this != &em) {
		copy(em);
	}

	return *this;
}

void
EntityManager::addEntity(std::string entityType, const Entity& em) {
	_entities.add(entityType, em);

	std::cout << "[Entity.cpp] Add... " << _entities.get(entityType).getTag() << std::endl;
}

Entity
EntityManager::getEntity(std::string entityType) const {
	return _entities.get(entityType);
}

bool
EntityManager::rmEntity(std::string entityType) {
	return _entities.rm(entityType);
}

Json::Value
EntityManager::serialize() const {
	Json::Value val;

	val["entities"] = _entities.serialize();

	return val;
}

void
EntityManager::deserialize(const Json::Value& root) {
	Json::Value vector = root["entities"];

	_entities.deserialize(vector);
}

void
EntityManager::copy(const EntityManager& em) {
	_entities = em._entities;
}

} 
