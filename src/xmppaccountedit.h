/**
 * @file xmppaccountadd.h
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#ifndef _XMPPACCOUNTEDIT_H
#define _XMPPACCOUNTEDIT_H

#include <AccountsUI/n-accountsettingspage.h>
#include <AccountsUI/AbstractAccountSetupContext>

class XmppAccountEditPrivate;

class XmppAccountEdit: public AccountsUI::NAccountSettingsPage{
  Q_OBJECT

  public:
  XmppAccountEdit(AccountsUI::AbstractAccountSetupContext *context);
  ~XmppAccountEdit();

  virtual void createContent();

  private:
  XmppAccountEditPrivate *d_ptr;
  Q_DISABLE_COPY(XmppAccountEdit)
  Q_DECLARE_PRIVATE(XmppAccountEdit)
};

#endif
