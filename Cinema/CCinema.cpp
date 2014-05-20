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
	ClearScreen();
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

		place** ppP_room;
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

			ppP_room = new ::place*[p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_line];
			for (unsigned int j = 0; j < p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_line; ++j)
				ppP_room[j] = new ::place[get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_column];

			for (unsigned int l = 0; l < p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_line; ++l)
			for (unsigned int c = 0; c < p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_column; ++c)
			{
				projections >> place;
				ppP_room[l][c] = (::place) place;
			}
			p_Projection[i] = new CProjection(tm_projection_time, usi_movie_number, usi_cinema_room_number, new CCinema_Room({ p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_line, p_Cinema->get_p_Cinema_Room(usi_cinema_room_number)->get_room_array().ui_column }, p_Cinema->get_p_Movie(usi_movie_number)->get_b_if_3d(), ppP_room));
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
			for (unsigned short int j = 0; j < usi_tickets_number; ++j)
				reservations >> p_usi_ticket_index[j];

			p_seat = new room_array[usi_tickets_number];
			for (unsigned short int k = 0; k < usi_tickets_number; ++k)
			{
				reservations >> p_seat[k].ui_line;
				reservations >> p_seat[k].ui_column;
			}
			p_Reservation[i] = new CReservation(ui_projection_number, usi_tickets_number, p_usi_ticket_index, d_total_cost, p_seat, s_first_name, s_last_name, s_email, ui_tel_number, usi_age);
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
	
	fstream reservations("Reservations.txt", ios::out);
	if (reservations.good())
	{
		reservations.clear();
		reservations << ui_Reservation_size << endl;

		for (unsigned int i = 0; i < ui_Projection_size; ++i)
		{
			reservations << p_Reservation[i]->get_s_first_name() << " ";
			reservations << p_Reservation[i]->get_s_last_name() << " ";
			reservations << p_Reservation[i]->get_s_email() << " ";
			reservations << p_Reservation[i]->get_ui_tel_number() << " ";
			reservations << p_Reservation[i]->get_usi_age() << endl;
			reservations << p_Reservation[i]->get_i_projection_number() << " ";
			reservations << p_Reservation[i]->get_usi_tickets_number() << " ";
			reservations << p_Reservation[i]->get_d_total_cost() << endl;

			for (int j = 0; j < p_Reservation[i]->get_usi_tickets_number(); ++j)
				reservations << p_Reservation[i]->get_usi_ticket_index(j) << " ";

			reservations << endl;

			for (unsigned short int k = 0; k < p_Reservation[i]->get_usi_tickets_number(); ++k)
			{
				reservations << p_Reservation[i]->get_seat(k).ui_line << " ";
				reservations << p_Reservation[i]->get_seat(k).ui_column << " ";
			}
			reservations << endl;
		}
		reservations.close();
	}
	else cout << "FILE ERROR \"Reservations.txt\" !" << endl;
	delete[] p_Reservation;
	p_Reservation = NULL;

	fstream projections("Projections.txt", ios::out);
	if (projections.good())
	{
		projections.clear();
		projections << ui_Projection_size << endl;

		tm tm_projection_time;

		for (unsigned int i = 0; i < ui_Projection_size; ++i)
		{
			tm_projection_time = p_Projection[i]->get_tm_projection_time();

			projections << (int) tm_projection_time.tm_mday << " ";
			projections << (int) tm_projection_time.tm_mon << " ";
			projections << (int) tm_projection_time.tm_year << " ";
			projections << (int) tm_projection_time.tm_hour << " ";
			projections << (int)tm_projection_time.tm_min << endl;

			projections << p_Projection[i]->get_usi_movie_number() << endl;
			projections << p_Projection[i]->get_usi_cinema_room_number() << endl;

			for (unsigned int j = 0; j < p_Cinema_Room[p_Projection[i]->get_usi_cinema_room_number()]->get_room_array().ui_line; ++j)
			{
				for (unsigned int k = 0; k < p_Cinema_Room[p_Projection[i]->get_usi_cinema_room_number()]->get_room_array().ui_column; ++k)
				{
					projections << (char) p_Projection[i]->get_cinema_room()->get_place(j,k) << " ";
				}
				projections << endl;
			}
		}
		projections.close();
	}
	else cout << "FILE ERROR \"Projections.txt\" !" << endl;

	delete[] p_Projection;
	p_Projection = NULL;

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
	
	cout << endl << "PROGRAM ZAKOÑCZY£ DZIA£ANIE" << endl;
	system("PAUSE");
}

