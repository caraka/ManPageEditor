/*
 *
 * K.D.Hedger 2013 <kdhedger68713@gmail.com>
 *
 * globals.cpp
 *
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include <sys/stat.h>
#include <gtksourceview/gtksourcebuffer.h>
#include <gtksourceview/gtksourcelanguage.h>
#include <gtksourceview/gtksourcelanguagemanager.h>

#include "config.h"
#ifdef BUILDDOCVIEWER
#include <webkit/webkit.h>
#endif

#ifdef _ASPELL_
#include <aspell.h>
#endif

#include "globals.h"
#include "searchcallbacks.h"
#include "callbacks.h"
#include "script.h"


//manpage
char*			manFilename=NULL;
char*			manName=NULL;
char*			manSection=NULL;
char*			manVersion=NULL;
char*			manAuthor=NULL;
char*			manCategory=NULL;
char*			manFilePath=NULL;
bool			pageOpen=false;
bool			dirty=false;
char*			exportPath=NULL;

GtkWidget*		nameBox;
GtkWidget*		sectionBox;
GtkWidget*		versionBox;
GtkWidget*		authorBox;
GtkWidget*		categoryBox;

GtkWidget*		window=NULL;
GtkNotebook*	notebook=NULL;
GtkWidget*		menubar=NULL;
GtkWidget*		menufile;
GtkWidget*		menuedit;



GtkWidget*		menuhelp;




GtkWidget*		menuprint;
GtkWidget*		menuclose;

GtkWidget*		menusaveall;

GtkWidget*		redoMenu;
GtkWidget*		undoMenu;
GtkWidget*		saveMenu;
GtkWidget*		exportMenu;

GtkWidget*		saveAsMenu;
GtkWidget*		closeSectionMenu;


GtkWidget*		liveSearchWidget;

int				currentPage=0;

GtkWidget*		prefswin;


bool			lineWrap;
bool			highLight;

int				tabWidth;
char*			fontAndSize;







bool			showLiveSearch;

GtkWidget*		fontBox;



bool			tmpLineWrap;
bool			tmpHighLight;

int				tmpTabWidth;






bool			tmpShowLiveSearch;










int				windowWidth;
int				windowHeight;
int				windowX=-1;
int				windowY=-1;
bool			wrapSearch;
bool			insensitiveSearch;
bool			replaceAll;

int				currentTabNumber;


GtkToolItem*	newButton;
GtkToolItem*	openButton;
GtkToolItem*	saveButton;

GtkToolItem*	closeButton;
GtkToolItem*	redoButton;
GtkToolItem*	undoButton;


GtkWidget*		findReplaceDialog;
GtkWidget*		findBox;
GtkWidget*		replaceBox;

char*			thePage=NULL;




//spellcheck
GtkWidget*		spellCheckWord;
GtkWidget*		wordListDropbox;
char*			badWord=NULL;
char*			goodWord=NULL;
#ifdef _ASPELL_
AspellConfig*	aspellConfig;
AspellSpeller*	spellChecker=0;
#endif

void scrollToIterInPane(pageStruct* page,GtkTextIter* iter)
{
	if(page->inTop==true)
		gtk_text_view_scroll_to_iter((GtkTextView*)page->view,iter,0,true,0,0.5);
	else
		gtk_text_view_scroll_to_iter((GtkTextView*)page->view2,iter,0,true,0,0.5);
}

pageStruct* getPageStructPtr(int pagenum)
{
	int			thispage;
	GtkWidget*	pageBox;

	if(pagenum==-1)
		thispage=gtk_notebook_get_current_page(notebook);
	else
		thispage=pagenum;

	pageBox=gtk_notebook_get_nth_page(notebook,thispage);
	if(pageBox==NULL)
		return(NULL);
	else
		return((pageStruct*)g_object_get_data((GObject*)pageBox,"pagedata"));
}











