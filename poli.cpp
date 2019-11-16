#include "poli.h"
#include "ui_poli.h"
#include <QMessageBox>
#include <math.h>

Poli::Poli(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poli)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    centroX = 450.0;
    centroY = 300.0;
    QTransform centro;
    centro.translate(centroX,centroY);
    vecTrans.push_back(centro);

}

Poli::~Poli()
{
    delete ui;
}

void dibujarPoligono(int lados, QPainter & painter) {

    double radio = 100;
    double angulo = (double)360.0/(double)lados;
    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;
    for(a = 1; a <= lados; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        painter.drawLine(xi, yi, xf, yf);
    }
}

void Poli::paintEvent(QPaintEvent *e)
{
    QPen pointPen(Qt::black);
    QPainter painter(this);
    painter.setPen(pointPen);
    pointPen.setWidth(2);
    if (dibuja) {
        QString ladosStr = ui->boxXfin->toPlainText();
        if (!ladosStr.isEmpty()) {
            int lados = ladosStr.toInt();
            for(int i=0; i<vecTrans.size(); ++i) {
                painter.setTransform(vecTrans[i],true);
                dibujarPoligono(lados, painter);
            }
        }
    }
}
void Poli::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,centroX,centroY);

    update();

}
void Poli::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);
    update();
}
void Poli::on_pushButton_2_clicked()
{
    QString yStr = ui->boxYinicio->toPlainText();
    QString xStr = ui->boxXinicio->toPlainText();
    trans.trasladar(xStr, yStr, vecTrans);
    update();

}

void Poli::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();
    trans.rotar(gradosStr, vecTrans);
    update();
}

void Poli::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);
    update();
}

void Poli::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);
    update();
}


void Poli::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);
    update();
}
