poss = 0
def splitamount(amount, arr, num):
	print amount
	print arr
	print len(arr)
	print num
	global poss
	if len(arr) == 1:

		if amount == arr[0]:
			num = num+1
			return num
		else:
			return False
	x = 0
	array = arr
	print "arr[0] ="+str(arr[0])
	while (arr[0]*x)<amount+1:
		x = x+1
	x = x-1
	print "x="+str(x)
	oldarr = arr[0]
	del arr[0]
	while x != 0:
		amo = splitamount(amount-(oldarr*x), arr, num+1)
		if amo != False:
			if poss == 0:
				poss = amo
			elif amo < poss:
				poss = amo
		x = x-1
splitamount(30, [1,10,25],0)
print poss

