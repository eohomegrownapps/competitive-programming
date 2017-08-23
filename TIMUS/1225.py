def flags(num):
	digits = []
	for i in range(0, num+1):
		digits.append([0,0])
	digits[0][0] = 2
	digits[0][1] = 0
	if num==1:
		return 2
	for i in range(2, num+1):
		digits[i-1][0] = (digits[i-2][0]*2)-digits[i-2][1]
		digits[i-1][1] = digits[i-2][0]-digits[i-2][1]
	return digits[i-1][0]-digits[i-1][1]

if __name__ == '__main__':
	nums = []
	nums.append(int(input()))#N

	print flags(nums[0])