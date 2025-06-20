package UMD2024;

import java.util.*;

public class KoopaFinda {

    private static int lookForKoopa(String str) {

        int cnt = 0;
        for(int i = 0; i < str.length()-4; i++) 
        {
            if(str.substring(i, i+5).equals("Koopa"))
            {
                cnt++;
            }
        }
        
        if(str.contains("Peach"))
        {
            return cnt;
        }

        return -1;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfTestCases = sc.nextInt();
        sc.nextLine();

        for (int testCase=0; testCase < numOfTestCases; testCase++) { 
            String str = sc.nextLine();
            System.out.println(
                    "Result is " + lookForKoopa(str)
                    );
        }

        sc.close();
    }


}
