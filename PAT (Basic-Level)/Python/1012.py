#!/usr/bin/python3
# -*- coding: utf-8 -*-

nums = list(map(int, input().split()))
numSet1 = []
numSet2 = []
numSet4 = []
numSet5 = []
result1 = 0
result2 = 0
result3 = 0
result4 = 0
result5 = -1

for i in range(1, len(nums)):
    tem = nums[i]%5
    if tem == 0 and nums[i]%2 == 0:
        numSet1.append(nums[i])
    elif tem == 1:
        numSet2.append(nums[i])
    elif tem == 2:
        result3 += 1
    elif tem == 3:
        numSet4.append(nums[i])
    elif tem == 4:
        numSet5.append(nums[i])

if len(numSet1) == 0:
    print("N", end = ' ')
else:
    for i in range(len(numSet1)):
        result1 += numSet1[i]
    print(result1, end = ' ')

if len(numSet2) == 0:
    print("N", end = ' ')
else:
    for i in range(len(numSet2)):
        if (i+1)%2 == 1:
            result2 += numSet2[i]
        else:
            result2 -= numSet2[i]
    print(result2, end = ' ')

if result3 == 0:
    print("N", end = ' ')
else:
    print(result3, end = ' ')

sum = 0
if len(numSet4) == 0:
    print("N", end = ' ')
else:
    for i in range(len(numSet4)):
        sum += numSet4[i]
        result4 = float(sum/len(numSet4))
    print("%.1f" % result4, end = ' ')

if len(numSet5) == 0:
    print("N")
else:
    for i in range(len(numSet5)):
        if numSet5[i] > result5:
            result5 = numSet5[i]
    print(result5)
    