import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        StringBuffer sb = new StringBuffer();

        int count = 0;

        while(true) {
            int M = scanner.nextInt();
            int N = 2 * M;
            if(M<=0) break;

            ArrayList<Boolean> primeN = new ArrayList<Boolean>(N + 1); //N+1: 0도 숫자로 치기 때문에 출력할 때 용이하게 하기 위함
            primeN.add(false); //0은 소수아님
            primeN.add(false); //1도 소수아님

            for (int i = 2; i <= N; i++) { //2부터 N까지 소수라고 침
                primeN.add(i, true);
            }

            //N=4
            for (int i = 2; i * i <= N; i++) { //루트 N까지의 숫자만 고려
                if (primeN.get(i)) { //만약 해당 숫자가 true면 (에라토스테네스의 체에 의해 걸러지지 않았다면)
                    for (int j = i * i; j <= N; j += i) primeN.set(j, false); //i*i 부터 N까지 i의 배수를 제거
                }
            }

            for (int i = M+1; i <= N; i++) {
                if (primeN.get(i) == true) {
                    count++;
                }
            }
            sb.append(count);
            sb.append('\n');
            count =0;
        }
        System.out.println(sb.toString());
    }
}
