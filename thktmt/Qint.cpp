#include "pch.h"
#include "Qint.h"

string QintToStringUnsigned(Qint q)
{
	string str = "0";
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		str = multiply2(str);
		if (q.getBit(i) == 1)
		{
			str[str.length() - 1] = (char)(str[str.length() - 1] + '1' - '0');
		}
	}
	return str;
}

void ScanQInt(Qint& x)
{
	string s;
	cin >> s;
	x = Qint(s);
}

void PrintQInt(Qint x)
{
	cout << x.toDec();
}

bool* DecToBin(Qint x)
{
	bool* temp = new bool[numberofbyte * 8];
	for (int i = 1; i < numberofbyte * 8 + 1; i++)
	{
		temp[i - 1] = x.getBit(i);
	}
	return temp;
}

Qint BinToDec(bool* bit)
{
	Qint q;
	for (int i = 1; i < numberofbyte * 8 + 1; i++)
	{
		if (bit[i - 1] == 1)
			q.turnOn(i);
		else
			q.turnOff(i);
	}
	return q;
}

string Qint::toDec()
{
	if (this->getBit(1) == 0)
	{
		return QintToStringUnsigned(*this);
	}
	else
	{
		Qint n = -*this;
		return "-" + QintToStringUnsigned(n);
	}
}
#include "Qint.h"

int Qint::getBit(int position)
{
	if (position <= 0)
		return -1;
	if (position > numberofbyte * 8)
		return -1;
	//lay bit theo position
	return (data[(position - 1) / (numberofbyte / 4 * 8)] >> ((numberofbyte * 8 - position) % 32)) & 1;
}

void Qint::turnOn(int position)
{
	if (position <= 0)
		return;
	if (position > numberofbyte * 8)
		return;
	data[(position - 1) / (numberofbyte / 4 * 8)] = data[(position - 1) / (numberofbyte / 4 * 8)] | (1 << ((numberofbyte * 8 - position) % 32));
}

void Qint::turnOff(int position)
{
	if (position <= 0)
		return;
	if (position > numberofbyte * 8)
		return;
	data[(position - 1) / (numberofbyte / 4 * 8)] = data[(position - 1) / (numberofbyte / 4 * 8)] & ~(1 << ((numberofbyte * 8 - position) % 32));
}

void Qint::printBin()
{
	for (int i = 1; i < numberofbyte * 8 + 1; i++)
	{
		cout << getBit(i);
		if (i % 8 == 0)
			cout << endl;
		//print 8bit on a line
	}
}

string Qint::shortenBin_group4bit()
{
	int offset = 1;
	while (this->getBit(offset) == 0)
	{
		offset++;
		}
	
	while (offset % 4 != 1)
	{
		offset--;
	}

	string newstr = "";
	for (int i = offset; i <= numberofbyte * 8; i++)
	{
		if (i % 4 == 1 && i != offset)
		{
			newstr += ' ';
		}
		newstr += this->getBit(i) + '0';
	}

	return newstr;
}

string Qint::shortenBin()
{
	int offset = 1;
	while (this->getBit(offset) == 0)
	{
		offset++;
	}

	while (offset % 4 != 1)
	{
		offset--;
	}

	string newstr = "";
	for (int i = offset; i <= numberofbyte * 8; i++)
	{
		newstr += this->getBit(i) + '0';
	}

	return newstr;
}

char* BinToHex(bool* bit)
{
	char* c = new char[numberofbyte * 8 / 4];
	int j = 0;

	for (int i = 0; i < numberofbyte * 8; i += 4)
	{
		cout << i << endl;
		int value = bit[i] * 8 + bit[i + 1] * 4 + bit[i + 2] * 2 + bit[i + 3];
		cout << value;
		switch (value)
		{
		case 10:
			c[j] = 'A';
			break;
		case 11:
			c[j] = 'B';
			break;
		case 12:
			c[j] = 'C';
			break;
		case 13:
			c[j] = 'D';
			break;
		case 14:
			c[j] = 'E';
			break;
		case 15:
			c[j] = 'F';
			break;
		default:
			c[j] = value + '0';
			break;
		}

		j++;
	}
	return c;
}
char* DecToHex(Qint x)
{
	char* c = new char[numberofbyte * 8 / 4];
	int j = 0;

	for (int i = 1; i < numberofbyte * 8 + 1; i += 4)
	{
		int value = x.getBit(i) * 8 + x.getBit(i + 1) * 4 + x.getBit(i + 2) * 2 + x.getBit(i + 3);
		switch (value)
		{
		case 10:
			c[j] = 'A';
			break;
		case 11:
			c[j] = 'B';
			break;
		case 12:
			c[j] = 'C';
			break;
		case 13:
			c[j] = 'D';
			break;
		case 14:
			c[j] = 'E';
			break;
		case 15:
			c[j] = 'F';
			break;
		default:
			c[j] = value + '0';
			break;
		}

		j++;
	}
	return c;
}
Qint::Qint()
{
	//khoi tao all bang 0
	this->data[0] = 0;
	this->data[1] = 0;
	this->data[2] = 0;
	this->data[3] = 0;
}

