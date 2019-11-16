#include "mainScreen.h"
#include "ui_mainScreen.h"

mainScreen::mainScreen(QWidget *parent) : QmainScreen(parent), ui(new Ui::mainScreen)
{
    ui->setupUi(this);
}

mainScreen::~mainScreen()
{
    delete ui;
}

void mainScreen::on_pushButton_4_clicked()
{
   
    PrismaRec prismaRectangular;
    prismaRectangular.setModal(true);
    prismaRectangular.exec();

}

void mainScreen::on_pushButton_clicked()
{
    Poligonos poligonos;
    poligonos.setModal(true);
    poligonos.exec();
}

void mainScreen::on_pushButton_2_clicked()
{
    Arco arco;
    arco.setModal(true);
    arco.exec();
}

void mainScreen::on_pushButton_3_clicked()
{
    cubo.setModal(true);
    cubo.exec();
}
void mainScreen::on_pushButton_6_clicked()
{
    
   
    cono.setModal(true);
    cono.exec();
}

void mainScreen::on_pushButton_5_clicked()
{
    
    PrismaTri prismaTriangular;
    prismaTriangular.setModal(true);
    prismaTriangular.exec();
}

