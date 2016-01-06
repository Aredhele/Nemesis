#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import hashlib

l_filePathList = []
l_hashList = []
BLOCKSIZE = 65536
hasher = hashlib.sha1()

def getHash(elt):
    file = open("res\\client\\" + elt, 'rb')
    buf = file.read(BLOCKSIZE)

    while(len(buf)) > 0:
          hasher.update(buf)
          buf = file.read(BLOCKSIZE)
          
    file.close()
    return hasher.hexdigest()


for root, dirs, files in os.walk("res\\client\\"):
    [l_filePathList.append(str(root)[11:] + "\\" + elt) for elt in files if(len(files) > 0)]

for elt in l_filePathList:
    print(elt)
    
[l_hashList.append(getHash(elt)) for elt in l_filePathList]

file = open("res/files/filesInfo.txt", "w")
[file.write(l_filePathList[i] + "\n") for i in range(0, len(l_filePathList))]
#[file.write(l_filePathList[i] + "\n" + l_hashList[i] + "\n") for i in range(0, len(l_filePathList))]
file.close()

#os.system("pause")
