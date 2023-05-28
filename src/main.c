#include <genesis.h>
#include <resources.h>

u16 ind = TILE_USER_INDEX;

int i = 0;
int ifore = 0;
int xDirection = 0;
int y = 15;

void simpleJoyHandler(u16 joy, u16 changed, u16 state) {
    KLog_f3("Joy:", joy, " changed:", changed, " state:", state);
    if (joy == JOY_1) {
        if (state & BUTTON_LEFT) {
            xDirection = -1;
        } else if (state & BUTTON_RIGHT) {
            xDirection = 1;
        } else {
            xDirection = 0;
        }

        if (state & BUTTON_UP) {
            y += 1;
        } else if (state & BUTTON_DOWN) {
            y -= 1;
        }
    }
}

int main() {
    PAL_setPalette(PAL0, bg1.palette->data, DMA);
    VDP_drawImageEx(BG_B, &bg1, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind), 0, 0, FALSE, TRUE);

    u16 fI = TILE_FONT_INDEX;
    VDP_drawTextEx(BG_B, "Hell-o World!", TILE_ATTR(PAL0, FALSE, FALSE, FALSE),0, 10,DMA );
    ind += bg1.tileset->numTile;
    PAL_setPalette(PAL1, fg1.palette->data, DMA);
    VDP_drawImageEx(BG_A, &fg1, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 0, 0, FALSE, TRUE);

    VDP_setScrollingMode(HSCROLL_PLANE, VSCROLL_PLANE);

    KLog("Log Data");

    JOY_init();
    JOY_setEventHandler(&simpleJoyHandler);

    while (1) {
        VDP_showFPS(TRUE);

        VDP_setHorizontalScroll(BG_B, i);
        VDP_setHorizontalScroll(BG_A, ifore);
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();

        if (xDirection != 0) {
            i += xDirection;
            ifore += xDirection * 2;
        }
    }
    return (0);
}
