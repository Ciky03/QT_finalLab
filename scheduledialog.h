#ifndef SCHEDULEDIALOG_H
#define SCHEDULEDIALOG_H

#include <QDialog>
#include <QDateTime>
#include "scheduleitem.h"

namespace Ui {
class ScheduleDialog;
}

class ScheduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleDialog(QWidget *parent = nullptr);
    ~ScheduleDialog();

    void setScheduleItem(const ScheduleItem &item);
    ScheduleItem scheduleItem() const;

private slots:
    void onRepeatTypeChanged(int index);
    void onPriorityChanged(int index);
    void onColorButtonClicked();

private:
    void setupUI();
    void createConnections();
    void updateColorButton();

private:
    Ui::ScheduleDialog *ui;
    QColor m_currentColor;
};

#endif // SCHEDULEDIALOG_H 