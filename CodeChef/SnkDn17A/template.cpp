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


vector<int> up[2];

pair<int,int> walker(int a, int b,  int c){
	up[a][b]=c;
	cerr<<"CAMINO EN "<<a<<' '<<b<<endl;
	if (up[a^1][b]!=c && up[a^1][b]!=0){
		return walker(a^1, b, c);
	}else if (0<b && up[a][b-1]!=c && up[a][b-1]!=0){
		return walker(a, b-1, c);
	}else if (b+1<up[0].size() && up[a][b+1]!=c && up[a][b+1]!=0){
		return walker(a, b+1,  c);
	}
	return make_pair(a,b) ;
}

int main() {
	int t;
	cin>> t;
	
	forn(i,t){
		int n;
		cin>>n;
		
		up[0].clear(); up[1].clear();
		up[0]=up[1]=vector<int> (n, 0);
		
		pair<int,int> start{-1,-1};
		
		forn(i,n){
			char c;
			cin>>c;
			up[0][i]=(c=='.'?0:1);
			//if (up[0][i]) start=i;
		}
		forn(i,n){
			char c;
			cin>>c;
			up[1][i]=(c=='.'?0:1);
			//if (up[1][i]) start=i+n;
		}
		
		forn(i,n){
			bool a=up[1][i], b=up[0][i];
			if ((a && !b)){
				start.fst=1; start.snd=i;
				i=n;
			}else if (!a && b){
				start.fst=0; start.snd=i;
				i=n;
			}
		}
		
		if (start.fst==-1){
			forn(i,n){
				bool a=up[1][i], b=up[0][i];
				if (a||b){
					start.fst=0; start.snd=i;
					i=n;
				}
				
			}
		}
		
		
		
		bool res=true;
		
		
		
		auto p=walker(start.fst, start.snd, 2);
		forn(i,2){
			forn(j,n){
				cerr<<up[i][j];
			}
			cerr<<endl;
		}
		p=walker(p.fst, p.snd, 3);
		walker(p.fst, p.snd,  0);
		forn(i,2){
			forn(j,n){
				cerr<<up[i][j];
			}
			cerr<<endl;
		}
		forn(i,2){
			forn(j,n){
				res&=up[i][j]==0;
			}
		}
		
				
		cout<<(res?"yes":"no")<<endl;
		
		
		
	}
	
		
		
	return 0;
}
