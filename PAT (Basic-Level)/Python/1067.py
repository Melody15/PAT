#!/usr/bin/python3
# -*- coding: utf-8 -*-

password, limitTimes = input().split()
limitTimes = int(limitTimes)
enterTimes = 0

while True:
    data = input()
    if data == '#':
        break
    enterTimes += 1
    if data != password and enterTimes <= limitTimes:
        print("Wrong password: %s" % data)
        if enterTimes == limitTimes:
            print("Account locked", end = '')
            break
    elif data == password and enterTimes <= limitTimes:
        print("Welcome in", end = '')
        break
