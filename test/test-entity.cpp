#include "Entity.h"
#include "Component.h"
#include "CData.h"
#include "JSONSerializer.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	/* TESTING FOR SERIALIZERS (Y UN POCO DE TODO) */
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
		for(int j = 0; j < 1; j++){
			EF::Component c(j);
			c.addData("velocidad", EF::CData(3));
			c.addData("frenado", EF::CData(2.5));
			c.addData("marca", EF::CData("peugeot"));

			std::cout << "velocidad: " << c.getData("velocidad").getInt() << std::endl;
			std::cout << "frenado: " << c.getData("frenado").getDouble() << std::endl;
			std::cout << "marca: " << c.getData("marca").getString() << std::endl;

			e.addComponent(c);
		}
	}

	std::string output = "";
	//EF::JSONSerializer::serializeFast(&e, output);

	std::cout << output << std::endl;
	
	/* TESTING FOR ComponentData 
	EF::CData<int> cd1;
	cd1.set(2);
	std::cout << "Should be Integer(2)...." << std::endl;
	std::cout << cd1.get() << std::endl;

	EF::CData<bool> cd2;
	cd2.set(true);
	std::cout << "Should be Bool(true)...." << std::endl;
	std::cout << cd2.get()  << std::endl;

	EF::CData<double> cd3;
	cd3.set(3.5);
	std::cout << "Should be Double/Float(3.5)...." << std::endl;
	std::cout << cd3.get()  << std::endl;

	EF::CData<std::string> cd4;
	cd4.set("hola");
	std::cout << "Should be String('hola')...." << std::endl;
	std::cout << cd4.get()  << std::endl;
	*/
	// For prevent closing on Windows
	getchar();
}
