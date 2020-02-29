
import sys
sys.setrecursionlimit(20000)

dp = [-1]*1000009
MOD = 1000000000+7
def fun(x):
    if x<0 : return 0
    if x==0 : return 1

    ans = 0
    if dp[x] != -1 : 
        return dp[x]  
    for i in range(1,7):
        ans += (fun(x-i)%MOD)
    dp[x] = ans % MOD
    return dp[x]

n = int(input())
print(fun(n) % MOD)