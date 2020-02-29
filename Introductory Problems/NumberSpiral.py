tc = int(input())
while tc!=0:
    tc-=1
    x,y = map(int,input().split())
    tx,ty = 0,0
    if x%2 == 0:
        tx = x**2 
    else:
        tx = (x-1)**2 + 1
    
    if y%2 == 1:
        ty = y**2 
    else:
        ty = (y-1)**2 + 1


    if ty>tx:
        if y%2==0:
            print(ty+x-1)
        else :
            print(ty-x+1)
    elif ty<tx:
        if x%2==0:
            print(tx-y+1)
        else:
            print(tx+y-1)
    else:
        print(1)