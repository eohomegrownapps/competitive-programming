from collections import Counter
import math
dictionary = {}

def partition(i,n,w):
	try:
		return dictionary[(i,n,w)]
	except Exception as e:
		pass
	if w==1:
		return [[1]]
	answers = [[w]]
	if w>i:
		answers = []
	for x in range(1,w):
		pa = partition(i,n-1,x)
		for j in pa:
			if (w-x)>=j[0] and (w-x)<=i and len(j)==n-1:
				answers.append([w-x]+j)
	dictionary[(i,n,w)]=answers
	return answers

q = {}

def partitionunordered(n,length):
	try:
		return q[(n,length)]
	except:
		pass
	result = [[n]]
	for i in range(1,n):
		a = n-i
		p = partitionunordered(i,length-1)
		for j in p:
			if j[0]<=a and len(j)==length-1:
				result.append([a]+j)
	q[(n,length)] = result
	return result

if __name__ == '__main__':
	p=1
	i=10
	n=5
	w=25
	if p==1:
		print len(partition(i,n,w))
		quit()
	dicti = {}
	if w<=i:
		dicti[1] = 1
	else:
		dicti[1] = 0
	for z in range(2,n):
		dicti[z] = len(partition(i,z,w))
	print dicti
	#print len(partition(1,1,20,20))
	#print dictionary

	parts = partitionunordered(n,p)
	parts.pop(0)
	print parts
	total = 0
	for pa in parts:
		val = 1
		for item in pa:
			val = val*dicti[item]
		vals = Counter(pa).values()
		tot = math.factorial(len(pa))
		div = 1
		for v in vals:
			div = div*math.factorial(v)
		tot = tot/div
		tot = tot*val
		total = total+tot
	print total