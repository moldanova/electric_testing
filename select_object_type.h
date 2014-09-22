#ifndef SELECT_OBJECT_TYPE_H
#define SELECT_OBJECT_TYPE_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class select_object_type;
}

class select_object_type : public QWidget
{
    Q_OBJECT

public:
    explicit select_object_type(QWidget *parent = 0);
    ~select_object_type();

private:
    Ui::select_object_type *ui;
    void FillList();
};

#endif // SELECT_OBJECT_TYPE_H
