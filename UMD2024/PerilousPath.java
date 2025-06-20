package UMD2024;

import java.util.*;

public class PerilousPath {

    private static int findPath(char[][] grid) {
        int steps = -1;

        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();
        int xDirs[] = {0, 1, 0, -1};
        int yDirs[] = {1, 0, -1, 0};
        int [][]dist = new int[grid.length][grid[0].length];
        
        for(int k = 0; k < grid.length; k++) {
            for(int l = 0; l < grid[k].length; l++) {
                dist[k][l] = 10000000;
                if(grid[k][l] == 'M') {
                    queue.add(new Pair<>(k, l));
                    dist[k][l] = 0;
                }
            }
        }

        int ans = 1000000;

        while(!queue.isEmpty())
        {
            Pair<Integer, Integer> top = queue.poll();
            for(int i = 0; i < 4; i++)
            {
                int nx = top.first + xDirs[i], ny = top.second + yDirs[i];
                if(nx < 0 || ny < 0 || nx >= grid.length || ny >= grid[0].length) continue;
                if(grid[nx][ny] == 'S') continue;
                
                if(dist[nx][ny] > dist[top.first][top.second] + 1)
                {
                    dist[nx][ny] = dist[top.first][top.second] + 1;
                    if(grid[nx][ny] == 'P') ans = Math.min(ans, dist[nx][ny]);
                    queue.add(new Pair<Integer,Integer>(nx, ny));
                }
            }
        }

        if(ans == 1000000)
        {
            return -1;
        }
        
        return ans;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int numOfTestCases = sc.nextInt();
        sc.nextLine();

        char[][] levelGrid;
        for (int testCase=0; testCase < numOfTestCases; testCase++) { 
            int width = sc.nextInt();
            int height = sc.nextInt();
            sc.nextLine();
            levelGrid = new char[height][width];
            for (int row=0; row<height; row++) {
                String currRow = sc.nextLine();
                for (int col=0; col<width; col++) {
                    char val = currRow.charAt(col);
                    levelGrid[row][col]=val;
                }
            }

            int result=findPath(levelGrid);
            if (result > 0) {
                System.out.println(
                        "Path length is " + findPath(levelGrid)
                        );
            }
            else {
                System.out.println(
                        "Path is blocked." 
                        );
            }
        }

        sc.close();
    }

    static class Pair<T extends Comparable<T>, U extends Comparable<U>> {
        T first;
        U second;
    
        // Constructor to initialize the pair
        public Pair(T first, U second) {
            this.first = first;
            this.second = second;
        }
    
        // Method to compare the first elements of the pair
        public int compareFirst(Pair<T, U> other) {
            return this.first.compareTo(other.first);
        }
    
        // Method to compare the second elements of the pair
        public int compareSecond(Pair<T, U> other) {
            return this.second.compareTo(other.second);
        }
    
        // Method to compare the whole pair lexicographically: first then second
        public int compare(Pair<T, U> other) {
            int firstComparison = this.compareFirst(other);
            if (firstComparison != 0) {
                return firstComparison;
            }
            return this.compareSecond(other);
        }
    
        // Overriding equals() method
        @Override
        public boolean equals(Object obj) {
            if (obj == null || getClass() != obj.getClass()) {
                return false;
            }
            if (this == obj) {
                return true;
            }
            Pair<?, ?> other = (Pair<?, ?>) obj;
            return Objects.equals(first, other.first) && Objects.equals(second, other.second);
        }
    
        // Overriding hashCode() method
        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    
        @Override
        public String toString() {
            return "(" + first + ", " + second + ")";
        }
    }
    
}
