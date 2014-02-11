#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QColorDialog>
#include <QDialog>
#include <QFontDialog>
#include <QMessageBox>

#include "icontrols.h"

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsDialog(IControls *control, QWidget *parent = 0);
    ~OptionsDialog();

public slots:
    void OnFontSelect();
    void OnColorSelect();
    void OnApplyButton();

private:
    Ui::OptionsDialog *ui;

    void InitOptionsDialog();

    IControls *_control;
    Settings *_settings;
};

#endif // OPTIONSDIALOG_H
