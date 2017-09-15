#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
for i in range(n):
    cal = list(map(int, input().split()))
    if cal[0] + cal[1] > cal[2]:
        print("Case #%d: true" % (i+1))
    else:
        print("Case #%d: false" % (i+1))
