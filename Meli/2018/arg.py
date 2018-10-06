# s = 'a'
# cnt = 18

# while cnt:
# 	cnt -= 1
# 	t = ''
# 	for c in s:
# 		if c == 'a':
# 			t += ('al')
# 		if c == 'l':
# 			t += ('paca')
# 		if c == 'p':
# 			t += ('cp')
# 		if c == 'c':
# 			t += ('pc')

# 	# print (t)
# 	print (s.count('alpaca'), end=', ')
# 	s = t


'''
(2**cant + 1) / 3 = x (mod m)
2**cant + 1 = 3*x + km = bla + k'm
2**cant = 3x + km - 1 = bla + k'm

'''

m = 123456789
def power(base, exp):
    """ Fast power calculation using repeated squaring """
    if exp < 0:
        return 1 / power(base, -exp)
    ans = 1
    while exp:
        if exp & 1:
            ans = (ans*base)%m
        exp >>= 1
        base = (base*base)%m
    return ans

def f(n):
    if n % 2 ==0:
        return 1
    else:
        return -1

cant = 1

cant = 234612846789231-1
# cant = 3
print((power(2, cant)-f(cant)))
print(((power(2, cant)-f(cant)))%m)
bla = ((power(2, cant)-f(cant)))%m

for x in range(m):
    if 3*x % m == bla:
        print (x)

# J = [0, 1]

# cant = 10

# for x in range(2, cant):
# 	J.append((J[x-1] + 2*J[x-2])%m)


# print(J)
