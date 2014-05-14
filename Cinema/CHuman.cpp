#include "stdafx.h"
#include "CHuman.h"


CHuman::CHuman()
{
	s_first_name="First name...";
	s_last_name = "Last name...";
	s_email = "E-mail...";
	ui_tel_number = 111111111;
	usi_age = 0;
}

CHuman::CHuman(string s_first_name, string s_last_name, string s_email, unsigned int ui_tel_number, unsigned short int usi_age)
{
	this->s_first_name = s_first_name;
	this->s_last_name = s_last_name;
	this->s_email = s_email;
	this->ui_tel_number = ui_tel_number;
	this->usi_age = usi_age;
}

CHuman::~CHuman()
{
}

void CHuman::set_s_first_name(string s_first_name){ this->s_first_name = s_first_name; }
void CHuman::set_s_last_name(string s_last_name){ this->s_last_name = s_last_name; }
void CHuman::set_s_email(string s_email){ this->s_email = s_email; }
void CHuman::set_ui_tel_number(unsigned int usi_tel_number){ this->ui_tel_number = ui_tel_number; }
void CHuman::set_usi_age(unsigned short int usi_age){ this->usi_age = usi_age; }

string CHuman::get_s_first_name(){ return s_first_name; }
string CHuman::get_s_last_name(){ return s_last_name; }
string CHuman::get_s_email(){ return s_email; }
unsigned int CHuman::get_ui_tel_number(){ return ui_tel_number; }
unsigned short int CHuman::get_usi_age(){ return usi_age; }