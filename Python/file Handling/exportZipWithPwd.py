#
# Sample Alien Zip file found at /tmp/alien-zip-2092.zip is password protected
# We have worked out they are using three digit code
# Brute force the Zip file to extract to /tmp
#
# Note: The script can timeout if this occurs try narrowing
# down your search

import zipfile
for i in range(1000):
	zip_ref = zipfile.ZipFile("/tmp/alien-zip-2092.zip", 'r')
	try:
		zip_ref.setpassword(str(i))
		zip_ref.extractall("/tmp")
		zip_ref.close()
		print("SUCCESS WITH PWD: " + str(i))
		break
	except:
		print("fail with pwd: " + str(i))

with open("/tmp/alien-zip-2092.txt") as f:
  for line in f:
    print(line)
