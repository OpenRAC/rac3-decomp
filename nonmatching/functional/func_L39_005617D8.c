/* functional: high. Per-frame update of a multiplayer-menu homing projectile (object state at 0x68; mode in object[0x20]): mode 0 steers toward its target (aim vector from the target's position scaled by 1/1024, turn rate capped via the state's max turn), advances, casts a collision ray, and on impact (object or world) arms the explosion burst, sound and parks the object, else leaves a 5-puff trail; mode 1 releases its sound slot and frees the object when its countdown reaches -1. PAL disassembly; the NTSC-U draft is the structural guide but the PAL code differs (target-lock threshold 5 frames, different callee set). func_L39_00561630 is called with two arguments although retail leaves two more in a2/a3: the callee ignores them. */
#include "common.h"
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_005617D8;

extern s32 D_L39_00242930;
extern u8 *D_L39_0024CE1C;
extern u8 D_L39_0025F740[];
extern u8 D_1FE020[];
extern u8 *func_00382348(void *);
extern s32 func_L39_005F2FA0(void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern f32 func_0038DB48(f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
extern void func_L39_005F2FF8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_00561630(void *, u8 *);
extern s32 func_0038CB00(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L39_005F3088(s32);
extern void func_003C2880(void *);

void func_L39_005617D8(u8 *p) {
    u8 *st = *(u8 **)(p + 0x68);
    V_005617D8 np;
    V_005617D8 v10;
    V_005617D8 dir;
    V_005617D8 tmp;
    V_005617D8 info[3];
    V_005617D8 *dir2 = &info[1];
    V_005617D8 *v60 = &info[2];
    u8 *t;
    u8 *r;
    u8 *g;
    u8 *snd;
    f32 a;
    f32 k;
    f32 sz;
    s32 hit;
    s32 n;
    s32 i;
    s32 pend;
    s32 idx;

    switch (p[0x20]) {
    case 0:
        *(u16 *)(p + 0x96) = *(u16 *)(p + 0x96) + 1;
        if (func_L39_005F2FA0(p, *(s32 *)(st + 0x30)) == 0) {
            *(s32 *)(st + 0x30) = func_L39_005F33E0(0, 4, p);
        }
        t = *(u8 **)(st + 0x24);
        if (t != 0) {
            r = func_00382348(t);
            if (t[0x20] == 0xFE) {
                *(s32 *)(st + 0x24) = 0;
            } else if (t[0x20] == 0xFD) {
                *(s32 *)(st + 0x24) = 0;
            } else if (r != 0 && *(f32 *)r <= 0.0f) {
                *(s32 *)(st + 0x24) = 0;
            } else if (*(u16 *)(p + 0x96) >= 5) {
                tmp.x = *(f32 *)t * 0.0009765625f;
                tmp.y = *(f32 *)(t + 4) * 0.0009765625f;
                tmp.z = *(f32 *)(t + 8) * 0.0009765625f;
                tmp.w = 0.0f;
                vec_sub_ab(&dir, &tmp, p + 0x10);
                func_0038CF68(&dir, &dir, 1.0f);
                func_0038CF68(&v10, st, 1.0f);
                a = func_0038DB48(func_0038D0C8(func_0038CE68(&dir, &v10)) + 1.5707964f);
                k = 1.0f;
                if (*(f32 *)(st + 0x28) < a) {
                    k = *(f32 *)(st + 0x28) / a;
                }
                func_003C4098(&dir, &v10, &dir, k);
                func_0038CF68(&dir, &dir, 1.0f);
                *(V_005617D8 *)(p + 0xC0) = dir;
                func_0038CE90(p + 0xD0, p + 0xC0, p + 0xE0);
                func_0038CE90(p + 0xE0, p + 0xD0, p + 0xC0);
                *(s32 *)(p + 0xCC) = 0;
                *(s32 *)(p + 0xDC) = 0;
                *(s32 *)(p + 0xEC) = 0;
                func_0038CF68(st, &dir, func_0038CEA8(st));
            }
        }
        vec_add_ba(&np, p + 0x10, st);
        if (*(s16 *)(st + 0x12) < 12) {
            *(s16 *)(st + 0x12) = *(s16 *)(st + 0x12) + 1;
        }
        if (*(f32 *)(st + 0x2C) > 0.0f) {
            func_L01_00446760(&v10, p, 0x10001, &D_L39_00242930, 0.0f);
        } else {
            func_L01_00446760(&v10, p, 0x10001, &D_L39_00242930, (f32)*(s32 *)(st + 0x18));
        }
        pend = *(s32 *)(st + 0x14);
        idx = -1;
        if (D_L39_0024CE1C != 0) {
            idx = *(s32 *)(D_L39_0024CE1C + 0x2548);
        }
        func_L39_005FFDF8(idx);
        hit = func_003D3CB0(p + 0x10, &np, 0, pend, &v10);
        func_L39_005FFE78();
        g = D_L39_0025F740;
        if (hit != 0 && *(u8 **)(g + 0x18) != *(u8 **)(p + 0xB8) && *(u8 **)(g + 0x18) != p) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(p, 1);
            func_L01_004450F0(p, 1, -1);
            func_L39_00561630(p, g + 0x20);
            func_L39_005F33E0(1, 0, p);
        } else if (func_0038CB00(st + 0x10) != 0) {
            *(s32 *)(p + 0x98) = 0;
            *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(p, 1);
            func_L01_004450F0(p, 1, -1);
            func_L39_00561630(p, p + 0x10);
            func_L39_005F33E0(1, 0, p);
        } else {
            func_003C2F58(p, 1, &info[0]);
            func_0038CE20(dir2, st, 0.2f);
            for (i = 0; i < 5; i++) {
                sz = func_L39_005B4410(0.1f, 0.3f) * *(f32 *)(st + 0x20);
                n = func_L39_005B4398(0xFF);
                func_L01_00443B88(v60, 0.0f, 0.1f);
                vec_add_ba(v60, v60, &info[0]);
                func_L01_0046FB40(v60, &D_L39_00242930, 0xC, *(s32 *)(st + 0x1C), n, 0x20, 0,
                                  sz * 210000.0f, sz * 0.2f * 210000.0f, 0.0f, 0);
                vec_add_ab(&info[0], &info[0], dir2);
            }
        }
        *(V_005617D8 *)(p + 0x10) = np;
        break;
    case 1:
        idx = *(s32 *)(st + 0x30);
        if (idx != -1) {
            snd = D_1FE020 + (idx << 7);
            if (*(u8 **)(snd + 0xDC) == p && snd[0xD0] != 0) {
                func_L39_005F3088(idx);
            }
        }
        *(s32 *)(st + 0x30) = -1;
        *(u16 *)(st + 0x12) = *(u16 *)(st + 0x12) - 1;
        if (*(s16 *)(st + 0x12) == -1) {
            func_003C2880(p);
        }
        break;
    default:
        break;
    }
}
