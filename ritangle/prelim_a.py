i = 0
while True:
	s = str(i)
	b = True
	for j in range(0,len(s)):
		x = int(s[j])
		if s.count(str(j))!=x:
			b = False
	if b==True:
		print s
	i+=1