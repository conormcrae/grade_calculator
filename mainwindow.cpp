#include "mainwindow.h"
#include "ui_widget.h"
//#include <vector>
//#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->spinBox,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_2,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_3,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_4,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_5,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_6,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_7,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_8,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_9,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_10,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );
    QObject::connect(ui->spinBox_11,SIGNAL(valueChanged(int)),
                     this,SLOT(compute_grade()) );

    QObject::connect(ui->label_14,SIGNAL(valueChanged(Qstring)),
                     this,SLOT(compute_grade()) );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::compute_grade() const
{
    std::vector<int> homeworks(8);
    homeworks[0] = ui->spinBox->value();
    homeworks[1] = ui->spinBox_2->value();
    homeworks[2] = ui->spinBox_3->value();
    homeworks[3] = ui->spinBox_4->value();
    homeworks[4] = ui->spinBox_5->value();
    homeworks[5] = ui->spinBox_6->value();
    homeworks[6] = ui->spinBox_7->value();
    homeworks[7] = ui->spinBox_8->value();

    double midterm1 = (double)(ui->spinBox_9->value());
    double midterm2 = (double)(ui->spinBox_10->value());
    double final = (double)(ui->spinBox_11->value());

    double highest_midterm;
    double grade;

    if (midterm1 > midterm2)
        highest_midterm = midterm1;
    else
        highest_midterm = midterm2;

    int least = homeworks[0];
    for (int i = 1; i < homeworks.size(); ++i)
    {
        if (least < homeworks[i])
            least = homeworks[i];
    }

    int removal_pos = 0;

    while (homeworks[removal_pos] != least)
        ++removal_pos;

    for (int j = removal_pos + 1; j < homeworks.size(); ++j)
        homeworks[j - 1] = homeworks[j];

    homeworks.pop_back();

    int homework_sum = 0;
    for (int i = 0; i < homeworks.size(); ++i)
        homework_sum += homeworks[i];

    double homework_score = (double)(homework_sum)/homeworks.size();

    double schemeA = (0.25*homework_score + 0.2*midterm1 + 0.2*midterm2 + 0.35*final);
    double schemeB = (0.25*homework_score + 0.35*highest_midterm + 0.44*final);

    if (schemeA > schemeB)
        grade = schemeA;
    else
        grade = schemeB;

    int grade_out = (int)(grade + 0.5);

    ui->spinBox_12->setValue(grade_out);

    QString letter_grade = "F";

    if (60 <= grade_out && grade_out <=62)
        letter_grade = "D-";
    else if (63 <= grade_out && grade_out <=66)
        letter_grade = "D";
    else if (67 <= grade_out && grade_out <=69)
        letter_grade = "D+";
    else if (70 <= grade_out && grade_out <=72)
        letter_grade = "C-";
    else if (73 <= grade_out && grade_out <=76)
        letter_grade = "C";
    else if (77 <= grade_out && grade_out <=79)
        letter_grade = "C+";
    else if (80 <= grade_out && grade_out <=82)
        letter_grade = "B-";
    else if (83 <= grade_out && grade_out <=86)
        letter_grade = "B";
    else if (87 <= grade_out && grade_out <=89)
        letter_grade = "B+";
    else if (90 <= grade_out && grade_out <=92)
        letter_grade = "A-";
    else if (93 <= grade_out)
        letter_grade = "A";

    ui->label_14->setText(letter_grade);



}
