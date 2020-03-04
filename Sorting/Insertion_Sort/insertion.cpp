// This program will need to take in a user inputed number, create a vector of
// random numbers based on the ammount the user inputed. Then sort tthe vector
// based off of 1 of 3 types of sorting then print the vector to a text file.
// To do this I will first create a print function to print out each vector.
// I will initially take in the users inputed number and place it a vector.
// Using srand and basing it on the system time I will fill the vector with
// random numbers. Finally I will print the numbers to the file.

#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int i, n, j, elem;

/* Simple print function which uses a for loop in order to iterate through
  a vector and print out each number to a file. */
void print(vector<int> &v)
{
	ofstream outputFile("File.txt");
	for (int i = 0; i < v.size(); i++)
		outputFile << v[i] << endl;

}

/* Sorting function which looks at each number in a vector and inserts or
 places it where it is supposed to be based on previous numbers and shifts
 the sorted numbers up */
void insertion_sort(vector<int> &v)
{
	for (i = 1; i < n; i++)
		for (elem = v[i], j = i-1; j >=0 and elem < v[j]; j--)
		    v[j+1] = v[j];
		v[j+1] = elem;
}

main()
{

int n;


cout << "enter vector size: ";
cin >> n;

vector <int> v(n);


/* Simple for loop that randomly generates numbers based on time starting from 0.
 until the ammount of numbers is what the user inputed*/
srand(time(0));
for(int i = 0; i < n; i++)
	v[i] = rand()% 1000000;

insertion_sort(v);
print(v);


}
