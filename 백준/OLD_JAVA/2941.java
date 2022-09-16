import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        String alphabet[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

        String input = scanner.nextLine();

        for(int i = 0; i< alphabet.length; i++){
            if(input.contains(alphabet[i])){
                input = input.replace(alphabet[i], "#");
            }
        }
        System.out.println(input.length());
    }
}
