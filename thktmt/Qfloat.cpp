#include "pch.h"

#include "Qfloat.h"

#include <iostream>
using namespace std;
int Qfloat::getBit(int position)
{
	if (position <= 0) return -1;
	if (position > numberofbyte * 8) return -1;
	//lay bit theo position
	return (data[(position - 1) / (numberofbyte / 4 * 8)] >> ((numberofbyte * 8 - position) % 32)) & 1;
}

void Qfloat::turnOn(int position)
{
	if (position <= 0) return;
	if (position > numberofbyte * 8) return;
	data[(position - 1) / (numberofbyte / 4 * 8)] = data[(position - 1) / (numberofbyte / 4 * 8)] | (1 << ((numberofbyte * 8 - position) % 32));
}

void Qfloat::turnOff(int position)
{
	if (position <= 0) return;
	if (position > numberofbyte * 8) return;
	data[(position - 1) / (numberofbyte / 4 * 8)] = data[(position - 1) / (numberofbyte / 4 * 8)] & ~(1 << ((numberofbyte * 8 - position) % 32));

}

//1: so 0, 2: am vo cuc, 3: duong vo cuc, 4: NaN, 0: binh thuong
int Qfloat::type()
{
	Qint somu = this->getSoMu(), tri = this->getTri(somu), zero = Qint("0");
	//0
	if (somu == Qint("-16383") && tri == zero)
	{
		return 1;
	}

	//NaN
	if (somu == Qint("16384") && tri > zero)
		return 4;

	//am va duong vo cuc
	if (somu == Qint("16384") && tri == zero)
	{
		if (this->getBit(1))
		{
			return 2;
		}
		return 3;
	}
	return 0;
}

Qint Qfloat::getSoMu()
{
	Qint value, k("16383");
	for (int i = 2; i <= 16; i++)
	{
		if ((*this).getBit(i))
		{
			value.turnOn(numberofbyte * 8 - 16 + i);
		}
	}

	value = value - k;

	return value;
}

Qint Qfloat::getTri(Qint somu)
{
	Qint value;

	for (int i = 17; i <= 128; i++)
	{
		if ((*this).getBit(i))
		{
			value.turnOn(i);
		}
	}

	if (somu == Qint("16384") || somu == Qint("-16383")) //vo cuc, 0, NaN
	{
		//do nothing
	}
	else //truong hop normalize thi them 1. o dau
	{
		value.turnOn(16);
	}

	return value;
}

void Qfloat::setSoMu(Qint value)
{
	Qint k("16383");
	value = value + k;
	for (int i = 2; i <= 16; i++)
	{
		if (value.getBit(numberofbyte * 8 - 16 + i))
		{
			this->turnOn(i);
		}
	}
}

void Qfloat::setTri(Qint value)
{
	for (int i = 17; i <= 128; i++)
	{
		if (value.getBit(i))
		{
			this->turnOn(i);
		}
	}
}

void Qfloat::printBin()
{
	cout << getBit(1) << " ";
	for (int i = 2; i < numberofbyte * 8 + 1; i++)
	{
		cout << getBit(i);
		if (i == 16)  cout << " ";
		//print 8bit on a line
	}
}

string Qfloat::stringBin(bool group4)
{
	string s = "";
	for (int i = 1; i < numberofbyte * 8 + 1; i++)
	{
		if (group4)
		{
			if (i % 4 == 1 && i != 1)
			{
				s += ' ';
			}
		}
		s += this->getBit(i) + '0';
	}
	return s;
}

Qfloat::Qfloat()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
	data[3] = 0;
}

