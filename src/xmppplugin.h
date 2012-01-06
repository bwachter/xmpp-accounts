/**
 * @file xmppplugin.h
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#ifndef _XMPPPLUGIN_H
#define _XMPPPLUGIN_H

#include <AccountsUI/NProviderPluginProcess>
#include <AccountsUI/AbstractAccountSetupContext>

class XmppPlugin: public AccountsUI::NProviderPluginProcess {
  Q_OBJECT

  public:
  XmppPlugin(int &argc, char **argv) :
  AccountsUI::NProviderPluginProcess(argc, argv){}

  AccountsUI::AbstractAccountSetupContext* accountSetupContext(Accounts::Account *account,
                                                               AccountsUI::SetupType type,
                                                               QObject *parent);

  MApplicationPage *mainPage();
};

#endif
