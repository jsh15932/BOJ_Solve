import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        Set<String> arr1 = new HashSet<>();
        List<String> arr2 = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            arr1.add(s);
        }
        
        for(int i = 0; i < m; i++) {
            String s = sc.next();
            
            if(arr1.contains(s)) {
                arr2.add(s);
            }
        }
        
        Collections.sort(arr2);
        
        System.out.println(arr2.size());
        
        for(String s:arr2) {
            System.out.println(s);
        }
    }
}