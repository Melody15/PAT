#!/usr/bin/python3
# -*- coding: utf-8 -*-

s1 = input()
s2 = input()
s3 = input()
s4 = input()
week = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
count = 0

for i in range(min(len(s1), len(s2))):
    if s1[i] >= 'A' and s1[i] <= 'G' and s1[i] == s2[i]:
        day = ord(s1[i]) - ord('A')
        #ord()return the char's ascii code
        count = i
        break
print(week[day], end = ' ')

for i in range(count+1, min(len(s1), len(s2))):
    if ((s1[i] >= 'A' and s1[i] <= 'N') or (s1[i] >= '0' and s1[i] <= '9')) and s1[i] == s2[i]:
        hour = s1[i]
        break
if hour >= '0' and hour <= '9':
    print("%.2d:" % (ord(hour) - 48), end = '')
else:
    print("%d:" % (ord(hour) - 55), end = '')

for i in range(min(len(s3), len(s4))):
    if ((s3[i] >= 'A' and s3[i] <= 'Z') or (s3[i] >= 'a' and s3[i] <= 'z')) and s3[i] == s4[i]:
        minute = i
print("%.2d" % minute)