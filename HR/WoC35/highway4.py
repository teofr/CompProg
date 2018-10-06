#!/bin/python3

import sys

from fractions import Fraction
#from scipy.special import binom as binomial

mod = 1000000009


combo = {}
def comb(p):
    n, k = p
    if k == n or k == 0:
        return 1
    if not p in combo:
        combo[p] = (comb((n-1, k-1)) + comb((n-1, k)))
    return combo[p]


bern = [Fraction(1, 1), -Fraction((comb((1, 0))), (2))]

for n in range(2, 1001, 2):
    res = Fraction(0, 1)
    for k in range(n):
        res += Fraction((comb((n, k))), (n-k+1))*bern[k]
    bern.append(-res)
    bern.append(Fraction(0, 1))



def exp(b, e):
    if e <= 2:
        return b**e
    return exp(b, e//2)**2 * (b if e%2==1 else 1)

def sum(n, a):
    ans = Fraction(-comb((a+1, 1))*exp(n, a),1)*bern[1]
    for i in range(0, a+1, 2):
        #if i==1 or i%2==0:
            #sgn = 1 if i!=1 else -1
        tmp = Fraction(comb((a+1, i))*exp(n, a+1-i),1)*bern[i]
       
        ans = (ans+tmp)#%mod
    return ans//(a+1)

def highwayConstruction(n, k):
    if n == 1:
        return 0
    return (sum(n-1, k)-1)%mod
    # Complete this function

if __name__ == "__main__":
    q = int(input().strip())
    for a0 in range(q):
        n, k = input().strip().split(' ')
        n, k = [int(n), int(k)]
        result = highwayConstruction(n, k)
        print(result)
