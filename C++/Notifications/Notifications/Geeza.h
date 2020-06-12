//
//  Geeza.h
//  Notifications
//
//  Created by Harry O'Brien on 10/06/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#ifndef Geeza_h
#define Geeza_h

#include "Notifications.hpp"
#include <iostream>

class Geeza : public Util::Subject<int> {
	
	int currentNotifVal = 0;
public:
	void run() {
		std::cout << "Run:" << std::endl;
		setLatestVal(currentNotifVal++);
		std::cout << std::endl;
	}
};

#endif /* Geeza_h */
