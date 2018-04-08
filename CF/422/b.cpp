//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first
#define debug(a) cerr<< #a <<': '<<a<<endl

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	string s,t;
	cin>>s>>t;

	int res=n + m + 1;
	vector<int> resV;
	for (int i=0; i<m - n + 1; i++){
		int cnt=0;
		vector<int> cntV;
		for (int j=0; j < n; j++){
			if (s[j] != t[j + i]){
				cnt++;
				cntV.pb(j + 1);
			}
		}
		if (res > cnt){
			res = cnt;
			resV = cntV;
		}
	}

	cout<<res<<endl;

	for (auto x : resV){
		cout<<x<<' ';
	}
	cout<<endl;


	return 0;
}
