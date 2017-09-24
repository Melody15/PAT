#!/usr/bin/python3
# -*- coding: utf-8 -*-

timeSet = list(map(int, input().split()))
time = ((timeSet[1] - timeSet[0]) / 100.0)

if int((time * 10) % 10) > 4:
    se_time = int(time)
    se_time += 1
elif int((time * 10) % 10) <= 4:
    se_time = int(time)

hour = int(se_time / 3600)
min = int((se_time - 3600 * hour) / 60)
second = int(se_time - 3600 * hour - min * 60)
print(hour)
print(min)
print(second)
print("%.2d:%.2d:%.2d" % (hour, min, second))
