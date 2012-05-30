/*
 * ComponentData.h
 *
 *  Created on: 30/05/2012
 *      Author: kaseyo
 */

#ifndef COMPONENTDATA_H_
#define COMPONENTDATA_H_

#include <sstream>

namespace EF {

	//Class that holds one variable (of type C)
	class ComponentData {
	public:
		enum DataType {
			Int,
			Double,
			Bool,
			String,
			None
		};

		//Constructors
		ComponentData();
		ComponentData(int _int);
		ComponentData(double _double);
		ComponentData(std::string _string);
		ComponentData(char* _string);
		ComponentData(bool _bool);
		~ComponentData();
		ComponentData(const ComponentData& cd);
		ComponentData& operator=(const ComponentData& cd);

		//Setters
		void set(int _int);
		void set(double _double);
		void set(std::string _string);
		void set(char* _string);
		void set(bool _bool);

		//Getters
		int getInt() const;
		double getDouble() const;
		bool getBool() const;
		std::string getString() const;

		//Print method for DEBUG
		std::string print() const;

	private:
		//Type of data
		DataType _dataType;

		//Value of data
		int _integerValue;
		bool _boolValue;
		double _doubleValue;
		std::string _stringValue;

		//Methods for init/copy
		void init();
		void copy(const ComponentData& cd);
	};

} /* namespace EF */
#endif /* COMPONENTDATA_H_ */
