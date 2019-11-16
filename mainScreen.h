#include <QMainDialog>
#include "poli.h"
#include "arco.h"
#include "cubo.h"
#include "prismRec.h"
#include "prismTri.h"
#include "cono.h"

namespace Ui {
class MainScreen;
}

class MainScreen : public QMainScreen
{
    Q_OBJECT

public:
    explicit MainScreen(QWidget *parent = 0);
    ~MainScreen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainScreen *ui;
};
