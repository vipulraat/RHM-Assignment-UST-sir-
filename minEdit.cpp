// A Dynamic Programming based C++ program to find minimum
// Edit Operations to convert str1 to str2
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Function to find the minimum of three numbers
int min(int n1, int n2, int n3)
{
	return min(min(n1, n2), n3);
}

int editDist(string str1, string str2, int m, int n)
{
	// Create a table to store results of subproblems
	int dT[m+1][n+1];

	// Fill d[][] in bottom up manner
	for (int i=0; i<=m; i++)
	{
		for (int j=0; j<=n; j++)
		{
			// If first string is empty, only option is to
			// isnert all characters of second string
			if (i==0)
				dT[i][j] = j; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j==0)
				dT[i][j] = i; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i-1] == str2[j-1])
				dT[i][j] = dT[i-1][j-1];

			// If the last character is different, consider all
			// possibilities and find the minimum
			else
				dT[i][j] = 1 + min(dT[i][j-1], // Insert
								dT[i-1][j], // Remove
								dT[i-1][j-1]); // Replace
		}
	}

	return dT[m][n];
}

// Main function
int main()
{
	string strX;
	string strY;

	cout<< "Enter two string to find min edit distance between them "<<endl;

	cin>>strX;
	cin>>strY;

	int dist = editDist(strX, strY, strX.length(), strY.length());
	cout<< "Minimum Edit distance = " <<dist;

	return 0;
}
