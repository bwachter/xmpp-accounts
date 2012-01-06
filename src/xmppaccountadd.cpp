/**
 * @file xmppaccountadd.cpp
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

// This page is currently mainly a placeholder, we just use the
// default account creation page anyway
#include "xmppaccountadd.h"

#include <QDeclarativeView>

#ifdef DEBUG
#include <QDir>
#endif

class XmppAccountAddPrivate{
  public:
    XmppAccountAddPrivate(): context(NULL){}
    ~XmppAccountAddPrivate(){}

    AccountsUI::AbstractAccountSetupContext *context;
};

XmppAccountAdd::XmppAccountAdd(AccountsUI::AbstractAccountSetupContext *context,
                               QGraphicsItem *parent)
  : AccountsUI::NAddAccountPage(context, parent),
    d_ptr(new XmppAccountAddPrivate()){
  Q_D(XmppAccountAdd);
  setStyleName("AccountsUiPage");
  d->context = context;
}

XmppAccountAdd::~XmppAccountAdd(){
  delete d_ptr;
}

void XmppAccountAdd::createContent(){
  Q_D(XmppAccountAdd);

  setStyleName("AccountsUiPage");
  setPannable(false);

  MWidget *widget = new MWidget;
  QDeclarativeView* view = new QDeclarativeView();

/* Placeholder for error handling on account creation
#ifdef DEBUG
  QDir dir;
  if (dir.exists("/home/developer/xmpp-add-error.qml"))
    view->setSource(QUrl("file:/home/developer/xmpp-add-error.qml"));
  else
#endif
    view->setSource(QUrl("qrc:/qml/xmpp-add-error.qml"));

  return;
*/

  d->context->account()->selectService();

  // set some default values
#ifdef DEBUG
  d->context->account()->setValue("parameters/priority", 125);
#endif

  AddAccountPage::createContent();

/* Placeholder for experiments with customized signup pages
#ifdef DEBUG
  QDir dir;
  if (dir.exists("/home/developer/xmpp-add.qml"))
    view->setSource(QUrl("file:/home/developer/xmpp-add.qml"));
  else
#endif
    view->setSource(QUrl("qrc:/qml/xmpp-add.qml"));

  QGraphicsObject *qmlWidget = qobject_cast<QGraphicsObject*>(view->rootObject());
  qmlWidget->setParentItem(widget);
*/
}
