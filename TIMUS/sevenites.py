def sevenite(num):
	if str(num)[len(str(num))-1] == 0 or str(num)[len(str(num))-1] == 2 or str(num)[len(str(num))-1] == 4 or str(num)[len(str(num))-1] == 5 or str(num)[len(str(num))-1] == 6 or str(num)[len(str(num))-1] == 8:
		return "Impossible"
	else:
		x = 7
		while x%num != 0:
			x = int(str(x)+7)