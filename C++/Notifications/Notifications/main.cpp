//
//  main.cpp
//  Notifications
//
//  Created by Harry O'Brien on 10/06/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include "Geeza.h"
#include "Subber.h"


int main(int argc, const char * argv[]) {
	
	
	Geeza g;
	Subber* s1 = new Subber(&g, 1);
	Subber* s2 = new Subber(&g, 2);
	Subber* s3 = new Subber(&g, 3);
	
	g.run();
	g.run();
	delete s2;
	
	g.run();
	delete s1;
	g.run();
	
	delete s3;
	g.run();
	
	Subber* s4 = new Subber(&g, 4);
	Subber* s5 = new Subber(&g, 5);
	g.run();
	g.run();
	
	return 0;
}
