import java.io.*;
import java.util.*;

class CowGymnastics {

    public static int numP, numC;
    public static int[][] rankings;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("gymnastics.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("gymnastics.out"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        numP = Integer.parseInt(st.nextToken());
        numC = Integer.parseInt(st.nextToken());
        rankings = new int[10][20];
        
        for(int i = 0; i < numP; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; i < numC; i++){
                rankings[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ctr = 0;
        for(int x = 1; x <= numC; x++){
            for(int y = 1; y <= numC; y++){
                if(n_better(x, y) == numP){
                    ctr++;
                }
            }
        }

        pw.println(ctr);
        pw.close();
    }

    public static int n_better(int a, int b){
        int total = 0;
        for(int i = 0; i < numP; i++){
            if(better(a, b, i)){
                total++;
            }
        }
        return total;
    }

    public static boolean better(int a, int b, int i){
        int aPos = 0; 
        int bPos = 0;
        for(int j = 0; j < numC; j++){
            if(rankings[i][j] == a){
                aPos = j;
            }
            if(rankings[i][j] == b){
                bPos = i;
            }
        }
        return aPos < bPos;
    }
}