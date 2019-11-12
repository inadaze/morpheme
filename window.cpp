#include "window.h"
#include <QPushButton>
#include <QApplication>
#include <QTextEdit>

Window::Window(QWidget *parent) : QWidget(parent)
{
    setFixedSize(500, 500);

    m_button = new QPushButton("Hello", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    m_filecontent = new QTextEdit("Hello", this);
    m_filecontent->setGeometry(50, 50, 80, 30);

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
    connect(this, SIGNAL (counterReached()), QApplication::instance(), SLOT (quit()));

}

void Window::slotButtonClicked(bool checked)
{
    if (checked) {
        m_button->setText("Checked");
    } else {
        m_button->setText("Hello");
    }

    m_counter++;
    if (m_counter == 10) {
        emit counterReached();
    }
}
