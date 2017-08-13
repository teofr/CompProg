//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first
#define debug(a) //cerr<< #a <<": "<<a<<endl

typedef long long tint;

using namespace std;

const tint MOD = 1000000007;

// Function to return gcd of a and b
int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main() {
	int n;
	cin>>n;
	vector<int> army (n);
	forn (i, n){
		cin>>army[i];
	}

	map<int, pair<tint, tint> > gcds;
	//fst es #clanes, snd es suma de los clanes

	forn (i,n){
		//para los primeros i army
		map<int, pair<tint, tint> > next;


		for (auto x : gcds){
			int currgcd = gcd(army[i], x.fst);
      if (currgcd > 1){
        auto & ref = next[currgcd];
				ref.fst += x.snd.fst;
        ref.fst %= MOD;
				ref.snd += x.snd.snd + x.snd.fst;
        ref.snd %= MOD;
			}
		}

    if (army[i] > 1){
      auto & ref = gcds[army[i]];
		    ref.fst++;
		    ref.snd++;
    }

    for (auto x : next){
      auto& ref = gcds[x.fst];
      ref.fst += x.snd.fst;
      ref.snd += x.snd.snd;
    }
  }

	int ans = 0;

	for(auto x : gcds){
		ans = (ans + ((x.fst*x.snd.snd) % MOD)) % MOD;
	}

	cout<<ans<<endl;

	return 0;
}
