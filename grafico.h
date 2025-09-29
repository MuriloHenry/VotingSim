#ifndef GRAFICO_H
#define GRAFICO_H

#include <QDialog>
#include <QTableWidget>
#include <QProgressBar>

namespace Ui {
class Grafico;
}

class Grafico : public QDialog
{
    Q_OBJECT

public:
    explicit Grafico(int, int, QWidget *parent = nullptr);
    ~Grafico();

private slots:


private:
    Ui::Grafico *ui;
    int total, porc_cj, porc_leon;
    QProgressBar *progressBar;
};

#endif // GRAFICO_H
