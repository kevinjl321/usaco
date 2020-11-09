import java.io.*;
import java.util.*;

class Blocks {
    public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new FileReader("blocks.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));

		int[] blocksNeeded = new int[26];
		int n = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String firstWord = st.nextToken();
			String secondWord = st.nextToken();
			
			int[] firstFrequency = getFrequency(firstWord);
			int[] secondFrequency = getFrequency(secondWord);

			for(int j = 0; j < 26; j++) {
				if(firstFrequency[j] > secondFrequency[j]) {
					blocksNeeded[j] += firstFrequency[j];
				}
				else {
					blocksNeeded[j] += secondFrequency[j];
				}
			}
		}
		for(int i = 0; i < 26; i++) {
			pw.println(blocksNeeded[i]);
		}
		pw.close();
	}
	public static int[] getFrequency(String s) {
		int[] blocksNeeded = new int[26];
		for(int i = 0; i < s.length(); i++) {
			int index = s.charAt(i) - 'a';
			blocksNeeded[index]++;
		}
		return blocksNeeded;
	}
}