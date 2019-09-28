# -*- coding: utf-8 -*-
#!/usr/bin/env python3

import sys
import os

class ProjectManager(object):
    """
    Manager your project!
    label: path
    label: 1. common; 2, git, svn, hg and so on, 3, exvim;
    Save cache to file!
    Lazy update!
    """
    _version_label = ['git', 'svn', 'hg']

    def __init__(self):
        """__init__ documentation"""
        self._vscRootPath = []
        self._cachePath = ""

    def push_vsc_path(self, path):
        self._vscRootPath.append(path)

    def set_cache_path(self, path):
        self._cachePath = path

    def cache_to_file(self):
        """Save project cache to file"""
        pass

    def filter_vsc_project(self):
        """Filter version control project!"""
        for item in os.listdir(self._vscRootPath[0]):
            newItem = self._vscRootPath[0] + os.sep + item
            if self.__class__.isvscdir(newItem, '.git'):
                print(newItem)
            elif self.__class__.isvscdir(newItem, '.svn'):
                print(newItem)
            elif self.__class__.isvscdir(newItem, '.hg'):
                print(newItem)
            elif self.__class__.isvscdir(newItem, '.exvim'):
                print(newItem)
            else:
                print('No valid item!')

    @staticmethod
    def isvcsdir(path, str):
        """
        call: ProjectManager.isvcsdir()
        """
        print(path)

    @classmethod
    def isvscdir(cls, path, vscstr):
        """
        if path+os.seq+'.git' or '.svn' or '.hg' is dir, return true
        """
        fullpath = path + os.sep + vscstr
        if os.path.isdir(fullpath):
            return True
        return False


if __name__ == '__main__':
    filepath = os.path.realpath(__file__)
    filedir = os.path.dirname(filepath)
    print(filepath)
    print(filedir)

    prjMgr = ProjectManager()
    vsc_path = "/mnt/e/Self/05_gitsrc"
    cache_path = "~/cache.txt"
    prjMgr.push_vsc_path(vsc_path)
    prjMgr.set_cache_path(cache_path)
    prjMgr.filter_vsc_project()
