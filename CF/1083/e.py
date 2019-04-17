n = int(input())

a = [(0, 0, 0)] * (n)

for i in range(n):
	x, y, c = map(int, list(input().split()))
	a[i] = (x, y, c)

a.sort()

dp = [(0, 0)] * (n+1)
ans = 0
best = 0
for x in range(n):
	area = a[x][0]*a[x][1] - a[x][2]
	while best < x and (area + dp[best][0] - dp[best][1]*a[x][1]) <= (area + dp[best+1][0] - dp[best+1][1]*a[x][1]):
		best += 1
	dp[x+1] = (area + dp[best][0] - dp[best][1]*a[x][1], a[x][0])
	ans = max(ans, dp[x+1][0])
# print(dp)
print(ans)