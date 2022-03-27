import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine()); // 주어질 문자열의 수
        
        for (int i=0;i<N;i++) {
            String OX = br.readLine(); // 문자열 한 줄 읽기
            
            int count = 1; // 연속되는 O의 수에 따라 1씩 증가시킬 변수
            int sum = 0; // 점수 합 저장할 변수
            for (int j=0;j<OX.length();j++) {
                if (OX.charAt(j)=='X') {
                    count = 1; // X 만날 경우 1로 초기화
                } else { // O일 경우 sum에 1, 2, 3, ... 더함
                    sum += count; 
                    count++;
                }
            }
            System.out.println(sum);
        }
    }
}
