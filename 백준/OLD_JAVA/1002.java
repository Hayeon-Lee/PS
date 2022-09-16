import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for(int i = 0; i<n; i++){
            int x1 = scanner.nextInt();
            int y1 = scanner.nextInt();
            int r1 = scanner.nextInt();

            int x2 = scanner.nextInt();
            int y2 = scanner.nextInt();
            int r2 = scanner.nextInt();

            double dist = Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));
            int count = 0;
            int dist_rad = 0;
            if(r1>r2) dist_rad = r1-r2;
            else dist_rad = r2-r1;

            if(dist == 0 && (r1==r2)) count = -1;

            //두 점에서 접할 때
            else if((dist_rad < dist) && (dist < (r1+r2))) count = 2;

            //외접 또는 내접할 때
            else if ((r1+r2 ==dist) || (dist_rad == dist)) count = 1;

            //만나지 않을 때
            else if ((r1+r2 < dist) || (dist_rad > dist)) count = 0;

            else count = 0;

            System.out.println(count);
        }
    }
}
