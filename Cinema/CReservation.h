#pragma once
#include "CHuman.h"
#include "CCinema_Room.h"
#include <iostream>

class CReservation :
	public CHuman
{
private:
	unsigned short int usi_movie_number;
	unsigned short int usi_tickets_number;
	unsigned short int* p_usi_ticket_index;
	double d_total_cost;
	room_array* p_seat;

public:
	CReservation();
	CReservation(unsigned short int, unsigned short int, unsigned short int*, double, room_array*, string, string, string, unsigned int, unsigned short int);
	virtual ~CReservation();

	void set_usi_movie_number(unsigned short int);
	void set_usi_tickets_number(unsigned short int);
	void set_p_usi_ticket_index(unsigned short int*);
	void set_usi_ticket_index(unsigned short int, unsigned short int);
	void set_d_total_cost(double);
	void set_p_seat(room_array*);
	bool set_seat(int,room_array);

	unsigned short int get_usi_movie_number();
	unsigned short int get_usi_tickets_number();
	unsigned short int* get_p_usi_ticket_index();
	unsigned short int get_usi_ticket_index(unsigned short int);
	double get_d_total_cost();
	room_array* get_p_seat();
	room_array get_place(int);
};

