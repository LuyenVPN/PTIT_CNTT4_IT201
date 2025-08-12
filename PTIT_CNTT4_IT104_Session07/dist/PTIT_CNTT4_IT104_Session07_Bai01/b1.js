"use strict";
class Employee {
    constructor(name, company, phone) {
        this.name = name;
        this.company = company;
        this.phone = phone;
    }
    getInfo() {
        console.log(`Ten: ${this.name}\n Company: ${this.company} \n Phone: ${this.phone}`);
    }
}
class Manager extends Employee {
    constructor(name, company, phone, teamSize) {
        super(name, company, phone);
        this.teamSize = teamSize;
    }
    getInfo() {
        super.getInfo();
        console.log(`So luong thanh vien: ${this.teamSize}`);
    }
}
let emp = new Employee("Luyen", "Abc", "0123456789");
emp.getInfo();
let mage = new Manager("Luyen", "Abc", "0123456789", 10);
mage.getInfo();
