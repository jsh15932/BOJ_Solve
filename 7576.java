import java.io.*;
import java.util.*;

public class Main {
    public static int n, m;
    public static int[][] map;
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        m = sc.nextInt();
        n = sc.nextInt();
        map = new int[n + 1][m + 1];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                map[i][j] = sc.nextInt();
            }
        }
        
        bfs();
        
        int res = 0;
        boolean chk = true;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 0) {
                    chk = false;
                }
                
                res = Math.max(res, map[i][j]);
            }
        }
        
        if(chk) {
            System.out.println(res - 1);
        }
        
        else {
            System.out.println("-1");
        }
        
    }
    
    public static void bfs() {
        Queue<Integer> qx = new LinkedList<>();
        Queue<Integer> qy = new LinkedList<>();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 1) {
                    qx.add(i);
                    qy.add(j);
                }
            }
        }
        
        while(!qx.isEmpty() && !qy.isEmpty()) {
            int x = qx.poll();
            int y = qy.poll();
            
            for(int i = 0; i < 4; i++) {
                if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < m) {
                    if(map[x + dx[i]][y + dy[i]] == 0) {
                        map[x + dx[i]][y + dy[i]] = map[x][y] + 1;
                        qx.add(x + dx[i]);
                        qy.add(y + dy[i]);
                    }
                }
            }
        }
    }
}