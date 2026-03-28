import java.util.*;

public class Main{
    public static boolean prime(long a){
        
        if(a == 0 || a == 1){
            return false;
        }
        for(long i = 2; i*i<=a; i++){
            if(a%i ==0){
                return false;
            }
        }
        return true;
        
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 0; i< n; i++){
            long num = sc.nextLong();
            while(true){
                boolean j = prime(num);
                if(j == false){
                    num++;
                }
                else{
                    break;
                }
            }
            System.out.println(num);
        }
    }
}