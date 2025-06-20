package UMD2024;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Objects;
import java.util.Random;
import java.util.Scanner;

public class MaximizingHarmony {

    static class DSU {
        private final List<Integer> e;
        private final List<Integer> harmony;
        
        // Constructor to initialize the DSU with a size N
        public DSU(int N) {
            e = new ArrayList<>(Collections.nCopies(N, -1)); 
            harmony = new ArrayList<>(Collections.nCopies(N, 0));
        }
    
        // Initialize the DSU with a size N
        public void init(int N) {
            e.clear();
            e.addAll(Collections.nCopies(N, -1));
        }
    
        // Find the representative of the set containing x
        public int get(int x) {
            if (e.get(x) < 0) {
                return x;
            } else {
                e.set(x, get(e.get(x))); 
                return e.get(x);
            }
        }
    
        // Check if elements a and b belong to the same set
        public boolean sameSet(int a, int b) {
            return get(a) == get(b);
        }
    
        // Return the size of the set containing x
        public int size(int x) {
            return -e.get(get(x));
        }
    
        // Union the sets containing x and y by size
        public boolean unite(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) return false;
            
            if (e.get(x) > e.get(y)) {
                int temp = x;
                x = y;
                y = temp;
            }
            
            int val = harmony.get(x) + harmony.get(y) + 1;
            harmony.set(x, val);
            harmony.set(y, val);
            e.set(x, e.get(x) + e.get(y));
            e.set(y, x);
            return true;
        }
    }
    
    
    public static class Edge implements Comparable<Edge> {
        public int u;
        public int v;
        public int weight;

        public Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge other) {
            return Integer.compare(this.weight, other.weight);  
        }
    }


    public static int maxHarmony(int numVertices, ArrayList<Edge> typeshit) 
    {
        DSU d = new DSU(numVertices);
        Collections.sort(typeshit);
        for(Edge e : typeshit)
        {
            d.unite(e.u, e.v);
        }

        return d.harmony.get(0);
    }

    public static int RunTestCase(Scanner sc) {
        // Read the seed and the number of nodes.
        int seed=sc.nextInt();
        int N=sc.nextInt();

        Random r = new Random(seed);
        Integer[] P = new Integer[N-1];
        for (int i = 0; i < N-1; i++) {
            P[i] = i;
        }
        Collections.shuffle(Arrays.asList(P), r);

        ArrayList<Edge> edges = new ArrayList<Edge>();
        for (int i = 1; i < N; i++) {
            int target = r.nextInt(i);
            edges.add(new Edge(i, target, P[i-1]));
        }

        return maxHarmony(N, edges);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfTestCases = sc.nextInt();
        sc.nextLine();

        for (int testCase=0; testCase < numOfTestCases; testCase++) { 
            int answer = RunTestCase(sc);
            System.out.println("Max Penalty: " + answer);
        }

        sc.close();
    }
}