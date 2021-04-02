import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt[] = new int[10001];
        
        for(int i = 0; i < n; i++) {
            int num = Integer.parseInt(br.readLine());
            cnt[num]++;
        }
        
        br.close();
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < 10001; i++) {
            for(int j = 0; j < cnt[i]; j++) {
                sb.append(i).append('\n');
            }
        }
        
        System.out.println(sb);
    }
}