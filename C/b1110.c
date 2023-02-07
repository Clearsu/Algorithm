import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int copy = N;
        int count = 0;
        
        
        while (true) {
            N = (((N%10)*10) + (((N/10) + (N%10))%10));
            count++;
            
            if (N == copy) {
                break;
            }
        }
        System.out.println(count);
    }
}
