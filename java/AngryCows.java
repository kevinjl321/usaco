import java.io.*;
import java.util.*;

class AngryCows{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("angry.in"));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));
        
		int n = Integer.parseInt(br.readLine());
		int[] locations = new int[n];
		for(int i = 0; i < n; i++) {
			locations[i] = Integer.parseInt(br.readLine());
		}
		Arrays.sort(locations);

		int fin = 1;
		for(int start = 0; start < n; start++) {
			int leftMostExplosion = getExplosionIndex(locations, start, true);
			
			int rightMostExplosion = getExplosionIndex(locations, start, false);
		
			int numExploded = rightMostExplosion - leftMostExplosion + 1;
		 
			if(numExploded > fin) {
				fin = numExploded;
			}
		}
		pw.println(fin);
		pw.close();
	}

	public static int getExplosionIndex(int[] location, int startIndex, boolean goLeft) {
		int lastExplosionIndex = startIndex;
		int currentRadius = 1;
		while(lastExplosionIndex > 0 && lastExplosionIndex < location.length-1) {
			int direction = 0;
			if(goLeft) {
				direction = -1;
			}
			else {
				direction = 1;
			}
			int nextIndex = lastExplosionIndex;
			while(nextIndex + direction >= 0 && nextIndex + direction < location.length && Math.abs(location[nextIndex + direction] - location[lastExplosionIndex]) <= currentRadius) {
				nextIndex += direction;
			}
			if(nextIndex == lastExplosionIndex) {
				break;
			}
			lastExplosionIndex = nextIndex;
			currentRadius++;
		}
		return lastExplosionIndex;
	}
	
}
    
