#pragma once

#include "Tag.h"
#include "IJsonSerializable.h"
#include "json/json.h"

#include <map>
#include <string>

namespace EF {
	//Template for an std::map indexed by Tags
	//IMPORTANT: Value class must inherit from ITagged and IJsonSerializable !!!
	template<class C>
	class TagMap : public IJsonSerializable {
	public:
		//Constructors
		TagMap() {}

		TagMap(const TagMap& itm) {
			copy(itm);
		}

		TagMap& operator=(const TagMap& tm) {
			if(this != &tm) {
				copy(tm);
			}

			return *this;
		}

		~TagMap() {
			_map.clear();
		}

		//Adders/Getters/Removers...
		void add(std::string identifier, const C& c) {
			Tag t(identifier);
			C aux(c);
			aux.setTag(t);
			_map[t] = aux;
		}

		bool addUnique(std::string identifier, const C& c) {
			Tag t(identifier);
			bool added = false;
			std::map<Tag, C>::iterator it;
			it = _map.find(t);

			if(it == _map.end()) {
				//Doesnt exists, we can insert
				c.setTag(t);
				_map[t] = c;
			}

			return added;
		}

		C get(std::string identifier) const {
			std::map<Tag, C>::const_iterator it = _map.find(Tag(identifier));
			C aux;
			if(it != _map.end()) {
				aux = it->second;
			}
			return aux;
		}

		bool rm(std::string identifier) {
			return (_map.erase(Tag(identifier)) >= 1);
		}

		//Serializers
		Json::Value serialize() const {
			Json::Value val;
			typedef std::map<Tag, C> MyMap;

			MyMap::const_iterator it, it_end;
			for(it = _map.begin(), it_end = _map.end(); it != it_end; it++) {
				val.append(it->second.serialize());
			}

			return val;
		}

		void deserialize(const Json::Value& root) {
			if(root.isArray()) {
				int size = root.size();
				for(int i = 0; i < size; i++){
					C c;
					c.deserialize(root[i]);
					_map[c.getTag()] = c;
				}
			}
		}

	protected:
		//Map of the class
		std::map<Tag, C> _map;

		void copy(const TagMap& tm) {
			_map = tm._map;
		}
	};
}