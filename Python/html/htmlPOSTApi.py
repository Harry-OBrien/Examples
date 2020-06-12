#
# Tweet bot API listening at http://127.0.0.1:8082.
# GET / returns basic info about api. POST / with x-api-key:tweetbotkeyv1
# and data with user tweetbotuser and status-update of alientest
#

import urllib
import urllib2

data = urllib.urlencode({'user': 'tweetbotuser',
                         'status-update': 'alientest'})
req = urllib2.Request("http://127.0.0.1:8082/", data=data)
req.add_header('x-api-key', "tweetbotkeyv1")

xml = urllib2.urlopen(req).read()
print(xml)