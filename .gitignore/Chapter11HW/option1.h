#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "MinHeap.h"
using namespace std;

int option1()
{
	

	
	MinHeap<int> mh;
	do
	{
		system("cls");
		cout << "\n\t\tA> Min Heap";
		cout << "\n\t\t" << string(50, char(205));
		cout << "\n\t\t  1. size";			//done
		cout << "\n\t\t  2. empty";			//done
		cout << "\n\t\t  3. push";			//done
		cout << "\n\t\t  4. top";			//done
		cout << "\n\t\t  5. pop";			//done
		cout << "\n\t\t  6. Display the vector";
		cout << "\n\t\t" << string(50, char(196));
		cout << "\n\t\t  0 return";		//done
		cout << "\n\t\t" << string(50, char(205)) << '\n';

		int option;
		cin >> option; // inlcude input.h

		switch (option)
		{
		case 0:  return 0;
		case 1:
			cout << "\n\t\t\t The size of the heap: " << mh.getSize() << '\n';
			break;
		case 2:
			cout << "\n\t\t\t The minheap is " << (mh.isEmpty() ? " empty." : " not empty.") << '\n';
			break;
		case 3:
			int e;
			do
			{
				cout << "Enter an element: ";
				cin >> e;
				if (!mh.find(e))
				{
					mh.push(e);
					cout << e << " has been inserted into the heap.\n";
					break;
				}
				else
					cout << "\n\t\t\tERROR: the element, " << e << ", already existed in the heap. Please re-enter.\n";
			} while (true);
			break;
		case 4:
			if (!mh.isEmpty())
				cout << "\n\t\t\tThe first element of the heap: " << mh.top() << '\n';
			else
				cout << "\n\t\t\tThe heap is empty.\n";
			break;
		case 5:
			if (!mh.isEmpty())
			{
				cout << "\n\t\t\tThe first element of the heap: " << mh.top() << '\n';
				mh.pop();
			}
			else
				cout << "\n\t\t\tThe heap is empty.\n";
			break;
		case 6:
			cout << "\n\t\t\t" << mh << '\n';
			break;
		}

		cout << '\n';
		system("pause");
	} while (true);

	return 0;
}
