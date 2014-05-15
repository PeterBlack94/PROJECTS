#include "stdafx.h"
#include "CTicket.h"


CTicket::CTicket()
{
	d_price = 0;
	usi_min_age = 3;
	usi_max_age = 150;
	for (int i = 0; i < 7; i++)
		b_validity[i] = 0;
	b_if_3d = 0;
	C_code = NORMAL;
}

CTicket::CTicket(double d_price, unsigned short int usi_min_age, unsigned short int usi_max_age, bool b_validity[], bool b_if_3d, code C_code)
{
	this->d_price = d_price;
	this->usi_min_age = usi_min_age;
	this->usi_max_age = usi_max_age;
	for (int i = 0; i < 7; ++i)
	{
		this->b_validity[i] = b_validity[i];
	}
	this->b_if_3d = b_if_3d;
	this->C_code = C_code;
}

CTicket::~CTicket()
{
}

void CTicket::set_d_price(double d_price){ this->d_price = d_price; }
void CTicket::set_usi_min_age(unsigned short int usi_min_age){ this->usi_min_age = usi_min_age; }
void CTicket::set_usi_max_age(unsigned short int usi_max_age){ this->usi_max_age = usi_max_age; }
bool CTicket::set_b_validity(unsigned int i_index, bool b_validity)
{ 
	if (i_index > 6 || i_index < 0) return false;
	
	this->b_validity[i_index] = b_validity; 
	return true;
}
void CTicket::set_b_if_3d(bool b_if_3d){ this->b_if_3d = b_if_3d; }
void CTicket::set_C_code(code C_code){ this->C_code = C_code; }

double CTicket::get_d_price(){ return d_price; }
unsigned short int CTicket::get_usi_min_age(){ return usi_min_age; }
unsigned short int CTicket::get_usi_max_age(){ return usi_max_age; }
bool CTicket::get_b_validity(unsigned int i_index)
{ 
	if (i_index > 6 || i_index < 0)
	{
		cout << "CTicket::get_b_validity - MEMORY ERROR!" << endl;
		return false;
	}
	return b_validity[i_index]; 
}
bool CTicket::get_b_if_3d(){ return b_if_3d; }
code CTicket::get_C_code(){ return C_code; }