/**
 * @file xmppplugin.cpp
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#include "xmppplugin.h"

#include <AccountsUI/NGenericAccountSetupContext>
#include <AccountsUI/ValidationData>

#include <MExport>
#include <MApplicationPage>

#include <xmppaccountadd.h>
#include <xmppaccountedit.h>

using namespace Accounts;
using namespace AccountsUI;

AbstractAccountSetupContext *
XmppPlugin::accountSetupContext(Accounts::Account *account,
                                SetupType type,
                                QObject *parent){
  return new NGenericAccountSetupContext(account, type, parent);
}

MApplicationPage *XmppPlugin::mainPage(){
  AbstractAccountSetupContext *context = setupContext();

  if (context->setupType() == CreateNew)
    return new XmppAccountAdd(context);
  if (context->setupType() == EditExisting)
    return new XmppAccountEdit(context);

  // should never happen
  Q_ASSERT(false);
  return 0;
}

M_EXPORT int main(int argc, char **argv){
  XmppPlugin *plugin = new XmppPlugin(argc, argv);

  QVariantMap sessionData;

  sessionData.insert("method", "password");
  sessionData.insert("mechanism", "ClientLogin");

  GenericAccountSetupContext *context =
    qobject_cast<GenericAccountSetupContext *>(plugin->setupContext());
  context->setValidationData(ValidationData("password",
                                            "ClientLogin",
                                            sessionData));

  int ret = plugin->exec();

  delete plugin;
  return ret;
}

