#ifndef LEARNQTLOGO_HPP
#define LEARNQTLOGO_HPP

#include <QtQML>
#include <QImage>
#include <QObject>
#include <QQuickPaintedItem>

class LearnQtLogo : public QQuickPaintedItem {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QColor bgColor READ bgColor WRITE setBgColor NOTIFY bgColorChanged)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor NOTIFY textColorChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QtTopic topic READ topic WRITE setTopic NOTIFY topicChanged)
public:
    explicit LearnQtLogo(QQuickItem *po_parent = nullptr);

    enum QtTopic {
        QTCPP
        , QTQUICK
    };
    Q_ENUM(QtTopic)

    // QQuickPaintedItem interface
    void paint(QPainter *po_painter);

    // Properties
    QColor bgColor() const;
    void setBgColor(const QColor &o_bgColor);
    QColor textColor() const;
    void setTextColor(const QColor &o_textColor);
    QString text() const;
    void setText(const QString &o_text);
    QtTopic topic() const;
    void setTopic(const QtTopic &e_topic);

signals:
    void bgColorChanged(const QColor &o_bgColor);
    void textColorChanged(const QColor &o_textColor);
    void textChanged(const QString &o_text);
    void topicChanged(const QtTopic e_topic);

private:
    QColor  _o_bgColor;
    QColor  _o_textColor;
    QString _o_text;
    QtTopic _e_topic;
};

#endif // LEARNQTLOGO_HPP
