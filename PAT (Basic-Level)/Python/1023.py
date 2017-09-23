#!/usr/bin/python3
# -*- coding: utf-8 -*-

num_rec = list(map(int, input().split()))
i = 0
while i < 9:
    i += 1
    if num_rec[i] != 0:
        print(i, end = '')
        num_rec[i] -= 1
        break
i = -1
while i < 9:
    i += 1
    while num_rec[i] != 0:
        print(i, end = '')
        num_rec[i] -= 1