/**
 * @file FishBeta.cpp
 * @author YufanAi
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"
#include "Fish.h"
#include <string>

using namespace std;
/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/// Min speed in X direction in pixels per second
const double MinSpeedX = 120;
/// Max speed in X direction in pixels per second
const double MaxSpeedX = 200;


/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
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
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"beta");

	return itemNode;
}
