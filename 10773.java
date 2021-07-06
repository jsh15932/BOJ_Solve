import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> s = new Stack<Integer>();
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            int num = sc.nextInt();
            
            if(num != 0) {
                s.push(num);
            }
            
            else {
                s.pop();
            }
        }
        
        while(!s.isEmpty()) {
            sum += s.peek();
            s.pop();
        }
        
        System.out.println(sum);
    }
}