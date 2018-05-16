#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QByteArray>
#include <QListWidget>
#include <QListWidgetItem>
#include <QListView>
#include <QStringListModel>

#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QVBoxLayout *mainLayout;
    QPushButton *buttonCreateObject;
    QPushButton *buttonDeleteObject;
    QPushButton *buttonCreateRam;
    QPushButton *buttonClearRam;
    QPushButton *buttonDeleteModel;
    void createForm();

    QListWidget *listWidget;
    QVector<QListWidgetItem*> items;

    QStringListModel *stringListModel;
    QListView *listView;
    QStringList *myData;

    QByteArray *array;
    char *array2;

private slots:
    void slotPushCreateRam();
    void slotPushClearRam();

    void slotPushCreateObject();
    void slotPushDeleteObject();
    void slotPushDeleteModel();

    void slotListWidgetDestroyed(QObject *object);

};

#endif // WIDGET_H
