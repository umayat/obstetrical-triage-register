/*
 * header.hpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Uzair Mayat & Muhammad Noor
 */

#ifndef HEADER_HPP_
#define HEADER_HPP_
#include <iostream>
using namespace std;

class patient{
public:
	string firstName;
	string lastName;
	string healthCard;
	int condition;		//unknown = 0; test = 1; labour = 2; admit = 3; release = 4;
	int bedNumber;
	int id;
	double contractionRate;
	double dilation;
};

class reg{
public:
	patient *patientList;
	int patientCount;
	void regSize(int *size);	//gets size of patient register
	void regPatient();			//add patient to register
	void examine();				//examine patient
	void displayPatient();		//displays single patient
	void displayReg();			//display all patients in register
	int menu();					//register menu
	reg(int);					//constructor
	~reg();						//destructor
};

#endif /* HEADER_HPP_ */
