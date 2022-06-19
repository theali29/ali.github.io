#include <iostream>
#include <fstream>
using namespace std;
void writedata(char*** store, int shelves, int positions)
{
	ofstream fout("Store.txt");
	fout << shelves << endl;
	fout << noofpositions << endl;
	fout(int i = 0; i < shelves; i++)
	{
		for (int y = 0; y < positions; y++)
		{
			if (store[i][y][0] != '\0')
				fout << store[i][y];
			else
			{

				fout << "Empty";
			}

			fout << endl;
		}

	}
	fout.close();
}
bool LoadData(char***& store, int& shelves, int& positions)
{

	fstream fin("Store.txt");
	bool status = false;

	if (fin)
	{
		status = true;
		fin >> shelves;
		fin >> positions;
		store = new char** [shelves];
		for (int i = 0; i < shelves; i++)
			store[i] = new char* [positions];

		for (int i = 0; i < shelves; i++)
			for (int y = 0; y < positions; y++)
			{
				store[i][y] = new char[100];
				store[i][y][0] = '\0';
			}

		for (int i = 0; i < shelves; i++)
		{
			for (int y = 0; y < positions; y++)
			{
				char* item = new char[100];
				fin >> item;
				if (strcmp("Empty", item) == 0)
					store[i][y][0] = '\0';
				else
					store[i][y] = item;

			}

		}
	}


	fin.close();
	return status;
}
void AddingItem(char*** store, int shelves, int positions)
{
	int shelf;
	int position;
	char* item = new char[100];
	bool added = false;
	cout << "\nEnter Shelf: ";
	cin >> shelf;
	if (shelf > shelves)
	{
		cout << "Error! Shelf not found";
		return;
	}
	cout << "\nEnter Position: ";
	cin >> position;
	if (position > positions)
	{
		cout << "Error! Position not found";
		return;
	}
	cout << "\nEnter Item: ";
	cin.getline(item, 100);
	if (store[shelf - 1][position - 1][0] == '\0')
	{
		store[shelf - 1][position - 1] = item;
		cout << "Added successfully!";
		added = true;
	}

	else
	{
		for (int i = 0; i < positions; i++)
		{
			if (store[shelf - 1][i][0] == '\0')
			{
				store[shelf - 1][i] = item;
			}
		}
	}


}

void RemovingItem(char*** store, int shelves, int positions)
{
	int shelf;
	int position;
	cout << "\nEnter shelf no to remove item: " << endl;
	cin >> shelf;
	if (shelf > shelves)
	{
		cout << "Error! Shelf not found";
		return;
	}
	cout << "\nEnter position: ";
	cin >> position;
	if (position > positions)
	{
		cout << "Error! Position not found";
		return;
	}
	if (store[shelf - 1][position - 1][0] != '0')
	{
		cout << "Item removed!";
		store[shelf - 1][position - 1][0] = '\0';
	}

	else
		cout << "Item not removed!";
}
void DisplayingAllItems(char*** store, int shelves, int positions)
{
	for (int i = 0; i < shelves; i++)
	{
		cout << "\n\nShelve ";
		cout << i + 1;
		cout << endl;
		cout << endl;
		for (int y = 0; y < positions; y++)
		{
			if (store[i][y][0] != '\0')
			{
				cout << store[i][y];
				cout << " ";
			}

			else
				cout << "Empty ";
		}
	}

}


void RemovingAllItems(char*** store, int shelves, int positions)
{
	for (int i = 0; i < shelves; i++)
	{
		for (int y = 0; y < positions; y++)
		{
			store[i][y][0] = '\0';
		}
	}
	cout << "All items removed from every shelf!";
}

int ReturningAllItems(char*** store, int shelves, int positions)
{
	int count = 0;
	for (int i = 0; i < shelves; i++)
	{
		for (int y = 0; y < positions; y++)
		{
			if (store[i][y][0] != '\0')
				count++;
		}
	}
	return count;

}

void FindingItems(char*** store, int shelves, int positions)
{
	char* item = new char[100];
	cout << "Enter item name to find ";
	cin.getline(item, 100);
	cout << endl;

	bool found = false;
	for (int i = 0; i < shelves; i++)
	{
		for (int y = 0; y < positions; y++)
		{
			if (strcmp(store[i][y], item) == 0)
			{
				found = true;
				cout << "Item found at:\t";
				cout << "Shell" << i + 1 << endl;
				cout << "\tPosition:" << y + 1cout << endl;;

			}
		}
	}

	if (!found) cout << "Item not Found\n";

}

