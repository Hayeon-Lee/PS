import java.util.Scanner;
import java.lang.Math;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);

        double radius = scanner.nextDouble();
        double Ucircle = radius * radius * (Math.PI);
        System.out.println(Ucircle);

        double t_radius = Math.sqrt((radius*radius)+(radius*radius));
        double Tcircle = t_radius * t_radius;
        System.out.println(Tcircle);
    }
}
