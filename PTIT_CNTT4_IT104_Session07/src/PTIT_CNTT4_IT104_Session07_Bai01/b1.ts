class Employee{
    name:string
    private company: string
    private phone: string
    constructor(name:string, company:string, phone: string){
        this.name=name
        this.company=company
        this.phone=phone
    }
    getInfo():void{
        console.log(`Ten: ${this.name}\n Company: ${this.company} \n Phone: ${this.phone}`);
        
    }
}
class Manager extends Employee{
    teamSize:number
    constructor(name:string, company:string, phone: string, teamSize:number){
        super(name,company,phone)
        this.teamSize=teamSize
    }
    getInfo(): void {
        super.getInfo()
        console.log(`So luong thanh vien: ${this.teamSize}`);
    }
}
let emp= new Employee("Luyen","Abc","0123456789")
emp.getInfo()
let mage= new Manager("Luyen","Abc","0123456789",10)
mage.getInfo()