abstract class Animal {
    name:string
    constructor(name:string) {
        this.name=name
    }
    abstract makeNoise():void
    printName():void{
        console.log(`ten: ${this.name}`);
    }
}
class Dog extends Animal{
    makeNoise(): void {
        console.log("gau gau");
    }
}
class Cat extends Animal{
    makeNoise(): void {
        console.log("meo meo");
    }
}
let dog=new Dog("cho")
dog.printName()
dog.makeNoise()
let cat=new Cat("meo")
cat.printName()
cat.makeNoise()