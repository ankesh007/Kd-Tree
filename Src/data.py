import random

n=100000

for k in [2,3,5,10,15,20]:

	f = open('./Data/data' + str(k) + '.txt','w')
	f.write(str(k)+" "+str(n)+"\n")
	
	for i in range(n):
		for j in range(k):
			f.write(str(random.uniform(0,1))+" ")
		f.write('\n')

	for i in range(100):	
		q = open('./Data/query' + str(k) +'-'+str(i)+ '.txt', 'w')
		q.write(str(k)+"\n")
		for j in range(k):
			q.write(str(random.uniform(0, 1)) + " ")
		q.write('\n')
		q.close()

	print("k={} done".format(k))