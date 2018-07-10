#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtdialog.h"
#include "ui_qtdialog.h"
#pragma GCC diagnostic pop

QtDialog::QtDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtDialog)
{
  ui->setupUi(this);

  QTableWidget * const t = ui->tableWidget;
  t->setRowCount(10);
  const int n_rows = t->rowCount();
  const int n_cols = t->columnCount();
  for (int col=0; col!=n_cols; ++col)
  {
    for (int row=0; row!=n_rows; ++row)
    {
      t->setRowHeight(row,ui->tableWidget->fontMetrics().height() * 2 * (row + 1));

      QTableWidgetItem * const i = new QTableWidgetItem;
      if (col != 3)
      {
        //Checkbox
        i->setFlags(
            Qt::ItemIsSelectable
          | Qt::ItemIsUserCheckable
        );
        i->setCheckState(Qt::Unchecked);
      }
      else
      {
        //Text
        i->setFlags(
            Qt::ItemIsSelectable
          | Qt::ItemIsEditable
          | Qt::ItemIsEnabled);
        QString s;
        for (int sub_row=0;sub_row!=row; ++sub_row)
        {
          s += QString::number(sub_row) + "\n";
        }
        if (!s.isEmpty()) s.resize(s.size() - 1);
        i->setText(s);
      }
      t->setItem(row, col, i);
    }
  }
  t->setColumnWidth(0,24);
  t->setColumnWidth(1,24);
  t->setColumnWidth(2,24);
}

QtDialog::~QtDialog() noexcept
{
  delete ui;
}
