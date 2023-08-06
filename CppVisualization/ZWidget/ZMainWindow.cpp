#include "ZMainWindow.h"

ZMainWindow::ZMainWindow(QWidget* parent) : QMainWindow(parent)
{
    _pen = new QPen(Qt::blue, 2.0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    // 创建菜单栏
    QMenuBar* menuBar = this->menuBar();
    {
        // File
        {
            QMenu* fileMenu = menuBar->addMenu("File");

            QAction* openAction = new QAction("Open", fileMenu);
            fileMenu->addAction(openAction);

            QAction* saveAction = new QAction("Save", fileMenu);
            fileMenu->addAction(saveAction);
        }

        // Preference
        {
            QMenu* preferenceMenu = menuBar->addMenu("Preference");
        }
    }
    this->setMenuBar(menuBar);

    // 创建选项卡
    QTabWidget* tabWidget = new QTabWidget(this);
    // this->setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::North); // 设置 Tab 全在上面
    {
        _currentViewindex = 0;

        // 创建第一个 DockWidget
        {
            ZDockWidget*    dock  = new ZDockWidget(tabWidget);
            QGraphicsScene* scene = new QGraphicsScene(this);
            ZGraphicsView*  view  = new ZGraphicsView(this);
            view->setScene(scene);

            _views.emplace_back(view);
            dock->setWidget(view);
            tabWidget->addTab(dock, "Dock1");
        }

        // 创建第一个 DockWidget
        {
            ZDockWidget*    dock  = new ZDockWidget(tabWidget);
            QGraphicsScene* scene = new QGraphicsScene(this);
            ZGraphicsView*  view  = new ZGraphicsView(this);
            view->setScene(scene);

            _views.emplace_back(view);
            dock->setWidget(view);
            tabWidget->addTab(dock, "Dock2");
        }
    }
    this->setCentralWidget(tabWidget);
}

void ZMainWindow::initialize()
{
    // 设置窗口的默认宽度和默认高度
    this->resize(960, 480);

    // 获取屏幕的宽度和高度
    const QScreen* screen       = QGuiApplication::primaryScreen();
    const int      screenWidth  = screen->geometry().width();
    const int      screenHeight = screen->geometry().height();

    // 计算窗口在屏幕中央的位置
    const int windowWidth  = this->width();
    const int windowHeight = this->height();
    const int x            = (screenWidth - windowWidth) / 2;
    const int y            = (screenHeight - windowHeight) / 2;

    this->setGeometry(x, y, windowWidth, windowHeight);

    this->setIsMaxShow(false);
}
