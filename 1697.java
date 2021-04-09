import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int max_n = 100001;
        boolean[] chk = new boolean[max_n];
        int[] arr = new int[max_n];
        
        Queue<Integer> que = new LinkedList<>();
        que.add(n);
        chk[n] = true;
        
        while(!que.isEmpty()) {
            int x = que.poll();
            chk[x] = true;
            
            if(x >= 1 && !chk[x - 1]) {
                chk[x - 1] = true;
                arr[x - 1] = arr[x] + 1;
                que.add(x - 1);
            }
            
            if(x < max_n - 1 && !chk[x + 1]) {
                chk[x + 1] = true;
                arr[x + 1] = arr[x] + 1;
                que.add(x + 1);
            }
            
            if(x * 2 < max_n && !chk[x * 2]) {
                chk[x * 2] = true;
                arr[x * 2] = arr[x] + 1;
                que.add(x * 2);
            }
        }
        
        System.out.println(arr[k]);
    }
}