"use strict";
class _$Account {
    constructor(accountNumber, balance, status) {
        this.accountNumber = accountNumber;
        this.balance = balance;
        this.status = status;
        this.history = [];
    }
    deposit(amount) {
        if (amount < 0) {
            console.log("So tien nap khong hop le");
            return;
        }
        if (this.status === "band") {
            console.log("tai khoan bi cam");
            return;
        }
        else {
            this.balance += amount;
            console.log(`Nap: +${amount}`);
            this.history.push(`So tien nap: +${amount} | So du hien tai: ${this.balance}`);
        }
        console.log(`So du hien tai la: ${this.balance}`);
    }
    withdraw(amount) {
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
        }
        else {
            this.balance -= amount;
            console.log(`Rut: -${amount}`);
            this.history.push(`So tien rut: -${amount} | So du hien tai: ${this.balance}`);
        }
    }
    showHistory() {
        if (this.history.length === 0) {
            console.log("Chua co giao dich");
            return;
        }
        this.history.forEach((e) => {
            console.log(e);
        });
    }
}
class CheckingAccount extends _$Account {
    constructor(accountNumber, balance, status, overdraftLimit) {
        super(accountNumber, balance, status);
        this.overdraftLimit = overdraftLimit;
    }
    withdraw(amount) {
        if (amount < 0) {
            console.log("So tien nap khong hop le");
            return;
        }
        const available = this.balance + this.overdraftLimit;
        if (amount > available) {
            console.log(`Vuot qua han muc rut`);
            return;
        }
        if (this.status === "band") {
            console.log("tai khoan bi cam");
            return;
        }
        else {
            this.balance -= amount;
            console.log(`Rut: -${amount}`);
            this.history.push(`So tien rut: -${amount} | So du hien tai: ${this.balance}`);
        }
    }
}
const tk3 = new CheckingAccount("123456789", 1000, "active", 500);
tk3.showHistory();
tk3.withdraw(400);
tk3.withdraw(1200);
tk3.withdraw(750);
tk3.showHistory();
