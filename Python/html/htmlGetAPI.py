#
# Alien Signal API listening on http://127.0.0.1:8082
# Use HTTP GET with x-api-key header to get signal
# We have narrowed down the key to be in the range of 5500 to 5600
# Note: The script can timeout if this occurs try narrowing
# down your search
#

import urllib2
import re

for i in range (5500, 5600):
	api_key = str(i)
  
	req = urllib2.Request("http://127.0.0.1:8082")
	req.add_header('x-api-key', api_key)
	xml = urllib2.urlopen(req).read()
	print(xml + "\n")
