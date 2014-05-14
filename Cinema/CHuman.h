#pragma once
#include <string>

using namespace std;

class CHuman
{
protected:
	string s_first_name;
	string s_last_name;
	string s_email;
	unsigned int ui_tel_number;
	unsigned short int usi_age;

public:
	CHuman();
	CHuman(string, string, string, unsigned int, unsigned short int);
	virtual ~CHuman();

	void set_s_first_name(string);
	void set_s_last_name(string);
	void set_s_email(string);
	void set_ui_tel_number(unsigned int);
	void set_usi_age(unsigned short int);

	string get_s_first_name();
	string get_s_last_name();
	string get_s_email();
	unsigned int get_ui_tel_number();
	unsigned short int get_usi_age();
};

