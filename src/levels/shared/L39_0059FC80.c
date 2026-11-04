#include "common.h"

/* localdecomp:start func_L39_0059FC80 */
typedef struct { s32 type; s32 packed; s32 offset; s32 size; } UploadChunk_0059FC80;
typedef struct { u8 p0[0x20]; s32 w20; u8 p24[0x10]; s32 w34; } Cfg_0059FC80;
typedef struct { u8 d[0x60]; } UploadImage_0059FC80;

extern Cfg_0059FC80 D_001FC450;
extern s32 D_L39_002402F0;
extern s32 D_L39_002402F4;
extern s32 D_001D4BE0_sda;
extern s32 D_001D4BE4_sda;
extern s32 func_00139EA0(UploadImage_0059FC80 *, s16, s32, s32, s32, s32, s16, s16);
extern void func_001264E0(s32);
extern void func_0013A1C8(UploadImage_0059FC80 *, void *);
extern void func_001331A0(s32, s32);

void func_L39_0059FC80(s32 base, s32 count, s32 palettes, UploadChunk_0059FC80 *list) {
    UploadImage_0059FC80 li;
    s32 i, j, cursor;
    D_L39_002402F4 = D_001D4BE0_sda = D_001FC450.w20;
    for (i = 0; i < count; i++, list++) {
        s32 addr = base + list->size;
        s32 packed = list->packed;
        s32 t = D_L39_002402F0;
        s32 type = list->type;
        s32 w = packed & 0xffff;
        s32 h = packed >> 16;
        if (type == 0x13) {
            s32 dbw = w >> 6;
            s32 sz;
            if (dbw < 1) dbw = 1;
            func_00139EA0(&li, t >> 8, dbw, 0x13, 0, 0, w, h);
            sz = w * h;
            if (sz < 0x100) sz = 0x100;
            D_001D4BE0_sda = D_L39_002402F0 + sz;
        } else if (type == 2) {
            func_00139EA0(&li, t >> 8, 1, 2, 0, 0, 16, 16);
            D_L39_002402F0 += 0x200;
        } else if (type == 0) {
            func_00139EA0(&li, t >> 8, 1, 0, 0, 0, 16, 16);
            D_L39_002402F0 += 0x400;
        }
        func_001264E0(0);
        func_0013A1C8(&li, (void *)addr);
        func_001331A0(0, 0);
    }
    D_001D4BE4_sda = D_L39_002402F0;
    cursor = D_001FC450.w34;
    for (j = 0; j < palettes; j++, list++) {
        s32 packed = list->packed;
        s32 addr = base + list->offset;
        s32 w = packed & 0xffff;
        s32 h = packed >> 16;
        s32 dbw = w >> 6;
        if (dbw < 1) dbw = 1;
        func_00139EA0(&li, cursor >> 8, dbw, 0x1b, 0, 0, w, h);
        cursor += w * h * 4;
        func_001264E0(0);
        func_0013A1C8(&li, (void *)addr);
        func_001331A0(0, 0);
    }
}
/* localdecomp:end func_L39_0059FC80 */
