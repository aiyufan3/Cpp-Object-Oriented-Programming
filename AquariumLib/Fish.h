/**
 * @file Fish.h
 * @author Yufan_Ai
 *
 * The Declaration of Fish.h
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H


#include "Item.h"

/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
public:
/// Fish speed in the X direction
/// in pixels per second
	double mSpeedX;

/// Fish speed in the Y direction
/// in pixels per second
	double mSpeedY;

	/**
 * Get the width of the fish screen
 * @return Pointer to the width
 */
	int GetWidth(){return mItemBitmap->GetWidth();}

	/// Default constructor (disabled)
	Fish() = delete;

	/// Copy constructor (disabled)
	Fish(const Fish &) = delete;


/// Assignment operator
	void operator=(const Fish &) = delete;

	Fish(Aquarium *aquarium, const std::wstring &filename);

	void Update(double elapsed) override;
};


#endif //AQUARIUM_FISH_H
