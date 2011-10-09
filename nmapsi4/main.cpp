/***************************************************************************
 *   Copyright (C) 2007-2011 by Francesco Cecconi                          *
 *   francesco.cecconi@gmail.com                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <QApplication>
#include <QTranslator>
#include <config.h>
#include "mainwin.h"


int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(mainwin);
    QApplication app(argc, argv);

    QString locale = QLocale::system().name();
    QString localeComplete;
    localeComplete.append("nmapsi4_");

    if(locale.contains("pt"))
    {
         locale.resize(5);
    } 
    else 
    {
         locale.resize(2);
    }

    localeComplete.append(locale);

    QTranslator translator;
    bool tmp_translator;
    QString urlTranslate;

#ifndef Q_WS_WIN // Gnu/Linux && Mac Os/x
    urlTranslate = __LinuxTranslateUrl__;
#ifndef TRANSL_NO_DEBUG
    qDebug() << "Nmapsi4/core -> url Translator::" << urlTranslate;
#endif

#else // MS Windows
    //urlTranslate = QDir::homePath();
    urlTranslate = QDir::rootPath();
    urlTranslate.append(QDir::toNativeSeparators("program files/nmapsi4/"));
#ifndef TRANSL_NO_DEBUG
    qDebug() << "Nmapsi4/core -> url Translator::" << urlTranslate;
#endif

#endif

    tmp_translator = translator.load(localeComplete, urlTranslate);

    if (tmp_translator == false)
    {
        tmp_translator = translator.load(localeComplete, QDir::currentPath());
    }

    // debug messages for Translation file
#ifndef TRANSL_NO_DEBUG
    qDebug() << "Nmapsi4/core -> Locale::" << localeComplete;
    qDebug() << "Nmapsi4/core -> Translation file Load::" << tmp_translator;
    qDebug() << "Nmapsi4/core -> Traslation file is Empty::" << translator.isEmpty();
#endif

    app.installTranslator(&translator);

    nmapClass dialog;
    dialog.show();
    return app.exec();
}
