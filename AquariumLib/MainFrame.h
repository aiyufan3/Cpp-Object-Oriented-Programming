/**
 * @file MainFrame.h
 * @author Yufan Ai
 *
 * The top-level (main) frame of the application
 */

#ifndef AQUARIUM_MAINFRAME_H
#define AQUARIUM_MAINFRAME_H

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame {
private:

public:
	///initialize function
	void Initialize();
	///exit function
	void OnExit(wxCommandEvent &event);
	///welcome function
	void OnWelcome(wxCommandEvent &event);
};

#endif //AQUARIUM_MAINFRAME_H