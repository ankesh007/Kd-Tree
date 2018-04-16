#!/bin/bash
# python3 data.py
echo "data generated";

rm -f graph.csv
touch graph.csv
rm -f KdTree
for k in {20,100}
do
echo "">error$k;
for d in {2,3,5,10,15,20}
do

	echo "For d=$d k=$k";
	datafile="./Data/data"$d".txt"
	queryfile="./Data/query"$d".txt"
	echo "$d">>error$k;
	python3 parent1.py  $datafile $queryfile $k $d 2>> error$k
	echo "-----------------" >>error$k
	
	echo "---------------------------";

done;	
done;	
rm -f KdTree
