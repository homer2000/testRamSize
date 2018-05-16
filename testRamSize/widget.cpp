#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    createForm();

    myData = new QStringList;
}

Widget::~Widget()
{

}

void Widget::createForm()
{
    mainLayout = new QVBoxLayout(this);
    buttonCreateRam = new QPushButton(tr("Create array"),this);
    connect(buttonCreateRam,SIGNAL(pressed()),this,SLOT(slotPushCreateRam()));
    mainLayout->addWidget(buttonCreateRam);

    buttonClearRam = new QPushButton(tr("Clear array"),this);
    connect(buttonClearRam,SIGNAL(pressed()),this,SLOT(slotPushClearRam()));
    mainLayout->addWidget(buttonClearRam);

    buttonCreateObject = new QPushButton(tr("Create object"),this);
    connect(buttonCreateObject,SIGNAL(pressed()),this,SLOT(slotPushCreateObject()));
    mainLayout->addWidget(buttonCreateObject);

    buttonDeleteObject = new QPushButton(tr("Delete object"),this);
    connect(buttonDeleteObject,SIGNAL(pressed()),this,SLOT(slotPushDeleteObject()));
    mainLayout->addWidget(buttonDeleteObject);

    buttonDeleteModel = new QPushButton(tr("Delete model"),this);
    connect(buttonDeleteModel,SIGNAL(pressed()),this,SLOT(slotPushDeleteModel()));
    mainLayout->addWidget(buttonDeleteModel);

    /*
    listWidget = new QListWidget(this);
    connect(listWidget,SIGNAL(destroyed(QObject*)),this,SLOT(slotListWidgetDestroyed(QObject*)));
    mainLayout->addWidget(listWidget);
    */

    listView = new QListView(this);
    mainLayout->addWidget(listView);
    stringListModel = new QStringListModel(listView);
    listView->setModel(stringListModel);

}

void Widget::slotPushCreateRam()
{
    int size = 2000000;
    array2 = new char[size];

    QListWidgetItem *item;

    myData->clear();


    for (int i=0;i<size;i++)
    {
        *myData << QString::number(i);

        /*
        item = new QListWidgetItem(QString::number(i),listWidget);
        listWidget->addItem(item);
        items.push_back(item);
        */
    }
    stringListModel->setStringList(*myData);
      //array2[i]=0xa0;
        //array->push_back(0xA0);
}

void Widget::slotPushClearRam()
{
    //listWidget->clear();
    /*
    QListWidgetItem *item;
    for (int i=0;i<items.length();i++)
    {
        item = items.at(i);
        delete item;
    }
    items.clear();
    listWidget->clear();
    //delete[] array2;
    */

    myData->clear();
    stringListModel->setStringList(QStringList{});

}

void Widget::slotPushCreateObject()
{
    listWidget = new QListWidget(this);
    connect(listWidget,SIGNAL(destroyed(QObject*)),this,SLOT(slotListWidgetDestroyed(QObject*)));
    mainLayout->addWidget(listWidget);
}

void Widget::slotPushDeleteObject()
{
    //delete listWidget;
    delete listView;
}

void Widget::slotPushDeleteModel()
{
    delete stringListModel;
    delete myData;
}

void Widget::slotListWidgetDestroyed(QObject *object)
{
    qDebug()<<"List widget destroyed";
}
