




#'r': Open the file for reading only.
#'r+': Open the file for reading and writing. Any text written will overwrite the contents of the file, starting from the beginning of the file.
#'w': Create the file if it doesn't exist. If it exists overwrite it and open for writing.
#'w+': Create the file if it doesn't exist. If it exists overwrite it and open for reading and writing.
#'a': Open the file for writing only (create it if it doesn't already exist). Anything written will be appended to the end of the file.
#'a+': Open the file for reading and writing (create it if it doesn't already exist). Anything written will be appended to the end of the file.




with open("test", "w") as f:
	f.write("hello")
