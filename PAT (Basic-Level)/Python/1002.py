#!/usr/bin/python3
# -*- coding: utf-8 -*-

numString = str(input())
list1 = ['ling','yi','er','san','si','wu','liu','qi','ba','jiu']
list2 = []
sum = 0
for i in numString:
    sum = sum + int(i)

sumString = str(sum)
for i in sumString:
    list2.append(list1[int(i)])
print(' '.join(list2))