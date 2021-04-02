import java.util.Scanner;
import java.util.Comparator;
import java.util.Arrays;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] arr = new String[n];
        
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            arr[i] = s;
        }
        
        Arrays.sort(arr, new Comparator<String>() {
            public int compare(String s1, String s2) {
                if(s1.length() > s2.length()) {
                    return 1;
                }
                
                else if(s1.length() == s2.length()) {
                    return s1.compareTo(s2);
                }
                
                else {
                    return -1;
                }
            }
        });
        
        for(int i = 0; i < n - 1; i++) {
            if(arr[i].equals(arr[i + 1])) {
                continue;
            }
            
            else {
                System.out.println(arr[i]);
            }
        }
        
        System.out.println(arr[n - 1]);
    }
}