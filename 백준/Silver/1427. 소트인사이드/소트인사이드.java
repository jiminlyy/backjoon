import java.util.Scanner;

public class Main{
    public static void main(String agrs[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int []k = new int[10];
        int i = 0;
        while(true){
            if(n<10) {
                k[n]++;
                break;
            }
            else {
                k[n%10]++;
                n = n/10;
                i++;
            }
        }
        for(int m = 9; m>=0; m--){
            if(k[m] ==0){continue;}
            else{
            while(k[m] != 0){
                System.out.print(m);
                k[m]--;
            }
            }
        }
        
    }
}