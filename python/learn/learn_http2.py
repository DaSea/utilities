# -*- coding: utf-8 -*-
#!/usr/bin/env python3

import httplib2
httplib2.debuglevel = 1
h = httplib2.Http('.cache')
response, content = h.request("http://diveintopython3.org/examples/feed.xml")
