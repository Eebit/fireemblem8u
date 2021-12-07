#include "global.h"

#include "constants/classes.h"

#include "monstergen.h"

const u8 gMonsterLevelWeights[8] = { 5, 10, 49, 20, 10, 5, 1, 0 };

const struct MonsterClassWeights gMonsterClassWeights[] = {
    { .classes = { CLASS_REVENANT, CLASS_ENTOUMBED, CLASS_BONEWALKER, CLASS_BONEWALKER_BOW, CLASS_NONE },
        .weights = { 82, 3, 10, 5, 0, } },
    { .classes = { CLASS_REVENANT, CLASS_ENTOUMBED, CLASS_BONEWALKER, CLASS_BONEWALKER_BOW, CLASS_NONE },
        .weights = { 60, 30, 5, 5, 0, } },
    { .classes = { CLASS_BONEWALKER, CLASS_BONEWALKER_BOW, CLASS_REVENANT, CLASS_ENTOUMBED, CLASS_NONE },
        .weights = { 75, 10, 10, 5, 0, } },
    { .classes = { CLASS_WIGHT, CLASS_WIGHT_BOW, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_BONEWALKER_BOW, CLASS_BONEWALKER, CLASS_REVENANT, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 15, 5, 0, 0, } },
    { .classes = { CLASS_WIGHT_BOW, CLASS_WIGHT, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_BAEL, CLASS_MAUTHEDOOG, CLASS_TARVOS, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_ELDER_BAEL, CLASS_GWYLLGI, CLASS_MAELDUIN, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_CYCLOPS, CLASS_ENTOUMBED, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 95, 5, 0, 0, 0, } },
    { .classes = { CLASS_MAUTHEDOOG, CLASS_TARVOS, CLASS_BAEL, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_GWYLLGI, CLASS_MAELDUIN, CLASS_ELDER_BAEL, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_TARVOS, CLASS_BAEL, CLASS_MAUTHEDOOG, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_MAELDUIN, CLASS_ELDER_BAEL, CLASS_GWYLLGI, CLASS_NONE, CLASS_NONE },
        .weights = { 70, 20, 10, 0, 0, } },
    { .classes = { CLASS_MOGALL, CLASS_BAEL, CLASS_GARGOYLE, CLASS_MAUTHEDOOG, CLASS_NONE },
        .weights = { 75, 10, 10, 5, 0, } },
    { .classes = { CLASS_MOGALL, CLASS_BAEL, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_MOGALL, CLASS_GARGOYLE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_ARCH_MOGALL, CLASS_ELDER_BAEL, CLASS_DEATHGOYLE, CLASS_GWYLLGI, CLASS_NONE },
        .weights = { 75, 10, 10, 5, 0, } },
    { .classes = { CLASS_ARCH_MOGALL, CLASS_ELDER_BAEL, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_ARCH_MOGALL, CLASS_DEATHGOYLE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_GARGOYLE, CLASS_MOGALL, CLASS_BAEL, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 10, 10, 0, 0, } },
    { .classes = { CLASS_GARGOYLE, CLASS_MOGALL, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_DEATHGOYLE, CLASS_ARCH_MOGALL, CLASS_ELDER_BAEL, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 10, 10, 0, 0, } },
    { .classes = { CLASS_DEATHGOYLE, CLASS_ARCH_MOGALL, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_GORGON, CLASS_NONE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 100, 0, 0, 0, 0, } },
    { .classes = { CLASS_DRACO_ZOMBIE, CLASS_NONE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 100, 0, 0, 0, 0, } },
    { .classes = { CLASS_REVENANT, CLASS_ENTOUMBED, CLASS_MAUTHEDOOG, CLASS_BAEL, CLASS_MOGALL },
        .weights = { 60, 10, 10, 10, 10, } },
    { .classes = { CLASS_BAEL, CLASS_MOGALL, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 80, 20, 0, 0, 0, } },
    { .classes = { CLASS_CYCLOPS_2, CLASS_NONE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 100, 0, 0, 0, 0, } },
    { .classes = { CLASS_ELDER_BAEL_2, CLASS_NONE, CLASS_NONE, CLASS_NONE, CLASS_NONE },
        .weights = { 100, 0, 0, 0, 0, } },
    { .classes = { 255, 0, 0, 0, 0, },
        .weights = { 0, 0, 0, 0, 0, } },
};
