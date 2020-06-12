//
//  main.cpp
//  composition
//
//  Created by Harry O'Brien on 12/06/2018.
//  Copyright © 2018 Harry O'Brien. All rights reserved.
//

#include <iostream>
#include <string>

class Birthday {
public:
	Birthday(int m, int d, int y):
	month(m),
	day(d),
	year(y)
	{}
	
	void printDate(){
		std::cout << day << "/" << month << "/" << year << std::endl;
	}
	
private:
	int day, month, year;
	Birthday *bd;
};

class Person {
public:
  Person(std::string n, Birthday b) :
	name(n),
	bd(b)
	{};
	
  void printInfo() {
		std::cout << name << std::endl;
		bd.printDate();
	}
  
private:
  std::string name;
  Birthday bd;
};

int main(int argc, const char * argv[]) {
	
	Birthday bd(07,26,2000);
	Person p("Harry", bd);
	
	p.printInfo();
	
	return 0;
}
