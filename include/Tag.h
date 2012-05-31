#pragma once

#include <string>

namespace EF {
	class Tag
	{
	public:
		//Constructors
		Tag(std::string val = "");
		Tag(const Tag& tag);
		Tag& operator=(const Tag& tag);
		~Tag();

		//Getters
		std::size_t getHash() const;
		std::string getTag() const;

		//Setters
		void setTag(std::string val);

		//Needed for key on std::map
		bool operator<(const Tag& t) const;

	private:
		//Value of tag and hash
		std::string _val;
		std::size_t _hash;

		//init/copy methods
		void init(std::string val);
		void copy(const Tag& t);
	};
}

