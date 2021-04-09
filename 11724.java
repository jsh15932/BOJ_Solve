import java.io.*;
import java.util.*;

public class Main {
    static int n, m, cnt;
    static int[][] arr;
    static boolean[] chk;
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[1001][1001];
        chk = new boolean[1001];
        
        for(int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        
        cnt = 0;
        
        for(int i = 1; i <= n; i++) {
            if(!chk[i]) {
                dfs(i);
                cnt++;
            }
        }
        
        System.out.println(cnt);
    }
    
    public static void dfs(int start) {
        chk[start] = true;
        
        for(int i = 1; i <= n; i++) {
            if(arr[start][i] == 1 && !chk[i]) {
                dfs(i);
            }
        }
    }
}