n = int(input())
data = list(map(int, input().split()))
data.sort()
ans = 1

for i in data:
    if ans < i:
        break
    
    ans += i
    
print(ans)