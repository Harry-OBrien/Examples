//
//  main.swift
//  parseFromFileSwift
//
//  Created by Harry O'Brien on 14/01/2020.
//  Copyright © 2020 SociaDevLtd. All rights reserved.
//

import Foundation

// MARK: Read from file
func parseInts(from fileName: String) -> [Int] {
	
	let DocumentDirURL = FileManager.default.currentDirectoryPath
	let fileURL = URL(fileURLWithPath: DocumentDirURL).appendingPathComponent(fileName)
		
	var fileContent = "" // Used to store the file contents
	do {
		// Read the file contents
		fileContent = try String(contentsOf: fileURL)
	} catch let error as NSError {
		print("Failed reading from URL: \(fileURL), Error: " + error.localizedDescription)
		exit(1)
	}

	//compile the tokens from the text input
	var tokens = [Int]()
	fileContent.enumerateLines { line, _ in
		let lineComponents = line.components(separatedBy: " ")
		
		for val in lineComponents {
			tokens.append(Int(val)!)
		}
	}
	
	return tokens
}

// MARK: Write to file
func outputTextTo(fileName: String, outputString: String) {

	let DocumentDirURL = FileManager.default.currentDirectoryPath
	let fileURL = URL(fileURLWithPath: DocumentDirURL).appendingPathComponent("Output_of_\(fileName)")

	print(outputString)

	do {
		// Write to the file
		try outputString.write(to: fileURL, atomically: true, encoding: String.Encoding.utf8)
	} catch let error as NSError {
		print("Failed writing to URL: \(fileURL), Error: " + error.localizedDescription)
	}
}

let inputFileName = "d_quite_big.in"
let tokens = parseInts(from: inputFileName)
print(tokens)
