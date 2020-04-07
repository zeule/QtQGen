add_executable(QGen)
set_target_properties(QGen PROPERTIES
	AUTOMOC True
	AUTORCC True
	AUTOUIC True
)

target_sources(QGen PRIVATE
actioncode.h
actionslist.h
controls.h
datacontainer.h
game.h
ilocationpage.h
locationcode.h
locationdesc.h
locationpage.h
locationslistbox.h
mainwindow.h
mergedialog.h
stdafx.h
tabswidget.h
toolbutton.h
updater.h
updaterdescriptiondlg.h
updateshow.h
keywordsstore.h
qsphighlighter.h
searchdialog.h
searchdatastore.h
actionspanel.h
icontrols.h
iobserver.h
maintoolbar.h
settings.h
syntaxtextbox.h
locationactions.h
updaterthread.h
optionsdialog.h
colorwidget.h
fontwidget.h
crashhandler.h
actioncode.cpp
actionslist.cpp
controls.cpp
datacontainer.cpp
game.cpp
locationcode.cpp
locationdesc.cpp
locationpage.cpp
locationslistbox.cpp
main.cpp
mainwindow.cpp
mergedialog.cpp
tabswidget.cpp
toolbutton.cpp
updater.cpp
updaterdescriptiondlg.cpp
updateshow.cpp
keywordsstore.cpp
qsphighlighter.cpp
searchdialog.cpp
searchdatastore.cpp
actionspanel.cpp
locationactions.cpp
maintoolbar.cpp
settings.cpp
syntaxtextbox.cpp
updaterthread.cpp
optionsdialog.cpp
colorwidget.cpp
fontwidget.cpp
../misc/main_window.qrc
game.c
)

target_link_libraries(QGen PRIVATE
	Qt5::Core
	Qt5::Network
	Qt5::Widgets
	Qt5::Xml
	Qsp::qsp
)

find_package(GoogleBreakpad)
if (GoogleBreakpad_FOUND)
	target_sources(QGen PRIVATE
		crashhandler.cpp
	)
endif()

set(GOOGLE_BREAKPAD ${GoogleBreakpad_FOUND})

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmakein" "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)
