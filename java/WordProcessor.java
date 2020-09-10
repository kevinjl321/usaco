import java.io.*;
import java.util.*;

class WordProcessor{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("word.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("word.out"));   
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        String essay = br.readLine();

        String[] words = essay.split(" ", -1);

        int len = 0;
        for(int i = 0; i < n; i++){
            if(len + words[i].length() > k){
                pw.print("\n" + words[i]);
                len  = words[i].length();
            }
            else{
                if (len > 0){
                    pw.print(" ");
                } 
                pw.print(words[i]);
                len += words[i].length();
            }
        }
        pw.close();
    }
}