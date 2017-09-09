#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QWidget>
#include <QComboBox>

class MyComboBox : public QComboBox
{
  Q_OBJECT

public:
  MyComboBox(QWidget *parent = 0);
  ~MyComboBox();

protected:
  //virtual void focusInEvent(QFocusEvent *e);

private slots:
  void ActiveClavier();
};

#endif // MYCOMBOBOX_H
