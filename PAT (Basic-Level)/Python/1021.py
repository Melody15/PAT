#!/usr/bin/python3
# -*- coding: utf-8 -*-

#record = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
#or use dict
record = {0:0, 1:0, 2:0, 3:0, 4:0, 5:0, 6:0, 7:0, 8:0, 9:0}

num = input()
for i in range(len(num)):
    record[int(num[i])] += 1

for i in range(len(record)):
    if record[i] != 0:
        print("%d:%d" % (i, record[i]))
