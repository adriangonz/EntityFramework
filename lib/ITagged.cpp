#include "ITagged.h"

namespace EF {
	ITagged::ITagged(std::string tag) 
		:_tag(tag)
	{
		
	}

	ITagged::ITagged(const ITagged& tag) {
		copy(tag);
	}

	ITagged::~ITagged() {
		
	}

	ITagged&
	ITagged::operator=(const ITagged& t) {
		if(this != &t){
			copy(t);
		}

		return *this;
	}

	std::string
	ITagged::getTag() const {
		return _tag.getTag();
	}

	void
	ITagged::setTag(const Tag& t) {
		_tag = t;
	}

	bool
	ITagged::operator<(const ITagged& t) const {
		return (_tag < t._tag);
	}

	void
	ITagged::copy(const ITagged& t) {
		_tag = t._tag;
	}
}