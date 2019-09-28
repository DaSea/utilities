# -*- coding: utf-8 -*-
#!/bin/python

import urllib.request
import urllib.parse

# base
# response = urllib.request.urlopen("http://www.baidu.com")
# print(response.read())

values = {"usrname": "dhf0214@126.com", "password": "!DHF*d622#LXY^"}
data = urllib.parse.urlencode(values)
url = "https://passport.csdn.net/account/login?from=http://my.csdn.net/my/mycsdn"
response = urllib.request.urlopen(url, data)
print(type(response))
print(response.read())
