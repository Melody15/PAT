#!/usr/bin/python3
# -*- coding: utf-8 -*-

firstAddress, N, K = list(map(int, input().split()))
data = [0 for x in range(100000)]
nextAddress = [0 for x in range(100000)]
tempAddress = [0 for x in range(N)]
resultAddress = [0 for x in range(N)]
sum = 0

for i in range(N):
    address, tempData, tempNextAddress = list(map(int, input().split()))
    data[address] = tempData
    nextAddress[address] = tempNextAddress
address = firstAddress

while address != -1:
    tempAddress[sum] = address
    resultAddress[sum] = address
    sum += 1
    address = nextAddress[address]

for i in range(sum - sum % K):
    resultAddress[i] = tempAddress[int((i/K))*K + K-i%K - 1]

for i in range(sum-1):
    print("%05d %d %05d" % (resultAddress[i], data[resultAddress[i]], resultAddress[i+1]))

print("%05d %d -1" % (resultAddress[sum-1], data[resultAddress[sum-1]]))

#testpoint 5 overtime
