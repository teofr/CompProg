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

using namespace std;

int main() {
	char a;
	vector<char> s;
	int up, low;
	up=low=0;
	while(cin>>a){
		if(a==tolower(a)){
			low++;
		}else{
			up++;
		}
		s.push_back(a);
	}


	if(low>=up){
		for (char c: s) cout<<(char)tolower(c);
	}else{
		for (char c: s) cout<<(char)toupper(c);
	}
	cout<<endl;

	return 0;
}
