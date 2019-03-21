#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QColor color() const;

private slots:
    void onColorChanged();

private:
    Ui::Widget *ui;
    QColor current_color;
};

#endif // WIDGET_H
