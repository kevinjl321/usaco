import java.io.*;
import java.util.*;

class WhereAmI {

    public static int n;
    public static String farms;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("whereami.out"));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        farms = br.readLine();

        int ctr = 1;
        while(isRepeating(ctr)){
            ctr++;
        }

        pw.println(ctr);
        pw.close();
    }
    
    public static boolean isRepeating(int len) {
        Set<String> set = new TreeSet<String>();
        for(int i = 0; i <= n - len; i++){
            if(set.contains(farms.substring(i, len))){
                return true;
            }
            set.add(farms.substring(i, len));
        }
        return false;
    }
}