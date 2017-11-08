#!/usr/bin/python3
# -*- coding: utf-8 -*-

T, K = map(int, input().split())
for i in range(K):
    n1, b, t, n2 = map(int, input().split())
    if t > T:
        print("Not enough tokens.  Total = %d." % T)
    elif ((b == 0 and n1 > n2) or (b == 1 and n1 < n2)):
        T += t
        print("Win %d!  Total = %d." % (t, T))
    elif ((b == 0 and n1 < n2) or (b == 1 and n1 > n2)):
        T -= t
        print("Lose %d.  Total = %d." % (t, T))
        if T == 0:
            print("Game Over.")
            break 