#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef int tint;
#define INF 1e9+7
#define forsn(i, s, n) for(int i = s; i < (n); i++)
#define forn(i, n) forsn(i, 0, n)

#define debug(v) //cerr << #v << ": " << v << endl;

vector<vector<tint>> dp, mat, der, izq;
int n, m;

void DPandC(int i, int jleft, int jright, int kleft, int kright){
    int jmid = (jleft + jright)/2;
    dp[i][jmid] = -INF;
    int bestk = -1;
    for (int k = kleft; k < kright; k++){
        if (k < jmid){
            int t = dp[i-1][k] + mat[i][jmid] - mat[i][k+1] + izq[i][k] + der[i][jmid];
            if (t > dp[i][jmid]){
                dp[i][jmid] = t;
                bestk = k;
            }
        }else if (jmid < k){
            int t = dp[i-1][k] + mat[i][k] - mat[i][jmid+1] + der[i][k] + izq[i][jmid];
            if (t > dp[i][jmid]){
                dp[i][jmid] = t;
                bestk = k;
            }
        }else{
            //son iguales
            int t = dp[i-1][k] + der[i][k] + izq[i][k] - (mat[i][k+1] - mat[i][k]);
            if (t > dp[i][jmid]){
                dp[i][jmid] = t;
                bestk = k;
            }
        }
    }
    debug(i);
    debug(jmid);
    debug(bestk);
    debug(dp[i][jmid]);

    if (jleft < jmid){
        DPandC(i, jleft, jmid, kleft, bestk+1);
    }
    if (jmid + 1 < jright){
        DPandC(i, jmid + 1, jright, bestk, kright);
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    mat = vector<vector<tint>> (n, vector<tint> (m+1, 0)); // la pos x, y esta en mat[x][y+1] - mat[x][y]
    dp  = vector<vector<tint>> (n, vector<tint> (m, 0));
    der = vector<vector<tint>> (n, vector<tint> (m+1, 0));
    izq = vector<vector<tint>> (n, vector<tint> (m+1, 0));
    
    tint suma = 0;
    for(int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            //cin >> mat[i][j];
            int t;
            cin >> t;
            //scanf ("%d", &t);
            suma += (tint)t;
            //cerr << t << endl;
            mat[i][j] = (tint)t;
            
            mat[i][j] += mat[i][j-1];
            
        }
        //char a;
        //scanf("%c", &a);
        //cerr << "a: " << a << endl;
    }

    cerr << "suma: " << suma << endl;

    forn(i, n){
        izq[i][0] = mat[i][1] - mat[i][0];
        forsn(j, 1, m){
            izq[i][j] = mat[i][j+1] - mat[i][j] + max(0, izq[i][j-1]);
        }
        der[i][m-1] = mat[i][m] - mat[i][m-1];
        for(int j = m-2; j >= 0; j--){
            der[i][j] = mat[i][j+1] - mat[i][j] + max(0, der[i][j+1]);
        }
    }

    //Completar para i=0
    forn(j, m){
        dp[0][j] = der[0][j] + izq[0][j] - (mat[0][j+1] - mat[0][j]);
        debug(j);
        debug(dp[0][j]);
    }

    //llamar a DPandC para cada i in [1, n)
    forsn(i, 1, n){
        DPandC(i, 0, m, 0, m);
    }

    tint res = -INF;
    forn(j, m){
        if (res < dp[n-1][j]){
            res = dp[n-1][j];
        }
    }
    cout << res << endl;
    
    return 0;
}
