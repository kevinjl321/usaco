/*
import java.io.*;
import java.util.*;

class LoadBalancing{
    public static void main (String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("balancing.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("balancing.out"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int nCows = Integer.parseInt(st.nextToken());
        int sideLen = Integer.parseInt(st.nextToken());

        int[] cowX = new int[nCows];
        int[] cowY = new int[nCows];
        for(int i = 0; i < nCows; i++){
            st = new StringTokenizer(br.readLine());
            cowX[i] = Integer.parseInt(st.nextToken());
            cowY[i] = Integer.parseInt(st.nextToken());
        }
        int ans = nCows;
		for(int xIndex = 0; xIndex < nCows; xIndex++) {
			for(int yIndex = 0; yIndex < nCows; yIndex++) {
				int xDiv = cowX[xIndex]+1;
				int yDiv = cowY[yIndex]+1;
				int upperLeft = 0;
				int upperRight = 0;
				int lowerLeft = 0;
				int lowerRight = 0;
				for(int i = 0; i < nCows; i++) {
					if(cowX[i] < xDiv && cowY[i] < yDiv) {
						lowerLeft++;
					}
					if(cowX[i] < xDiv && cowY[i] > yDiv) {
						upperLeft++;
					}
					if(cowX[i] > xDiv && cowY[i] < yDiv) {
						lowerRight++;
					}
					if(cowX[i] > xDiv && cowY[i] > yDiv) {
						upperRight++;
					}
				}
				int worstRegion = 0;
				if(upperLeft > worstRegion) {
					worstRegion = upperLeft;
				}
				if(upperRight > worstRegion) {
					worstRegion = upperRight;
				}
				if(lowerLeft > worstRegion) {
					worstRegion = lowerLeft;
				}
				if(lowerRight > worstRegion) {
					worstRegion = lowerRight;
                }
				if(worstRegion < ans) {
					ans = worstRegion;
				}
			}
        }
        pw.println(ans);
        pw.close();
        
    }
}
*/
