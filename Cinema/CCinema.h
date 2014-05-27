#pragma once
#include "CCinema_Room.h"
#include "CMovie.h"
#include "CProjection.h"
#include "CReservation.h"
#include "CTicket.h"
#include "CWorker.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <Windows.h>

class CCinema
{
private:
	static unsigned short int usi_Cinema_Room_size;
	static unsigned short int usi_Ticket_size;
	static unsigned short int usi_Movie_size;
	static unsigned short int usi_Worker_size;
	static unsigned int ui_Projection_size;
	static unsigned int ui_Reservation_size;

	static CCinema* p_Cinema;
	static CCinema_Room** p_Cinema_Room;
	static CTicket** p_Ticket;
	static CMovie** p_Movie;
	static CWorker** p_Worker;
	static CProjection** p_Projection;
	static CReservation** p_Reservation;

	CCinema();

public:
	~CCinema();
	static CCinema* Cinema();

	static void Initialization();
	static void ShowMenu();
	static void ShowWorkersMenu();
	static void Finish();

	static void ShowTickets();
	
	static void AddMovie();
	static void ShowMovies();
	static void CheckMovie(unsigned short int& usi_movie,bool& check);

	static void ShowRepertoire(unsigned short int&, unsigned short int&, unsigned short int&);

	static void AddProjection();
	static void ShowProjections(unsigned short int);
	static void ChooseProjection(unsigned short int, unsigned int&);

	static void ClearScreen();
	static void ClearProjections();

	static bool CheckRooms(tm, unsigned short int&, unsigned short int&);

	static bool NewReservation(string&, int&, unsigned short int&, unsigned short int*, double&, room_array*, string&, string&, string&, unsigned int&, unsigned short int&);

	static CProjection* get_p_Projection(unsigned int);
	static CTicket* get_p_Ticket(unsigned short int);
	static CCinema_Room* get_p_Cinema_Room(unsigned short int);
	static CMovie* get_p_Movie(unsigned short int);
};

