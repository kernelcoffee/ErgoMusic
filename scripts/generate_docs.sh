#!/bin/sh

cd ../docs && doxygen Doxyfile && cd html && qhelpgenerator index.qhp