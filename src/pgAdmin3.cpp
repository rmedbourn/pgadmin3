//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// Copyright (C) 2002, The pgAdmin Development Team
// This software is released under the pgAdmin Public Licence
//
// pgAdmin3.cpp - The application
//
//////////////////////////////////////////////////////////////////////////

// wxWindows Headers
#include <wx/wx.h>
#include <wx/image.h>
#include <wx/utils.h>

// App headers
#include "pgAdmin3.h"
#include "ui/frmMain.h"
#include "ui/frmSplash.h"

IMPLEMENT_APP(pgAdmin3)

// Globals
frmMain *winMain;

// The Application!
bool pgAdmin3::OnInit()
{
  // We need JPEG Support
  wxImage::AddHandler(new wxJPEGHandler);
  
  // Show the splash screen
  frmSplash *winSplash = new frmSplash();
  SetTopWindow(winSplash);
  winSplash->Show(TRUE);
  
  wxSleep(2);
  
  // Create & show the main form
  winMain = new frmMain("pgAdmin III", wxPoint(50, 50), wxSize(450, 340));
  winMain->Show(TRUE);
  
  
  delete winSplash;
  
  return TRUE;
}
