#! /usr/bin/env python2.7

import latte

latte.add_layer('data')
latte.add_layer('debug')

print latte.forward()
