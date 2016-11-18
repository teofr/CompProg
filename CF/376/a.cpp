//#include "../../stdc++.h"
//#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

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
	int res=0;
	//Falta de a a primero
	int resder=(-(s[0]-'a')+26)%26;
	int resizq=((s[0]-'a')+26)%26;
	res=min(resder,resizq);
	forn(i,s.size()-1){
		int curder=((s[i]-'a')-(s[i+1]-'a')+26)%26;
		int curizq=(-(s[i]-'a')+(s[i+1]-'a')+26)%26;
		res+=min(curizq, curder);

	}

	cout<<res<<endl;


	return 0;
}
