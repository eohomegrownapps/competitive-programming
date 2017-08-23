import math
import sys
def rope(coords, radius):
	length = 0.0;
	for i in range(0,len(coords)-1):
		length += math.sqrt(pow(coords[i+1][1]-coords[i][1],2)+pow(coords[i+1][0]-coords[i][0],2))
	length += math.sqrt(pow(coords[len(coords)-1][1]-coords[0][1],2)+pow(coords[len(coords)-1][0]-coords[0][0],2))
	length += math.pi*2*radius
	return round(length,2)

if __name__ == '__main__':
	varis = sys.stdin.readline().rstrip("\n").split()
	varis = map(float, varis)
	coords = []
	for i in range(0,int(varis[0])):
		coords.append(map(float,sys.stdin.readline().rstrip("\n").split()))
	#print varis[1]
	#print coords
	print rope(coords,varis[1])