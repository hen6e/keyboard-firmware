// -*- c++ -*-
#ifndef KEYBOARDPRESENTER_H
#define KEYBOARDPRESENTER_H

#include <QObject>
#include <QList>
#include <QScopedPointer>

#include "keyboardview.h"
#include "layoutpresenter.h"
#include "programspresenter.h"

class KeyboardModel;
class KeyboardComm;

class KeyboardPresenter : public QObject {
	Q_OBJECT
	Q_DISABLE_COPY(KeyboardPresenter)

	QList<USBDevice> mDevices;
	QScopedPointer<KeyboardView> mView;
	QScopedPointer<KeyboardModel> mKeyboardModel;
	QScopedPointer<KeyboardComm> mKeyboardComm;

	LayoutPresenter mLayoutPresenter;
	ProgramsPresenter mProgramsPresenter;

	QList<QPair<QString, QWidget*> > createSubviewList();

public:
	KeyboardPresenter();
	~KeyboardPresenter();

signals:
	void modelChanged(KeyboardModel*);

public slots:
	void showAction();
	void selectDeviceAction(int index);
	void updateDeviceListAction();
	void uploadAction();
	void downloadAction();
};

#endif
