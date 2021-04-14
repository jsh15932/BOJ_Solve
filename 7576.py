from collections import deque
import sys
input = sys.stdin.readline

m, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
q = deque()
ans = 0

for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            q.append([i, j])

while q:
    que = q.popleft()
    
    if arr[que[0]][que[1]] > ans:
        ans = arr[que[0]][que[1]]
    
    for i in range(4):
        que_x = que[0] + dx[i]
        que_y = que[1] + dy[i]
        
        if 0 <= que_x < n and 0 <= que_y < m:
            if arr[que[0] + dx[i]][que[1] + dy[i]] == 0:
                q.append([que[0] + dx[i], que[1] + dy[i]])
                arr[que[0] + dx[i]][que[1] + dy[i]] = arr[que[0]][que[1]] + 1
                
for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            ans = 0

print(ans - 1)