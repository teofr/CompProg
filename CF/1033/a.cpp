#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define ii pair<tint,tint>
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define mp make_pair
#define fst first
#define snd second
#define pb push_back

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif


int main() {
	tint n, ax, ay, bx, by, cx, cy;
	cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

	bx -= ax;
	by -= ay;
	cx -= ax;
	bool perdi = false;
	cy -= ay;

	if (bx > 0 and cx < 0){
		perdi = true;
	} else if (bx < 0 and cx > 0){
		perdi = true;
	} else if (by > 0 and cy < 0){
		perdi = true;
	} else if (by < 0 and cy > 0){
		perdi = true;
	}
	// }else if (bx > by and cy > cx){
	// 	perdi = true;
	// }else if (bx < by and cy < cx){
	// 	perdi = true;
	// }


	if (perdi){
		cout << "NO" << endl;
	}else {
		cout << "YES" << endl;
	}

	return 0;



	return 0;
}
