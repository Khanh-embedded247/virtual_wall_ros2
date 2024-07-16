from setuptools import find_packages
from setuptools import setup

setup(
    name='virtual_wall',
    version='0.0.1',
    packages=find_packages(
        include=('virtual_wall', 'virtual_wall.*')),
)
