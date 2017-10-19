#!/usr/bin/python3
# -*- coding: utf-8 -*-
import math

N = int(input())
radius = temp = 0
for i in range(N):
    a, b = list(map(int, input().split()))
    temp = math.sqrt(a*a + b*b)
    if temp > radius:
        radius = temp;
print("%.2f" % radius)