/*
1. Create a Bank class that supports multiple accounts
2. The account numbers are identified with a 'String' account number.
   All the top-level methods will work with 'String' account number.
3. Features:
   a. Transfer money into an account. If the account does not exist,
      then we create an account with the given account number.
      This is also the way to create new accounts.
        `deposit(accountNumber, amount)`
   b. Withdraw money out of an account.
        `withdraw(accountNumber, amount)`
   c. Transfer money between two accounts.
        `transfer(fromAccountNumber, toAccountNumber, amount)`
   d. Check the total amount of money in the Bank
      cumulative of all the accounts.
        `getTotalMoneyInBank()`
4. Restrictions:
   a. An account cannot have more than $10,000,000.00
   b. We do not support overdraft, so an account cannot have a negative amount at any point in time.

*/

public class Bank {
  // check syntax for array
  // or store in map for quick search

  unordered_map<String, Account> accounts;

  private List<Account> accounts;
  private String address; // Address can be abstracted out to a separate class
  private String name;

  public Bank(String name, String address) {
    this.name = name;
    this.address = address;
  }

  public double getTotalMoney() {
    double totalMoney = 0;

    for(Account acc: accounts) {
      totalMoney += acc.getAmount();
    }

    return totalMoney;
  }

  protected Account getAccountInstance(String account) {
    for(Account acc: accounts) {
      // check syntax for comparing strings
      if(acc.getAccountNumber() == account) {
        return acc;
      }
    }
    // throw an error that account does not exists
  }

  public boolean deposit(String accNum, double money) {
    Account acc = getAccountInstance(accNum);

    // if account does not exist .. catch error and do not transfer amount .. return false

    double amount = acc.getAmount();

    if(isAmountTransferPossible(amount + money)) {
      updateBalance(acc, amount+money);
      // log here
      return true;
    }

    return false;
  }

  public boolean withdraw(String accNum, double money) {
    Account acc = getAccountInstance(accNum);

    // if account does not exist .. catch error and do not transfer amount .. return false

    double amount = acc.getAmount();

    if(isAmountTransferPossible(amount - money)) {
      updateBalance(acc, amount-money);
      // log here
      return true;
    }

    return false;
  }

  public boolean transfer(String accNum1, String accNum2, double amount) {
    Account acc1 = getAccountInstance(accNum1),
      acc2 = getAccountInstance(accNum2);

    // if any account does not exist .. catch error and do not transfer amount .. return false

    double amount1 = acc1.getAmount(),
      amount2 = acc2.getAmount();

    if(!isAmountTransferPossible(amount1-amount) || !isAmountTransferPossible(amount2+amount)) {
      // log or throw an error
      return false;
    }

    updateBalance(acc1, amount1-amount);
    updateBalance(acc2, amount2+amount);
    // if both transactions are success only then return true .. else rollback

    // log that amount was transferred correctly
    return true;

  }

  protected boolean updateBalance(Account acc, double amount) {
    try {
      acc.setAmount(amount);
    } catch (...) {
      // log error
      return false;
    }
    return true;
  }

  public boolean isAmountTransferPossible(int netAmount) {
    if(netAmount <= AccountLimits.MIN_AMOUNT || netAmount > AccountLimits.MAX_AMOUNT) {
      return false;
    }
    return true;
  }
}
