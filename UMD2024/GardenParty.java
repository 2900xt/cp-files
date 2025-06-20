package UMD2024;

import java.util.Scanner;



public class GardenParty {
    static class Solution {
        char[] four_set = new char[4];
        char[] three_set = new char[3];
    }

    private static Solution solveRamsey(String[] pairs) {
        Solution sol = new Solution();
        sol.four_set = null;
        sol.three_set = null;

        for(char c1 = 'A'; c1 <= 'I'; c1++)
        {
            for(char c2 = (char)(c1 + 1); c2 <= 'I'; c2++)
            {
                for(char c3 = (char)(c2 + 1); c3 <= 'I'; c3++)
                {
                    for(char c4 = (char)(c3 + 1); c4 <= 'I'; c4++)
                    {
                        boolean pos = true;
                        char[] arr = {c1, c2, c3, c4};
                        for(int i = 0; i < 4; i++)
                        {
                            for(int j = i+1; j < 4; j++)
                            {
                                boolean fnd = false;
                                for(String p : pairs)
                                {
                                    if(p.equals(arr[i] + "" + arr[j]) || p.equals(arr[j] + "" + arr[i]))
                                    {
                                        fnd = true;
                                    }
                                }

                                if(!fnd) pos = false;
                            }
                        }

                        if(pos && sol.four_set == null)
                        {
                        sol.four_set = arr;
                        }
                    }
                }
            }
        }

        for(char c1 = 'A'; c1 <= 'I'; c1++)
        {
            for(char c2 = (char)(c1 + 1); c2 <= 'I'; c2++)
            {
                for(char c3 = (char)(c2 + 1); c3 <= 'I'; c3++)
                {
                    boolean pos = true;
                    char[] arr = {c1, c2, c3};
                    for(int i = 0; i < 3; i++)
                    {
                        for(int j = i+1; j < 3; j++)
                        {
                            for(String p : pairs)
                            {
                                if(p.equals(arr[i] + "" + arr[j]) || p.equals(arr[j] + "" + arr[i]))
                                {
                                    pos = false;
                                }
                            }
                        }
                    }

                    if(pos && sol.three_set == null)
                    {
                        sol.three_set = arr;
                    }
                }
            }
        }


        return sol;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numCases = sc.nextInt();

        for(int i = 0; i < numCases; i++) 
        {
            int M = sc.nextInt();

            String[] pairs = new String[M];

            for(int j = 0; j < M; j++) {
                pairs[j] = sc.next();
            }

            Solution sol = solveRamsey(pairs);

            if(sol.four_set == null) {
                System.out.println("No 4-set of people have all gone on quests with each other.");
            } else {
                System.out.println("These 4 people have gone on quests with each other : " + sol.four_set[0] + " " + sol.four_set[1] + " " + sol.four_set[2] + " " + sol.four_set[3]);
            }

            if(sol.three_set == null) {
                System.out.println("Every 3-set of people has a pair that has done a quest."); 
            } else {
                System.out.println("These 3 people have not gone on quests with each other : " + sol.three_set[0] + " " + sol.three_set[1] + " " + sol.three_set[2]);
            }
        }
    }
}
