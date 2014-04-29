#include "stdafx.h"
#include "CReservation.h"


CReservation::CReservation()
{
	usi_movie_number = 0;
	usi_tickets_number = 1;
	
	p_usi_ticket_index = new unsigned short int[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_usi_ticket_index[i] = 0;
	
	p_seat = new room_array[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_seat[i] = { 1, 1 };

	d_total_cost = 0;
}

CReservation::CReservation(unsigned short int usi_movie_number, unsigned short int usi_tickets_number, unsigned short int* p_usi_ticket_index, double d_total_cost, room_array* p_seat, string s_first_name, string s_last_name, string s_email, unsigned int ui_tel_number, unsigned short int usi_age)
:CHuman(s_first_name, s_last_name, s_email, ui_tel_number, usi_age)
{
	this->usi_movie_number = usi_movie_number;
	this->usi_tickets_number = usi_tickets_number;
	this->p_usi_ticket_index = p_usi_ticket_index;
	this->d_total_cost = d_total_cost;
	this->p_seat = p_seat;
}

CReservation::~CReservation()
{
}

void CReservation::set_usi_movie_number(unsigned short int usi_movie_number){ this->usi_movie_number = usi_movie_number };
void CReservation::set_usi_tickets_number(unsigned short int usi_tickets_number){this->usi_tickets_number=usi_tickets_number};
void set_p_usi_ticket_index(unsigned short int*){/*........*/};