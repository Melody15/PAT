#!/usr/bin/python3
# -*- coding: utf-8 -*-
import re
import sys

N = int(input())
avail = 0
maxYear = maxDay = maxMonth = 0
minYear = minDay = minMonth = sys.maxsize
minName = maxName = ''

for i in range(N):
    temName, temYear, temMonth, temDay = re.split(' |/', input())
    temYear, temMonth, temDay = int(temYear), int(temMonth), int(temDay)

    if (temYear < 2014 and temYear > 1814) or (temYear == 2014 and temMonth < 9) or (temYear == 1814 and temMonth > 9) or (temYear == 2014 and temMonth == 9 and temDay <= 6) or (temYear == 1814 and temMonth == 9 and temDay >= 6):
        if (temYear < minYear) or (temYear == minYear and temMonth < minMonth) or (temYear == minYear and temMonth == minMonth and temDay < minDay):
            minYear = temYear
            minMonth = temMonth
            minDay = temDay
            minName = temName
        if (temYear > maxYear) or (temYear == maxYear and temMonth > maxMonth) or (temYear == maxYear and temMonth == maxMonth and temDay > maxDay):
            maxYear = temYear
            maxMonth = temMonth
            maxDay = temDay
            maxName = temName

        avail += 1

if avail != 0:
    print("%d %s %s" % (avail, minName, maxName), end = '')
else:
    print(avail, end = '')

#testpoint 4 overtime