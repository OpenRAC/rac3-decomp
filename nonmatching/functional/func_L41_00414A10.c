/* functional: high. PAL rewrite from the disassembly (the NTSC draft's callees and 60 Hz constant differ: PAL uses 50.0f and func_L40_0053D8C8). 97 instructions differ in scheduling/regalloc; all branches and calls read against the asm. */
#include "common.h"
/* localdecomp:start func_L41_00414A10 */
typedef struct { u8 p0[0x70]; s32 slots[5]; s32 interval; u8 p88[8]; s32 timer; u8 p94[4]; s32 token; u8 p9C[4]; s32 arg; s32 values[5]; s32 pB8; s32 group; } P_414A10;
extern u16 *D_L41_0028EB60[];
extern s32 D_L41_00248698;
extern s32 D_001DCF88_sda;
extern u8 *D_L41_0024865C;
extern s32 D_L41_0025BAD8;
extern u8 D_001A5CD0[];
extern s32 func_L40_0053D8C8(s32, s32, s32, s32);
extern void func_L40_003EFDE0(void);
extern void func_L40_003EE130(void);
extern void func_L41_003EDA60(void);
extern void func_L39_0061C1E0(void *, s32);
extern s32 func_003D4D00(void *, s32, s32, s32, f32);
extern void func_L41_00414900(s32 *, s32 *);
extern s32 func_L41_004149E0(void *);
extern s32 func_0038CAD0(void *);
extern s32 func_L41_00414980(void *);
extern s32 func_L41_003ED748(void *, s32, s32, s32 *, s32, s32, s32);

void func_L41_00414A10(u8 *obj) {
    P_414A10 *p = *(P_414A10 **)(obj + 0x68);
    obj[0x30] = 0xFF;
    if (obj[0x20] == 0) {
        s32 i;
        for (i = 0; i < 5; i++) {
            p->slots[i] = 0;
            p->values[i] = 0;
            func_L40_0053D8C8(0x109D, (s32)func_L40_003EFDE0, (s32)func_L40_003EE130, (s32)func_L41_003EDA60);
        }
        {
            u16 **tab = D_L41_0028EB60;
            u16 *list = tab[p->group];
            if ((p->group & 0xFF) != 0xFF && p->group <= D_L41_00248698 && list != 0) {
                while (1) {
                    u8 *m = D_L41_0024865C + ((*list & 0x7FFF) << 8);
                    if (m == 0) {
                        break;
                    }
                    list++;
                    func_L39_0061C1E0(m, -1);
                    if ((p->group & 0xFF) == 0xFF || D_001DCF88_sda < p->group || list == 0) {
                        break;
                    }
                    if (!((s16)list[-1] >= 0 || list == tab[p->group])) {
                        break;
                    }
                }
            }
        }
        if (p->interval <= 0) {
            p->interval = 30;
        }
        if (func_003D4D00(obj + 0x10, 1, 0, 0, 3.0f)) {
            p->token = D_L41_0025BAD8;
        }
        obj[0x20] = 1;
    }
    if (D_001A5CD0[0x168] != 0) {
        s32 i;
        for (i = 0; i < 5; i++) {
            func_L41_00414900(&p->values[i], &p->slots[i]);
        }
        if (func_L41_004149E0(p) != 0) {
            func_0038CAD0(&p->timer);
        }
        if (p->timer > 0) {
            return;
        }
        if (func_L41_00414980(obj) == 0) {
            return;
        }
        if (func_003D4D00(obj + 0x10, 1, p->token, 0, 3.0f) != 0) {
            return;
        }
        {
            u32 pos[4];
            pos[0] = ((u32 *)(obj + 0x10))[0];
            pos[1] = ((u32 *)(obj + 0x10))[1];
            pos[2] = ((u32 *)(obj + 0x10))[2];
            pos[3] = ((u32 *)(obj + 0x10))[3];
            func_L41_003ED748(pos, p->group, -1, p->slots, -1, p->arg, -1);
        }
    }
    p->timer = (s32)((f32)p->interval * 50.0f);
}
/* localdecomp:end func_L41_00414A10 */
