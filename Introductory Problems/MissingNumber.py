n = int(input())
s = 0
ar = list(map(int,input().split()))
print(n*(n+1)//2 - sum(ar))