//bool* Qint::getBin()
//{
//	bool* temp = new bool[numberofbyte * 8];
//	for (int i = 1; i < numberofbyte * 8 + 1; i++)
//	{
//		temp[i - 1] = getBit(i);
//	}
//	return temp;
//}

//void Qint::setBin(bool* bin)
//{
//	for (int i = 1; i < numberofbyte * 8 + 1; i++)
//	{
//		if (bin[i - 1] == 1)
//			turnOn(i);
//		else
//			turnOff(i);
//	}
//}
Qint Qint::operator+(Qint x)
{
	Qint result; //Constructor = 0

	int reminder = 0;
	for (int i = numberofbyte * 8; i > 0; i--)
	{
		int tmp = this->getBit(i) + x.getBit(i) + reminder;

		if (tmp <= 1)
		{
			reminder = 0;
			if (tmp == 1)
				result.turnOn(i);
		}
		else
		{
			reminder = 1;
			if (tmp == 3)
				result.turnOn(i);
		}
	}
	return result;
}

Qint Qint::operator-(Qint x)
{
	Qint result; //Constructor = 0

	int reminder = 0;
	for (int i = numberofbyte * 8; i > 0; i--)
	{
		int tmp = this->getBit(i) - x.getBit(i) - reminder;

		if (tmp >= 0)
		{
			if (tmp == 1)
				result.turnOn(i);
			reminder = 0;
		}
		else
		{
			if (tmp == -1)
				result.turnOn(i);
			reminder = 1;
		}
	}
	return result;
}

Qint Qint::operator-()
{
	Qint result;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (!this->getBit(i))
		{
			result.turnOn(i);
		}
	}
	Qint one;
	one.turnOn(numberofbyte * 8);
	result = result + one;
	return result;
}

Qint Qint::operator*(Qint x)
{
	Qint a[2];

	a[1] = *this;
	int q = 0; //last digit

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (a[1].getBit(numberofbyte * 8) == q) //Last 2 digit equal, do nothing
		{
		}
		else
		{
			if (a[1].getBit(numberofbyte * 8) > q)
			{
				a[0] = a[0] - x;
			}
			else
			{
				a[0] = a[0] + x;
			}
		}

		//Ghi lai Q-1
		q = a[1].getBit(numberofbyte * 8);

		//shift right
		a[1] = a[1] >> 1;

		//move last digit of a[0] to first digit of a[1]
		int tmp = a[0].getBit(numberofbyte * 8);
		(tmp == 1) ? a[1].turnOn(1) : a[1].turnOff(1);

		//shift right
		a[0] = a[0] >> 1;
	}
	return a[1];
}

Qint Qint::operator/(Qint x)
{
	Qint A, Q;
	Q = *this;

	bool sign; //2 so cung dau / nhau thi sign = false va nguoc lai.
	x.getBit(1) == Q.getBit(1) ? sign = false : sign = true;
	//Chuyen thanh so duong het
	if (x.isNegative())
		x = -x;
	if (Q.isNegative())
		Q = -Q;

	for (int i = 1; i <= numberofbyte * 8; i++) //Only for counting, do not use i
	{
		/////////
		//Shift//
		/////////
		int tmp = Q.getBit(1); //First digit of a[1]
		Q = Q << 1;
		A = A << 1;
		//turn on last digit of a[0] from shifting
		if (tmp)
			A.turnOn(numberofbyte * 8);
		else
			A.turnOff(numberofbyte * 8);
		////////////
		//Substract/
		////////////
		A = A - x;
		if (A.isNegative())
		{
			//Restore
			A = A + x;
		}
		else
		{
			//Set Q_0=1
			Q.turnOn(numberofbyte * 8);
		}
	}

	//Doi dau
	if (sign)
	{
		Q = -Q;
	}
	return Q;
}

