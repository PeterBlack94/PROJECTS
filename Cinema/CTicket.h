#pragma once

#include <iostream>
using namespace std;

enum code{NORMAL='N', JUNIOR='J', SENIOR='S'};

class CTicket
{
protected:
	double d_price;
	unsigned short int usi_min_age;
	unsigned short int usi_max_age;
	bool b_validity[7];
	bool b_if_3d;
	code C_code;

public:
	CTicket();
	CTicket(double, unsigned short int, unsigned short int, bool [7], bool, code);
	virtual ~CTicket();

	void set_d_price(double);
	void set_usi_min_age(unsigned short int);
	void set_usi_max_age(unsigned short int);
	bool set_b_validity(unsigned int i,bool=true);
	void set_b_if_3d(bool);
	void set_C_code(code);

	double get_d_price();
	unsigned short int get_usi_min_age();
	unsigned short int get_usi_max_age();
	bool get_b_validity(unsigned int i);
	bool get_b_if_3d();
	code get_C_code();
};

