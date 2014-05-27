#include "stdafx.h"
#include "CReservation.h"


CReservation::CReservation()
{
	s_password = generate_s_password();
	i_projection_number = 0;
	usi_tickets_number = 1;
	
	p_usi_ticket_index = new unsigned short int[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_usi_ticket_index[i] = 0;
	
	p_seat = new room_array[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_seat[i] = { 1, 1 };

	d_total_cost = 0;
}

CReservation::CReservation(string s_password, int i_projection_number, unsigned short int usi_tickets_number, unsigned short int* p_usi_ticket_index, double d_total_cost, room_array* p_seat, string s_first_name, string s_last_name, string s_email, unsigned int ui_tel_number, unsigned short int usi_age)
:CHuman(s_first_name, s_last_name, s_email, ui_tel_number, usi_age)
{
	this->s_password = s_password;
	this->i_projection_number = i_projection_number;
	this->usi_tickets_number = usi_tickets_number;
	this->p_usi_ticket_index = p_usi_ticket_index;
	this->d_total_cost = d_total_cost;
	this->p_seat = p_seat;
}

CReservation::~CReservation()
{
}

void CReservation::set_s_passoword(string s_password){ this->s_password == s_password; }
void CReservation::set_i_projection_number(int i_projection_number){ this->i_projection_number = i_projection_number; };
void CReservation::set_usi_tickets_number(unsigned short int usi_tickets_number){ this->usi_tickets_number = usi_tickets_number; };
void CReservation::set_p_usi_ticket_index(unsigned short int* usi_ticket_index){ this->p_usi_ticket_index = usi_ticket_index; };
void CReservation::set_usi_ticket_index(unsigned short int usi_ticket_index, unsigned short int i)
{
	if (i < usi_tickets_number) p_usi_ticket_index[i] = usi_ticket_index;
	else cout << "set_usi_ticket_index = MEMORY ERROR !" << endl;
}
void CReservation::set_d_total_cost(double d_total_cost){ this->d_total_cost = d_total_cost; };
void CReservation::set_p_seat(room_array* p_seat){ this->p_seat = p_seat; };

string CReservation::get_s_password(){ return s_password; }
int CReservation::get_i_projection_number() { return i_projection_number; };
unsigned short int CReservation::get_usi_tickets_number() { return usi_tickets_number; };
unsigned short int* CReservation::get_p_usi_ticket_index() { return p_usi_ticket_index; };
unsigned short int CReservation::get_usi_ticket_index(unsigned short int i)
{
	if (i < usi_tickets_number) return p_usi_ticket_index[i];
	else return 999;  //ERROR CONTROL
}
double CReservation::get_d_total_cost(){ return d_total_cost; };
room_array* CReservation::get_p_seat(){ return p_seat; };
room_array CReservation::get_seat(unsigned short int i)
{
	if (i < usi_tickets_number) return p_seat[i];
	else
	{
		cout << "CReservation::get_seat - MEMORY ERROR";
		return p_seat[0];
	}
}

CReservation& CReservation::operator=(CReservation& reservation)
{
	if (this != &reservation)
	{
		delete[] p_usi_ticket_index;
		p_usi_ticket_index = NULL;
		delete[] p_seat;
		p_seat = NULL;
	}

	i_projection_number = reservation.i_projection_number;
	usi_tickets_number = reservation.usi_tickets_number;

	p_usi_ticket_index = new unsigned short int[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_usi_ticket_index[i] = reservation.p_usi_ticket_index[i];

	for (int i = 0; i < usi_tickets_number; ++i)
		p_seat[i] = reservation.p_seat[i];

	d_total_cost = reservation.d_total_cost;
	return *this;
}

string CReservation::generate_s_password()
{
	string password = "aaaaaaaaaa";
	for (int i = 0; i < 10; ++i)
	{
			password[i] = (char)(rand()%(int)('z'-'a')+(int)'a'-1);
	}
	return password;
}
