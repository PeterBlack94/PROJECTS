#pragma once
#include "CHuman.h"
#include <string>

class CWorker :
	public CHuman
{
private:
	string s_login;
	string s_password;
	string s_position;
	bool b_if_admin;

public:
	CWorker();
	CWorker(string, string, string, unsigned int, unsigned short int, string, string, string, bool);
	~CWorker();

	void set_s_login(string);
	void set_s_password(string);
	void set_s_position(string);
	void set_b_if_admin(bool);

	string get_s_login();
	string get_s_password();
	string get_s_position();
	bool get_b_if_admin();
};

