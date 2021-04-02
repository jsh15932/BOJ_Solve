import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String[] arr = new String[s.length()];
        
        for(int i = 0; i < s.length(); i++) {
            arr[i] = s.substring(i, i + 1);
        }
        
        Arrays.sort(arr);
        
        for(int i = s.length() - 1; i >= 0; i--) {
            System.out.print(arr[i]);
        }
    }
}