#include "window.h"
#include <iostream>
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QDataStream>
#include <QTextStream>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500, 500);

    m_button = new QPushButton("Save", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    m_open_button = new QPushButton("Open", this);
    m_open_button->setGeometry(10, 40, 80, 30);
    m_open_button->setCheckable(true);

    m_filecontent = new QTextEdit("Write text here...", this);
    m_filecontent->setGeometry(50, 80, 400, 400);

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (writeFile()));
    connect(m_open_button, SIGNAL (clicked(bool)), this, SLOT (openFileDialog(bool)));
    connect(m_filecontent, SIGNAL (textChanged()), this, SLOT (textChangedMessage()));

}

void Window::writeFile()
{
    QFile file(m_filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QTextStream out(&file);
    out << m_filecontent->toPlainText().toUtf8();
    file.close();


//    if (checked) {
//        m_button->setText("Checked");
//    } else {
//        m_button->setText("Hello");
//    }

//    m_counter++;
//    if (m_counter == 10) {
//        emit counterReached();
//    }
}

void Window::openFileDialog(bool checked)
{
    if (checked) {
        m_filename = QFileDialog::getOpenFileName(this,
            tr("Open File"), "/Users", tr("Text Files (*.txt)"));
        m_current_file = new QFile(m_filename);

        if (!m_current_file->open(QIODevice::ReadWrite)) {
                    QMessageBox::information(this, tr("Unable to open file"),
                        m_current_file->errorString());
                    return;
                }
        m_filecontent->setText(m_current_file->readAll());
        m_current_file->close();
    }
}

void Window::textChangedMessage()
{
    std::cerr << "The Text has changed " << std::endl;
    if (m_filecontent->toPlainText().endsWith(" ")){
        std::cerr << "There is a space " << std::endl;
        // TODO: identify word before the space
        // send request to fetch synonyms
        // Display synonyms in new popup window
    }
}
