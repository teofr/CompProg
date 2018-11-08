n, m, a = map(int, input().split())

mod = 998244353

def gaus(n):
	n = n * (n+1)
	n = n % mod
	n = n//2
	return n

def modexp(n, e, m):
	if e == 0:
		return 1

	p = modexp(n, e//2, m)
	p *= p
	if (e % 2 == 1):
		p *= n

	return (p % m)

def f(cut):
	return (gaus(modexp(a, cut, mod) - 1)*modexp(a, n-2*cut, mod)) % mod

b = map(int, input().split())
last = 0

ans = 0

for x in range(1, n//2 + 1):
	print('f({}): {}'.format(x, f(x)))

for bi in b:
	num = f(bi)
	# num = num * modexp(a, n - 2*bi, mod)
	num = num % mod
	# num = num*(modexp(a, last, mod))
	print('bi {}, num {}'.format(bi, num))
	# print(modexp(a, last, mod))
	# num = num % mod
	# print(num)
	ans += num
	last = bi



print(ans)
print((modexp(a, n, mod) - ans) % mod)

'''


con b1, cuento, para cada medio:
	gauss(strings dist de long b1 - 1)

con b2 

aaaaa
aaaab = baaaa
aaaba = abaaa
aaabb = baaba = bbaaa = abaab
aabaa
aabab = babaa
aabba = abbaa
aabbb = babba = bbbaa
abaab = bbaaa
ababa
ababb = bbaba
abbab = bbbaa
abbba
abbbb = bbbba
baaab
baabb
babab
babbb
bbaab
bbabb
bbbab
bbbbb

'''