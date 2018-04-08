//#include "../../stdc++.h"
#include <bits/stdc++.h>

#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n-1; i>=s; i--)
#define dforn(i,n) dforsn(i,0,n)
#define pb push_back
#define snd second
#define fst first

using namespace std;

int main() {
	string s;
	cin>>s;
	
	bool ones=s[0]=='1';
	int res=0;
	
	
	forn(i, s.size()){
		if (ones &&s[i]=='1'){
		}else if (ones && s[i]=='0'){
			ones=false;
			res++;
		}else if (s[i]=='1'){
			ones=true;
			res++;
		}else{
		}
	}
	
	if (s[s.size()-1]=='1') res++;
	
	cout<<res<<endl;

	return 0;
}
