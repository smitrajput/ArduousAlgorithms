// This C++ code gives longest path in a matrix of size (row*coloumn) containing numbers from 1 to row*coloumn... 

#include<bits/stdc++.h> 
using namespace std; 

#define row 3
#define coloumn 3

// Function to return length of the longest path beginning with mat[i][j]... 
int findLongestFromACell(int i, int j, int mat[row][coloumn], int dp[row][coloumn]) 
{ 
    // Base case 
    if (i<0 || i>=row || j<0 || j>=coloumn) 
        return 0; 
  
    // If this subproblem is already solved 
    if (dp[i][j] != -1) 
        return dp[i][j]; 
  
    // Since all numbers are unique and in range from 1 to n*n, 
    // there is atmost one possible direction from any cell
    if (j<coloumn-1 && ((mat[i][j] +1) == mat[i][j+1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j+1,mat,dp); 
  
    if (j>0 && (mat[i][j] +1 == mat[i][j-1]))
       return dp[i][j] = 1 + findLongestFromACell(i,j-1,mat,dp); 
  
    if (i>0 && (mat[i][j] +1 == mat[i-1][j])) 
       return dp[i][j] = 1 + findLongestFromACell(i-1,j,mat,dp); 
  
    if (i<row-1 && (mat[i][j] +1 == mat[i+1][j])) 
       return dp[i][j] = 1 + findLongestFromACell(i+1,j,mat,dp); 
  
    // If none of the adjacent fours is one greater 
    return dp[i][j] = 1; 
} 
  
// Returns length of the longest path beginning with any cell 
int finLongestOverAll( int matrix[row][coloumn] ) 
{
  int answer = 1;
  
  // Create a lookup table and fill all entries in it as -1 
  int dp[row][coloumn]; 
  memset(dp, -1, sizeof dp); 
  
  // Compute longest path beginning from all cells 
  for (int i=0; i<row; i++) 
  { 
    for (int j=0; j<coloumn; j++) 
    { 
      if (dp[i][j] == -1) 
        findLongestFromACell(i, j, matrix, dp); 
  
      //  Update result if needed 
      answer = max(answer, dp[i][j]); 
    } 
  } 
  return answer; 
} 
  
// Driver program...
int main() 
{
  int matrix[row][coloumn];
  for(int i=0;i<row;i++)
    for(int j=0;j<coloumn;j++)
      cin >> matrix[i][j];
  cout << "Length of the longest path is :"<< finLongestOverAll(matrix); 
  return 0; 
}
