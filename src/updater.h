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

#ifndef UPDATER_H
#define UPDATER_H

#include "IControls.h"

namespace Ui
{
    struct UpdateInfo
    {
        QString filename;
        uint filesize;
        QString sum;
    };

    class Updater : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit Updater(IControls *controls);
        ~Updater();

        int CheckForUpdate();
        bool GenerateUpdateFile();
        int LaunchUpdater();

        int Show();

    signals:

    protected:
        void closeEvent(QCloseEvent * event);

    public slots:

    private slots:
        void OnLaunchButton();
        void OnDownloadProgress(qint64,qint64);
        void OnDownloadFinished();
        void OnDownloadReadyRead();
        //void OnCancelDownload();

    private:
        bool CleanFolder(const QString &directory);
        QStringList GetFileList(const QDir &directory);
        QString GetMD5Sum(const QString &fileName);
        QString ConvertSize(quint64);
        int StartUpdate();

        QString _appName;
        QString _remoteVersion;
        QString _appPath;
        QString _downloadPath;
        QString _updateUrl;
        QString _lastFile;

        QDomDocument _updateFile;
        QList<UpdateInfo> _filesToUpdate;
        QTextEdit *_textEdit;
        QProgressBar *_fileProgress;
        QProgressBar *_totalProgress;
        QFile *_downFile;

        QNetworkAccessManager manager;
        QNetworkReply *download;

        QPushButton *launchButton;

        quint32 _crc32table[256];
        bool downloadRequestAborted;
        bool networkError;
    };
} // namespace Ui

#endif // UPDATER_H
