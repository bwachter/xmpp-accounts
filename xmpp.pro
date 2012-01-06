TEMPLATE = subdirs
SUBDIRS += src

providers.path = $$system(pkg-config --variable=providerfilesdir accounts-qt)
providers.files += providers/*

services.path = $$system(pkg-config --variable=servicefilesdir accounts-qt)
services.files += services/*

icons.path = /usr/share/themes/base/meegotouch/icons
icons.files = icons/*

share.path = /usr/share/xmpp-accounts/
share.files = share/*

plugins.path = $$system(pkg-config --variable=providerplugindir AccountPlugin)
plugins.files = xmppplugin

INSTALLS += providers services icons share plugins