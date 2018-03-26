#ifndef SUSANLISTWIDGET_H
#define SUSANLISTWIDGET_H
#include <QListWidget>
#include <QString>

class QListWidget;

class SusanListWidget : public QListWidget
{
    Q_OBJECT

public:

    SusanListWidget(QWidget *xParent = 0);
public slots:
    void addListItem(QString);

};

#endif // SUSANLISTWIDGET_H
