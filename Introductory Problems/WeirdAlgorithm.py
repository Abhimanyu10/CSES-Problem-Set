n = int(input())
ans = []
while n!=1:
    ans.append(str(n))
    if n%2==1:
        n = n*3+1
    else:
        n = n//2
ans.append("1")
print(' '.join(ans))
