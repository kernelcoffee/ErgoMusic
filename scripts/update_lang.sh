#!/bin/sh

# make sure you have lupdate and lrealse from QT5 in you path

cd ../src/ && lupdate ErgoMusic.pro && lrelease ErgoMusic.pro
