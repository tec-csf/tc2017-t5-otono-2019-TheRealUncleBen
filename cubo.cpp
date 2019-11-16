#include "cubo.h"
#include "ui_cubo.h"
#include <math.h>

Cubo::Cubo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cubo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    centroX = 450.0;
    centroY = 300.0;
    QTransform center;
    center.translate(centroX,centroY);
    vecTrans.push_back(center);
}

Cubo::~Cubo()
{
    delete ui;
}

void dibujaCubo(QPainter &painter){
    int med = 25;

    int x1 = -med;
    int y1 = med;
    int x2 = med;
    int y2 = med;
    int x3 = -med;
    int y3 = -med;
    int x4 = med;
    int y4 = -med;

    int longi = (x2-x1)/2;

    int _x1 = x1 + longi;
    int _y1 = y1 - longi;
    int _x2 = x2 + longi;
    int _y2 = y2 - longi;
    int _x3 = x3 + longi;
    int _y3 = y3 - longi;
    int _x4 = x4 + longi;
    int _y4 = y4 - longi;

    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x1, y1, x3, y3);
    painter.drawLine(x2, y2, x4, y4);
    painter.drawLine(x3, y3, x4, y4);
    painter.drawLine(_x1, _y1, _x2, _y2);
    painter.drawLine(_x1, _y1, _x3, _y3);
    painter.drawLine(_x2, _y2, _x4, _y4);
    painter.drawLine(_x3, _y3, _x4, _y4);
    painter.drawLine(x1, y1, _x1, _y1);
    painter.drawLine(x2, y2, _x2, _y2);
    painter.drawLine(x3, y3, _x3, _y3);
    painter.drawLine(x4, y4, _x4, _y4);

}

void Cubo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    painter.setPen(pointPen);
    if (dibuja) {
        for(int i=0; i<vecTrans.size(); ++i) {
            painter.setTransform(vecTrans[i],true);
            dibujaCubo(painter);
        }
    }
}
void Cubo::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,centroX,centroY);
    update();
}
void Cubo::on_pushButton_2_clicked()
{
    QString yStr = ui->boxYinicio->toPlainText();
    QString xStr = ui->boxXinicio->toPlainText();
    trans.trasladar(xStr, yStr, vecTrans);
    update();
}
void Cubo::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();
    trans.rotar(gradosStr, vecTrans);
    update();
}

void Cubo::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);
    update();
}
void Cubo::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);
    update();
}/

void Cubo::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    update();
}

void Cubo::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    update();
}
