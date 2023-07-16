#include <iostream>

#define N 10   
int solvemaze(int maze[N][N], int i, int j, int soln[N][N]); 
int is_Safe(int r, int c, int maze[N][N]); 
int main() 
{ 
    cout << 
"===========================================================\n "; 
    cout << "                     maze solver\n"; 
    cout << 
"===========================================================\n "; 
    int maze[N][N] = { 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 1 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 }, 
    }; 
    int soln[N][N] = { 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
                         { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }, 
    }; 
    if (solvemaze(maze,0,0,soln)) 
    { 
        for (int i = 0; i < N; i++) 
        { 
            for (int j = 0; j < N; j++) 
                cout << soln[i][j] << " "; 
            cout << endl; 
        } 
    } 
    else 
    { 
        cout << " not solve"; 
    } 
} 
int solvemaze(int maze[N][N],int i, int j, int soln[N][N]) 
{ 
    if (i == N - 1 && j == N - 1) 
    { 
        soln[i][j] = 1; 
        return 1; 
    } 
    if (is_Safe(i, j, maze)) 
    { 
        soln[i][j] = 1; 
        if (solvemaze(maze, i + 1, j, soln)) 
            return 1; 
        if (solvemaze(maze, i, j + 1, soln)) 
            return 1; 
        soln[i][j] = 0; 
    } 
    return 0; 
} 
int is_Safe(int r, int c, int maze[N][N]) 
{ 
    if (r < 0 || r >= N) 
        return 0; 
    if (c < 0 || c >= N) 
        return 0; 
    if (maze[r][c]) 
        return 1; 
    return 0; 
} 
 