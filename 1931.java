import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][2];
        
        for(int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }
        
        Arrays.sort(arr, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[1] == b[1]) {
                    return a[0] - b[0];
                }
                
                return a[1] - b[1];
            }
        });
        
        int cnt = 0;
        int k = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i][0] >= k) {
                k = arr[i][1];
                cnt++;
            }
        }
        
        System.out.println(cnt);
    }
}