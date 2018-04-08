//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

typedef long long int tint;

using namespace std;


int main() {
	int t;
	cin>> t;
	
	forn(i,t){
		int n;
		cin>>n;
		
		vector<int> v(n);
		forn(i,n){
			cin>>v[i];
		}
		tint res=0;
		
		forn(i,n){
			int mini=v[i];
			if (i>0){
				mini=min(mini, v[i-1]+1);
			}
			if (i+1<n){
				mini=min(mini, v[i+1]+1);
			}
			res+=v[i]-mini;
			v[i]=mini;
		}
		forn(i,n){
			cerr<<v[i]<<' ';
		}
		cerr<<endl;
		
		
	}
	
		
		
	return 0;
}
