#ifndef UPDATERDESCRIPTIONDLG_H
#define UPDATERDESCRIPTIONDLG_H

#include <QDialog>
#include <QTextEdit>

namespace Ui
{

    class UpdaterDescriptionDlg : public QDialog
    {
        Q_OBJECT
    public:
        explicit UpdaterDescriptionDlg(QWidget *parent = 0);

        QString GetText() { return _resText; }

    signals:

    public slots:

    private:
        QTextEdit *text;

        QString _resText;

    private slots:
        void OnOkButton();

    };

} // namespace Ui

#endif // UPDATERDESCRIPTIONDLG_H
