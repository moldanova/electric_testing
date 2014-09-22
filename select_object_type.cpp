#include "select_object_type.h"
#include "ui_select_object_type.h"

select_object_type::select_object_type(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_object_type)
{
    ui->setupUi(this);
    this->setWindowTitle("Выберите тип объекта");
    this->setFixedSize(391, 418);
    FillList();
}

void select_object_type::FillList()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM object_types;");
    q.exec();
    QListWidgetItem *itm = new QListWidgetItem(q.value(1).toString(), 0, q.value(0).toInt());
    while (q.next())
    {
        ui->type_list->addItem(q.value(1).toString());
    }
}

select_object_type::~select_object_type()
{
    delete ui;
}
