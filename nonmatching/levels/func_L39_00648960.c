/* NTSC-U draft (Claude wave C2): C of func_L39_006460E8, the NTSC-U twin of func_L39_00648960, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 6 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006460E8", whose code is not the PAL one).
 * Worker's note: 6 diff, only the order/registers of the last load group: retail loads table[idx*2+1] into a3, then the gp word D_001DA9C0_sda into v0, then table[idx*2] into a2 (move a0,t1 between); ours loads second->a2, first->a3, gp last (all 24 orders of the four stores ...
 */
#include "common.h"

/* NTSC-U counterpart of the PAL function at the same position (L39 shared) */
/* localdecomp:start func_L39_006460E8 */
typedef struct {
    s32 f00;
    u8 pad_04[0x20];
    s32 f24;
    s32 f28;
    u8 pad_2C[0x14];
    s32 f40;
    s32 f44;
} Req_6460E8;

typedef struct {
    u8 pad_00[0x24];
    s32 f24;
    u8 pad_28[0x44];
    s32 f6C;
    u8 pad_70[0x24];
    s32 f94;
} Src_6460E8;

typedef struct {
    s32 first;
    s32 second;
} Ent_6460E8;

extern u8 D_001A5995[];
extern s32 D_001D5A1C_sda;
__asm__(".extern D_001D5A1C_sda, 4");
extern s32 D_001DA9C0_sda;
__asm__(".extern D_001DA9C0_sda, 4");
extern Req_6460E8 D_L39_00498AA0;
extern Src_6460E8 D_L39_002257E0;
extern s32 D_L39_0047AB28[];
extern void func_L39_00646070(u8 *, s32);

void func_L39_006460E8(u8 *obj, s32 idx) {
    if (D_001A5995[0] != 0 && obj[0x1A14] != 0 && D_001D5A1C_sda >= 10 && D_L39_00498AA0.f00 == 0 &&
        D_L39_00498AA0.f24 == -1 && D_L39_002257E0.f6C == 0 && D_L39_002257E0.f24 == D_L39_00498AA0.f24 &&
        D_L39_002257E0.f94 == 0) {
        D_L39_00498AA0.f28 = D_L39_0047AB28[idx * 2 + 1];
        D_L39_00498AA0.f24 = D_L39_0047AB28[idx * 2];
        D_L39_00498AA0.f40 = D_001DA9C0_sda;
        D_L39_00498AA0.f44 = 0;
        func_L39_00646070(obj, idx);
    }
}
/* localdecomp:end func_L39_006460E8 */
