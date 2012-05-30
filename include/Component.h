#pragma once

#include <string>

#include "IJsonSerializable.h"

namespace EF {
	class Component : public IJsonSerializable {
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

		//Serialize
		Json::Value serialize() const;
		void deserialize(Json::Value& root);

	private:
		//Unique ID for Component
		int _id;

		//Maps of data for the component
		//map<string, CompAttribute> _data;

		//Aux func for copy/init/destroy
		void copy(const Component& comp);
		void init(int id);
		void destroy();
	};
}
