// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>


std::string Sdvig(std::string str)
{
	std::string result;
	result = str.substr(1, 5) + str[0];

	return result;
}


std::string mirror(std::string str)
{
	std::string result;

	for (auto i = str.length(); i > 0; i--)
	{
		result = result + str[i];
	}
	return result;
}

std::vector<std::string> GetVariants (std::string str)
{
	std::vector<std::string> result;

	result.push_back(str);
	auto fm = mirror(str);
	result.push_back(fm);

	std::string t = str;

	for (auto i = 0; i < 5; i ++)
	{
		t = Sdvig(t);
		result.push_back(t);
		auto tm = mirror(t);
		result.push_back(tm);
	}

	return result;
}

bool IsInCombination(std::string str, std::vector<std::string> combination)
{
	
	auto same = GetVariants(str);

	for (auto it = combination.begin(); it != combination.end(); ++it)
	{
		for (auto sam = same.begin(); sam!= same.end(); ++sam)
		{
			if (*it == *sam)
			{
				return true;
			}
		}
	}
	return false;
}


std::vector<std::string> check(std::string s, std::vector<std::string> combination)
{
	std::string s1;

	int a, b, c;

	s1 = "";

	for (a = 0; a < 6; a++)
	{
		if (s1.find(s[a]) == std::string::npos)
		{
			s1 = s1 + s[a];
		}
		else
		{
			c = 0;
			for (b = 0; b < s1.length(); b++)
			{
				if (s1[b] == s[a])
				{
					c++;
				}
			}
			if (c == 1)
			{
				s1 = s1 + s[a];
			}
		}
	}

	if (s1.length() == 6)
	{
		if (combination.size() == 0)
		{
			std::cout << s1 << std::endl;
			combination.push_back(s1);
			
		}
		else
		{
			if( !IsInCombination(s1,combination))
			{
				std::cout << s1 << std::endl;
				combination.push_back(s1);
				
			}
		}
		
	}
	return combination;
}

int main()
{
	int i, j, k, l, m, n;

	std::string h[3];

	h[0] = 'B';
	h[1] = 'R';
	h[2] = 'W';

	std::vector<std::string> com;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					for (m = 0; m < 3; m++)
					{
						for (n = 0; n < 3; n++)
						{
							com = check(h[i] + h[j] + h[k] + h[l] + h[m] + h[n], com);
						}
					}
				}
			}
		}
	}
	std::cout << std::endl;
	std::cout << "Ne povtorki" <<com.size()<<std::endl;

	return 0;
}