bool Qint::operator<(Qint x)
{
	if (x.isNegative() != this->isNegative())
	{
		//Khac dau
		return (this->isNegative() ? true : false);
	}

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (this->getBit(i) < x.getBit(i))
		{
			return true;
		}
		else if (this->getBit(i) > x.getBit(i))
		{
			return false;
		}
	}
	return false;
}
bool Qint::operator>(Qint x)
{
	if (x.isNegative() != this->isNegative())
	{
		//Khac dau
		return (this->isNegative() ? false : true);
	}

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (this->getBit(i) > x.getBit(i))
		{
			return true;
		}
		else if (this->getBit(i) < x.getBit(i))
		{
			return false;
		}
	}
	return false;
}
bool Qint::operator<=(Qint x)
{
	if (x.isNegative() != this->isNegative())
	{
		//Khac dau
		return (this->isNegative() ? true : false);
	}

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (this->getBit(i) < x.getBit(i))
		{
			return true;
		}
		else if (this->getBit(i) > x.getBit(i))
		{
			return false;
		}
	}
	return true;
}
bool Qint::operator>=(Qint x)
{
	if (x.isNegative() != this->isNegative())
	{
		//Khac dau
		return (this->isNegative() ? false : true);
	}

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (this->getBit(i) > x.getBit(i))
		{
			return true;
		}
		else if (this->getBit(i) < x.getBit(i))
		{
			return false;
		}
	}
	return true;
}
bool Qint::operator==(Qint x)
{
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (this->getBit(i) != x.getBit(i))
		{
			return false;
		}
	}
	return true;
}

Qint& Qint::operator=(Qint x)
{
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (x.getBit(i))
		{
			this->turnOn(i);
		}
		else
		{
			this->turnOff(i);
		}
	}
	return *this;
}

Qint Qint::operator&(Qint x)
{
	Qint result;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		int bit = this->getBit(i) & x.getBit(i);
		if (bit)
			result.turnOn(i);
	}
	return result;
}
Qint Qint::operator|(Qint x)
{
	Qint result;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		int bit = this->getBit(i) | x.getBit(i);
		if (bit)
			result.turnOn(i);
	}
	return result;
}
Qint Qint::operator^(Qint x)
{
	Qint result;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		int bit = this->getBit(i) ^ x.getBit(i);
		if (bit)
			result.turnOn(i);
	}
	return result;
}
Qint Qint::operator~()
{
	Qint result;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (!this->getBit(i))
		{
			result.turnOn(i);
		}
	}
	return result;
}
bool Qint::isNegative()
{
	return this->getBit(1);
}

Qint Qint::operator<<(int count)
{
	Qint temp;
	for (int i = 1; i <= numberofbyte * 8; i++) //Why start at 1? Fix this
	{
		//neu bit goc bang 1
		if (this->getBit(i + count) == 1)
		{
			temp.turnOn(i);
		}
	}
	return temp;
}

Qint Qint::operator>>(int count)
{
	Qint temp;
	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		//neu dich bit neu bit kia bang 1 hoac bit am dich phai
		if ((this->getBit(i - count) == 1) || ((i <= count) && (this->getBit(1) == 1)))
		{
			temp.turnOn(i);
		}
	}
	return temp;
}

Qint Qint::rol(int d)
{
	d = d % (numberofbyte * 8);
	Qint s;
	for (int i = 0; i < d; i++)
	{
		s.turnOn(numberofbyte * 8 - i);
	}
	return (*this << d) | ((*this >> (numberofbyte * 8 - d)) & (s));
}

Qint Qint::ror(int d)
{
	Qint s;
	d = d % (numberofbyte * 8);
	for (int i = d + 1; i <= numberofbyte * 8; i++)
	{
		s.turnOn(i);
	}
	return ((*this >> d) & s) | ((*this << (numberofbyte * 8 - d)));
}

