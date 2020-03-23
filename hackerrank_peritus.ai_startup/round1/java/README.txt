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
