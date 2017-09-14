#!/usr/bin/python3
# -*- coding: utf-8 -*-

sentence = input().split()
sentence.reverse()

for i in range(len(sentence)-1):
    print(sentence[i], end = ' ')
print(sentence[len(sentence)-1])