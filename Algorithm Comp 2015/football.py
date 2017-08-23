import sys
n = int(sys.stdin.readline())
teams = []
def index2d(myList, v):
    for i, a in enumerate(myList):
        if v in a:
            return [i, a.index(v)]
names = []
for i in range(1,n+1):
	x = sys.stdin.readline()
	team = (x.split(":"))[0]
	first = team.split("-")[0]
	second = team.split("-")[1]
	if (first in names) == False:
		teams.append([first, 0])
		names.append(first)
	if (second in names) == False:
		teams.append([second, 0])
		names.append(second)
	indf = index2d(teams, first)
	inds = index2d(teams, second)
	scores = (x.split(":"))[1]
	firstscore = int((scores.split("-"))[0])
	secondscore = int((scores.split("-"))[1])
	if firstscore == 1 and secondscore == 0:
		teams[indf[0]][1]=teams[indf[0]][1]+2
	elif firstscore == 0 and secondscore == 1:
		teams[inds[0]][1]=teams[inds[0]][1]+2
	elif firstscore == secondscore:
		teams[indf[0]][1] = teams[indf[0]][1]+1
		teams[inds[0]][1] = teams[inds[0]][1]+1
	elif firstscore > secondscore:
		teams[indf[0]][1]=teams[indf[0]][1]+3
	else:
		teams[inds[0]][1]=teams[inds[0]][1]+3

teams.sort(key=lambda team: team[0]) 
for i in range(0, len(teams)):
	print teams[i][0]+" "+str(teams[i][1])
