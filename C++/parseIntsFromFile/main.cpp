//
//  main.cpp
//  parseIntsFromFile
//
//  Created by Harry O'Brien on 10/01/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

#include <fstream>
#include <sstream>
#include <vector>

std::vector<int> parseIntsFromFile(std::string fileName) {
	
	std::string line;
	std::ifstream inputFile(fileName);
	std::vector<std::string> tokens;
	
	while(getline(inputFile, line)) {
		std::stringstream ss(line);
		std::string buf;
		
		while(ss >> buf)
			tokens.push_back(buf);
	}
	
	inputFile.close();
	
	std::vector<int> castTokens;
	for(size_t i = 0; i < tokens.size(); i++) {
		castTokens.push_back(std::stoi(tokens[i]));
	}
	
	return castTokens;
}

int main(int argc, const char * argv[]) {
	
	std::vector<int> parsedFile = parseIntsFromFile("./a_example.in");
	
	return 0;
}
