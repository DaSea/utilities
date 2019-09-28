# -*- coding: utf-8 -*-
#!/usr/bin/env python3

class PrjItem:
    """
    Describe the item of project
    """
    def __init__(self, label, path):
        self.label = label
        self.path = path

    def setPath(self, path):
        """Get label and path from path"""
        pass

    def __str__(self):
        """Get the str"""
        return "[%s] %s"%{self.label, self.path}
