//
//  main.cpp
//  tbd
//
//  Created by Harry O'Brien on 15/03/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include "HL_HAL_Namespace.hpp"

class HL_HAL::HAL {
public:
	~HAL() {
		
	}
	
	void init() {
		std::cout << "Initialising!" << std::endl;
	}
	
	void run() const {
		std::cout << "Running!" << std::endl;
	}
	
	// Dissalow copies <- Singleton class
	HAL(HAL const&) = delete;
	void operator=(HAL const&) = delete;
	
private:
	// Private constructor <- Singleton class
	HAL() {
		init();
	}
	friend const HAL& HL_HAL::get_HAL();
};

const HL_HAL::HAL& HL_HAL::get_HAL() {
  static const HL_HAL::HAL hal;
  return hal;
}

const HL_HAL::HAL& hal = HL_HAL::get_HAL();

int main(int argc, const char * argv[]) {
	hal.run();
	
	return 0;
}
