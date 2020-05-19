// Number of islands
#include <bits/stdc++.h>

int directions[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};
int queue[100][2];
int rear = 0, front = 0;

int queueInsert(int x, int y){
	queue[rear][0] = x;
	queue[rear][1] = y;
	rear++;	
}

int isempty(){
	if (rear == front)
		return 1;
	return 0;
}
int main(){
	int no_of_islands =0;
	int i, j;
	int matrix[5][5] = {
		{1,1,0,0,0},
		{1,1,0,1,1},
		{0,0,0,1,1},
		{0,1,1,0,0},
		{0,1,1,0,0}};
	
	int rows = sizeof(matrix)/sizeof(matrix[0]);
	int columns = sizeof(matrix[0])/sizeof(int);

	for (i=0; i<rows; i++){
		for (j=0; j<columns; j++){
			if (matrix[i][j] == 1){

				//BFS
				matrix[i][j] = 2;
				queueInsert(i, j);
				while (!isempty()){
					int x = queue[front][0];
					int y = queue[front++][1];
					
					for (int k=0; k<4; k++){
						int newX = x + directions[k][0];
						int newY = y + directions[k][1];
						
						if ((newX < rows && newX >= 0) && (newY < columns && newY >=0)){
							if (matrix[newX][newY] == 1){
								matrix[newX][newY] = 2;
								queueInsert(newX, newY);
							}
						}
					}
				}
				no_of_islands++;
			}
		}
	}
	std::cout<<no_of_islands<<"\n";
	for (i=0; i<rows; i++){
		for (j=0; j<columns; j++){
		    std::cout<<matrix[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}