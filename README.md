
# latte [![build status](https://travis-ci.org/mkrum/latte.svg?branch=master)](https://travis-ci.org/mkrum/latte)

Developed by: Michael Krumdick, Tristan Mitchell, Matthew Lanus

A minimal dependency network builder styled after Caffe, built for customizability

- Disclaimer: Program currently only works on Mac machines - linux machines will receive an error

How to use the latte:

		To test latte -
	1. Navigate to the src/ directory and run make
	2. Go to the example directory and run $./latte sample.ptx final

		To use create own layers and use latte to compute results -
	1. Create a .ptx file in similar format to sample.ptx with multiple layers and functions
		To find layers that one can use please navigate to src/layers/
	2. Create an input file for the .ptx file
	3. Run $./latte <ptx.ptx> <name of last layer of .ptx file>


Benchmarks:

	Graph Traversals - 
		A took on average 0.000387 seconds
		B took on average 0.000372 seconds
		C took on average 0.000364 seconds
		D took on average 0.000385 seconds
		E took on average 0.000390 seconds
		F took on average 0.000386 seconds
		G took on average 0.000396 seconds
		H took on average 0.000379 seconds
		I took on average 0.000389 seconds
		J took on average 0.000397 seconds
		K took on average 0.000388 seconds
	
	Total time to run:
		Run time of latte for 1 rows and cols is 0.00035 seconds
		Run time of latte for 10 rows and cols is 0.00027 seconds
		Run time of latte for 100 rows and cols is 0.00029 seconds
		Run time of latte for 1000 rows and cols is 0.00040 seconds
		Run time of latte for 10000 rows and cols is 0.00046 seconds

