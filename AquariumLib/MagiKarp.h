/**
 * @file MagiKarp.h
 * @author Yufan Ai
 */

#ifndef AQUARIUM_AQUARIUMLIB_MAGIKARP_H
#define AQUARIUM_AQUARIUMLIB_MAGIKARP_H

#include "Item.h"
#include "Fish.h"

/**
 * MagiKarp class
 */
class MagiKarp : public Fish {
private:

public:
	/// Default constructor (disabled)
	MagiKarp() = delete;

	/// Copy constructor (disabled)
	MagiKarp(const MagiKarp &) = delete;

	/// Assignment operator
	void operator=(const MagiKarp &) = delete;

	MagiKarp(Aquarium* aquarium);
	wxXmlNode *XmlSave(wxXmlNode *node) override;
};



#endif //AQUARIUM_AQUARIUMLIB_MAGIKARP_H
