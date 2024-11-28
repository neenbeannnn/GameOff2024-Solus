#include "CatSprite.h"

CatSprite::CatSprite() {

}

void CatSprite::addAnimation(CatAnimation name, std::shared_ptr<Animations> animation) {
	this->allAnimations[name] = animation;
	if (!this->currentAnimation)
		this->currentAnimation = currentAnimation;
}

void CatSprite::switchToAnimation(CatAnimation name) {
	auto newAnimation = allAnimations.find(name);
	this->currentAnimation = newAnimation->second;
}

