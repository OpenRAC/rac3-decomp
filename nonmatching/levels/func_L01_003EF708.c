/* NTSC-U draft (Codex wave 3): C of func_L01_003ED7C8, the NTSC-U twin of func_L01_003EF708, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 32 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003ED7C8", whose code is not the PAL one).
 * Worker's note: 32 diff; best log func_L01_003ED7C8.check-03.log; small pointer with .extern 16 fixes ordinary global accesses and removes unresolved alias use; remaining VU0/prologue and final-copy scheduling; j-form fails allowed flags VU_REGS log .check-04; no unlisted ...
 */
#include "common.h"

/* NTSC-U level function. */
extern u8 D_L01_001E2A40[];
extern u8 D_001A3190[];
extern u8 D_001A30B0[];
extern s32 func_L01_004A74A0(s32, s32, void *, s32);
extern void func_0039FB08(s32);
#include "vu0.h"
extern void func_003888C8(void *, void *, void *);

/* localdecomp:start func_L01_003ED7C8 */
#include "vu0.h"

typedef struct Ent_00574AF0 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    u8 f18;
    u8 pad19[7];
} Ent_00574AF0;

extern Ent_00574AF0 *D_L01_001DFBEC;
__asm__(".extern D_L01_001DFBEC, 16");
extern Ent_00574AF0 *D_001DFBEC_sda;
__asm__(".extern D_001DFBEC_sda, 4");
extern Ent_00574AF0 *D_L01_001DFBEC_003ED7C8;
__asm__(".extern D_L01_001DFBEC_003ED7C8, 0");
extern void func_003888C8(void *, void *, void *);
extern f32 func_00388770(void *);
extern s32 func_00388398(void *);
extern s32 func_0039EA60(void *, s32, f32, f32, f32);
extern s32 func_0039FFC8(u32, s32);
extern s32 func_0037E1D8(s32);

void func_L01_003ED7C8(u8 *self) {
    s32 *sub = *(s32 **)(self + 8);
    vu0_v4 d;
    vu0_v4 s;
    vu0_v4 v;
    vu0_v4 w;
    f32 lw;
    f32 lv;
    f32 r;
    s32 flags;
    s32 id;
    u8 *slot;
    vu0_q qa, qb;
    vu0_v4 *camera = (vu0_v4 *)D_L01_001E2A40;

    __asm__("lqc2 $vf2, %0" : : "m"(*camera) : "vf2");
    __asm__("lqc2 $vf1, %0" : : "m"(*(vu0_v4 *)(self+0x40)) : "vf1");
    __asm__("vsub.xyz $vf2, $vf2, $vf1" : : : "vf2");
    s.z = s.y = s.x = *(f32 *)(self + 0xC);
    __asm__("sqc2 $vf2, %0" : "=m"(d) : : "vf2");
    d.w = 0;
    func_003888C8(&v, &d, self + 0x50);
    func_003888C8(&w, &s, self + 0x50);
    lw = func_00388770(&w);
    lv = func_00388770(&v);
    if (lv < lw) {
        flags = 0x10;
        if (fabs_asm(v.x) <= 1.0f && fabs_asm(v.y) <= 1.0f && fabs_asm(v.z) <= 1.0f) {
            id = D_001DFBEC_sda[sub[0]].fC;
        } else {
            if (v.x > 1.0f) {
                v.x = 1.0f;
            } else if (v.x < -1.0f) {
                v.x = -1.0f;
            }
            if (v.y > 1.0f) {
                v.y = 1.0f;
            } else if (v.y < -1.0f) {
                v.y = -1.0f;
            }
            if (v.z > 1.0f) {
                v.z = 1.0f;
            } else if (v.z < -1.0f) {
                v.z = -1.0f;
            }
            r = func_00388770(&v);
            id = func_0039EA60(&((Ent_00574AF0 *)D_L01_001DFBEC)[sub[0]], 0, lv, r, lw);
        }
        if (D_L01_001DFBEC[sub[0]].f18) {
            flags = 0x14;
        }
        slot = D_001A30B0 + (sub[4] << 7);
        if (*(u8 **)(slot + 0x100) != self || slot[0xD0] == 0) {
            if (func_00388398(sub + 3)) {
                sub[4] = func_L01_004A74A0(sub[0], flags, self, id);
                if (sub[2] > 0) {
                    sub[3] = (s32)((sub[1] + func_0037E1D8(sub[2] - sub[1])) * 60.0f);
                }
            } else {
                sub[4] = -1;
            }
        }
        if (sub[4] != -1) {
            func_0039FFC8(sub[4], id);
            func_003888C8(&d, &v, self + 0x10);
            {
                vu0_q pa, pb, pr;

                __asm__("lqc2 $vf2, %0" : : "m"(*(vu0_v4 *)(self+0x40)) : "vf2");
                __asm__("lqc2 $vf1, %0" : : "m"(d) : "vf1");
                __asm__("vadd.xyz $vf1, $vf1, $vf2" : : : "vf1");
                __asm__("sqc2 $vf1, %0" : "=m"(d) : : "vf1");
            }
            *(vu0_q *)(D_001A3190 + (sub[4] << 7)) = *(vu0_q *)&d;
        }
    } else {
        s32 index = sub[4];
        if (index != -1) {
            u8 *slot2 = D_001A30B0 + (index << 7);
            if (*(u8 **)(slot2 + 0x100) == self && slot2[0xD0]) {
                func_0039FB08(index);
            }
        }
        sub[4] = -1;
    }
}
/* localdecomp:end func_L01_003ED7C8 */
