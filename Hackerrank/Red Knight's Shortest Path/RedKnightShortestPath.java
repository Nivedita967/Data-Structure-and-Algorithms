import java.io.* ;
import java.math.* ;
import java.security.* ;
import java.text.* ;
import java.util.* ;
import java.util.concurrent.* ;
import java.util.regex.* ;

public class Solution {

  // Java class to store pair as key in hashmap 
  public static class Index {

    private int x;
    private int y;

    public Index(int x, int y) {
      this.x = x;
      this.y = y;
    }

    // override function to calculate hashcode for my key
    @Override
    public int hashCode() {
      return this.x ^ this.y;
    }

    @Override
    public boolean equals(Object obj) {
      if (this == obj) return true;
      if (obj == null) return false;
      if (getClass() != obj.getClass()) return false;
      Index other = (Index) obj;
      if (x != other.x) return false;
      if (y != other.y) return false;
      return true;
    }
  }

  static void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    
    // Arraylist to store string path of final resultant path
    ArrayList < String > result = new ArrayList < String > ();
    
    // Boolean array to mark visited cells , source is initially marked visited;
    boolean[][] visited = new boolean[n][n];
    visited[i_start][j_start] = true;
    
    // HashMap to store coordinates(x, y) vs string Path from source cell to current cell , Source is at given starting coordinates
    HashMap < Index, String > parent = new HashMap <>();
    Index src = new Index(i_start, j_start);
    parent.put(src, "");
    
    // Queue data structure used to implement Breadth First Search Algorithm, initially source cell added to queue 
    Queue < Index > pq = new LinkedList < >();
    pq.add(src);
    
    // Extra variables to store certain entities
    int count = 0 , size = 1;
    boolean flag = false;
    
    // Direction arrays that tells the possible next move for knight
    int[][]dir={{-2, -1}, {-2, 1}, {0, 2}, {2, 1}, {2, -1}, {0, -2}};
    String[]directions={"UL", "UR", "R", "LR", "LL", "L"};

    // Breadth First Search Algorithm
    while (pq.size() != 0) {
      Index top = pq.poll();
      int x = top.x;
      int y = top.y;
      if (x == i_end && y == j_end) {
        flag = true;
        break;
      }

      // Selecting next valid moves out of all possible moves and adding them to queue for shortest Path traversal
      for (int i = 0; i < dir.length; i++) {
        int newx = x + dir[i][0];
        int newy = y + dir[i][1];
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && !visited[newx][newy]) {
          Index newpair = new Index(newx, newy);
          Index oldpair = new Index(x, y);
          pq.add(newpair);
          parent.put(newpair, parent.get(oldpair) + " " + directions[i]);
          visited[newx][newy] = true;
        }
      }
      size--;
      if (size == 0) {
        count++;
        size = pq.size();
      }
    }

    // Print the distance along with the sequence of moves.
    if (!flag) {
      System.out.println("Impossible");
    }
    else {
      Index pair = new Index(i_end, j_end);
      System.out.println(count);
      System.out.println(parent.get(pair).substring(1));
    }
  }

  // driver code as per hackerrank platform
  private static final Scanner scanner = new Scanner(System. in );

  public static void main(String[] args) {
    int n = scanner.nextInt();
    scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

    String[] i_startJ_start = scanner.nextLine().split(" ");

    int i_start = Integer.parseInt(i_startJ_start[0]);

    int j_start = Integer.parseInt(i_startJ_start[1]);

    int i_end = Integer.parseInt(i_startJ_start[2]);

    int j_end = Integer.parseInt(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    scanner.close();
  }
}