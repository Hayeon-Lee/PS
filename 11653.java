import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        if (N==1) System.exit(0); //N이 1일 경우 아무것도 출력하지 않는다

        StringBuilder sb = new StringBuilder();
        
        for(int i = 2; i*i <= N; i++){
            while(N%i==0){
                sb.append(i).append('\n');
                N/=i;
            }
        }

        if(N!=1) sb.append(N);

        System.out.println(sb);
    }
}
