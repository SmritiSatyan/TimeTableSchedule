// timetable.cpp : Defines the entry point for the console application.
//

#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#define mslot 6
#define mday 6

enum day { mon = 0, tue, wed, thu, fri, sat };
enum sub { free = 0, maths, SS,JAVA, DS, CPP };
enum slot { f = 0, s, t, f, fi, si };
char *d[6] = { "mon", "tue", "wed", "thu", "fri", "sat" }; // days
char *s[6] = { "-", "mat", "SS", "DS", "JAVA", "CPP" }; // subjects
char *t[6] = { "7:30", "8:30", "9:30", "10:30", "11:30", "12:30" };//time
class timetable
{
private: int slot[mday][mslot];


public: timetable();
         {
           int i,j;
           for(i=0;i<mday;i++)
	    {
	      for(j=0;j<mslot;j++)
	       {
		 slot[i][j]=free
               }
	     }
	}
friend ostream& operator << (ostream &out,Timetable &t)
{
	int i, j, sub;
	out << "\t7:30\t" << "8:30\t" << "9:30\t" << "10:30\t" << "11:30\t" << "12:30\t";
	for (i = 0; i < mday; i++)
	{
		out << d[i] << "\t";
		for (j = 0; j < mslot; j++)
		{
			s = t.slot[i][j];
			out << sloth[s] << "\t";
		}
	}

	out << endl;
	return out;
}
void allslot(int row, int col, int sub)
{
	slot[row][col] = sub;
}

void setfree(int row, int col)
{
	slot[row][col] =free;
}

void search(int day, int period)
{
	int s;
	s = slot[day][period];
	cout << sloth[s] << endl;
}
void search(int sub)
{
	for (int i = 0; i < mday; i++)
	{
		for (int j = 0; j < mslot; j++)
		{
			int s = slot[i][j];
			if (s == sub)
			{
				slot[i][j] = free;
			}
		}
	}
}

void read(int day)
{
	int i,s;
	for (i = 0; i < mslot; i++)
	{
		s = slot[day][i];
		cout << sloth[s] << "\t";
	}
}
void getfreeslots()
{
	int i, j, s;
	for (i = 0; i < mday; i++)
	{
		cout << dayh[i] << "\t";
		for (j = 0; j < mslot; j++)
		{
			s = slot[i][j];
			if (s == free)
			{
				cout << time[j] << "\t";
			}

		}
	}
}

void save()
{
	char fname[20],s[20];
	cout << "Enter name of file\n" << endl;
	cin >> s;
	sprintf(fname, "c:/%s.txt", s);
	ofstream write(fname);
	if (!write)
	{
		cout << "Cannot open file" << endl;
		return;
	}

	int i, j, sub;
	write << "\t7:30\t" << "8:30\t" << "9:30\t" << "10:30\t" << "11:30\t" << "12:30\t";
	for (i = 0; i < mday; i++)
	{
		write << dayh[i] << "\t";
		for (j = 0; j < mslot; j++)
		{
			sub = slot[i][j];
			write << sloth[sub] << "\t";
		}
	}

     }
}

int main()
{
	timetable t1;
	int ch, d, s, p,true;
	true = 1;
	while (true)
	{
		cout << "Enter your choice" << endl;
		cout << "1.Allot Slot\n" << "2.Free a slot\n" << "3.Free subject from the table\n " << "4.Search for a subject from a respective slot\n";
		cout << "5.Read and display the activities on a specified date\n" << "6.Display all the free slots\n" << "7.Save\n"<<"8.display\n"<<"9.Exit" << endl;
		cin >> ch;
		switch (ch)
		{
		case 1: 
				cout << "Enter the time " << endl;
				cout << "7 : 30 -> 1\t" << "8 : 30 -> 2\t" << "9 : 30 -> 3" << "..........\t" << "12 : 30 -> 6" << endl;
				cin >> period;
				
				cout << "Enter the day" << endl;
				cout << "MONDAY -> 1\t" << "Tuesday -> 2\t" << "Wednesday -> 3\t" << " ............\t" << "Saturday -> 6" << endl;
				cin >> day;

				cout << "Enter subject" << endl;
				cout << "Maths -> 1\t" << "SS -> 2\t" << "DS -> 3\t" << "JAVA -> 4\t" << "OOP -> 5" << endl;
				cin >> sub;

				t1.allslot(day-1 ,period-1, sub);
				break;

		case 2: 
			    cout << t1;
				cout << "Enter the day and period to free" << endl;
				cout << "7 : 30 -> 1\t" << "8 : 30 -> 2\t" << "9 : 30 -> 3" << "..........\t" << "12 : 30 -> 6" << endl;
				cout << "MONDAY -> 1\t" << "Tuesday -> 2\t" << "Wednesday -> 3\t" << " ............\t" << "Saturday -> 6" << endl;
				cin >> day >> period;
				t1.setfree(day, period);
				break;

		case 3:
				cout << "Enter the subject to be freed from the table" << endl;
				cout << "Maths -> 1\t" << "DMS -> 2\t" << "LD -> 3\t" << "DS -> 4\t" << "OOP -> 5" << endl;
				cin >> sub;
				t1.search(sub);
				break;

		case 4:
				cout << "Enter the day and period" << endl;
				cout << "7 : 30 -> 1\t" << "8 : 30 -> 2\t" << "9 : 30 -> 3" << "..........\t" << "12 : 30 -> 6" << endl;
				cout << "MONDAY -> 1\t" << "Tuesday -> 2\t" << "Wednesday -> 3\t" << " ............\t" << "Saturday -> 6" << endl;
				cin >> day >> period;
				t1.search(day, period);
				break;

		case 5: 
				cout << "Enter the day" << endl;
				cout << "7 : 30 -> 1\t" << "8 : 30 -> 2\t" << "9 : 30 -> 3" << "..........\t" << "12 : 30 -> 6" << endl;
				cin >> day;
				t1.read(day);
				break;

		case 6: 
				cout << "The slots available are" << endl;
				t1.getfreeslots();
				break;

		case 7: 
				cout << "Enter your name to save" << endl;
				t1.save();
				break;

		case 8: cout << t1;
			break;

		case 9: true = 0;
			break;
		default:
			 break;
		}
	}
	/*t1.allslot(wed,f,CPP);
	t1.allslot(fri, si, JAVA);
	t1.allslot(sat, f, DS);
	t1.allslot(sat, t, SS);
	t1.allslot(sat, s, maths);
	t1.allslot(sat, f, CPP);
	t1.allslot(sat, fi, JAVA);
	cout << t1;
	t1.search(2, 3);
	cout << t1 << endl;
	t1.read(SAT);
	cout << "FREE SLOTS" << endl;
	t1.getfreeslots();
	t1.save();*/
	return 0;
}

