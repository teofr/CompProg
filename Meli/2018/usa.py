casos = int(input())

def prefix(a, b):
	ans = 0
	for x in range(min(len(a), len(b))):
		if a[x] != b[x]:
			return ans
		ans += 1
	return ans

for x in range(casos):
	s = input()
	ans = 0
	t = s

	while len(t) > 0:
		ans += prefix(s,t)
		t = t[1:]

	print (ans)