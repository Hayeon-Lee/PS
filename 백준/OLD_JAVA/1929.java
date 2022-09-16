import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int M = scanner.nextInt();
        int N = scanner.nextInt();

        ArrayList<Boolean> primeN = new ArrayList<Boolean>(N+1);
        primeN.add(false);
        primeN.add(false);

        for(int i = 2; i<=N; i++){
            primeN.add(i,true);
        }

        for(int i = 2; i*i<=N; i++){
            if(primeN.get(i)){
                for(int j = i*i; j<=N; j+=i) primeN.set(j, false);
            }
        }

        StringBuffer sb = new StringBuffer();
        for(int i = M; i<=N; i++){
            if(primeN.get(i)==true){
                sb.append(i);
                sb.append('\n');
            }
        }
        System.out.println(sb.toString());
    }
}
