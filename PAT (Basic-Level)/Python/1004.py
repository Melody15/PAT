#!/usr/bin/python3
# -*- coding: utf-8 -*-
# 
n = input()  
stuInfo = {}  #dict 
score = [] #list
for i in range(int(n)): 
    a = input().split() #split by space
    stuInfo[int(a[2])] = a[0] + ' ' + a[1] #score is the key

for key in stuInfo: 
    score.append(key) # memorize the score in list_score

print(stuInfo[max(score)])
print(stuInfo[min(score)])

#reference: http://blog.csdn.net/zjw_python/article/details/62434011
