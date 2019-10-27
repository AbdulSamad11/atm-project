#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class Bank
{
public:
	int code;
	string name, address;
	Bank()
	{
		code = 56567;
		name = "HBL";
		address = "26 street mumtazabad multan";
	}
	void showDetails()
	{
		cout <<"Bank code is: " <<code << endl << "Bank name is:  " << name << endl <<"Address of bank is: "
                     << address << endl;
	}
	void startMenu()
	{
		cout << "\n\t\t\t***WELCOME TO OUR ATM SYSTEM***" << endl;
		cout << "\n\nPRESS to login as\n1-ADMIN " << endl;
		cout << "2-USER" << endl;

	}
	void adminMenu()
	{
		system("cls");
		cout << "1-Add customer" << endl;
		cout << "2-Current Customer details" << endl;
		cout << "3-My details" << endl;
		cout << "4-Bank Details" << endl;
		cout << "5-Load Customers" << endl;
		cout << "6-Return to Main Menu" << endl;
	}
	void userMenu()
	{
		system("cls");
		cout << "1-Deposit Amount" << endl;
		cout << "2-Withdraw Amount" << endl;
		cout << "3-Check balance" << endl;
		cout << "4-My information" << endl;
		cout << "5-Bank Information" << endl;
		cout << "6-Admin Info" << endl;
	}
	bool password(string pass)
	{
		string password = "pak";
		if (pass.compare(password) == 0)
			return true;
		else
			return false;
	}

}bank;


class debitCard
{
public:
	double accountNo;
	int pin, n;
	debitCard(int Pin) {
		pin = Pin;
	}
	debitCard(double accountNo, int pin) {

		this->accountNo = accountNo;
		this->pin = pin;
		n = 20;
		if (n > 20)
			n = 0;
	}
	bool VerifyPin(int Pin)
	{
		return (pin == Pin);
	}
}card(0000);

class Transaction
{
public:
	static int amount;
	double accountNo;
	string type;
	string date;
	int pin;
	Transaction(){ date = "15-6-2000"; }
	Transaction(double accountNo, string type, int pin)
	{
		this->accountNo = accountNo;
		this->type = type;
		this->pin = pin;
		
	}
};

int Transaction::amount = 0;

class WithdrawAmount :public Transaction
{
public:
	 bool Withdraw(int am)
	{
		if ((amount - am) < 0)
		{
			cout << "insufficient balance" << endl;
			system("pause");
			return false;
		}
		else {
			amount = amount - am; return true;
		}
	}
}withdraw;

class DepositAmount :public Transaction
{
public:
	 void Deposit(int am)
	{
		amount = amount + am;
	}
}deposit;

class Customer
{
public:
	int user;
	string name, type;
	double accountNo;
	
	

	Customer(string name, double accountNo, string type)
	{
		this->name = name;
		this->accountNo = accountNo;
		this->type = type;
	}
	bool loadCustomers()
	{
		char ch;
		ifstream read;
		read.open("customers.txt");
		while (!read.eof())
		{
			ch = read.get();
			cout << ch;
		}
		read.close();
		return true;
	}
	void Details()
	{
		cout << "Name: " << name << endl;
		cout << "Account No: " << accountNo << endl;
		cout << "Type: " << type << endl;
		cout <<"Your available balance is: " <<Transaction::amount << endl;
	}

}customer("Ali",193221,"current");     

class Account
{
public:
	string type, owner;
	double accountNo;


	Account(string type, string owner, double accountNo)
	{
		this->accountNo = accountNo;
		this->type = type;
		this->owner = owner;
	}
	void checkBalance()
	{
		cout << "Name: " << owner << endl;
		cout << "Account no. " << accountNo << endl;
		cout << "Your available balance is: " << Transaction::amount << endl;
	}
}account("null","no",0);

class Admin
{
public:
	string Name, email,line;
	int user;
	Customer *c[20];
	debitCard *d[20];
	Account *account[20];
	Transaction *t[20];
	ofstream write;
	Admin()
	{
		Name = "Abdul Samad";
		email = "asasamad11@gmail.com";
		user = 0;
	}
	bool addCustomer(string name, double accountNo, string type, int pin)
	{

		if (user < 20) {
			c[user] = new Customer(name, accountNo, type);
			while ((!write.eof()))
			{
				write.open("customers.txt",ios::app);
				write << name << " " << type << " " << accountNo << "." << endl;
				write.close();
				return true;
			}
			account[user] = new Account(type, name, accountNo);  //account no gain for other class			
			d[user] = new debitCard(accountNo, pin);  //pin
			t[user] = new Transaction(accountNo, type, pin);
			user++;
			return true;
		}
		return false;
	}
	void details()
	{
		cout << "Name: " << Name << endl;
		cout << "Email: " << email << endl;
		cout << "Customers added: " << user << endl;
	}

}admin;

int main()
{
	int option,Pin, optionAd,am;
	string pass,Type,Name,transop;
	double AccountNo;
	bool result;
	start:
	bank.startMenu();
	cin >> option;
	system("cls");
	if (option == 1)
	{
		cout << "enter password" << endl;
		back:
		cin >> pass;
		result=bank.password(pass);
		if (result == false) {
			cout << "wrong password" << endl;
			goto back;
		}cus:
		bank.adminMenu();
		cin >> optionAd;
		switch (optionAd)
		{
		case 1:system("cls");
			cout << "PLEASE ENTER DETAILS TO ALLOCATE: " << endl;
			cout << "NAME" << endl;
			cin >> Name;
			cout << "ACCOUNT NO." << endl;
			cin >> AccountNo;
			cout << "TYPE" << endl;
			cin >> Type;
			cout << "PIN" << endl;
			cin >> Pin;
			admin.addCustomer(Name, AccountNo, Type, Pin);
			cout << "Customer added successfully\n" << endl;
			system("pause");
			goto cus;
			break;
		case 2:
			customer.Details();
			system("pause");
			goto cus;
			break;
		case 3:
			admin.details();
			system("pause");
			goto cus;
			break;
		case 4:
			bank.showDetails();
			system("pause");
			goto cus;
			break;
		case 5:
			customer.loadCustomers();
			system("pause");
			goto cus;
		case 6:
			goto start;
			system("cls");
			break;
		default:cin.clear();
			cin.ignore();
			cout << "Invalid input" << endl;
			system("pause");
			goto cus;
			break;
		}
	}
	if (option == 2)
	{
	pinn:
		cout << "enter secret pin" << endl;
		cin >> Pin;
		result = card.VerifyPin(Pin);
		if (result == false)
			goto pinn;
		else {
		now:
			system("cls");
			bank.userMenu();
			cin >> optionAd;
			switch (optionAd)
			{
			case 1:
				cout << "Enter amount to deposit" << endl;
				cin >> am;
				deposit.Deposit(am);
				goto now;
				break;
			case 2:
				cout << "Enter amount to withdraw" << endl;
				cin >> am;
				withdraw.Withdraw(am);
				goto now;
				break;
			case 3:
				account.checkBalance();
				system("pause");
				goto now;
				break;
			case 4:
				customer.Details();
				system("pause");
				goto now;
				break;
			case 5:
				bank.showDetails();
				system("pause");
				goto now;
				break;
			case 6:
				admin.details();
				system("pause");
				goto now;
				break;
			default:
				cin.clear();
				cin.ignore();
				cout << "invalid input" << endl;
				system("pause");
				goto now;
				break;
			}
		}
	}
	system("pause"); //this is only for vs code
	return 0;
}
/*
author
  abdul samad
	uetian 2018 session
*/