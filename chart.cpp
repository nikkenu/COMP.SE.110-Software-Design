#include "chart.h"
#include <QDebug>

Chart::Chart(QObject *parent) : QObject(parent)
{

}

Chart::~Chart()
{

}

void Chart::getData(const QString &title)
{
    emit apiRequest(title);
}
