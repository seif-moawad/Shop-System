#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
class cusnode
{
public:
	int id;
	string name;
	cusnode* pnext;
};
class cuslist
{
public:
	cusnode* phead;
	cusnode* ptail;
	cuslist()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(cusnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void dispall()
	{
		cusnode* ptrv = phead;
		while (ptrv != NULL)
		{
			cout << ptrv->id << ',' << ptrv->name << endl;
			ptrv = ptrv->pnext;
		}
	}
};
class pronode
{
public:
	int id = 0;
	string name;
	int stock = 0;
	int price = 0;
	pronode* pnext = NULL;
};
class prolist
{
public:
	pronode* phead;
	pronode* ptail;
	prolist()
	{
		phead = NULL;
		ptail = NULL;
	}
	void Attach(pronode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void dispall()
	{
		pronode* ptrav = phead;
		while (ptrav != NULL)
		{
			cout << ptrav->id << "," << ptrav->name << "," << ptrav->stock << "," << ptrav->price << endl;
			ptrav = ptrav->pnext;
		}
	}
};
class pcnode
{
public:
	int cid;
	int pid;
	int price;
	string date;
	pcnode* pnext;
};
class pclist
{
public:
	pcnode* phead;
	pcnode* ptail;
	pclist()
	{
		phead = NULL;
		ptail = NULL;
	}
	void attach(pcnode* pnn)
	{
		if (phead == NULL)
		{
			phead = pnn;
			ptail = pnn;
		}
		else
		{
			ptail->pnext = pnn;
			ptail = pnn;
		}
	}
	void dispall()
	{
		pcnode* ptrv = phead;
		while (ptrv != NULL)
		{
			cout << ptrv->cid << ',' << ptrv->pid << "," << ptrv->price << "," << ptrv->date << endl;
			ptrv = ptrv->pnext;
		}
	}
};
void main()
{
	fstream customer;
	fstream product;
	fstream procust;
	int i, j, k, flag;
	cuslist l;
	prolist l2;
	pclist l3;
	customer.open("E:\\Data Structures\\customer.txt");
	product.open("E:\\Data Structures\\product.txt");
	procust.open("E:\\Data Structures\\procust.txt");
	if (customer.is_open())
	{
		string x;
		while (getline(customer, x))
		{
			string tmp[3];
			int it = 0;
			for (i = 0; i < x.length(); i++)
			{
				if (x[i] == ',')
				{
					it++;
				}
				else
				{
					tmp[it] += x[i];
				}
			}
			cusnode* pnn;
			pnn = new cusnode;
			pnn->id = stoi(tmp[0]);
			pnn->name = tmp[1];
			pnn->pnext = NULL;
			l.attach(pnn);
		}
	}
	customer.close();
	if (product.is_open())
	{
		string y;
		while (getline(product, y))
		{
			string tmpp[5];
			int it = 0; int i = 0;
			for (i = 0; i < y.length(); i++)
			{
				if (y[i] == ',')
				{
					it++;
				}
				else
				{
					tmpp[it] += y[i];
				}
			}
			pronode* pnn1;
			pnn1 = new pronode;
			pnn1->id = stoi(tmpp[0]);
			pnn1->name = tmpp[1];
			pnn1->stock = stoi(tmpp[2]);
			pnn1->price = stoi(tmpp[3]);
			pnn1->pnext = NULL;
			l2.Attach(pnn1);
		}
	}
	product.close();
	if (procust.is_open())
	{
		string z;
		while (getline(procust, z))
		{
			string tmmp[5];
			int it = 0;
			for (i = 0; i < z.length(); i++)
			{
				if (z[i] == ',')
				{
					it++;
				}
				else
				{
					tmmp[it] += z[i];
				}
			}
			pcnode* pnn2;
			pnn2 = new pcnode;
			pnn2->cid = stoi(tmmp[0]);
			pnn2->pid = stoi(tmmp[1]);
			pnn2->price = stoi(tmmp[2]);
			pnn2->date = tmmp[3];
			pnn2->pnext = NULL;
			l3.attach(pnn2);
		}
	}
	procust.close();
	l.dispall();
	l2.dispall();
	l3.dispall();
	cout << " " << endl;
	cout << "enter number of function" << endl;
	cin >> flag;
	if (flag == 1)
	{
		int custid;
		int prodid;
		string date1;
		cout << "please enter customer id" << endl;
		cin >> custid;
		cout << "please enter product id" << endl;
		cin >> prodid;
		cusnode* ptrav = l.phead;
		pronode* ptrav2 = l2.phead;
		while (ptrav != NULL)
		{
			if (ptrav->id == custid)
			{
				while (ptrav2 != NULL)
				{
					if (ptrav2->id == prodid)
					{
						if (ptrav2->stock > 0)
						{
							cout << "please enter the date" << endl;
							cin >> date1;
							ptrav2->stock--;
							pcnode* pnn;
							pnn = new pcnode;
							pnn->cid = custid;
							pnn->pid = prodid;
							pnn->price = ptrav2->price;
							pnn->date = date1;
							l3.attach(pnn);
							cout << "done" << endl;
							break;
						}
						else
						{
							cout << "stock are empty" << endl;
							break;
						}
					}
					ptrav2 = ptrav2->pnext;
				}
				break;
			}
			else
			{
				if (ptrav->id != custid && ptrav->pnext == NULL)
				{
					cout << "customer not found" << endl;
					cusnode* pnnnew;
					pnnnew = new cusnode;
					cout << "enter the name of the new customer" << endl;
					string newcustname;
					cin >> newcustname;
					pnnnew->id = custid;
					pnnnew->name = newcustname;
					pnnnew->pnext = NULL;
					l.attach(pnnnew);
					break;
				}
			}
			ptrav = ptrav->pnext;
		}
	}
	if (flag == 2)
	{
		int custid1;
		int prodid1;
		cout << "enter customer id" << endl;
		cin >> custid1;
		cout << "enter product id" << endl;
		cin >> prodid1;
		cusnode* ptrav = l.phead;
		pronode* ptrav2 = l2.phead;
		pcnode* ptrav3 = l3.phead;
		pcnode* pb = NULL;
		while (ptrav3 != NULL)
		{
			if (ptrav3->cid == custid1 && ptrav3->pid == prodid1)
			{
				if (ptrav3 == l3.phead)
				{
					l3.phead = ptrav3->pnext;
					ptrav3->pnext = NULL;
					delete ptrav3;
					ptrav3 = l3.phead;
				}
				if (ptrav3 != l3.phead && ptrav3 != l3.ptail)
				{
					pb->pnext = ptrav3->pnext;
					ptrav3->pnext = NULL;
					delete ptrav3;
					ptrav3 = pb->pnext;
				}
				if (ptrav3 == l3.ptail)
				{
					l3.ptail = pb;
					pb->pnext = NULL;
					delete ptrav3;
					ptrav3 = l3.ptail;
				}
				while (ptrav2 != NULL)
				{
					if (ptrav2->id == prodid1)
					{
						ptrav2->stock++;
						break;
					}
					ptrav2 = ptrav2->pnext;
				}
			}
			else
			{
				pb = ptrav3;
				ptrav3 = ptrav3->pnext;
			}
		}
	}
	if (flag == 3)
	{
		int tot = 0;
		string date2;
		cout << "please enter date" << endl;
		cin >> date2;
		pcnode* ptrav = l3.phead;
		while (ptrav != NULL)
		{
			if (ptrav->date == date2)
			{
				tot += ptrav->price;
			}
			ptrav = ptrav->pnext;
		}
		cout << tot << endl;
	}
	if (flag == 4)
	{
		int ct = 0;
		int custid2;
		cout << "please enter customer id" << endl;
		cin >> custid2;
		pcnode* ptrav = l3.phead;
		while (ptrav != NULL)
		{
			if (ptrav->cid == custid2)
			{
				ct++;
			}
			ptrav = ptrav->pnext;
		}
		cout<<"customer made "<< ct<<" orders"<<endl;
	}
	customer.open("E:\\Data Structures\\customer.txt", ios::in | ios::out | ios::trunc);
	product.open("E:\\Data Structures\\product.txt", ios::in | ios::out | ios::trunc);
	procust.open("E:\\Data Structures\\procust.txt", ios::in | ios::out | ios::trunc);
	cusnode* ptrav = l.phead;
	pronode* ptrav2 = l2.phead;
	pcnode* ptrav3 = l3.phead;
	while (ptrav != NULL)
	{
		customer << ptrav->id << ',' << ptrav->name << endl;
		ptrav = ptrav->pnext;
	}
	while (ptrav2 != NULL)
	{
		product << ptrav2->id << ',' << ptrav2->name << ',' << ptrav2->stock << "," << ptrav2->price << endl;
		ptrav2 = ptrav2->pnext;
	}
	while (ptrav3 != NULL)
	{
		procust << ptrav3->cid << ',' << ptrav3->pid << "," << ptrav3->price << "," << ptrav3->date << endl;
		ptrav3 = ptrav3->pnext;
	}
	system("pause");
}