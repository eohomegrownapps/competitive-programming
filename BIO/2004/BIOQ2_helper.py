def partition(n,r):
	if r==0:
		return [[n]]
	lis = []
	for i in range(0,n-r+1):
		temp = partition(n-i,r-1)
		for l in temp:
			l.append(i)
			lis.append(l)
	return lis

if __name__ == '__main__':
	p = partition(21,6)
	print len(p)
	abc = []
	for i in p:
		check = True
		for j in i:
			if j>6:
				check = False
		if check==True:
			abc.append(i)
	print abc
	print len(abc)

