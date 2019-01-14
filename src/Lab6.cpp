//============================================================================
// Name        : Lab6.cpp
// Author      : Uzair Mayat (500599647) & Muhammad Noor (500589087)
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 6: Obstetrical Triange Register
//============================================================================

#include <iostream>
#include <string>
#include "header.hpp"
using namespace std;

int main() {
	int option, size;
	reg list (size);

	list.regSize(&size);		//gets register size

	do{
		option = list.menu();	//menu
		if (option == 1)
			list.regPatient();	//register patient
		if (option == 2)
			list.examine();		//examine patient
		if (option == 3)
			list.displayPatient();	//display single patient
		if (option == 4)
			list.displayReg();		//display entire patient register
	}while (option != 5);

	list.~reg();	//destructor
}
