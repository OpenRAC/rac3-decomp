/* near miss (level 11, Obani Moons): 108 differences (with the file's flags): the block layout, both switches (the second with retail's empty cases 1, 2 and 5, which give its jump table) and every call are retail's; what differs is one register choice that runs through the function: retail keeps a0 in $s3 because the death effect's func_L01_003303B8 call holds three of its stack constants (0x63F7, 0x20FF, 0x8FFF) in $s0-$s2, while here those constants get $t1/$t3/$t7 and a0 gets $s2. Not tuned further (argument order of the 30-parameter call is the likely lever) */
#include "common.h"

/* localdecomp:start func_L11_003A9260 */
#include "vu0.h"
typedef struct { s32 n; u8 pad4[0xC]; vu0_v4 pts[1]; } P_3A9260;
extern P_3A9260 *D_L11_0021CB80[];
extern s32 func_L11_003A9860(u8 *);
extern void func_L11_003A9CB0(u8 *);
extern void func_L11_003A9D50(void *);
extern void func_003C2880(void *);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_00315900(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L11_003A9260(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    P_3A9260 *l;
    s32 i;
    s32 r;
    f32 best;
    f32 f;

    if (func_L11_003A9860(a0) != 0) {
        goto kill;
    }
    if (*(f32 *)(v + 0x30) <= 0.0f) {
        func_L11_003A9CB0(a0);
        func_L01_003303B8(a0 + 0x10, 3.0f, 1, 0x28, 0x28, 0x28, 0x28, 0x41, 0, 0.0f, 0.0f, 2.0f,
            0, 1, 1, 1, 1, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
kill:
        func_003C2880(a0);
        return;
    }
    switch (a0[0x95]) {
    case 0:
        if (func_L01_004561E0(a0) != 0) {
            *(s16 *)(v + 0x2D6) = (func_00382498(0, 30) * 5 + 2) / 6;
        }
        func_0038D890(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.041887905f);
        func_0038D890(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.041887905f);
        if (*(s16 *)(v + 0x234) == 1 && func_0038CB00(v + 0x2D6) != 0) {
            break;
        }
        if (*(s32 *)(v + 0x2D8) != 0 && func_0038CB00(v + 0x2D6) != 0) {
            *(s32 *)(v + 0x2D8) = 0;
            if (*(s32 *)(v + 0x2D0) < 250) {
                *(s32 *)(v + 0x2D0) = (func_00382498(480, 600) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (*(s16 *)(v + 0x234) == 1) {
            goto hit;
        }
        if (*(s32 *)(v + 0x2D0) == 0) {
            func_L01_004450F0(a0, 1, 0);
        }
        break;
    case 2:
        if (a0[0x42] == 2 && a0[0x20] != 4 && a0[0x43] != 3) {
            func_003C3A10(a0, 3, 0, 2);
        }
        if (a0[0x42] == 3 && (a0[0x60] & 2) && a0[0x43] != 0) {
            func_003C3A10(a0, 0, 0, 2);
        }
        if (*(s16 *)(v + 0x234) != 1) {
            func_L01_004561E0(a0);
        }
        break;
    case 3:
        r = func_L01_00454370(a0, v + 0x160);
        if (r & 1) {
            func_L11_003A9CB0(a0);
            func_L01_00315900(a0, 0, 0);
            return;
        }
        if (r & 2) {
            if (*(s16 *)(v + 0x234) == 1) {
hit:
                func_L01_004450F0(a0, 3, 2);
            } else {
                func_L01_004450F0(a0, 2, 1);
                *(s32 *)(v + 0x2D0) = (func_00382498(0x244, 600) * 5 + 2) / 6;
            }
        }
        break;
    }
    switch (a0[0x20]) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        if (func_L01_004561B8(a0) != 0 && a0[0x94] != 4) {
            l = D_L11_0021CB80[*(s32 *)(v + 0x2E4)];
            best = 1e9f;
            for (i = 0; i < l->n - 1; i++) {
                if (func_0038CF00(a0 + 0x10, &l->pts[i]) < best) {
                    *(s32 *)(v + 0x2E8) = i;
                    best = func_0038CF00(a0 + 0x10, &l->pts[i]);
                }
            }
        }
        if (*(s32 *)(v + 0x2E4) != -1) {
            l = D_L11_0021CB80[*(s32 *)(v + 0x2E4)];
            vec_sub_ba(&d, &l->pts[*(s32 *)(v + 0x2E8)], a0 + 0x10);
            f = (f32)*(s32 *)(v + 0x2E4);
            func_0038CF68(&d, &d, f * 0.020000001f);
            if (func_0038CF00(a0 + 0x10, &l->pts[*(s32 *)(v + 0x2E8)]) < 1.0f) {
                *(s32 *)(v + 0x2E8) += 1;
                if (*(s32 *)(v + 0x2E8) >= l->n) {
                    *(s32 *)(v + 0x2E8) = 0;
                }
            }
        }
        if (*(u16 *)(a0 + 0x96) >= 201) {
            func_L01_004450F0(a0, 4, -1);
            if (a0[0x43] != 1) {
                func_003C3A10(a0, 1, 0, 8);
            }
        }
        break;
    case 4:
        if (a0[0x42] == 1 && (a0[0x60] & 2) && a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, 2);
        }
        func_0038D890(a0 + 0xD0, a0 + 0xD0, a0 + 0xE0, 0.041887905f);
        func_0038D890(a0 + 0xC0, a0 + 0xC0, a0 + 0xE0, 0.041887905f);
        if (*(u16 *)(a0 + 0x96) >= 51) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 5:
        break;
    }
    func_L11_003A9D50(a0);
}
/* localdecomp:end func_L11_003A9260 */
