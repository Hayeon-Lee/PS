import java.util.Scanner;

class factorial{
    int N;

    factorial(int N){
        this.N = N;
    }

    int repeat(int N){
        if (N == 0) return 1;
        else if (N==1) return N;
        else return (N * repeat(N-1));
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        factorial f = new factorial(n);
        int answer = f.repeat(n);
        System.out.println(answer);
    }
}
