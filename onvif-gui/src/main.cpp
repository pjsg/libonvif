/*******************************************************************************
* main.cpp
*
* Copyright (c) 2022 Stephen Rhodes
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*******************************************************************************/

#include <functional>
#include <iostream>

#include "mainwindow.h"
#include <QApplication>

#ifdef _WIN32
#include "getopt-win.h"
#else
#include <getopt.h>
#endif

static struct option longopts[] = 
{
			 { "version",    no_argument,       NULL,      'v'},
			 { "clear",      no_argument,       NULL,      'c'},
             { NULL,         0,                 NULL,       0 }
};


Q_DECLARE_METATYPE(std::string);

int main(int argc, char *argv[])
{
	//std::string clearSettings;
	//if (argc > 1)
	//	clearSettings = argv[1];
	bool clear = false;

   	int ch;
	while ((ch = getopt_long(argc, argv, "vc", longopts, NULL)) != -1) {
		switch (ch) {
			case 'v':
				std::cout << "onvif-gui version " << VERSION << std::endl;
				exit(0);
			case 'c':
				clear = true;
				break;
		}
	}

    qRegisterMetaType<std::string>();

    QApplication a(argc, argv);
	//if (!clearSettings.empty()) {
	//	if (clearSettings == "clear") {
	//		clear = true;
	//	}
	//}

    MainWindow w(nullptr, clear);
	w.show();
    return a.exec();
}
