import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int M = sc.nextInt();
        sc.nextLine();

        char[][] board = new char[N][M];

        for (int i = 0; i < N; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = line.charAt(j);
            }
        }

        int answer = 64;

        for (int x = 0; x <= N - 8; x++) {
            for (int y = 0; y <= M - 8; y++) {
                int count = countRepaint(board, x, y);
                answer = Math.min(answer, count);
            }
        }

        System.out.println(answer);
    }

    public static int countRepaint(char[][] board, int x, int y) {
        int whiteStart = 0;
        int blackStart = 0;

        for (int i = x; i < x + 8; i++) {
            for (int j = y; j < y + 8; j++) {
                if ((i + j) % 2 == 0) {
                    if (board[i][j] != 'W') whiteStart++;
                    if (board[i][j] != 'B') blackStart++;
                } else {
                    if (board[i][j] != 'B') whiteStart++;
                    if (board[i][j] != 'W') blackStart++;
                }
            }
        }

        return Math.min(whiteStart, blackStart);
    }
}