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

auto rey;
auto torre;
bool loAtacan(int x, int y){
	
}

int main() {
	vector<pair<int,int>> val(3);

	forn(i,3){
		char a; cin>>a; char b; cin>>b;
		val[i].fst=(int)(a-'a');
		val[i].snd=(int)(b-'1');
	}

	rey=val[0]; torre=val[1];

/*
	bool atacarey=false, atacatorre=false, mueve=true;

	vector<vector<int > > mat (8, vector<int>(8,0));
	vector<int> dir={1,0,-1};


	forn(i,3){
		forn(j,3){
			int a=val[2].fst+dir[i];
			int b=val[2].snd+dir[i];
			int rey=val[0];
			int torre=val[1];

			if(a>=0 && b>=0 && a<8 && b<8){
				if (dir[i]==0 && dir[i]==0){
					if(max(abs(a-val[0].fst), abs(b-val[0.fst]))==1   ){
						atacarey=true;
					}
					if(a==val[1].fst && !(a==val[0].fst && ((rey.snd>b &&))))
				}
			}

			if ((a!=0 || b!=0) && (a!=val[1].fst || b!=val[1].snd)&& (a>=0 && b>=0 && a<8 && b<8)){
				mat[a][b]=1;
			}
		}
	}
*/
/*
	forn(i,3){
		forn(j,3){
			int a=val[0].fst+dir[i];
			int b=val[0].snd+dir[i];

			if ((dir[i]!=0 || dir[i]!=0) && (a!=val[1].fst || b!=val[1].snd)&& (a>=0 && b>=0 && a<8 && b<8)){
				mat[a][b]=1;
			}
		}
	}

	if (mat[val[2].fst][val[2].snd]==1){
		cout<<"Strange"<<endl;
		return 0;
	}

	int h=1;
	while(val[1].fst+h<8){
		if (val[1].snd==val[0].snd && val[1].fst+h==val[0].fst) break;

		mat[val[1].fst+h][val[1].snd]=1;
		h++;
	}

	h=-1;
	while(val[1].fst+h>=0){
		if (val[1].snd==val[0].snd && val[1].fst+h==val[0].fst) break;

		mat[val[1].fst+h][val[1].snd]=1;
		h--;
	}

	h=1;
	while(val[1].snd+h<8){
		if (val[1].snd+h==val[0].snd && val[1].fst==val[0].fst) break;

		mat[val[1].fst][val[1].snd+h]=1;
		h++;
	}

	h=-1;
	while(val[1].snd+h>=0){
		if (val[1].snd+h==val[0].snd && val[1].fst==val[0].fst) break;

		mat[val[1].fst][val[1].snd+h]=1;
		h--;
	}

	bool mov=true;

	forn(i,3){
		forn(j,3){
			int a=val[2].fst+dir[i];
			int b=val[2].snd+dir[i];

			if ((dir[i]!=0 || dir[i]!=0) && (a>=0 && b>=0 && a<8 && b<8)){
				mov=mov || mat[a][b]!=1;
			}
		}
	}

	if (mat[val[2].fst][val[2].snd]==1){
		if(mov){
			cout<<"Check"<<endl;
		}else{
			cout<<"Checkmate"<<endl;

		}
	}else{
		if(mov){
			cout<<"Normal"<<endl;
		}else{
			cout<<"Stalemate"<<endl;

		}

	}
*/

	return 0;
}
