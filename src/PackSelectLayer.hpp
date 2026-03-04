#pragma once

#include <Noahh/DefaultInclude.hpp>
#include <cocos2d.h>
#include <Noahh/ui/ScrollLayer.hpp>
#include "Pack.hpp"

using namespace noahh::prelude;

class PackSelectLayer : public CCLayer {
protected:
    ScrollLayer* m_availableList = nullptr;
    ScrollLayer* m_appliedList = nullptr;

    bool init();

    void keyBackClicked() override;

    void updateList(
        ScrollLayer* list,
        std::vector<std::shared_ptr<Pack>> const& packs
    );

public:
    static PackSelectLayer* create();
    static PackSelectLayer* scene();
    
    void updateLists();

    void onGoBack(CCObject*);
    void onApply(CCObject*);

    void onOpenFolder(CCObject*);
};