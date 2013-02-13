/*
 * The latest version of your favorite adventure game has been released.
 * On each level you search for stars that earn you points. 
 * Simply moving over a location containing stars allows you to acquire them.
 * To help you on your journey, you are given an overhead map of the level in a String[]. 
 * Each character in level describes the number of stars at that location.
 * You begin in the upper left spot of the map (character 0 of element 0 of level).
 * On the current stage you must move according to the following rules:
 * 	1) On the first pass you may only move downward or rightward each move (not diagonally) until you reach the lower right corner.
 * 	2) The second pass begins in the lower right corner where the first pass ended, and proceeds back to the beginning using only upward and leftward steps (not diagonal).
 * 	3) The final pass, like the first pass, begins in the upper left corner and proceeds to the lower right corner using only rightward and downward (not diagonal) steps.
 * Once the stars on a spot are claimed, they cannot be claimed again on a future pass. Return the largest possible number of stars that can be acquired.
 *
 * Definition
 *	Class:	StarAdventure
 *	Method:	mostStars
 *	Parameters:	String[]
 *	Returns:	int
 *	Method signature:	int mostStars(String[] level) (be sure your method is public)
 * 
 * Constraints
 * 	level will contain between 2 and 50 elements inclusive.
 * 	Each element of level will contain between 2 and 50 characters inclusive.
 * 	Each element of level will contain the same number of characters.
 * 	Each character in each element of level will be a digit ('0' - '9').
 * 	Character 0 in element 0 of level will be '0'.
 * 
 * Examples
 * 0)	
 * 	{"01",
 * 	 "11"}
 * 	Returns: 3
 * 1)	    	     	
 * 	{"0999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"
 * 	,"9999999999"}
 * 	Returns: 450
 * 2)	
 * 	{"012"
 * 	,"012"
 * 	,"012"
 * 	,"012"
 * 	,"012"
 * 	,"012"
 * 	,"012"}
 * 	Returns: 21
 * 3)		    	     	    	    	
 * 	{"0123456789",
 * 	 "1123456789",
 * 	 "2223456789",
 * 	 "3333456789",
 * 	 "4444456789",
 *	 "5555556789",
 * 	 "6666666789",
 * 	 "7777777789",
 * 	 "8888888889",
 * 	 "9999999999"}
 *  Returns: 335
 */
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

class StarAdventure{
	public:
		int mostStars(string* L, int n){
			int X=L[0].length();
			int Y=n;
			int XY=X+Y;

			vector<vector<vector<int> > > best = vector<vector<vector<int> > >(X, vector<vector<int> >(X, vector<int>(X,0)));
			// best score with paths at the given X positions
			vector<vector<vector<int> > > b2 = vector<vector<vector<int> > >(X, vector<vector<int> >(X, vector<int>(X,0)));
			for (int A=0; A<X; A++)
				for (int B=0; B<X; B++)
					for (int C=0; C<X; C++)
						best[A][B][C] = INT_MIN;
			best[0][0][0] = 0;
			//we treat three paths together, they have the same length using DP in each step with different X and Y.
			for (int t=1; t<=X+Y-2; t++){//t is the length of current path
				for (int A=0; A<X; A++){
					for (int B=0; B<X; B++){
						for (int C=0; C<X; C++){
							int aa = t-A, bb=t-B, cc=t-C;
							//aa is the y of the first path, now at(A,aa)
							//bb is the y of the first path, now at(B,bb)
							//cc is the y of the first path, now at(C,cc)
							if(aa<0 || bb<0 || cc<0 || aa>=Y || bb>=Y || cc>=Y)
								continue;//make sure range is valid
							//record current best sum 
							int bestHere = 0;
							int delta = L[aa][A]-'0';
							if (B != A)
								delta += L[bb][B]-'0';
							if (C != A && C != B)
								delta += L[cc][C]-'0';
							//8 previous situations around one point(x1,x2,x3) can reach this point, since each (x,y) can be reached from up or left
							if(A>0 && B>0 && C>0)//left left left
								bestHere = max(bestHere, best[A-1][B-1][C-1] + delta);
							if(A>0 && B>0 && cc>0)//left left up
								bestHere = max(bestHere, best[A-1][B-1][C] + delta);
							if(A>0 && bb>0 &&  C>0)//left up left
								bestHere = max(bestHere, best[A-1][B][C-1] + delta);
							if(A>0 && bb>0 && cc>0)//left up up
								bestHere = max(bestHere, best[A-1][B][C] + delta);
							if(aa>0 &&  B>0 &&  C>0)//up left left
								bestHere = max(bestHere, best[A][B-1][C-1] + delta);
							if(aa>0 &&  B>0 && cc>0)//up left up
								bestHere = max(bestHere, best[A][B-1][C] + delta);
							if(aa>0 && bb>0 &&  C>0)//up up left
								bestHere = max(bestHere, best[A][B][C-1] + delta);
							if (aa>0 && bb>0 && cc>0)//up up up
								bestHere = max(bestHere, best[A][B][C] + delta);
							b2[A][B][C] = bestHere;
						}
					}
				}
				swap(best, b2);
			}
			return best[X-1][X-1][X-1];
		}

