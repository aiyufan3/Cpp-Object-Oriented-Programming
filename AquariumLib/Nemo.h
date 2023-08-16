/**
 * @file Nemo.h
 * @author Yufan Ai
 */

#ifndef AQUARIUM_AQUARIUMLIB_NEMO_H
#define AQUARIUM_AQUARIUMLIB_NEMO_H

#include "Item.h"
#include "Fish.h"

/**
 * Nemo class
 */
class Nemo : public Fish {
private:

public:
	/// Default constructor (disabled)
	Nemo() = delete;

	/// Copy constructor (disabled)
	Nemo(const Nemo &) = delete;

	/// Assignment operator
	void operator=(const Nemo &) = delete;

	Nemo(Aquarium* aquarium);

	wxXmlNode *XmlSave(wxXmlNode *node) override;

};


#endif //AQUARIUM_AQUARIUMLIB_NEMO_H
