#!/bin/python3

import sys

from fractions import Fraction
#from scipy.special import binom as binomial

mod = 1000000009

fact = [1]
for n in range(1, 1010):
    fact.append(n*fact[n-1])

combo = {}
def comb(p):
    n, k = p
    """
    if k == n or k == 0:
        return 1
    if not p in combo:
        combo[p] = (comb((n-1, k-1)) + comb((n-1, k)))
        """
    return fact[n]//(fact[k]*fact[n-k])

berno = {}
def Bern(n):
    return bern[n]
    if n == 0:
        return 1
    if not n in berno:
        res = Fraction(0, 1)
        for k in range(n):
            res += Fraction((comb((n, k))*Bern(k)), (n-k+1))
        berno[n] = -res
    return berno[n]


combi = [[0 for x in range(1010)] for y in range(1010)]
#bl
"""
for n in range(1, 1005):
    for k in range(0, n+1):
        if k == n or k == 0:
            combi[n][k] = 1
        else:
            combi[n][k] = combi[n-1][k-1] + combi[n-1][k]
"""

bern = [Fraction(1, 1)]
for n in range(1, 1001):
    res = Fraction(0, 1)
    for k in range(n):
        res += Fraction((comb((n, k))), (n-k+1))*bern[k]
    bern.append(-res)


def bernouilli_gen(init=1):
    """generator of Bernouilli numbers
    :param init: int -1 or +1. 
    * -1 for "first Bernoulli numbers" with B1=-1/2
    * +1 for "second Bernoulli numbers" with B1=+1/2
    https://en.wikipedia.org/wiki/Bernoulli_number
    https://rosettacode.org/wiki/Bernoulli_numbers#Python:_Optimised_task_algorithm
    """
    B, m = [], 0
    while True:
        B.append(Fraction(1, m+1))
        for j in range(m, 0, -1):
            B[j-1] = j*(B[j-1] - B[j])
        yield init*B[0] if m==1 else B[0]# (which is Bm)
        m += 1
            
def faulhaber(n,p):
    """ sum of the p-th powers of the first n positive integers
    :return: 1^p + 2^p + 3^p + ... + n^p
    https://en.wikipedia.org/wiki/Faulhaber%27s_formula
    """
    s=0
    for j,a in enumerate(bernouilli_gen()):
        if j>p : break
        s=s+comb((p+1,j))*a*n**(p+1-j)
    return s//(p+1)

def exp(b, e):
    if e <= 2:
        return b**e
    return exp(b, e//2)**2 * (b if e%2==1 else 1)

def sum(n, a):
    ans = 0
    for i in range(0, a+1):
        sgn = 1
        if i % 2 == 1:
            sgn = -1
        tmp = sgn*combi[a+1][i]#((a+1, i))
        #tmp = tmp % mod
        tmp *= bern[i]
        #tmp = tmp% mod
        tmp *= exp(n, a+1-i)
        #tmp = tmp % mod
        #ans += sgn*comb((a+1, i))*Bern(i)*modExp((n, a+1-i))
        ans = (ans+tmp)#%mod
        #ans = int(ans)
        #print ("i {} => {} comb: {} Bern: {} modExp: {}".format(i, ans, comb((a+1, i)), Bern(i), modExp((n, a+1-i))))
    return ans//(a+1)

def highwayConstruction(n, k):
    if n == 1:
        return 0
    return (sum(n-1, k)-1)%mod
    # Complete this function

#print (comb((500, 200)))
#exit(0)

for x in range(int(1e18), int(1e18)+1):
    for y in range(800, 1000):
        print ("{} {} -> {}".format(x, y, highwayConstruction(x, y)))

