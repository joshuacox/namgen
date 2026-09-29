from setuptools import setup, find_packages

setup(
    name="namgen",
    version="1.0.0",
    author="Joshua Cox",
    description="High-performance procedural fantasy and real-world name generator with 900+ modules",
    long_description=open("README.md").read() if open("README.md") else "",
    long_description_content_type="text/markdown",
    url="https://github.com/joshuacox/namgen",
    packages=find_packages(),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: OS Independent",
        "Topic :: Games/Entertainment",
    ],
    python_requires=">=3.8",
)
