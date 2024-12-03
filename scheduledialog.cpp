#include "scheduledialog.h"
#include "ui_scheduledialog.h"
#include <QColorDialog>
#include <QPushButton>
#include <QMessageBox>

ScheduleDialog::ScheduleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleDialog)
    , m_currentColor(Qt::blue)
{
    ui->setupUi(this);
    setupUI();
    createConnections();
}

ScheduleDialog::~ScheduleDialog()
{
    delete ui;
}

void ScheduleDialog::setupUI()
{
    // 设置窗口标题
    setWindowTitle(tr("添加事件"));

    // 设置重复类型选项
    ui->repeatTypeComboBox->addItem(tr("不重复"), ScheduleItem::NoRepeat);
    ui->repeatTypeComboBox->addItem(tr("每天"), ScheduleItem::Daily);
    ui->repeatTypeComboBox->addItem(tr("每周"), ScheduleItem::Weekly);
    ui->repeatTypeComboBox->addItem(tr("每月"), ScheduleItem::Monthly);
    ui->repeatTypeComboBox->addItem(tr("每年"), ScheduleItem::Yearly);

    // 设置优先级选项
    ui->priorityComboBox->addItem(tr("低"), ScheduleItem::Low);
    ui->priorityComboBox->addItem(tr("中"), ScheduleItem::Medium);
    ui->priorityComboBox->addItem(tr("高"), ScheduleItem::High);

    // 设置默认时间
    QDateTime currentDateTime = QDateTime::currentDateTime();
    ui->startDateTimeEdit->setDateTime(currentDateTime);
    ui->endDateTimeEdit->setDateTime(currentDateTime.addSecs(3600));
    ui->reminderDateTimeEdit->setDateTime(currentDateTime);

    updateColorButton();
}

void ScheduleDialog::createConnections()
{
    connect(ui->repeatTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ScheduleDialog::onRepeatTypeChanged);
    connect(ui->priorityComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ScheduleDialog::onPriorityChanged);
    connect(ui->colorButton, &QPushButton::clicked,
            this, &ScheduleDialog::onColorButtonClicked);
}

void ScheduleDialog::setScheduleItem(const ScheduleItem &item)
{
    ui->titleLineEdit->setText(item.title());
    ui->descriptionTextEdit->setText(item.description());
    ui->startDateTimeEdit->setDateTime(item.startTime());
    ui->endDateTimeEdit->setDateTime(item.endTime());
    ui->reminderDateTimeEdit->setDateTime(item.reminderTime());
    ui->repeatTypeComboBox->setCurrentIndex(item.repeatType());
    ui->priorityComboBox->setCurrentIndex(item.priority());
    m_currentColor = item.color();
    updateColorButton();
}

ScheduleItem ScheduleDialog::scheduleItem() const
{
    ScheduleItem item;
    item.setTitle(ui->titleLineEdit->text());
    item.setDescription(ui->descriptionTextEdit->toPlainText());
    item.setStartTime(ui->startDateTimeEdit->dateTime());
    item.setEndTime(ui->endDateTimeEdit->dateTime());
    item.setReminderTime(ui->reminderDateTimeEdit->dateTime());
    item.setRepeatType(static_cast<ScheduleItem::RepeatType>(ui->repeatTypeComboBox->currentData().toInt()));
    item.setPriority(static_cast<ScheduleItem::Priority>(ui->priorityComboBox->currentData().toInt()));
    item.setColor(m_currentColor);
    return item;
}

void ScheduleDialog::onRepeatTypeChanged(int index)
{
    // 可以根据重复类型来调整UI
}

void ScheduleDialog::onPriorityChanged(int index)
{
    // 可以根据优先级来调整UI
}

void ScheduleDialog::onColorButtonClicked()
{
    QColor color = QColorDialog::getColor(m_currentColor, this, tr("选择颜色"));
    if (color.isValid()) {
        m_currentColor = color;
        updateColorButton();
    }
}

void ScheduleDialog::updateColorButton()
{
    QString styleSheet = QString("background-color: %1; border: 1px solid #c0c0c0; border-radius: 4px;")
                            .arg(m_currentColor.name());
    ui->colorButton->setStyleSheet(styleSheet);
} 