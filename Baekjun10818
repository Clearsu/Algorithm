import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());
        int[] nums = new int[N];
        
        st = new StringTokenizer(br.readLine());
        
        for (int i=0;i<N;i++)
            nums[i] = Integer.parseInt(st.nextToken());
        
        int small = nums[0];
        int big = nums[0];
        
        for (int j=1;j<N;j++) {
            if (small > nums[j]) {
                small = nums[j];
            }
            if (big < nums[j]) {
                big = nums[j];
            }
        }
        System.out.println(small + " " + big);
        br.close();
    }
}
