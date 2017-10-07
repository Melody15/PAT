#!/usr/bin/python3
# -*- coding: utf-8 -*-

import math

R1, P1, R2, P2 = list(map(float, input().split()))
Re1 = R1 * math.cos(P1)
Im1 = R1 * math.sin(P1)
Re2 = R2 * math.cos(P2)
Im2 = R2 * math.sin(P2)
resultRe = Re1 * Re2 - Im1 * Im2
resultIm = Re1 * Im2 + Re2 * Im1

if resultRe + 0.005 >= 0 and resultRe < 0:
    print("0.00", end = '')
else:
    print("%.2f" % resultRe, end = '')
if resultIm + 0.005 >= 0 and resultIm < 0:
    print("+0.00i", end = '')
elif resultIm >= 0:
    print("+%.2fi" % resultIm, end = '')
else:
    print("%.2fi" % resultIm, end = '')
