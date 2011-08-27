TEMPLATE = subdirs

providers.path = $$system(pkg-config --variable=providerfilesdir accounts-qt)
providers.files += providers/*

services.path = $$system(pkg-config --variable=servicefilesdir accounts-qt)
services.files += services/*

icons.path = /usr/share/themes/base/meegotouch/icons
icons.files = icons/*

INSTALLS += providers services icons