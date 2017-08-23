#Python 2.7
import itertools
import sys
def sticks(arr):
	#print arr
	for i in range(0, len(arr)):
		sticksavailable = []
		for c in itertools.combinations(arr, len(arr)-i):
			dupl = 0
			for st in sticksavailable:
				if sorted(st) == sorted(list(c)):
					dupl = 1
			if dupl == 0:
				sticksavailable.append(list(c))

		for k in sticksavailable:
			#print k
			accept = 1
			for j in k:
				#print "j"+str(j)
				#print sum(arr)-j
				if j>(sum(arr)-j):
					accept = 0
			if accept == 1:
				return len(arr)-i 

if __name__ == '__main__':
	num = int(sys.stdin.readline())
	arr = []
	for i in range(0,num):
		arr.append(int(sys.stdin.readline()))
	print sticks(arr)