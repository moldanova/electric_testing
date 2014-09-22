#include "select_object_type.h"
#include "ui_select_object_type.h"

select_object_type::select_object_type(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::select_object_type)
{
    ui->setupUi(this);
}

select_object_type::~select_object_type()
{
    delete ui;
}
