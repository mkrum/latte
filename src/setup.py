#! /usr/bin/env python2.7

import os

from distutils.core import setup, Extension

comp = []

def all_cpp():
    ret = []
    for root, dirs, files in os.walk('.'):
        for f in files:
            if f[-3:] == 'cpp':
                ret.append(root+'/'+f)
    return ret

def from_dir(d):
    ret = []
    for root, dirs, files in os.walk(d):
        for f in files:
            if f[-3:] == 'cpp':
                ret.append(root+'/'+f)
    return ret

files = from_dir('model') + from_dir('layers') + from_dir('matrix')

ext = Extension('latte', sources=files, include_dirs=['../include'], language="c++",)
 
setup(name='latte', version='0.0.1', description='Machine Learning Network Builder', ext_modules=[ext])
