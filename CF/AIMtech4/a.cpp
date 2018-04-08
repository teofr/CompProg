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
	string s;
	cin>>s;

	set<char> pres;

	int k;
	cin>>k;

	if (k>s.size()){
		cout<<"impossible"<<endl;
		return 0;
	}

	forn(i, s.size()){
		pres.insert(s[i]);
	}

	int res = max(0,  k -  (int) pres.size());
	cout<<res<<endl;


	return 0;
}
