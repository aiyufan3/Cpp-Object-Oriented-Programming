/**
 * @file Aquarium.h
 * @author Yufan Ai
 *
 *
 */

#include<memory>
#include <random>
#include "Item.h"
#ifndef AQUARIUM_AQUARIUMLIB_AQUARIUM_H
#define AQUARIUM_AQUARIUMLIB_AQUARIUM_H

/**
 * class for our aquarium
 */
class Aquarium {
private:
	std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use and avoid leak memory
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<Item>> mItems;
	///move to Xml
	void XmlItem(wxXmlNode *node);

public:
	Aquarium();
	void OnDraw(wxDC* dc);

	void Add(std::shared_ptr<Item> item);
	std::shared_ptr<Item> HitTest(int x, int y);
	///move to front
	void Front(std::shared_ptr<Item> front);
	///save
	void Save(const wxString &filename);
	///load
	void Load(const wxString &filename);

	///clear
	void Clear();

	///update
	void Update(double elapsed);

	/// Random number generator
	std::mt19937 mRandom;
	/**
 * Get the random number generator
 * @return Pointer to the random number generator
 */
	std::mt19937 &GetRandom() {return mRandom;}
	/**
	* Get the width of the aquarium
	* @return Aquarium width in pixels
	*/
	int GetWidth() const { return mBackground->GetWidth(); }

	/**
	 * Get the height of the aquarium
	 * @return Aquarium height in pixels
	 */
	int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUM_AQUARIUMLIB_AQUARIUM_H
