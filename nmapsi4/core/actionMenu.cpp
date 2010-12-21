/***************************************************************************
 *   Copyright (C) 2010-2011 by Francesco Cecconi                          *
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

#include "../mainwin.h"


void nmapClass::menuScanBook() {
    QAction removeBook(this);
    removeBook.setIcon(QIcon(QString::fromUtf8(":/images/images/window-close.png")));
    removeBook.setIconText(tr("Remove Host"));

    QAction scanBook(this);
    scanBook.setIcon(QIcon(QString::fromUtf8(":/images/images/viewmag.png")));
    scanBook.setIconText(tr("Scan Host"));

    connect(&scanBook, SIGNAL(triggered()),
                this, SLOT(callScanH()));
    connect(&removeBook, SIGNAL(triggered()),
            this, SLOT(deleteBookMark()));

    QMenu menuBook(this);
    menuBook.addAction(&scanBook);
    menuBook.addAction(&removeBook);

    menuBook.exec(QCursor::pos());
}

void nmapClass::menuVulnBook() {
    QAction removeBook(this);
    removeBook.setIcon(QIcon(QString::fromUtf8(":/images/images/window-close.png")));
    removeBook.setIconText(tr("Remove Service"));

    QAction addBook(this);
    addBook.setIcon(QIcon(QString::fromUtf8(":/images/images/viewmag.png")));
    addBook.setIconText(tr("Search for vulnerabilities"));

    connect(&addBook, SIGNAL(triggered()),
                this, SLOT(callVulnCheck()));
    connect(&removeBook, SIGNAL(triggered()),
            this, SLOT(deleteBookMark()));

    QMenu menuBook(this);
    menuBook.addAction(&addBook);
    menuBook.addAction(&removeBook);

    menuBook.exec(QCursor::pos());
}

void nmapClass::menuParBook() {
    QAction removeBook(this);
    removeBook.setIcon(QIcon(QString::fromUtf8(":/images/images/window-close.png")));
    removeBook.setIconText(tr("Remove Scan Paramenters"));

    QAction addBook(this);
    addBook.setIcon(QIcon(QString::fromUtf8(":/images/images/viewmag.png")));
    addBook.setIconText(tr("Use Parameters"));

    connect(&addBook, SIGNAL(triggered()),
                this, SLOT(callParFromBook()));
    connect(&removeBook, SIGNAL(triggered()),
            this, SLOT(deleteBookMarkPar()));

    QMenu menuBook(this);
    menuBook.addAction(&addBook);
    menuBook.addAction(&removeBook);

    menuBook.exec(QCursor::pos());
}

void nmapClass::menuServiceMain() {
    QAction checkVuln(this);
    checkVuln.setIcon(QIcon(QString::fromUtf8(":/images/images/viewmag+.png")));
    checkVuln.setIconText(tr("Check Vulnerability"));

    QAction showDetails(this);
    showDetails.setIcon(QIcon(QString::fromUtf8(":/images/images/messagebox_info.png")));
    showDetails.setIconText(tr("Show Details"));


    connect(&checkVuln, SIGNAL(triggered()),
                this, SLOT(objVulnButton()));
    connect(&showDetails, SIGNAL(triggered()),
            this, SLOT(actDetails()));

    QMenu menuVulnMain(this);
    menuVulnMain.addAction(&showDetails);
    menuVulnMain.addAction(&checkVuln);

    menuVulnMain.exec(QCursor::pos());
}

void nmapClass::actDetails() {
    if(actTabHost->isChecked()) {
        tabWidget->setCurrentIndex(tabWidget->indexOf(tab_9));
    } else {
        actTabHost->setChecked(true);
        updateTabHost();
        tabWidget->setCurrentIndex(tabWidget->indexOf(tab_9));
    }
}