Qint Qint::multiplySignificandQfloat(Qint x)
{
	Qint a[2];

	a[1] = *this;
	int q = 0; //last digit

	for (int i = 1; i <= numberofbyte * 8; i++)
	{
		if (a[1].getBit(numberofbyte * 8) == q) //Last 2 digit equal, do nothing
		{
		}
		else
		{
			if (a[1].getBit(numberofbyte * 8) > q)
			{
				a[0] = a[0] - x;
			}
			else
			{
				a[0] = a[0] + x;
			}
		}

		//Ghi lai Q-1
		q = a[1].getBit(numberofbyte * 8);

		//shift right
		a[1] = a[1] >> 1;

		//move last digit of a[0] to first digit of a[1]
		int tmp = a[0].getBit(numberofbyte * 8);
		(tmp == 1) ? a[1].turnOn(1) : a[1].turnOff(1);

		//shift right
		a[0] = a[0] >> 1;
	}

	//dich phai 112 bit de lay phan dau cua ket qua o a[0]
	for (int i = 1; i <= 112; i++)
	{
		//shift right
		a[1] = a[1] >> 1;

		int tmp = a[0].getBit(numberofbyte * 8);
		(tmp == 1) ? a[1].turnOn(1) : a[1].turnOff(1);

		a[0] = a[0] >> 1;
	}

	return a[1];
}

Qint Qint::divideSignificandQfloat(Qint x, Qint& somu)
{
	Qint A, Q[2];
	Q[1] = *this;

	bool sign; //2 so cung dau / nhau thi sign = false va nguoc lai.
	x.getBit(1) == Q[1].getBit(1) ? sign = false : sign = true;
	//Chuyen thanh so duong het
	if (x.isNegative())
		x = -x;
	if (Q[1].isNegative())
		Q[1] = -Q[1];

	for (int i = 128; i >= 32; i--)
	{
		if (Q[1].getBit(i-16))
		{
			Q[0].turnOn(i);
		}
	}
	Q[1] = Q[1] << 112;

	for (int i = 1; i <= 225; i++) //Only for counting, do not use i
	{
		//shift
		int tmp = Q[0].getBit(32), tmp1 = Q[1].getBit(1); //First digit of a[1]
		Q[1] = Q[1] << 1;
		Q[0] = Q[0] << 1;
		if (tmp1)
		{
			Q[0].turnOn(numberofbyte*8);
		}
		A = A << 1;
		//turn on last digit of a[0] from shifting
		if (tmp)
			A.turnOn(numberofbyte * 8);
		//subtract
		A = A - x;
		if (A.isNegative())
		{
			//Restore
			A = A + x;
		}
		else
		{
			Q[1].turnOn(numberofbyte * 8);
		}
	}

	//tran so
	for (int i = 32; i <= 128; i++)
	{
		if (Q[0].getBit(i))
		{
			somu = somu + Qint("one");
			//overflow
			if (somu == Qint("16384"))
			{
				return somu;
			}
			//get the last bit of Q[0]
			int tmp = Q[0].getBit(numberofbyte * 8);
			Q[0] = Q[0] >> 1;
			Q[1] = Q[1] >> 1;
			if (tmp)
			{
				Q[1].turnOn(1);
			}
		}
	}

	for (int i = 1; i <= 15; i++)
	{
		if (Q[1].getBit(i))
		{
			somu = somu + Qint("one");
			//overflow
			if (somu == Qint("16384"))
			{
				return somu;
			}
			Q[1] = Q[1] >> 1;
		}
	}

	//Doi dau
	if (sign)
	{
		Q[1] = -Q[1];
	}
	return Q[1];
}

Qint::Qint(string bignumber)
{
	*this = Qint();
	//khai bao 0 tat ca

	//kiem tra phai so khong
	for (int i = 0; i < bignumber.length(); i++)
	{
		if ((i == 0) && (bignumber[i] == '-'))
			continue;
		if (bignumber[i] < '0')
			return;
		if (bignumber[i] > '9')
			return;
	}

	int position = numberofbyte * 8;
	bool odd = false;
	if (bignumber[0] == '-') //ne la so am
	{
		odd = true;												 //luu lai
		bignumber = bignumber.substr(1, bignumber.length() - 1); //bo dau tru di
	}
	if (bignumber.length() == 0)
		return;
	do
	{
		if ((bignumber[bignumber.length() - 1] - '0') & 1) //la so le
		{
			this->turnOn(position); //bat bit len
		}
		position--;
		bignumber = divide2(bignumber); //chia hai tiep
	} while (bignumber.length() != 0);	//den khi het ki tu

	if (odd)
	{
		bool check = false;
		for (size_t i = numberofbyte * 8; i > 0; i--)
		{
			if (check)
			{
				if (this->getBit(i) == 0)
					this->turnOn(i); //bang khong thi bat bit nguoc lai tat bit
				else
					this->turnOff(i);
			}
			if (this->getBit(i) == 1)
			{
				check = true;
			}
		}
	}
}

