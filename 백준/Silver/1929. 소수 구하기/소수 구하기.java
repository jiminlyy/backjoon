import java.util.*;

public class Main{
    public static boolean Prime(int num){
        if(num == 0||num ==1)return false;
        for(int i = 2; i *i<=num; i++){
            if(num % i ==0){
                return false;
            }
        }
        return true;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        for(int i = a; i<=b; i++){
            boolean k = Prime(i);
            if(k){
                System.out.println(i);
            }
        }
    }
}