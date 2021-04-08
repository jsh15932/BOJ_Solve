import java.io.*;
import java.util.*;

public class Main {
    public static int[][] map;
    public static int[][] chk;
    public static int n;
    public static int dx[] = {-1, 0, 1, 0};
    public static int dy[] = {0, -1, 0, 1};
    public static int size;
    
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        map = new int[n + 1][n + 1];
        chk = new int[n + 1][n + 1];
        ArrayList<Integer> arr = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            
            for(int j = 0; j < s.length(); j++) {
                map[i][j] = s.charAt(j) - 48;
            }
        }
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 1 && chk[i][j] == 0) {
                    cnt++;
                    size = 0;
                    dfs(i, j);
                    arr.add(size);
                }
            }
        }
        
        Collections.sort(arr);
        
        System.out.println(cnt);
        
        for(int i = 0; i < cnt; i++) {
            System.out.println(arr.get(i));
        }
    }
    
    public static void dfs(int x, int y) {
        chk[x][y] = 1;
        size++;
        
        for(int i = 0; i < 4; i++) {
            if(x + dx[i] >= 0 && y + dy[i] >= 0 && x + dx[i] < n && y + dy[i] < n) {
                if(map[x + dx[i]][y + dy[i]] == 1 && chk[x + dx[i]][y + dy[i]] == 0) {
                    dfs(x + dx[i], y + dy[i]);
                }
            }
        }
    }
}