/*
 * reg.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: Uzair Mayat (500599647) & Muhammad Noor (500589087)
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "header.hpp"
using namespace std;

/*constructor*/
reg::reg(int size){
	patientList = new patient[size];
	patientCount = 0;
}

/*destructor*/
reg::~reg(){
	delete [] patientList;
}

/*get register size*/
void reg::regSize(int *size){
	cout << "Obstetrical Triange Register" << endl;
	cout << "----------------------------" << endl << endl;
	cout << "Please enter the maximum size of the patient register: ";
	cin >> *size;
}

/*register menu*/
int reg::menu(){
	int option;

	cout << endl << "Obstetrical Triange Register" << endl;
	cout << "----------------------------" << endl << endl;
	cout << "1. Register a new patient" << endl;
	cout << "2. Examine the patient" << endl;
	cout << "3. Display single patient" << endl;
	cout << "4. Display patient register" << endl;
	cout << "5. Exit" << endl;
	cin >> option;

	while ((option != 1) && (option != 2) && (option != 3) && (option != 4) && (option != 5)){
		cout << endl << "Please choose one of the above options:";
		cin >> option;
	}

	return (option);
}

/*register new patient*/
void reg::regPatient(){
	cout << "Register New Patient" << endl;
	cout << "--------------------" << endl << endl;
	cout << "Enter patient first name: ";
	cin >> patientList[patientCount].firstName;
	cout << endl << "Enter patient last name: ";
	cin >> patientList[patientCount].lastName;
	cout << endl << "Enter patient health card number: ";
	cin >> patientList[patientCount].healthCard;
	patientList[patientCount].id = patientCount;
	patientCount++;
}

/*examine patient*/
void reg::examine(){
	int randCondition;
	patient *current;

	current = &patientList[0];	//pop first patient into current

	/* initialize random seed: */
	srand (time(NULL));
	/* generate secret number between 1 and 4: */
	randCondition = rand() % 4 + 1;
	cout << randCondition;

	/*shift patient to the left by 1*/
	for (int i=0; i<patientCount; i++)
		patientList[i]=patientList[i+1];

	if (current->condition == 0){
		current->condition = randCondition;
		patientList[patientCount-1] = current[0];
	}
	if (current->condition == 1){
		current->dilation = 0;
		patientList[patientCount-1] = current[0];
	}
	if (current->condition == 2){
		cout << "Please enter the cervical dilation: ";
		cin >> current->dilation;
		cout << endl << "Please enter the contraction rate: ";
		cin >> current->contractionRate;
		if (current->dilation >= 4 && current->contractionRate < 4)
			current->condition = 3;
		else
			patientList[patientCount-1] = current[0];
	}
	if (current->condition == 3){
		cout << "Patient " << current->id << " has been admitted to the ER." << endl;
		cout << current->firstName << "\t" << current->lastName << "\t" << endl;
	}
	if (current->condition == 4){
		cout << "Patient " << current->id << " has been removed from the patient register." << endl;
		cout << current->firstName << "\t" << current->lastName << "\t" << endl;
	}
}

/*display single patient*/
void reg::displayPatient(){
	int id;
	cout << "Display Patient" << endl;
	cout << "---------------" << endl << endl;
	cout << "Enter the ID of the patient you wish to display: ";
	cin >> id;
	cout << endl << "ID\t" << "First Name\t" << "Last Name\t" << "Health Card Number\t" << "Condition\t";
	cout << "Dialation\t" << "Contraction Rate\t" << "Bed Number\t" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;
	cout << (patientList[id-1].id)+1 << "\t" << patientList[id-1].firstName << "\t\t" << patientList[id-1].lastName << "\t\t";
	cout << patientList[id-1].healthCard << "\t\t";
	switch (patientList[id-1].condition){
	case 0:
		cout << "Unknown\t\t";
		break;
	case 1:
		cout << "Test\t\t";
		break;
	case 2:
		cout << "Labour\t\t";
		break;
	case 3:
		cout << "Admit\t\t";
		break;
	case 4:
		cout << "Release\t\t";
		break;
	default:
		break;
	}
	cout << patientList[id+1].dilation << "\t\t" << patientList[id+1].contractionRate << "\t\t\t";
	cout << patientList[id+1].bedNumber << endl;
}

/*display entire register*/
void reg::displayReg(){
	int i;
	cout << "Display Patient" << endl;
	cout << "---------------" << endl << endl;
	cout << endl << "ID\t" << "First Name\t" << "Last Name\t" << "Health Card Number\t" << "Condition\t";
	cout << "Dialation\t" << "Contraction Rate\t" << "Bed Number\t" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl << endl;

	for (i=0; i<patientCount;i++){
		cout << (patientList[i].id)+1 << "\t" << patientList[i].firstName << "\t\t" << patientList[i].lastName << "\t\t";
		cout << patientList[i].healthCard << "\t\t";
		switch (patientList[i].condition){
		case 0:
			cout << "Unknown\t\t";
			break;
		case 1:
			cout << "Test\t\t";
			break;
		case 2:
			cout << "Labour\t\t";
			break;
		case 3:
			cout << "Admit\t\t";
			break;
		case 4:
			cout << "Release\t\t";
			break;
		default:
			break;
		}
	cout << patientList[i].dilation << "\t\t" << patientList[i].contractionRate << "\t\t\t";
	cout << patientList[i].bedNumber << endl;
	}
}
