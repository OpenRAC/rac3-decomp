/* func_L01_0035F480 (Claude wave 14 r53, 2026-11-28). First draft kept here. */
#include "common.h"

/* localdecomp:start func_L01_0035F480 */
/* wr53 (wave 14), first draft (fresh entry), from the retail listing and the functional C: 231 diff at
 * level 01. Frame (0xD0: two shared vectors + the damage record), saves, block order and every call match;
 * the state tests are an if-chain (retail tests 0, 1, 2, 3 in order), the case-1 particle loop reads the hero,
 * camera and id table through pointer locals (retail's base+offset loads), case 2 keeps the body under
 * `if (!func_0038CAD0(...))`, the 5.0/4.0 scale is two func_003D4D00 calls cross-jumped as retail, and the
 * damage is loaded before the 2000.0 override. Left: register permutations in the case-1 loop (hero/camera/
 * counter in s4/s5/s2 where retail has s5/s4/s2, &vel s6), the camera stores of the case-1 else branch
 * (retail addresses them from &D_L01_001E2A40 in s1/a0), the mob loop's n > 0 test (bgtz; retail copies n
 * to s4 and tests bnez, a do-while with --n != 0 gives 233), and the vsub register roles in the mob loop. Callees declared in the body with
 * this block's own types (the file's later blocks declare func_00382348 / func_L01_00446760 /
 * func_L01_00446978 with their own structs, so the contract stage conflicts until they share one). */
#include "vu0.h"
typedef struct { u8 p0; u8 kind; u8 pad2[0x6A]; f32 damage; u8 pad70[0x80]; } Row_0035F480;
typedef struct {
    S_38C110v vec; u8 *attacker; u8 pad14[4]; u8 b18; u8 b19; s16 source_class; s32 pad1C; s32 flag; u8 pad24[0x0C];
} Info_0035F480;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern Row_0035F480 D_L01_002C5600_0035F480[];
extern u8 *D_L01_00221098[];
extern u8 D_L01_001E2880[];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001D66B0[8];
extern u8 *D_L01_001EEA80[];
__asm__(".extern D_L01_001DD704, 4");
__asm__(".extern D_L01_001DD708, 4");
__asm__(".extern D_L01_001DD70C, 4");
extern f32 D_L01_001DD704;
extern f32 D_L01_001DD708;
extern f32 D_L01_001DD70C;

