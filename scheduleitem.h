#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <QString>
#include <QDateTime>
#include <QColor>

class ScheduleItem
{
public:
    enum RepeatType {
        NoRepeat,       // 不重复
        Daily,          // 每天
        Weekly,         // 每周
        Monthly,        // 每月
        Yearly          // 每年
    };

    enum Priority {
        Low,            // 低优先级
        Medium,         // 中优先级
        High            // 高优先级
    };

public:
    ScheduleItem();
    ScheduleItem(const QString &title, const QDateTime &startTime);

    // Getters
    int id() const { return m_id; }
    QString title() const { return m_title; }
    QString description() const { return m_description; }
    QDateTime startTime() const { return m_startTime; }
    QDateTime endTime() const { return m_endTime; }
    QDateTime reminderTime() const { return m_reminderTime; }
    RepeatType repeatType() const { return m_repeatType; }
    Priority priority() const { return m_priority; }
    QColor color() const { return m_color; }
    bool isCompleted() const { return m_completed; }

    // Setters
    void setId(int id) { m_id = id; }
    void setTitle(const QString &title) { m_title = title; }
    void setDescription(const QString &description) { m_description = description; }
    void setStartTime(const QDateTime &startTime) { m_startTime = startTime; }
    void setEndTime(const QDateTime &endTime) { m_endTime = endTime; }
    void setReminderTime(const QDateTime &reminderTime) { m_reminderTime = reminderTime; }
    void setRepeatType(RepeatType type) { m_repeatType = type; }
    void setPriority(Priority priority) { m_priority = priority; }
    void setColor(const QColor &color) { m_color = color; }
    void setCompleted(bool completed) { m_completed = completed; }

private:
    int m_id;                  // 事件ID
    QString m_title;           // 事件标题
    QString m_description;     // 事件描述
    QDateTime m_startTime;     // 开始时间
    QDateTime m_endTime;       // 结束时间
    QDateTime m_reminderTime;  // 提醒时间
    RepeatType m_repeatType;   // 重复类型
    Priority m_priority;       // 优先级
    QColor m_color;           // 事件颜色
    bool m_completed;         // 是否完成
};

#endif // SCHEDULEITEM_H 