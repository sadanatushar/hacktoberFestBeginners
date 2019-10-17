t=int(input())
while t>0:
    n=int(input())
    arr=list(map(int,input().split()))
    ans=min(arr)
    print(ans)
    t-=1