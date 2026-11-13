#include "common.h"

/* NTSC-U counterpart of func_L39_006C45C8 (src/levels/39_multiplayer_menu/L39_006C45C8.c) */
typedef struct {
    char pad0[4];
    s32 w4;
    char pad8[0x164];
    s32 w16C;
} S_1A5CD0_006C4308;
extern S_1A5CD0_006C4308 D_001A5E50;

/* localdecomp:start func_L39_006C1AB0 */
/* best: 1 diff under --mode S --as ps2as (file flags: ~60). Only the final return: retail nor+slti $v0,$v0,0, mine srl 0x1f. Tried >=0, >-1, -1<, !(<0), ~x<0, ?:, (<0)^1, != -1 (sltu), return types u8/s8/s16/u32/long. */
typedef struct {
    char name[8][16];
    char _p0[0xE0 - 0x80];
    s16 hE0[8];
} S_006C45C8_p;

extern S_006C45C8_p *D_001D5F30_sda_006C1AB0;
extern S_1A5CD0_006C4308 D_001A5E50;
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} S_006C45C8_g;
extern s32 func_001205B0(u8 *, char *);
typedef struct {
    char _p0[0x110];
    u8 *f110[1];
} S_006C45C8_o;

s32 func_L39_006C1AB0(S_006C45C8_o *a0, s32 a1, s32 *out) {
    u8 *name;
    s32 i;

    *out = -1;
    name = a0->f110[a1 + 15] + 0x14;
    if (name == 0) {
        return 0;
    }
    if (name[0] != 0) {
        for (i = 0; i < 8; i++) {
            if (D_001D5F30_sda_006C1AB0 != 0 && D_001D5F30_sda_006C1AB0->hE0[i] != -1) {
                if (D_001D5F30_sda_006C1AB0->hE0[i] == ((S_006C45C8_g *)&D_001A5E50)->w8) {
                    (*out)++;
                }
                if (func_001205B0(name, D_001D5F30_sda_006C1AB0->name[i]) == 0) {
                    if (D_001D5F30_sda_006C1AB0->hE0[i] != ((S_006C45C8_g *)&D_001A5E50)->w8) {
                        *out = -1;
                    }
                    return ~*out >> 31 != 0;
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006C1AB0 */