		int mostStarsII(string* L, int n){
			int X=L[0].length();
			int Y=n;
			int XY=X+Y;

			vector<vector<vector<int> > > best = vector<vector<vector<int> > >(X, vector<vector<int> >(X, vector<int>(X,0)));
			// best score with paths at the given X positions
			vector<vector<vector<int> > > b2 = vector<vector<vector<int> > >(X, vector<vector<int> >(X, vector<int>(X,0)));
			for (int A=0; A<X; A++)
				for (int B=0; B<X; B++)
					for (int C=0; C<X; C++)
						best[A][B][C] = INT_MIN;
			best[0][0][0] = 0;
			//we treat three paths together, they have the same length using DP in each step with different X and Y.
			for (int t=1; t<=X+Y-2; t++){//t is the length of current path
				for (int A=0; A<X; A++){
					for (int B=A; B<X; B++){
						for (int C=B; C<X; C++){
							int aa = t-A, bb=t-B, cc=t-C;
							//aa is the y of the first path, now at(A,aa)
							//bb is the y of the first path, now at(B,bb)
							//cc is the y of the first path, now at(C,cc)
							if(aa<0 || bb<0 || cc<0 || aa>=Y || bb>=Y || cc>=Y)
								continue;//make sure range is valid
							//record current best sum 
							int bestHere = 0;
							int delta = L[aa][A]-'0';
							if (B != A)
								delta += L[bb][B]-'0';
							if (C != A && C != B)
								delta += L[cc][C]-'0';
							//8 previous situations around one point(x1,x2,x3) can reach this point, since each (x,y) can be reached from up or left
							if(A>0 && B>0 && C>0)//left left left
								bestHere = max(bestHere, best[A-1][B-1][C-1] + delta);
							if(A>0 && B>0 && cc>0)//left left up
								bestHere = max(bestHere, best[A-1][B-1][C] + delta);
							if(A>0 && bb>0 &&  C>0)//left up left
								bestHere = max(bestHere, best[A-1][B][C-1] + delta);
							if(A>0 && bb>0 && cc>0)//left up up
								bestHere = max(bestHere, best[A-1][B][C] + delta);
							if(aa>0 &&  B>0 &&  C>0)//up left left
								bestHere = max(bestHere, best[A][B-1][C-1] + delta);
							if(aa>0 &&  B>0 && cc>0)//up left up
								bestHere = max(bestHere, best[A][B-1][C] + delta);
							if(aa>0 && bb>0 &&  C>0)//up up left
								bestHere = max(bestHere, best[A][B][C-1] + delta);
							if (aa>0 && bb>0 && cc>0)//up up up
								bestHere = max(bestHere, best[A][B][C] + delta);
							b2[A][B][C] = bestHere;
						}
					}
				}
				best=b2;
			}
			return best[X-1][X-1][X-1];
		}

};



int main(){
	StarAdventure sa;
	//303
	string a[10]={"0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789", "0123456789"};
	//195
	string b[8]={"0333111111", "1300000000", "1330999990", "1030999990", "1030999990", "1010999990", "1011000000", "1111111111"};
	//239
	string c[10]={"0108135222", "2905827284", "5020668507", "3014679657", "0118090573", "8403531056", "6591900825", "5604532844", "8902156030", "1514262291"};
	cout<<sa.mostStars(a,10)<<", "<<sa.mostStarsII(a,10)<<endl;
	cout<<sa.mostStars(b,8)<<", "<<sa.mostStarsII(b,8)<<endl;
	cout<<sa.mostStars(c,10)<<", "<<sa.mostStarsII(c,10)<<endl;
	return 0;
}
