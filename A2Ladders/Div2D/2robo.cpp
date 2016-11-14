// Este problema del ojete no me entraba en tiempo por boludeces


#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int a[1000][1000];
int w, h;

int fastMax(int x, int y) { return max(x,y);}//(((y-x)>>(32-1))&(x^y))^y; }
int fastMin(int x, int y) { return min(x,y);}//(((y-x)>>(32-1))&(x^y))^x; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>h>>w;
  //scanf("%d%d", &h, &w);
  for(int y = 0; y < h; y++)
    for(int x = 0; x < w; x++)
			cin>>a[y][x];
			//scanf("%d", &a[y][x]);
  int ans = -1;
  for(int y1 = 0; y1 < h; y1++)
    for(int y2 = y1 + 1; y2 < h; y2++) {
      int m1 = -1, m2 = -1;
      for(int x = 0; x < w; x++) {
        const int v = fastMin(a[y1][x], a[y2][x]);
        if ((m1 < v)) { m2 = m1; m1 = v; }
        else if((m2 < v)) { m2 = v; }
      }
      ans = fastMax(ans, m2);
    }
  printf("%d\n", ans);
  return 0;
}
