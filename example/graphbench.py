#! /usr/bin/env python

import os
import sys
from random import randint
import time

layertime = {'A':0, 'B':0, 'C':0, 'D':0, 'E':0, 'F':0, 'G':0, 'H':0, 'I':0, 'J':0, 'K':0}
for i in range(100):
	for j in layertime:
		start = time.clock()
		cmd = "./latte graph.ptx {}".format(j)
		os.system(cmd)
		end = time.clock()
		layertime[j] = layertime[j] + (end - start)/100
		

for i in layertime:
	print '%s took on average %f seconds' % (i, layertime[i])