Qfloat::Qfloat(string numberString)
{
	*this = Qfloat();//zero
	if (numberString == "0" || numberString == "0.0")
	{
		return;
	}
	//+-inf NaN
	if (numberString == "-inf" || numberString == "inf" || numberString == "NaN")
	{
		if (numberString == "-inf")
		{
			this->turnOn(1);
		}

		for (int i = 2; i <= 16; i++)
		{
			this->turnOn(i);
		}

		if (numberString == "NaN")
		{
			this->turnOn(128);
		}
		return;
	}
	string decimal;//Phan nguyen
	string fraction;//Phan sau dau .

	//Kiem tra so am
	bool negative = false;
	if (numberString[0] == '-')//ne la so am
	{
		negative = true;//luu lai
		numberString = numberString.substr(1, numberString.length() - 1);//bo dau tru di
	}

	bool frac = false;//Danh dau duyet qua dau . chua
	for (int i = 0; i < numberString.size(); i++) {
		if (!frac)
		{
			if (numberString[i] == '.' || numberString[i] == ',')
				frac = true;
			else
				decimal += numberString[i];
		}
		else {
			fraction += numberString[i];
		}
	}
	if (decimal.length() == 0) decimal = "0";// .0 thi decimal = "0"


	//THEM PHAN NGUYEN
	int soMu=0;//Dem so mu
	Qint one("1");

	bool first1 = false;
	int position = 16;
	int step = 0;
	if (decimal != "0")
	{
		while (decimal.length() != 0)//den khi het ki tu
		{
			if ((decimal[decimal.length() - 1] - '0') & 1) //la so le
			{
				first1 = true;
				this->turnOn(16);//bat bit len
			}

			if (first1)
			{
				*this = *this >> 1;//Shift qua phai de tao khoang trong them bit ke tiep vao
			}
			soMu ++;
			step++;
			decimal = divide2(decimal);//chia hai tiep
		}
		//Restore step bi du
		step--;
		*this = *this << 1;
		position = 17 + step;
	}
	soMu--;
	//PHAN THAP PHAN
	if (fraction != "0")
	{
		while (position <= 128)
		{
			int previousLength = fraction.length();
			fraction = multiply2(fraction);
			if (fraction.length() > previousLength)
			{
				this->turnOn(position);
				first1 = true;
				fraction = fraction.substr(1, fraction.length() - 1);//Bo phan dau di
			}
			if (first1)
				position++;
			else
				soMu --;
		}
	}
	Qint s("-16382");//So mu thap nhat cua normalize
	if (soMu<-16382) {
		int gap = -16382 -soMu;
		//denormalize
		*this = *this >> gap;
		//soMu = soMu + one;
	}
	else
	{
		soMu = soMu + 16383;
		//normalize
		this->turnOff(16);//Tat bit 1 bi day qua
		for (int i = 16;i >= 2;i--) {
			if (soMu >> (16 - i) & 1) {
				this->turnOn(i);
			}
		}
	}
	//Dua so mu ve dang excess k
	
	//Copy soMu vao phan exp
	/*for (int i = 16;i >= 2;i--) {
		if (soMu.getBit(numberofbyte * 8 - 16 + i)) {
			this->turnOn(i);
		}
	}*/

	if (negative)//So am
		this->turnOn(1);
}

Qfloat Qfloat::operator<<(int count)
{
	Qfloat temp;
	for (int i = 1; i <= numberofbyte * 8; i++)//Why start at 1? Fix this
	{
		//neu bit goc bang 1
		if (this->getBit(i + count) == 1)
		{
			temp.turnOn(i);
		}

	}
	return temp;
}

