q = {1:[[1]]}

def partition(n):
	try:
		return q[n]
	except:
		pass
	result = [[n]]
	for i in range(1,n):
		a = n-i
		p = partition(i)
		for j in p:
			if j[0]<=a:
				result.append([a]+j)
	q[n] = result
	return result

if __name__ == '__main__':
	print partition(5)