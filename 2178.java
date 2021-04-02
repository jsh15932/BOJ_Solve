import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();
        int map[][] = new int[n + 1][m + 1];
        int arr[][] = new int[n + 1][m + 1];
        
        for(int i = 1; i <= n; i++) {
            String s = sc.nextLine();
            
            for(int j = 1; j <= m; j++) {
                map[i][j] = s.charAt(j - 1) - 48;
            }
        }
        
        Queue<Integer> que = new LinkedList<>();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        int ans = 0;
        
        for(int i = 0; i < 3; i++) {
            que.add(1);
        }
        
        arr[1][1] = 1;
        
        while(true) {
            if(que.size() == 0) {
                break;
            }
            
            int x = que.poll();
            int y = que.poll();
            int cnt = que.poll();
            
            if(x == n && y == m) {
                ans = cnt;
                
                break;
            }
            
            for(int i = 0; i < 4; i++) {
                if(x + dx[i] > 0 && y + dy[i] > 0 && x + dx[i] <= n && y + dy[i] <= m) {
                    if(map[x + dx[i]][y + dy[i]] == 1 && arr[x + dx[i]][y + dy[i]] == 0) {
                        que.add(x + dx[i]);
                        que.add(y + dy[i]);
                        que.add(cnt + 1);
                        arr[x + dx[i]][y + dy[i]] = 1;
                    }
                }
            }
        }
        
        System.out.println(ans);
    }
}