#Python 2.7
import math
import sys

def breakcoindown(coin):
	result = []
	result.append(math.floor(coin/3))
	#print math.floor(coin/3)
	result.append(math.floor(coin/2))
	#print math.floor(coin/2)
	result.append(math.floor(coin/4))
	#print math.floor(coin/4)
	return result



def coins(coin):
	dollars = 0
	arr = breakcoindown(coin)
	if sum(arr)<coin:
		return coin
	for i in arr:
		dollars = dollars+coins(i)
	return dollars

if __name__ == '__main__':
	print int(coins(int(sys.stdin.readline())))