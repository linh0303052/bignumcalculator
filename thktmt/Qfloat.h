#pragma once
#include "Qint.h"
#define numberofbyte 16
class Qfloat
{
private:
	int data[numberofbyte / 4];//day bit
	int getBit(int);//tra ve gia tri bit thu i
	void turnOn(int);//Doi bit i thanh 1
	void turnOff(int);//Doi bit i thanh 0
	int type(); //1: so 0, 2: am vo cuc, 3: duong vo cuc, 4: NaN
	Qint getSoMu(); //tra ve so mu
	Qint getTri(Qint);//tra ve phan tri
	void setSoMu(Qint);//gan so mu duoc truyen vao
	void setTri(Qint);//gan phan tri duoc truyen vao
public:
	Qfloat();
	Qfloat(string);//Gan string cho Qfloat
	
	string toDec();//Tra ve chuoi he 10 co dau
	string QfloatToString();// Tra ve chuoi he 10 khong co dau
	void printBin();//In day bit tung 8 bits tren moi dong

	string stringBin(bool group4);//In day bit loai bo cac so 0 dung dau
	//group4 true: chuoi string tra ve duoc tach ra moi 4 bit

	//cac operator
	Qfloat operator+(Qfloat y);
	Qfloat operator-(Qfloat y);
	Qfloat operator*(Qfloat y);
	Qfloat operator/(Qfloat y);
	Qfloat operator<<(int);
	Qfloat operator>>(int);
	bool operator==(Qfloat);

	static Qfloat BinToDec(bool* bit);//Chuyen chuoi bit thanh Qfloat
	static bool* DecToBin(Qfloat x);//Chuyen Qfloat thanh chuoi bit
	Qfloat normalize(Qint, Qint); //tra ve so co dang chuan hoa 
	int exceptionCalculation(Qfloat, int type); //xu ly cac truong hop tinh toan ra ket qua dac biet (type 1 cong, 2 nhan, 3 chia)

};
void ScanQfloat(Qfloat& x);//Nhap vao Qfloat
void PrintQfloat(Qfloat x);//Xuat ra Qfloat
