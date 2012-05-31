#include "Tag.h"


namespace EF {

Tag::Tag(std::string s) {
	init(s);
}


Tag::~Tag(void) {
 	init("");
}

Tag::Tag(const Tag& t) {
	copy(t);
}

Tag& 
Tag::operator=(const Tag& t) {
	if(this != &t) {
		init("");
		copy(t);
	} 

	return *this;
}

void
Tag::init(std::string val) {
	_val = val;
	if(_val != "") {
		_hash = std::hash<std::string>()(_val);
	}else{
		_hash = 0;
	}
}

void
Tag::copy(const Tag& t) {
	_val = t._val;
	_hash = t._hash;
}

void
Tag::setTag(std::string val) {
	init(val);
}

std::string
Tag::getTag() const {
	return _val;
}

std::size_t
Tag::getHash() const {
	return _hash;
}

bool
Tag::operator<(const Tag& t) const {
	return (_hash < t._hash);
}

}
