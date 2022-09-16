import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStreamReader;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int result = n;

        StringTokenizer st;
        for (int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            String s = st.nextToken();
            int cnt = 0;

            for(char c = 'a'; c<= 'z'; c++){
                int first = s.indexOf(c);
                int last = s.lastIndexOf(c);
                if(first!=last){
                    for(int j = first+1; j<last; j++){
                        if(s.charAt(j)!=c){
                            cnt++;
                            break;
                        }
                    }
                }
            }
            if(cnt!=0) {
                result--;
            }
        }
        System.out.println(result);
    }
}
