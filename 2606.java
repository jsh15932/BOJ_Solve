import java.io.*;
import java.util.*;

public class Main {
    public static int n, v;
    public static int arr[][];
    public static int chk[];
    
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        v = sc.nextInt();
        arr = new int[n + 1][n + 1];
        chk = new int[n + 1];
        
        for(int i = 0; i < v; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            arr[a][b] = 1;
            arr[b][a] = 1;
        }
        
        bfs(1);
    }
    
    public static void bfs(int start) {
        Queue<Integer> que = new LinkedList<>();
        int cnt = 0;
        chk[start] = 1;
        que.add(start);
        
        while(!que.isEmpty()) {
            int x = que.poll();
            
            for(int i = 1; i < arr.length; i++) {
                if(arr[x][i] == 1 && chk[i] != 1) {
                    que.add(i);
                    chk[i] = 1;
                    cnt++;
                }
            }
        }
        
        System.out.println(cnt);
    }
}