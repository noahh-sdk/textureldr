#include <Noahh/loader/Mod.hpp>
#include <Noahh/binding/CCMenuItemSpriteExtra.hpp>
#include "PackSelectLayer.hpp"
#include <Noahh/modify/MenuLayer.hpp>
#include <Noahh/modify/IDManager.hpp>
#include <Noahh/ui/BasedButtonSprite.hpp>
#include "PackManager.hpp"

USE_NOAHH_NAMESPACE();

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;
        
        NodeIDs::provideFor(this);

        auto menu = this->getChildByID("right-side-menu");

        menu->addChild(CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("gj_folderBtn_001.png"),
            this, menu_selector(MyMenuLayer::onTextureLdr)
        ));
        menu->updateLayout();

        return true;
    }

    void onTextureLdr(CCObject*) {
        PackSelectLayer::scene();
    }
};
