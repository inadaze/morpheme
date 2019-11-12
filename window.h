#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTextEdit>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private:
    QPushButton *m_button;
    QTextEdit *m_filecontent;
    int m_counter;

signals:
    void counterReached();

public slots:
    void slotButtonClicked(bool checked);
};

#endif // WINDOW_H
