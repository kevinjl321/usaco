import java.io.*;
import java.util.*;

class SquarePasture {
    public static void main(String[] args) throws IOException{
        BufferedReader br  = new BufferedReader(new FileReader("square.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("square.out"));
        
        int minX = 10;
        int minY = 10;
        int maxX = 0;
        int maxY = 0;

        for(int i = 0; i < 2; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int xLow = Integer.parseInt(st.nextToken());
			int yLow = Integer.parseInt(st.nextToken());
			int xHigh = Integer.parseInt(st.nextToken());
			int yHigh = Integer.parseInt(st.nextToken());
			
			if(xLow < minX) {
				minX = xLow;
			}
			if(xHigh > maxX) {
				maxX = xHigh;
			}
			if(yLow < minY) {
				minY = yLow;
			}
			if(yHigh > maxY) {
				maxY = yHigh;
			}
        }
        
        int len = maxX - minX;
        if(maxY - minY > len){
            len = maxY - minY;
        }

        pw.println(len * len);
        pw.close();

    }
}