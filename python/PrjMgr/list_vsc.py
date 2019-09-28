# -*- coding: utf-8 -*-
#!/bin/python

import os


def filter_vsc_projcect(fileobj, label, path):
    """
    主要查找path下面的文件夹是否是label类型的文件夹, 如git, svn等, 并写入文件(label:path)
    """
    for item in os.listdir(path):
        itempath = os.sep.join([path, item])
        fullpath = os.sep.join([itempath, "."+label])
        print(fullpath)
        if os.path.isdir(fullpath):
            line = label + ":" + itempath + "\n"
            fileobj.write(line)


def main():
    vsc_rootdir = {"E:/Self/05_gitsrc": "git"}
    cache_path = "vsclist.txt"
    with open(cache_path, 'w', encoding='utf-8', newline='\n') as f:
        for item in vsc_rootdir.items():
            filter_vsc_projcect(f, item[1], item[0])

if __name__ == '__main__':
    main()
