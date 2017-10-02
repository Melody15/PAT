#!/usr/bin/python3
# -*- coding: utf-8 -*-

import re

gallonp, sicklep, knutp, gallona, sicklea, knuta = list(map(int, re.split(' |\.', input())))
flat = 0

if (gallona < gallonp) or (gallona == gallonp and sicklea < sicklep) or (gallona == gallonp and sicklea == sicklep and knuta < knutp):
    gallona, gallonp = gallonp, gallona
    sicklea, sicklep = sicklep, sicklea
    knuta, knutp = knutp, knuta
    flat = 1

if knuta < knutp:
    knutr = knuta + 29 - knutp
    sicklea -= 1
else:
    knutr = knuta - knutp

if sicklea < sicklep:
    sickler = sicklea + 17 - sicklep
    gallona -= 1
else:
    sickler = sicklea - sicklep

gallonr = gallona - gallonp

if flat == 1:
    print("-%d.%d.%d" % (gallonr, sickler, knutr), end = '')
else:
    print("%d.%d.%d" % (gallonr, sickler, knutr), end = '')