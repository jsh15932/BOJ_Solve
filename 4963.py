import sys
sys.setrecursionlimit(100000)
input = sys.stdin.readline

dx = [-1, -1, -1, 1, 1, 1, 0, 0]
dy = [-1, 0, 1, -1, 0, 1, -1, 1]

def dfs(x, y):
    arr[x][y] = 0
    
    for i in range(8):
        if 0 <= x + dx[i] < w and 0 <= y + dy[i] < h:
            if arr[x + dx[i]][y + dy[i]] == 1:
                dfs(x + dx[i], y + dy[i])

while(True):
    h, w = map(int, input().split())
    
    if w == 0 and h == 0:
        break

    arr = [list(map(int, input().split())) for _ in range(w)]
    cnt = 0
    
    for i in range(w):
        for j in range(h):
            if arr[i][j] == 1:
                dfs(i, j)
                cnt += 1
                
    print(cnt)