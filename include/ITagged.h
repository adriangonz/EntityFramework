#pragma once

#include "Tag.h"
#include <string>

namespace EF {
	class ITagged {
	public:
		//Constructors
		ITagged(std::string tag = "");
		ITagged(const ITagged& t);
		ITagged& operator=(const ITagged& t);
		virtual ~ITagged();

		//Setters/Getters
		std::string getTag() const;
		void setTag(const Tag& t);

		//Nedded for map
		bool operator<(const ITagged& t) const;

	protected:
		//Tag for the class
		Tag _tag;

		//copy method
		void copy(const ITagged& t);
	};
}