void CCinema::ClearProjections()
{
	unsigned int ui_projections_counter = 0;
	unsigned int ui_reservations_counter = 0;
	tm tm_system_time;

	int* projection_numbers;
	projection_numbers = new int[ui_Projection_size];

	for (unsigned int i = 0; i < ui_Projection_size; ++i)
		projection_numbers[i] = -1;

	__time32_t long_time;
	_time32(&long_time);
	errno_t err;
	err = _localtime32_s(&tm_system_time, &long_time);

	for (unsigned int i = 0; i < ui_Projection_size; ++i)
	{
		if (p_Projection[i]->get_tm_projection_time()>tm_system_time)
		{
			projection_numbers[ui_projections_counter] = i;
			for (unsigned int j = 0; j < ui_Reservation_size; ++j)
			{
				if (p_Reservation[j]->get_i_projection_number() == i)
				{
					p_Reservation[j]->set_i_projection_number(ui_projections_counter);
					++ui_reservations_counter;
				}
			}
			++ui_projections_counter;
		}
		else
		{
			for (unsigned int j = 0; j < ui_Reservation_size; ++j)
			if (p_Reservation[j]->get_i_projection_number() == i)
				p_Reservation[j]->set_i_projection_number(-1);
		}
	}

	CProjection** new_p_Projection = new CProjection*[ui_projections_counter];
	for (unsigned int i = 0; i < ui_projections_counter; ++i)
	{
		if (projection_numbers[i] != -1)
			new_p_Projection[i] = p_Projection[projection_numbers[i]];
	}

	delete[] p_Projection;
	p_Projection = new_p_Projection;
	new_p_Projection = NULL;
	ui_Projection_size = ui_projections_counter;

	CReservation** new_p_Reservation = new CReservation*[ui_reservations_counter];
	for (unsigned int i = 0,j=0; i < ui_Reservation_size; ++i)
	{
		if (p_Reservation[i]->get_i_projection_number() != -1)
		{
			new_p_Reservation[j] = p_Reservation[i];
			++j;
		}
	}

	delete[] p_Reservation;
	p_Reservation = new_p_Reservation;
	new_p_Reservation = NULL;
	ui_Reservation_size = ui_reservations_counter;
}

void CCinema::ClearScreen()
{
	system("cls");
	cout << "SYSTEM REZERWACJI BILETÓW KINA HELIOS LUBIN" << endl;
	cout << "===============================================================================" << endl << endl << endl << endl;
}
void CCinema::ShowMenu()
{
	unsigned short int usi_option;
	system("cls");
	cout << "SYSTEM REZERWACJI BILETÓW KINA HELIOS LUBIN" << endl;
	cout << "===============================================================================" << endl << endl<<endl<<endl;
	cout << "WITAMY W SYSTEMIE REZERWACJI BILETÓW!" << endl;
	cout << "Wybierz opcjê:" << endl;
	cout << "1. Zarezerwuj bilet." << endl;
	cout << "2. Wyœwietl repertuar." << endl;
	cout << "3. Poka¿ cennik biletów." << endl;
	cout << "4. Zaloguj siê do systemu." << endl;
	cout << "5. Zamknij program." << endl << endl;
	cout << "Wybrana opcja: ";
	cin >> usi_option;

	switch (usi_option)
	{
	case 1:
	{
			  unsigned short int usi_movie, usi_tickets_number,usi_ticket;
			  unsigned short int* usi_ticket_index;
			  unsigned int ui_projection;
			  char c_seat;
			  unsigned int ui_seat;
			  room_array* seat;
			  
			  do
			  {
				  ClearScreen();
				  cout << "Wybierz film:" << endl;
				  ShowFilms();
				  cout << "Wybrany film: ";
				  cin >> usi_movie;

				  if (usi_movie < 0 || usi_movie >= usi_Movie_size)
				  {
					  cout << "WPROWAD POPRAWNY NUMER!";
					  Sleep(3 * 1000);
				  }
				  else
				  {
					  do
					  {
						  ClearScreen();
						  cout << "Wybierz projekcjê:" << endl;
						  ShowProjections(usi_movie);
						  cout << "Wybrana projekcja: ";
						  cin >> ui_projection;

						  if (ui_projection < 0 || ui_projection >= ui_Projection_size)
						  {
							  cout << "WPROWAD POPRAWNY NUMER!";
							  Sleep(3 * 1000);
						  }
					  } while (ui_projection < 0 || ui_projection >= ui_Projection_size);

					  ChooseProjection(usi_movie, ui_projection);
					  
					  bool check;
					  do
					  {
						  ClearScreen();
						  cout << "Podaj iloœæ biletów: ";
						  cin >> usi_tickets_number;
						  check = p_Projection[ui_projection]->Free_places(usi_tickets_number);
						  if (!check) Sleep(3 * 1000);
					  } while (!check);

					  seat = new room_array[usi_tickets_number];
					  usi_ticket_index = new unsigned short int[usi_tickets_number];

					  for (int i = 0; i < usi_tickets_number; ++i)
					  {
						  do
						  {
							  check = true;
							  ClearScreen();
							  p_Projection[ui_projection]->get_cinema_room()->ShowCinemaRoom();
							  cout << "Podaj miejsce nr" << i + 1 << " (np. A 1): ";
							  cin >> c_seat >> ui_seat;
							  if (c_seat >= 'a' && c_seat <= '¿');
							  c_seat = c_seat - 'a' + 'A';
							  seat[i].ui_line = (int)(c_seat - 'A');
							  seat[i].ui_column = ui_seat - 1;
							  if (seat[i].ui_line >= p_Projection[ui_projection]->get_cinema_room()->get_room_array().ui_line || seat[i].ui_column >= p_Projection[ui_projection]->get_cinema_room()->get_room_array().ui_column)
							  {
								  check = false;
								  cout << endl << "WPROWAD POPRAWNY NUMER MIEJSCA!";
								  Sleep(3 * 1000);
							  }
							  else
							  {
								  if (p_Projection[ui_projection]->get_cinema_room()->get_place(seat[i].ui_line, seat[i].ui_column) != FREE)
								  {
									  check = false;
									  cout << endl << "WYBRANE MIEJSCE NIE JEST WOLNE!";
									  Sleep(3 * 1000);
								  }
								  else
								  {
									  p_Projection[ui_projection]->get_cinema_room()->set_place(seat[i].ui_line, seat[i].ui_column, BUSY);
									  ClearScreen();
									  cout << "Wybierz rodzaj biletu: "<<endl;
									  ShowTickets(usi_movie);
									  cin >> usi_ticket;
								  }
							  }

						  } while (!check);
					  }
				  }
			  } while (usi_movie < 0 || usi_movie >= usi_Movie_size);
		}
		break;
	case 5:
		break;
	default:
		{
			   cout << "WPROWAD POPRAWNY NUMER!";
			   Sleep(3 * 1000);
			   ShowMenu();
		}
	}
}

