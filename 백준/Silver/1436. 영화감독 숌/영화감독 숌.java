import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int count = 0;
        int num = 666;

        while (true) {
            String s = String.valueOf(num); //숫자를 문자열로 바꿈
            if (s.contains("666")) { // 666이라는 문자열이 있으면 count
            count++;
            }

            if (count == n) {
                System.out.println(num);
                break;
            }

        num++;
        }    
    }
}