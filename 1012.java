import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int m;
    static int[][] arr;
    static int dx[] = {-1, 0, 1, 0};
    static int dy[] = {0, -1, 0, 1};
    static int[][] chk;
        
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        for(int idx = 0; idx < t; idx++) {
            m = sc.nextInt();
            n = sc.nextInt();
            int num = sc.nextInt();
            arr = new int[51][51];
            chk = new int[51][51];
            int cnt = 0;
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    arr[i][j] = 0;
                    chk[i][j] = 0;
                }
            }
            
            for(int i = 0; i < num; i++) {
                int a = sc.nextInt();
                int b = sc.nextInt();
                arr[b][a] = 1;
            }
            
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(arr[i][j] == 1 && chk[i][j] == 0) {
                        chk[i][j] = 1;
                        dfs(i, j);
                        cnt++;
                    }
                }
            }
            
            System.out.println(cnt);
        }
    }
    
    public static void dfs(int a, int b) {
        for(int i = 0; i < 4; i++) {
            if(a + dx[i] >= 0 && b + dy[i] >= 0 && a + dx[i] < n && b + dy[i] < m) {
                if(arr[a + dx[i]][b + dy[i]] == 1 && chk[a + dx[i]][b + dy[i]] == 0) {
                    chk[a + dx[i]][b + dy[i]] = 1;
                    dfs(a + dx[i], b + dy[i]);
                }
            }
        }
    }
}