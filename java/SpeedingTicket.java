import java.io.*;
import java.util.*;

class SpeedingTicket {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("speeding.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("speeding.out"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] limits = new int[100];
        int frame = 0;
        
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int limit = Integer.parseInt(st.nextToken());
            for(int j = 0; j < len; j++){
                limits[frame] = limit;
                frame++;
            }
        }

        int speeds[] = new int[100];
        frame = 0;

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int limit = Integer.parseInt(st.nextToken());
            for(int j = 0; j < len; j++){
                speeds[frame] = limit;
                frame++;
            }
        }

        int max = 0;
        for(int i = 0; i < 100; i++){
            int over = speeds[i] - limits[i];
            if(over > max){
                max = over;
            }
        }

        pw.println(max);
        pw.close();

    }

}