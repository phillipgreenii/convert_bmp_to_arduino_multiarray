'''
convert_bmp_to_arduino_multiarray: Converts BMP into an arduino multiarray.

Note that "python setup.py test" invokes pytest on the package. With appropriately
configured setup.cfg, this will check both xxx_test modules and docstrings.

Copyright 2016, Phillip Green II.
Licensed under MIT.
'''
from codecs import open
from os import path
import sys

from setuptools import setup, find_packages
from setuptools.command.test import test as TestCommand


# This is a plug-in for setuptools that will invoke py.test
# when you run python setup.py test
class PyTest(TestCommand):
    def finalize_options(self):
        TestCommand.finalize_options(self)
        self.test_args = ['--cov-report', 'term', '--cov', 'convert_bmp_to_arduino_multiarray']
        self.test_suite = True

    def run_tests(self):
        import pytest  # import here, because outside the required eggs aren't loaded yet
        sys.exit(pytest.main(self.test_args))

here = path.abspath(path.dirname(__file__))

with open(path.join(here, 'README.rst'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='convert_bmp_to_arduino_multiarray',

    version='0.1.0',

    description='This project converts a BMP into a multi array that can be used on an arduino.',
    long_description=long_description,

    url='https://github.com/phillipgreenii/convert_bmp_to_arduino_multiarray',

    author='Phillip Green II',
    author_email='phillip.green.ii@gmail.com',

    license='MIT',

    classifiers=[
        'Development Status :: 3 - Alpha',

        'License :: OSI Approved :: MIT License',

        'Programming Language :: Python',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7'
    ],

    keywords='arduino image bmp',

    packages=find_packages(exclude=['examples', 'tests']),

    include_package_data=True,

    install_requires=['Pillow', 'numpy'],

    tests_require=['pytest', 'pytest-cov'],
    cmdclass={'test': PyTest},

    extras_require={
    }
)
