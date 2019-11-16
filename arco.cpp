#include "arco.h"
#include <math.h>
#include <QMessageBox>
#include "ui_arco.h"

#define PI 3.14159265

Arco::Arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arcos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    centroX = 450.0;
    centroY = 300.0;
    QTransform center;
    center.translate(centroX,centroY);
    vecTrans.push_back(center);
}

Arco::~Arco()
{
    delete ui;
}

void puntosCirculo(int & x, int & y, int & ang, QPainter & painter) {

    int oct = (ang - (ang % 45)) / 45;
    double limiteA = tan((90.0 - (ang % 90)) * PI / 180.0) * x;
    double limiteB = tan((45.0 + (ang % 45)) * PI / 180.0) * x;

    if (oct > 0 || (oct == 0 && y > limiteA))
        painter.drawPoint(x,-y);
    if (oct > 1 || (oct == 1 && y <= limiteB))
        painter.drawPoint(y,-x);
    if (oct > 2 || (oct == 2 && y > limiteA))
        painter.drawPoint(y,x);
    if (oct > 3 || (oct == 3 && y <= limiteB))
        painter.drawPoint(x,y);
    if (oct > 4 || (oct == 4 && y > limiteA))
        painter.drawPoint(-x,y);
    if (oct > 5 || (oct == 5 && y <= limiteB))
        painter.drawPoint(-y,x);
    if (oct > 6 || (oct == 6 && y > limiteA))
        painter.drawPoint(-y,-x);
    if (oct > 7 || (oct == 7 && y <= limiteB))
        painter.drawPoint(-x,-y);

}

void dibujarArco(int ang, int rad, QPainter & painter) {

    int y = rad;
    int x = 0;
    double p = 5.0/4.0-y;

    puntosCirculo(x, y, ang, painter);
    while(y > x) {
        if(p < 0) {
            p += 2.0 * x + 3.0;
        }
        else {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }
        x++;
        puntosCirculo(x, y, ang, painter);
    }

}

void Arco::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(pointPen);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);

    if (dibuja) {

        QString angStr = ui->boxang->toPlainText();
        QString radStr = ui->boxrad->toPlainText();
        int rad = radStr.toInt();
        int ang = angStr.toInt();
        if (!radStr.isEmpty() && !angStr.isEmpty()) {
            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarArco(ang, rad,  painter);

            }

        }

    }

}

void Arco::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,centroX,centroY);
    update();

}

void Arco::on_pushButton_2_clicked()
{
    QString yStr = ui->boxYinicio->toPlainText();
    QString xStr = ui->boxXinicio->toPlainText();
    trans.trasladar(xStr, yStr, vecTrans);
    update();

}

void Arco::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();
    trans.rotar(gradosStr, vecTrans);
    update();

}

void Arco::on_pushButton_4_clicked()
{
    trans.zoomIn(vecTrans);
    update();

}
void Arco::on_pushButton_5_clicked()
{
    trans.zoomOut(vecTrans);
    update();

}

void Arco::on_pushButton_6_clicked()
{
    trans.reflexVertical(vecTrans);
    update();

}
void Arco::on_pushButton_7_clicked()
{
    trans.reflexHorizontal(vecTrans);
    update();

}
