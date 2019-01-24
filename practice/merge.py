import os

os.system('wget -r -np -nd --accept=zip https://www.comp.nus.edu.sg/~cs1010/practice/2017s1/')

currentFolder = os.getcwd() + '/'

Makefile_content = """.SILENT: samplerun
CC=clang
LDLIBS=-lm -lcs1010
INCLUDEDIR=~cs1010/include
CFLAGS=-g -Wall -I $(INCLUDEDIR) -L $(LIBDIR)
LIBDIR=~cs1010/lib

all: %s samplerun

samplerun:
	./test.sh %s %d
"""

testsh_content = """#!/bin/bash

function control_c() {
  if [ -e $out ] 
  then
    rm $out
  fi
}
trap control_c INT

PROG=$1
if [ ! -e $PROG ]
  then
    echo "$PROG does not exist.  Have you compiled it with make?"
    exit 1
  fi

NUM_OF_TEST_CASES=$2
num_failed=0
num_passed=0
for i in $(seq 1 $NUM_OF_TEST_CASES)
do
  out=$(mktemp --suffix=$PROG)
  ./$PROG < ../testdata/input/$PROG$i.in > $out
  if [ -e $out ] 
  then
    if [ `diff -bB $out ../testdata/output/$PROG$i.out | wc -l` -ne 0 ] 
      then
      echo "$PROG: incorrect output for test case $i"
      num_failed=$((num_failed + 1))
    else
      num_passed=$((num_passed + 1))
    fi
    rm $out
  fi
done
if [ $num_passed -eq $NUM_OF_TEST_CASES ] 
then
  echo "$PROG: passed"
fi
"""


def writeFile(folderName):
    skeletonName = os.listdir(currentFolder + folderName + '/skeleton/')
    testcaseInputFile = os.listdir(currentFolder + folderName + '/testdata/input/')
    testcaseOutputFile = os.listdir(currentFolder + folderName + '/testdata/output/')
    testcaseNum = len(testcaseInputFile)
    for i in range(testcaseNum):
        try:
            os.system('mv -f ' + currentFolder + folderName + '/testdata/input/' + testcaseInputFile[
                i] + ' ' + currentFolder + folderName + '/testdata/input/' + skeletonName[0][:-2] + str(i + 1) + '.in')
        except:
            pass
        try:
            os.system('mv -f ' + currentFolder + folderName + '/testdata/output/' + testcaseOutputFile[
                i] + ' ' + currentFolder + folderName + '/testdata/output/' + skeletonName[0][:-2] + str(
                i + 1) + '.out')
        except:
            pass
    with open(currentFolder + folderName + '/skeleton/Makefile', 'w') as f:
        f.write(Makefile_content % (skeletonName[0][:-2], skeletonName[0][:-2], testcaseNum))
    with open(currentFolder + folderName + '/skeleton/test.sh', 'w') as f:
        f.write(testsh_content)
        os.system('chmod +x ' + currentFolder + folderName + '/skeleton/test.sh')


filename = os.listdir(currentFolder)

for zipName in filename:
    if not (('merge' in zipName) or ('Separate' in zipName)):
        os.system('unzip ' + zipName)
        writeFile(zipName[:-4])

os.system('rm -rf *.zip')