#!/usr/bin/python3
# -*- coding: utf-8 -*-

digit = ["zero","one","two","three","four","five","six","seven","eight","nine"]

num = input()
sum = 0
for i in num:
    sum += int(i)

sumChar = str(sum)

count = 0
for i in sumChar:
    if count < len(sumChar)-1:
        print(digit[int(i)], end = ' ')
        count += 1
    else:
        print(digit[int(i)])
