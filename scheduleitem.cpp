#include "scheduleitem.h"

ScheduleItem::ScheduleItem()
    : m_id(-1)
    , m_repeatType(NoRepeat)
    , m_priority(Medium)
    , m_color(Qt::blue)
    , m_completed(false)
{
}

ScheduleItem::ScheduleItem(const QString &title, const QDateTime &startTime)
    : m_id(-1)
    , m_title(title)
    , m_startTime(startTime)
    , m_repeatType(NoRepeat)
    , m_priority(Medium)
    , m_color(Qt::blue)
    , m_completed(false)
{
} 