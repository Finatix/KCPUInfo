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

// application header
#include "kcpuinfo.h"
// KDE headers
#include <QApplication>
#include <KAboutData>
#include <QCommandLineParser>

static const char description[] =
    I18N_NOOP("A very simple KDE 4 Application");

static const char version[] = "0.1";

int main(int argc, char **argv)
{
    KLocalizedString::setApplicationDomain("KCPUInfo");
    
    QApplication application(argc, argv);
    application.setWindowIcon(QIcon::fromTheme("kcpuinfo"));
    
    KAboutData aboutData( QStringLiteral("khallo"),
                          i18n("Simple App"),
                          QStringLiteral("%{VERSION}"),
                          i18n("A Simple Application written with KDE Frameworks"),
                          KAboutLicense::GPL,
                          i18n("(c) %{CURRENT_YEAR}, %{AUTHOR} <%{EMAIL}>"));
    
    aboutData.addAuthor( i18n("Ronny Kissing"), QStringLiteral("ronny.kissing@gmx.de"));

    KCPUInfo *mainWindow = new KCPUInfo;
    mainWindow->show();
    
    
    
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(application);
    aboutData.processCommandLine(&parser);
    
    return application.exec();
}
