#include <iostream>
using namespace std;
void employeedata(int& b, int& c, int& d, int& e, int& i, int& disp, int data[100][2], string id[100][2], int& tempo);
void stock(int& f, int& g, int& h, int& j, int& k, int& sdisp, int sdata[100][2], string sid[100][1]);
void attendence(int att[31][100], int& tempo, int data[100][2], string id[100][2], int& td);
void salary(string id[100][2], int att[31][100], int& tempo, int data[100][2]);
void invoice(int sdata[100][2], string sid[100][1], int& out);
void profit(int& out);

int main()
{
//1 tine intializer
	int td = 0, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, k = 0, l = 0, disp = 0, sdisp = 0, tempo = 0, out = 0;
	int data[100][2], sdata[100][2], att[31][100];
	string id[100][2], sid[100][1];
	for (int in = 0;in < 100;in++)
	{
		for (int ini = 0;ini < 2;ini++)
		{
			sdata[in][ini] = 0;
		}
	}
	for (int in = 0;in < 100;in++)
	{
		for (int ini = 0;ini < 1;ini++)
		{
			sid[in][ini] = "No Data Found!";
		}
	}
	for (int in = 0;in < 100;in++)
	{
		for (int ini = 0;ini < 2;ini++)
		{
			data[in][ini] = 0;
		}
	}
	for (int in = 0;in < 100;in++)
	{
		for (int ini = 0;ini < 2;ini++)
		{
			id[in][ini] = "No Data Found!";
		}
	}
//program
redo:
	system("cls");
	cout << "\n\t\t Welcome to Canteen Management.\n";
	cout << "\tThis Project is made by Muteeb Yousuf (342),Ahsan Ali (338),Hamza Abbas (342).\n";
	cout << "-------------------------------------------------------------\n\n\n";
	cout << "1 For Employee Data\n2 For Stock Management\n3 For Attendence\n4 For Salary\n5 For Invoice\n6 For Profit\n7 For Exit!";
	cout << "\nEnter:";
	cin >> a;
	if (a == 1)
	{
		employeedata(b, c, d, e, i, disp, data, id, tempo);
		goto redo;
	}
	else if (a == 2)
	{
		stock(f, g, h, j, k, sdisp, sdata, sid);
		goto redo;

	}
	else if (a == 3)
	{
		attendence(att, tempo, data, id, td);
		goto redo;
	}
	else if (a == 4)
	{
		salary(id, att, tempo, data);
		goto redo;
	}
	else if (a == 5)
	{
		invoice(sdata, sid, out);
		goto redo;
	}
	else if (a == 6)
	{
		profit(out);
		goto redo;
	}
	else if (a == 7)
	{
		return 0;
	}
	goto redo;

}
void employeedata(int& b, int& c, int& d, int& e, int& i, int& disp, int data[100][2], string id[100][2], int& tempo)
{

back:
	int chk = 0;
	system("cls");
	cout << "\t\t\tEmployee Data";

	cout << "\n-------------------------------------------------------------\n\n\n";
	cout << "\n1 To Add Data\n2 To View Data\n3 To Edit Data\n4 To Goto Main";
	cout << "\nEnter:";
	cin >> b;
	
	if (b == 1)
	{
		system("cls");
		cout << "\t\tEmployee Data Entry\n";
		cout << "\n-------------------------------------------------------------\n\n\n";
		cout << "How many Employees You Want to Enter:";
		cin >> c;
		tempo = tempo + c;

		//adding empoyee data
		for (i; i < tempo; i++)
		{
			cout << "\n\tEntering Employee Data for Id:" << i + 1;
			cout << "\n\nEnter Name:";
			cin >> id[i][0];
			cout << "Enter Designation:";
			cin >> id[i][1];
			cout << "Enter Age:";
			cin >> data[i][0];
			cout << "Enter Salary:";
			cin >> data[i][1];

		}

	view:
		//viewing employee data
		cout << "\n\n\n1 To Display Employee Data\n2 To Back\n3 To Main";
		cout << "\nEnter:";
		cin >> d;
		//Displaying
		if (d == 1)
		{

			system("cls");
			cout << "\t\t\tDisplaying Employee Data\n\n";
			cout << "\n-------------------------------------------------------------\n\n\n";
			cout << "1 To Show All Employee Data\n2 To Search for ID\n";
			cout << "Enter:";

			cin >> disp;
			//showing all employee data
			if (disp == 1)
			{
				
				for (int s = 0; s < i; s++)
				{
					cout << "\n\tDisplaying Employee Data:" << s + 1;
					cout << "\n\nName:" << id[s][0];
					cout << "\nDesignation:" << id[s][1];
					cout << "\nAge:" << data[s][0];
					cout << "\nSalary:" << data[s][1] << "\n\n";

				}
				goto view;

			}
			//showing employee data by id
			else if (disp == 2)
			{
				cout << "Enter ID:";
				cin >> e;
				cout << "\n\tDisplaying Employee Data:" << e;
				cout << "\n\nName:" << id[e - 1][0];
				cout << "\nDesignation:" << id[e - 1][1];
				cout << "\nAge:" << data[e - 1][0];
				cout << "\nSalary:" << data[e - 1][1];
			}
		}
		//To Back
		else if (d == 2)
		{
			goto back;
		}
		//To mian
		else if (d == 3)
		{
			return;
		}

	}
	//viewing data
	else if (b == 2)
	{
		goto view;
	}
	//Editing data
	else if (b == 3)
	{
	edit:
		system("cls");
		int h, l;
		cout << "Enter Edit ID:";
		cin >> h;
		cout << "\n\t\t\tDisplaying Current Data\n";
		cout << "\nName:" << id[h - 1][0];
		cout << "\nDesignation:" << id[h - 1][1];
		cout << "Age:" << data[h - 1][0];
		cout << "Salary:" << data[h - 1][1];
		
		//checking avalibility of data
		if (id[h - 1][0] == "No Data Found!")
		{
			cout << "\n\t\t\t\tAdd Data First!\n1 To Go Back\n2 Goto Main\nEnter:";
			cin >> chk;
			
			if (chk == 1)
			{
				goto back;
			}

		}
		//editing previously enterded data.
		else
		{
			cout << "\n\tEditing Employee Data for Id:" << h;
			cout << "\n\nEnter Name:";
			cin >> id[h - 1][0];
			cout << "Enter Designation:";
			cin >> id[h - 1][1];
			cout << "Enter Age:";
			cin >> data[h - 1][0];
			cout << "Enter Salary:";
			cin >> data[h - 1][1];
			cout << "\n1 To Back\n2 To Edit More\nEnter:";
			cin >> l;
			if (l == 1)
			{
				goto back;
			}
			else if (l == 2)
			{
				goto edit;
			}
		}

	}
	//to main
	else if (b == 4)
	{
	
		return;
	}
	goto back;
}
void stock(int& f, int& g, int& h, int& j, int& k, int& sdisp, int sdata[100][2], string sid[100][1])
{
	system("cls");

	int temp = 0;
back:
	system("cls");
	cout << "\t\t\tStock Management";

	cout << "\n-------------------------------------------------------------\n\n\n";
	cout << "\n1 To New Stock\n2 To View Stock\n3 To Edit Stock\n4 To Add Stock\n5 To Goto Main";
	cout << "\nEnter:";
	cin >> f;

	//adding stock
	if (f == 1)
	{
		system("cls");
		cout << "\t\tStock Entry\n";
		cout << "\n-------------------------------------------------------------\n\n\n";
		cout << "How many Items You Want to Enter:";
		cin >> g;
		temp = temp + g;

		for (k; k < temp; k++)
		{
			cout << "\n\tEntering Stock for Id:" << k + 1;
			cout << "\n\nEnter Name:";
			cin >> sid[k][0];
			cout << "Enter QTY:";
			cin >> sdata[k][0];
			cout << "Enter Price:";
			cin >> sdata[k][1];

		}
		//displaying stock
	view:
		cout << "\n\n\n1 To Display Stock\n2 To Back\n3 To Main";
		cout << "\nEnter:";
		cin >> h;
		//display stock
		if (h == 1)
		{

			system("cls");
			cout << "\t\t\tDisplaying Stock\n\n";
			cout << "\n-------------------------------------------------------------\n\n\n";
			cout << "1 To Show All Stock\n2 To Search for Stock ID\n";
			cout << "Enter:";

			cin >> sdisp;
			//showing alll stock
			if (sdisp == 1)
				
			{

				for (int s = 0; s < k; s++)
				{
					cout << "\n\tDisplaying Stock Data:" << s + 1;
					cout << "\n\nName:" << sid[s][0];
					cout << "\nQTY:" << sdata[s][0];
					cout << "\nPrice:" << sdata[s][1] << "\n\n";
				}
			}
			//showing stock for id
			else if (sdisp == 2)
			//showing stock for id
			{
				cout << "Enter ID:";
				cin >> j;
				cout << "\n\tDisplaying Stock Data:" << j;
				cout << "\n\nName:" << sid[j - 1][0];
				cout << "\nQTY:" << sdata[j - 1][0];
				cout << "\nPrice:" << sdata[j - 1][1];
			}
		}
		//to back
		else if (h == 2)
		{
			goto back;
		}
		//to main
		else if (h == 3)
		{
			return;
		}

	}
	//viewing data
	if (f == 2)
	{
		goto view;
	}

	else if (f == 3)
	{
	edit:
		system("cls");
		int h, l,chk=0;
		cout << "Enter Edit ID:";
		cin >> h;
		cout << "\n\t\t\tDisplaying Current Data\n";
		cout << "\nPrduct name:" << sid[h - 1][0];
		cout << "\nQTY:" << sdata[h - 1][0];
		cout << "\nPrice:" << sdata[h - 1][1];

		//checking avalibility of data
		if (sid[h - 1][0] == "No Data Found!")
		{
			cout << "\n\t\t\t\tAdd Data First!\n1 To Go Back\n2 Goto Main\nEnter:";
			cin >> chk;

			if (chk == 1)
			{
				goto back;
			}

		}
		//editing previously enterded data.
		else
		{
			cout << "\n\tEditing Stock Data for Id:" << h;
			cout << "\n\nEnter Name:";
			cin >> sid[h - 1][0];
			cout << "Enter QTY:";
			cin >> sdata[h - 1][0];
			cout << "Enter Price:";
			cin >> sdata[h - 1][1];
			cout << "\n1 To Back\n2 To Edit More\nEnter:";
			cin >> l;
			if (l == 1)
			{
				goto back;
			}
			else if (l == 2)
			{
				goto edit;
			}
		}



	}
	else if (f == 4)
	{
		int ad, add;
		cout << "Enter Add ID:";
		cin >> ad;
		cout << "\nName:" << sid[ad - 1][0];
		cout << "\nCurrent QTY:" << sdata[ad - 1][0];
		cout << "\nPrice:" << sdata[ad - 1][1];
		cout << "\nEnter Quantity to add:";
		cin >> add;
		sdata[ad - 1][0] = sdata[ad - 1][0] + add;
		goto back;
	}
	else if (f == 5)
	{
		return;
	}


}
void attendence(int att[31][100], int& tempo, int data[100][2], string id[100][2], int& td)
{
	system("cls");
	cout << "\t\t\t\tAttendence";
	int tf = 0, tdisp = 0, tc = 0, tco;
	double temp1 = 0;
	string temp;
	cout << "\n-------------------------------------------------------------\n\n\n";
back:
	cout << "\n\n\n1 To Mark Attendence\n2 To View Attendence\n3 To Goto Main";
	cout << "\nEnter:";
	cin >> tf;
	if (tf == 1)
	{
		system("cls");
		cout << "\n\t\t\tMarking Attendence\n";
		cout << "\n-------------------------------------------------------------\n\n\n";
		cout << "Enter Marking Day:";
		cin >> td;
		for (int cn = 0;cn < tempo;cn++)
		{
			cout << "\nID:" << cn + 1;
			cout << "\nName:" << id[cn][0];
			cout << "\nDesignation:" << id[cn][1];
			cout << "\nAttendence(A/P):";
			cin >> temp;
			if (temp == "p" || temp == "P")
			{
				att[td - 1][cn] = 1;
			}
			else
			{
				att[td - 1][cn] = 0;
			}

		}


	}
	else if (tf == 2)
	{
		system("cls");
		cout << "\t\t\tDisplaying Attendence\n\n";
		cout << "\n-------------------------------------------------------------\n\n\n";
		cout << "1 For Today\n2 For Monthly\nEnter:";
		cin >> tco;
		cout << "\n1 To Show All Attendence\n2 To Search for ID\n";
		cout << "Enter:";
		cin >> tdisp;

		
		//today
		if (tco == 1)
		{
			//All
			if (tdisp == 1)
			{
				for (int ts = 0; ts < tempo; ts++)
				{
					cout << "\n\tDisplaying Attendence Data:" << ts + 1;
					cout << "\nName:" << id[ts][0];
					cout << "\nDesignation:" << id[ts][1];
					if (att[td - 1][ts] == 1)
					{
						cout << "\nAttendence(A/P):P";
					}
					else
					{
						cout << "\nAttendence(A/P):A";
					}
				}
				goto back;
			}
			
			//Search for id
			else if (tdisp == 2)
			{
				cout << "Enter ID:";
				cin >> tc;
				cout << "\n\tDisplaying Attendence of ID:" << tc;
				cout << "\nName:" << id[tc - 1][0];
				cout << "\nDesignation:" << id[tc - 1][1];
				if (att[td - 1][tc] == 1)
				{
					cout << "\nAttendence(A/P):P";
				}
				else
				{
					cout << "\nAttendence(A/P):A";
				}
				goto back;
			}
		}
		
		//Monthly
		else if (tco == 2)
		{
			
			//All
			if (tdisp == 1)
			{
				for (int ts = 0; ts < tempo; ts++)
				{
					cout << "\n\tDisplaying Attendence Data:" << ts + 1;
					cout << "\nName:" << id[ts][0];
					cout << "\nDesignation:" << id[ts][1];
					temp1 = 0;
					
					//Attendence Calculator
					for (int tl = 0;tl < 31;tl++)
					{
						if (att[tl][ts] == 1)
						{
							temp1++;
						}
						else
						{

						}
					}

					cout << "\nAttendence(%):" << (temp1 / 31) * 100;
				}
				goto back;
			}

			//id
			else if (tdisp == 2)
			{
				cout << "Enter ID:";
				cin >> tc;
				cout << "\n\tDisplaying Attendence of ID:" << tc;
				cout << "\nName:" << id[tc - 1][0];
				cout << "\nDesignation:" << id[tc - 1][1];
				temp1 = 0;
				for (int tl = 0;tl < 31;tl++)
				{
					if (att[tl][tc - 1] == 1)
					{
						temp1++;
					}
					else
					{

					}
				}

				cout << "\nAttendence(%):" << (temp1 / 31) * 100;
				goto back;
			}
		}

	}

	return;
}
void salary(string id[100][2], int att[31][100], int& tempo, int data[100][2])
{
	system("cls");
	cout << "\t\t\t\tSalary";
	int  tf = 0, tc = 0, disp = 0, ids = 0;
	double temp = 0, temp1 = 0;

	cout << "\n-------------------------------------------------------------\n\n\n";
back:
	cout << "\n\n\n1 To View Salary\n2 To Goto Main";
	cout << "\nEnter:";
	cin >> tf;
	system("cls");
	if (tf == 1)
	{
		cout << "\n1 To View All Salaries\n2 To Search For ID\nEnter:";
		cin >> disp;
		if (disp == 1)
		{
			for (int ts = 0; ts < tempo; ts++)
			{
				cout << "\n\tDisplaying Salary Data:" << ts + 1;
				cout << "\nName:" << id[ts][0];
				cout << "\nDesignation:" << id[ts][1];
				temp1 = 0;
				for (tc = 0;tc < 31;tc++)
				{
					if (att[tc][ts] == 1)
					{
						temp1++;
					}
					else
					{

					}
				}
				temp = (temp1 / 31) * 100;
				if (temp > 80)
				{
					cout << "\nBonus Rewarded!\n";
					cout << "Total Salary is:" << data[ts][1] + (data[ts][1] / 15);
				}
				else if (temp < 80 && temp > 50)
				{
					cout << "\nNo Bonus\n";
					cout << "Total Salary is:" << data[ts][1];
				}
				else if (temp < 50 && temp>10)
				{
					cout << "\nSalaray Deduced Due To Low Attendence!!!\n";
					cout << "Total Salary is:" << data[ts][1] - (data[ts][1] / 30);
				}
				else if (temp < 10)
				{
					cout << "\nNo Salary Due To Low Attendence";
				}
			}
		}
		else if (disp == 2)
		{
			cout << "Enter ID:";
			cin >> ids;
			cout << "\n\tDisplaying Salary Data:" << ids;
			cout << "\nName:" << id[ids - 1][0];
			cout << "\nDesignation:" << id[ids - 1][1];
			temp1 = 0;
			for (tc = 0;tc < 31;tc++)
			{
				if (att[tc][ids - 1] == 1)
				{
					temp1++;
				}
				else
				{

				}
			}
			temp = (temp1 / 31) * 100;
			if (temp > 80)
			{
				cout << "\nBonus Rewarded!\n";
				cout << "Total Salary is:" << data[ids - 1][1] + (data[ids - 1][1] / 15);
			}
			else if (temp < 80 && temp > 50)
			{
				cout << "\nNo Bonus\n";
				cout << "Total Salary is:" << data[ids - 1][1];
			}
			else if (temp < 50 && temp>10)
			{
				cout << "\nSalaray Deduced Due To Low Attendence!!!\n";
				cout << "Total Salary is:" << data[ids - 1][1] - (data[ids - 1][1] / 30);
			}
			else if (temp < 10)
			{
				cout << "\nNo Salary Due To Low Attendence";
			}
		}

		goto back;
	}
	if (tf == 2)
	{
		return;
	}
}
void invoice(int sdata[100][2], string sid[100][1], int& out)
{
	system("cls");
back:
	int temp, tem = 0;
	cout << "\t\t\t\tInvoice";
	cout << "\n-------------------------------------------------------------\n\n\n";
	cout << "1 To Generate Invoice\n2 To Goto Main\n";
	cin >> temp;
	if (temp == 1)
	{
		int rm, rmv, ttl = 0;

		for (int t = 0;t < 1; t++)
		{
			cout << "Enter Product ID:";
			cin >> rm;
			cout << "\nName:" << sid[rm - 1][0];
			cout << "\nCurrent QTY:" << sdata[rm - 1][0];
			cout << "\nPrice:" << sdata[rm - 1][1];
			cout << "\nEnter Quantity to Sale:";
			cin >> rmv;
			sdata[rm - 1][0] = sdata[rm - 1][0] - rmv;
			out = out + (sdata[rm - 1][1] * rmv);
			ttl = out + (sdata[rm - 1][1] * rmv);
			cout << "1 To Add More\n2 To Done\nEnter:";
			cin >> tem;
			if (tem == 1)
			{
				t--;
			}

		}
		cout << "\nYour Total is:" << ttl;
		cout << "\n-------------------------------------------------------------\n\n\n";
		goto back;
	}

	else
		return;


}
void profit(int& out)
{
	system("cls");
	int temp, temp1;
back:
	cout << "\t\t\t\tProfit";
	cout << "\n-------------------------------------------------------------\n\n\n";
	cout << "1 To View Profit\n2 To Goto Main\n";
	cin >> temp;


	if (temp == 1)
	{
		cout << "The Profit This Month is:" << (out * .15) << endl;
	}
	else
	{
		return;
	}
	goto back;
}
