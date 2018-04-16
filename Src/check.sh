for k in {20,100}
do
for d in {2,3,5,10,15,20}
do
	f1="./Results/resultskd_"$k"_"$d".txt"
	f2="./Results/resultsseq_"$k"_"$d".txt"
	diff $f1 $f2

done;
done;