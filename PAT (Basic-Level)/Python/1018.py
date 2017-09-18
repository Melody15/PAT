#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
AWinTimes = 0; AFailTimes = 0; AEqualTimes = 0
AWinByC = 0; AWinByJ = 0; AWinByB = 0
BWinByC = 0; BWinByJ = 0; BWinByB = 0
for i in range(N):
    temp = input().split()
    if (temp[0] == 'C' and temp[1] == 'J') or (temp[0] == 'J' and temp[1] == 'B') or (temp[0] == 'B' and temp[1] == 'C'):
        AWinTimes += 1
        if temp[0] == 'C':
            AWinByC += 1
        if temp[0] == 'J':
            AWinByJ += 1
        if temp[0] == 'B':
            AWinByB += 1
    elif temp[0] == temp[1]:
        AEqualTimes += 1
    else:
        AFailTimes += 1
        if temp[0] == 'C':
            BWinByB += 1
        if temp[0] == 'J':
            BWinByC += 1
        if temp[0] == 'B':
            BWinByJ += 1

print("%d %d %d" % (AWinTimes, AEqualTimes, AFailTimes))
print("%d %d %d" % (AFailTimes, AEqualTimes, AWinTimes))

if AWinByB >= AWinByC and AWinByB >= AWinByJ:
    print("B", end = '')
elif AWinByC >= AWinByJ:
    print("C", end = '')
else:
    print("J", end = '')

if BWinByB >= BWinByC and BWinByB >= BWinByJ:
    print(" B", end = '')
elif BWinByC >= BWinByJ:
    print(" C", end = '')
else:
    print(" J", end = '')

#last testpoint overtime