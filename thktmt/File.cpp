#include "pch.h"
#include "File.h"

void File::input(char* inputFileName, char* outputFilename, int base)
{
	ifstream input(inputFileName);
	ofstream output(outputFilename);
	while (!input.eof())
	{
		string s;
		getline(input, s);
		this->resolveLine(s, output, base);
		output << endl;
	}
	output.close();
	input.close();
}
	
void File::resolveLine(string data, ofstream& output, int base)
{
	stringstream line(data);
	string a, b, c, d;
	int type; //2 binary, 10 decimal, 16 hexadecimal
	Qint result;
	Qfloat fresult;
	getline(line, a, ' ');
	getline(line, b, ' ');
	if (a == "") return;
	//toan tu 1 ngoi
	if (b[0] == '~')
	{
		result = iCalculate1Operand(a, b, type);
	}
	else
	{
		getline(line, c, ' ');
		//toan tu 2 ngoi tru <<, >>
		if (c == "+" || c == "-" || c == "*" || c == "/" || c == "&" || c == "|" || c == "^")
		{
			getline(line, d, '\0');
			if (base == 1)
			{
				result = iCalculate2Operand(a, b, c, d, type);
			}
			else
			{
				fresult = fCalculateArithmetic(a, b, c, d, type);
			}
		}
		else if (c == "<<" || c == ">>" || c == "rol" || c == "ror")
		{
			//Qfloat khong co dich trai phai
			getline(line, d, '\0');
			result = iCalculateShift(a, b, c, d, type);
		}
		else if (c == ">" || c == "<" || c == "==" || c == "<=" || c == ">=")
		{
			getline(line, d, '\0');
			bPrintResult(iCalculateCompare(a, b, c, d, type), output);
			return;
		}
		else
		{
			//chuyen he
			if (base == 1)
			{
				result = iCalculateConvert(a, b, c, type);
			}
			else
			{
				fresult = fCalculateConvert(a, b, c, type);
			}
		}
	}

	//in ket qua
	if (base == 1)
	{
		iPrintResult(result, type, output);
	}
	else
	{
		fPrintResult(fresult, type, output);
	}
}

Qint File::iCalculate2Operand(string a, string b, string c, string d, int& type)
{
	Qint o1, o2, result;

	type = stoi(a);

	if (type == 2)
	{
		type = 2;
		//bien doi chuoi bin thanh day bool* bit
		bool* operand1 = stringToBin(b), * operand2 = stringToBin(d);
		//set vao Qint
		//o1.setBin(operand1);
		o1 = BinToDec(operand1);
		//o2.setBin(operand2);
		o2 = BinToDec(operand2);
	}
	else if (type == 10)
	{
		type = 10;
		o1 = Qint(b);
		o2 = Qint(d);
	}
	else
	{
		type = 16;
		//bien doi chuoi hex thanh day bool* bit
		bool* operand1 = hexToBin(b), * operand2 = hexToBin(d);
		//set vao Qint
		//o1.setBin(operand1);
		o1 = BinToDec(operand1);
		//o2.setBin(operand2);
		o2 = BinToDec(operand2);
		
	}

	if (c == "+")
	{
		result = o1 + o2;
	}
	if (c == "-")
	{
		result = o1 - o2;
	}
	if (c == "*")
	{
		result = o1 * o2;
	}
	if (c == "/")
	{
		result = o1 / o2;
	}
	if (c == "&")
	{
		result = o1 & o2;
	}
	if (c == "|")
	{
		result = o1 | o2;
	}
	if (c == "^")
	{
		result = o1 ^ o2;
	}
	return result;
}

bool File::iCalculateCompare(string a, string b, string c, string d, int& type)
{
	Qint o1, o2;

	type = stoi(a);

	if (type == 2)
	{
		type = 2;
		//bien doi chuoi bin thanh day bool* bit
		bool* operand1 = stringToBin(b), * operand2 = stringToBin(d);
		//set vao Qint
		//o1.setBin(operand1);
		o1 = BinToDec(operand1);
		//o2.setBin(operand2);
		o2 = BinToDec(operand2);
	}
	else if (type == 10)
	{
		type = 10;
		o1 = Qint(b);
		o2 = Qint(d);
	}
	else
	{
		type = 16;
		//bien doi chuoi hex thanh day bool* bit
		bool* operand1 = hexToBin(b), * operand2 = hexToBin(d);
		//set vao Qint
		//o1.setBin(operand1);
		o1 = BinToDec(operand1);
		//o2.setBin(operand2);
		o2 = BinToDec(operand2);

	}

	bool res;
	if (c == "<")
	{
		res = o1 < o2;
	}
	else if (c == ">")
	{
		res = o1 > o2;
	}
	else if (c == "==")
	{
		res = o1 == o2;
	}
	else if (c == "<=")
	{
		res = (o1 <= o2);
	}
	else if (c == ">=")
	{
		res = (o1 >= o2);
	}
	return res;
}

