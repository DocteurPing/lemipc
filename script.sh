#!/bin/bash

for i in `seq 1 $1`
do 
	./lemipc `pwd` $2 &
	sleep 0.1
done