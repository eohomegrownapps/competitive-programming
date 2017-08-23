import sys

telephone = [['o','q','z'],['i','j'],['a','b','c'],['d','e','f'],['g','h'],['k','l'],['m','n'],['p','r','s'],['t','u','v'],['w','x','y']]
def howMany(arr, words):
	l = len(arr)
	if (l<len(words)):
		dictionary = words[l]
		w = isValid(arr,dictionary)
		return w
	return False

def isValid(arr, words):
	if words!=None:
		for i in words:
			check = True
			for j in range(0,len(arr)):
				if (i[j] not in telephone[arr[j]]):
					check = False
			if check == True:
				return i
	return False
def answer(num, words):
	array = []
	for i in range(0, len(num)):
		array.append([0,""])
	val = howMany([num[0]],words)
	if val != False:
		array[0] = [1,val]
	#print num
	for i in range(1, len(num)):
		#print "i"
		#print i
		#print array
		temparr = []
		valids = []
		for j in range(0, i):
			val = False
			if j!=0:
				if array[j-1][0]!=0:
					section = num[j:i+1]
					val = howMany(section, words)
			else:
				section = num[j:i+1]
				val = howMany(section, words)
			if val!=False and j!=0:
				temparr.append([array[j-1][0]+1,array[j-1][1]+" "+val])
			elif val!=False and j==0:
				temparr.append([1,val])
			else:
				temparr.append(-1)
		mini = -1;
		for a in range(0,len(temparr)):
			if temparr[a]!=-1:
				if mini==-1:
					mini = a
				elif temparr[a][0]<temparr[mini][0]:
					mini = a
			#print mini
		if mini!=-1:
			array[i] = temparr[mini]
		#print temparr
		#print array
	if array[i][0]==0:
		return "No solution."
	return array[i][1]


if __name__ == '__main__':
	num = sys.stdin.readline()
	while int(num.rstrip('\n'))!=-1:
		num = list(num)
		num.pop()
		num = map(int, num)
		wl = int(sys.stdin.readline().rstrip('\n'))
		words = [None]*51
		for i in range(0,wl):
			wor = sys.stdin.readline().rstrip('\n')
			if (words[len(wor)])==None:
				words[len(wor)]=[wor]
			else:
				words[len(wor)].append(wor)
		#print words
		print answer(num, words)
		num = sys.stdin.readline()