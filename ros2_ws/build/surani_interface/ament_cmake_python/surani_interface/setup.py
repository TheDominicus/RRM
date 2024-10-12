from setuptools import find_packages
from setuptools import setup

setup(
    name='surani_interface',
    version='0.0.0',
    packages=find_packages(
        include=('surani_interface', 'surani_interface.*')),
)
