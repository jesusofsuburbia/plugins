// Copyright (C) 2014-2018 Manuel Schneider

#pragma once
#include <QWidget>
#include <QStringListModel>
#include <memory>
#include "core_globals.h"
#include "core/frontend.h"

namespace WidgetBoxModel {

class FrontendWidget final : public QWidget
{
	Q_OBJECT

    class Private;

public:

    FrontendWidget(QSettings*);
    ~FrontendWidget();

    bool isVisible();
    void setVisible(bool visible) override;

    QString input();
    void setInput(const QString&);

    void setModel(QAbstractItemModel *);

    QWidget* widget(QWidget *parent = nullptr);

    const QString &theme() const;
    bool setTheme(const QString& theme);

    uint maxResults() const;
    void setMaxResults(uint max);

    bool showCentered() const;
    void setShowCentered(bool b = true);

    bool hideOnFocusLoss() const;
    void setHideOnFocusLoss(bool b = true);

    bool hideOnClose() const;
    void setHideOnClose(bool b = true);

    bool clearOnHide() const;
    void setClearOnHide(bool b = true);

    bool alwaysOnTop() const;
    void setAlwaysOnTop(bool alwaysOnTop);

    bool displayIcons() const;
    void setDisplayIcons(bool value);

    bool displayScrollbar() const;
    void setDisplayScrollbar(bool value);

    bool displayShadow() const;
    void setDisplayShadow(bool value);


protected:

    void closeEvent(QCloseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
    void resizeEvent(QResizeEvent* event) override;
    bool nativeEvent(const QByteArray &eventType, void *message, long *) override;
    bool eventFilter(QObject*, QEvent *event) override;

    void setShowActions(bool showActions);

private:

    std::unique_ptr<Private> d;

signals:

    void widgetShown();
    void widgetHidden();
    void inputChanged(QString qry);
    void settingsWidgetRequested();
};

}
