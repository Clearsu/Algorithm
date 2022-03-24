import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int h = sc.nextInt();
        int m = sc.nextInt();
        int t = sc.nextInt();
        m += t;
        int newM = m % 60; // 표시될 분
        int newH = h + (m/60); // 표시될 시
        
        if (newH >= 24) { 
            newH %= 24; // 24시가 넘어가는 경우 시간 설정
        }
        
        System.out.println(newH + " " + newM);
        
    }
}
