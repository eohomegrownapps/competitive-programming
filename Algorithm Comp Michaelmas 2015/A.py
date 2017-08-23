#Python 2.7
import sys
def grades(grade):
	badgrades = 0
	for i in grade:
		if ("4" in i) | ("5" in i) | ("S" in i) | ("P" in i):
			badgrades = badgrades+1
	return badgrades

if __name__ == "__main__":
	num = int(sys.stdin.readline())
	grade = []
	for i in range(0,num):
		grade.append(sys.stdin.readline())
	print grades(grade)