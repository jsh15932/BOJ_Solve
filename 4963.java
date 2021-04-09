import java.io.*;
import java.util.*;

public class Main {
    static int w, h;
    static int[][] arr;
    static int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    static int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        arr = new int[51][51];
        
        while(true) {
            h = sc.nextInt();
            w = sc.nextInt();
            
            if(w == 0 && h == 0) {
                break;
            }
            
            int cnt = 0;
            
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < h; j++) {
                    arr[i][j] = sc.nextInt();
                }
            }
            
            for(int i = 0; i < w; i++) {
                for(int j = 0; j < h; j++) {
                    if(arr[i][j] == 1) {
                        dfs(i, j);
                        cnt++;
                    }
                }
            }
            
            System.out.println(cnt);
        }
    }
    
    public static void dfs(int x, int y) {
        arr[x][y] = 0;
        
        for(int i = 0; i < 8; i++) {
            if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < w && y + dy[i] < h) {
                if(arr[x + dx[i]][y + dy[i]] == 1) {
                    dfs(x + dx[i], y + dy[i]);
                }
            }
        }
    }
}