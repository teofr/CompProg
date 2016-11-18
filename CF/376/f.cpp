//#include "../../stdc++.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
typedef long long ll;
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<ll> cnt(200010, 0);

	forn(i,n){
		int a;
		cin>>a;
		cnt[a]++;
	}

	forsn(i,1, cnt.size()){
		cnt[i]+=cnt[i-1];
	}

	ll res=0;

	forsn (v,1, cnt.size()){
		if(cnt[v]-cnt[v-1]!=0){
			ll curres=0;
			for (ll i=v; i<cnt.size(); i+=v){
				curres+=(ll)(cnt[min((ll)cnt.size()-1,i+v-1)]-cnt[i-1])*i;
			}
			res=max(res, curres);

		}
	}

	cout<<res<<endl;
	return 0;
}