void func_L01_0035F480(u8 *m) {
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00404808(void *, u8 *);
    extern void func_L01_00360A48(u8 *);
    extern void func_L01_00361690(u8 *);
    extern void func_L01_00360A00(void);
    extern void func_L01_003609D0(void *);
    extern void func_L01_00360170(u8 *);
    extern void func_L01_0035FEC8(u8 *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382498(s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_0039B478(void *, void *, s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_L01_00474390(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32);
    extern u8 *func_L01_0046B458(u8 *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
    extern u8 *func_L01_00470C78(u8 *, s32, s32, s32, s32, void *, s32, s32, s16, s32, f32, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern void *func_00382348(void *);
    extern void func_L01_00446760(Info_0035F480 *, u8 *, s32, void *, f32);
    extern void func_L01_00446978(u8 *, Info_0035F480 *);
    extern void func_L01_0031B090(u8 *, s32, s32);
    extern void func_003C2880(void *);
    u8 *v = *(u8 **)(m + 0x68);
    S_38C110v pos, vel;
    Info_0035F480 info;
    s32 colour, c1, c2, c3, c4;
    s32 i, n, kind, life;
    f32 ang, len, mult, dmg;
    u8 *p;
    u8 *hero;
    u8 *cam;
    u8 **ids;
    u8 **mp;

    if (func_L01_004CB2D8()) {
        func_L01_004CAB30(m + 0x10, m + 0x10);
    }
    if (m[0x20] == 0) {
        func_0038CAD0(v + 0x14);
        *(f32 *)(v + 0x18) -= 0.13f;
        if (*(s32 *)(v + 0x14) >= 0x4C) {
            *(f32 *)(v + 0x34) += 0.1f;
            func_L01_00404808(func_L01_00360A48, m);
        } else {
            func_L01_00404808(func_L01_00361690, m);
            m[0x20] = 1;
        }
    } else if (m[0x20] == 1) {
        func_0038CAD0(v + 0x14);
        if (*(s32 *)(v + 0x14) >= 0x49) {
            func_L01_00404808(func_L01_00361690, m);
            colour = 0x606060;
            func_L01_00404808(func_L01_00360A00, m);
            hero = D_001A4BE0;
            cam = D_L01_001E2880;
            ids = D_L01_00221098;
            if (D_L01_002C5600_0035F480[D_001425C0[0x77]].kind >= 2) {
                colour = 0x406080;
            }
            for (i = 0; i < 50; i++) {
                ang = func_0038D160(*(f32 *)(hero + 0x80) - *(f32 *)(cam + 0x140),
                                    *(f32 *)(hero + 0x84) - *(f32 *)(cam + 0x144));
                func_L01_00443A18(1.0f, 2.0f);
                pos.x = *(f32 *)v + func_L01_00443A18(0.0f, 0.15f);
                pos.y = *(f32 *)(v + 4) + func_L01_00443A18(0.0f, 0.15f);
                pos.z = *(f32 *)(v + 8) + 0.1f;
                ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, -6.2831855f));
                vel.x = func_0038D098(ang) * 0.20000002f;
                vel.y = func_0038D0B0(ang) * 0.20000002f;
                vel.z = 0.0f;
                life = func_00382498(20, 40);
                p = func_L01_004713C8(&pos, &vel, (life * 5 + 2) / 6, colour, func_00382498(-2, -4), 0x40, 0, 0,
                                      126000.01f, 231000.0f, 0.0f);
                if (p != 0) {
                    p[2] = *ids[0x17];
                }
            }
        } else {
            vec_sub_ba(&pos, D_L01_001E2A40, m + 0x10);
            len = func_0038CEA8(&pos);
            if (len < 20.0f) {
                *(f32 *)(D_L01_001E2A40 + 0x20) = 0.4f - len * 0.02f;
            } else {
                *(s32 *)(D_L01_001E2A40 + 0x20) = 0;
            }
            *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
            *(s32 *)(D_L01_001E2A40 + 0x28) = 0x15;
            if (D_L01_002C5600_0035F480[D_001425C0[0x77]].kind != 0) {
                func_L01_0039B478(m + 0x10, m, 0);
            }
            c1 = 0xBF804020;
            c2 = 0xBF604020;
            c3 = 0x80FF8040;
            c4 = 0xFF8040;
            kind = D_L01_002C5600_0035F480[D_001425C0[0x77]].kind;
            if (kind >= 2) {
                c1 = 0xBF204080;
                c2 = 0xBF2040A0;
                c3 = 0x804080FF;
                c4 = 0x4080FF;
            } else if (kind >= 3) {
                c1 = 0xBF102080;
                c2 = 0xBF1020A0;
                c3 = 0x801020FF;
                c4 = 0x1020FF;
            }
            if (D_L01_002C5600_0035F480[D_001425C0[0x77]].kind != 0) {
                for (i = 0; i < 50; i++) {
                    func_00382580(&vel, 0.40000004f, 0.50000006f);
                    life = func_00382498(20, 35);
                    func_L01_00474390(m + 0x10, &vel, (life * 5 + 2) / 6, c3, c4, 0x14, 0,
                                      0.16f, 1.0f, 2.0f, 0.1f);
                }
            }
            func_L01_0046B458(m + 0x10, 0x14, c1, 2, 2, D_L01_001D66B0, 1, 17.5f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, c2, 2, -2, D_L01_001D66B0, 1, 12.5f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, 0xC0FFFFFF, 2, 2, D_L01_001D66B0, 1, 8.75f, 0.1f, 0.0f);
            func_L01_0046B458(m + 0x10, 0x14, 0xB0FFFFFF, 2, -2, D_L01_001D66B0, 1, 6.25f, 0.1f, 0.0f);
            func_L01_00470C78(m + 0x10, 0x14, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1, 2.6999998f, 2.0999999f);
            func_L01_00470C78(m + 0x10, 0x14, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1, 5.1000004f, 2.0999999f);
            func_L01_00470C78(m + 0x10, 0x14, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1, 6.0f, 4.5f);
            m[0x20] = 2;
        }
    } else if (m[0x20] == 2) {
        f32 a = *(f32 *)(v + 0x18) + 0.4f;
        f32 b = D_L01_001DD708 + 0.5f;
        f32 c = D_L01_001DD70C + 0.7f;
        *(f32 *)(v + 0x18) = a;
        D_L01_001DD708 = b;
        D_L01_001DD70C = c;
        if (1.6f < a) {
            *(f32 *)(v + 0x18) = 1.6f;
        }
        if (func_0038CAD0(v + 0x1C) == 0) {
            *(s128 *)&pos = *(s128 *)(m + 0x10);
            pos.w = 2.0f;
            if (func_0038DC20(&pos, 100.0f) != -1) {
                s32 t;
                t = *(s32 *)(v + 0x20) - 4;
                D_L01_001DD704 += 0.8f;
                *(s32 *)(v + 0x20) = t;
                if (t < 0) {
                    *(s32 *)(v + 0x20) = 0;
                }
                func_L01_00404808(func_L01_003609D0, m);
                func_L01_00404808(func_L01_00361690, m);
                func_L01_00404808(func_L01_00360170, m);
            }
            func_L01_0035FEC8(m);
            if (D_L01_002C5600_0035F480[D_001425C0[0x77]].kind >= 3) {
                n = func_003D4D00(m + 0x10, 0, m, 0, (1.0f - (f32)*(s32 *)(v + 0x1C) / 17.0f) * 5.0f + 2.0f);
            } else {
                n = func_003D4D00(m + 0x10, 0, m, 0, (1.0f - (f32)*(s32 *)(v + 0x1C) / 17.0f) * 4.0f + 2.0f);
            }
            hero = D_001A4BE0;
            for (mp = D_L01_001EEA80; n > 0; n--, mp++) {
                if (func_00382348(*mp) == 0) {
                    if (!(*(u16 *)(*mp + 0x34) & 0x4000)) {
                        continue;
                    }
                }
                if (*mp == *(u8 **)(hero + 0x25C0)) {
                    if (*(s16 *)(*mp + 0xAA) != 0x1865) {
                        continue;
                    }
                }
                if (*(s16 *)(*mp + 0xAA) == 0x185A) {
                    continue;
                }
                vec_sub_ab(&vel, *mp + 0x10, m + 0x10);
                func_0038CF68(&vel, &vel, 1.5f);
                func_0038CF68(&info, &info, 1.0f);
                dmg = D_L01_002C5600_0035F480[D_001425C0[0x77]].damage;
                if (*(s32 *)(v + 0x38) != 0) {
                    dmg = 2000.0f;
                }
                func_L01_00446760(&info, m, 0x1030000, &vel, dmg);
                *(s128 *)&info.vec = *(s128 *)&vel;
                info.flag = 1;
                info.vec.w = 5627.9248f;
                info.b18 = 5;
                info.b19 = 3;
                info.attacker = m;
                info.source_class = *(s16 *)(*mp + 0xAA);
                if (*(s32 *)(v + 0x38) != 0) {
                    info.attacker = 0;
                }
                func_L01_00446978(*mp, &info);
                func_L01_0031B090(*mp, 0x77, *(s32 *)(v + 0x28));
            }
        } else {
            m[0x20] = 3;
        }
    } else if (m[0x20] == 3) {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_0035F480 */
