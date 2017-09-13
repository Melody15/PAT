#!/usr/bin/python3
# -*- coding: utf-8 -*-

resultNum = [] #storage the resultNum
K = int(input())
num = list(map(int, input().split())) #python3 method
#in python 2: num = map(int, input().split()) is ok
#print(num)

for i in num:
    resultNum.append(i)

for i in num:
    while i != 1:
        if i%2 == 1:
            i = (3*i+1)/2
            if i in resultNum:
                resultNum.remove(i)
        elif i%2 == 0:
            i = i/2
            if i in resultNum:
                resultNum.remove(i)

resultNum.sort(reverse=True)

result = ''                   #for print as demand
for i in resultNum:
    result += str(i) + ' '
print(result.strip())  
       
#strip()方法用于移除字符串头尾指定的字符（默认为空格）