import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();

        int count = 0;
        count = scanner.nextInt(); //테스트 갯수

        for(int i=0; i<count; i++) {
            int N = scanner.nextInt(); //숫자

            ArrayList<Boolean> primeN = new ArrayList<Boolean>(N + 1); //N+1: 0도 숫자로 치기 때문에 출력할 때 용이하게 하기 위함
            primeN.add(false); //0은 소수아님
            primeN.add(false); //1도 소수아님

            for (int j = 2; j <= N; j++) { //2부터 N까지 소수라고 침
                primeN.add(j, true);
            }

            for (int j = 2; j * j <= N; j++) { //루트 N까지의 숫자만 고려
                if (primeN.get(j)) { //만약 해당 숫자가 true면 (에라토스테네스의 체에 의해 걸러지지 않았다면)
                    for (int k = j * j; k <= N; k += j) primeN.set(k, false); //i*i 부터 N까지 i의 배수를 제거
                }
            }

            for (int j = N/2; j <= N; j++) {
                if (primeN.get(j)) {
                    if(primeN.get(N-j)){
                        sb.append(N-j);
                        sb.append(' ');
                        sb.append(j);
                        sb.append('\n');
                        break;
                    }
                }
            }
        }
        System.out.println(sb.toString());
        System.exit(0);
    }
}
