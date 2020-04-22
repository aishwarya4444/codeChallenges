public class Account {

  private String accountNumber;
  private static int id = 1;
  private String accountType;
  private double amount = 0;

  public Account(String accType) {
    this.accountType = accType;
  }

  public String getAccountNumber() {
    return this.accountNumber;
  }

  public void setAccountNumber(String accNo) {
    this.accountNumber = accNo;
  }

  public double getAmount() {
    return this.amount;
  }

  public void setAmount(double amount) {
    this.amount = amount;
  }
}