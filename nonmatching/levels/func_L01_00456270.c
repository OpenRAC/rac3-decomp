/* PAL near miss (Codex wave 6): near miss: 11 words differ with the file's flags.
 * Worker's note: 11 diff; build/codex/w267/func_L01_00456270.best.log; initial record/cache register allocation and load/store order; three direct/typed/preloaded cache forms give identical 12-diff result; selection loops exact
 */
#include "common.h"
/* localdecomp:start func_L01_00456270 */
typedef struct { u8 pad0[0x1A]; s16 stamp; } Rec_00456270;
typedef struct { s32 first; u8 count; u8 pad5[3]; s32 last; } Cache_00456270;
extern char *D_L01_001DFC4C;
extern u8 *D_L01_001DFC48 __attribute__((section(".data")));
extern u16 D_L01_001DFB40_00456270;
extern u16 D_001DFB40_sda;
extern s16 D_L01_001E0180[] __attribute__((section(".sdata")));
extern s16 D_L01_001E01C0[] __attribute__((section(".sdata")));
extern u8 *D_L01_001E001C;
extern s32 D_L01_001D6774;
extern void *D_L01_001EFFE8[];
extern int D_L01_001F01E8[];
extern u8 D_001A4C60_00456270[];
__asm__(".extern D_L01_001DFB40_00456270, 16");
__asm__(".extern D_001DFB40_sda, 2");
__asm__(".extern D_L01_001DFC48, 16");
__asm__(".extern D_L01_001E0180, 64");
__asm__(".extern D_L01_001E01C0, 64");
static __inline__ u8 *base_00456270(u8 **p) { return *p; }
void func_L01_00456270(s32 index)
{
    extern s32 func_L01_00456500(void *, s32);
    extern void func_L01_004566A8(void *, s32, s32);
    Rec_00456270 *rec = (Rec_00456270 *)(D_L01_001DFC4C + (index * 0x30 + 0x20));
    Cache_00456270 *cache;
    s32 i;
    s32 offset;
    u8 *moby;
    if (rec->stamp == D_L01_001DFB40_00456270) return;
    offset = index * 0xE0;
    rec->stamp = D_001DFB40_sda;
    cache = (Cache_00456270 *)(base_00456270(&D_L01_001DFC48) + offset);
    cache->first = 0;
    cache->count = 0;
    cache->last = 0;
    if (func_L01_00456500(D_001A4C60_00456270, index)) {
        func_L01_004566A8(*(void **)(D_001A4C60_00456270 + 0x2540), index, 1);
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
/* localdecomp:end func_L01_00456270 */
