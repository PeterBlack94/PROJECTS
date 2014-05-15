#include "stdafx.h"
#include "CReservation.h"


CReservation::CReservation()
{
	ui_projection_number = 0;
	usi_tickets_number = 1;
	
	p_usi_ticket_index = new unsigned short int[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_usi_ticket_index[i] = 0;
	
	p_seat = new room_array[usi_tickets_number];
	for (int i = 0; i < usi_tickets_number; ++i)
		p_seat[i] = { 1, 1 };

	d_total_cost = 0;
}

CReservation::CReservation(unsigned int ui_projection_number, unsigned short int usi_tickets_number, unsigned short int* p_usi_ticket_index, double d_total_cost, room_array* p_seat, string s_first_name, string s_last_name, string s_email, unsigned int ui_tel_number, unsigned short int usi_age)
:CHuman(s_first_name, s_last_name, s_email, ui_tel_number, usi_age)
{
	this->ui_projection_number = ui_projection_number;
	this->usi_tickets_number = usi_tickets_number;
	this->p_usi_ticket_index = p_usi_ticket_index;
	this->d_total_cost = d_total_cost;
	this->p_seat = p_seat;
}

CReservation::~CReservation()
{
}

void CReservation::set_ui_projection_number(unsigned int ui_projection_number){ this->ui_projection_number = ui_projection_number; };
void CReservation::set_usi_tickets_number(unsigned short int usi_tickets_number){ this->usi_tickets_number = usi_tickets_number; };
void CReservation::set_p_usi_ticket_index(unsigned short int* usi_ticket_index){ this->p_usi_ticket_index = usi_ticket_index; };
void CReservation::set_usi_ticket_index(unsigned short int usi_ticket_index, unsigned short int i)
{
	if (i < usi_tickets_number) p_usi_ticket_index[i] = usi_ticket_index;
	else cout << "set_usi_ticket_index = MEMORY ERROR !" << endl;
}
void CReservation::set_d_total_cost(double d_total_cost){ this->d_total_cost = d_total_cost; };
void CReservation::set_p_seat(room_array* p_seat){ this->p_seat = p_seat; };

unsigned int CReservation::get_ui_projection_number() { return ui_projection_number; };
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