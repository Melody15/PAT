#!/usr/bin/python3
# -*- coding: utf-8 -*-

N, sumNeed = list(map(int, input().split()))
mokeAmount = list(map(float, input().split()))
sumPrice = list(map(float, input().split()))

#dict
singlePrice = {i: sumPrice[i]/mokeAmount[i] for i in range(N)}  

singlePriceIndex = sorted(singlePrice, key=lambda i:singlePrice[i], reverse=True)

sale = 0
for i in singlePriceIndex:   
    if sumNeed >= mokeAmount[i]:  
        sale += sumPrice[i]  
        sumNeed -= mokeAmount[i]  
    else:  
        sale += sumNeed * singlePrice[i]  
        break  
print('%.2f' % sale)  

#reference:http://blog.csdn.net/zjw_python/article/details/70161827