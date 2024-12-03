#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupUI();
    createConnections();
    
    // 设置窗口标题和大小
    setWindowTitle("桌面日历");
    resize(800, 600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    // 创建中央部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    
    // 创建顶部日期显示标签
    currentDateLabel = new QLabel(this);
    currentDateLabel->setAlignment(Qt::AlignCenter);
    QFont font = currentDateLabel->font();
    font.setPointSize(14);
    currentDateLabel->setFont(font);
    
    // 设置窗口背景色
    this->setStyleSheet("QMainWindow { background-color: #f5f6fa; }");
    
    // 设置日期标签样式
    currentDateLabel->setStyleSheet(
        "QLabel {"
        "    color: #2c3e50;"
        "    padding: 10px;"
        "    margin: 10px;"
        "    background-color: white;"
        "    border-radius: 8px;"
        "    border: 1px solid #e0e0e0;"
        "}"
    );
    
    // 创建日历控件
    calendar = new QCalendarWidget(this);
    calendar->setMinimumDate(QDate(1900, 1, 1));
    calendar->setMaximumDate(QDate(3000, 1, 1));
    calendar->setGridVisible(true);
    calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendar->setNavigationBarVisible(true);
    
    // 设置日历样式
    calendar->setStyleSheet(
        "QCalendarWidget {"
        "    background-color: white;"
        "    border-radius: 8px;"
        "    border: 1px solid #e0e0e0;"
        "}"
        "QCalendarWidget QToolButton#qt_calendar_prevmonth {"
        "    qproperty-icon: url(:/img/up.png);"
        "    qproperty-iconSize: 24px;"
        "    height: 36px;"
        "    width: 36px;"
        "    color: transparent;"
        "    background-color: white;"
        "    border-radius: 4px;"
        "    border: 1px solid #e0e0e0;"
        "    margin: 5px;"
        "}"
        "QCalendarWidget QToolButton#qt_calendar_nextmonth {"
        "    qproperty-icon: url(:/img/down.png);"
        "    qproperty-iconSize: 24px;"
        "    height: 36px;"
        "    width: 36px;"
        "    color: transparent;"
        "    background-color: white;"
        "    border-radius: 4px;"
        "    border: 1px solid #e0e0e0;"
        "    margin: 5px;"
        "}"
        "QCalendarWidget QToolButton {"
        "    height: 36px;"
        "    width: 120px;"
        "    color: #2c3e50;"
        "    font-size: 14px;"
        "    icon-size: 24px, 24px;"
        "    background-color: white;"
        "    border-radius: 4px;"
        "    border: 1px solid #e0e0e0;"
        "    margin: 5px;"
        "}"
        "QCalendarWidget QToolButton:hover {"
        "    background-color: #f8f9fa;"
        "    border: 1px solid #3498db;"
        "}"
        "QCalendarWidget QMenu {"
        "    width: 150px;"
        "    left: 20px;"
        "    color: #2c3e50;"
        "    background-color: white;"
        "    border: 1px solid #e0e0e0;"
        "}"
        "QCalendarWidget QSpinBox {"
        "    width: 100px;"
        "    font-size: 14px;"
        "    color: #2c3e50;"
        "    background-color: white;"
        "    selection-background-color: #3498db;"
        "    selection-color: white;"
        "}"
        "QCalendarWidget QTableView {"
        "    border: none;"
        "    background-color: white;"
        "}"
        "QCalendarWidget QTableView:enabled {"
        "    color: #2c3e50;"
        "}"
        "QCalendarWidget QTableView:disabled {"
        "    color: #999999;"
        "}"
        "QCalendarWidget QTableView::item:hover {"
        "    background-color: #f0f7ff;"
        "    color: #2c3e50 !important;"
        "    border-radius: 4px;"
        "}"
        "QCalendarWidget QTableView::item:selected {"
        "    background-color: #3498db;"
        "    color: white !important;"
        "    border-radius: 4px;"
        "}"
        "QCalendarWidget QAbstractItemView:enabled {"
        "    color: #2c3e50;"
        "}"
        "QCalendarWidget QAbstractItemView:disabled {"
        "    color: #999999;"
        "}"
        "QCalendarWidget QWidget {"
        "    alternate-background-color: #fafafa;"
        "}"
        "QCalendarWidget QWidget#qt_calendar_navigationbar {"
        "    background-color: white;"
        "    border-top-left-radius: 8px;"
        "    border-top-right-radius: 8px;"
        "    padding: 4px;"
        "}"
    );
    
    // 设置主布局的边距和间距
    mainLayout->setContentsMargins(20, 20, 20, 20);
    mainLayout->setSpacing(15);
    
    // 添加到主布局
    mainLayout->addWidget(currentDateLabel);
    mainLayout->addWidget(calendar);
    
    // 更新当前日期显示
    currentDateLabel->setText(QDate::currentDate().toString("yyyy年MM月dd日 dddd"));
}

void MainWindow::createConnections()
{
    // 连接日期选择信号
    connect(calendar, &QCalendarWidget::selectionChanged, [this]() {
        QDate selectedDate = calendar->selectedDate();
        currentDateLabel->setText(selectedDate.toString("yyyy年MM月dd日 dddd"));
    });
}
