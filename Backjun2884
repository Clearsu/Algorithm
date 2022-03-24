import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int M = sc.nextInt();
        
        if ( M >= 45 ) { // 45분 다음일 경우 단순히 45 빼주면 됨
            System.out.println(H + " " + (M-45));
        } else { // 45분 전일 경우 : 시간이 1 줄어듦
            if ( H == 0 ) { // 0시 -> 23시 되므로
                System.out.println(23 + " " + (15+M));
            } else { // 일반적인 경우
                System.out.println((H-1) + " " + (15+M));
            }
        }
    }
}
