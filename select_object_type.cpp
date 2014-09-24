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

void select_object_type::GetTree(QTreeWidget *_tree)
{
    tree = _tree;
}

void select_object_type::FillList()
{
    QSqlQuery q;
    q.prepare("SELECT * FROM object_types;");
    q.exec();
    while (q.next())
    {
        QListWidgetItem* itm = new QListWidgetItem();
        itm->setText(q.value(1).toString());
        itm->setData(Qt::UserRole, q.value(0).toInt());
        ui->type_list->addItem(itm);
    }
}

select_object_type::~select_object_type()
{
    delete ui;
}

void select_object_type::on_back_pb_clicked()
{
    this->close();
}

void select_object_type::on_next_pb_clicked()
{
    add_item *add_item_form = new add_item();
    //add_item_form->GetTree(tree, "object_types");
    add_item_form->GetTypeObj(tree, ui->type_list->currentItem());
    add_item_form->show();
    this->close();
}
