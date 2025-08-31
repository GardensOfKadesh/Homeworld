# Compiling the GoK Engine From Source

The GoK project (this repository) contains the source code to compile an executable/binary to play Homeworld.
(That binary will be useless without the assets from the original game.)

This page assumes you have no knowledge of software development and compilers.
Feel free to skip some sections if you do.

If this documentation was not enough to let you build and run the game, then please [let us know!][open an issue]

("build" and "compile" are used interchangeably in this documentation.
They basically mean the same thing.)

[open an issue]: /documentation/community/README.md#opening-an-issue

## Overview

1. You will need to download the code in this repository
2. You will need to install tools and libraries to build the code.
3. Once you have these tools and libraries, you will need to follow some instructions to use them to translate the source code into an executable.

These tools will vary depending on your Operating System (OS), so we have separate documentation for each:

- [Linux](/Linux/BUILD.md)
- [MacOS](/Mac/BUILD.md)
- [Windows](/Windows/readme.txt)

However these documentations are in various states of disrepair ([contributions welcome!](/documentation/README.md#helping-with-documentation)), so it might sometimes help to read that of another OS for pointers.

If *Homeworld* were a bicycle, then *GoK* would be like a new frame that you have to build to replace the old one.

To build that new frame, you need the blueprints (the source code), and a factory (the build tools, compilers, and libraries).
When you have the factory set up, you can change the blueprints to build as many different frames as you wish!
(This is what software developers do)

## Build tools

Regardless of your OS, you should expect to install the following to build GoK:

 - Meson (a build system)
 - A C compiler (e.g. GCC or Clang)
 - SDL2 (*the* cross-platform game library)
 - yacc & flex (domain-specific parsers and translators for the scripts of the single-player campaign)
