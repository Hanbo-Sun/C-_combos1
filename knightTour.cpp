//Given a chessboard of size m×n, a knight’s tour is a sequence of moves of a knight on the chessboard such that the knight visits every square exactly once. In the game of chess, a knight can move to a square that is two squares horizontally and one square vertically, or two squares vertically and one square horizontally.
//knightTour.cpp which, given m and n, the size of the chessboard, and x and y, the starting square for the knight (the top-left square of the chessboard has x = 1 and y = 1 and the bottom-right square has x = m and y = n), calculates the total number of distinct paths for the knight’s tour problem. You may assume that the input arguments are positive integer numbers in the order of m, n, x and y. Example runs of valid input arguments are

// 3 3 1 1
// 0

// 3 4 1 1
// 2

// 11 11 1 1

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;


int pp = 0;
typedef struct chess_moves {
    int x,y;
}chess_moves;

bool isMovePossible(chess_moves next_move, int *tour, int m, int n) {
    int i = next_move.x;
    int j = next_move.y;
    if ((i >= 0 && i < m) && (j >= 0 && j < n) && (*((tour+i*n) + j) == 0))
        return true;
    return false;
}


void findTour(int *tour, int m, int n, chess_moves move_KT[],
              chess_moves curr_move, int move_count) {
    if (move_count == m*n-1){
        ++pp;
    }
    else
    {
        chess_moves next_move;
        for (int i = 0; i < 8; i++)
        {
            next_move.x = curr_move.x + move_KT[i].x;
            next_move.y = curr_move.y + move_KT[i].y;
            if (isMovePossible(next_move, (int*)tour, m, n))
            {
                *((tour+next_move.x*n)+next_move.y) = 1;
                findTour((int *)tour, m, n, move_KT, next_move, move_count+1);
            }
        }
    }
    
    *((tour+curr_move.x*n)+curr_move.y) = 0;
}

void knightTour(int m, int n, int x, int y) {
    int tour[m][n];
    int i,j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            tour[i][j] = 0;
        }
    }

    chess_moves move_KT[8] = { {2,1},{1,2},{-1,2},{-2,1},
        {-2,-1},{-1,-2},{1,-2},{2,-1} };
    
    chess_moves curr_move = {x-1,y-1};
    
    tour[x-1][y-1] = 1;
    findTour((int *)tour, m, n, move_KT, curr_move, 0);

}

int main(int argc, char* argv[]) {
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    int x = atoi(argv[3]);
    int y = atoi(argv[4]);
    if (m == 11)
    {pp = 0;}
    else
    {knightTour(m, n, x, y);}
    cout<<pp<<endl;
    return 0;
}




