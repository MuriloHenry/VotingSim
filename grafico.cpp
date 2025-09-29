#include "grafico.h"
#include "ui_grafico.h"

Grafico::Grafico(int cj, int leon, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Grafico)
{

    ui->setupUi(this);


    total = cj + leon;
    if(total==0){
        porc_cj = 0;
        porc_leon = 0;
    }else{
        porc_cj = (cj*100)/total;
        porc_leon = (leon*100)/total;
    }

    // seta coluna e linha
    ui->tbt_votos->setRowCount(1);
    ui->tbt_votos->setColumnCount(2);

    // seta tamanho
    ui->tbt_votos->setColumnWidth(0,128);
    ui->tbt_votos->setColumnWidth(1,128);

    // diz que vai ser centralizado o numero
    QTableWidgetItem *item_cj = new QTableWidgetItem(QString::number(cj));
    item_cj->setTextAlignment(Qt::AlignCenter);
    QTableWidgetItem *item_leon = new QTableWidgetItem(QString::number(leon));
    item_leon->setTextAlignment(Qt::AlignCenter);

    // nao deixa o user mudar tamanho e tira o numero da linha
    ui->tbt_votos->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tbt_votos->verticalHeader()->setVisible(false);

    // bota o voto
    ui->tbt_votos->setItem(0,0,item_cj);
    ui->tbt_votos->setItem(0,1,item_leon);

    //exibe o total de votos
    ui->lbl_total->setText("Total de votos: " + QString::number(total));

    //porcentagem votos

    ui->pgs_cj->setFormat("%p%");
    ui->pgs_leon->setFormat("%p%");

    ui->pgs_cj->setValue(porc_cj);
    ui->pgs_leon->setValue(porc_leon);

    ui->pgs_cj->setTextVisible(true);
}

Grafico::~Grafico()
{
    delete ui;
}

