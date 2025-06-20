
import java.math.BigInteger;
import java.util.Scanner;

public class bigIntProblem 
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        for(int t = sc.nextInt(); t > 0; t--)
        {
            int N = sc.nextInt();
            if(N == 1)
            {
                System.out.println(1);
                continue;
            }

            int zeroes = (N-2)/2;
            String s = "14";
            for(int j = 0; j < zeroes; j++) s += "0";
            System.out.println(new BigInteger(s).multiply(new BigInteger(s)));

            for(int j = 0; j <= zeroes; j++)
            {
                s = "1";
                for(int k = 0; k < j; k++)
                {
                    s += "0";
                }

                s += "3";
                for(int k = j; k < zeroes; k++)
                {
                    s += "0";
                }

                System.out.println(new BigInteger(s).multiply(new BigInteger(s)));
            }

            for(int j = 0; j <= zeroes; j++)
            {
                s = "3";
                for(int k = 0; k < j; k++)
                {
                    s += "0";
                }

                s += "1";
                for(int k = j; k < zeroes; k++)
                {
                    s += "0";
                }

                System.out.println(new BigInteger(s).multiply(new BigInteger(s)));
            }
        }
    }
}