"use strict";
class Account {
    constructor(id, userName, password, isLogin, role) {
        this.id = id;
        this.userName = userName;
        this.password = password;
        this.isLogin = isLogin;
        this.role = role;
    }
    login() {
        if (this.isLogin) {
            console.log("Dang nhap thanh cong");
        }
        else {
            console.log("Dang nhap that bat");
        }
    }
    logout() {
        if (this.isLogin) {
            console.log("Dang xuat thanh cong");
            this.isLogin = false;
        }
    }
}
class userAcc extends Account {
    constructor(id, userName, password, isLogin, role, status) {
        super(id, userName, password, isLogin, role);
        this.status = status;
    }
    login() {
        if (this.status === "active") {
            console.log("Dang nhap thanh cong");
            this.isLogin = true;
        }
        else if (this.status === "banned") {
            console.log("Tai khoan bi khoa");
        }
        else {
            console.log("khong hop le");
        }
    }
}
let user1 = new userAcc(1, "Luyen", "abc", true, "admin", "active");
let user2 = new userAcc(1, "Lum", "abc", true, "user", "banned");
user1.login();
user1.logout();
user2.login();
user2.logout();
