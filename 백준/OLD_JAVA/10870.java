import java.util.Scanner;

class fibonacci{
    int N;

    fibonacci(int N){
        this.N = N;
    }

    int repeat(int N){
       if(N==0) return 0;
       else if(N==1) return 1;
       else return (repeat(N-1) + repeat(N-2));
    }
}

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        fibonacci f = new fibonacci(n);
        int answer = f.repeat(n);
        System.out.println(answer);
    }
}
