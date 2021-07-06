import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        String c[] = new String[n];
        boolean chk[] = new boolean[26];
        
        for(int i = 0; i < n; i++) {
            c[i] = sc.next();
        }
        
        for(int i = 0; i < c.length; i++) {
            cnt++;
            Arrays.fill(chk, false);
            
            for(int j = 0; j < c[i].length(); j++) {
                if(j != c[i].length() - 1 && chk[c[i].charAt(j) - 97] == false && c[i].charAt(j) != c[i].charAt(j + 1)) {
                    chk[c[i].charAt(j) - 97] = true;
                }
                
                else if(chk[c[i].charAt(j) - 97] == true) {
                    cnt -= 1;
                    
                    break;
                }
            }
        }
        
        System.out.println(cnt);
    }
}