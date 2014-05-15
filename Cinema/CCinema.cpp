#include "stdafx.h"
#include "CCinema.h"

CCinema* CCinema::p_Cinema = NULL;
CCinema_Room** CCinema::p_Cinema_Room = NULL;
CTicket** CCinema::p_Ticket = NULL;
CMovie** CCinema::p_Movie = NULL;
CWorker** CCinema::p_Worker = NULL;
CProjection** CCinema::p_Projection = NULL;
CReservation** CCinema::p_Reservation = NULL;

unsigned short int CCinema::usi_Cinema_Room_size = 1;
unsigned short int CCinema::usi_Ticket_size = 1;
unsigned short int CCinema::usi_Movie_size = 1;
unsigned short int CCinema::usi_Worker_size = 1;
unsigned int CCinema::ui_Projection_size = 1;
unsigned int CCinema::ui_Reservation_size = 1;

CCinema::CCinema() { p_Cinema = this; }
CCinema::~CCinema(){ p_Cinema = NULL; }

CCinema* CCinema::Cinema()
{
	if (p_Cinema == NULL) CCinema();
	return p_Cinema;
}

void CCinema::Initialization()
{
	cout << "SYSTEM REZERWACJI BILETÓW KINA HELIOS LUBIN" << endl;
	cout << "===============================================================================" << endl << endl;
	cout << "INICJALIZACJA PROGRAMU..." << endl << endl;

	fstream room("Cinema Rooms.txt",ios::in);
	if (room.good())
	{
		cout << "Wczytywanie pliku: \"Cinema Rooms.txt\"." << endl;
		bool b_if_3d;
		unsigned int ui_line = 0;
		unsigned int ui_column = 0;
		char place;
		room >> usi_Cinema_Room_size;
		p_Cinema_Room = new CCinema_Room*[usi_Cinema_Room_size];

		for (int i = 0; i < usi_Cinema_Room_size; ++i)
		{
			room >> ui_line;
			room >> ui_column;
			room >> b_if_3d;
			p_Cinema_Room[i] = new CCinema_Room({ ui_line, ui_column }, b_if_3d);
			for (unsigned int l = 0; l < ui_line; ++l)
			for (unsigned int c = 0; c < ui_column; ++c)
			{
				room >> place;
				p_Cinema_Room[i]->set_place(l, c, ::place(place));
			}
		}
	}
	else cout << "FILE ERROR \"Cinema Rooms.txt\"!" << endl;
	room.close();

	fstream tickets("Tickets.txt",ios::in);
	if (tickets.good())
	{
		cout << "Wczytywanie pliku: \"Tickets.txt\"." << endl;

		double d_price;
		unsigned short int usi_min_age;
		unsigned short int usi_max_age;
		bool b_validity[7];
		bool b_if_3d;
		char code;

		tickets >> usi_Ticket_size;
		p_Ticket = new CTicket*[usi_Ticket_size];

		for (int i = 0; i < usi_Ticket_size; ++i)
		{
			tickets >> d_price;
			tickets >> usi_min_age;
			tickets >> usi_max_age;
			for (int j = 0; j < 7; ++j)
				tickets >> b_validity[j];
			tickets >> b_if_3d;
			tickets >> code;
			p_Ticket[i] = new CTicket(d_price, usi_min_age, usi_max_age, b_validity, b_if_3d, (::code)code);
		}
	}
	else cout << "FILE ERROR \"Tickets.txt\"!" << endl;
	tickets.close();

	fstream movies("Movies.txt.",ios::in);
	if (movies.good())
	{
		cout << "Wczytywanie pliku: \"Movies.txt\"." << endl;

		string s_title;
		string s_production;
		string s_director;
		string s_scenario;
		string s_cast;
		string s_description;
		bool b_if_dubbing;
		bool b_if_3d;
		bool b_if_premiere;
		unsigned int ui_minimal_age;
		unsigned int ui_duration;

		movies >> usi_Movie_size;
		p_Movie = new CMovie*[usi_Movie_size];

		for (int i = 0; i < usi_Movie_size; ++i)
		{
			movies >> s_title;
			movies >> s_production;
			movies >> s_director;
			movies >> s_scenario;
			movies >> s_cast;
			movies >> s_description;
			movies >> b_if_dubbing;
			movies >> b_if_3d;
			movies >> b_if_premiere;
			movies >> ui_minimal_age;
			movies >> ui_duration;

			p_Movie[i] = new CMovie(s_title, s_production, s_director, s_scenario, s_cast, s_description, b_if_dubbing, b_if_3d, b_if_premiere, ui_minimal_age, ui_duration);
		}
	}
	else cout << "FILE ERROR \"Movies.txt\"!" << endl;
	movies.close();

	fstream workers("Workers.txt",ios::in);
	if (workers.good())
	{
		cout << "Wczytywanie pliku: \"Workers.txt\"." << endl;

		string s_first_name;
		string s_last_name;
		string s_email;
		unsigned int ui_tel_number;
		unsigned short int usi_age;
		string s_login;
		string s_password;
		string s_position;
		bool b_if_admin;

		workers >> usi_Worker_size;
		p_Worker = new CWorker*[usi_Worker_size];

		for (unsigned short int i = 0; i < usi_Worker_size; ++i)
		{
			workers >> s_first_name;
			workers >> s_last_name;
			workers >> s_email;
			workers >> ui_tel_number;
			workers >> usi_age;
			workers >> s_login;
			workers >> s_password;
			workers >> s_position;
			workers >> b_if_admin;

			p_Worker[i] = new CWorker(s_first_name, s_last_name, s_email, ui_tel_number, usi_age, s_login, s_password, s_position, b_if_admin);
		}
	}
	else cout << "FILE ERROR \"Workers.txt\"!" << endl;
	workers.close();

	fstream projections("Projections.txt",ios::in);
	if (projections.good())
	{
		cout << "Wczytywanie pliku: \"Projections.txt\"." << endl;

		tm tm_projection_time;
		unsigned short int usi_movie_number;
		unsigned short int usi_cinema_room_number;
		CCinema_Room* cinema_room;

		unsigned int ui_line = 0;
		unsigned int ui_column = 0;
		char place;

		projections >> ui_Projection_size;
		p_Projection = new CProjection*[ui_Projection_size];

		for (unsigned int i = 0; i < ui_Projection_size; ++i)
		{
			projections >> tm_projection_time.tm_mday;
			projections >> tm_projection_time.tm_mon;
			projections >> tm_projection_time.tm_year;
			projections >> tm_projection_time.tm_hour;
			projections >> tm_projection_time.tm_min;

			projections >> usi_movie_number;
			projections >> usi_cinema_room_number;

			cinema_room = new CCinema_Room(p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array(), p_Cinema->get_p_Movie(usi_movie_number)->get_b_if_3d());
			for (unsigned int l = 0; l < ui_line; ++l)
			for (unsigned int c = 0; c < ui_column; ++c)
			{
				projections >> place;
				cinema_room->set_place(l, c, ::place(place));
			}
			p_Projection[i] = new CProjection(tm_projection_time, usi_movie_number, usi_cinema_room_number, *cinema_room);
			// delete cinema_room;
		}
	}
	else cout << "FILE ERROR \"Projections.txt\"!" << endl;
	projections.close();

	fstream reservations("Reservations.txt",ios::in);
	if (reservations.good())
	{
		cout << "Wczytywanie pliku: \"Reservations.txt\"." << endl;

		string s_first_name;
		string s_last_name;
		string s_email;
		unsigned int ui_tel_number;
		unsigned short int usi_age;

		unsigned int ui_projection_number;
		unsigned short int usi_tickets_number;
		unsigned short int* p_usi_ticket_index;
		double d_total_cost;
		room_array* p_seat;

		reservations >> ui_Reservation_size;
		p_Reservation = new CReservation*[ui_Reservation_size];

		for (unsigned int i = 0; i < ui_Reservation_size; ++i)
		{
			reservations >> s_first_name;
			reservations >> s_last_name;
			reservations >> s_email;
			reservations >> ui_tel_number;
			reservations >> usi_age;
			reservations >> ui_projection_number;
			reservations >> usi_tickets_number;
			reservations >> d_total_cost;

			p_usi_ticket_index = new unsigned short int[usi_tickets_number];
			for (int j = 0; j < usi_tickets_number; ++j)
				reservations >> p_usi_ticket_index[j];

			p_seat = new room_array[usi_tickets_number];
			for (int k = 0; k < usi_tickets_number; ++k)
			{
				reservations >> p_seat[k].ui_line;
				reservations >> p_seat[k].ui_column;
			}
			p_Reservation[i] = new CReservation(ui_projection_number, usi_tickets_number, p_usi_ticket_index, d_total_cost, p_seat, s_first_name, s_last_name, s_email, ui_tel_number, usi_age);

			delete[] p_seat;
			p_seat = NULL;
			delete[] p_usi_ticket_index;
			p_usi_ticket_index = NULL;
		}
	}
	else cout << "FILE ERROR \"Reservations.txt\"!" << endl;
	reservations.close();

	cout << endl << "INICJALIZACJA ZAKOÑCZONA" << endl;
	cout << endl;
	system("PAUSE");
}

