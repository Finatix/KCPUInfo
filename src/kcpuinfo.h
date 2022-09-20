/***************************************************************************
 *   Copyright (C) %{CURRENT_YEAR} by %{AUTHOR} <%{EMAIL}>                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef KCPUINFO_H
#define KCPUINFO_H


#include <QMainWindow>


#include "ui_kcpuinfo.h"
#include "cpuinformationaquirer.h"


/**
 * This class serves as the main window for KCPUInfo.  It handles the
 * menus, toolbars and status bars.
 *
 * @short Main window class
 * @author Your Name <mail@example.com>
 * @version 0.1
 */
class KCPUInfo : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * Default Constructor
     */
    KCPUInfo();

    /**
     * Default Destructor
     */
    virtual ~KCPUInfo();

public slots:
    void quitSlot();
    
private:
    // this is the name of the root widget inside our Ui file
    // you can rename it in designer and then change it here
    Ui::mainWidget m_ui;
    void fillCPUInfo();
    
    CpuInformationAquirer *aquirer;
};

#endif // _KCPUINFO_H_
