import java.util.*;

public class Main {
    public static boolean prime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int k = sc.nextInt();
            if (k == 0) break;

            int count = 0;
            for (int i = k + 1; i <= 2 * k; i++) {
                if (prime(i)) {
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}