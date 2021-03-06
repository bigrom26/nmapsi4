/*
Copyright 2010-2012  Francesco Cecconi <francesco.cecconi@gmail.com>

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

#include "pobjects.h"

PObject::PObject() : m_validFlag(false), m_id(0)
{

}

PObject::~PObject()
{

}

const QString &PObject::getHostName() const
{
    return m_hostName;
}

const QStringList &PObject::getHostInfo() const
{
    return m_mainInfo;
}

const QString& PObject::scanDate() const
{
    return m_scanDate;
}

const QStringList &PObject::getPortOpen() const
{
    return m_portOpened;
}

const QStringList &PObject::getPortClose() const
{
    return m_portClosed;
}

const QStringList &PObject::getPortFiltered() const
{
    return m_portFiltered;
}

const QStringList &PObject::getTraceRouteInfo() const
{
    return m_scanTraceRoute;
}

const QStringList &PObject::getFullScanLog() const
{
    return m_fullLogScan;
}

const QStringList &PObject::getErrorScan() const
{
    return m_errorScan;
}

const QHash< QString, QStringList > &PObject::getNseResult() const
{
    return m_nssResult;
}

const QStringList& PObject::getVulnDiscoverd() const
{
    return m_vulnDiscoverd;
}

bool PObject::isValidObject()
{
    return m_validFlag;
}

const QString &PObject::getParameters() const
{
    return m_parameters;
}

void PObject::setValidity(bool isValid)
{
    m_validFlag = isValid;
}

void PObject::setHostName(const QString hostName)
{
    m_hostName.append(hostName);
}

void PObject::setHostInfo(const QString hostInfoLine)
{
    m_mainInfo.append(hostInfoLine);
}

void PObject::setScanDate(const QString date)
{
    m_scanDate.append(date);
}

void PObject::setPortOpen(const QString portOpen)
{
    m_portOpened.push_back(portOpen);
}

void PObject::setPortClose(const QString portClose)
{
    m_portClosed.push_back(portClose);
}

void PObject::setPortFiltered(const QString portFiltered)
{
    m_portFiltered.push_back(portFiltered);
}

void PObject::setTraceRouteInfo(const QString traceElem)
{
    m_scanTraceRoute.push_back(traceElem);
}

void PObject::setFullScanLog(const QString logElem)
{
    m_fullLogScan.push_back(logElem);
}

void PObject::setErrorScan(const QString errorElem)
{
    m_errorScan.push_back(errorElem);
}

void PObject::setParameters(const QString parameters)
{
    m_parameters = parameters;
}

void PObject::setNseResult(const QHash< QString, QStringList > nseResult)
{
    m_nssResult = nseResult;
}

void PObject::setId(int id)
{
    m_id = id;
}

int PObject::getId()
{
    return m_id;
}

void PObject::setVulnDiscoverd(const QString vulnAddress)
{
    if (!m_vulnDiscoverd.contains(vulnAddress)) {
        m_vulnDiscoverd.push_back(vulnAddress);
    }
}

PObjectLookup::PObjectLookup() : m_id(0)
{

}

PObjectLookup::~PObjectLookup()
{

}

const QStringList &PObjectLookup::getInfoLookup() const
{
    return m_mainLookup;
}

const QString &PObjectLookup::getHostName() const
{
    return m_hostName;
}

void PObjectLookup::setInfoLookup(const QString lookupElem)
{
    m_mainLookup.push_back(lookupElem);
}

void PObjectLookup::setHostName(const QString hostName)
{
    m_hostName.append(hostName);
}

void PObjectLookup::setId(int id)
{
    m_id = id;
}

int PObjectLookup::getId()
{
    return m_id;
}
