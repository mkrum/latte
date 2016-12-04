#! /usr/bin/env python2.7

from latte.proto.read import PTX
from latte.make import model
f = PTX('sample.ptx')
layers = f.compose()

ml = model()

for l in layers:
    ml.add_layer(l[0], l[1], l[2], l[3], l[4])

ml.run()
