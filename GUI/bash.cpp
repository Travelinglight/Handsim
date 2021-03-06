#include "bash.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

Bash::Bash(QWidget *parent) : QWidget(parent) {
    title = new QLabel(tr("Source Code"));
    title->setAlignment(Qt::AlignCenter);
    text = new QTextEdit;
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(title);
    mainLayout->addWidget(text);
}

void Bash::slotOpen() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/.", "Text files (*.txt)");
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << " Could not open the file for reading";
        return;
    }
    QTextStream in(&file);
    QString bashCode = in.readAll();
    text->clear();
    text->insertPlainText(bashCode);
}

void Bash::slotSave() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "../sourceCode", "Text files (*.txt)");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << " Could not open file for writing";
        return;
    }
    QTextStream out(&file);
    out << text->toPlainText();
    file.flush();
    file.close();
}

void Bash::slotCommit() {
    QFile file("sourceCode.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << " Could not open file for writing";
        return;
    }
    QTextStream out(&file);
    out << text->toPlainText();
    file.flush();
    file.close();
}

void Bash::slotClear() {
    text->clear();
}
