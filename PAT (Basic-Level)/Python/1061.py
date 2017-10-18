#!/usr/bin/python3
# -*- coding: utf-8 -*-

stuNum, questionNum = input().split()
questionScore = list(map(int, input().split()))
answer = list(map(int, input().split()))
for i in range(int(stuNum)):
    stuScore = 0
    stuAnswer = list(map(int, input().split()))
    for i in range(int(questionNum)):
        if stuAnswer[i] == answer[i]:
            stuScore += questionScore[i]
    print(stuScore)