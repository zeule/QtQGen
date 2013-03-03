#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#define TITLE "QGen"
#define QSP_CONFIG "qgen.cfg"

#include "locationslistbox.h"
#include "locationpage.h"
#include "tabswidget.h"
#include "IControls.h"
#include "MainToolBar.h"

enum
{
	ID_MAINDESC,
	ID_VARSDESC,
	ID_OBJECTS,
	ID_ACTIONS,
	ID_VIEWPIC,
	ID_INPUT,
	ID_TIMER,

	ID_DUMMY
};

namespace Ui
{

	class MainWindow : public QMainWindow
	{
		Q_OBJECT

	public:
		MainWindow(IControls *controls);
		//~MainWindow();

	private:
		void CreateMenuBar();
		void CreateToolBar();
		void CreateDockWindows();
		void CreateStatusBar();

		LocationsListBox		*_locListBox;
		QTabWidget				*_tabWidget;
		IControls				*_controls;
	};
} // namespace Ui

#endif // _MAIN_WINDOW_H_