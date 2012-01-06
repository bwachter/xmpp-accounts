/**
 * @file xmppaccountadd.h
 * @author Bernd Wachter <bwachter@lart.info>
 * @date 2012
 */

#ifndef _XMPPACCOUNTADD_H
#define _XMPPACCOUNTADD_H

#include <AccountsUI/n-add-account-page.h>
#include <AccountsUI/AbstractAccountSetupContext>

class XmppAccountAddPrivate;

class XmppAccountAdd: public AccountsUI::NAddAccountPage{
  Q_OBJECT

  public:
  XmppAccountAdd(AccountsUI::AbstractAccountSetupContext *context,
                 QGraphicsItem *parent = 0);
  ~XmppAccountAdd();

  virtual void createContent();

  private:
  XmppAccountAddPrivate *d_ptr;
  Q_DISABLE_COPY(XmppAccountAdd)
  Q_DECLARE_PRIVATE(XmppAccountAdd)
};


#endif
