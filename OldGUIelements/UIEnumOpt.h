#pragma once

enum ColourType {
    FILL,
    OUTLINE,
    HOVER,
    PRESSED,
};

enum Origin {
    TOPLEFT,
    TOPRIGHT,
    BOTTOMLEFT,
    BOTTOMRIGHT,
    CENTER,
};

enum ButtonStates {
    BTN_IDLE = 0,
    BTN_HOVER = 2,
    BTN_ACTIVE = 3
};

