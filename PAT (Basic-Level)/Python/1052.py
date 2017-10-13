#!/usr/bin/python3
# -*- coding: utf-8 -*-

import re

hand = re.split(' |\[|\]', input())
hand = [item for item in filter(lambda x:x != '', hand)]
eye = re.split(' |\[|\]', input())
eye = [item for item in filter(lambda x:x != '', eye)]
mouth = re.split(' |\[|\]', input())
mouth = [item for item in filter(lambda x:x != '', mouth)]

N = int(input())
for i in range(N):
    data = list(map(int, input().split()))
    if data[0] < len(hand) and data[1] < len(eye) and data[2] < len(mouth) and data[3] < len(eye) and data[4] < len(hand):
        print(hand[data[0]-1]+'('+eye[data[1]-1]+mouth[data[2]-1]+eye[data[3]-1]+')'+hand[data[4]-1])
    else:
        print("Are you kidding me? @\/@")

#return nonzero..