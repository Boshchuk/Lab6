// Lab6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>


void check(std::string s)
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
		std::cout << s1 << std::endl;
	}
}

int main()
{
	int i, j, k, l, m, n;

	std::string h[3];

	h[0] = 'B';
	h[1] = 'R';
	h[2] = 'W';

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
							check(h[i] + h[j] + h[k] + h[l] + h[m] + h[n]);
						}
					}
				}
			}
		}
	}

	return 0;
}


