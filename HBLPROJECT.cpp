/*
this project is of bank managment system
using link list
functions in this are creat acount search acount delete acount view acount for managaer
and password of manager is kamran
user funtions are transfer amount withdraw change pin and check balance

*/
#include<iostream>
#include<conio.h>
#include<windows.h>
int main();
using namespace std;
struct node{
	int age;
	double amount;
	int account;
	int password;
     string fname;
     string lname;
     string address;
     string type;
     node *link;
};
node *head=NULL;
node *previous=NULL;
node *check=NULL;
node *save=NULL;
node *other=NULL;
void print(){
cout<<"************************************************************************************"<<endl;
cout<<"************************************************************************************"<<endl;
cout<<"******************";
cout<<"\t\t  BANK MANAGEMENT SYSTEM\t********************"<<endl;
cout<<"************************************************************************************"<<endl;
cout<<"************************************************************************************"<<endl;
cout<<endl;
   
}

class managar{
	private:
		
	void insertion();
	void view();
	void update();
	void search();
	void del();
	int acount;
	int choice;
	char ch;
	string pass="kamran",checkpass;
	public:	
	int n;
	void managr(){
	x:
	cout<<"ENTER PASSWORD : ";
	while(ch!='\r'){
		ch=getch();
		if(ch=='\r')
		{
			break;
		}
		cout<<"*";
		checkpass+=ch;
	}
	cout<<endl;
	if(checkpass==pass){
		cout<<"WELCOME "<<endl;
	}
	else{
		cout<<"TRY AGAIN..."<<endl;
		Sleep(300); 
		goto n;
	}
	xyz:
				system("cls");
			print();
	
	cout<<"PRESS 1 FOR INSERTION"<<endl;
	cout<<"PRESS 2 FOR UPDATE RECORD"<<endl;
	cout<<"PRESS 3 FOR SEARCH RECORD"<<endl;
	cout<<"PRESS 4 FOR DELETE ANY RECORD"<<endl;
	cout<<"PRESS 5 FOR VIEW RECORDS"<<endl;
	cout<<"press 6 For main Manue"<<endl;
	y:
	cout<<"YOUR CHOICE : ";
	cin>>choice;
	switch(choice){
		case 1:
   		insertion();
   	    goto xyz;
		   break;
	case 2:
		update();
		goto xyz;
		break;
	case 3:
		search();
		goto xyz;
		break;
	case 4:
		del();
		goto xyz;
		break;
	case 5:
		view();
		goto xyz;
		break;
	case 6:
		n:
	system("cls");
	main();
	break;
	 default:
	 	cout<<"wrong choice plz try again";
	 	goto y;
	    break;
	}
}

};
class user{
private:
void transfer();
	int amo;	
	int acount;
	int pass;
	int option;
public:	
	
