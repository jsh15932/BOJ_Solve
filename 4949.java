import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        while(true) {
            String s = br.readLine();
            
            if(s.equals(".")) {
                return;
            }
            
            Stack<Character> stack = new Stack<>();
            
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '(') {
                    stack.push(')');
                }
                
                else if(s.charAt(i) == '[') {
                    stack.push(']');
                }
                
                else if(s.charAt(i) == ')' || s.charAt(i) == ']') {
                    if(!stack.isEmpty() && stack.peek() == s.charAt(i)) {
                        stack.pop();
                    }
                    
                    else {
                        stack.push('x');
                    }
                }
            }
            
            System.out.println(stack.isEmpty() ? "yes" : "no");
        }
    }
}