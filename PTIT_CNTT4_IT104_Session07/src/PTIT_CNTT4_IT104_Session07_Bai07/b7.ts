class $Account {
  accountNumber: string;
  protected balance: number;
  protected history: string[];
  protected status: string;
  constructor(accountNumber: string, balance: number, status: string) {
    this.accountNumber = accountNumber;
    this.balance = balance;
    this.status = status;
    this.history = [];
  }
  deposit(amount: number): void {
    if (amount < 0) {
      console.log("So tien nap khong hop le");
      return;
    }
    if (this.status === "band") {
      console.log("tai khoan bi cam");
      return;
    } else {
      this.balance += amount;
      console.log(`Nap: +${amount}`);
      this.history.push(
        `So tien nap: +${amount} | So du hien tai: ${this.balance}`
      );
    }
    console.log(`So du hien tai la: ${this.balance}`);
  }
  withdraw(amount: number): void {
    if (amount < 0) {
      console.log("So tien nap khong hop le");
      return;
    }
    if (this.balance === 0 || this.balance < amount) {
      console.log("So du khong du");
      return;
    }
    if (this.status === "band") {
      console.log("tai khoan bi cam");
      return;
    } else {
      this.balance -= amount;
      console.log(`Rut: -${amount}`);
      this.history.push(
        `So tien rut: -${amount} | So du hien tai: ${this.balance}`
      );
    }
  }
  showHistory(): void {
    if(this.history.length===0){
        console.log("Chua co giao dich");
        return;
    }
    this.history.forEach((e) => {
      console.log(e);
    });
  }
}
class SavingAccount extends $Account {
  private interestRate: number;
  constructor(
    accountNumber: string,
    balance: number,
    status: string,
    interestRate: number
  ) {
    super(accountNumber, balance, status);
    this.interestRate = interestRate;
  }
  withdraw(amount: number): void {
    if (amount < 0) {
      console.log("So tien nap khong hop le");
      return;
    }
    if (this.balance === 0 || this.balance < amount) {
      console.log("So du khong du");
      return;
    }
    if (this.status === "band") {
      console.log("tai khoan bi cam");
      return;
    } else {
      this.balance -= amount;
      console.log(`Rut tien tiet kiem: -${amount}`);
      this.history.push(
        `----------------\nTai khoan tiet kiem: \n So tien rut: -${amount} | So du tiet kiem hien tai: ${this.balance}`
      );
    }
  }
}
let tk1= new $Account("226688",1000,"active")
tk1.showHistory()
tk1.withdraw(500)
tk1.showHistory()
tk1.deposit(500)
tk1.withdraw(2000)
let tk2= new SavingAccount("123456789",1000,"active",20)
tk2.showHistory()
tk2.withdraw(500)
tk2.showHistory()
tk2.withdraw(600)