Qint File::iCalculateShift(string a, string b, string c, string d, int& type)
{
	Qint o, result;
	int count = stoi(d);

	type = stoi(a);

	if (type == 2)
	{
		bool* operand = stringToBin(b);
		o = BinToDec(operand);
	}
	if (type == 10)
	{
		o = Qint(b);
	}
	if (type == 16)
	{
		bool* operand = hexToBin(b);
		o = BinToDec(operand);
	}

	if (c == "<<")
	{
		result = o << count;
	}
	else if (c == ">>")
	{
		result = o >> count;
	}
	else if (c == "rol")
	{
		result = o.rol(count);
	}
	else
	{
		result = o.ror(count);
	}
	return result;
}

Qint File::iCalculateConvert(string a, string b, string c, int& type)
{
	Qint result;

	type = stoi(b);

	if (a == "2")
	{
		bool* operand = stringToBin(c);
		result = BinToDec(operand);
	}
	if (a == "10")
	{
		result = Qint(c);
	}
	if (a == "16")
	{
		bool* operand = hexToBin(c);
		result = BinToDec(operand);
	}

	return result;
}

Qint File::iCalculate1Operand(string a, string b, int& type)
{
	Qint result;
	char operate = b[0];
	b = b.substr(1, b.length() - 1);

	type = stoi(a);

	if (type == 2)
	{
		bool* operand = stringToBin(b);
		result = BinToDec(operand);
	}
	else if (type == 10)
	{
		result = Qint(b);
	}
	else
	{
		bool* operand = hexToBin(b);
		result = BinToDec(operand);
	}

	result = ~result;
	return result;
}

Qfloat File::fCalculateArithmetic(string a, string b, string c, string d, int& type)
{
	Qfloat o1, o2, result;
	type = stoi(a, nullptr, 10);
	if (type == 2)
	{
		//bien doi chuoi bin thanh day bool* bit
		bool* operand1 = stringToBin(b), * operand2 = stringToBin(d);
		//set vao Qint
		//o1.binToQfloat(operand1);
		o1 = Qfloat::BinToDec(operand1);
		//o2.binToQfloat(operand2);
		o2 = Qfloat::BinToDec(operand2);
	}
	else if (type == 10)
	{
		o1 = Qfloat(b);
		o2 = Qfloat(d);
	}
	else
	{
		//bien doi chuoi hex thanh day bool* bit
		bool* operand1 = hexToBin(b), * operand2 = hexToBin(d);
		//set vao Qint
		o1 = Qfloat::BinToDec(operand1);
		o2 = Qfloat::BinToDec(operand2);
	}

	if (c == "+")
	{
		result = o1 + o2;
	}
	if (c == "-")
	{
		result = o1 - o2;
	}
	if (c == "*")
	{
		result = o1 * o2;
	}
	if (c == "/")
	{
		result = o1 / o2;
	}
	return result;
}

Qfloat File::fCalculateConvert(string a, string b, string c, int& type)
{

	Qfloat result;
	if (a == "2")
	{
		bool* operand = stringToBin(c);
		result = Qfloat::BinToDec(operand);
	}
	if (a == "10")
	{
		result = Qfloat(c);
	}
	if (a == "16")
	{
		bool* operand = hexToBin(c);
		result = Qfloat::BinToDec(operand);
	}

	type = stoi(b, nullptr, 10);

	return result;
}

void File::bPrintResult(bool result, ofstream& output)
{
	if (result)
	{
		output << "true";
	}
	else
	{
		output << "false";
	}
}

void File::iPrintResult(Qint result, int type, ofstream& output)
{
	//in ket qua
	if (type == 2)
	{
		output << result.shortenBin();
	}
	else
	{
		if (type == 10)
		{
			output << result.toDec();
		}
		if (type == 16)
		{
			string s = BinToHex_string(DecToBin(result));
			int i = 0;
			while (s[i] == '0')
			{
				i++;
			}
			s = s.substr(i, s.length() - 1);
			output << s;
		}
	}
}

void File::fPrintResult(Qfloat result, int type, ofstream& output)
{
	//in ket qua
	if (type == 2)
	{
		output << result.stringBin(false);
	}
	else
	{
		if (type == 10)
		{
			output << result.toDec();
		}
		if (type == 16)
		{
			string s = BinToHex_string(Qfloat::DecToBin(result));
			output << s;
		}
	}
}

bool* stringToBin(string s)
{
	int length = s.length();
	bool* bin = new bool[128];
	//mo rong dau
	for (int i = 0; i < 128 - length; i++)
	{
		bin[i] = false;
	}
	//copy phan con lai
	for (int i = 128 - length; i < 128; i++)
	{
		if (s[i - 128 + length] == '1')
		{
			bin[i] = true;
		}
		else
		{
			bin[i] = false;
		}
	}
	return bin;
}

bool* hexToBin(string s)
{
	string bin;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		int n;
		switch (s[i])
		{
		case 'A': n = 10; break;
		case 'B': n = 11; break;
		case 'C': n = 12; break;
		case 'D': n = 13; break;
		case 'E': n = 14; break;
		case 'F': n = 15; break;
		default: n = s[i] - '0';
		}

		for (int i = 0; i < 4; i++)
		{
			bin = (char)((n % 2) + '0') + bin;
			n = n / 2;
		}
	}
	return stringToBin(bin);
}
