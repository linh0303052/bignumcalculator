#include "pch.h"
#include "Header.h"
#include "Qint.h"
string convertBoolToString(bool * arrBool) {
	string str = "";
	int index = 0;
	while (arrBool[index] == 0)
	{
		index++;
	}
	
	for (int i = (index/4)*4; i < numberofbyte*8; i++)
	{
		if ((i % 32 == 0)&&(i>0))
		{
			str += "\n";
		}
		if (i%4==0)
		{
			str += " ";
		}
		str += arrBool[i] + '0';
	}
	return str;
}

System::String^ convertEach4(string str)
{
	int i = 0;
	while (str[i] == '0')
	{
		i++;
	}
	str = str.substr(i, str.length() - i + 1);
	int count = 0;
	string newstr = "";
	for (int i = 0; i < str.length(); i++)
	{
		if ((str.length()-i) % 4 == 0)
		{
			newstr += " ";
		}
		newstr += str[i];
	}
	
	return gcnew System::String(newstr.c_str());
}

