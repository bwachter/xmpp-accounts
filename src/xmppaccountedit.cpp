/**
 * @file xmppaccountadd.cpp
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#include "xmppaccountedit.h"

#include <QDeclarativeContext>

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

  widget = new MWidget;
  view = new QDeclarativeView();
  connect(view, SIGNAL(statusChanged(QDeclarativeView::Status)),
          this, SLOT(qmlStatusChanged(QDeclarativeView::Status)));
}

XmppAccountEdit::~XmppAccountEdit(){
  delete d_ptr;
}

void XmppAccountEdit::createContent(){
  Q_D(XmppAccountEdit);
  setStyleName("AccountsUiPage");
  setPannable(false);

  d->context->account()->selectService();

  AccountSettingsPage::createContent();

  d->context->account()->beginGroup("parameters");

  // Like providing slots in this class for passing changes through to accounts,
  // storing all interesting values from the Account object is just a quick
  // hack to avoid messing with exposing the Account object directly to qml
  view->rootContext()->setContextProperty("param_resource",
                                          d->context->account()->valueAsString("resource"));
  view->rootContext()->setContextProperty("param_priority",
                                          d->context->account()->valueAsInt("priority"));
  view->rootContext()->setContextProperty("param_old_ssl",
                                          d->context->account()->valueAsBool("old-ssl"));
  view->rootContext()->setContextProperty("param_ignore_ssl_errors",
                                          d->context->account()->valueAsBool("ignore-ssl-errors"));
  view->rootContext()->setContextProperty("param_require_encryption",
                                          d->context->account()->valueAsBool("require-encryption"));

  d->context->account()->endGroup();

#ifdef DEBUG
  QDir dir;
  if (dir.exists("/home/developer/xmpp-settings.qml"))
    view->setSource(QUrl("file:/home/developer/xmpp-settings.qml"));
  else
#endif
    view->setSource(QUrl("qrc:/qml/xmpp-settings.qml"));

  setValueAsString("parameters/resource", "aardphone");
}

void XmppAccountEdit::setValueAsInt(const QString &key, const int value){
  Q_D(XmppAccountEdit);
  d->context->account()->setValue(key, value);
}

void XmppAccountEdit::setValueAsString(const QString &key, const QString &value){
  Q_D(XmppAccountEdit);
  d->context->account()->setValue(key, value);
}

void XmppAccountEdit::setValueAsBool(const QString &key, const bool value){
  Q_D(XmppAccountEdit);
  d->context->account()->setValue(key, value);
}

void XmppAccountEdit::qmlStatusChanged(QDeclarativeView::Status status){
  switch (status){
    case QDeclarativeView::Ready: {
      qmlWidget = qobject_cast<QGraphicsObject*>(view->rootObject());
      qmlWidget->setParentItem(widget);
      AccountSettingsPage::setWidget(widget);
      QObject *item=dynamic_cast<QObject*>(view->rootObject());
      connect(item, SIGNAL(setValueAsInt(QString, int)), this, SLOT(setValueAsInt(QString, int)));
      connect(item, SIGNAL(setValueAsBool(QString, bool)), this, SLOT(setValueAsBool(QString, bool)));
      connect(item, SIGNAL(setValueAsString(QString, QString)), this, SLOT(setValueAsString(QString, QString)));
      break;
    }
    case QDeclarativeView::Error:
      QList<QDeclarativeError> qmlErrors = view->errors();
      QTextStream qout(stdout);
      for (int i = 0; i < qmlErrors.size(); i++){
        qout << qmlErrors.at(i).toString() << "\n";
      }
      qout.flush();
      break;
  }
}
