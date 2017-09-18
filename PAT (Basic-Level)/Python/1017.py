#!/usr/bin/python3
# -*- coding: utf-8 -*-

data = list(map(int, input().split()))
print((data[0]//data[1]), end = ' ') #//为整数除法
print(data[0]%data[1])
