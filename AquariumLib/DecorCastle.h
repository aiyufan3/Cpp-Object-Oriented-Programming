/**
 * @file DecorCastle.h
 * @author your_name_here
 *
 *
 */

#ifndef AQUARIUM_DECORCASTLE_H
#define AQUARIUM_DECORCASTLE_H


#include "Item.h"
#include "Fish.h"

/**
 * DecorCastle class
 */
class DecorCastle : public Item {
public:
	/// Default constructor (disabled)
	DecorCastle ()= delete;

	/// Copy constructor (disabled)
	DecorCastle(const DecorCastle &) = delete;

	/// Assignment operator
	void operator=(const DecorCastle &) = delete;

	DecorCastle(Aquarium* aquarium);

	wxXmlNode *XmlSave(wxXmlNode *node);
};

#endif //AQUARIUM_DECORCASTLE_H
