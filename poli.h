#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "transformaciones.h"

namespace Ui {
class Poligonos;
}

class Poligonos : public QDialog
{
    Q_OBJECT

public:
    explicit Poligonos(QWidget *parent = 0);
    ~Poligonos();

private:
    Ui::Poligonos *ui;
    bool dibuja = false;

    double centroX;
    double centroY;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
};

