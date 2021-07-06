import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int cnt = 1;
        
        if(s.isEmpty()) {
            System.out.println(0);
        }
        
        else {
            for(int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == ' ') {
                    cnt++;
                }
            }
            
            if(s.charAt(0) == ' ') {
                cnt--;
            }
            
            if(s.charAt(s.length() - 1) == ' ') {
                cnt--;
            }
            
            System.out.println(cnt);
        }
    }
}