#include <genesis.h>
#include <resources.h>

int main() {
    u16 ind = TILE_USER_INDEX;
    PAL_setPalette(PAL0, bg1.palette->data, DMA);
    VDP_drawImageEx(BG_B, &bg1, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind), 0, 0, FALSE, TRUE);

    ind += bg1.tileset->numTile;
    PAL_setPalette(PAL1, fg1.palette->data, DMA);
    VDP_drawImageEx(BG_A, &fg1, TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, ind), 0, 0, FALSE, TRUE);
    VDP_drawText("Hell-o World!", 2, 13);

    KLog("Log Data");
    VDP_showFPS(TRUE);

    while (1) {
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
    }
    return (0);
}
