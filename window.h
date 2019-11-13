#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>

class QPushButton;
class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
private:
    QPushButton *m_open_button;
    QPushButton *m_button;
    QTextEdit *m_filecontent;
    QString m_filename;
    QFile *m_current_file;
    int m_counter;

signals:
    void counterReached();

public slots:
    void writeFile();
    void openFileDialog(bool checked);
    void textChangedMessage();
};

#endif // WINDOW_H
