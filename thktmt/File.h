#pragma once
#include "Qfloat.h"
#include <sstream>

class File
{
public:
	void input(char* inputFileName, char* outputFilename, int base); //1 Qint, 2 Qfloat
	void resolveLine(string data, ofstream &output, int base);//xu ly moi phep toan
	
	Qint iCalculate2Operand(string a, string b, string c, string d, int &types);//phep toan so hoc 2 ngoi
	bool iCalculateCompare(string a, string b, string c, string d, int& types);//phep so sanh
	Qint iCalculateShift(string a, string b, string c, string d, int& type);//phep toan xoay va dich
	Qint iCalculateConvert(string a, string b, string c, int& type);//chuyen he
	Qint iCalculate1Operand(string a, string b, int &type);//phep toan 1 ngoi tren bit
	
	Qfloat fCalculateArithmetic(string a, string b, string c, string d, int& type);//phep toan so hoc
	Qfloat fCalculateConvert(string a, string b, string c, int& type);//chuyen he

	void bPrintResult(bool result, ofstream& output); //in ket qua Bool
	void iPrintResult(Qint result, int type, ofstream& output);//in ket qua Qint
	void fPrintResult(Qfloat result, int type, ofstream& output);//in ket qua Qfloat
};
bool* stringToBin(string s);//doc chuoi ky tu he 2 thanh chuoi bool* bit
bool* hexToBin(string s);//doc chuoi ky tu he 16 thanh chuoi bool* bit
