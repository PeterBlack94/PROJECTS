#pragma once
#include "CHuman.h"
#include "CCinema_Room.h"
#include <ctime>
#include <iostream>
#include <Windows.h>
class CReservation :
	public CHuman
{
private:
	string s_password;
	int i_projection_number;
	unsigned short int usi_tickets_number;
	unsigned short int* p_usi_ticket_index;
	double d_total_cost;
	room_array* p_seat;

public:
	CReservation();
	CReservation(string, int, unsigned short int, unsigned short int*, double, room_array*, string, string, string, unsigned int, unsigned short int);
	virtual ~CReservation();

	void set_s_passoword(string);
	void set_i_projection_number(int);
	void set_usi_tickets_number(unsigned short int);
	void set_p_usi_ticket_index(unsigned short int*);
	void set_usi_ticket_index(unsigned short int, unsigned short int);
	void set_d_total_cost(double);
	void set_p_seat(room_array*);
	bool set_seat(int,room_array);

	string get_s_password();
	int get_i_projection_number();
	unsigned short int get_usi_tickets_number();
	unsigned short int* get_p_usi_ticket_index();
	unsigned short int get_usi_ticket_index(unsigned short int);
	double get_d_total_cost();
	room_array* get_p_seat();
	room_array get_seat(unsigned short int i);

	static string generate_s_password();
	CReservation& operator=(CReservation&);
};

