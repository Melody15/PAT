#!/usr/bin/python3
# -*- coding: utf-8 -*-

nums = list(map(int, input().split()))

if nums[0] + nums[1] < 0:
    print("-", end = '')

result = str(abs(nums[0] + nums[1]))
k = (len(result)-1) % 3
for i in range(len(result)):
    print(result[i], end = '')
    if (i-k) % 3 == 0 and i != len(result) - 1:
        print(",", end = '')