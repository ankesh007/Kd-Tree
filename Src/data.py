import random

n1=100000
n2=100
for d in [2,3,5,10,15,20]:

	f = open('./Data/data' + str(d) + '.txt','w')
	f.write(str(d)+" "+str(n1)+"\n")

	for i in range(n1):
		for j in range(d):
			f.write(str(random.uniform(0,1))+" ")
		f.write('\n')


	q = open('./Data/query' + str(d) + '.txt', 'w')
	q.write(str(d)+" "+str(n2)+"\n")
	for i in range(n2):	
		for j in range(d):
			q.write(str(random.uniform(0, 1)) + " ")
		q.write('\n')
	q.close()

	print("d={} done".format(d))
