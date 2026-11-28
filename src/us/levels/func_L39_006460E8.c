#include "common.h"
/* localdecomp:start func_L39_006460E8 */
typedef struct {
    s32 f00;
    u8 pad_04[0x20];
    s32 f24;
    s32 f28;
    u8 pad_2C[0x14];
    s32 f40;
    s32 f44;
} Req_648960;

typedef struct {
    u8 pad_00[0x24];
    s32 f24;
    u8 pad_28[0x44];
    s32 f6C;
    u8 pad_70[0x24];
    s32 f94;
} Src_648960;

typedef struct {
    s32 first;
    s32 second;
} Ent_648960;

extern u8 D_001A5995 __attribute__((section(".data")));
extern s32 D_L39_002412AC;
__asm__(".extern D_L39_002412AC, 4");
extern s32 D_L39_00246250;
__asm__(".extern D_L39_00246250, 4");
extern Req_648960 D_L39_00498AA0;
extern Src_648960 D_L39_002257E0;
extern const s32 D_L39_0047AB28[];
extern void func_L39_00646070(u8 *, s32);

void func_L39_006460E8(u8 *obj, s32 idx) {
    if (D_001A5995 != 0 && obj[0x1A14] != 0 && D_L39_002412AC >= 10 && D_L39_00498AA0.f00 == 0 &&
        D_L39_00498AA0.f24 == -1 && D_L39_002257E0.f6C == 0 && D_L39_002257E0.f24 == D_L39_00498AA0.f24 &&
        D_L39_002257E0.f94 == 0) {
        D_L39_00498AA0.f24 = D_L39_0047AB28[idx * 2];
        D_L39_00498AA0.f28 = D_L39_0047AB28[idx * 2 + 1];
        D_L39_00498AA0.f40 = D_L39_00246250;
        D_L39_00498AA0.f44 = 0;
        func_L39_00646070(obj, idx);
    }
}
/* localdecomp:end func_L39_006460E8 */
