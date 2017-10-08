#!/usr/bin/python3
# -*- coding: utf-8 -*-

low = ["tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"]
high = ["xxx","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"]

N = int(input())
for i in range(N):
    data = input()
    if data.isdigit() == True:
        if int(data) <= 12:
            print(low[int(data)])
        elif int(data)%13 == 0:
            print(high[int(int(data)/13)])
        else:
            print(high[int(int(data)/13)], low[int(data)%13])
    else:
        temp = data.split()
        if len(temp) == 1:
            if temp[0] in low:
                print(low.index(temp[0]))
            else:
                print(high.index(temp[0])*13)
        else:
            print(high.index(temp[0])*13+low.index(temp[1]))
