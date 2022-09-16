import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int M = 0, N = 0, flag = 0, small=10001, sum = 0;
        M = scanner.nextInt();
        N = scanner.nextInt();

        for(int i = M; i<=N; i++){
            if(i==1) continue;
            for(int j = 2; j<i ; j++){
                if(i%j == 0){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                sum += i;
                if(small >= i) small = i;
            }
            flag = 0;
        }

        if (sum == 0 || small ==0) System.out.println(-1);
        else {
            System.out.println(sum);
            System.out.println(small);
        }
    }
}
