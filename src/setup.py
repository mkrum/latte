#! /usr/bin/env python2.7

from setuptools import find_packages, Command
from distutils.core import setup, Extension
import os
import sys

comp = []

def from_dir(d):
    ret = []
    for root, dirs, files in os.walk(d):
        for f in files:
            if f[-3:] == 'cpp' or f[-1] == 'c':
                ret.append(root+'/'+f)
    return ret

def read_layer_defs(d):
    ret = []
    for root, dirs, files in os.walk(d):
        for f in files:
            if f[-3:] == 'ptx':
                new_layer = Layer()
                new_layer.read_path(root+'/'+f)
                ret.append(new_layer.get_source())
    return ret

files = from_dir('model')# + from_dir('matrix') + from_dir('utils') + from_dir('layers')# + read_layer_defs('layer_defs')
ext_make = Extension('latte.make', sources=files, include_dirs=['../include'], language="c++")

setup(name='latte', version='0.0.1', packages=find_packages(), description='Machine Learning Network Builder', ext_modules=[ext_make])
