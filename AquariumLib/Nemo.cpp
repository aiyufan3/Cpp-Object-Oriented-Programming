/**
 * @file Nemo.cpp
 * @author Yufan Ai
 */

#include "pch.h"
#include "Nemo.h"
#include "Aquarium.h"
#include "Fish.h"
#include <string>
/// Min speed in X direction in pixels per second
const double MinSpeedX = 100;
/// Max speed in X direction in pixels per second
const double MaxSpeedX = 170;

using namespace std;
/// Fish filename
const wstring NemoImageName = L"images/nemo.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
Nemo::Nemo(Aquarium *aquarium) : Fish(aquarium,NemoImageName)
{
	std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
	mSpeedX = distribution(aquarium->GetRandom());
	mSpeedY = 0;
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* Nemo::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"nemo");

	return itemNode;

}