dp = [-1]*33
dp[0] = 1
# dp[1] = 32
dp[1] = 1
# dp[2] = 31 * dp[1]
dp[2] = dp[1]
# dp[3] = 30 * dp[2] + 32*31*30

for x in range(3, 33):
	dp[x] = dp[x-1] + dp[x-3]
	# dp[x] = (33-x)*dp[x-1] + (33-x)*(33-x+1)*(33-x+2)*dp[x-3]
	print (dp[x])


