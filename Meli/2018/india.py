s = input()
a = len(s)
print (a)
print (a*(a+1)/2)
dicc = {s : 0}

for x in range(len(s)):
	for y in range(x+1, len(s)):
		dicc[s[x:y+1]] = 0
		print (len(dicc))

print (len(dicc))