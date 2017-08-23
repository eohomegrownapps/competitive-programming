import sys
def sevenite(num):
	if str(num)[len(str(num))-1] == "0":
		return "Impossible"
	elif str(num)[len(str(num))-1] == "2":
		return "Impossible"
	elif str(num)[len(str(num))-1] == "4":
		return "Impossible"
	elif str(num)[len(str(num))-1] == "5":
		return "Impossible"
	elif str(num)[len(str(num))-1] == "6":
		return "Impossible"
	elif str(num)[len(str(num))-1] == "8":
		return "Impossible"

	else:
		x = 7
		while x%num != 0:
			x = int(str(x)+"7")
		return x
if __name__ == '__main__':
	nums = []
	nums.append(int(sys.stdin.readline()))#N

	print sevenite(nums[0])