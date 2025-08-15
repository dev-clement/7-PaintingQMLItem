#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "learnqtlogo.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LearnQtLogo>("com.franco.custom", 1, 0, "Logo");
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QPaintingQMLItems", "Main");

    return app.exec();
}
