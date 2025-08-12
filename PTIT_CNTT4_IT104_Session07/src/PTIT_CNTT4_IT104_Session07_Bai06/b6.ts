class _Account {
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
class _userAcc extends _Account{
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
class adminAcc extends _Account{
    banUser(user:_userAcc):void{
        user.status="banned"
    }
}
let user=new _userAcc(1,"Hup","abc",true,"user","active")
let admin=new adminAcc(28,"Luyen","abc",true,"admin")
user.login()
admin.banUser(user)
user.login()
