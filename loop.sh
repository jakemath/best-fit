#!/bin/bash
i=10
while [ $i -lt 1010 ]; do
	./main 1000 $i >> out.txt
	let i=i+10
done
