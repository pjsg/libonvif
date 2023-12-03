#*******************************************************************************
# onvif-gui/setup.py
#
# Copyright (c) 2023 Stephen Rhodes 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
#******************************************************************************/

from setuptools import setup, find_packages
from setuptools.command.install import install

with open("README.md", "r", encoding = 'cp850') as fh:
    long_description = fh.read()

setup(
    name="onvif-gui",
    version="1.2.11",
    author="Stephen Rhodes",
    author_email="sr99622@gmail.com",
    description="GUI program for onvif",
    long_description=long_description,
    long_description_content_type="text/markdown",
    packages=find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.8',
    entry_points={
        'gui_scripts': [
            'onvif-gui=gui.main:run',
        ],
    }
)