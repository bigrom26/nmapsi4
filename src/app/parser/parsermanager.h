/***************************************************************************
 *   Copyright (C) 2011 by Francesco Cecconi                               *
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

#ifndef PARSERMANAGER_H
#define PARSERMANAGER_H

#include <QtGui/QWidget>
#include <QtGui/QTreeWidgetItem>
#include <QtGui/QMessageBox>

// local inclusion
#include "parserObjects.h"
#include "memorytools.h"

class nmapClass;

class parserManager : public QWidget
{
    Q_OBJECT

public:
    parserManager(nmapClass* parent = 0);
    ~parserManager();
    /*
     * Clear all Items in parser QList
     */
    void clearParserItems();
    /*
     * Add a parserObjUtil in dedicate parser qlist
     */
    void addUtilObject(parserObjUtil* object);

private:
    void showParserObj(int hostIndex);
    void showParserObjPlugins(int hostIndex);
    parserObj* parserCore(const QStringList parList,QString StdoutStr,QString StderrorStr,QTreeWidgetItem* mainTreeE);

    nmapClass* m_ui;
    QList<parserObj*> m_parserObjList;
    QList<parserObjUtil*> m_parserObjUtilList;
    QList<QTreeWidgetItem*> m_itemListScan;
    QList<QTreeWidgetItem*> m_objectItems;
    QList<QTreeWidgetItem*> m_treeItems;

public slots:
    /*
     * Start data QByteArray scan result parser.
     */
    void startParser(const QStringList parList, QByteArray dataBuffer,  QByteArray errorBuffer);
    void showParserResult(QTreeWidgetItem *item, int column);
    void showParserTracerouteResult(QTreeWidgetItem *item, int column);
};

#endif // PARSER_H