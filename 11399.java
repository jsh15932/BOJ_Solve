import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        
        for(int i = 1; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }
        
        Arrays.sort(arr);
        
        int sum = 0;
        
        for(int i = 1; i < arr.length; i++) {
            for(int j = 1; j <= i ; j++) {
                sum += arr[j];
            }
        }
        
        System.out.println(sum);
    }
}