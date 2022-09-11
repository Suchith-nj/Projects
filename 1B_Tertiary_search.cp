/* Tertiary search to find an element in the array */
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// To find an element in the array by splitting the array into 3 parts

int tertiarySearch(int i, int l, int ele, int arr[])
{

	if (l >= i) 
    {
    
		// To find l_mid and r_mid so that we split array imto 3 parts to search
		int l_mid = i + (l - i) / 3;
		int r_mid = l - (l - i) / 3;

		// Check if element ele is present at any mid
		if (arr[l_mid] == ele) {
			return l_mid;
		}
		else if (arr[r_mid] == ele) {
			return r_mid;
		}

		// to check element’s position and find at which region it is present
		if (ele < arr[l_mid]) {
			return tertiarySearch(i, l_mid - 1, ele, arr);    // element found in 1st part 
		}
		else if (ele > arr[r_mid]) {
			return tertiarySearch(r_mid + 1, l, ele, arr);    // element found in 3rd part
		}
		else {
		return tertiarySearch(l_mid + 1, r_mid - 1, ele, arr);   // element found in mid part
		}
    }
       
        // If element not found, return -1
        return -1;
    

	
}

int main()
{
	int i, l, x, ele;
	int arr[] = { 3, 7, 9, 10, 12, 15, 18, 21, 25, 31, 50, 75, 81, 100, 105};

	// Starting index
	i = 0;

	// length of the array
	l = sizeof(arr)/sizeof(arr[0]);

	cout << "Enter the element to search in the array" << endl;
	cin >> ele;

	// Search the ele using tertiarySearch
	x = tertiarySearch(i, l-1, ele, arr);

	if( x == -1 )
     {
	cout << "Oops, Element not found in the given array" << endl;
        }
	else 
	{cout << "Index of the element " << ele << " is "<< x << " in the given array "<< endl;}

    return 0;
}
