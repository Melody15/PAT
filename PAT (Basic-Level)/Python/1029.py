#!/usr/bin/python3
# -*- coding: utf-8 -*-

tar = input()
real = input()
result = []

for i in range(len(tar)):
    if tar[i] not in real:
        result.append(tar[i])

for i in range(len(result)):
    result[i] = result[i].upper()

for i in range(len(result)):
    if result[i] != '!':
        for j in range(i+1, len(result)):
            if result[j] == result[i]:
                result[j] = '!'

for i in range(len(result)):
        if result[i] != '!':
            print("%c" % result[i], end = '')