void CCinema::Finish()
{
	cout << endl<<"KOÑCZENIE PRACY PROGRAMU..."<<endl;
	
	fstream room("Cinema Rooms.txt",ios::out);
	if (room.good())
	{
		room.clear();
		room << usi_Cinema_Room_size<<endl;

		::room_array temp;

		for (unsigned int i = 0; i < usi_Cinema_Room_size;++i)
		{	
			temp = p_Cinema_Room[i]->get_room_array();
			room << temp.ui_line<<" ";
			room << temp.ui_column<<" ";
			room << p_Cinema_Room[i]->get_b_if_3d()<<endl;
			for (unsigned int l = 0; l < temp.ui_line; ++l)
			{
				for (unsigned int c = 0; c < temp.ui_column; ++c)
				{
					room <<(char) p_Cinema_Room[i]->get_place(l,c) << " ";
				}
				room << endl;
			}
		}
		room.close();
	}
	else cout << "FILE ERROR \"Cinema Room.txt\"!" << endl;

	delete[] p_Cinema_Room;
	p_Cinema_Room = NULL;

	fstream tickets("Tickets.txt", ios::out);
	if (tickets.good())
	{
		tickets.clear();
		tickets << usi_Ticket_size << endl;

		for (unsigned int i = 0; i < usi_Ticket_size; ++i)
		{
			tickets << p_Ticket[i]->get_d_price() << " ";
			tickets << p_Ticket[i]->get_usi_min_age() << " ";
			tickets << p_Ticket[i]->get_usi_max_age() << endl;
			for (unsigned short int j = 0; j < 7; ++j)
			{
				tickets << p_Ticket[i]->get_b_validity(j)<<" ";
			}
			tickets << endl <<p_Ticket[i]->get_b_if_3d()<<endl;
			tickets << (char)p_Ticket[i]->get_C_code()<<endl;
		}
		tickets.close();
	}
	else cout << "FILE ERROR \"Tickets.txt\" !" << endl;

	delete[] p_Ticket;
	p_Ticket = NULL;

	fstream movies("Movies.txt", ios::out);
	if (movies.good())
	{
		movies.clear();
		movies << usi_Movie_size<<endl;

		for (unsigned short int i = 0; i < usi_Movie_size; ++i)
		{
			movies << p_Movie[i]->get_s_title()<<endl;
			movies << p_Movie[i]->get_s_production()<<endl;
			movies << p_Movie[i]->get_s_director()<<endl;
			movies << p_Movie[i]->get_s_scenario()<<endl;
			movies << p_Movie[i]->get_s_cast()<<endl;
			movies << p_Movie[i]->get_s_description()<<endl;
			movies << p_Movie[i]->get_b_if_dubbing()<<" ";
			movies << p_Movie[i]->get_b_if_3d()<<" ";
			movies << p_Movie[i]->get_b_if_premiere()<<" ";
			movies << p_Movie[i]->get_ui_minimal_age()<<" ";
			movies << p_Movie[i]->get_ui_duration()<<endl;
		}
		movies.close();
	}
	else cout << "FILE ERROR \"Movies.txt\" !" << endl;

	delete[] p_Movie;
	p_Movie = NULL;

	fstream workers("Workers.txt", ios::out);
	if (workers.good())
	{
		workers.clear();
		workers << usi_Worker_size<<endl;

		for (unsigned short int i = 0; i < usi_Worker_size; ++i)
		{
			workers << p_Worker[i]->get_s_first_name() << endl;
			workers << p_Worker[i]->get_s_last_name() << endl;
			workers << p_Worker[i]->get_s_email() << endl;
			workers << p_Worker[i]->get_ui_tel_number() << endl;
			workers << p_Worker[i]->get_usi_age() << endl;
			workers << p_Worker[i]->get_s_login() << endl;
			workers << p_Worker[i]->get_s_password() << endl;
			workers << p_Worker[i]->get_s_position() << endl;
			workers << p_Worker[i]->get_b_if_admin() << endl;
		}
		workers.close();
	}
	else cout << "FILE ERROR \"Workers.txt.\" !" << endl;

	delete[] p_Worker;
	p_Worker = NULL;
	/*
	fstream projections("Projections.txt", ios::out);
	if (projections.good())
	{

	}
	else cout << "FILE ERROR \"Projections.txt\" !" << endl;
	*/
	delete[] p_Projection;
	p_Projection = NULL;
	delete[] p_Reservation;
	p_Reservation = NULL;
	cout << endl << "PROGRAM ZAKOÑCZY£ DZIA£ANIE" << endl;
	system("PAUSE");
}

CCinema_Room* CCinema::get_p_Cinema_Room(unsigned short int i)
{
	if (i < usi_Cinema_Room_size) return p_Cinema_Room[i];
	else 
	{
		cout << "get_p_Cinema_Room - MEMORY ERROR";
		return p_Cinema_Room[0];
	}
}

CMovie* CCinema::get_p_Movie(unsigned short int i)
{
	if (i < usi_Movie_size) return p_Movie[i];
	else
	{
		cout << "get_p_Movie - MEMORY ERROR";
		return p_Movie[0];
	}
}

CTicket* CCinema::get_p_Ticket(unsigned short int i)
{
	if (i < usi_Ticket_size) return p_Ticket[i];
	else
	{
		cout << "get_p_Ticket - MEMORY ERROR";
		return p_Ticket[0];
	}
}