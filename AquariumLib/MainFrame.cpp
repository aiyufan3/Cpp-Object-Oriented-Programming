/**
 * @file MainFrame.cpp
 * @author Yufan Ai
 *
 * The top-level (main) frame of the application
 */

#include "pch.h"
#include "ids.h"
#include "MainFrame.h"
#include "AquariumView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
	Create(nullptr, wxID_ANY, L"Aquarium", wxDefaultPosition,  wxSize( 1000,800 ));

	//create the status bar
	CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	// Create a sizer that will lay out child windows vertically
	// one above each other
	auto sizer = new wxBoxSizer( wxVERTICAL );

	// Create the view class object as a child of MainFrame
	auto aquariumView = new AquariumView();
	aquariumView->Initialize(this);

	// Add it to the sizer
	sizer->Add(aquariumView,1, wxEXPAND | wxALL );

	// Set the sizer for this frame
	SetSizer( sizer );

	// Layout (place) the child windows.
	Layout();


	//create the object and call SetMenuBar
	auto menuBar = new wxMenuBar( );


	auto fileMenu = new wxMenu();
	auto helpMenu = new wxMenu();
	auto fishMenu = new wxMenu();


	menuBar->Append(fileMenu, L"&File" );
	menuBar->Append(fishMenu, L"&Add Fish");
	menuBar->Append(helpMenu, L"&Help");

	//Exit or Quit option on the File menu
	fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
	fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
	fishMenu->Append(IDM_ADDNEMO, L"&Nemo", L"Add a Nemo Fish");
	fishMenu->Append(IDM_ADDMAGIKARP, L"&MagiKarp", L"Add a Magikarp Fish");
	fishMenu->Append(IDM_ADDCASTLE, L"&Castle", L"Add a Castle");
	fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");
	fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");

	helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

	SetMenuBar( menuBar );

	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
	Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnWelcome, this, wxID_ABOUT);
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{

	Close(true);
}

/**
 * Welcome menu option handlers
 * @param event
 */
void MainFrame::OnWelcome(wxCommandEvent& event)
{
	wxMessageBox(L"Welcome to the Aquarium!",
				 L"About Aquarium",
				 wxOK,
				 this);
}