string divide2(string number)
{
	int remainder = 0;
	int j = 0;
	string result;
	for (int i = 0; i < number.length(); i++)
	{
		//lay so m la gia tri chia
		int m = remainder * 10 + (number[i] - '0');
		if ((m >> 1 > 0) || (i > 0))
		{
			//ghi ket qua vao
			result = result + to_string(m >> 1);
			j++;
		}
		//luu nho
		remainder = (m & 1);
	}
	return result;
}

//string multiply2(string number)
//{
//	string result;
//	int reminder = 0;
//	for (int i = number.length() - 1; i >= 0; i--) //Nhan tu phai qua
//	{
//		int d = (number[i] - '0') * 2 + reminder; //Tong 2 so hien tai
//		result = to_string(d % 10) + result;	  //Them vao result
//		reminder = d / 10;						  //Tinh nho
//	}
//	if (reminder != 0) //Cong phan du cuoi cung
//	{
//		result = to_string(reminder) + result; //Them vao result
//	}
//	return result;
//}

char convertToHex(int temp)
{
	if ((temp >= 0) && (temp <= 9))
	{
		return temp + '0';
	}
	switch (temp)
	{
	case 10:
		return 'A';
		break;
	case 11:
		return 'B';
		break;
	case 12:
		return 'C';
		break;
	case 13:
		return 'D';
		break;
	case 14:
		return 'E';
		break;
	case 15:
		return 'F';
		break;
	default:

		break;
	}
}

string BinToHex_string(bool* bit)
{
	if (sizeof(bit) % 4 != 0)
	{
		return "";
	}
	int temp = 0;
	string result = "";
	for (int i = numberofbyte * 8 - 1; i >= 0; i--)
	{
		if (bit[i] == 1)
		{
			temp = temp | 1 << (3 - i % 4);
		}

		if ((i % 4 == 0) && (i < numberofbyte * 8))
		{
			result = convertToHex(temp) + result;
			temp = 0;
		}
	}
	return result;
}

string DecToHex_string(Qint qinit)
{
	return BinToHex_string(DecToBin(qinit));
}

string multiply2(string bigNumber)
{
	int reminder = 0;
	string result = "";
	for (int i = bigNumber.length() - 1; i >= 0; i--)
	{
		char c = ((bigNumber[i] - '0') * 2 + reminder) % 10 + '0';
		result = c + result;
		reminder = ((bigNumber[i] - '0') * 2 + reminder) / 10;
	}
	if (reminder == 1)
		result = "1" + result;
	return result;
}
string divide2_fraction(string bigNumber)
{
	//Cac buoc*5
	int reminder = 0;
	string result = "";
	int numberOfZeroInfront = 0;

	//Luu so luong so 0 phia truoc
	for (int i = 0; i < bigNumber.length(); i++) {
		if (bigNumber[i] == '0') {
			numberOfZeroInfront++;
		}
		else
		{
			bigNumber = bigNumber.substr(numberOfZeroInfront, bigNumber.length());
			break;
		}
	}

	//Nhan cho 5
	for (int i = bigNumber.length() - 1; i >= 0; i--)
	{
		char c = ((bigNumber[i] - '0') * 5 + reminder) % 10 + '0';
		result = c + result;
		reminder = ((bigNumber[i] - '0') * 5 + reminder) / 10;
	}

	//Phan du neu co
	if (reminder)
	{
		result = to_string(reminder) + result;
	}

	if (result[0] >= '5' && result[0] <= '9') //Chu cai khac 0 dau tien
		result = '0' + result;


	//Them lai so khong ban dau
	for (int i = 0; i < numberOfZeroInfront; i++) {

		result = '0' + result;
	}

	//Them so 0 cho truong hop 0.01 / 2 = 0.005
	//Tim so dau tien khac 0
	//for (int i = 0; i < result.length(); i++)
	//{
	//	if (result[i] != '0')
	//	{
	//		if (result[i] >= '5' && result[i] <= '9') //Chu cai khac 0 dau tien
	//		{
	//			result = '0' + result;
	//			break;
	//		}
	//		else
	//		{
	//			break;
	//		}
	//	}
	//}

	return result;
}
