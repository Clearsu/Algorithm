// 6 > 12 > 18 > 24 > ...
// 가운데에서 n 칸 밖으로 갈 때마다 해당 라인의 cell 수는 6n 씩 증가
// 1 : 1 번 이동
// 2 ~ 7 : 2 번 이동
// 8 ~ 19 : 3 번 이동
// 20 ~ 37 : 4 번 이동

import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // 가고자 하는 cell 번호
        
        int i = 0;
        int num = 1;
        while (true) {
            num = num + 6*i;
            if (N == 1) {
                System.out.println(1);
                break;
            } else if ((num-6*i+1) <= N && N <= num) {
                System.out.println(i+1);
                break;
            }
            i++;
        }
    }
}
