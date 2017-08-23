import sys
def manifesto(v,c,manif):
	manif = manif.lower()
	manif = manif.replace(" ", "")

	x = 0
	for i in range(1, len(manif)):
		if manif[i-1] == 'a':
			x = x+1

		if manif[i-1] == 'e':
			x = x+1

		if manif[i-1] == 'i':
			x = x+1

		if manif[i-1] == 'o':
			x = x+1

		if manif[i-1] == 'u':
			x=x+1
	return (v*x)+(c*(len(manif)-1-x))

if __name__ == '__main__':
	nums = []
	nums.append(int(sys.stdin.readline()))#N
	nums.append(int(sys.stdin.readline()))#K
	mani = str(sys.stdin.readline())
	print manifesto(nums[0], nums[1], mani)