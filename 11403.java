import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] arr;

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        arr = new int[101][101];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        
        floyd();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                System.out.print(arr[i][j] + " ");
            }
            
            System.out.println();
        }
    }
    
    public static void floyd() {
        for(int via = 0; via < n; via++) {
            for(int from = 0; from < n; from++) {
                for(int to = 0; to < n; to++) {
                    if(arr[from][via] == 1 && arr[via][to] == 1) {
                        arr[from][to] = 1;
                    }
                }
            }
        }
    }
}