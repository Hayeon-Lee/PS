import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        int A, B, C;
        Scanner scanner = new Scanner(System.in);

        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        if(B>=C){ //제작비용이 판매비용보다 같거나 큰 경우 손익분기점은 절대 생길 수 없다.
            System.out.println(-1);
            System.exit(0);
        }

        //제작비용이 판매비용보다 작다면
        //A+Bx <= Cx 부등식을 풀면  x >= -A/(B-C)

        int quantity = (A*-1 )/ (B-C); //최초로 같아지게 되는 숫자
        System.out.println(quantity+1); //무조건 소수점자리가 버려지므로 1 큰 수로 해야 최초로 수익이 커지는 숫자가 나온다
    }
}
