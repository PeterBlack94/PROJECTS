#include "stdafx.h"
#include "CWorker.h"


CWorker::CWorker()
{
	s_login = "worker";
	s_password = "password";
	s_position = "Position...";
	b_if_admin = 0;
}

CWorker::CWorker(string s_first_name, string s_last_name, string s_email,unsigned int usi_tel_number,unsigned short int usi_age, string s_login, string s_password, string s_position, bool b_if_admin)
:CHuman(s_first_name,s_last_name,s_email,usi_tel_number,usi_age)
{
	this->s_login = s_login;
	this->s_password = s_password;
	this->s_position = s_position;
	this->b_if_admin = b_if_admin;
}

CWorker::~CWorker()
{
}

void CWorker::set_s_login(string s_login){ this->s_login = s_login; }
void CWorker::set_s_password(string s_password){ this->s_password = s_password; }
void CWorker::set_s_position(string s_position){ this->s_position = s_position; }
void CWorker::set_b_if_admin(bool b_if_admin){ this->b_if_admin = b_if_admin; }

string CWorker::get_s_login(){ return s_login; }
string CWorker::get_s_password(){ return s_password; }
string CWorker::get_s_position(){ return s_position; }
bool CWorker::get_b_if_admin(){ return b_if_admin; }

