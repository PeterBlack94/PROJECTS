#include "stdafx.h"
#include "CCinema.h"

CCinema* CCinema::p_Cinema = NULL;
CCinema_Room** CCinema::p_Cinema_Room = NULL;
CTicket** CCinema::p_Ticket = NULL;
CMovie** CCinema::p_Movie = NULL;
CWorker** CCinema::p_Worker = NULL;
CProjection** CCinema::p_Projection = NULL;
CReservation** CCinema::p_Reservation = NULL;

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
		cout << "SYSTEM REZERWACJI BILETÓW KINA HELIOS LUBIN" << endl;
		cout << "===============================================================================" << endl<<endl;
		cout << "INICJALIZACJA..." << endl;
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
			p_Cinema_Room = new CCinema_Room*[rooms_number];

			for (int i = 0; i < rooms_number; ++i)
			{
				room >> ui_line;
				room >> ui_column;
				room >> b_if_3d;
				p_Cinema_Room[i] = new CCinema_Room({ ui_line, ui_column }, b_if_3d);

				for (int l = 0; l < ui_line; ++l)
				for (int c = 0; c < ui_column; ++c)
				{
					room >> place;
					p_Cinema_Room[i]->set_place(l, c, ::place(place));
				}
			}
		}
		else cout << "B³¹d wczytywania pliku \"Cinema_Room.txt\"!"<<endl;
		room.close();

		ifstream tickets("Tickets.txt");
		if (tickets.good())
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
			p_Ticket = new CTicket*[tickets_number];

			for (int i = 0; i < tickets_number; ++i)
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
		else cout << "B³¹d wczytywania pliku \"Tickets.txt\"!" << endl;
		tickets.close();
		
		ifstream movies("Movies.txt.");
		if (movies.good())
		{
			unsigned short int usi_movies_number;
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

			movies >> usi_movies_number;
			p_Movie = new CMovie*[usi_movies_number];

			for (int i = 0; i < usi_movies_number; ++i)
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
		else cout << "B³¹d wczytywania pliku \"Movies.txt\"!" << endl;
		movies.close();

		ifstream workers("Workers.txt");
		if (workers.good())
		{
			unsigned int ui_workers_number;
			string s_first_name;
			string s_last_name;
			string s_email;
			unsigned int ui_tel_number;
			unsigned short int usi_age;
			string s_login;
			string s_password;
			string s_position;
			bool b_if_admin;

			workers >> ui_workers_number;
			p_Worker = new CWorker*[ui_workers_number];
			
			for (int i = 0; i < ui_workers_number; ++i)
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
		else cout << "B³¹d wczytywania pliku \"Workers.txt\"!" << endl;
		workers.close();

		ifstream projections("Projections.txt");
		if (projections.good())
		{
			unsigned int ui_projections_number;
			tm tm_projection_time;
			unsigned short int usi_movie_number;
			unsigned short int usi_cinema_room_number;
			CCinema_Room* cinema_room;

			unsigned short int rooms_number = 0;
			bool b_if_3d;
			unsigned int ui_line = 0;
			unsigned int ui_column = 0;
			char place;

			projections >> ui_projections_number;
			p_Projection = new CProjection*[ui_projections_number];

			for (int i = 0; i < ui_projections_number; ++i)
			{
				p_Projection[i] = new CProjection;

				projections >> tm_projection_time.tm_mday;
				projections >> tm_projection_time.tm_mon;
				projections >> tm_projection_time.tm_year;
				projections >> tm_projection_time.tm_hour;
				projections >> tm_projection_time.tm_min;

				projections >> usi_movie_number;
				projections >> usi_cinema_room_number;

				projections >> ui_line;
				projections >> ui_column;
				projections >> b_if_3d;
				cinema_room = new CCinema_Room({ ui_line, ui_column }, b_if_3d);

				for (int l = 0; l < ui_line; ++l)
				for (int c = 0; c < ui_column; ++c)
				{
					projections >> place;
					cinema_room->set_place(l, c, ::place(place));
				}
				p_Projection[i]->set_cinema_room(*cinema_room);
			}
		}
		else cout << "B³¹d wczytywania pliku \"Projections.txt\"!" << endl;
		projections.close();

		ifstream reservations("Reservations.txt");
		if (projections.good())
		{
		/*	unsigned int ui_projection_number;
			unsigned short int usi_tickets_number;
			unsigned short int* p_usi_ticket_index;
			double d_total_cost;
			room_array* p_seat;*/
		}
		else cout << "B³¹d wczytywania pliku \"Reservations.txt\"!" << endl;
		reservations.close();
	}
	return p_Cinema;
}