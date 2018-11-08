chars = ['a', 'b']

def append(a):
	return lambda b : b + a


l = ['']

for x in range(5):
	l = [append(c)(li) for li in l for c in chars]

print(l)

b = [2]

for bi in b:
	l2 = l.copy()
	for li in l:
		# print(li)
		lit = li[-bi:][::-1] + li[bi:-bi] + li[:bi][::-1]
		# print(lit)
		if lit != li and (lit in l2) and (li in l2): l2.remove(lit)
	l = l2.copy()

print(l)
print(len(l))

'''



aaaaa
aaaab = baaaa
aaaba = abaaa
aaabb = bbaaa
aabaa
aabab = babaa
aabba = abbaa
aabbb = bbbaa
abaab = baaba
ababa
ababb = bbaba
abbab = babba
abbba
abbbb = bbbba
baaab
baabb = bbaab
babab
babbb = bbbab
bbabb
bbbbb



aaaaa
aaaab = baaaa
aaaba = abaaa
aaabb = bbaaa = baaba = abaab
aabaa
aabab = babaa
aabba = abbaa
aabbb = bbbaa = babba = abbab
ababa
ababb = bbaba
abbba
abbbb = bbbba
baaab
baabb = bbaab
babab
babbb = bbbab
bbabb
bbbbb