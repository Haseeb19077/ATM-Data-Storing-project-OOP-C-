//============================================   SEMESTER FINAL PROJECT   ============================================

#include <iostream>
#include <string>
#include <stdlib.h>                             //Haseeb Aslam
#include <fstream>                              //FA19-BEE-077


using namespace std;

//---------------   PARENT / BASE CLASS    ---------------

class Account
{
public:
	string accountTitle;
	string accountNumber;
	string CNIC;
	double amountDeposit;
	string openingDate;
};

//---------------   CHILD / DERIVED CLASS   ---------------

class Current : public Account
{
public:
	string accountType;
	float minimumBalance;
public:
	string AccountType()
	{
		return accountType = "current";
	}
	double MinimumBalance()
	{
		return minimumBalance = 20000;
	}
};

//---------------    CHILD / DERIVED CLASS    ---------------

class Saving : public Account
{
public:
	string accountType;
	float interestRate;
public:
	string AccountType()
	{
		return accountType = "saving";
	}
	double InterestRate()
	{
		return interestRate = 94/1000;
	}
};

//===========================   ---------------    FUNCTIONS    ---------------    ==============================



//---------------    FUNCTION TO CONVERT THE CLASS VARIABLES FROM STRING TO INT    ---------------

void StringToUnsignedLong(unsigned long &account_number, unsigned long &user_CNIC,Account &a)
	{
		
		account_number = strtoul(a.accountNumber.c_str(),NULL,0);
		user_CNIC = strtoul(a.CNIC.c_str(),NULL,0);

	}

//---------------   FUMCTION TO CHECK , WHETHER THE ACCOUNT WILL BE "CURRENT" OR "SAVING" BY COMPARING IT WITH THE MINIMUM BALANCE    ---------------

string CurrentOrSaving(double initialDeposit)
{
	Current account_current;
	if (initialDeposit >= account_current.MinimumBalance())
	{
		
		return account_current.AccountType();
	
	}
	else
	{
		Saving account;
		return account.AccountType();
	}
}


//---------------    MAIN ( THE ENTERY / STARTING POINT OF THE PROGRAM )    ---------------

int main()
{
	Account a;
	unsigned long account_number;
	unsigned long user_CNIC;

	cout<<"             =============================    WELCOME TO OUR ACCOUNT DEPARTMENT    =============================="<<endl;


//---------------    GETTING DATA FROM USER    ---------------

	cout<<"Please enter the account title"<<endl;
	cin>>a.accountTitle;

	cout<<"Please enter the account number"<<endl;
	cin>>a.accountNumber;
	
	cout<<"Please enter the CNIC"<<endl;
	cin>>a.CNIC;

	cout<<"Please enter the amount deposited"<<endl;
	cin>>a.amountDeposit;

	cout<<"Please enter the opening date"<<endl;
	cin>>a.openingDate;

	StringToUnsignedLong(account_number,user_CNIC,a);
	system("CLS");

	cout<<endl<<endl;

//---------------    WRITING DATA INPUT BY USER TO FILE    ---------------

	ofstream writeData;
	cout<<"Opening file and writing data ..."<<endl;
	writeData.open("account Detail.txt", ios::out);

	writeData<<a.accountTitle<<",";
	writeData<<account_number<<",";
	writeData<<user_CNIC<<",";
	writeData<<a.amountDeposit<<",";
	writeData<<a.openingDate<<",";
	writeData<<CurrentOrSaving(a.amountDeposit)<<"\n";

	writeData.close();
	cout<<endl<<endl;


//---------------    READING DATA FROM FILE, ENTERED BY USER    ---------------

	cout<<"Now reading data from the file."<<endl;
	fstream readData;
	readData.open("account Detail.txt", ios::in);

	string line;
	if (CurrentOrSaving(a.amountDeposit) == "current")
	{
		while (readData >> line)
		{
			cout<<line<<endl;
		}
	}
	else
	{
		double interest_rate;
		while (readData >> line)
		{
			cout<<line<<endl;
		}
		cout<<endl;
		Saving s;
		cout<<endl;
		cout<<"Interest Rate:"<<endl<<endl;
		
		interest_rate = s.interestRate * 3;
		cout<<"Three month interest rate is: "<<interest_rate<<endl;
	
		interest_rate = s.interestRate * 12;
		cout<<"Per annum interest rate is: "<<interest_rate<<endl;
	}

	readData.close();
	cout<<endl<<endl;

	cout<<"==========  Thank you for using our account department's service :)"<<endl;
}
