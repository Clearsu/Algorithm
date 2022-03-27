import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int[] array = new int[42];
        int num;
        
        for (int i=0;i<42;i++)
            array[i] = 0;
        
        for (int i=0;i<10;i++) {
            num = Integer.parseInt(br.readLine())%42;
            if (array[num] != 0)
                continue;
            else
                array[num]++;
        }
        
        int count = 0;
        for (int i=0;i<42;i++)
            count += array[i];
        
        System.out.println(count);
        
    }
}
