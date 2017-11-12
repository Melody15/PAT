#!/usr/bin/python3
# -*- coding: utf-8 -*-
import re

M = int(input())
record = [[] for i in range(M)]

for i in range(M):
    temp = re.split(' |:', input())
    record[i].append(temp[0])
    record[i].append(int(temp[1])*3600+int(temp[2])*60+int(temp[3]))
    record[i].append(int(temp[4])*3600+int(temp[5])*60+int(temp[6]))

earlyId = lateId = record[0][0]
earltTime = record[0][1]
lateTime = record[0][2]

for i in record[1:]:
    if i[1] < earltTime:
        earltTime = i[1]
        earlyId = i[0]
    if i[2] > lateTime:
        lateTime = i[2]
        lateId = i[0] 

print("%s %s" % (earlyId, lateId), end = '')
