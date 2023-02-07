//일단 세준이는 자기 점수 중에 최댓값을 골랐다. 이 값을 M이라고 한다. 
//그리고 나서 모든 점수를 점수/M*100으로 고쳤다.
//첫째줄 N(과목 수)
//둘째줄 점수들

import java.io.*;
import java.util.StringTokenizer;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        
        double[] scores = new double[N];

        for (int i=0;i<N;i++) // 점수 배열에 넣기
            scores[i] = Double.parseDouble(st.nextToken());
        
        double max = 0;
        for (int i=0;i<N;i++) { // 최댓값
            if (max < scores[i])
                max = scores[i];
        }
        
        double total = 0; // 점수 합
        for (int i=0;i<N;i++) {
            total += scores[i];
        }
        
        System.out.println((((total)/N)/max)*100); // (원래 평균)/(최댓값)*100
    }
}
