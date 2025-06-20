
import java.io.*;
import java.util.*;

public class Main {
    static class FastReader {
        BufferedReader b;
        StringTokenizer s;
        public FastReader() {
            b = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (s == null || !s.hasMoreElements()) {
                try {
                    s = new StringTokenizer(b.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return s.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    static long min(long a, long b)
    {
        return a < b ? a : b;
    }

    public static void main(String[] args) {
        FastReader sc = new FastReader();
        int n = sc.nextInt(), m = sc.nextInt(), q = sc.nextInt();
        
        long[][] dist = new long[n][n];
        long INF = (long)1e18;

        StringBuilder ans = new StringBuilder("");

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                dist[i][j] = INF;
            }
        }

        for(int i = 0; i < n; i++) dist[i][i] = 0;

        for(int i = 0; i < m; i++)
        {
            int u = sc.nextInt(), v = sc.nextInt();
            u--; v--;

            int w = sc.nextInt();
            dist[u][v] = Math.min(dist[u][v], w);
            dist[v][u] = Math.min(dist[v][u], w);
        }

        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {            
                    if (dist[i][k] < INF && dist [k][j] < INF) 
                    {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        for(int i = 0; i < q; i++)
        {
            int u = sc.nextInt(), v = sc.nextInt();
            u--; v--;
            
            if(dist[u][v] == INF)
            {
                ans.append("-1\n");
            }
            else 
            {
                ans.append(dist[u][v]).append("\n");
            }
        }
        System.out.print(ans);
    }
}
