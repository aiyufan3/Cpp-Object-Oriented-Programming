/**
 * @file FishBeta.h
 * @author Yufan Ai
 *
 *
 */

#ifndef AQUARIUM_AQUARIUMLIB_FISHBETA_H
#define AQUARIUM_AQUARIUMLIB_FISHBETA_H


#include "Item.h"
#include "Fish.h"

/**
 * class for our FishBeta
 */
class FishBeta : public Fish {
public:
	/// Default constructor (disabled)
	FishBeta() = delete;

	/// Copy constructor (disabled)
	FishBeta(const FishBeta &) = delete;

	/// Assignment operator
	void operator=(const FishBeta &) = delete;

	FishBeta(Aquarium* aquarium);

	wxXmlNode *XmlSave(wxXmlNode *node) override;

};



#endif //AQUARIUM_AQUARIUMLIB_FISHBETA_H
