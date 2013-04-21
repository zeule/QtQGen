// Copyright (C) 2013
// Shchannikov Dmitry (rrock DOT ru AT gmail DOT com)
// Nex (nex AT otaku DOT ru)
/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "locationpage.h"

namespace Ui
{
    LocationPage::LocationPage(QWidget *parent, IControls *controls) : QWidget(parent)
    {
        _controls = controls;

        _locDesc = new LocationDesc(this, this, _controls);
        _locCode = new LocationCode(this, this, _controls);
        _locActs = new LocationActions(this, this, _controls);

        QHBoxLayout *hbox = new QHBoxLayout;
        QSplitter *topSplit = new QSplitter(this);
        
        QSplitter *vertSplit = new QSplitter(Qt::Vertical, this);

        topSplit->addWidget(_locDesc);
        topSplit->addWidget(_locCode);
        

        vertSplit->addWidget(topSplit);
        vertSplit->addWidget(_locActs);

        hbox->addWidget(vertSplit);
        setLayout(hbox);
    }

    void LocationPage::SetLocationIndex(size_t locIndex)
    {
        _locIndex = locIndex;
    }

    size_t LocationPage::GetLocationIndex()
    {
        return _locIndex;
    }

    void LocationPage::LoadPage()
    {
        _locDesc->LoadDesc();
        _locCode->LoadCode();
        _locActs->LoadAllActions();
    }

    void LocationPage::ExpandCollapseAll(bool isExpanded)
    {

    }

    void LocationPage::SelectAction( size_t actIndex )
    {
        _locActs->SelectActionInList( actIndex );
    }

    void LocationPage::SavePage()
    {
        _locDesc->SaveDesc();
        _locCode->SaveCode();
        _locActs->SaveAction();
    }

    size_t LocationPage::AddAction(const QString &name)
    {
        return _locActs->AddActionToList(name);
    }

    void LocationPage::SetFocusOnActionCode()
    {
        _locActs->SetFocusOnActionCode();
    }

    long LocationPage::GetSelectedAction()
    {
        return _locActs->GetSelectedAction();
    }

    void LocationPage::RenameAction( size_t actIndex, const QString& name )
    {
        _locActs->RenameActionInList(actIndex, name);
    }

    void LocationPage::DeleteAction( size_t actIndex )
    {
        _locActs->DeleteActionFromList(actIndex);
    }
}
