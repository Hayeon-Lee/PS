import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int x, y, w, h;
        x = scanner.nextInt();
        y = scanner.nextInt();
        w = scanner.nextInt();
        h = scanner.nextInt();

        float w1 = (float)w/2;
        float h1 = (float)h/2;
        int dx, dy;

        if(x<w1) dx = x;
        else dx = (w-x);

        if(y<h1) dy = y;
        else dy = (h-y);

        if(dx<dy) System.out.println(dx);
        else System.out.println(dy);
    }
}
