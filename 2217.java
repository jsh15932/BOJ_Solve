import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        
        Arrays.sort(arr);
        
        int idx = n;
        int ans = arr[0] * idx;
        
        for(int i = 1; i < n; i++) {
            idx--;
            
            if(arr[i] * idx > ans) {
                ans = arr[i] * idx;
            }
        }
        
        System.out.println(ans);
    }
}