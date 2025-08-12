abstract class Person{
    name:string
    constructor(name:string) {
        this.name=name
    }
    displayInfo():void{
        console.log(`Name: ${this.name}`);
    }
}
class Student extends Person{
    id:number
    constructor(name:string,id:number) {
        super(name)
        this.id=id
    }
    // override
    displayInfo(): void {
        console.log(`${this.id}. ${this.name}`);
    }
}
class Teacher extends Person{
    subject:string
    constructor(name:string,subject:string) {
        super(name)
        this.subject=subject
    }
    // override
    displayInfo(): void {
        console.log(`${this.name} --- ${this.subject}`);
    }
}
let sv1= new Student("luyen",1)
sv1.displayInfo()
let gv1= new Teacher("Hu Giang", "Khong lam ma doi co an")
gv1.displayInfo()