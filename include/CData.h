/*
 * ComponentData.h
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */
#pragma once

#include <string>

namespace EF {

	//Class that holds one variable of any basic type
	class CData {
	public:
		//Type of data
		enum DataType {
			Int,
			Double,
			Bool,
			String,
			None
		};

		//Constructors
		CData();
		CData(int intValue_);
		CData(double doubleValue_);
		CData(bool boolValue_);
		CData(std::string stringValue_);
		CData(char* stringValue_);
		~CData();
		CData(const CData& cd);
		CData& operator=(const CData& cd);

		//Setters
		void set(int intValue_);
		void set(double doubleValue_);
		void set(bool boolValue_);
		void set(std::string stringValue_);
		void set(char* stringValue_);

		//Getters
		int getInt() const;
		double getDouble() const;
		bool getBool() const;
		std::string getString() const;

	private:
		//Value of data
		int _iVal;
		double _dVal;
		bool _bVal;
		std::string _sVal;

		//Type of data
		DataType _type;

		//Methods for init/copy
		void init();
		void copy(const CData& cd);
	};

} /* namespace EF */
