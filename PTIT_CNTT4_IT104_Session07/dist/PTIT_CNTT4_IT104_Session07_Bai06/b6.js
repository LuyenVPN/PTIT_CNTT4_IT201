"use strict";
class _Account {
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
class _userAcc extends _Account {
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
class adminAcc extends _Account {
    banUser(user) {
        user.status = "banned";
    }
}
let user = new _userAcc(1, "Hup", "abc", true, "user", "active");
let admin = new adminAcc(28, "Luyen", "abc", true, "admin");
user.login();
admin.banUser(user);
user.login();
