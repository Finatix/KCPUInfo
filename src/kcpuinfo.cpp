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

#include "kcpuinfo.h"
#include "ui_kcpuinfo.h"


KCPUInfo::KCPUInfo()
    : QMainWindow()
{
    // tell the KXmlGuiWindow that this is indeed the main widget
    // defining the widget
    QWidget* w = new QWidget(this);
    aquirer = new CpuInformationAquirer();
    setCentralWidget(w);
    setGeometry(0, 0, 670, 680);
    m_ui.setupUi(w);

    //KStandardAction::quit(qApp, SLOT(quit()), actionCollection());

    // connecting the slots
    connect(m_ui.exitButton, SIGNAL(clicked()), this, SLOT(quitSlot()));

    // filling the form with initial data
    fillCPUInfo();
}

KCPUInfo::~KCPUInfo()
{
}

void KCPUInfo::quitSlot()
{
    QApplication::exit();
}

void KCPUInfo::fillCPUInfo()
{
    m_ui.cpuName->setText(QString::fromUtf8(aquirer->getCpuName().c_str()));
    m_ui.codeName->setText(QString::fromUtf8(aquirer->getCodeName().c_str()));
    m_ui.brandId->setText(QString::fromUtf8(aquirer->getBrandId().c_str()));
    m_ui.packageName->setText(QString::fromUtf8(aquirer->getPackageName().c_str()));
    m_ui.technology->setText(QString::fromUtf8(aquirer->getTechnology().c_str()));
    m_ui.vid->setText(QString::fromUtf8(aquirer->getVID().c_str()));
    m_ui.specification->setText(QString::fromUtf8(aquirer->getSpecification().c_str()));
    m_ui.family->setText(QString::fromUtf8(aquirer->getFamily().c_str()));
    m_ui.model->setText(QString::fromUtf8(aquirer->getModel().c_str()));
    m_ui.stepping->setText(QString::fromUtf8(aquirer->getStepping().c_str()));
    m_ui.extFamily->setText(QString::fromUtf8(aquirer->getExtFamily().c_str()));
    m_ui.extModel->setText(QString::fromUtf8(aquirer->getExtModel().c_str()));
    m_ui.instructions->setText(QString::fromUtf8(aquirer->getInstructions().c_str()));
    m_ui.clockSpeed->setText(QString::fromUtf8(aquirer->getClockSpeed().c_str()));
    m_ui.busSpeed->setText(QString::fromUtf8(aquirer->getBusSpeed().c_str()));
    m_ui.ratedFSB->setText(QString::fromUtf8(aquirer->getRatedFSB().c_str()));
    m_ui.revision->setText(QString::fromUtf8(aquirer->getRevision().c_str()));
    m_ui.l1Data->setText(QString::fromUtf8(aquirer->getL1Data().c_str()));
    m_ui.l1DataWays->setText(QString::fromUtf8(aquirer->getL1DataWays().c_str()));
    m_ui.l1Inst->setText(QString::fromUtf8(aquirer->getL1Inst().c_str()));
    m_ui.l1InstWays->setText(QString::fromUtf8(aquirer->getL1InstWays().c_str()));
    m_ui.l2->setText(QString::fromUtf8(aquirer->getL2().c_str()));
    m_ui.l2Ways->setText(QString::fromUtf8(aquirer->getL2Ways().c_str()));
    m_ui.l3->setText(QString::fromUtf8(aquirer->getL3().c_str()));
    m_ui.l3Ways->setText(QString::fromUtf8(aquirer->getL3Ways().c_str()));
    m_ui.multiplier->setText(QString::fromUtf8(aquirer->getMultiplier().c_str()));
    m_ui.cores->setText(QString::fromUtf8(aquirer->getCores().c_str()));
    m_ui.threads->setText(QString::fromUtf8(aquirer->getThreads().c_str()));
    m_ui.instructions->setText(QString::fromUtf8(aquirer->getInstructions().c_str()));

    // todo fill in the missing information
}


#include "kcpuinfo.moc"
