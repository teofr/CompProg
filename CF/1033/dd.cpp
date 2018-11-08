#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cassert>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
#define dprint(v) cerr << #v"=" << v << endl //;)
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
typedef long long tint;
typedef long long ll;

ll gcd(ll a, ll b){return a?gcd(b %a, a):b;}

ll mulmod (ll a, ll b, ll c) { //returns (a*b)%c, and minimize overfloor
	ll x = 0, y = a%c;
	while (b > 0){
		if (b % 2 == 1) x = (x+y) % c;
		y = (y*2) % c;
		b /= 2;
	}
	return x % c;
}

ll expmod (ll b, ll e, ll m){//O(log b)
	if(!e) return 1;
	ll q= expmod(b,e/2,m); q=mulmod(q,q,m);
	return e%2? mulmod(b,q,m) : q;
}

bool es_primo_prob (ll n, int a)
{
	if (n == a) return true;
	ll s = 0,d = n-1;
	while (d % 2 == 0) s++,d/=2;
	
	ll x = expmod(a,d,n);
	if ((x == 1) || (x+1 == n)) return true;
	
	forn (i, s-1){
		x = mulmod(x, x, n);
		if (x == 1) return false;
		if (x+1 == n) return true;
	}
	return false;
}
		
bool rabin (ll n){ //devuelve true si n es primo
	if (n == 1)	return false;
	const int ar[] = {2,3,5,7,11,13,17,19,23};
	forn (j,9)
		if (!es_primo_prob(n,ar[j]))
			return false;
	return true;
}



ll mulmod2(ll a, ll b, ll c) {
  ll x = 0, y = a % c;
  while (b) {
    if (b & 1) x = (x + y) % c;
    y = (y << 1) % c;
    b >>= 1;
  }
  return x % c;
}
 
ll fastPow(ll x, ll n, ll MOD) {
  ll ret = 1;
  while (n) {
    if (n & 1) ret = mulmod2(ret, x, MOD);
    x = mulmod2(x, x, MOD);
    n >>= 1;
  }
  return ret;
}
 
bool isPrime(ll n) {
  ll d = n - 1;
  int s = 0;
  while (d % 2 == 0) {
    s++;
    d >>= 1;
  }
 
  // It's guranteed that these values will work for any number smaller than 3*10**18 (3 and 18 zeros)
  int a[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
  for(int i = 0; i < 9; i++) {
    bool comp = fastPow(a[i], d, n) != 1;
    if(comp) for(int j = 0; j < s; j++) {
      ll fp = fastPow(a[i], (1LL << (ll)j)*d, n);
      if (fp == n - 1) {
        comp = false;
        break;
      }
    }
    if(comp) return false;
  }
  return true;
}


ll rho(ll n){
    if( (n & 1) == 0 ) return 2;
    ll x = rand() % n + 1 , y = 2 , d = 1;
    ll c = rand() % n + 1;
    while( d == 1 ){
        x = (mulmod( x , x , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        y = (mulmod( y , y , n ) + c)%n;
        if( x - y >= 0 ) d = gcd( x - y , n );
        else d = gcd( y - x , n );
    }
    return d==n? rho(n):d;
}

map<ll,ll> prim; 
void factRho (ll n){ //O (lg n)^3. un solo numero
	if (n == 1) return;
	if (isPrime(n)){
		prim[n]++;
		return;
	}
	ll factor = rho(n);
	factRho(factor);
	factRho(n/factor);
}


int main(){
	int n;

	dprint(rabin(11));
	dprint(rabin(13));
	cin >> n;

	forn(i, n){
		tint a;
		cin >> a;
		factRho(a);
		dprint(rho(a));
		// dprint(a);
	}

	tint ans = 1;
	tint m = 998244353;
	dprint(prim.size());
	for (auto p : prim){
		dprint(p.first);
		dprint(p.second);
		ans = (ans*(p.second + 1)) % m;
	}

	cout << (ans % m) << endl;
	return 0;
}
// int main(){
// 	ll n;
// 	while(1){
// 		n=abs((ll)rand()*rand()*rand()%(ll(1e18))+50);
// 		dprint(n);
// 		if(!rabin(n)){
// 			//~ dprint(n);
// 			ll ans = rho (n);
// 			assert(!(n%ans) && ans>0);
// 		}
// 	}
// 	n = 2063512844981574047LL;
// 	while(cin >> n){
// 		dprint(n);
// 		if(rabin (n))
// 			cout << n << " es primo.\n";
// 		else{
// 			ll ans = rho (n);
// 			if (ans > n / ans) ans = n / ans;
// 			printf ("%lld = %lld * %lld\n", n, ans, n / ans);
// 		}
//     }
//     return 0;
// }
