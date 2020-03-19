#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define M 6
#define N 6

//4 directions DOWN, RIGHT, LEFT, UP
int directions[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int rotten_queue[100][2], rot_rr=0, rot_ft=0;

int insert_rotten(int x, int y){
    rotten_queue[rot_rr][0] = x;
    rotten_queue[rot_rr][1] = y;
    rot_rr++;
}

int is_rotten_empty(){
    if (rot_rr == rot_ft)
        return 1;
    return 0;
}

int display_basket(int basket[M][N]){
    // Display basket    
    cout<<"\nBasket contents:\n";
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            cout<<basket[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int basket[M][N];
    int minutes_elapsed=0, fresh_oranges=0;
    int i, j;
    memset(basket, 0, (M*N*sizeof(int)));
    
    // Sample input - set 1
    // Rotten oranges - 2
    basket[1][2] = 2;
    basket[1][3] = 2;
    basket[4][5] = 2;

    // Fresh oranges - 1
    basket[0][3] = 1;
    basket[0][4] = 1;
    basket[0][5] = 1;
    basket[1][5] = 1;
    basket[2][4] = 1;
    basket[2][5] = 1;
    basket[3][5] = 1;
    basket[4][4] = 1;

    display_basket(basket);
    for (i=0; i<M; i++){
        for (j=0; j<N; j++){
            if (basket[i][j] == 2){
                insert_rotten(i, j);
            }
            else
            if (basket[i][j] == 1)
                fresh_oranges++;
        }
    }
    
    while(!is_rotten_empty()){
        int curr_rotten_count = rot_rr - rot_ft;

        while(curr_rotten_count--){
            int x = rotten_queue[rot_ft][0];
            int y = rotten_queue[rot_ft][1];
            rot_ft++;

            for (i=0; i<4; i++){
                int boxX = x + directions[i][0];
                int boxY = y + directions[i][1];
                if ((boxX >= 0) && (boxX < M) && (boxY >= 0) && (boxY  < N)){
                    if (basket[boxX][boxY] == 1){
                        insert_rotten(boxX, boxY);
                        basket[boxX][boxY] = 2;
                        fresh_oranges--;
//                        cout<<boxX<<" "<<boxY<<"\n";
                    }
                }
            }
        }
        if (!is_rotten_empty())
            minutes_elapsed++;
    }
    if (fresh_oranges)
        cout<<fresh_oranges<<" fresh oranges present after "<< minutes_elapsed <<" minutes of process.";
    else
        cout<<"Minutes elapsed: "<<minutes_elapsed;
    return 0;
}


/*
    // Sample input - set 1
    // Rotten oranges - 2
    basket[1][2] = 2;
    basket[1][3] = 2;
    basket[4][5] = 2;

    // Fresh oranges - 1
    basket[0][3] = 1;
    basket[0][4] = 1;
    basket[0][5] = 1;
    basket[1][5] = 1;
    basket[2][4] = 1;
    basket[2][5] = 1;
    basket[3][5] = 1;
    basket[4][4] = 1;
 */
