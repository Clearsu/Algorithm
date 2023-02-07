import java.util.Scanner; // Scanner class import

public class Main{
    public static void main(String args[]){
        Scanner s = new Scanner(System.in); // 스캐너 객체 생성
        int a = s.nextInt();
        int b = s.nextInt(); // 입력 읽어서 변수 저장
        s.close();
        
        System.out.println(a/(double)b); // 실수 형태로 강제형변환하여 소숫점 이하까지 출력하도록
    }
}
