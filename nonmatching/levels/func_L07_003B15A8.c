/* NTSC-U draft (Claude wave C4): C of func_L07_003AFCF0, the NTSC-U twin of func_L07_003B15A8, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L07_003AFCF0", whose code is not the PAL one).
 * Worker's note: flags: needs -mvu0-use-vf0-vf2 in addition ('-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as': vec_add_ba helper for the lqc2/vadd.xyz/sqc2); with it 9 aligned words differ (of 235): the register pair of the two 'D_L07_001E8C00.p18 == ...
 */
#include "common.h"
#include "vu0.h"

typedef struct {
    f32 f00;
    f32 f04;
    f32 f08;
    u8 pad0C[4];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[3];
    u8 b24;
    u8 pad25;
    u8 b26;
} Priv_003AFCF0;

typedef struct {
    u8 pad00[0x18];
    u8 *p18;
    s32 w1C;
    vu0_v4 v20;
} Glob_003AFCF0;

/* localdecomp:start func_L07_003AFCF0 */
extern Glob_003AFCF0 D_L07_001E8C00;
extern s32 D_001A71A0;
extern u8 D_L07_003B0350[];
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_004C76B8(void);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_004C76F0(void);
extern f32 func_003887C8(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443938(s32, s32, s32, void *, void *, f32);
extern void func_L01_00452F40(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L07_003B0178(u8 *);
extern void func_L01_004026A0(void *, void *);
extern void func_003BD360(void *);

void func_L07_003AFCF0(u8 *obj) {
    vu0_v4 v0;
    vu0_v4 v10;
    Priv_003AFCF0 *p;
    u8 *e;
    s32 hit;
    s32 w;

    p = *(Priv_003AFCF0 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        p->f18 = func_00389380(p->f18, 0.104719765f);
        p->f10 = p->f10 + 1.3333334f;
        func_003886E8(&v0, obj + 0xC0, p->f10);
        w = *(s32 *)(obj + 0xB8);
        vec_add_ba(&v0, obj + 0x10, &v0);
        func_L01_004C76B8();
        hit = func_003CE740(obj + 0x10, &v0, 0, w, 0);
        if (hit != 0) {
            e = D_L07_001E8C00.p18;
            if (e != 0 && *(s16 *)(e + 0xAA) == 0x186D && e[0x20] != 2 && e[0x20] != 5) {
                e[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit != 0) {
            p->f10 = func_003887C8(obj + 0x10, &D_L07_001E8C00.v20);
            if (D_L07_001E8C00.w1C > 0) {
                *(vu0_q *)p = *(vu0_q *)&D_L07_001E8C00.v20;
                p->b24 = 1;
                p->f08 = p->f08 + 0.1f;
            }
            if ((s32)D_L07_001E8C00.p18 == D_001A71A0) {
                func_00388830(&v10, obj + 0xC0, 0.083333336f);
                func_L01_00443938((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, &D_L07_001E8C00.v20, &v10, (f32)p->b26);
                func_L01_00452F40(*(s32 *)(obj + 0xB8), 1);
            }
            func_L01_00441FB8(obj, 1, -1);
        } else {
            *(u16 *)(obj + 0x96) += 1;
            if (*(u16 *)(obj + 0x96) >= 0x3D) {
                func_L01_00441FB8(obj, 1, -1);
            }
        }
        func_L01_004026A0(D_L07_003B0350, obj);
        break;
    case 1:
        if (p->f14 < 0.5f) {
            func_003886E8(&v0, obj + 0xC0, p->f10);
            vec_add_ba(&v0, obj + 0x10, &v0);
            if (func_003CE740(obj + 0x10, &v0, 0, *(s32 *)(obj + 0xB8), 0) != 0) {
                if ((s32)D_L07_001E8C00.p18 == D_001A71A0) {
                    func_00388830(&v10, obj + 0xC0, 0.083333336f);
                    func_L01_00443938((s32)D_L07_001E8C00.p18, *(s32 *)(obj + 0xB8), 1, &D_L07_001E8C00.v20, &v10, (f32)p->b26);
                    func_L01_00452F40(*(s32 *)(obj + 0xB8), 1);
                }
            }
        }
        func_L07_003B0178(obj);
        p->f18 = func_00389380(p->f18, 0.104719765f);
        p->f14 = p->f14 + 0.08f;
        if (p->f14 >= 1.0f) {
            p->f14 = 1.0f;
            if (p->b24 != 0) {
                func_L01_00441FB8(obj, 2, -1);
            } else {
                func_L01_00441FB8(obj, 3, -1);
            }
        }
        func_L01_004026A0(D_L07_003B0350, obj);
        break;
    case 2:
        if (func_L07_003B0178(obj) != 0) {
            func_L01_00441FB8(obj, 3, -1);
        }
        func_L01_004026A0(D_L07_003B0350, obj);
        break;
    case 3:
        func_003BD360(obj);
        break;
    }
}
/* localdecomp:end func_L07_003AFCF0 */
