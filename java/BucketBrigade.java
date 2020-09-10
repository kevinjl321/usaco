import java.io.*;
import java.util.*;

class BucketBrigade { 
    public static int barnX;
    public static int barnY;
    public static int rockX;
    public static int rockY;
    public static int lakeX;
    public static int lakeY;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("buckets.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("buckets.out"));

        for(int i = 0; i < 10; i++){
            String map = br.readLine();
            for(int j = 0; i < 10; i++){
                if(map.charAt(j) == 'B'){
                    barnX = j;
                    barnY = i;
                }
                if(map.charAt(j) == 'L'){
                    lakeX = j;
                    lakeY = i;
                }
                if(map.charAt(j) == 'R'){
                    rockX = j;
                    rockY = i;
                }
            }
        }

        int barnToRock = Math.abs(barnX - rockX) + Math.abs(barnY - rockY);
        int barnToLake = Math.abs(barnX - lakeX) + Math.abs(barnY - lakeY);
        int rockToLake = Math.abs(rockX - lakeX) + Math.abs(rockY - lakeY);

        if((barnX == lakeX || barnY == lakeY) && barnToLake == barnToRock + rockToLake){
            pw.println(barnToLake + 1);
        }
        else{
            pw.println(barnToLake - 1);
        }
        pw.close();
    }
}