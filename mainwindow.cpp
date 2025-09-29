#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QMovie>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //imagens
    ui->lbl_vencedor->setText("");

    QDir dir(QDir::currentPath());
    QString Leon_png = dir.filePath("leon.png");
    QString CJ_png = dir.filePath("cj.png");

    QPixmap cj(CJ_png);
    QPixmap leon(Leon_png);

    ui->lbl_cj->setPixmap(cj.scaled(320, 280, Qt::KeepAspectRatio));
    ui->lbl_leon->setPixmap(leon.scaled(220, 180, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_cj_clicked()
{
    if(encerrado == true){//votar no cj
        QMessageBox::information(this, "Encerrado", "A votação foi encerrada");
    } else {
        voto_cj++;
        QMessageBox::information(this,"Votado","Votou no CJ");
    }
}


void MainWindow::on_btn_leon_clicked()
{
    if(encerrado == true){//votar no leon
        QMessageBox::information(this, "Encerrado", "A votação foi encerrada");
    } else {
        voto_leon++;
        QMessageBox::information(this,"Votado","Votou no Leon");
    }
}


void MainWindow::on_btn_janela_clicked()
{

    Grafico *wi = new Grafico(voto_cj,voto_leon);//abrir janela  de grafico
    wi->exec();
}

void MainWindow::on_btn_ence_clicked()//encerrar a votação
{
    encerrado = true;
    QMessageBox::information(this, "Encerrado", "A votação foi encerrada");
    QDir dir(QDir::current());
    QString confeti_gif = dir.filePath("confeti.gif");//reproduzir o gif confeti
    QMovie * movie = new QMovie(confeti_gif);
    ui->lbl_confeti->setMovie(movie);
    movie->start();

    Grafico *wi = new Grafico(voto_cj,voto_leon);//mensagem de vencedor
    wi->exec();
    if(voto_leon > voto_cj){
        ui->lbl_vencedor->setText("Vencedor: Leon");
    }else if(voto_leon < voto_cj){
        ui->lbl_vencedor->setText("Vencedor: CJ");
    }else{
        ui->lbl_vencedor->setText("Ocorreu empate");
    }
}
