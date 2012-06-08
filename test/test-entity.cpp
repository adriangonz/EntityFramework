#include "Entity.h"
#include "Component.h"
#include "CData.h"
#include "JSONSerializer.h"
#include "EntityManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	/* TESTING FOR SERIALIZERS (Y UN POCO DE TODO) */
	//EF::Entity e(0);
	EF::EntityManager em;
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
		EF::JSONSerializer::deserialize(&em, inputContent);

	}else{
		//Create "random"
		for(int i = 0; i < 1; i++){
			EF::Entity e;
			for(int j = 0; j < 1; j++){
				EF::Component c(j);
				c.addData("velocidad", 3);
				c.addData("frenado", 2.5);
				c.addData("marca", "peugeot");
				/*
				std::cout << c.getData("velocidad").getTag() << " : " << c.getData("velocidad").getInt() << std::endl;
				std::cout << c.getData("frenado").getTag() << " : " << c.getData("frenado").getDouble() << std::endl;
				std::cout << c.getData("marca").getTag() << " : " << c.getData("marca").getString() << std::endl;
				*/
				e.addComponent("coche", c);
			}
			
			std::stringstream ss;
			ss << "entidad - " << i;
			em.addEntity(ss.str(), e);
		}
	}
	
	std::string output = "";
	EF::JSONSerializer::serialize(&em, output);

	std::cout << output << std::endl;

	//Lo escribo en prueba.json
	
	std::ofstream outputFile("prueba.json");
	if(outputFile.is_open()) {
		outputFile << output;
		outputFile.close();

		std::cout << "Output written on prueba.json" << std::endl;
	}
	
	
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
