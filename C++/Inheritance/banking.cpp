#include "banking.h"

namespace Banking
{
	double Account::Balance() const
	{
		return balance;
	}

	void Account::Transfer(double amount, Account* that) throw(InsufficientFunds)
	{
		if(this != that)
		{
			this->Withdraw(amount);
			that->Deposit(amount);
		}
	}

	class CurrentAccount : public Account
	{
	public:
		CurrentAccount()
		{
			balance = 0;
		}

		void Deposit(double amount)
		{
			if(balance < 0)
				amount *= 0.9;
			balance += amount;
		}

		void Withdraw(double amount) throw(InsufficientFunds)
		{
			balance -= amount;
		}

	};

	//Multiple inheritance (MI)
	class SavingsAccount : public Account, public Profitable
	{
	public:
		SavingsAccount()
		{
			balance = 5000;
		}

		void Deposit(double amount)
		{
			balance += amount;
		}

		void Withdraw(double amount) throw(InsufficientFunds)
		{
			if(balance - amount < 5000)
				throw InsufficientFunds();
			balance -= amount;
		}

		double Interest(short months) const
		{
			float rate = balance < 25000 ? 4 : 5;
			return balance * months * rate / 1200;
		}
	};

	Account* OpenCurrentAccount()
	{
		return new CurrentAccount;
	}

	Account* OpenSavingsAccount()
	{	
		return new SavingsAccount;
	}

	void CloseAccount(Account* acc)
	{
		delete acc;
	}
}

