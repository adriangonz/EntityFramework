#pragma once

#include <string>
#include <map>

#include "IJsonSerializable.h"
#include "CData.h"
#include "Tag.h"
#include "TagMap.h"

namespace EF {
	class Component : public IJsonSerializable, public ITagged {
	public:
		//Static attributes
		static const int InvalidID;

		//Canonical form
		Component(int id = -1);
		Component(const Component& comp);
		Component& operator=(const Component& comp);
		~Component();

		//Getters/Setters
		int getID() const;
		void setID(int id);

		//Adders/Removers
		void addData(std::string identifier, const CData& data);
		CData getData(std::string identifier);
		bool rmData(std::string identifier);

		//Serialize
		Json::Value serialize() const;
		void deserialize(const Json::Value& root);

	private:
		//Unique ID for Component
		int _id;

		//Maps of data for the component
		//std::map<Tag, CData> _data;
		//std::set<CData> _data;
		TagMap<CData> _attributes;

		//Aux func for copy/init/destroy
		void copy(const Component& comp);
		void init(int id);
		void destroy();
	};
}
