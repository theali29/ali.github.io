#include<iostream>
#include<fstream>
using namespace std;
class admin
{
	char* email;
	char* password;

public:
	int size = 0;
	admin()
	{
		email = new char[size];
		password = new char[size];
	}
	admin(const char* e, const char* p)
	{
		size = strlen(e);
		email = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			email[i] = e[i];
		}
		email[size] = '\0';
		size = strlen(p);



		password = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			password[i] = p[i];
		}
		password[size] = '\0';

	}
	void setemail(const char* e)
	{
		size = strlen(e);
		email = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			email[i] = e[i];
		}
		email[size] = '\0';

	}
	char getemail()
	{
		return *email;
	}
	

	void setpassword(const char* p)
	{
		size = strlen(p);
		password = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			password[i] = p[i];
		}
		password[size] = '\0';

	}

	char getpassword()
	{
		return *email;
	}
	int checkemail()
	{
		const int cesize = 3;
		const char* ce = new char[cesize];
		ce = "ali";
		bool flag;
		if (size == cesize)
		{
			flag = 1;
			for (int i = 0; i < size; i++)
			{
				if (ce[i] != email[i])
				{
					flag = 0;
				}
			}
		}
		else
		{
			flag = 0;
		}
		return flag;
	}
	int checkpassword()
	{
		const int cpsize = 6;
		const char* cp = new char[cpsize];
		cp = "ali123";
		bool flag;
		if (size == cpsize)
		{
			flag = 1;


			for (int i = 0; i < size; i++)
			{
				if (cp[i] != password[i])
				{
					flag = 0;
				}
			}
		}
		else
		{
			flag = 0;
		}
		return flag;
	}
};

class item
{
	int itemno;
	char* iname;
	int quantity;
	int price;
	int totalprice;
	int totalitems;
	
public:
	int size = 0;
	item()
	{
		itemno = 0;
		iname = new char[size];
		quantity = 0;
		price = 0;
		totalprice = 0;
		totalitems = 0;
	}
	item(const char* n, int ino, int q, int p,int ti)
	{
		size = strlen(n);
		iname = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			iname[i] = n[i];
		}
		iname[size] = '\0';
		itemno = ino;
		totalitems = ti;
		quantity = q;
		price = p;
		totalprice = price * quantity;
	}
	void setitem(const char*it)
	{
		size = strlen(it);
		iname = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			iname[i] = it[i];
		}
		iname[size] = '\0';

	}

	char getitem()
	{
		return *iname;
	}
	
	void setquantity(int q)
	{
		quantity = q;
	}
	int getquantity()
	{
		return quantity;
	}
	void setprice(int p)
	{
		price = p;
	}
	int getprice()
	{
		return price;
	}
	/*void settotalitem(int i)
	{
		totalitems = i;
	}
	int gettoalitem()
	{
		return totalitems;
	}*/
	void settotalprice()
	{
		totalprice = price * quantity;
	}
	int gettotalprice()
	{
		return totalprice;
	}
	
	void readdata()
	{
		char* str = new char[30];
		ifstream fin;
		fin.open("items.txt");
		while (!fin.eof())
		{
			fin.getline(str, 30);
			cout << str << endl;
			setitem(str);
		
		}
	}
	int checkitem(const char *ht)
	{ 
		size = strlen(ht);
		ifstream fin;
		char* ptr = new char[30];
		fin.open("items.txt", ios::in);
		int psize;
		bool flag = 0;
		while (!fin.eof())
		{
			
			fin.getline(ptr, 30);
			psize = strlen(ptr);
			if (size == psize)
			{
				flag = 1;
				for (int i = 0; i < size; i++)
				{
					if (ht[i] != ptr[i])
					{
						flag = 0;
					}
				}
			}
			else
			{
				flag = 0;
			}
			if (flag == 1)
			{
				break;
			}

		}
		fin.close();
		return flag;
	}
	void deleteit(const char *dt)
	{
		size = strlen(dt);
		iname = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			iname[i] = '\0';
		}
		quantity = 0;
		price = 0;
		totalprice = 0;
	}
	void output()
	{
		
		
		ofstream outfile("store.txt", ios::app);
		
	
			outfile << "Name: " << iname << " Qty: " << quantity << " Price: " << totalprice << endl;
			cout << iname << "\t\t" << quantity << "\t\t" << price << "\t\t" << totalprice << '\n';
		

		
		
	}
	void display()
	{

		cout  << iname << endl;
		/*"\t\t\t\t" << quantity << "\t\t" << price << "\t\t" << totalprice;
*/
	}
	
	
	/*void operator=(item& i)
	{
		i.size = strlen(i.iname);
		size = i.size;
		for (int i = 0; i < size; i++)
		{
			iname[i] = i;
		}
		iname[size] = '\0';
	}*/
	/*~item()
	{
		delete[]iname;
		iname = NULL;
	}*/

};
class sum :public item
{
	int amount;
	int tax;
	

public:
	sum(int a, int t)
	{
		amount = a;
		tax = t;
	}
	void output()
	{

	}
};

