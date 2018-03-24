#!/bin/bash

for i in `seq 1 $1`
do 
	./lemipc `pwd` $2 -n &
	./lemipc `pwd` $3 -n &
done