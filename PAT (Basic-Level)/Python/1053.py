#!/usr/bin/python3
# -*- coding: utf-8 -*-

N, e, D = list(map(float, input().split()))
N = int(N)
D = int(D)
proEmptyCount = emptyCount = 0
for i in range(N):
    eleLessDays = 0
    eleUsed = list(map(float, input().split()))
    obserDays = int(eleUsed[0])
    for j in eleUsed[1:]:
        if j < e:
            eleLessDays += 1
    if eleLessDays > int(obserDays/2) and obserDays > D:
        emptyCount += 1
    elif eleLessDays > int(obserDays/2) and obserDays <= D:
        proEmptyCount += 1
print("%.1f%% %.1f%%" % (proEmptyCount/N*100, emptyCount/N*100))


'''edition2
N, e, D = list(map(float, input().split()))
N = int(N)
D = int(D) 
proEmptyCount = 0  
emptyCount = 0  
for i in range(N):  
    eleLessDays = 0  
    eleUsed = list(map(float, input().split()))
    obserDays = int(eleUsed[0])
    if obserDays <= D:  
        for j in eleUsed[1:]:  
            if j < e:  
                eleLessDays += 1  
        if eleLessDays*2 > obserDays:  
            proEmptyCount += 1  
    else:  
        for j in eleUsed[1:]:  
            if j < e:  
                eleLessDays += 1  
        if eleLessDays*2 > obserDays:  
            emptyCount += 1  
print("%.1f%% %.1f%%" % (proEmptyCount/N*100, emptyCount/N*100))  '''