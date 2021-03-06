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

#ifndef _ACTIONS_LIST_
#define _ACTIONS_LIST_

#include "icontrols.h"
#include "iobserver.h"
#include "actioncode.h"
#include "ilocationpage.h"

#include <QListWidget>

class ActionsList :
    public QListWidget, public IObserver
{
    Q_OBJECT

public:
    ActionsList(QWidget *parent, ILocationPage *locPage, ActionCode *actCode, IControls *controls);

    void LoadAllActions();
    void DeleteAllActions();

    void Select(int);

    void Update(bool isFromObservable = false);

    void LoadActionData(size_t actIndex);
    void SaveActionData();

    size_t AddAction(const QString& name);
    int GetSelection() const;
    QString GetString(size_t index) const;
    void SetString(size_t index, const QString & name);
    void DeleteAction(size_t actIndex);

    void MoveItemTo( size_t actIndex, size_t moveTo );

    void RefreshActions();

private:
    IControls *_controls;
    ILocationPage *_locPage;
    ActionCode *_actCode;

    int _prevActionIndex;

    QListWidgetItem *draggingItem;

    private slots:
        void OnItemChanged(QListWidgetItem * item);
        void OnRightMouseButton(const QPoint &pos);

protected:
    void dropEvent(QDropEvent * event );
    void mousePressEvent(QMouseEvent *event);
    void dragMoveEvent(QDragMoveEvent * event);
    void dragEnterEvent(QDragEnterEvent * event );

};

#endif // _ACTIONS_LIST_
