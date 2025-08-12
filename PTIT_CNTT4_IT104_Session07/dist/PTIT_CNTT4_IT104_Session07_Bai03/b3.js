"use strict";
class Animal {
    constructor(name) {
        this.name = name;
    }
    printName() {
        console.log(`ten: ${this.name}`);
    }
}
class Dog extends Animal {
    makeNoise() {
        console.log("gau gau");
    }
}
class Cat extends Animal {
    makeNoise() {
        console.log("meo meo");
    }
}
let dog = new Dog("cho");
dog.printName();
dog.makeNoise();
let cat = new Cat("meo");
cat.printName();
cat.makeNoise();
