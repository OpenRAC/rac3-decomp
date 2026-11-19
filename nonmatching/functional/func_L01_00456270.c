/* functional: high. From the PAL near miss (11 words differ: register allocation and load order only), cleaned of its section/extern tricks and re-read against the assembly: same stamp test, same four scans (player, mobys of type 0xCB state 3, listed objects, mobys of type 0x1BC3) with the same arguments. */
extern char *D_L01_001DFC4C;
extern u8 *D_L01_001DFC48;
extern u16 D_L01_001DFB40;
extern s16 D_L01_001E0180[];
extern s16 D_L01_001E01C0[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001D6774;
extern void *D_L01_001EFFE8[];
extern s32 D_L01_001F01E8[];
extern u8 D_001A4C60[];
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_004566A8(void *, s32, s32);

typedef struct { u8 pad0[0x1A]; s16 stamp; } Rec_00456270;
typedef struct { s32 first; u8 count; u8 pad5[3]; s32 last; } Cache_00456270;

void func_L01_00456270(s32 index) {
    Rec_00456270 *rec = (Rec_00456270 *)(D_L01_001DFC4C + (index * 0x30 + 0x20));
    Cache_00456270 *cache;
    s32 i;
    u8 *moby;

    if (rec->stamp == D_L01_001DFB40) {
        return;
    }
    rec->stamp = D_L01_001DFB40;
    cache = (Cache_00456270 *)(D_L01_001DFC48 + index * 0xE0);
    cache->last = 0;
    cache->first = 0;
    cache->count = 0;
    if (func_L01_00456500(D_001A4C60, index)) {
        func_L01_004566A8(*(void **)(D_001A4C60 + 0x2540), index, 1);
    }
    for (i = 1; i <= D_L01_001E0180[0]; i++) {
        moby = D_L01_001E001C + (D_L01_001E0180[i] << 8);
        if (moby != 0 && *(s16 *)(moby + 0xAA) == 0xCB && moby[0x20] != 0xFE && moby[0x20] != 0xFD && moby[0x20] == 3) {
            if (func_L01_00456500(moby + 0x10, index)) {
                func_L01_004566A8(moby, index, 2);
            }
        }
    }
    for (i = 0; i < D_L01_001D6774; i++) {
        if (func_L01_00456500((u8 *)D_L01_001EFFE8[i] + 0x10, index)) {
            func_L01_004566A8(D_L01_001EFFE8[i], index, D_L01_001F01E8[i]);
        }
    }
    for (i = 1; i <= D_L01_001E01C0[0]; i++) {
        moby = D_L01_001E001C + (D_L01_001E01C0[i] << 8);
        if (moby != 0 && *(s16 *)(moby + 0xAA) == 0x1BC3 && moby[0x20] != 0xFE && moby[0x20] != 0xFD) {
            if (func_L01_00456500(moby + 0x10, index)) {
                func_L01_004566A8(moby, index, 4);
            }
        }
    }
}
