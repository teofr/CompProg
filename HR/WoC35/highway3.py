#!/bin/python3

import sys

from fractions import Fraction
#from scipy.special import binom as binomial

mod = 1000000009

fact = [1]
for n in range(1, 1010):
    fact.append(n*fact[n-1])

def comb(p):
    n, k = p
    return fact[n]//(fact[k]*fact[n-k])


bern = [Fraction(1, 1)]
for n in range(1, 1001):
    res = Fraction(0, 1)
    if n==1 or n%2==0 or True:
        for k in range(n):
            res += Fraction((comb((n, k))), (n-k+1))*bern[k]
    bern.append(-res)


#print("hola")

def exp(b, e):
    if e <= 2:
        return b**e
    return exp(b, e//2)**2 * (b if e%2==1 else 1)

def sum(n, a):
    ans = Fraction(0, 1)
    for i in range(0, a+1):
        if (i==1) or (i%2==0):
            print(i)
            print(bern[i])
            sgn = 1
            tmp = Fraction(sgn*comb((a+1, i))*exp(n, a+1-i), 1)*bern[i]
            #tmp = tmp % mod
            #tmp *= bern[i]
            #tmp = tmp% mod
            #tmp *= exp(n, a+1-i)
            #tmp = tmp % mod
            #ans += sgn*comb((a+1, i))*Bern(i)*modExp((n, a+1-i))
            ans += tmp#%mod
            #ans = int(ans)
            #print ("i {} => {} comb: {} Bern: {} modExp: {}".format(i, ans, comb((a+1, i)), Bern(i), modExp((n, a+1-i))))
    return ans//(a+1)

def highwayConstruction(n, k):
    if n == 1:
        return 0
    return (sum(n-1, k)-1)%mod

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, k = input().strip().split(' ')
        n, k = [int(n), int(k)]
        result = highwayConstruction(n, k)
        print(result)
