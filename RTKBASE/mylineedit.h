#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
  Q_OBJECT

public:
  MyLineEdit(QWidget *parent = 0);
  ~MyLineEdit();

protected:
  virtual void focusInEvent(QFocusEvent *e);
};

#endif // MYLINEEDIT_H
