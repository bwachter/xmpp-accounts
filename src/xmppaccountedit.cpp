/**
 * @file xmppaccountadd.cpp
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#include "xmppaccountedit.h"

#include <QDeclarativeView>

#ifdef DEBUG
#include <QDir>
#endif

class XmppAccountEditPrivate{
  public:
    XmppAccountEditPrivate(): context(NULL){}
    ~XmppAccountEditPrivate(){}

    AccountsUI::AbstractAccountSetupContext *context;
};

XmppAccountEdit::XmppAccountEdit(AccountsUI::AbstractAccountSetupContext *context)
  : AccountsUI::NAccountSettingsPage(context),
    d_ptr(new XmppAccountEditPrivate()){
  Q_D(XmppAccountEdit);
  setStyleName("AccountsUiPage");
  d->context = context;
}

XmppAccountEdit::~XmppAccountEdit(){
  delete d_ptr;
}

void XmppAccountEdit::createContent(){
  Q_D(XmppAccountEdit);
  setStyleName("AccountsUiPage");
  setPannable(false);

  d->context->account()->selectService();

#ifdef DEBUG
  d->context->account()->setValue("parameters/priority", 125);
#endif

  AccountSettingsPage::createContent();

  MWidget *widget = new MWidget;
  QDeclarativeView* view = new QDeclarativeView();

#ifdef DEBUG
  QDir dir;
  if (dir.exists("/home/developer/xmpp-settings.qml"))
    view->setSource(QUrl("file:/home/developer/xmpp-settings.qml"));
  else
#endif
    view->setSource(QUrl("qrc:/qml/xmpp-settings.qml"));

  QGraphicsObject *qmlWidget = qobject_cast<QGraphicsObject*>(view->rootObject());
  qmlWidget->setParentItem(widget);

  AccountSettingsPage::setWidget(widget);
}
