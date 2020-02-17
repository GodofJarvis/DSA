import java.util.*;
public class GraphTraversal{
    public static Queue<Integer> myQueue;
    public static Integer[][] matrix;
    public static Boolean[] visited;
    public static Integer n,e;
 
    public void initializeMatrix(){
        for (int i=1; i <= n; i++){
            visited [i] = false;
            for (int j=i; j <= n; j++){
                matrix [i][j] = 0;
                matrix [j][i] = 0;
            }
        }
    }
 
    public void addEdge(Integer a, Integer b){
        matrix[a][b] = 1;
    }
    
    public void displayMatrix(){
        for (int i=1; i <= n; i++){
            for (int j=1; j <= n; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public void depthFirstSearch(Integer node){
        System.out.print(node + " ");
        visited[node] = true;
        
        for (int i=1; i <= n ;i++){
            if (matrix[node][i]==1 && visited[i]==false){
                depthFirstSearch(i);
            }
        }
    }
    
    public void breadthFirstSearch(Integer node){
        System.out.print(node + " ");
        visited[node] = true;
        
        for (int i=1; i <= n; i++){
            if (matrix[node][i]==1 && visited[i]==false){
                myQueue.add(i);
            }
        }
        if(!myQueue.isEmpty()){
            breadthFirstSearch(myQueue.remove());
        }
    }
 
    public static void main(String []args){
        GraphTraversal graph = new GraphTraversal();
        myQueue = new LinkedList<>();
        
        n = 9;
        e = 8;
        matrix = new Integer[n+1][n+1];
        visited = new Boolean[n+1];
        graph.initializeMatrix();
 
        System.out.println("Graph Traversal");
        System.out.println("Number of nodes: " + n);
        System.out.println("Number of edges: " + e);
        graph.addEdge(1,2);
        graph.addEdge(1,3);
        graph.addEdge(2,5);
        graph.addEdge(3,4);
        graph.addEdge(3,7);
        graph.addEdge(5,6);
        graph.addEdge(4,8);
        graph.addEdge(7,9);
 
        graph.displayMatrix();
        System.out.print("DFS: ");
        graph.depthFirstSearch(1);
        
        for (int i=1; i <= n; i++){
            visited [i] = false;
        }
        System.out.println();
        System.out.print("BFS: ");
        graph.breadthFirstSearch(1);
    }
     
/*  //The below lines gets input from command line for  graph representation.
    public void getInputs(){
        Scanner myScanner = new Scanner(System.in);
        System.out.println("Graph Traversal : DFS");
        System.out.println("Number of nodes: ");
        n = myScanner.nextInt();
        matrix = new Integer[n][n];
        System.out.println("Number of edges: ");
        e = myScanner.nextInt();
        System.out.println("Enter edges: ");
        for (int i=0;i<e;i++){
            String str = myScanner.nextLine();
            String[] edge = str.split(" ");
//            Integer x = Integer.parseInt(edge[0]); 
//            Integer y = Integer.parseInt(edge[1]);
            System.out.println(edge[0] + edge.length());
        }
    }
*/
}