Qfloat Qfloat::operator>>(int count)
{
	Qfloat temp;
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

string Qfloat::toDec()
{
	if (this->getBit(1) == 0)
	{
		return  QfloatToString();
	}
	else
	{
		return "-" + QfloatToString();
	}
}

string Qfloat::QfloatToString()
{
	//+inf -inf
	if (this->type() == 2 || this->type() == 3)
	{
		return "inf";
	}
	//NaN
	if (this->type() == 4)
	{
		return "NaN";
	}

	string dec = "0";//Phan nguyen, tinh nhu Qint
	string fraction = "0";

	//So 0
	bool isZero = true;
	for (int i = 2; i <= 128; i++)
	{
		if (this->getBit(i) == 1) {
			isZero = false;
			break;
		}
	}
	if (isZero)
	{
		return dec + "." + fraction;
	}

	//Phan mu bit tu 2 den 16 = 15 bit, luu phan mu duoi dang int (int chua duoc 32 bit)
	int soMu = 0;
	int v = 1;
	bool normalize = false;
	if (this->getBit(2) == 1) //So duong
	{
		normalize = true;
		for (int i = 16;i >= 3;i--)
		{
			if (this->getBit(i) == 1)
			{
				soMu += v;
			}
			v *= 2;
		}
		soMu += 1;
	}
	else//so 0 thi soMu <0
	{
		v = -1;
		for (int i = 16; i >= 3; i--)
		{
			if (this->getBit(i) == 0)
			{
				soMu += v;
			}
			else
				normalize = true;//co it nhat mot so 1 trong phan mu thi la normalize
			v *= 2;
		}
	}
	//Phan tri: bit tu 17 den 128:
	//Tu bit 17 den 17+soMu-1 la phan nguyen
	if (normalize)
	{
		if (soMu >= 0)
		{
			//Cong them 1. o phia truoc
			dec = multiply2(dec);
			dec[dec.length() - 1] = (char)(dec[dec.length() - 1] + '1' - '0');
			//Tinh toan phan nguyen
			for (int i = 17;i < 17 + soMu;i++)
			{
				dec = multiply2(dec);
				if (this->getBit(i) == 1 && i <= 128)
				{
					dec[dec.length() - 1] = (char)(dec[dec.length() - 1] + '1' - '0');
				}
			}

			//17+soMu den 128: phan thap phan
			int j = 128;
			while (this->getBit(j) != 1) {//Find first bit 1 from right to left
				j--;
			}
			if (j >= 17 + soMu)
			{
				for (j;j >= 17 + soMu;j--)//Tinh toan phan thap phan
				{
					fraction = divide2_fraction(fraction);
					//cout << fraction << " ";
					if (this->getBit(j) == 1)
					{
						fraction[0] = (char)(fraction[0] + '5' - '0');
					}
					//cout << fraction << endl;
				}
			}
			else
			{//Truong hop phan thap phan khong co bit 1
				fraction = "0";
			}

		}
		else //soMu < 0 ==> phan nguyen = 0
		{
			dec = "0";
			int j = 128;

			while (this->getBit(j) != 1) {//Find first bit 1 from right to left
				j--;
			}
			if (j >= 17)
			{
				for (j;j >= 17;j--)//Tinh toan phan thap phan
				{
					fraction = divide2_fraction(fraction);
					if (j >= 17)
					{
						if (this->getBit(j) == 1)
						{
							fraction[0] = (char)(fraction[0] + '5' - '0');
						}
					}
				}
				//Xu ly them phan 0.0001_ (So 1 mac dinh): 
				fraction = divide2_fraction(fraction);
				fraction[0] = (char)(fraction[0] + '5' - '0');
				for (int i = 0;i > soMu + 1;i--)//Tinh toan phan thap phan
				{
					//cout << i << endl;
					fraction = divide2_fraction(fraction);
				}
			}
			else
			{
				//Truong hop phan thap phan khong co bit 1 ket qua la 2^soMu(-)
				//Vd: SoMu=-4 thi ket qua bin se la 0.0001
				//Ta tinh phan thap phan dua nhu so o tren
				fraction[0] = '5';
				for (int i = 0;i > soMu + 1;i--)//Tinh toan phan thap phan
				{
					fraction = divide2_fraction(fraction);
				}

			}
		}
	}
	else 
	{
		soMu = -16382;
		//Dang khong chuan
		int j = 128;
		while (this->getBit(j) != 1) {//Find first bit 1 from right to left
			j--;
		}
		if (j >= 17)
		{
			for (j; j >= 17; j--)//Tinh toan phan thap phan
			{
				fraction = divide2_fraction(fraction);
				if (j >= 17)
				{
					if (this->getBit(j) == 1)
					{
						fraction[0] = (char)(fraction[0] + '5' - '0');
					}
				}
			}
			//Xu ly them phan 0._ (So 1 mac dinh): 
			fraction = divide2_fraction(fraction);
			//fraction[0] = (char)(fraction[0] + '5' - '0');
			for (int i = 0;i > soMu + 1;i--)//Tinh toan phan thap phan
			{
				//cout << i<<endl;
				fraction = divide2_fraction(fraction);
			}
		}
	}
	//if (fraction.length() >= 20) fraction = fraction.substr(0, 20);
	return dec + "." + fraction;
}

//bool* Qfloat::toBin()
//{
//	bool* temp = new bool[128];
//	for (int i = 0; i < numberofbyte * 8; i++)
//	{
//		temp[i] = this->getBit(i + 1);
//	}
//	return temp;
//}

Qfloat Qfloat::BinToDec(bool* bin)
{
	Qfloat q;
	for (int i = 0; i < 128; i++)
	{
		if (bin[i])
			q.turnOn(i + 1);
		else
			q.turnOff(i + 1);
	}
	return q;
}

bool* Qfloat::DecToBin(Qfloat x)
{
	bool* temp = new bool[128];
	for (int i = 0; i < numberofbyte * 8; i++)
	{
		temp[i] = x.getBit(i + 1);
	}
	return temp;
}

Qfloat Qfloat::normalize(Qint soMuX, Qint TriX)
{
	Qfloat result;
	Qint zero("0"), one("1");
	bool isNegative = false;

	//chuyen dau vao ket qua
	if (TriX.getBit(1))
	{
		result.turnOn(1);
		TriX = -TriX;
		isNegative = true;
	}

	//xet tran phan tri, bit 15, neu bit 15 la 1 thi tran
	if (TriX.getBit(15))
	{
		TriX = TriX >> 1;
		soMuX = soMuX + one;
		//xet tran phan mu, 2^14
		if (soMuX == Qint("16384"))
		{
			if (isNegative)
			{
				return Qfloat("inf");
			}
			return Qfloat("-inf");
		}
	}

	//chuan hoa phan tri
	//neu bit 16 la 1 thi dung dang chuan
	while (!TriX.getBit(16))
	{
		TriX = TriX << 1;
		soMuX = soMuX - one;
		//denormalized
		if (soMuX == zero)
		{
			break;
		}
	}

	result.setSoMu(soMuX);
	result.setTri(TriX);

	return result;
}

//0: not exception, 1: 0, 2: -inf, 3: inf, 4: NaN
int Qfloat::exceptionCalculation(Qfloat y, int type) //type 1 cong, 2 nhan, 3 chia
{
	int typeX = this->type(), typeY = y.type();
	if (type == 1)
	{
		// NaN || NaN || inf - inf || -inf + inf
		if (typeX == 4 || typeY == 4 || typeX * typeY == 6)
		{
			return 4;
		}
		//0+0
		if (typeX * typeY == 1)
		{
			return 1;
		}
		//-inf + number
		if ((typeX == 2 && typeY != 3) || (typeX != 3 && typeY == 2))
		{
			return 2;
		}
		//+inf + number
		if ((typeX == 3 && typeY != 2) || (typeX != 2 && typeY == 3))
		{
			return 3;
		}
	}
	//phep nhan
	if (type == 2)
	{
		//NaN
		if (typeX == 4 || typeY == 4)
		{
			return 4;
		}
		//0*number
		if (typeX == 1 || typeY == 1)
		{
			return 1;
		}
		//0*inf
		if (typeX * typeY == 2 || typeX * typeY == 3)
		{
			return 4;
		}
	}
	//phep chia
	if (type == 3)
	{
		//NaN
		if (typeX == 4 || typeY == 4)
		{
			return 4;
		}
		//inf/inf
		if (typeX * typeY == 6 || typeX * typeY == 4 || typeX * typeY == 9)
		{
			return 4;
		}
		//0/0
		if (typeY == 1)
		{
			if (typeX == 1)
			{
				return 4;
			}
			//number/0, inf/0
			if (this->getBit(1))
			{
				return 2;
			}
			return 3;
		}
		//0/inf
		if (typeX * typeY == 2 || typeX * typeY == 3)
		{
			return 4;
		}
		//number/inf
		if (typeY == 2 || typeY == 3)
		{
			return 1;
		}
		//0/number
		if (typeX == 1)
		{
			return 1;
		}
	}
	return 0;
}

Qfloat Qfloat::operator+(Qfloat y)
{
	//xet cac TH dac biet
	int isExeption = this->exceptionCalculation(y, 1);
	switch (isExeption)
	{
	case 1: return Qfloat("0"); break;
	case 2: return Qfloat("-inf"); break;
	case 3: return Qfloat("inf"); break;
	case 4: return Qfloat("NaN"); break;
	}

	Qint soMuX = (*this).getSoMu(), soMuY = y.getSoMu(), TriX = (*this).getTri(soMuX), TriY = y.getTri(soMuY);
	bool isNegativeX = (*this).getBit(1), isNegativeY = y.getBit(1);
	Qint zero("0"), one("1");

	////neu 1 so bang 0 thi ket qua la so hang con lai

	if (this->type() == 1)
	{
		return y;
	}

	if (y.type() == 1)
	{
		return *this;
	}

	//neu 2 so mu khong bang nhau thi tang so mu nho hon
	while (soMuX < soMuY)
	{
		soMuX = soMuX + one;
		TriX = TriX >> 1;
		//neu tri bang 0 thi ket qua la so con lai
		if (TriX == zero)
		{
			return y;
		}
	}

	while (soMuX > soMuY)
	{
		soMuY = soMuY + one;
		TriY = TriY >> 1;
		if (TriY == zero)
		{
			return (*this);
		}
	}

	//2 so mu da bang nhau
	//them dau vao phan tri
	if (isNegativeX)
	{
		TriX = -TriX;
	}

	if (isNegativeY)
	{
		TriY = -TriY;
	}

	//luc nay phan tri cua z duoc luu trong triX, so mu cua z la so mu x
	TriX = TriX + TriY;

	return this->normalize(soMuX, TriX);
}

Qfloat Qfloat::operator-(Qfloat y)
{
	//doi dau y
	if (y.getBit(1))
	{
		y.turnOff(1);
	}
	else
	{
		y.turnOn(1);
	}
	return (*this) + y;
}

Qfloat Qfloat::operator*(Qfloat y)
{
	Qint soMuX = (*this).getSoMu(), soMuY = y.getSoMu(), TriX = (*this).getTri(soMuX), TriY = y.getTri(soMuY);
	bool isNegativeX = (*this).getBit(1), isNegativeY = y.getBit(1);
	Qint zero("0"), one("1");

	//xet cac TH dac biet
	int isExeption = this->exceptionCalculation(y, 2);
	switch (isExeption)
	{
	case 1: return Qfloat("0"); break;
	case 2: return Qfloat("-inf"); break;
	case 3: return Qfloat("inf"); break;
	case 4: return Qfloat("NaN"); break;
	}

	//them dau vao phan tri
	if (isNegativeX)
	{
		TriX = -TriX;
	}

	if (isNegativeY)
	{
		TriY = -TriY;
	}

	soMuX = soMuX + soMuY;

	//overflow
	if (soMuX >= Qint("16384"))
	{
		if (isNegativeX != isNegativeY)
		{
			return Qfloat("-inf");
		}
		return Qfloat("inf");
	}

	//overflow
	if (soMuX < Qint("-16383"))
	{
		return Qfloat("0");
	}
	
	//nhan phan tri
	TriX = TriX.multiplySignificandQfloat(TriY);

	return this->normalize(soMuX, TriX);
}

Qfloat Qfloat::operator/(Qfloat y)
{
	Qint soMuX = (*this).getSoMu(), soMuY = y.getSoMu(), TriX = (*this).getTri(soMuX), TriY = y.getTri(soMuY);
	bool isNegativeX = (*this).getBit(1), isNegativeY = y.getBit(1);
	Qint zero("0"), one("1");

	//xet cac TH dac biet
	int isExeption = this->exceptionCalculation(y, 3);
	switch (isExeption)
	{
	case 1: return Qfloat("0"); break;
	case 2: return Qfloat("-inf"); break;
	case 3: return Qfloat("inf"); break;
	case 4: return Qfloat("NaN"); break;
	}

	//them dau vao phan tri
	if (isNegativeX)
	{
		TriX = -TriX;
	}

	if (isNegativeY)
	{
		TriY = -TriY;
	}

	soMuX = soMuX - soMuY;

	//overflow
	if (soMuX >= Qint("16384"))
	{
		if (isNegativeX != isNegativeY)
		{
			return Qfloat("-inf");
		}
		return Qfloat("inf");
	}

	//underflow
	if (soMuX < Qint("-16383"))
	{
		return Qfloat("0");
	}

	//chia phan tri
	TriX = TriX.divideSignificandQfloat(TriY, soMuX);
	//danh cho truong hop so khong chuan
	if (TriX == Qint("16384"))
	{
		if (isNegativeX != isNegativeY)
		{
			return Qfloat("-inf");
		}
		return Qfloat("inf");
	}

	return this->normalize(soMuX, TriX);
}

bool Qfloat::operator==(Qfloat q)
{
	for (int i = 0; i < numberofbyte*8; i++)
	{
		if (this->getBit(i) != q.getBit(i))//neu co mot vi tri khong bang nhau
		{
			return false;
		}
	}
	return true;
}

void ScanQfloat(Qfloat& x)
{
	string q;
	cin >> q;
	x = Qfloat(q);
}

void PrintQfloat(Qfloat x) {
	string result = x.toDec();
	cout << result;
}