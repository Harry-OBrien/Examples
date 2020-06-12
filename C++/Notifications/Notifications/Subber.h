//
//  Subber.h
//  Notifications
//
//  Created by Harry O'Brien on 10/06/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#ifndef Subber_h
#define Subber_h

#include "Notifications.hpp"
#include <iostream>

class Subber : public Util::Observer<int> {
	int const identifier;
	
public:
	Subber(Geeza* g, int _identifier) :
	identifier(_identifier),
	Util::Observer<int>(g) {
		
	}
	
	void update() override {
		int latest = getSubject()->getLatestVal();
		std::cout << identifier << ": " << latest << std::endl;
	}
};

#endif /* Subber_h */
