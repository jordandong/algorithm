/*
The Pipeline
You have to lay a pipeline through the great city X. The city is represented by a grid of N x N cells. Columns are numbered 1 to N from left to right. Rows are numbered 1 to N from top to bottom. In order to lay the pipeline you have to dig in the cells that the pipeline goes through. There is a cost involved with digging up each cell. Your task is to minimize the total cost for digging up cells.

Furthermore pipeline should be laid from left column (column 1) to right column (column N) of the city satisfying the following conditions:

     Since the city is located in the middle of a dessert it doesn't matter from which row the pipeline starts and ends. i.e. The pipeline should start from any cell of column 1 and should end at any cell of column N.
     When pipeline enters into the column i (1 <= i < N), the pipeline can be laid to column i+1 using one of following ways: (lets say pipeline enters the column i at row j)
        Lay the pipeline upward any number of cells (say d) within the city boundary and move to column i+1 at row j-d. i.e. d+1 cells in column i will be digged up
        Lay the pipeline downward any number of cells (say d) within the city boundary and move to column i+1 at row j+d. i.e. d+1 cells in column 1 will be digged up
        Lay pipeline to column i+1 through current cell. i.e. Only 1 cell will be digged up in column i
Task

Given digging up costs for each cell in the city, find the minimum cost for laying the pipeline from column 1 to column N.

1 <= N <= 1000 
0 <= cost of digging up the cell at column i and row j, c(i,j)<= 1,000,000

Input

First line of the input will contain an integer N, the number of rows and column in city. 
Next N lines will represent row 1 to row N respectively. 
Each row will have N integers separated by spaces representing costs of column 1 to column N respectively of the corresponding rows.

Output

Output should contain only one integer, minimum cost for digging up the cells that pipeline goes through. 
Note: There is a newline character at the end of the last line of the output. If you are using C++, use scanf() instead of std::cin as it can be slower reading input

Sample Input

5 
1 1 9 1 1 
3 1 9 7 1 
4 1 9 1 1 
5 1 1 1 5 
6 1 9 3 1

Sample Output

9

Sample Explanation

Pipeline starts from (1,1). 
So pipeline enter the column 1 at (1,1). Moves to column right. 
So pipeline enters the column 2 at (2,1). Moves 4 cells downward and move to column right. 
So pipeline enters the column 3 at (3,4). Moves to column right. 
So pipeline enters the column 4 at (4,4). Move 1 cell upward and move to column right. 
So pipeline enter the column 5 at (5,3) 
Total cost of the path = 1 + (1 + 1 + 1 + 1) + 1 + (1 + 1) + 1 = 9

Note: Other paths would produce larger answers. For example, if you consider taking the first row across, then the answer would be 1+1+9+1+1=13, which is larger than the shortest path identified.

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int miniPath(vector<vector<int> > &data){
	int size = data.size();
	int dp[size][size];
	int res = 0;
	for(int k =0; k<size;k++)
		dp[k][0] = data[k][0];
	
	for(int j = 1; j<size; j++){
		for(int i = 0; i<size; i++){
			dp[i][j] = INT_MAX;
			for(int k=0; k<size; k++){
			        int temp_sum = 0;
				for(int l = min(i,k); l<=max(i,k); l++){
					temp_sum+=data[l][j-1];
				}
				dp[i][j] = min(dp[i][j], dp[k][j-1] + temp_sum + data[i][j] - data[k][j-1]);
			}
		}
	}	
	res = dp[0][size-1];
	for(int m =0; m<size; m++)	
		res = min(res, dp[m][size-1]);
	return res;
}


int main(){

	vector<int> r(5,0);
	vector<vector<int> >data(5, r);
	
	data[0][0] = 131;
	data[0][1] = 673;
	data[0][2] = 234;
	data[0][3] = 103;
	data[0][4] = 18;
	data[1][0] = 201;
	data[1][1] = 96;
	data[1][2] = 342;
	data[1][3] = 965;
	data[1][4] = 150;
	data[2][0] = 630;
	data[2][1] = 803;
	data[2][2] = 746;
	data[2][3] = 422;
	data[2][4] = 111;
	data[3][0] = 537;
	data[3][1] = 699;
	data[3][2] = 497;
	data[3][3] = 121;
	data[3][4] = 956;
	data[4][0] = 805;
	data[4][1] = 732;
	data[4][2] = 524;
	data[4][3] = 37;
	data[4][4] = 331;
	//output = 994

/*	
	data[0][0] = 1;
	data[0][1] = 1;
	data[0][2] = 9;
	data[0][3] = 1;
	data[0][4] = 1;
	data[1][0] = 3;
	data[1][1] = 1;
	data[1][2] = 9;
	data[1][3] = 7;
	data[1][4] = 1;
	data[2][0] = 4;
	data[2][1] = 1;
	data[2][2] = 9;
	data[2][3] = 1;
	data[2][4] = 1;
	data[3][0] = 5;
	data[3][1] = 1;
	data[3][2] = 1;
	data[3][3] = 1;
	data[3][4] = 5;
	data[4][0] = 6;
	data[4][1] = 1;
	data[4][2] = 9;
	data[4][3] = 3;
	data[4][4] = 1;
	//output = 9
*/
	cout<<"Mini Cost : "<<miniPath(data)<<endl;; 

	return 0;
}
