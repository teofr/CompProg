//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

typedef  long long ll;

using namespace std;

int main() {
	int n, a, b,c;
	cin>>n>>a>>b>>c;

	vector<int> res(n+1,-1);
	res[0]=0;

	forsn(i,1,1+n){
		int cur=0;
		if(i>=a){
			if(res[i-a]>=0) cur=max(cur, res[i-a]+1);
		}
		if(i>=b){
			if(res[i-b]>=0) cur=max(cur, res[i-b]+1);
		}
		if(i>=c){
			if(res[i-c]>=0) cur=max(cur, res[i-c]+1);
		}
		if(cur!=0) res[i]=cur;
	}

	cout<<res[n]<<endl;

	return 0;
}
