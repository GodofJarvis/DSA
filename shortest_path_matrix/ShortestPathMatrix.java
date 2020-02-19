import java.util.*;
public class ShortestPathMatrix{
    /*
     * Rat in a maze
     * 0 - Path, 1- wall, 9 - dest
     */
    public static Integer m, n;
    public static Integer[][] matrix;
    public static Integer[][] visited;
    public static Queue<Integer> myQueuex;
    public static Queue<Integer> myQueuey;
 
    public void initializeMatrix() {
        for (int i=0; i < m; i++) {
            for (int j=0; j < n; j++) {
                matrix [i][j] = 0;
                visited [i][j] = 0;
            }
        }
    }
 
    public void addWalls(Integer a, Integer b) {
        matrix[a][b] = 1;
    }
    
    public void displayMatrix(){
        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
 
    public void displayVisitedMatrix(){
        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                System.out.print(visited[i][j] + " ");
            }
            System.out.println();
        }
    }
 
    public void findPath(Integer x, Integer y){
        myQueuex.add(x);
        myQueuey.add(y);
        
        visited[x][y] = 1;
        while (!myQueuex.isEmpty()){
            x = myQueuex.remove();
            y = myQueuey.remove();
            
//            System.out.println(x + " " + y);
            if (matrix[x][y] == 9){
                System.out.println("Reached D with distance: " + visited[x][y]);
                return;
            }
            if (((y-1) >= 0) && (matrix[x][y-1] == 0 || matrix[x][y-1] == 9) && visited[x][y-1] == 0) {         //LEFT
                myQueuex.add(x);
                myQueuey.add(y-1);
                visited[x][y-1] = visited[x][y] + 1;
            }
            if (((y+1) < n) && (matrix[x][y+1] == 0 || matrix[x][y+1] == 9) && visited[x][y+1] == 0) {         //RIGHT
                myQueuex.add(x);
                myQueuey.add(y+1);
                visited[x][y+1] = visited[x][y] + 1;
            }
            if (((x-1) >= 0) && (matrix[x-1][y] == 0 || matrix[x-1][y] == 9) && visited[x-1][y] == 0) {         //UP
                myQueuex.add(x-1);
                myQueuey.add(y);
                visited[x-1][y] = visited[x][y] + 1;
            }
            if (((x+1) < m) && (matrix[x+1][y] == 0 || matrix[x+1][y] == 9) && visited[x+1][y] == 0) {         //DOWN
                myQueuex.add(x+1);
                myQueuey.add(y);
                visited[x+1][y] = visited[x][y] + 1;
            }
        }
        
    }
 
    public static void main(String []args){
        ShortestPathMatrix path = new ShortestPathMatrix();
        myQueuex = new LinkedList<>();
        myQueuey = new LinkedList<>();
        
        m = 10;
        n = 10;
        matrix = new Integer[m][n];
        visited = new Integer[m][n];
        path.initializeMatrix();
        
        System.out.println("Shortest path between S(0,0) to D(9)");
        path.addWalls(1, 3);
        path.addWalls(1, 4);
        path.addWalls(2, 3);
        path.addWalls(2, 4);
        path.addWalls(2, 0);
        path.addWalls(4, 2);
        path.addWalls(4, 5);
        path.addWalls(5, 0);
        path.addWalls(5, 5);
        matrix[3][3] = 9;     //Destination
        
        path.displayMatrix();
        path.findPath(0, 0);
        System.out.println("Traversed matrix");
        path.displayVisitedMatrix();
    }
}
