#!/usr/bin/python3
# -*- coding: utf-8 -*-

sum = _0Times = _1Times = 0
data = input().lower()

for i in data:
    if ord('a') <= ord(i) <= ord('z'):
        sum += ord(i) - ord('a') + 1

while sum != 0:
    if sum % 2 == 0:
        _0Times += 1
    else:
        _1Times +=1
    sum = int(sum/2)

print(_0Times, _1Times)
