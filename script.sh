#!/bin/bash

for i in `seq 1 $1`
do 
	./lemipc `pwd` $2 $5 &
	./lemipc `pwd` $3 $5 &
	./lemipc `pwd` $4 $5 &
done