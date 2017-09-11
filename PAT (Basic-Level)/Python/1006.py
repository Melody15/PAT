#!/usr/bin/python3
# -*- coding: utf-8 -*-

n = int(input())
if n >= 100:
    tem = int(n / 100)
    n = n - tem*100
    for i in range(tem):
        print("B", end = "")

if n >= 10:
    tem = int(n / 10)
    n = n - tem*10
    for i in range(tem):
        print("S", end = "")

if n != 0:
    for i in range(1, n + 1):
        print(i, end = "")