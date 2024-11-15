#include<bits/stdc++.h>
using namespace std;
struct Wood {
    string type;
    double size;
    int age;
    Wood(string t, double s, int a) : type(t), size(s), age(a) {}
};

//dem so luong go cung tuoi
int sameAge(stack<Wood> s, int selectAge) {
    int count = 0;
    // su dung stack temp de duyet de khong lam thay doi stack ban dau
    stack<Wood> temp;
    while (!s.empty()) {
        if (s.top().age == selectAge) { //kiem tra tuoi go co bang tuoi chon khong
            count++;
        }
        temp.push(s.top()); // day thanh go vao stack temp
        s.pop(); // xoa thanh go khoi stack goc
    }
    // khoi phuc stack goc tu stack temp
    while (!temp.empty()) {
        s.push(temp.top()); // day thanh go tu stack tam vao stack goc
        temp.pop(); //xoa thanh go khoi stack tam
    }
    return count;
}

int main() {
    stack<Wood> woodStack; //tao stack
    char choice; // bien lua chon cua nguoi dung

    do { //do while de nhap lien tuc
        string type;
        double size;
        int age;

        cout << "Nhap loai: ";
        cin >> type;
        cout << "Nhap kich thuoc(m): ";
        cin >> size;
        cout << "Nhap tuoi(nam): ";
        cin >> age;
        woodStack.push(Wood(type, size, age));//day thong tin vao stack
        cout << "Ban muon nhap tiep hay khong?(y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // lap neu nguoi dung chon 'y'
    int selectAge;
    cout << "Nhap tuoi ma ban muon dem so luong go: ";
    cin >> selectAge; // nhap tuoi can dem
    int count;
    count = sameAge(woodStack, selectAge);
    cout << "So luong thanh go co tuoi " << selectAge << "la: " << count << endl;
    cout << "\nDanh sach cac thanh go trong kho:\n";
    stack<Wood> displayStack = woodStack; // tao ban sao stack de hien thi
    while (!displayStack.empty()) { // lap den khi stack rong
        Wood w = displayStack.top(); // lay thanh go o dinh stack
        cout << "Loai: " << w.type << ", Kich thuoc: " << w.size << "m, Tuoi: " << w.age << " nam\n";
        displayStack.pop(); //xoa wood khoi stack hien thi
    }
}
