import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = 0, flag = 0, count = 0;

        n = scanner.nextInt();
        int array[] = new int[n];

        for (int i = 0; i < n; i++){
            array[i] = scanner.nextInt();
        }

        for (int i = 0; i<n; i++){
            if (array[i] == 1) continue; //1은 소수가 아님
            for(int j = 2; j<array[i]; j++){ //1과 자기자신을 제외한 수로 나뉘어지면 소수가 아님
                if(array[i]%j == 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) count++;
            flag = 0;
        }

        System.out.println(count);
    }
}
