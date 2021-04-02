import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        
        int n = sc.nextInt();
        ArrayList<Integer> input = new ArrayList<>();
        
        for(int i = 0; i < n; i++) {
            input.add(sc.nextInt());
        }
        
        Collections.sort(input);
        
        for(int i:input) {
            sb.append(i).append("\n");
        }
        
        System.out.println(sb);
    }
}