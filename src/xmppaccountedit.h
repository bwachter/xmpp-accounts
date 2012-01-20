/**
 * @file xmppaccountadd.h
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#ifndef _XMPPACCOUNTEDIT_H
#define _XMPPACCOUNTEDIT_H

#include <QtDeclarative>
#include <QDeclarativeView>
#include <AccountsUI/n-accountsettingspage.h>
#include <AccountsUI/AbstractAccountSetupContext>
#include <Accounts/Account>

class XmppAccountEditPrivate;

class XmppAccountEdit: public AccountsUI::NAccountSettingsPage{
  Q_OBJECT

  public:
  XmppAccountEdit(AccountsUI::AbstractAccountSetupContext *context);
  ~XmppAccountEdit();

  virtual void createContent();

  private:
  QDeclarativeView* view;
  MWidget *widget;
  QGraphicsObject *qmlWidget;
  XmppAccountEditPrivate *d_ptr;
  Q_DISABLE_COPY(XmppAccountEdit)
  Q_DECLARE_PRIVATE(XmppAccountEdit)

  private slots:
  // this is a quick hack to avoid dealing with the pitfalls of
  // exposing the accounts object  directly to qml
  void setValueAsInt(const QString &key, const int value);
  void setValueAsString(const QString &key, const QString &value);
  void setValueAsBool(const QString &key, const bool value);
  void qmlStatusChanged(QDeclarativeView::Status status);

};

#endif
