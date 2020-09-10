import java.io.*;
import java.util.*;

class badmilk {
	static int[] personDrink;
	static int[] milkDrink;
	static int[] timeDrink;
	static int[] personSick;
	static int[] timeSick;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("badmilk.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("badmilk.out")));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int s = Integer.parseInt(st.nextToken());

		personDrink = new int[d];
		milkDrink = new int[d];
		timeDrink = new int[d];
		for(int i = 0; i < d; i++) {
			st = new StringTokenizer(br.readLine());
			personDrink[i] = Integer.parseInt(st.nextToken());
			milkDrink[i] = Integer.parseInt(st.nextToken());
			timeDrink[i] = Integer.parseInt(st.nextToken());
		}
		
		personSick = new int[s];
		timeSick = new int[s];
		for(int i = 0; i < s; i++) {
			st = new StringTokenizer(br.readLine());
			personSick[i] = Integer.parseInt(st.nextToken());
			timeSick[i] = Integer.parseInt(st.nextToken());
		}
		
		int maxCanGetSick = 0;
		
		for(int i = 1; i <= m; i++) {
			if(milkTypeCanBeBad(i)) {
				int numDrank = numPeopleDrink(i);
				if(numDrank > maxCanGetSick) {
					maxCanGetSick = numDrank;
				}
			}
		}		
		pw.println(maxCanGetSick);
		pw.close();
	}
	
	private static boolean milkTypeCanBeBad(int milkType) {
		for(int i = 0; i < personSick.length; i++) {
			if(!personDrankMilkBefore(personSick[i], milkType, timeSick[i])) {
				return false;
			}
		}
		return true;
	}
	
	private static boolean personDrankMilkBefore(int person, int milkType, int time) {
		for(int i = 0; i < personDrink.length; i++) {
			if(personDrink[i] == person && milkDrink[i] == milkType && timeDrink[i] < time) {
				return true;
			}
		}
		return false;
	}

	private static int numPeopleDrink(int milkType) {
		boolean[] didDrink = new boolean[51];
		for(int i = 0; i < personDrink.length; i++) {
			if(milkDrink[i] == milkType) {
				didDrink[personDrink[i]] = true;
			}
		}
		int numPeopleDrink = 0;
		for(int i = 1; i < didDrink.length; i++) {
			if(didDrink[i]) {
				numPeopleDrink++;
			}
		}
		return numPeopleDrink;
	}
	
}