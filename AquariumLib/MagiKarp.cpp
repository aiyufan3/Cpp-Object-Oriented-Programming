/**
 * @file MagiKarp.cpp
 * @author Yufan Ai
 */

#include "pch.h"
#include "MagiKarp.h"
#include "Aquarium.h"
#include "Fish.h"
#include <string>

/// Min speed in X direction in pixels per second
const double MinSpeedX = 80;
/// Max speed in X direction in pixels per second
const double MaxSpeedX = 150;

using namespace std;

/// Fish filename
const wstring MagiKarpImageName = L"images/magikarp.png";
/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
MagiKarp::MagiKarp(Aquarium *aquarium) : Fish(aquarium,MagiKarpImageName)
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
wxXmlNode* MagiKarp::XmlSave(wxXmlNode* node)
{
	auto itemNode = Item::XmlSave(node);

	itemNode->AddAttribute(L"type", L"magikarp");

	return itemNode;

}