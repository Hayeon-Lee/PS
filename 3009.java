import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int x1, y1, x2, y2, x3, y3;
        int x4, y4;

        x1 = scanner.nextInt();
        y1 = scanner.nextInt();
        x2 = scanner.nextInt();
        y2 = scanner.nextInt();
        x3 = scanner.nextInt();
        y3 = scanner.nextInt();

        if(x1 == x2) x4 = x3;
        else if (x1 == x3) x4 = x2;
        else x4 = x1;

        if (y1 == y2) y4 = y3;
        else if (y1 == y3) y4 = y2;
        else y4 = y1;

        System.out.print(x4);
        System.out.print(' ');
        System.out.print(y4);
    }
}
