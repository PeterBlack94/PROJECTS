#include "stdafx.h"
#include "CCinema.h"

CCinema* CCinema::p_Cinema = NULL;
CCinema_Room* CCinema::p_Cinema_Room = NULL;
CTicket* CCinema::p_Ticket = NULL;
CMovie* CCinema::p_Movie = NULL;
CWorker* CCinema::p_Worker = NULL;
CProjection* CCinema::p_Projection = NULL;
CReservation* CCinema::p_Reservation = NULL;

CCinema::CCinema() { p_Cinema = this; }
CCinema::~CCinema()
{
	delete[] p_Cinema_Room;
	p_Cinema_Room = NULL;
	delete[] p_Ticket;
	p_Ticket = NULL;
	delete[] p_Movie;
	p_Movie = NULL;
	delete[] p_Worker;
	p_Worker = NULL;
	delete[] p_Projection;
	p_Projection = NULL;
	delete[] p_Reservation;
	p_Reservation = NULL;
	p_Cinema = NULL; 
}

CCinema* CCinema::Cinema()
{
	if (p_Cinema == NULL)
	{
		CCinema();
		ifstream room("Cinema Rooms.txt");

		if (room.good())
		{
			unsigned short int rooms_number = 0;
			bool b_if_3d;
			unsigned int ui_line = 0;
			unsigned int ui_column = 0;
			char place;

			room >> rooms_number;
			p_Cinema_Room = new CCinema_Room[rooms_number];

			for (int i = 0; i < rooms_number; ++i)
			{
				room >> ui_line;
				room >> ui_column;
				p_Cinema_Room[i].set_room_array({ ui_line, ui_column });

				room >> b_if_3d;
				p_Cinema_Room[i].set_b_if_3d(b_if_3d);

				for (int l = 0; l < ui_line; ++l)
				for (int c = 0; c < ui_column; ++c)
				{
					room >> place;
					p_Cinema_Room[i].set_place(l, c, ::place(place));
				}
			}
			room.close();
		}
		
		ifstream tickets("Tickets.txt");
		if (room.good())
		{
			unsigned short int tickets_number;
			double d_price;
			unsigned short int usi_min_age;
			unsigned short int usi_max_age;
			bool b_validity[7];
			bool b_if_3d;
			char code;
			place C_code;
			
			tickets >> tickets_number;
			p_Ticket = new CTicket[tickets_number];

			for (int i = 0; i < tickets_number; ++i)
			{
				tickets >> d_price;
				tickets >> usi_min_age;
				tickets >> usi_max_age;
				for (int j = 0; j < 7; ++j)
					tickets >> b_validity[j];
				tickets >> b_if_3d;
				tickets >> code;
				p_Ticket[i] = CTicket::CTicket(d_price, usi_min_age, usi_max_age, b_validity, b_if_3d, (::code)code);
				/*p_Ticket[i].set_d_price(d_price);
				p_Ticket[i].set_usi_min_age(usi_min_age);
				p_Ticket[i].set_usi_max_age(usi_max_age);
				for (int k = 0; k < 7; ++k)
				p_Ticket[i].set_b_validity(k,b_validity[k]);
				p_Ticket[i].set_b_if_3d(b_if_3d);
				p_Ticket[i].set_C_code((::code)code);*/
			}
			tickets.close();
		}
		
		ifstream movies("Movies.txt.");
		if (room.good())
		{
			unsigned short int movies_number;
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

			movies >> movies_number;
			p_Movie = new CMovie[movies_number];

			for (int i = 0; i < movies_number; ++i)
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

				p_Movie[i]=
			}
		}
	}

	return p_Cinema;
}