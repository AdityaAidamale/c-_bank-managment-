#include <iostream>
#include <vector>

class BankAccount {
private:
    std::string name;
    int accountNumber;
    double balance;

public:
    BankAccount(std::string name, int accountNumber, double initialDeposit) : name(name), accountNumber(accountNumber), balance(initialDeposit) {}

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance.\n";
            return false;
        }
        balance -= amount;
        return true;
    }

    void display() const {
        std::cout << "Account Name: " << name << "\nAccount Number: " << accountNumber << "\nBalance: $" << balance << std::endl;
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    void addAccount(const BankAccount& account) {
        accounts.push_back(account);
    }

    void depositToAccount(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.deposit(amount);
                std::cout << "Deposited $" << amount << " to account number " << accountNumber << std::endl;
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void withdrawFromAccount(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                if (account.withdraw(amount)) {
                    std::cout << "Withdrew $" << amount << " from account number " << accountNumber << std::endl;
                }
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void showAccountDetails(int accountNumber) const {
        for (const auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                account.display();
                return;
            }
        }
        std::cout << "Account not found.\n";
    }
};

int main() {
    Bank myBank;
    myBank.addAccount(BankAccount("John Doe", 123456, 500.0));
    myBank.depositToAccount(123456, 200.0);
    myBank.withdrawFromAccount(123456, 100.0);
    myBank.showAccountDetails(123456);

    return 0;
}
