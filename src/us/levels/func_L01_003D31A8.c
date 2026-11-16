#include "common.h"

/* NTSC-U counterpart of func_L01_003D4C08 (src/levels/shared/L01_003D0D48.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "structs/hero.h"
extern u8 *func_003BCFB0(s32, s32);

/* localdecomp:start func_L01_003D31A8 */
typedef struct {
    u8 pad0[0x20];
    u32 color0, color1, color2, color3;
    u8 pad30[0xC0 - 0x30];
    s32 time0, time1;
    u8 *second;
    u8 padCC[4];
    u8 *first;
    u8 padD4[0xE0 - 0xD4];
} Pair_003D4C08;
typedef struct { u8 pad[0x1C]; f32 width, height; } Style_003D4C08;
typedef struct {
    Pair_003D4C08 pairs[3];
    Style_003D4C08 *style;
    s32 count;
} Effect_003D4C08;
typedef struct { u8 pad0[0x20]; u8 state; u8 pad21[0x30-0x21]; u8 opacity; u8 pad31; u16 group; u16 flags; u8 pad36[0x68-0x36]; Effect_003D4C08 *data; u8 pad6C[0x98-0x6C]; s32 update; } Moby_003D4C08;
__asm__(".extern D_L01_001DF400, 4");
__asm__(".extern D_L01_001DF3F8, 4");
__asm__(".extern D_L01_001DF3FC, 4");
extern Style_003D4C08 D_L01_001DF400 __attribute__((section(".sdata")));
extern u32 D_L01_001DF3F8;
extern u32 D_L01_001DF3FC;
u8 *func_L01_003D31A8(s32 count, u8 **objects, s32 mode, s32 maximum, s32 ticks, f32 scale) {
    extern u8 *func_003BCFB0(s32, s32);
    extern void func_L01_004A6DF8(u8 *, s32);
    Moby_003D4C08 *m;
    s32 pair = 0;
    s32 limit;
    Effect_003D4C08 *data;
    s32 index;
    s32 accepted;
    Pair_003D4C08 *entry;
    u8 *object;
    m = (Moby_003D4C08 *)func_003BCFB0(0x1BE6, 0x2B0);
    if (m != 0) {
        data = m->data;
        m->group = 255;
        m->opacity = 255;
        m->state = 0;
        data->style = &D_L01_001DF400;
        data->style->height = scale * 0.02f;
        data->style->width = scale * 0.05f;
        limit = maximum < 4 ? maximum : 3;
        data->count = limit;
        index = 0;
        accepted = 0;
        while (accepted < count && pair < data->count) {
            object = objects[index];
            if (object == 0 || object[0x20] == 0xFE || object[0x20] == 0xFD || (*(u16 *)(object + 0x34) & 2)) goto next;
            entry = &data->pairs[pair];
            if (entry->first == 0) {
                entry->first = object;
                switch (mode) {
                case 1: D_L01_001DF3F8 = 0xFF0086FF; D_L01_001DF3FC = 0x200057FF; break;
                case 4: D_L01_001DF3F8 = 0xFFEB86C9; D_L01_001DF3FC = 0x20BA008D; break;
                case 5: D_L01_001DF3F8 = 0xFFBEDB6B; D_L01_001DF3FC = 0x200057FF; break;
                case 2: D_L01_001DF3F8 = 0xFFD1C0FF; D_L01_001DF3FC = 0x204500FF; break;
                case 3:
                default: D_L01_001DF3F8 = 0xFFE6925B; D_L01_001DF3FC = 0x20A40032; break;
                }
                {
                    Pair_003D4C08 *color = &data->pairs[pair];
                    color->color0 = D_L01_001DF3F8;
                    color->color2 = D_L01_001DF3FC;
                    color->color1 = D_L01_001DF3F8;
                    color->color3 = D_L01_001DF3FC;
                }
            } else {
                entry->second = object;
                entry->time1 = ticks;
                entry->time0 = ticks;
                pair++;
            }
            accepted++;
next:
            index++;
        }
        m->update = 0;
        m->flags = (m->flags | 0x41) & 0xEFFF;
        func_L01_004A6DF8((u8 *)m, 1);
    }
    return (u8 *)m;
}
/* localdecomp:end func_L01_003D31A8 */
