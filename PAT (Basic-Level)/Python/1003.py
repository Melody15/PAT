#!/usr/bin/python3
# -*- coding: utf-8 -*-

import re  
n = input()  
for i in range(int(n)):  
    s = input()  
    if re.match(r'A*PA+TA*', s):  #regular expression match
        a = re.split(r'[P|T]', s)  
        if a[0] * len(a[1]) == a[2]:  #rules
            print('YES')  
        else:  
            print('NO')  
    else:  
        print('NO')  

#reference: http://blog.csdn.net/zjw_python/article/details/62433010