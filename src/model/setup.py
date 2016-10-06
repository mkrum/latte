#! /usr/bin/env python2.7

from distutils.core import setup, Extension
 
ext = Extension('latte', sources=['lattemodule.cpp', 'model.cpp', '../layers/debug.cpp'], include_dirs=['../../include'], language="c++",)
 
setup(name='latte', version='0.0.1', description='Machine Learning Network Builder', ext_modules=[ext])
