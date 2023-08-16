/**
 * @file AquariumView.cpp
 * @author Yufan Ai
 *
 *
 */

#include "pch.h"
#include "ids.h"
#include "AquariumView.h"
#include <wx/dcbuffer.h>
#include "Item.h"
#include "FishBeta.h"
#include "Nemo.h"
#include "MagiKarp.h"
#include "DecorCastle.h"
#include <algorithm>

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Any item we are currently dragging
std::shared_ptr<Item> mGrabbedItem;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY);
	SetBackgroundStyle(wxBG_STYLE_PAINT);

	Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);

	//AquariumView object
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishNemo, this, IDM_ADDNEMO);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishMagiKarp, this, IDM_ADDMAGIKARP);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddDecorCastle, this, IDM_ADDCASTLE);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileOpen, this, wxID_OPEN);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileSaveAs, this, wxID_SAVEAS);


	//call Bind in that function for the paint event
	Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
	Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
	Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
	Bind(wxEVT_TIMER,  &AquariumView::OnTimer,this);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{
	// Compute the time that has elapsed
	// since the last call to OnPaint.
	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	wxAutoBufferedPaintDC dc(this);

	wxBrush background(*wxWHITE);
	dc.SetBackground(background);
	dc.Clear();

	mAquarium.Update(elapsed);
	mAquarium.OnDraw(&dc);
}

/**
 * Menu hander for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
	auto fish = make_shared<FishBeta>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Refresh();
}

/**
 * Menu hander for Add Fish>Nemo Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishNemo(wxCommandEvent& event)
{
	auto fish = make_shared<Nemo>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Refresh();
}

/**
 * Menu hander for Add Fish>MagiKarp Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishMagiKarp(wxCommandEvent& event)
{
	auto fish = make_shared<MagiKarp>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Refresh();
}

/**
 * Menu hander for Add Fish>DecorCastle
 * @param event Mouse event
 */
void AquariumView::OnAddDecorCastle(wxCommandEvent &event)
{
	auto fish = make_shared<DecorCastle>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Refresh();
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnLeftDown(wxMouseEvent &event)
{

	mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());

	if (mGrabbedItem != nullptr)
	{
		// We have selected an item
		// Move it to the end of the list of items
		// you'll need code here to do that...
		mAquarium.Front(mGrabbedItem);
	}

}


/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
	OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to
		// move it while the left button is down.
		if (event.LeftIsDown())
		{
			mGrabbedItem->SetLocation(event.GetX(), event.GetY());
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Refresh();
	}
}

/**
 * Handle the File>Save As menu option
 * @param event The menu event
 */
void AquariumView::OnFileSaveAs(wxCommandEvent& event)
{
	wxFileDialog saveFileDialog(this, _("Save Aquarium file"), "", "",
								"Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = saveFileDialog.GetPath();
	mAquarium.Save(filename);
}
/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event)
{
	wxFileDialog loadFileDialog(this, _("Load Aquarium file"), "", "",
								"Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
	if (loadFileDialog.ShowModal() == wxID_CANCEL)
	{
		return;
	}

	auto filename = loadFileDialog.GetPath();

	mAquarium.Load(filename);
	Refresh();
}
/**
 * Handle timer events
 * @param  event the timer needed to be refresh
 */
void AquariumView::OnTimer(wxTimerEvent& event)
{
	Refresh();
}



