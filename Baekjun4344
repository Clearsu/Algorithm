import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        int cases = Integer.parseInt(br.readLine()); // 테스트 케이스의 개수
        
        for (int i=0;i<cases;i++) {
            st = new StringTokenizer(br.readLine()); // 테스트 케이스 읽기    
            int N = Integer.parseInt(st.nextToken()); // 학생의 수
            int[] scores = new int[N]; // 점수 배열 생성
            int sum = 0; // 점수 합계 구하기 위한 변수
            for (int j=0;j<N;j++) {
                scores[j] = Integer.parseInt(st.nextToken()); // 배열에 점수 삽입
                sum += scores[j]; // 평균 구하기 위한 점수 합계
            }
            int over_avg = 0; // 평균 넘는 학생 수 세기 위한 변수
            for (int j=0;j<N;j++) {
                if ((double)scores[j] > ((double)sum/N))
                    over_avg++;
            }
            double rate = ((double)over_avg/N)*100;
            bw.write(String.format("%.3f%%\n",rate)); // 소수점 셋째 자리까지 출력
        }
        br.close();
        bw.close();
    }
}
