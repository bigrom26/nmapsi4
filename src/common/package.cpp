/*
Copyright 2012-2013  Francesco Cecconi <francesco.cecconi@gmail.com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 2 of
the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "package.h"


QString Package::localePath()
{
#if !defined(Q_OS_WIN32)
    return INSTALL_PATH + QString("locale/");
#else
    return QDir::rootPath() + QDir::toNativeSeparators("program files/nmapsi4/");
#endif

}

QUrl Package::qmlPath(QString qmlScript)
{
    return QUrl("qrc:/qml/platform/qml/" + qmlScript + ".qml");
}
