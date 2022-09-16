import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        if(n==1) { //1일 경우
            System.out.println(1);
            System.exit(0);
        }

        int number = 6;
        int old_index = 1;
        int new_index;

        while(true){
            new_index = old_index+number;
            if(n>old_index && n<=new_index) {
                System.out.println((number/6)+1);
                break;
            }
            else{
                number += 6;
                old_index = new_index;
            }
        }
    }
}
