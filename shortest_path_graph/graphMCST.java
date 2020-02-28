//All source all destination graph - shortest route

public class graphMCST{
    private Integer nodes, edges;
    private Integer start, end;
    private Integer matrix[][];
    private Integer costMatrix[][];
    private Boolean visited[];
    private Integer cost[];
    
    public void Initialize(){
        for (Integer i=0; i < nodes; i++){
            visited[i] = false;
            cost[i] = Integer.MAX_VALUE;
            for (Integer j=0; j < nodes; j++){
                matrix[i][j] = 0;
                costMatrix[i][j] = 0;
            }
        }
    }
    
    public void addEdge(Integer v1, Integer v2, Integer cost){
        matrix[v1][v2] = 1;
        costMatrix[v1][v2] = cost;
    }
    
    public Integer mcst(Integer node){
        visited[node] = true;
        if (node == end){
            cost[node] = 0;
            return 0;
        }
        
        for (Integer i = node; i< nodes; i++){
            if (matrix[node][i]==1){
                if (visited[i]==false)
                    mcst(i);
                if ((costMatrix[node][i] + cost[i]) < cost[node])
                {
                    cost[node] = costMatrix[node][i] + cost[i];
                }
            }
        }
        return 0;
    }
    
    public void displayMatrix(){
        for (Integer i=0; i < nodes; i++){
            for (Integer j=0; j < nodes; j++){
                System.out.print(costMatrix[i][j] + " ");
            }
            System.out.println();
        }
        for (Integer i:cost)
            System.out.println(i);
    }
    
    public static void main(String []args){
        graphMCST graph = new graphMCST();
        graph.nodes=13;
        graph.edges=21;
        
        graph.matrix = new Integer[graph.nodes][graph.nodes];
        graph.costMatrix = new Integer[graph.nodes][graph.nodes];
        graph.visited = new Boolean[graph.nodes];
        graph.cost = new Integer[graph.nodes];
        
        graph.Initialize();
        
        //12 graph nodes
        graph.addEdge(1,2,9);
        graph.addEdge(1,3,7);
        graph.addEdge(1,4,3);
        graph.addEdge(1,5,2);
        graph.addEdge(2,6,4);
        graph.addEdge(2,7,2);
        graph.addEdge(2,8,1);
        graph.addEdge(3,6,2);
        graph.addEdge(3,7,7);
        graph.addEdge(4,8,11);
        graph.addEdge(5,7,11);
        graph.addEdge(5,8,8);
        graph.addEdge(6,9,6);
        graph.addEdge(6,10,5);
        graph.addEdge(7,9,4);
        graph.addEdge(7,10,3);
        graph.addEdge(8,10,5);
        graph.addEdge(8,11,6);
        graph.addEdge(9,12,4);
        graph.addEdge(10,12,2);
        graph.addEdge(11,12,5);
        
        graph.start = 1;
        graph.end = 12;
        
    /*   
        //Small graph
        graph.addEdge(1,2,4);
        graph.addEdge(1,4,11);
        graph.addEdge(2,3,2);
        graph.addEdge(2,5,7);
        graph.addEdge(3,5,1);
        graph.addEdge(4,5,12);
        
        graph.start = 1;
        graph.end = 5;  */
        
        graph.mcst(graph.start);
        graph.displayMatrix();
    }
}
