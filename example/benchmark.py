#! /usr/bin/env python

import os
import sys
from random import randint
import time


for i in [1, 10, 100, 1000, 10000, 100000, 10000000000000000000000]:
	fo = open("input.txt", "w")
	for j in range(i):
		for k in range(i):
			if k != i-1:
				fo.write(str(randint(1,100)) + ",")
			else:
				fo.write(str(randint(1,100)) + "\n")

	fo.close()
	start = time.clock()
	os.system("./latte sample.ptx final")
	end = time.clock()
	print 'Run time of %s for %d rows is %4.5f' % ("latte", i, (end - start))

		
