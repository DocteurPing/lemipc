#!/bin/bash

for i in `seq 1 $1`
do 
	./lemipc `pwd` $2 $4 &
	./lemipc `pwd` $3 $4 &
done