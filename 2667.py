n = int(input())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
arr = []
chk = [[False] * n for _ in range(n)]

for _ in range(n):
    arr.append(list(map(int, input())))
    
def dfs(x, y):
    chk[x][y] = True
    global cnt
    
    for i in range(4):
        if 0 <= x + dx[i] < n and 0 <= y + dy[i] < n:
            if arr[x + dx[i]][y + dy[i]] == 1 and chk[x + dx[i]][y + dy[i]] == False:
                chk[x + dx[i]][y + dy[i]] = True
                dfs(x + dx[i], y + dy[i])
                cnt += 1

cnt = 0
res = 0
dp = []
                
for i in range(n):
    for j in range(n):
        if arr[i][j] == 1 and chk[i][j] == False:
            res += 1
            cnt = 1
            dfs(i, j)
            dp.append(cnt)
            
dp.sort()
print(res)

for i in dp:
    print(i)