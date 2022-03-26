import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int a = Integer.parseInt(br.readLine());
        int b = Integer.parseInt(br.readLine());
        int c = Integer.parseInt(br.readLine());
        int num = a * b * c;
        
        int[] arr = new int[10];
        
        while (num > 0) {
            switch(num%10) {
                case 0: 
                    arr[0]++;
                    break;
                case 1: 
                    arr[1]++;
                    break;
                case 2: 
                    arr[2]++;
                    break;
                case 3: 
                    arr[3]++;
                    break;
                case 4: 
                    arr[4]++;
                    break;
                case 5: 
                    arr[5]++;
                    break;
                case 6: 
                    arr[6]++;
                    break;
                case 7: 
                    arr[7]++;
                    break;
                case 8: 
                    arr[8]++;
                    break;
                case 9:
                    arr[9]++;
                    break;
            }
            num /= 10;
        }
        
        for (int j=0;j<10;j++) 
            System.out.println(arr[j]);
    }
}
