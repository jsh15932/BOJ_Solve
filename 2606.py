n = int(input())
m = int(input())

arr = [[0] * (n + 1) for i in range(n + 1)]
chk = [False] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    arr[a][b] = arr[b][a] = 1
    
res = []

def dfs(start):
    chk[start] = True
    
    for i in range(1, n + 1):
        if arr[start][i] == 1 and chk[i] == False:
            res.append(i)
            dfs(i)
            
    return len(res)
    
print(dfs(1))