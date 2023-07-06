from setuptools import setup, find_packages

with open("requirements.txt") as f:
	install_requires = f.read().strip().split("\n")

# get version from __version__ variable in myarbor/__init__.py
from myarbor import __version__ as version

setup(
	name="myarbor",
	version=version,
	description="Verwaltungssoftware für Bestattungswälder",
	author="Tobias Helfenstein",
	author_email="tobias.helfenstein@myarbor.de",
	packages=find_packages(),
	zip_safe=False,
	include_package_data=True,
	install_requires=install_requires
)
