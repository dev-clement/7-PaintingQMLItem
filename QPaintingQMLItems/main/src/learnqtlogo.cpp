#include <QRect>
#include <QPainter>
#include "learnqtlogo.hpp"

LearnQtLogo::LearnQtLogo(QQuickItem *po_parent)
    : QQuickPaintedItem{po_parent}
    , _o_bgColor{ Qt::white }
    , _o_textColor{ Qt::blue }
    , _o_text{ "Learn Qt" }
    , _e_topic{ QtTopic::QTCPP } {
    setWidth(128);
    setHeight(128);
}

void LearnQtLogo::paint(QPainter *po_painter) {
    // Draw image
    QString o_imagePath = ":/images/LearnQt.png";
    if (_e_topic == LearnQtLogo::QTQUICK) {
        o_imagePath = ":/images/LearnQtQuick.png";
    }

    QImage o_image{ o_imagePath };
    QImage o_scaledImage = o_image.scaled(width(), height());
    QRect o_rect = o_image.rect();
    po_painter->drawImage(o_rect, o_scaledImage);

    // Draw the rectangle
    po_painter->setBrush(bgColor());
    po_painter->drawRect(o_rect.bottomLeft().x(), o_rect.bottomLeft().y() - 33, width(), 33);

    // Draw the text
    po_painter->setPen(textColor());
    QPoint o_textPosition = o_rect.bottomLeft();
    o_textPosition.rx() += 10;
    o_textPosition.ry() -= 10;
    po_painter->setFont(QFont{"Consolas", 10, QFont::Bold});
    po_painter->drawText(o_textPosition, text());
}

QColor LearnQtLogo::bgColor() const {
    return _o_bgColor;
}

void LearnQtLogo::setBgColor(const QColor &o_bgColor) {
    if (_o_bgColor == o_bgColor)
        return;
    _o_bgColor = o_bgColor;
    emit bgColorChanged(_o_bgColor);
}

QColor LearnQtLogo::textColor() const {
    return _o_textColor;
}

void LearnQtLogo::setTextColor(const QColor &o_textColor) {
    if (_o_textColor == o_textColor)
        return;
    _o_textColor = o_textColor;
    emit textColorChanged(_o_textColor);
}

QString LearnQtLogo::text() const {
    return _o_text;
}

void LearnQtLogo::setText(const QString &o_text) {
    if (_o_text == o_text)
        return;
    _o_text = o_text;
    emit textChanged(_o_text);
}

LearnQtLogo::QtTopic LearnQtLogo::topic() const {
    return _e_topic;
}

void LearnQtLogo::setTopic(const QtTopic &e_topic) {
    if (_e_topic == e_topic)
        return;
    _e_topic = e_topic;
    emit topicChanged(_e_topic);
}
