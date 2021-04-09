import java.io.*;
import java.util.*;

public class Main {
    static int n, h;
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, -1, 0, 1};
    static int[][] arr;
    static boolean[][] chk;
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[101][101];
        chk = new boolean[101][101];
        int res = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
                
                if(arr[i][j] > res) {
                    res = arr[i][j];
                }
            }
        }
        
        for(int i = 0; i <= res; i++) {
            int cnt = 0;
            
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    chk[j][k] = false;
                }
            }
            
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(arr[j][k] > i && !chk[j][k]) {
                        chk[j][k] = true;
                        dfs(j, k, i);
                        cnt++;
                    }
                }
            }
            
            if(cnt > ans) {
                ans = cnt;
            }
        }
        
        System.out.println(ans);
    }
    
    public static void dfs(int x, int y, int h) {
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
                if(arr[x + dx[i]][y + dy[i]] > h && !chk[x + dx[i]][y + dy[i]]) {
                    chk[x + dx[i]][y + dy[i]] = true;
                    dfs(x + dx[i], y + dy[i], h);
                }
            }
        }
    }
}