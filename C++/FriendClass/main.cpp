//
//  main.cpp
//  FriendClass
//
//  Created by Harry O'Brien on 27/05/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <iostream>

class Mode {
protected:
	class SystemController* sysCtrl;
public:
	Mode(SystemController* _sysCtrl) : sysCtrl(_sysCtrl) {}
	virtual ~Mode() {}
	virtual void run() = 0;
};


class SystemController {
	friend class ModeIdle;
	
	Mode* activeMode;
	
	bool isAlive;
public:
	SystemController();
	
	void run() {
		std::cout << "isAlive: " << isAlive << std::endl;
		std::cout << "running..." << std::endl;
		activeMode->run();
		std::cout << "isAlive: " << isAlive << std::endl;
	}
	
};

class ModeIdle : public Mode {
public:
	ModeIdle(SystemController *sysCtrl) : Mode(sysCtrl) {}
	void run() override {
		std::cout << "running mode idle" << std::endl;
		sysCtrl->isAlive = true;
	}
};

SystemController::SystemController() : isAlive(false), activeMode(new ModeIdle(this)) {
	
}


int main(int argc, const char * argv[]) {
	SystemController sys;
	sys.run();
	return 0;
}
