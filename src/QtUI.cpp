#include "QtUI.h"
#include "ui_QtUI.h"

QtUI::QtUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtUI),
    m_3DWindow(nullptr)
{
    ui->setupUi(this);
    m_3DWindow = new Qt3DExtras::Qt3DWindow();
    m_3DWindow->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    QWidget *container = QWidget::createWindowContainer(m_3DWindow);
    QSize screenSize = m_3DWindow->screen()->size();
    container->setMinimumSize(QSize(640, 640));
    container->setMaximumSize(screenSize);  // or QSize(640, 640) ?
    ui->placeholder->addWidget(container);

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    m_3DWindow->registerAspect(input);

    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Camera
    Qt3DRender::QCamera *cameraEntity = m_3DWindow->camera();
//  cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->lens()->setOrthographicProjection(-10.0f, 10.0f, -10.0f, 10.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // Light
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Scene
    // Cuboid shape data
    Qt3DExtras::QCuboidMesh *cuboid = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    Qt3DCore::QTransform *cuboidTransform = new Qt3DCore::QTransform();
    cuboidTransform->setScale(4.0f);
    cuboidTransform->setTranslation(QVector3D(5.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    cuboidMaterial->setDiffuse(QColor(QRgb(0x665423)));

    //Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity(rootEntity);
    m_cuboidEntity->addComponent(cuboid);
    m_cuboidEntity->addComponent(cuboidMaterial);
    m_cuboidEntity->addComponent(cuboidTransform);

    // Set root object of the scene
    m_3DWindow->setRootEntity(rootEntity);

}


QtUI::~QtUI()
{
    qDebug() << "In QtUI::~QtUI()";
    //delete m_3DWindow;  // Don't need this
    delete ui;
}


void QtUI::on_cb_autosave_stateChanged(int state)
{
    if( state == Qt::Unchecked )
    {
        ui->cb_autofn->setDisabled(false);
    } else {
        ui->cb_autofn->setChecked(true);  // Or send a signal?
        ui->cb_autofn->setDisabled(true);
    }
}


void QtUI::on_cb_autofn_stateChanged(int state)
{
    if( state == Qt::Unchecked )
    {
        ui->le_filen->setDisabled(false);
    } else {
        // Set auto-filename
        ui->le_filen->setDisabled(true);
    }
}


void QtUI::on_actionExit_triggered()
{
    QApplication::quit();
}
