#include "widget.h"
#include "ui_widget.h"

#include <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect (ui->red_slider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect (ui->green_slider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    connect (ui->blue_slider, SIGNAL(valueChanged(int)), SLOT(onColorChanged()));
    onColorChanged();
}

Widget::~Widget()
{
    delete ui;
}

QColor Widget::color() const
{
    return current_color;
}

void Widget::onColorChanged()
{
    current_color.setRgb(ui->red_slider->value(), ui->green_slider->value(), ui->blue_slider->value());
    QPalette palette = ui->colorDisplay->palette();
    palette.setColor(QPalette::Window, current_color);
    ui->colorDisplay->setPalette(palette);
}
