from langconv import *
import sys,getopt
import os

print(sys.version)
print(sys.version_info)

# 转换繁体到简体
def cht_to_chs(line):
    line = Converter('zh-hans').convert(line)
    line.encode('utf-8')
    return line

# 转换简体到繁体
def chs_to_cht(line):
    line = Converter('zh-hant').convert(line)
    line.encode('utf-8')
    return line

def convertor(inputfile, outputfile):
    tofile = open(outputfile, 'w',encoding='utf-8')
    with open(inputfile, 'r', encoding='utf-8', newline='') as f:
        for line in f:
            #  print(line)
            ret_cht = "%s"%chs_to_cht(line)
            tofile.write(ret_cht)
    tofile.close()

def main(argv):
    inputfile = ''
    outputfile = ''
    try:
        opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
    except getopt.GetoptError:
        print('convertor.py -i <inputfile> -o <outputfile>');
        sys.exit(2)

    for opt, arg in opts:
        if opt == '-h':
            print('convertor.py -i <inputfile> -o <outputfile>')
            sys.exit()
        elif opt in ("-i", "--ifile"):
            inputfile = arg
        elif opt in ("-o", "--ofile"):
            outputfile = arg
    print('输入的文件为：', inputfile)
    print('输出的文件为：', outputfile)

    # 判断输入文件是否存在
    if not os.path.exists(inputfile):
        print("<inputfile> is not exitsts!")
        sys.exit(2)

    convertor(inputfile, outputfile)

if __name__ == "__main__":
   main(sys.argv[1:])

