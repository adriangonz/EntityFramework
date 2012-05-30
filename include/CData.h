/*
 * ComponentData.h
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */
#pragma once

#include <sstream>

#include "IData.h"

namespace EF {

	//Class that holds one variable (of type C)
	template <typename T>
	class CData : public IData{
	public:
		//Constructors
		CData() {
			init();
		}

		CData(T value_) {
			init();
			_value = value_;
		}

		~CData() {
			init();
		}

		CData(const CData& cd) {
			copy(cd);
		}

		CData& operator=(const CData& cd) {
			if(this != &cd) {
				init();
				copy(cd);
			}

			return *this;
		}

		//Setters
		void set(T value_) {
			_value = value_;
		}

		//Getters
		T get() const {
			return _value;
		}

	private:
		//Value of data
		T _value;

		//Methods for init/copy
		void init() {
			//_value = 0x0; //I'm not sure if this works
		}

		void copy(const CData& cd) {
			_value = cd._value;
		}
	};

} /* namespace EF */
