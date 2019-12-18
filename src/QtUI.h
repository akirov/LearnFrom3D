#ifndef QTUI_H
#define QTUI_H

#include <QMainWindow>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qforwardrenderer.h>
#include <QtGui/QScreen>
#include <Qt3DInput/QInputAspect>
#include <QEntity>
#include <Qt3DRender/QCamera>
#include <QPointLight>
#include <Qt3DCore/qtransform.h>
#include <QFirstPersonCameraController>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>


namespace Ui {
class QtUI;
}


class QtUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtUI(QWidget *parent = nullptr);
    ~QtUI();

private slots:
    void on_cb_autosave_stateChanged(int state);

    void on_cb_autofn_stateChanged(int state);

    void on_actionExit_triggered();

private:
    Ui::QtUI *ui;
    Qt3DExtras::Qt3DWindow* m_3DWindow;
    Qt3DCore::QEntity *m_cuboidEntity;
};

#endif // QTUI_H
