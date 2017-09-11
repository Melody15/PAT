#!/usr/bin/python3
# -*- coding: utf-8 -*-

i = 0
num = int(input())
while num != 1:
    if num % 2 == 1:
        num = (3*num + 1) / 2
        i = i + 1
    else:
        num = num / 2
        i = i + 1
print(i)