import java.io.*;
import java.util.*;

class Promote{
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new FileReader("promote.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("promote.out"));
        
        StringTokenizer bronze = new StringTokenizer(r.readLine());
        StringTokenizer silver = new StringTokenizer(r.readLine());
        StringTokenizer gold = new StringTokenizer(r.readLine());
        StringTokenizer plat = new StringTokenizer(r.readLine());

        int initBronze = Integer.parseInt(bronze.nextToken());
        int initSilver = Integer.parseInt(silver.nextToken());
        int finSilver = Integer.parseInt(silver.nextToken());
        int initGold = Integer.parseInt(gold.nextToken());
        int finGold = Integer.parseInt(gold.nextToken());
        int initPlat = Integer.parseInt(plat.nextToken());
        int finPlat = Integer.parseInt(plat.nextToken());

        pw.println(finSilver - initSilver + finGold - initGold + finPlat - initPlat);
        pw.println(finGold - initGold + finPlat - initPlat);
        pw.println(finPlat - initPlat);

        pw.close();

    }
}