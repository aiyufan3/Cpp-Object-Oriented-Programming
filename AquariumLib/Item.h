/**
 * @file Item.h
 * @author YufanAi
 *
 * Base class for any item in our aquarium.
 */

#ifndef AQUARIUM_ITEM_H
#define AQUARIUM_ITEM_H


class Aquarium;
/**
 * Base class for any item in our aquarium.
 */
class Item {
private:

	/// The aquarium this item is contained in
	Aquarium   *mAquarium;

	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
	bool mMirror = false;   ///< True mirrors the item image


protected:
//	/// The aquarium this item is contained in
//	Item(Aquarium *aquarium);
	/// The underlying fish image
	Item(Aquarium *aquarium, const std::wstring &filename);
	/// The underlying fish image
	std::unique_ptr<wxImage> mItemImage;

	/// The bitmap we can display for this fish
	std::unique_ptr<wxBitmap> mItemBitmap;
public:
	/**
 * The Aquarium function to get mAquarium
 * @return the mAquarium
 */
	Aquarium *GetAquarium(){return mAquarium;};

/**
* Draw this item
* @param dc Device context to draw on
*/
	virtual void Draw(wxDC *dc);


	virtual ~Item();
	/**
 * The X location of the item
 * @return X location in pixels
 */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/**
* Set the item speed
* @param x X location in pixels
* @param y Y location in pixels
*/
	void SetSpeed(double x, double y) { mX = x; mY = y; }

	/// Default constructor (disabled)
	Item() = delete;

	/// Copy constructor (disabled)
	Item(const Item &) = delete;

	/// Assignment operator
	void operator=(const Item &) = delete;

/**
 * Test to see if we hit this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
	virtual bool HitTest(int x, int y);

	/**
 * Test this item to see if it has been clicked on
 * @param elapsed
 */
	virtual void Update(double elapsed) {}

	///xml to save implementation
	virtual wxXmlNode *XmlSave(wxXmlNode *node);

	///xml to load
	virtual void XmlLoad(wxXmlNode *node);

/**
 * Set the mirror status
 * @param isMirror New mirror flag
 */
	void SetMirror(bool isMirror);
};


#endif //AQUARIUM_ITEM_H