int main()
{
	ifstream fin;
	ofstream fout;
	char* em = new char[30];
	char* ps = new char[10];
	cout << "\n\n\n\t\t\t\t   Super Market Billing System " << endl;
	cout << "\t\t\t\t*************************************" << endl;
	cout << "\n\t\t\t\t\t Admin Login " << endl;
	admin m1;
	bool adminem = 0;
	cout << "\n\t\t\t\tEnter Email    :";
	int k = 0;
	int quantity;
	int price;
	int sum=0;
	while (!adminem)
	{

		cin >> em;
		m1.setemail(em);
		adminem = m1.checkemail();

		if (adminem == false)
		{

			cout << "\n\t\t\t\tWrong Email try again ";
			k++;
			if (k == 3)
			{
				cout << "\n\t\t\t\tSorry All Attempts Failed!!!";
				exit(0);
			}
		}


	}

	bool adminp = 0;
	cout << "\n\t\t\t\tEnter Password :";
	k = 0;
	while (!adminp)
	{
		cin >> ps;
		m1.setpassword(ps);
		adminp = m1.checkpassword();
		if (adminp == false)
		{

			cout << "\n\t\t\t\tWrong Password try once more ";
			k++;
			if (k == 3)
			{
				cout << "\n\t\t\t\tSorry All Attempts Failed!!!\n";
				exit(0);
			}
		}
	}
	char opt;
	do
	{
	menu:
		system("pause");
		system("cls");

		cout << "\n\t\t\t\t1.Show Bill Report. " << endl;
		cout << "\t\t\t\t2.Display all items" << endl;
		cout << "\t\t\t\t3.Add/remove/edit items." << endl;
		cout << "\t\t\t\t4.Exit" << endl;
		int num = 0;


		cout << "\n\t\t\t\t Enter your choice " << endl;
		cin >> opt;
		item i9;
		int i=0, j=0;
		int a = 0;
		int size = 0;
		bool checki = 0;
		char* temp = new char[30];
		char* deleteitem = new char[30];
		item* i13 = new item[num];
		ofstream outfile("store.txt", ios::app);
		switch (opt)
		{
		case '1':
			i9.output();

		case '2':
			system("cls");
			i9.readdata();
			goto menu;
		case '3':
			choice:
			system("pause");
			system("cls");
			cout << "\n\n\t\t\t\t1.Add Items.  " << endl;
			cout << "\t\t\t\t2.Edit Items.   " << endl;
			cout << "\t\t\t\t3.Delete Items.  " << endl;
			cout << "\t\t\t\t4.Back to Main Menu" << endl;

			char ch;
			
			cout << "Enter your choice " << endl;
			cin >> ch;
			switch (ch)
			{
			case '1':
				cout << "Enter how many items you want to buy" << endl;
				cin >> num;
				
				i13[0].readdata();
				
				for (int i = 0; i < num; i++)
				{
					
					input:
					cout << "Enter an item" << (i + 1) << endl;
					cin >> temp;
					
					checki=i13[i].checkitem(temp);
					if (checki == true)
					{
						i13[i].setitem(temp);
						cout << "Enter a quantity " << endl;
						cin >> quantity;
						i13[i].setquantity(quantity);
						cout << "Enter a price " << endl;
						cin >> price;
						i13[i].setprice(price);
						i13[i].settotalprice();
						
						sum+= i13[i].gettotalprice();
						
						
					}
					else
					{
						cout << "\n\t\t\tItem is not available " << endl;
						goto input;
					}
					
				}
				
				a = +1;
				
				outfile << endl << "Bill No. : " << a << endl;
				outfile << "------------------------------------------------------------------------" << endl;
				cout << "\n";
				cout << "Items \t Quantity \t Price \t Total Price\n";
				for (int i = 0; i < num; i++)
				{
					i13[i].output();
				}
				outfile << "------------------------------------------------------------------------" << endl;
				outfile.close();
				goto choice;
				
			case'3':
				cout << "\n\t\t\tEnter Item name to be deleted ";
				cin.ignore();
				cin.getline(deleteitem, 30);
				size = strlen(deleteitem);
				for (int i = 0;i< num;i++)
				{
					
					if (deleteitem[i] ==i13[i].getitem())
					{
						
						i13[i].deleteit(deleteitem);

					}

				}
			case '4':
				system("pause");
				goto menu;
			}
		case '4':
			exit(0);
		}
	} while (opt != 3);
	
	return 0;

}
