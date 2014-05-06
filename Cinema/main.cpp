// Cinema.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCinema_Room.h"
#include "CHuman.h"
#include "CMovie.h"
#include "CProjection.h"
#include "CTicket.h"
#include "CWorker.h"
#include "CReservation.h"
#include <locale.h>
#include <cstdlib>


// CProjection - zaczête...

int _tmain(int argc, _TCHAR* argv[])
{
	string subtitles;
	CCinema_Room Cinema1;
	CHuman Human1;
	CMovie Movie1;
	CTicket Ticket1;
	CWorker Worker1;

	cout << "Cinema1.place: "<<(char) Cinema1.get_place(0, 0) << endl;
	cout << "Human1.s_firstname: " << Human1.get_s_first_name() << endl;
	cout << "Human1.usi_tel_number: "<< Human1.get_ui_tel_number() << endl;
	cout << "Movie1.s_title: " << Movie1.get_s_title() << endl;
	cout << "Ticket1.C_code: " <<(char) Ticket1.get_C_code() << endl;
	cout << "Worker1.s_login: " << Worker1.get_s_login() << endl;
	system("PAUSE");
	return 0;
}

