import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st1 = new StringTokenizer(br.readLine());
        
        //첫째 줄(조건)
        int N = Integer.parseInt(st1.nextToken());
        int x = Integer.parseInt(st1.nextToken());
        
        //둘째 줄 읽어서 출력
        StringTokenizer st2 = new StringTokenizer(br.readLine());
        for (int i=0;i<N;i++) {
            int n = Integer.parseInt(st2.nextToken());
            if (n<x)
                bw.write(n + " ");
        }
        bw.close();
    }
}
