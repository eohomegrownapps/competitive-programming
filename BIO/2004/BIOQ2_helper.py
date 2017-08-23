def partition(n,r):
	if r==0:
		return [[n]]
	lis = []
	for i in range(1,n-r+1):
		temp = partition(n-i,r-1)
		for l in temp:
			l.append(i)
			lis.append(l)
	return lis

if __name__ == '__main__':
	p = partition(21,7)
	print len(p)
	abc = []
	for i in p:
		check = True
		for j in i:
			if j>7:
				check = False
		if check==True:
			abc.append(i)
	print abc
	print len(abc)

