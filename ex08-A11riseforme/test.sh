#!/bin/bash
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
  # Please stop here, you are not allowed to see the test cases this time.
  openssl enc -aes-256-cbc -in inputs/$PROG.$i.in -d -pass pass:"$PROG.$i.in*@J#*Hs8drewh9rh3942her7H&H37" | ./$PROG > $out
  if [ `diff -bB $out <(openssl enc -aes-256-cbc -d -pass pass:"$PROG.$i.out*@J#*Hs8drewh9rh&H37" -in outputs/$PROG.$i.out) | wc -l` -ne 0 ] 
	  then
		echo "$PROG: incorrect output for test case $i"
		num_failed=$((num_failed + 1))
	else
		num_passed=$((num_passed + 1))
  fi
  rm $out
done
if [ $num_passed -eq $NUM_OF_TEST_CASES ] 
then
  echo "$PROG: passed"
fi
