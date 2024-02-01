from setuptools import find_packages
from setuptools import setup

setup(
    name='digipot_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('digipot_interfaces', 'digipot_interfaces.*')),
)
