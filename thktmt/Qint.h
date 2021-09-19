#pragma once
#include "string"
#include <fstream>
#include <iostream>
using namespace std;
#define numberofbyte 16

class Qint
{
private:
	int data[numberofbyte / 4];//Day bit
	int getBit(int);//Lay bit tai vi tri i
	void turnOn(int);//Change bit i to 1
	void turnOff(int);//Change bit i to 0

public:
	friend class Qfloat;
	void printBin();//In day bit
	string shortenBin_group4bit();//In day bit loai bo cac so 0 dung dau
	string shortenBin();//In day bit loai bo cac so 0 dung dau, khong co group by 4
	//char *BinToHex(bool *bit);//Bin to Hex
	//char *DecToHex(Qint x);//Qint to hex

	Qint(string);//string day so gan cho Qint
	Qint();//constructor gia tri mac dinh = 0

	//bool *getBin();//Tra ve day bit duoi dang bool
	string toDec();//Tra ve string trong he 10
	//void setBin(bool *);

	//Cac operator
	Qint operator+(Qint x);
	Qint operator-(Qint x); //prefix, lay bu 2
	Qint operator-();
	Qint operator*(Qint x);
	Qint operator/(Qint x);

	bool operator<(Qint x);
	bool operator>(Qint x);
	bool operator<=(Qint x);
	bool operator>=(Qint x);
	bool operator==(Qint x);
	Qint &operator=(Qint x);

	Qint operator&(Qint x);
	Qint operator|(Qint x);
	Qint operator^(Qint x);
	Qint operator~();

	bool isNegative();//So duong hay so am

	Qint operator<<(int);
	Qint operator>>(int);

	Qint rol(int d);//xoay trai
	Qint ror(int d);//xoay phai

	friend string QintToStringUnsigned(Qint);//Tra ve string decimal. Luu y: Chi tra ve so duong
	friend bool* DecToBin(Qint x);
	friend Qint BinToDec(bool* bit);
	friend char* DecToHex(Qint x);
	Qint multiplySignificandQfloat(Qint); //Ham ho tro nhan phan tri cua 2 Qfloat, khong dung operator do tran so
	Qint divideSignificandQfloat(Qint, Qint&); //Ham ho tro chia phan tri cua 2 Qfloat
};

////////////////////////
//Ham tro giup tinh toan
////////////////////////
string divide2(string);
//Dua vao phan fraction se ra phan fraction /2.
//Vi du: ta co so 0.01 thì divide2_fraction(01) se tra ve 005
string divide2_fraction(string);

string multiply2(string);//x2 chuoi so

string BinToHex_string(bool* bit);//bin to hex duoi dang string
string DecToHex_string(Qint qinit);//dec to hex duoi dang string
string QintToStringUnsigned(Qint);//Qint to string (he 10), tinh theo kieu don gian

void ScanQInt(Qint& x);//Nhap qint
void PrintQInt(Qint x);//Xuat qint
bool* DecToBin(Qint x);//Qint to bool*
Qint BinToDec(bool* bit);//bool* to qint
char* BinToHex(bool* bit);//bool* to hex
char* DecToHex(Qint x);//qint to hex