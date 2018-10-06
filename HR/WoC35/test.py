def f(n, k):
	if n == 1:
		return 1
	return n**k + f(n-1, k)

def fact(a):
	if a == 1:
		return 1
	return a*fact(a-1)

def gauss(n):
	return (n*(n+1))//2

def g(n, k):
	cur = 0
	res = 0
	while cur < k:
		res += (n-cur)*(n-cur+1)*(n-cur+2)*(n-cur+3)
		cur += 1
	return res//(k*(k+1))
	
for x in range(1, 21):
	print ("{}: {} = {} ({})".format(x, g(x, 3), f(x, 3), gauss(x)))