	void usr(){
	if(head==NULL){
		system("cls");
		print();
		cout<<" \n \nsorry there is no acount yet";
		Sleep(1000);
		system("cls");
		main();
	}
	fahad:
		cout<<"PLEASE ENTER YOUR ACCOUNT NUMBER : ";
		cin>>acount;
		cout<<"PLEASE ENTER YOUR PASSWORD"<<endl;
		cout<<"PASSWORD : ";
		cin>>pass;
		check=head;
		while(check!=NULL){
			if(check->account==acount && check->password==pass)
			{
			cout<<"\n           ****YOU ARE A REGISTERED USER****"<<endl;
			system("pause");
			break;}
			else
			  {
			   cout<<"ACCESS DENIED"<<endl;
			   system("pause");
			   goto fahad;}
			   check=check->link;
		}
		save=check;
		cout<<endl;
		zyx:
	
			system("cls");
			print();
	cout<<"PRESS 1 FOR TRANSFER AMOUNT"<<endl;
	cout<<"PRESS 2 FOR WITHDARAW"<<endl;
	cout<<"PRESS 3 FOR VIEW balance"<<endl;
	cout<<"PRESS 4 ENTER PASSWORD"<<endl;
	cout<<"enter 5 for exit"<<endl;
	s:
	cout<<"YOUR CHOICE : ";
	cin>>option;
	switch(option){
		case 1:
        transfer();
        goto zyx;
		break;
		case 2:{
					system("cls");
			print();
	
			cout<<"enter amount you wanna withdraw :";
			cin>>amo;
			if(check->amount>=amo){
			
			check->amount=check->amount-amo;
			cout<<"congratulations you succesfull withdraw :"<<amo<<endl;
		}
		else
		cout<<"sorry you have no balance "<<endl;
		system("pause");
			goto zyx;
			break;
			
		}
	case 3:
				system("cls");
			print();
	
			cout<<"AMOUNT IN YOUR ACCOUNT iS: "<<save->amount<<endl;
			system("pause");
			goto zyx;
			break;
	case 4:
    {
    			system("cls");
			print();
	
	cout<<"enter new password :";
	cin>>check->password;
	cout<<"congratulation !!! your password changed ";
	system("pause");
	goto zyx;		
	   break;
	   }
	   case 5:
	   	system("cls");
	   main();
	   	break;
       default:
       	cout<<"you enter wrong choice plz enter correct";
       	goto s;
       	break;
	
}
}
};
void managar::insertion(){
	system("cls");
	print();
	   
node *newnode=new node;
		cout<<"\t\t******  Enter Following Information  *******"<<endl;
		cout<<"First Name : ";
		cin>>newnode->fname;
		cout<<"Last name : ";
		cin>>newnode->lname;
		cout<<"Age : ";
		cin>>newnode->age;
		cout<<"Address : ";
		cin>>newnode->address;
		dcba:
		cout<<"Acount Type : ";
		cin>>newnode->type;
		if(newnode->type!="saving" && newnode->type!="current")
		{
		cout<<"\nPlease Enter a valid account type"<<endl;
	    goto dcba;
		}
		cout<<"Password : ";
		cin>>newnode->password;
		cout<<endl;
		cout<<"Account No. : ";
		cin>>newnode->account;
		cout<<"Amount : ";
		cin>>newnode->amount;
		cout<<"\t\t******  Your Record has Been Inserted  ******"<<endl;
		system("pause");
		cout<<endl;
		newnode->link=NULL;
		if(head==NULL)
		{
			head=newnode;
			previous=head;
		}
		else
			{
			previous->link=newnode;
			previous=previous->link;
		}
	return;
}
void managar::view(){
	system("cls");
	print();   
	check=head;
	if(head==NULL){
	
	cout<<"NO RECORD"<<endl;
	system("pause");
	}	while(check!=NULL){
				cout<<"*****************************************************************************"<<endl;
	  		cout<<"\tNAME : "<<check->fname<<" "<<check->lname<<"\n\tAGE : "<<check->age<<"\n\tADDRESS : "<<check->address<<"\n\tACCOUNT TYPE : "<<check->type<<"\n\tAMMOUNT : "<<check->amount<<"\n\tACCOUNT NO. : "<<check->account<<endl;
	  		cout<<"*****************************************************************************"<<endl;
          check=check->link;
          system("pause");
}
}
void managar::update(){
	system("cls");
	print();   
		int che=0;
		int item1;
	cout<<"***** ENTER ANY ACCOUNT NO. TO UPDATE ***** "<<endl;
	cout<<"ACCOUNT NUMBER";
	cin>>item1;
	cout<<endl;	
	check=head;
	if(head=NULL)
	cout<<"  NO RECORD  "<<endl;
	cout<<endl;
	while(check!=NULL){
		
		if(check->account==item1){
			che=1;
			break;
			}
		check=check->link;
	}
	if(che==1){
		cout<<"ENTER YOU NEW RECORD : "<<endl;
		cout<<"First Name : ";
		cin>>check->fname;
		cout<<"Last name : ";
		cin>>check->lname;
		cout<<"Age : ";
		cin>>check->age;
		cout<<"Address : ";
		cin>>check->address;
		cout<<"Acount Type : ";
		cin>>check->type;
		cout<<"Password : ";
		cin>>check->password;
		cout<<endl;
		cout<<"Account No. : ";
		cin>>check->account;
		cout<<"Amount : ";
		cin>>check->amount;
		cout<<"\t\t****** YOUR RECORD HAS BEEN UPDATED  ******"<<endl;
		cout<<endl;
		system("pause");
   }
	else 
	cout<<"YOUR RECORD IS NOT FOUND"<<endl;	
	system("pause");
	cout<<endl;
}
void managar::del(){
	system("cls");
	print();   
	cout<<endl;
	int item1;
	cout<<"***** ENTER ANY ACCOUNT TO DELETE ***** "<<endl;
	cout<<"ACCOUNT NUMBER : ";
	cin>>item1;
	previous=head;
	check=previous->link;
	if(head->account==item1){
		head=head->link;
	}
	
	while(check!=NULL){
		if(check->account==item1){
			previous->link=check->link;
			break;
					}
		previous=check;
		check=check->link;
	}
	cout<<endl;
}	

