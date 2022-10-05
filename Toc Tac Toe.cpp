#include<iostream>
using namespace std;
int player=0, Turn=1, check=0; 
struct node
{
	int data;
	node *address;
};
class TikTac
{
	private:
		node *head, *tail;
	public:
		TikTac()
		{
			head=NULL;
			tail=NULL;
		}
		void add(int num)
		{
			node *t1 = new node;
			t1->data=num;
			t1->address=NULL;
			if(head==NULL)
			{
				head=t1;
				tail=t1;
			}
			else
			{
				tail->address=t1;
				tail=tail->address;
			}
		}
		void Play(int Column)
		{
			node* temp;
			temp=head;
			int skip=0;
			for(int a=0;a<3;a++)
			{
				if(Column-1==a && Turn==1)
				{
					if(temp->data==1 || temp->data==2)
					{
						cout<<"Invalid Already Occupied"<<endl;
						cout<<"Your turn has been skipped"<<endl;
						skip++;
					}
					else
					{
						temp->data=1;
					    //temp=temp->address;
					} 
				}
				else if(Column-1==a && Turn==2)
				{
				    if(temp->data==1 || temp->data==2)
					{
						cout<<"Invalid Already Occupied"<<endl;
						cout<<"Your turn has been skipped"<<endl;
					}
					else
					{
						temp->data=2;
					    temp=temp->address;
					} 	
				}
				else
				{
					temp=temp->address;
				}
			}
			if(skip==0)
			{
				check++;
			}
		}
		void DisplayGrid(TikTac R2, TikTac R3)
		{
			int count=0;
			node* temp1;
			temp1=head;
			for(int a=0;a<3;a++)
			{
				cout<<"                     ";
				if(count==1)
				{
					temp1=R2.head;
				}
				else if(count==2)
				{
					temp1=R3.head;
				}
				for(int b=0;b<3;b++)
				{
					if(temp1->data==1)
					cout<<"X ";
					else if(temp1->data==2)
				    cout<<"O ";
				    else if(temp1->data==0)
				    cout<<"^ ";
				    temp1=temp1->address;
				    if(b!=2)
				    {
				    	cout<<" | ";
					}
				}
				if(count!=2)
				{
					cout<<endl<<"                    --------------"<<endl;
				}
				count++;
			}
		}
		int Check(TikTac R2, TikTac R3, int Win)
		{
			cout<<endl<<endl;
			node *temp1,*temp2,*temp3;
			temp1=head;                  //1st Row
			temp2=temp1->address;
			temp3=temp2->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 1st Row"<<endl;
				    return Win;
				}
			}
			temp1=R2.head;                   //2nd Row
			temp2=temp1->address;
			temp3=temp2->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 2nd Row"<<endl;
				    return Win;
				}
			}
			temp1=R3.head;               //3rd Row
			temp2=temp1->address;
			temp3=temp2->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 3rd Row"<<endl;
				    return Win;
				}
			}
			temp1=head;               //1st Column
			temp2=R2.head;
			temp3=R3.head;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 1st Column"<<endl;
				    return Win;
				}
			}
			temp1=temp1->address;     //2nd Column
			temp2=temp2->address;
			temp3=temp3->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 2nd Column"<<endl;
				    return Win;
				}
			}
			temp1=temp1->address;     //3rd Column
			temp2=temp2->address;
			temp3=temp3->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the 3rd Column"<<endl;
				    return Win;
				}
			}
			temp1=head;
			temp2=R2.head;
			temp2=temp2->address;
			temp3=R3.head;
			temp3=temp3->address->address;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the Diagonal Left to Right"<<endl;
				    return Win;
				}
			}
			temp1=temp1->address->address;
			temp3=R3.head;
			if(temp1->data==temp2->data && temp2->data==temp3->data)
			{
				if(temp1->data!=2 && temp1->data!=1)
				{
					//skip
				}
				else
				{
					Win=1;
				    cout<<"All symbols match in the Diagonal Right to Left"<<endl;
				    return Win;
				}
			}
		}
};
int main()
{
	cout<<"                        Welcome To Tic Tac Toe"<<endl;
	cout<<"                            2 player game"<<endl;
	cout<<"The Grid shown below has row and column number on it, kindly play accordingly!"<<endl;
	cout<<"                            Best of Luck!"<<endl<<endl<<endl;
	cout<<"                     "<<"11 "<<"| "<<"12 "<<"| "<<"13 "<<endl;
	cout<<"                    --------------"<<endl;
	cout<<"                     "<<"21 "<<"| "<<"22 "<<"| "<<"23 "<<endl;
	cout<<"                    --------------"<<endl;
	cout<<"                     "<<"31 "<<"| "<<"32 "<<"| "<<"33 "<<endl;
	TikTac R1,R2,R3;
	int Row=0,Column=0,Win=0;
	for(int a=0;a<3;a++)
	{
		for (int b=0;b<3;b++)
		{
			if (a==0)
			{
				R1.add(0);
			}
			else if (a==1)
			{
				R2.add(0);
			}
			else if(a==2)
			{
				R3.add(0);
			}
		}
	}
	cout<<endl<<endl;
	cout<<"Your Current Grid is Empty as Shown Below"<<endl;
	cout<<endl<<endl;
	R1.DisplayGrid(R2,R3);
	cout<<endl<<endl;
	while(player==0)
	{
		if(Turn==1)
		{
			back:
				Row=0;
				Column=0;
			cout<<endl<<endl<<"This is Player 1 turn"<<endl;
		    cout<<"Your symbol is a 'X'"<<endl;
		    cout<<"Please enter your Row and Column number to place the Symbol"<<endl;
		    cout<<"Row: ";
		    cin>>Row;
		    cout<<"Column: ";
		    cin>>Column;
		    if(Row<1 || Row>3)
		    {
				cout<<"Invalid Input Try again!"<<endl;
				goto back;
			}
		}
		else if(Turn==2)
		{
			prev:
			cout<<endl<<endl<<"This is Player 2 turn"<<endl;
		    cout<<"Your Symbol is a 'O'"<<endl;
		    cout<<"Please enter your Row and Column number to place the Symbol"<<endl;
		    cout<<"Row: ";
		    cin>>Row;
		    cout<<"Column: ";
		    cin>>Column;
		    if(Row<1 || Row>3)
		    {
		    	cout<<"Invalid Input Try again!"<<endl;
				goto prev;
			}
		}
		if(Row==2)
		{
			R2.Play(Column);
			R1.DisplayGrid(R2,R3);
		}
		else if(Row==1)
		{
			R1.Play(Column);
			R1.DisplayGrid(R2,R3);
		}
		else if(Row==3)
		{
			R3.Play(Column);
			R1.DisplayGrid(R2,R3);
		}
		if(check>=5)
		{
			Win=R1.Check(R2,R3,Win);
			if(Win==1 || check==9)
			{
				player++;
			}
		}
		if(Turn==1)
		{
			Turn=2;
		}
		else if(Turn==2)
		{
			Turn=1;
		}
	}
	if(check == 9)
	{
		cout<<endl<<endl<<"Game has ended, the game was a Draw!"<<endl;
	}
	else if(Turn==2)
	{
		cout<<endl<<endl<<"Game has ended Player 1 has Won the Game!"<<endl;
	}
	else 
	{
		cout<<endl<<endl<<"Game has ended Player 2 has Won the Game!"<<endl;
	}
}
