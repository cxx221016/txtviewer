#coding=utf-8
import cn2an
import sys

def sortkey(s):
    return cn2an.cn2an(s);
if "__main__"==__name__:
    for line in sys.argv[1:]:
        #line=line.encode("utf-8");
        try :
            print(cn2an.cn2an(line));
        except:
            print("error");