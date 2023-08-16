/**
 * @file AquariumView.h
 * @author Yufan Ai
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H

#include "Aquarium.h"
/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow {
private:
	void OnPaint(wxPaintEvent& event);
	/// An object that describes our aquarium
	Aquarium  mAquarium;

	///the timer
	wxTimer mTimer;

	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;

	/// The last stopwatch time
	long mTime = 0;
public:
	void OnFileSaveAs(wxCommandEvent &event);
	void OnFileOpen(wxCommandEvent &event);

	void OnTimer(wxTimerEvent &event);
	void Initialize(wxFrame *parent);
	void OnAddFishBetaFish(wxCommandEvent &event);
	void OnLeftDown(wxMouseEvent &event);
	void OnLeftUp(wxMouseEvent &event);
	void OnMouseMove(wxMouseEvent &event);
	void OnAddFishNemo(wxCommandEvent &event);
	void OnAddFishMagiKarp(wxCommandEvent &event);
	void OnAddDecorCastle(wxCommandEvent &event);
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUMVIEW_H
