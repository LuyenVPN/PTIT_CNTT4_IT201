"use strict";
class Person {
    constructor(name) {
        this.name = name;
    }
    displayInfo() {
        console.log(`Name: ${this.name}`);
    }
}
class Student extends Person {
    constructor(name, id) {
        super(name);
        this.id = id;
    }
    // override
    displayInfo() {
        console.log(`${this.id}. ${this.name}`);
    }
}
class Teacher extends Person {
    constructor(name, subject) {
        super(name);
        this.subject = subject;
    }
    // override
    displayInfo() {
        console.log(`${this.name} --- ${this.subject}`);
    }
}
let sv1 = new Student("luyen", 1);
sv1.displayInfo();
let gv1 = new Teacher("Hu Giang", "Khong lam ma doi co an");
gv1.displayInfo();
