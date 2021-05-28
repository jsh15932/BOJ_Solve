n = int(input())
arr = [int(input()) for _ in range(n)]
arr.sort()
cnt = 1

for i in range(n - 1):
    for j in range(i + 1, n):
        if arr[j] - arr[i] >= 5:
            break
        
        cnt = max(j - i + 1, cnt)
        
if cnt > 4:
    print(0)

else:
    print(5 - cnt)