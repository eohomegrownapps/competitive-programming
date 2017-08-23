#Python 2.7
import sys
def fiftypercent(voters):
	if voters%2==0:
		return (voters/2)+1
	else:
		return (voters+1)/2

def totalmoney(constituencies):
	finalamount = 0
	moneyperconst = []
	for i in constituencies:
		moneyperconst.append(fiftypercent(i[0])*i[1])
	money = sorted(moneyperconst)
	numberofconsts = fiftypercent(len(money))
	for i in range(0, numberofconsts):
		finalamount = finalamount+money[i]
	return finalamount

if __name__ == '__main__':
	nos = int(sys.stdin.readline())
	consts = []
	for i in range(0, nos):
		consts.append(map(int,sys.stdin.readline().split()))
	print totalmoney(consts)