void UpdatingItems(char*** store, int shelves, int positions)
{
	int shelf;
	int position;

	cout << "\nEnter Shelf no to update: ";
	cin >> shelf;
	if (shelf > shelves)
	{
		cout << "Error! Shelf not found";
		return;
	}

	cout << "\nEnter Position: ";
	cin >> position;
	if (position > positions)
	{
		cout << "Error! Position not found";
		return;
	}
	cout << "\nEnter Item to update with: ";


	cin.getline(store[shelf - 1][position - 1], 100); ;

	cout << "Shelf updated!";

}
void checkingshelffull(char*** store, int shelves, int positions)
{
	bool isfull = true;
	int shelf;
	cout << "Enter shelf no :";
	cin >> shelf;
	if (shelf > shelves)
	{
		cout << "Error! Shelf not found";
		return;
	}
	for (int i = 0; i < positions; i++)
	{
		if (store[shelf - 1][i][0] == '\0')
			isfull = false;
	}

	cout << "Shelf ";
	cout << " is not full.";

}

void checkingshelfempty(char*** store, int shelves, int positions)
{
	bool isempty = true;
	int shelf;
	cout << "Enter shelf no :";
	cin >> shelf;
	if (shelf > shelves)
	{
		cout << "Error! Shelf not found";
		return;
	}
	for (int i = 0; i < positions; i++)
	{
		if (store[shelf - 1][i][0] != '\0')
		{

			isempty = false;
		}
	}

	cout << "Shelf " << shelf;
	if (!isempty)
		cout << " Shelf is not empty.";
	else
		cout << "Shelf is empty.";

}
int main()
{
	int loadchoice;
	int noofshelves = 0;
	int positions = 0;
	char*** store;
	cout << "Do you want to load previous store data from file ? Enter 1 if you want else 2:  ";
	cin >> loadchoice;

	if (loadchoice == 1)
	{
		if (LoadData(store, noofshelves, positions))
		{
			cout << "\nNumber of Shelves Loaded: ";
			cout << noofshelves;
			cout << "\nNumber of Positions Loaded in each Shelf: ";
			cout << positions;
			cout << endl;
		}
		else
		{
			cout << "Previous Data not Found\n";
			cout << "Enter no of shelves: ";
			cin >> noofshelves;
			cout << "Enter no of positions on each shelf ";
			cin >> positions;

			store = new char** [noofshelves];
			for (int i = 0; i < noofshelves; i++)
				store[i] = new char* [positions];

			for (int i = 0; i < noofshelves; i++)
				for (int y = 0; y < positions; y++)
				{
					store[i][y] = new char[100];
					store[i][y][0] = '\0';
				}
		}

	}
	else
	{
		cout << "Enter no of shelves: ";
		cin >> noofshelves;
		cout << "Enter no of positions on each shelf ";
		cin >> positions;

		store = new char** [noofshelves];
		for (int i = 0; i < noofshelves; i++)
			store[i] = new char* [positions];

		for (int i = 0; i < noofshelves; i++)
			for (int y = 0; y < positions; y++)
			{
				store[i][y] = new char[100];
				store[i][y][0] = '\0';
			}
	}









	cout << "**********Menu***************" << endl;
	cout << "Press 1 for Inserting an item" << endl;
	cout << "Press 2 for Displaying all items." << endl;
	cout << "Press 3 for Remove an item." << endl;
	cout << "Press 4 for Remove all the items." << endl;
	cout << "Press 5 for Return total no of items." << endl;
	cout << "Press 6 for find an item." << endl;
	cout << "Press 7 for updating an item." << endl;
	cout << "Press 8 to check if shelf is empty." << endl;
	cout << "Press 9 to check if shelf is full." << endl;
	cout << "Press 0 to Quit" << endl;
	int choice;

	do
	{


		cout << "\n\nEnter Choice: ";
		cin >> choice;

		switch (choice)
		{

		case 0:
			break;
		case 1:
			AddingItem(store, noofshelves, positions);
			break;
		case 2:
			DisplayingAllItems(store, noofshelves, positions);
			break;

		case 3:
			RemovingItem(store, noofshelves, positions);
			break;
		case 4:
			RemovingAllItems(store, noofshelves, positions);
			break;
		case 5:
			cout << "\nTotal no of items : ";
			cout << ReturningAllItems(store, noofshelves, positions);
			break;
		case 6:
			FindingItems(store, noofshelves, positions);
			break;
		case 7:
			UpdatingItems(store, noofshelves, positions);
			break;
		case 8:
			checkingshelfempty(store, noofshelves, positions);
			break;
		case 9:
			checkingshelffull(store, noofshelves, positions);
			break;
		default:
			break;
		}
		writeData(store, noofshelves, positions);
	} while (choice != 0);
	cout << "\nThank You";
}