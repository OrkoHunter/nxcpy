#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import print_function

from glob import glob
import os
import sys

from setuptools import setup, Extension
from Cython.Build import cythonize

if sys.version_info[:2] < (2, 7):
    print(
        'nxcpy requires Python version 2.7 or later' +
        ' ({}.{} detected).'.format(*sys.version_info[:2]))
    # Because networkx does
    sys.exit(-1)

libraries = [
    ('nxcpy', {'sources': glob('src/*.c') + glob('src/*/*.c'),
               'depends': glob('src/*.h') + glob('src/*/*.h'),
               'include_dirs': ['src']})]

ext_modules = cythonize([
    Extension('*.*', ['*/*.pyx'],
        include_dirs=['src'],
        libraries=['nxcpy']),
    Extension('*.*.*', ['*/*/*.pyx'],
        include_dirs=['src'],
        libraries=['nxcpy'])]
)


install_requires = ['networkx', 'decorator']

if __name__ == "__main__":

    setup(
        name             = 'nxcpy',
        packages         = ['nxcpy'],
        libraries        = libraries,
        ext_modules      = ext_modules,
        install_requires = install_requires,
        test_suite       = 'nose.collector',
        tests_require    = ['nose>=0.10.1']
    )
