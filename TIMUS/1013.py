import sys
def kbasednumbers (base, n):
	digits = []
	for i in range(0, n+1):
		digits.append([0,0])
	digits[0][0] = base-1
	digits[0][1] = 0
	if n == 2:
		return base*(base-1)
	for i in range(2, n+1):
		digits[i-1][0] = ((digits[i-2][0])*base)-(digits[i-2][1])
		digits[i-1][1] = (digits[i-2][0]-digits[i-2][1])
	return digits[n-1][0]
	#return digits


if __name__ == '__main__':
	nums = []
	nums.append(int(input()))#N
	nums.append(int(input()))#K
	nums.append(int(input()))#M

	print kbasednumbers(nums[1], nums[0]%nums[2])