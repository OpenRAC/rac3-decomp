#include "common.h"

/* NTSC-U counterpart of func_L07_00332098 (src/levels/07_annihilation_nation/L07_00332098.c) */
/* localdecomp:start func_L07_00331958 */
typedef struct Ent_332098 {
    u8 b0;
    u8 pad1[0xB];
} Ent_332098;
typedef struct Tab_332098 {
    u8 pad0[4];
    Ent_332098 *ents;
    u8 pad8[8];
} Tab_332098;
typedef struct Vars_332098 {
    u8 pad0[0x50];
    s32 slot[8];
    u8 pad70[0x9E - 0x70];
    u8 b9E;
    u8 b9F;
} Vars_332098;
extern Tab_332098 D_L07_002B0D40_00331958[];
__asm__(".extern D_L07_002B0D40_00331958, 16");
extern u8 *D_L07_001DF41C_00331958;
__asm__(".extern D_L07_001DF41C_00331958, 16");
extern s32 func_L07_00333450(void);
extern s32 func_L07_003334B8(void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L02_0039E538(void *, s32);
extern s32 func_L07_003A0D08(void);
extern void func_L07_003A0BC0(s32, void *, s32, s32);

void func_L07_00331958(u8 *obj) {
    Vars_332098 *vars = *(Vars_332098 **)(obj + 0x68);
    Ent_332098 *ent = D_L07_002B0D40_00331958[vars->b9E].ents + vars->b9F;
    s32 flag;
    s32 diff;
    s32 rnd;
    s32 acc;
    s32 i;
    s32 k;
    s32 carry;
    u8 *p;

    if (ent->b0 == 0) {
        return;
    }
    diff = 8 - func_L07_00333450();
    flag = ent->b0 == 2;
    if (flag) {
        if (func_L07_003334B8(obj) != 0) {
            flag = 0;
        }
    }
    if (diff != 0) {
        rnd = func_0037E1D8(8);
        acc = 4;
        for (i = 0; i < 8; i++) {
            if ((vars->b9F & 1) != (i & 1)) {
                continue;
            }
            k = rnd + i;
            acc += diff;
            if (k >= 8) {
                k -= 8;
            }
            carry = 0;
            if (acc >= 8) {
                acc -= 8;
                carry = 1;
            }
            p = D_L07_001DF41C_00331958 + (vars->slot[k] << 8);
            if (flag) {
                if (func_L02_0039E538(p, 1) == 0) {
                    continue;
                }
                if (func_L07_003A0D08() != 0) {
                    func_L07_003A0BC0((u8)func_0037E208(0x25, 0x26), obj, 0, 0x78);
                }
                flag = 0;
            } else if (carry) {
                func_L02_0039E538(p, 0);
            }
        }
    }
}
/* localdecomp:end func_L07_00331958 */
