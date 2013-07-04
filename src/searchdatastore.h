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

#ifndef SEARCHDATASTORE_H
#define SEARCHDATASTORE_H

class SearchDataStore
{
private:
    QStringList _searchStrings;
    QStringList _replaceStrings;

public:
    SearchDataStore();

    const QStringList &GetSearchStrings() const { return _searchStrings; }
    const QStringList &GetReplaceStrings() const { return _replaceStrings; }
    void AddSearchString(const QString &text);
    void AddReplaceString(const QString &text);
    void ClearStore();
    void SaveSearchData(QSettings &settings);
    void LoadSearchData(QSettings &settings);
};

#endif // SEARCHDATASTORE_H