void CCinema::ShowTickets(unsigned short int usi_film)//TEMP
{
	tm tm_now;
	__time32_t long_time;
	_time32(&long_time);
	errno_t err;
	err = _localtime32_s(&tm_now, &long_time);

	for (unsigned int i = 0,j=0; i < usi_Ticket_size; ++i)
	{
		if (p_Ticket[i]->get_b_validity((int)tm_now.tm_wday) == 1 && p_Ticket[i]->get_b_if_3d() == p_Movie[usi_film]->get_b_if_3d())
		{
			cout << j + 1 << ". Typ: ";
			if (p_Ticket[i]->get_C_code() == JUNIOR)
				cout << "ulgowy";
			if (p_Ticket[i]->get_C_code() == SENIOR)
				cout << "ulgowy (senior)";
			if (p_Ticket[i]->get_C_code() == NORMAL)
				cout << "normalny";
			cout << endl << "Cena: " << p_Ticket[i]->get_d_price();
			cout << endl << "Minimalny wiek: " << p_Ticket[i]->get_usi_max_age();
			cout << endl << "Maksymalny wiek: " << p_Ticket[i]->get_usi_max_age();
		}
	}
}

void CCinema::ShowFilms()
{
	for (unsigned short int i = 0; i < usi_Movie_size; ++i)
	{
		cout << endl << i << ". " << p_Movie[i]->get_s_title();
	}
	cout << endl;
}
void CCinema::ShowProjections(unsigned short int usi_movie)
{
	for (unsigned int i = 0,j=0; i < ui_Projection_size;++i)
	if (p_Projection[i]->get_usi_movie_number() == usi_movie)
	{
		cout << j << ". Data: " << p_Projection[i]->get_tm_projection_time().tm_mday << "." << p_Projection[i]->get_tm_projection_time().tm_mon + 1 << endl;
		cout << "   Godzina: " << p_Projection[i]->get_tm_projection_time().tm_hour << "." << p_Projection[i]->get_tm_projection_time().tm_min << endl << endl;
	}
}
void CCinema::ChooseProjection(unsigned short int usi_movie, unsigned int& ui_projection)
{
	unsigned int ui_counter = 0,i=0;
	for (; i < ui_Projection_size && ui_counter != ui_projection; ++i)
	{
		if (p_Projection[i]->get_usi_movie_number() == usi_movie)
			++ui_counter;
	}
	ui_projection = i;
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
CProjection* CCinema::get_p_Projection(unsigned int i)
{
	if (i < ui_Projection_size) return p_Projection[i];
	else
	{
		cout << "get_p_Projection - MEMORY ERROR";
		return p_Projection[0];
	}
}