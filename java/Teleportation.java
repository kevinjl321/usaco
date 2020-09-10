import java.io.*;
import java.util.*;

class Teleportation{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("teleport.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("teleport.out"));
        StringTokenizer ints = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(ints.nextToken());
        int b = Integer.parseInt(ints.nextToken());

        int x = Integer.parseInt(ints.nextToken());
        int y = Integer.parseInt(ints.nextToken());

        int dist1;
        if(Math.abs(a - x) > Math.abs(a - y)){
            dist1 = Math.abs(a - y);
        } 
        else{
            dist1 = Math.abs(a - x);
        }

        int dist2;
        if(Math.abs(b - x) > Math.abs(b - y)){
            dist2 = Math.abs(b - y);
        }
        else{
            dist2 = Math.abs(b - x);
        }

        pw.println(dist1 + dist2);
        pw.close();

    }
}