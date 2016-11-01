// Author - Randy Lee
// This array searches a partially filled array of nonnegative integers.

#include "stdafx.h"

const int DECLARED_SIZE = 20;

void fill_array(int a[], int size, int& number_used);
//Precondition: size is the declared size of the array a.
//Postcondition: number_used is the number of values stored in a.
//a[0] through a[number_used − 1] have been filled with
//nonnegative integers read from the keyboard.

int search(const int a[], int number_used, int target);
//Precondition: number_used is <= the declared size of a.
//Also, a[0] through a[number_used − 1] have values.
//Returns the first index such that a[index] == target,
//provided there is such an index; otherwise, returns −1.

int main()
{
	using namespace std;
	int arr[DECLARED_SIZE], list_size, target;
	fill_array(arr, DECLARED_SIZE, list_size);
	char ans;
	int result;

	do
	{
		cout << "Enter a number to search for: ";
		cin >> target;
		result = search(arr, list_size, target);

		if (result == -1)
			cout << target << " is not on the list.\n";
		else
			cout << target << " is stored in array position "
			<< result << endl
			<< "(Remember: The first position is 0.)\n";
		cout << "Search again?(y/n followed by Return): ";
		cin >> ans;
	} while ((ans != 'n') && (ans != 'N'));

	cout << "End of program.\n";
	return 0;
}

//Uses iostream:
void fill_array(int a[], int size, int& number_used)
{
	using namespace std;

	cout << "Enter up to " << size << " nonnegative whole numbers.\n"
		<< "Mark the end of the list with a negative number.\n";
	int next, index = 0;
	cin >> next;
	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}
	number_used = index;
}

int search(const int a[], int number_used, int target)
{
	int index = 0;
	bool found = false;

	while ((!found) && (index < number_used))
		if (target == a[index])
			found = true;
		else
			index++;
	if (found)
		return index;
	else
		return -1;
}