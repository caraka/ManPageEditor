AUTOMAKE_OPTIONS = subdir-objects

include ../flagsandlibs
include ../sources

manpageeditor_SOURCES = $(COMMONSRC)

appfilesdir = ${datarootdir}/applications
appfiles_DATA = ../resources/applications/*

pixfilesdir = ${datarootdir}/pixmaps
pixfiles_DATA = ../resources/pixmaps/*

bin_PROGRAMS = manpageeditor

man1_MANS = ../resources/man/manpageeditor.1

helpfilesdir = $(pkgdatadir)/help
helpfiles_DATA = ../resources/help/*

examplefilesdir = $(pkgdatadir)/examples
examplefiles_DATA = ../resources/examples/*

docfilesdir = $(pkgdatadir)/docs
docfiles_DATA = ../resources/docs/*

install-exec-hook:
	mkdir -vp $(DESTDIR)${prefix}/share/icons/hicolor/256x256/apps||true
	cp ../resources/pixmaps/ManPageEditor.png $(DESTDIR)${prefix}/share/icons/hicolor/256x256/apps
	gtk-update-icon-cache --ignore-theme-index --force /usr/share/icons/hicolor||true

uninstall-hook:
	rm $(DESTDIR)${prefix}/share/icons/hicolor/256x256/apps/ManPageEditor.png||true


