/* functional: medium. 459 diff vs retail (no draft; written from asm; frame size 0xF0 matches); constants and loop counts verified; D_001A71A0[0] and D_001D52F0 are absolute (non-gp) globals; draw callback cast because file declares it void(void); unverified by gate */
#include "vu0.h"
extern s32 D_001D52F0;
extern u8 D_L01_001E2A40[];
extern vu0_v4 D_L01_001EAA20, D_L01_001EAA40;
/* Per-frame update of a particle-burst moby (vars at +0x68, state s16 vars+0x10: 0x3A, 0x38, 0x37, 0x36).
   Each state spawns particles around the moby, then the common tail ticks the timer and queues the draw callback. */
void func_L01_003DF8C0(u8 *m) {
    extern void func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
    extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003C2880(u8 *);
    extern void func_00382580(void *, f32, f32);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_00382538(void);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_L01_00470668(u8 *, void *, s32, f32);
    extern void func_L01_002FB660(u8 *, void *, s32, s32, s32, s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_L01_003DF8B8(void);
    extern void func_L01_00404A10(void (*)(void *), void *);
    vu0_v4 zero, p, q20, q30, q40, v50;
    u8 *vars = *(u8 **)(m + 0x68);
    f32 angle, x, y;
    s32 i, n, a, life;
    u8 *part;

    if (*(s32 *)(vars + 0x38) != 0)
        func_L01_0044C638(m, *(s32 *)(vars + 0x38), m + 0x10, m + 0xF0, m + 0x10, m + 0xF0);
    if (func_0038CB00(vars + 0x10) != 0) {
        func_003C2880(m);
        return;
    }
    qzero(&zero);
    if (*(s32 *)(vars + 0x38) != 0)
        func_L01_0044C870(m, *(s32 *)(vars + 0x38), m + 0x10, &zero);

    if (*(s16 *)(vars + 0x10) == 0x3A) {
        n = *(s16 *)(vars + 0x32);
        for (i = 0; i < n; i = i + 1) {
            x = *(f32 *)(vars + 0xC);
            func_00382580(&p, x * 0.30000001f, x * 0.40000004f);
            vec_add_ba(&p, &p, &zero);
            life = (func_00382498(25, 40) * 5 + 2) / 6;
            func_L01_00470668(m + 0x10, &p, life, 0.00584f);
            n = *(s16 *)(vars + 0x32);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x38) {
        n = *(s16 *)(vars + 0x30);
        for (i = 0; i < n; ) {
            i++;
            y = func_003824E0(0.43633232f, 0.78539819f);
            angle = func_00382538();
            x = func_003824E0(10.0f, 20.0f) * 0.02f;
            func_00382760(&p, x * *(f32 *)(vars + 0xC), angle, y);
            vec_add_ba(&p, &p, &zero);
            life = func_00382498(100, 125);
            func_L01_002FB660(m + 0x10, &p, life, 2, 0, 1);
            n = *(s16 *)(vars + 0x30);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x37 && *(s16 *)(vars + 0x3C) != 0) {
        angle = func_00382538();
        func_00382580(&p, 1.0f, 1.0f);
        vec_sub_ab(&q20, D_L01_001E2A40 + D_001D52F0 * 0x460, m + 0x10);
        func_0038CE90(&q30, &q20, &p);
        func_0038CF68(&q30, &q30, 1.0f);
        for (i = 99; i >= 0; i--) {
            a = (s32)func_L01_00443A18(2.0f, 5.0f);
            func_0038D890(&q40, &q30, &p, angle);
            func_0038CF68(&q40, &q40, *(f32 *)(vars + 0xC) * 0.30000001f);
            life = (func_00382498(20, 27) * 5 + 2) / 6;
            x = *(f32 *)(vars + 0xC);
            part = func_L01_004713C8(m + 0x10, &q40, life, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                     x * 231000.0f, x * 252000.016f, 0.0f);
            if (part != 0) part[2] = D_L01_00221098[0x5C][0];
            angle = func_0038DAB8(angle, 0.063466519f);
        }
    }
    if (*(s16 *)(vars + 0x10) == 0x36 && *(s16 *)(vars + 0x16) != 0) {
        angle = func_00382538();
        if (func_L01_003FB640(m + 0x10, 20, (void *)D_001A71A0[0], 1.0f) != 0) {
            q20 = D_L01_001EAA20;
            p = D_L01_001EAA40;
        } else {
            func_00382580(&p, 1.0f, 1.0f);
            q20 = *(vu0_v4 *)(m + 0x10);
        }
        func_0038CF68(&p, &p, 0.05f);
        vec_add_ba(&q20, &q20, &p);
        func_0038CF68(&p, &p, 1.0f);
        vec_sub_ab(&q30, D_L01_001E2A40 + D_001D52F0 * 0x460, m + 0x10);
        func_0038CE90(&q40, &q30, &p);
        func_0038CF68(&q40, &q40, 1.0f);
        if (*(s16 *)(vars + 0x36) != 0) {
            for (i = 0; i < 100; i++) {
                a = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &q40, &p, angle);
                func_0038CF68(&v50, &v50, func_003824E0(5.0f, 9.0f) * 0.02f * *(f32 *)(vars + 0xC));
                if (i % 3 == 0) {
                    life = (func_00382498(20, 27) * 5 + 2) / 6;
                    x = *(f32 *)(vars + 0xC);
                    part = func_L01_004713C8(&q20, &v50, life, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                             x * 231000.0f, x * 252000.016f, 0.0f);
                    if (part != 0) part[2] = D_L01_00221098[0x5C][0];
                }
                angle = func_0038DAB8(angle, 0.063466519f);
            }
        } else {
            for (i = 99; i >= 0; i--) {
                a = (s32)func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v50, &q40, &p, angle);
                func_0038CF68(&v50, &v50, *(f32 *)(vars + 0xC) * 0.30000001f);
                life = (func_00382498(20, 27) * 5 + 2) / 6;
                x = *(f32 *)(vars + 0xC);
                part = func_L01_004713C8(&q20, &v50, life, *(u32 *)(vars + 0x60), a, 0x4F, 0, 1,
                                         x * 231000.0f, x * 252000.016f, 0.0f);
                if (part != 0) part[2] = D_L01_00221098[0x5C][0];
                angle = func_0038DAB8(angle, 0.063466519f);
            }
        }
    }
    func_0038CB00(vars + 0x14);
    func_L01_00404A10((void (*)(void *))func_L01_003DF8B8, m);
}
