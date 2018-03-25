#!/bin/bash

for i in `seq 1 $1`
do 
	./lemipc `pwd` $2 &
	./lemipc `pwd` $3 &
done