/*
같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다. 
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다. 
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.  
*/

import java.util.Scanner;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = 0;
        if (a == b && b == c) { // 세 눈이 모두 같은 경우
            System.out.println(10000 + a * 1000);
        } else if (a != b && b != c && a != c) { // 세 눈이 모두 다른 경우
            if (a > b) { // 가장 큰 수 판별
                d = a;
            } else if (b > c) {
                d = b;
            } else {
                d = c;
            }
            System.out.println(d * 100);
        } else { // 두 눈이 같을 경우
            if (a != b) {
                System.out.println(1000 + c * 100); // 어느 두 눈이 다르면 나머지 한 눈은 두 눈 중
            } else if (a != c) {                    // 하나와 반드시 같음
                System.out.println(1000 + b * 100);
            } else {
                System.out.println(1000 + a * 100);
            }
        }
    }
}
