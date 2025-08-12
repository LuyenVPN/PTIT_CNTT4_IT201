class Account {
  id: number;
  userName: string;
  private password: string;
  isLogin: boolean;
  role: string;
  constructor(id: number,userName: string,password: string,isLogin: boolean,role: string) {
    this.id = id;
    this.userName = userName;
    this.password = password;
    this.isLogin = isLogin;
    this.role = role;
  }
  login():void{
   if(this.isLogin){
     console.log("Dang nhap thanh cong");
   }else{
     console.log("Dang nhap that bat");
   }
  }
  logout():void{
    if(this.isLogin){
     console.log("Dang xuat thanh cong");
     this.isLogin=false
   }
  }
}
class userAcc extends Account{
    status:string
    constructor(id: number,userName: string,password: string,isLogin: boolean,role: string,status:string) {
        super(id,userName,password,isLogin,role)
        this.status=status
  }
   login():void{
   if(this.status==="active"){
     console.log("Dang nhap thanh cong");
     this.isLogin=true
   }else if(this.status==="banned"){
     console.log("Tai khoan bi khoa");
   }else{
    console.log("khong hop le");
   }
  }
}
let user1=new userAcc(1,"Luyen","abc",true,"admin","active")
let user2=new userAcc(1,"Lum","abc",true,"user","banned")
user1.login()
user1.logout()
user2.login()
user2.logout()