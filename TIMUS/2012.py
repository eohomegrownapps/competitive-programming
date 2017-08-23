def grisha(f):
	probs = 12-f
	if 45*probs < 241:
		return "YES"
	else:
		return "NO"

if __name__ == '__main__':
	nums = []
	nums.append(int(input()))#N

	print grisha(nums[0])