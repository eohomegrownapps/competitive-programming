#Python 2.7
import sys
def zombieshit(zombies, trees, beam):
	zombiecount = 0
	for z in zombies:
		zombiex = z[0]-beam[0]
		zombiey = z[1]-beam[1]
		#print "zombiex"+str(zombiex)
		#print "zombiey"+str(zombiey)
		equal = 0
		for i in trees:
			gradx = i[0]-beam[0]
			grady = i[1]-beam[1]
			#print gradx
			#print grady
			#print str(gradx*zombiey)+"="+str(grady*zombiex)
			if gradx*zombiey == grady*zombiex:
				#print "equal"
				equal = 1
		if equal == 0:
			zombiecount = zombiecount + 1
	return zombiecount

if __name__ == '__main__':
	zombies = []
	trees = []
	zombiesno = int(sys.stdin.readline())
	for i in range(0, zombiesno):
		zombies.append(map(int,sys.stdin.readline().split()))
	#print zombies
	treesno = int(sys.stdin.readline())
	for i in range(0, treesno):
		trees.append(map(int,sys.stdin.readline().split()))
	#print trees
	print zombieshit(zombies,trees,map(int,sys.stdin.readline().split()))

		