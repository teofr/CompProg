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
	int n;
	cin>>n;
	vector<int> seq (n);
	map<int, int> idx;

	forn(i,n){
		cin>>seq[i];
		idx[seq[i]] = i;
	}

	int count = 0;
	for(auto x:idx){
		seq[x.snd] = count;
		count++;
	}

	//idx.clear()

	vector<int> checked (n, 0);

	int actual = 0;

	set<set<int> > result;

	while (actual<n){
		while (actual<n &&  checked[actual]){
			actual++;
		}

		if (actual<n){
			set<int> pos;

			int walker = actual;

			while (pos.find(walker) == pos.end()){
				pos.insert(walker);
				checked[walker] = 1;
				walker = seq[walker];
			}

			result.insert(pos);
			//cout<<pos.size()<<" ";

			//for(auto p:pos){
			//	cout<<p+1<<" ";
			//}
			//cout<<endl;



		}

	}

	cout<<result.size()<<endl;

	for(auto pos:result){
		cout<<pos.size()<<" ";

		for(auto p:pos){
			cout<<p+1<<" ";
		}
		cout<<endl;
	}


	return 0;
}
