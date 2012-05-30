#include "Entity.h"
#include "Component.h"
#include "ComponentData.h"
#include "JSONSerializer.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	/* TESTING FOR SERIALIZERS (Y UN POCO DE TODO)
	EF::Entity e(0);

	if(argc == 2) {
		//Read from file
		std::string inputFile = argv[1];
		std::ifstream inputFic;
		std::string inputContent = "";
		inputFic.open(inputFile.c_str(), std::ios::in);
		if(inputFic.is_open()){
			std::stringstream ss;
			ss << inputFic.rdbuf();
			inputFic.close();
			inputContent = ss.str();
		}

		std::cout << "[test-entity.cpp] Readed Content: " << inputContent << " from " << inputFile << std::endl;
		EF::JSONSerializer::deserialize(&e, inputContent);

	}else{
		//Create random
		for(int j = 0; j < 10; j++){
			e.addComponent(EF::Component(j));
		}
	}

	std::string output = "";
	EF::JSONSerializer::serializeFast(&e, output);

	std::cout << output << std::endl;
	*/
	/* TESTING FOR ComponentData */
	EF::ComponentData cd1;
	cd1.set(2);
	std::cout << "Should be Integer(2)...." << std::endl;
	std::cout << cd1.getInt() << std::endl;

	cd1.set(true);
	std::cout << "Should be Bool(true)...." << std::endl;
	std::cout << cd1.getBool()  << std::endl;

	float aux = 3.5;
	cd1.set(aux);
	std::cout << "Should be Double/Float(3.5)...." << std::endl;
	std::cout << cd1.getDouble()  << std::endl;

	cd1.set("hola");
	std::cout << "Should be String('hola')...." << std::endl;
	std::cout << cd1.getString()  << std::endl;
}
