#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include "grafico.h"
#include "QMovie"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots://funções
    void on_btn_cj_clicked();

    void on_btn_leon_clicked();

    void on_btn_janela_clicked();

    void on_btn_ence_clicked();

private://variaveis
    Ui::MainWindow *ui;
    int voto_cj = 0;
    int voto_leon = 0;
    bool encerrado = false;
    QString Leon_png, CJ_png, confeti_gif;
};
#endif // MAINWINDOW_H
