s = input()
sz = len(s)
dp = [[0 for i in range(sz)] for i in range(sz)]
for i in range(sz):
    dp[i][i] = 1
for le in range(2, sz + 1):
    for l in range(0, sz):
        if l + le - 1 < sz:
            r = l + le - 1
            if (s[l] == s[r]):
                dp[l][r] = dp[l + 1][r] + dp[l][r - 1] + 1
            else:
                dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1];
print(dp[0][sz - 1])