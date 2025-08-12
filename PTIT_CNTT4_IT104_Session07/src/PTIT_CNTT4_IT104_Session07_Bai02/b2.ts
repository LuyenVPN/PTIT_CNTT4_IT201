class Vehicle{
    protected  name:string
    protected speed:number
    protected id:number
    constructor(name:string,speed: number,id:number) {
        this.name=name
        this.speed=speed
        this.id=id
    }
    slowDownn(tocdo: number):void{
        this.speed-=tocdo
        if(this.speed<0){
            this.speed=0
        }
    }
    speedUp(tocdo:number):void{
        this.speed+=tocdo
    }
    showSpeed():void{
        console.log(`toc do hien tai ${this.speed}`);
    }
}
class Bicycle extends Vehicle{
    private gear:number
     constructor(name:string,speed: number,id:number,gear:number) {
        super(name,speed,id)
        this.gear=gear
    }
    showInfo():void{
        console.log(`Name: ${this.name}`);
        console.log(`Speed: ${this.speed}`);
        console.log(`Id: ${this.id}`);
        console.log(`Gear: ${this.gear}`);
    }
}
let xe1= new Vehicle("Camry",30,1)
xe1.showSpeed()
xe1.speedUp(10)
xe1.showSpeed()
xe1.slowDownn(5)
xe1.showSpeed()
let xe=new Bicycle("Honda",55,2,5)
xe.showInfo()