void managar::search(){
	system("cls");
	print();   
		int che=0;
		int item1;
	cout<<"***** ENTER ANY RECORD TO SEARCH  ***** "<<endl;
	cout<<"ACCOUNT NUMBER";
	cin>>item1;
	cout<<endl;	
	check=head;
	if(head==NULL)
	cout<<"  NO RECORD  "<<endl;
	cout<<endl;
	while(check!=NULL){
		
		if(check->account==item1){
			che=1;
			break;
			}
		check=check->link;
	}
	if(che==1){
			cout<<"*****************************************************************************"<<endl;
	  		cout<<"\tNAME : "<<check->fname<<" "<<check->lname<<"\n\tAGE : "<<check->age<<"\n\tADDRESS : "<<check->address<<"\n\tACCOUNT TYPE : "<<check->type<<"\n\tAMMOUNT : "<<check->amount<<"\n\tACCOUNT NO. : "<<check->account<<endl;
	  		cout<<"*****************************************************************************"<<endl;
   system("pause");
   }
	else{
	
	cout<<"YOUR RECORD IS NOT FOUND ";
	system("pause");	
	}cout<<endl;
}	
void user::transfer(){
			system("cls");
			print();
	
	         fahad:
	         	int che;
	         	int am;
	         	int trans;
	         cout<<endl;
	         int a=0;
			cout<<"ENTER  ACCOUNT TO TRASFER: ";
			cin>>trans;
			cout<<"ENTER AMOUNT TO TRANSFER : ";
			cin>>am;
			other=head;
	while(other!=NULL){
		
		if(other->account==trans){
			che=1;
			break;
			}
		other=other->link;
	}
	if(che==1){
			if(save->amount>=am){
				save->amount-=am;
				other->amount+=am;
				cout<<"congartulation !!!! amount tranfer";
				system("pause");
			}
			else{
				cout<<"sorry amont not transfer";
				return;
			}
			
   }
	else 
	cout<<"YOUR RECORD IS NOT FOUND ";	
	return;
	cout<<endl;		   
		
	}

int main(){
	system("color 1b");
	int i;
	
	managar ob1;
user ob;
    		system("cls");
			print();
	
	cout<<"enter 1 for user"<<endl;
	cout<<"enter 2 for manager"<<endl;
	cout<<"enter 3 for exit"<<endl;
	gh:
	cout<<"enter your choice  :";
	cin>>i;
	switch(i){
		case 1:
		ob.usr();
		break;
		case 2:
		ob1.managr();
		case 3:
		exit(0);
		break;
		default:
		cout<<"you enter wrong choice :";
		goto gh;
	}
	
}
