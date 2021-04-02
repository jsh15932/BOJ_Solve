import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][2];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        
        Arrays.sort(arr, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[1] == b[1]) {
                    return a[0] - b[0];
                }
                
                return a[1] - b[1];
            }
        });
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                System.out.print(arr[i][j] + " ");
            }
            
            System.out.println();
        }
    }
}