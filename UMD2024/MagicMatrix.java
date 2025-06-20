package UMD2024;

import java.util.Scanner;
import java.lang.Math;

public class MagicMatrix {

    static int[] toAdd = new int[4];
    public static int reconstruct(int[][] mat, int ind)
    {
        if(ind == 4) 
        {
            int ans=0;
            for(int i = 0; i < 4; i++)
            {
                int prod=1;
                for(int j = 0 ; j < 4; j++) prod *= mat[i][j];
                ans += prod;
            }

            for(int i = 0; i < 4; i++)
            {
                int prod=1;
                for(int j = 0 ; j < 4; j++) prod *= mat[j][i];
                ans += prod;
            }

            return ans;
        }

        int ans = 0;
        for(int r = 0; r < 4; r++)
        {
            for(int c = 0; c < 4; c++)
            {
                if(mat[r][c] == 0)
                {
                    mat[r][c] = toAdd[ind];
                    ans = Math.max(ans, reconstruct(mat, ind+1));
                    mat[r][c] = 0;
                }
            }
        }
        return ans;
    }

    public static int reconstructMatrix(int[][] matrix) {
        int coin_haul = 0;
        int ind = 0;
        for(int i = 1; i <= 16; i++)
        {
            boolean fnd = false;
            for(int j = 0; j < 4; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    if(matrix[j][k] == i)
                    {
                        fnd = true;
                    }
                }
            }

            if(!fnd) 
            {
                toAdd[ind++] = i;
            }
        }

        return reconstruct(matrix, 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfTestCases = sc.nextInt();
        sc.nextLine();

        for (int testCase=0; testCase < numOfTestCases; testCase++) { 
            int[][] matrix = new int[4][4];

            for (int i=0; i<4; i++) {
                for (int j=0; j<4; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }

            int coin_haul = reconstructMatrix(matrix);

            // print out the result
            System.out.println("The maximum number of coins that can be collected is: " + coin_haul);
        }

        sc.close();
    }
}