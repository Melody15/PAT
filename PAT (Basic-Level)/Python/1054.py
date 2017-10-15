#!/usr/bin/python3
# -*- coding: utf-8 -*-

N = int(input())
sum = 0 
num = 0 
data = input().split()  
for i in data:
    try:
        if round(float(i),2) == float(i) and -1000<=float(i)<=1000:  
            sum += float(i)  
            num += 1    
        else:  
            print("ERROR: %s is not a legal number" % i)
    except:
        print("ERROR: %s is not a legal number" % i)

if num == 0:  
    print("The average of 0 numbers is Undefined")  
elif num == 1:  
    print("The average of %d number is %.2f" % (num,sum))  
else:  
    print("The average of %d numbers is %.2f" % (num,sum/num))