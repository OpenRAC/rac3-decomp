/* PAL near miss (Codex wave 7): near miss: 287 words differ with the file's flags.
 * Worker's note: 287 diff best: build/codex/w343/func_00130CF0.a1.log; complete PAL motion/slice reconstruction; frame 0x70 vs retail 0xB0, 8-byte vs 16-byte save spacing, register allocation and expression scheduling; four source forms no progress
 */
#include "common.h"
/* localdecomp:start func_00130CF0 */
typedef struct Slice_00130CF0 {
    s32 destination, x, first, second, stride;
    u8 *source0, *source1;
} Slice_00130CF0;
extern s32 D_001415E0[], D_00141600[];
void func_00130CF0(u8 *ctx, Pic_130AA0 *pic, s32 row, s32 column,
                   s32 y, s32 width, s32 x, s32 fieldY,
                   s32 motionX, s32 motionY, s32 field, s32 mode) {
    s32 block = *(s32 *)(ctx + 0x820);
    s32 *count = (s32 *)(ctx + 0x6CC + block * 0x140);
    s32 slot = *count;
    u8 *b = ctx + 0x5A0 + block * 0x140;
    Slice_00130CF0 *luma = (Slice_00130CF0 *)(b + 0x48 + slot * 0x1C);
    Slice_00130CF0 *chroma = (Slice_00130CF0 *)(b + 0xB8 + slot * 0x1C);
    s32 destination = *(s32 *)(ctx + 0x830);
    s32 fullX, fullY, tileX, tileY, remY, oddY, oddX;
    s32 halfX, halfY, halfTileX, halfTileY, offset, phase, halfWidth;
    u8 *source0, *source1, *base;
    fullX = x + (motionX >> 1);
    if (field) fullY = ((motionY >> 1) << 1) + fieldY + y + row;
    else fullY = (motionY >> 1) + fieldY + y + row;
    tileX = fullX >> 4;
    tileY = fullY >> 4;
    source0 = (u8 *)pic->f0 + (tileX * pic->f10 + tileY) * 0x180;
    source1 = (u8 *)pic->f0 + (tileX * pic->f10 + tileY + pic->f10) * 0x180;
    remY = fullY - (tileY << 4);
    luma->x = fullX - (tileX << 4);
    *(u8 **)(ctx + 0x5A8 + block * 0x140 + slot * 4) = source0;
    *(u8 **)(ctx + 0x5B8 + block * 0x140 + slot * 4) = source1;
    luma->destination = destination + ((column + y) << 5);
    oddY = motionY & 1;
    oddX = motionX & 1;
    if (oddY) {
        if (remY + (width << field) < 16) { luma->first = width; luma->second = 0; }
        else {
            luma->first = (16 >> field) - (remY >> field) - 1;
            luma->second = width - luma->first;
        }
    } else {
        if (remY + (width << field) <= 16) { luma->first = width; luma->second = 0; }
        else {
            luma->first = (16 >> field) - (remY >> field);
            luma->second = width - luma->first;
        }
    }
    if (*(s32 *)(ctx + 0x87C) == 0) {
        base = *(u8 **)(ctx + 0x5A0 + *(s32 *)(ctx + 0x820) * 0x140) + slot * 0x600;
        luma->source0 = base + (remY << 4);
        luma->source1 = base + (remY << 4) + 0x300;
    } else {
        base = source0;
        luma->source0 = source0 + (remY << 4);
        luma->source1 = source1 + (remY << 4);
    }
    phase = (mode << 2) | (oddX << 1) | oddY;
    luma->stride = 16 << field;
    motionX /= 2;
    motionY /= 2;
    halfWidth = width >> 1;
    halfX = (motionX >> 1) + (x >> 1);
    if (field) halfY = ((motionY >> 1) << 1) + (fieldY >> 1) + (y >> 1) + row;
    else halfY = (motionY >> 1) + (fieldY >> 1) + (y >> 1) + row;
    halfTileX = halfX >> 3;
    halfTileY = halfY >> 3;
    remY = halfY - (halfTileY << 3);
    chroma->x = halfX - (halfTileX << 3);
    chroma->destination = destination + ((column + (y >> 1)) << 4) + 0x200;
    oddX = motionX & 1;
    oddY = motionY & 1;
    if (oddY) {
        if (remY + (halfWidth << field) < 8) { chroma->first = halfWidth; chroma->second = 0; }
        else {
            chroma->first = (8 >> field) - (remY >> field) - 1;
            chroma->second = halfWidth - chroma->first;
        }
    } else {
        if (remY + (halfWidth << field) <= 8) { chroma->first = halfWidth; chroma->second = 0; }
        else {
            chroma->first = (8 >> field) - (remY >> field);
            chroma->second = halfWidth - chroma->first;
        }
    }
    offset = ((halfTileX - tileX) * 2 + halfTileY - tileY) * 0x180;
    if (*(s32 *)(ctx + 0x87C) == 0) {
        chroma->source1 = base + offset + (remY << 3) + 0x400;
        chroma->source0 = base + offset + (remY << 3) + 0x100;
    } else {
        if ((u32)(offset + (remY << 3) + 0x100) <= 0x300)
            chroma->source0 = source0 + offset + (remY << 3) + 0x100;
        else
            chroma->source0 = source1 + offset + (remY << 3) + 0x100 - 0x300;
        chroma->source1 = source1 + offset + (remY << 3) + 0x100;
    }
    chroma->stride = 8 << field;
    *(s32 *)(ctx + 0x5C8 + *(s32 *)(ctx + 0x820) * 0x140 + slot * 4) = D_001415E0[phase];
    *(s32 *)(ctx + 0x5D8 + *(s32 *)(ctx + 0x820) * 0x140 + slot * 4) = D_00141600[(mode << 2) | (oddX << 1) | oddY];
    ++*(s32 *)(ctx + 0x6CC + *(s32 *)(ctx + 0x820) * 0x140);
}
/* localdecomp:end func_00130CF0 */
