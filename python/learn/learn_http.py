# -*- coding: utf-8 -*-
#!/bin/python

import urllib.request
from http.client import HTTPConnection

a_url = 'http://diveintopython3.org/examples/feed.xml'

# urllib测试, 低效
data = urllib.request.urlopen(a_url).read()
print(type(data))
print('\n')
print(data)

HTTPConnection.debuglevel = 1
response = urllib.request.urlopen(a_url)
print(response.headers.as_string())
