#!/usr/bin/env python

import setuptools

setuptools.setup(
    name='blocksparse-kite',
    version='1.15.2',
    description='Tensorflow ops for blocksparse matmul, transformer, convolution and related operations.',
    install_requires=[
        'numpy',
        'scipy',
        # We don't depend on `tensorflow` or `tensorflow-gpu` here, since one or the other is sufficient.
    ],
    packages=['blocksparse'],
    package_data={ 'blocksparse': ['blocksparse_ops.so'] },
    url='https://github.com/kiteco/blocksparse',
    license='MIT')
