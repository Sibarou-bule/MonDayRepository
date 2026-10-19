#include"MagicalGirl.h"
#include"Madoka.h"
#include"Homura.h"

#include<iostream>
using namespace std;

int main(void)
{
	MagicalGirl* magicalGirl[2];
	Madoka madoka;
	Homura homura;

	magicalGirl[0] = &madoka;
	magicalGirl[1] = &homura;

	for (int i = 0; i < 2; i++)
	{
		magicalGirl[i]->Profile();
		magicalGirl[i]->Fight();
	}

}