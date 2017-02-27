#!/bin/bash

gcc -o BubbleSort BubbleSort.c
gcc -o ModifiedBubbleSort ModifiedBubbleSort.c

bold=$(tput bold)
normal=$(tput sgr0)

printf "\n"

for i in {1000..100000..10000}
do	
	echo "......................................   Array size:     $i"
	printf "\n"
	echo "${bold}Bubble Sort:${normal} "
	./BubbleSort $i 
	
	echo "${bold}Modified Bubble Sort:${normal} "
	./ModifiedBubbleSort $i 
	printf "\n"
done

