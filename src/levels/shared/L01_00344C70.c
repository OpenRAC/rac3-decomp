#include "common.h"
#include "vu0.h"
#include "structs/weapon.h"

typedef int s128_00341C10 __attribute__((mode(TI)));
typedef struct {
    u8 a;
    u8 b;
    u8 pad[238];
} S_00341C10;
typedef struct {
    u8 pad0[16];
    u8 pos[20];
    s32 active;
    s32 visible;
    s32 target;
} Vars3462F0;
typedef struct {
    char pad0[0x20];
    unsigned char b32;
} Obj;
extern void func_003C2880(Obj *);
typedef struct { u8 pad[0x1A]; s16 x1A; } V_347888;
typedef struct { u8 pad[0x68]; V_347888 *x68; } O_347888;

typedef struct {
    u8 pad0[0x170];
    f32 f170;
    u8 pad1[0x109C];
    s32 f1210;
    u8 pad2[0x13B0];
    s32 f25C4;
    u8 pad3[0x25];
    u8 b25ED;
    u8 pad4[0x2CE];
    s32 f28BC;
} G_00346998;

LINKER_REMNANT("asm/levels", func_L01_00344C70);

/* localdecomp:start func_L01_00344C78 */
extern void func_L01_00344CA8(char *);

/* from rac2-decomp's func_L00_003CA650, renamed */
void func_L01_00344C78(char *object)
{
    if (*(unsigned char *)(object + 0x20) == 1)
        func_L01_00344CA8(object);
}
/* localdecomp:end func_L01_00344C78 */

/* localdecomp:start func_L01_00344CA8 */
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00409B08(u8 *a0, s32 a1, s32 a2);
extern void func_L01_00409E70(u8 *a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

void func_L01_00344CA8(char *obj) {
    vu0_v4 v;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 color;

    *(vu0_q *)&v = 0;
    v.x = -0.3f;
    v.w = 1.0f;
    func_0038D000(&v, &v, obj + 0xC0);
    vec_add_ba(&v, &v, obj + 0x10);
    color = vars[0x81] != 0 ? 0x803010 : 0x103080;
    func_L01_00409B08((u8 *)&v, color, 0);
    func_L01_00409E70((u8 *)&v, vars + 0x10, color, 4, *(f32 *)(vars + 0x64), 0.25f);
}
/* localdecomp:end func_L01_00344CA8 */

/* localdecomp:start func_L01_00344D68 */
extern u8 D_001425C0[];
extern u8 D_L01_001439F4[];
typedef struct {
    u8 p0[0x6F0];
    u8 f6F0;
    u8 p6F1[0x4E7];
    s32 fBD8;
    u8 pBDC[0x634];
    s32 f1210;
    u8 p1214[0x10];
    s32 f1224;
    u8 p1228[0x208];
    s32 f1430;
    u8 p1434[0x27C];
    s32 f16B0;
    u8 p16B4[0xF0C];
    void *f25C0;
    s32 f25C4;
    u8 p25C8[0x1D];
    u8 f25E5;
    u8 p25E6[0x3];
    u8 f25E9;
    u8 p25EA[0x3];
    u8 f25ED;
    u8 p25EE[0x286];
    s16 f2874;
    u8 p2876[0x46];
    s32 f28BC;
} GS_4BE0;
extern GS_4BE0 D_L01_001A4BE0_00344D68;
typedef struct { u8 p0[0x144]; u16 f144; u8 p146[0xF2E]; u16 f1074; } GS_7E18;
extern GS_7E18 D_L01_001A7E18_00344D68;
extern void *D_L01_001D52FC;
extern u8 D_L01_001A30B0[];
extern u8 D_L01_001F1B50[];
extern u8 D_L01_002B28F0[];
extern void func_L01_00346620(s32);
__asm__(".extern D_L01_001DD2A8, 4");
__asm__(".extern D_L01_001DD2AC, 4");
__asm__(".extern D_L01_001DD2B0, 4");
__asm__(".extern D_L01_001DD2B4, 4");
__asm__(".extern D_L01_001DD2B8, 4");
__asm__(".extern D_L01_001DD2BC, 1");
extern s32 D_L01_001D6694;
extern s32 D_L01_001D7B88;
extern f32 D_L01_001DD2A8;
extern f32 D_L01_001DD2AC;
extern f32 D_L01_001DD2B0;
extern f32 D_L01_001DD2B4;
extern f32 D_L01_001DD2B8;
extern u8 D_L01_001DD2BC;
extern f32 D_L01_001DF6E0;
extern u8 D_L01_001DF6E8;
extern f32 D_L01_001DF6F0;
extern u8 D_L01_001DF6F8;
extern u8 D_L01_001DFB40;
typedef struct { u8 p[8]; f32 f8; } TS8_344D68;
typedef struct { f32 f0; } TF_344D68;
typedef struct { u8 p[0x10]; s32 f10; } TI10_344D68;
extern f32 D_L01_001E1A00;
extern f32 D_L01_001E19FC[2];
extern u8 D_L01_001E2A40[];
extern u8 D_L01_001E7630[];
extern struct WeaponRow D_L01_002C5600_00344D68[];
extern void *D_L01_001EAA18[];

extern f32 *func_00382348(void *);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern int func_0038CB00(char *);
extern s32 func_0038CBA0(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0_00344D68(s32, s32, void *);
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_003C4B50(void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
extern void func_L01_00345C08(void *);
extern void func_L01_00348160_00344D68(s32);
extern s32 func_L01_003F2058(void *, void *);
extern void func_L01_003F2278(s32, s32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_00404AD8(void (*)(s32), void *);
extern s32 func_L01_0040E050(void *);
extern s32 func_L01_0041A938();
extern s32 func_L01_0041A990();
extern s32 func_L01_0041BE28(s32, s32);
extern s32 func_L01_00424B88(f32, f32, void *, s32);
extern s32 func_L01_00424D88(s32);
extern s32 func_L01_00444F38(void *, s32, s32, s32, s32);
extern s32 func_L01_004572B0(void *, s32, s32 *);
extern u8 *func_L01_00457410(void *);
extern char *func_L01_00457480(s32, s32);
extern void *func_L01_004574B0(s16, s32);
extern s32 func_L01_004B14C8(s32);
extern s32 func_L01_004BA800();
extern void func_L01_004EA7D8(s32 i);
extern s32 func_L01_005003D0(s32, s32);
extern s32 func_L01_005118D0(s32, s32);
extern s32 func_L01_005119E0(s32);
void func_L01_00344D68(void *arg0) {
    s32 ix;
    u8 *pp;
    vu0_v4 sp0;
    vu0_v4 sp10;
    vu0_v4 sp20;
    s32 sp30;
    u8 *temp_v0_4;
    u8 *var_s0;
    f32 *temp_s1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f3;
    f32 var_f0_2;
    f32 var_f2;
    s32 temp_v0_2;
    s16 temp_v1_3;
    s32 temp_a0_10;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_5;
    s32 temp_a0_9;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_v0_3;
    s32 temp_v0_7;
    s32 temp_v0_9;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_s0_2;
    s32 var_v1;
    u8 temp_a0;
    u8 temp_v1_4;
    void *temp_a0_4;
    void *temp_a0_6;
    void *temp_a0_7;
    void *temp_a0_8;
    void *temp_s0;
    void *temp_s2;
    void *temp_s4;
    void *temp_v0;
    void *temp_v0_8;

    temp_s2 = (*(void **)((u8 *)(arg0) + (0x68)));
    if ((u8) D_L01_002C5600_00344D68[D_001425C0[0x6F]].level >= 2U) {
        D_L01_001E19FC[1] = 0.17453292f;
    } else {
        D_L01_001E19FC[1] = 0.34906584f;
    }
    if (D_L01_001A7E18_00344D68.f144 == 0) {
        if ((D_L01_002C5600_00344D68[D_001425C0[0x6F]].level == 0) && (D_L01_001A4BE0_00344D68.f16B0 == 0)) {
            func_L01_0041BE28(0xB78, 0x1B);
        }
    }
    if (D_L01_001A7E18_00344D68.f1074 == 0) {
        if (D_L01_002C5600_00344D68[D_001425C0[0x6F]].level == 0) {
            if (D_L01_001A4BE0_00344D68.f16B0 > 0) {
                func_L01_0041BE28(0x186F, 0x15F);
            }
        }
    }
    temp_a0 = D_L01_002C5600_00344D68[D_001425C0[0x6F]].level;
    if (temp_a0 == 1) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = (s16) temp_a0;
    } else if (temp_a0 == 2) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = 3;
    } else if (temp_a0 >= 3) {
        (*(s16 *)((u8 *)(arg0) + (0x7C))) = 7;
    }
    if (((*(u8 *)((u8 *)(arg0) + (0x42))) == (*(u8 *)((u8 *)(arg0) + (0x43)))) && ((*(u8 *)((u8 *)(arg0) + (0x60))) & 2)) {
        func_L01_00444F38(arg0, 1, 0, 2, 0);
    }
    if (D_L01_001A4BE0_00344D68.f1224 == 3) {
        if ((*(u8 *)((u8 *)(arg0) + (0x20))) != 0) {
            ((TF_344D68 *)&D_L01_001DF6E8)->f0 = (f32) (*(f32 *)&D_L01_001DD2A8);
            ((TF_344D68 *)&D_L01_001DF6F0)->f0 = (f32) (*(f32 *)&D_L01_001DD2AC);
            ((TF_344D68 *)&D_L01_001DF6F8)->f0 = (f32) (*(f32 *)&D_L01_001DD2B0);
            (((TF_344D68 *)&D_L01_001DF6E0)->f0) = (f32) (*(f32 *)&D_L01_001DD2B4);
            func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
            temp_a0_12 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
            if (temp_a0_12 >= 0) {
                func_L01_00424D88(temp_a0_12);
            }
            (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
            (*(s32 *)&D_L01_001D7B88) = 0xE0;
            func_L01_004B14C8(1);
        }
    } else if ((D_L01_001A4BE0_00344D68.f25C4 == 0x74) || ((*(s32 *)&D_L01_001D6694) != 0) || (func_L01_004BA800() != 0)) {
            if ((*(u8 *)((u8 *)(arg0) + (0x20))) != 4) {
                (*(u8 *)((u8 *)(arg0) + (0x20))) = 4U;
                temp_a0_11 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
                if (temp_a0_11 >= 0) {
                    func_L01_00424D88(temp_a0_11);
                }
                ((TI10_344D68 *)temp_s2)->f10 = -1;
                ((TF_344D68 *)&D_L01_001DF6E8)->f0 = (*(f32 *)&D_L01_001DD2A8);
                ((TF_344D68 *)&D_L01_001DF6F0)->f0 = (f32) (*(f32 *)&D_L01_001DD2AC);
                ((TF_344D68 *)&D_L01_001DF6F8)->f0 = (f32) (*(f32 *)&D_L01_001DD2B0);
                (((TF_344D68 *)&D_L01_001DF6E0)->f0) = (f32) (*(f32 *)&D_L01_001DD2B4);
                func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
                func_L01_004B14C8(1);
            }
    } else {
                if ((*(u8 *)((u8 *)(arg0) + (0x20))) == 4) {
                    (*(u8 *)((u8 *)(arg0) + (0x20))) = 0U;
                }
                sp0 = *(vu0_v4 *)((u8 *)arg0 + 0x10);
                temp_v1 = D_L01_001A4BE0_00344D68.f25C4;
                if (((temp_v1 == 1) || (temp_v1 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                    func_L01_0041A938();
                    (*(u8 *)&D_L01_001DD2BC) = 1U;
                } else if ((*(u8 *)&D_L01_001DD2BC) != 0) {
                    func_L01_0041A990();
                    (*(u8 *)&D_L01_001DD2BC) = 0U;
                }
                temp_v1_2 = D_L01_001A4BE0_00344D68.f25C4;
                if (((temp_v1_2 == 1) || (temp_v1_2 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0) && ((*(u8 *)((u8 *)(arg0) + (0x20))) != 0)) {
                    (*(s8 *)((u8 *)(arg0) + (0x31))) = 0;
                    (*(u16 *)((u8 *)(arg0) + (0x34))) = (u16) ((*(u16 *)((u8 *)(arg0) + (0x34))) | 1);
                    func_L01_00404AD8(func_L01_00346620, arg0);
                    *(s32 *)((u8 *)&D_L01_001DFB40 + 0x1F8) = 1;
                    if ((*(s32 *)&D_L01_001DFB40 & 4) && ((*(void **)((u8 *)(temp_s2) + (0x2C))) = 0, (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 0, func_0038CF68(&sp10, pp = (u8 *)D_L01_001E2A40 + 0x380, 128.0f), vec_add_ab(&sp10, &sp10, D_L01_001E2A40), (func_003D3CB0(D_L01_001E2A40, &sp10, 0x10, (s32)D_L01_001A4BE0_00344D68.f25C0, 0) != 0))) {
                        temp_s0 = D_L01_001EAA18[0];
                        if ((temp_s0 != 0) && ((*(u8 *)((u8 *)(temp_s0) + (0x31))) != 0)) {
                            temp_s1 = func_00382348(temp_s0);
                            if (func_003C4B50(temp_s0) == 0) {
                                if ((temp_s1 != 0) && (*temp_s1 > 0.0f)) {
                                    temp_v0 = (*(void **)((u8 *)(temp_s0) + (0x24)));
                                    if (temp_v0 != 0) {
                                        if ((*(u8 *)((u8 *)(temp_v0) + (0x46))) == 5) {
                                            temp_v1_3 = (*(s16 *)((u8 *)(temp_s0) + (0xAA)));
                                            if (temp_v1_3 != 0x19C0) {
                                                if (temp_v1_3 != 0x1AE6) {
                                                    goto block_62;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else {
block_62:
                                (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 1;
                                (*(void **)((u8 *)(temp_s2) + (0x2C))) = temp_s0;
                            }
                        }
                    }
                    if ((D_L01_001A4BE0_00344D68.f28BC == 0) && ((*(s16 *)((u8 *)(temp_s2) + (0x28))) != 0)) {
                        temp_v0_2 = (*(u16 *)((u8 *)(temp_s2) + (0x2A))) + 1;
                        (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = (u16) temp_v0_2;
                        if ((s16) temp_v0_2 >= 0x1A) {
                            (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = 0U;
                        }
                        if (((*(f32 *)((u8 *)(temp_s2) + (4))) <= 0.0f) && (func_L01_005119E0(-1) != 0) && ((s16) (*(u16 *)((u8 *)(temp_s2) + (0x2A))) >= 0xD)) {
                            func_L01_003F6F20(0, arg0, 0x200000FF, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
                        }
                    }
                } else {
                    *(s32 *)((u8 *)&D_L01_001DFB40 + 0x1F8) = 0;
                }
                temp_v1_4 = (*(u8 *)((u8 *)(arg0) + (0x20)));
                switch (temp_v1_4) {                /* switch 2; irregular */
                case 0:                             /* switch 2 */
                    (*(s16 *)((u8 *)(temp_s2) + (0))) = 0;
                    (*(f32 *)((u8 *)(temp_s2) + (4))) = 0.36666667f;
                    (*(u8 *)((u8 *)(arg0) + (0x20))) = 3U;
                    temp_f0 = 2.0f * func_0038D160(1.0f, *(f32 *)D_L01_001E7630);
                    ((TS8_344D68 *)temp_s2)->f8 = temp_f0;
                    (*(f32 *)&D_L01_001DD2A8) = (f32) ((TF_344D68 *)&D_L01_001DF6E8)->f0;
                    (*(f32 *)&D_L01_001DD2AC) = (f32) ((TF_344D68 *)&D_L01_001DF6F0)->f0;
                    (*(f32 *)&D_L01_001DD2B0) = (f32) ((TF_344D68 *)&D_L01_001DF6F8)->f0;
                    (*(f32 *)&D_L01_001DD2B8) = (f32) (temp_f0 + ((D_L01_001E1A00 - temp_f0) * 0.25f));
                    (*(f32 *)&D_L01_001DD2B4) = (f32) ((TF_344D68 *)&D_L01_001DF6E0)->f0;
                    (*(s32 *)((u8 *)(temp_s2) + (0x14))) = 0;
                    (*(s16 *)((u8 *)(temp_s2) + (0x28))) = 0;
                    (*(u16 *)((u8 *)(temp_s2) + (0x2A))) = 0U;
                    (*(void **)((u8 *)(temp_s2) + (0x2C))) = 0;
                    (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
                    temp_v0_3 = func_L01_004572B0(arg0, 0, &sp30);
                    (*(s32 *)((u8 *)(temp_s2) + (0x18))) = temp_v0_3;
                    if (sp30 == 0) {
                        var_s0 = (u8 *)func_L01_00457480((*(s16 *)((u8 *)(arg0) + (0xAA))), temp_v0_3);
                        (*(u8 **)((u8 *)(temp_s2) + (0x20))) = var_s0;
                        temp_v0_4 = var_s0;
                        temp_s4 = func_L01_004574B0((*(s16 *)((u8 *)(arg0) + (0xAA))), (*(s32 *)((u8 *)(temp_s2) + (0x18))));
                        var_s0 = func_L01_00457410(temp_v0_4 + 0xC);
                        for (var_v1 = 0; var_v1 < 3; var_v1++) {
                            ((u8 **)temp_v0_4)[var_v1] = var_s0;
                            var_s0 += 0xF00;
                        }
                        var_s0 = func_L01_00457410(var_s0);
                        (*(s32 *)((u8 *)(temp_s4) + (0))) = (s32) (var_s0 - temp_v0_4);
                        func_0038CBA0(var_s0, 0x120);
                        var_s0 = func_L01_00457410(var_s0 + 0x120);
                        (*(s32 *)((u8 *)(temp_s4) + (4))) = (s32) (var_s0 - temp_v0_4);
                        func_0038CBA0(var_s0, 0x1E00);
                    }
                    temp_a0_2 = (*(s32 *)((u8 *)(temp_s2) + (0x18)));
                    if (temp_a0_2 >= 0) {
                        func_L01_00348160_00344D68(temp_a0_2);
                    }
                    break;
                case 1:                             /* switch 2 */
                    if (D_L01_001A4BE0_00344D68.f25C4 != 1) {
                        goto block_90;
                    }
                    func_L01_005003D0(0x1D, 1);
                    if (D_L01_001A4BE0_00344D68.f25C4 != 1) {
block_90:
                        if (D_L01_001A4BE0_00344D68.f25C4 == 0x1D) {
                            goto block_92;
                        }
                    } else {
block_92:
                        if (D_L01_001A4BE0_00344D68.f25E5 != 0) {
                            if ((*(s16 *)((u8 *)(temp_s2) + (0))) == 0) {
                                (*(s32 *)&D_L01_001D7B88) = 0;
                            }
                            (*(s16 *)((u8 *)(temp_s2) + (0))) = 1;
                        }
                    }
                    temp_v0_7 = D_L01_001A4BE0_00344D68.f1430;
                    if (temp_v0_7 != 0) {
                        D_L01_001A4BE0_00344D68.fBD8 = temp_v0_7;
                    }
                    temp_v1_5 = D_L01_001A4BE0_00344D68.f25C4;
                    if (((temp_v1_5 == 1) || (temp_v1_5 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                        if (D_L01_001439F4[0] != 0) {
                            temp_v0_8 = D_L01_001D52FC;
                            var_f0_2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x10C)));
                            goto block_104;
                        }
                        temp_v0_8 = D_L01_001D52FC;
                        var_f2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x134)));
                        var_f0_2 = (*(f32 *)((u8 *)(temp_v0_8) + (0x13C)));
                        if (var_f2 < var_f0_2) {
block_104:
                            var_f2 = -var_f0_2;
                        }
                        if (var_f2 > 0.0f) {
                            if ((*(f32 *)&D_L01_001DD2B8) > D_L01_001E19FC[1]) {
                                temp_a0_3 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if ((temp_a0_3 == -1) || (temp_a0_4 = (temp_a0_3 << 7) + D_L01_001A30B0, (*(void **)((u8 *)temp_a0_4 + 0xDC) != arg0)) || ((*(u8 *)((u8 *)(temp_a0_4) + (0xD0))) == 0)) {
                                    (*(s32 *)((u8 *)(temp_s2) + (0x30))) = func_003A52A0_00344D68(2, 4, arg0);
                                }
                                (*(f32 *)&D_L01_001DD2B8) = (f32) ((*(f32 *)&D_L01_001DD2B8) - 0.01f);
                            } else {
                                goto block_113;
                            }
                        } else {
block_113:
                            if ((var_f2 < 0.0f) && ((*(f32 *)&D_L01_001DD2B8) < (*(f32 *)((u8 *)(temp_s2) + (8))))) {
                                temp_a0_5 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if ((temp_a0_5 == -1) || (temp_a0_6 = (temp_a0_5 << 7) + D_L01_001A30B0, (*(void **)((u8 *)temp_a0_6 + 0xDC) != arg0)) || ((*(u8 *)((u8 *)(temp_a0_6) + (0xD0))) == 0)) {
                                    (*(s32 *)((u8 *)(temp_s2) + (0x30))) = func_003A52A0_00344D68(3, 4, arg0);
                                }
                                (*(f32 *)&D_L01_001DD2B8) = (f32) ((*(f32 *)&D_L01_001DD2B8) + 0.01f);
                            } else {
                                temp_a1 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                                if (temp_a1 != -1) {
                                    temp_a0_7 = (temp_a1 << 7) + D_L01_001A30B0;
                                    if (((*(void **)((u8 *)temp_a0_7 + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_a0_7) + (0xD0))) != 0)) {
                                        func_003A4F28(temp_a1);
                                    }
                                }
                                (*(s32 *)((u8 *)(temp_s2) + (0x30))) = -1;
                            }
                        }
                        temp_f1 = (*(f32 *)&D_L01_001DD2B8);
                        if ((*(f32 *)((u8 *)(temp_s2) + (8))) < temp_f1) {
                            (*(f32 *)&D_L01_001DD2B8) = (*(f32 *)((u8 *)(temp_s2) + (8)));
                        } else if (temp_f1 < D_L01_001E19FC[1]) {
                            (*(f32 *)&D_L01_001DD2B8) = D_L01_001E19FC[1];
                        }
                        func_00382810(0, 0, 3, (*(f32 *)&D_L01_001DD2B8), 0.02f, 0.2f, 0.0f);
                        func_L01_004B14C8(0);
                    } else {
                        if ((*(s16 *)((u8 *)(temp_s2) + (0))) != 0) {
                            temp_f1_2 = (*(f32 *)((u8 *)(temp_s2) + (8)));
                            (*(f32 *)&D_L01_001DD2B8) = (f32) (temp_f1_2 + ((D_L01_001E19FC[1] - temp_f1_2) * 0.25f));
                            func_00382810(0, 0, 3, temp_f1_2, 0.005f, 0.2f, 0.0f);
                            (*(s16 *)((u8 *)(temp_s2) + (0))) = 0;
                            *(s32 *)&D_L01_001D7B88 = 0xE0;
                            func_L01_004B14C8(1);
                        }
                        temp_a1_2 = (*(s32 *)((u8 *)(temp_s2) + (0x30)));
                        if (temp_a1_2 != -1) {
                            temp_a0_8 = (temp_a1_2 << 7) + D_L01_001A30B0;
                            if (((*(void **)((u8 *)temp_a0_8 + 0xDC)) == arg0) && ((*(u8 *)((u8 *)(temp_a0_8) + (0xD0))) != 0)) {
                                func_003A4F28(temp_a1_2);
                            }
                        }
                        (*(s32 *)((u8 *)(temp_s2) + (0x30))) = -1;
                    }
                    temp_f1_3 = D_L01_001E19FC[1];
                    var_s0_2 = 1;
                    temp_f3 = ((*(f32 *)&D_L01_001DD2B8) - temp_f1_3) / ((*(f32 *)((u8 *)(temp_s2) + (8))) - temp_f1_3);
                    temp_v1_6 = D_L01_001A4BE0_00344D68.f25C4;
                    ((TF_344D68 *)&D_L01_001DF6E8)->f0 = (f32) ((((*(f32 *)&D_L01_001DD2A8) - 0.03f) * temp_f3) + 0.03f);
                    (((TF_344D68 *)&D_L01_001DF6F0)->f0) = (f32) ((((*(f32 *)&D_L01_001DD2AC) - 0.4f) * temp_f3) + 0.4f);
                    ((TF_344D68 *)&D_L01_001DF6E0)->f0 = (f32) ((((*(f32 *)&D_L01_001DD2B4) - 0.010471975f) * temp_f3) + 0.010471975f);
                    if (((temp_v1_6 == 1) || (temp_v1_6 == 0x1D)) && (D_L01_001A4BE0_00344D68.f25E5 != 0)) {
                        if (func_0038CAD0((void *)&D_L01_001A4BE0_00344D68.f28BC) == 0) {
                            var_s0_2 = 0;
                        }
                    } else {
                        D_L01_001A4BE0_00344D68.f28BC = 0x21;
                    }
                    if ((D_L01_001A4BE0_00344D68.f25ED == 0) && ((*(s32 *)((u8 *)(D_L01_001D52FC) + (0x1A4))) & D_L01_001A4BE0_00344D68.f1210) && (var_s0_2 != 0)) {
                        if (func_L01_005118D0(-1, 1) != 0) {
                            func_L01_004EA7D8(-1);
                            (*(s32 *)((u8 *)(temp_s2) + (0x1C))) = func_L01_003F2058(D_L01_002B28F0, 0);
                            (*(s16 *)((u8 *)(temp_s2) + (2))) = 2;
                            (*(u8 *)((u8 *)(arg0) + (0x20))) = 2U;
                            func_003C3A10(arg0, 2, 0, 0);
                        } else {
                            func_003A52A0_00344D68(1, 0, arg0);
                        }
                        if (!((*(s32 *)((u8 *)(D_L01_001D52FC) + (0x1A0))) & D_L01_001A4BE0_00344D68.f1210) || (func_L01_005119E0(-1) == 0) || (D_L01_001A4BE0_00344D68.f25E9 == 0)) {
                            temp_a0_9 = (*(s32 *)((u8 *)(temp_s2) + (0x1C)));
                            if (temp_a0_9 >= 0) {
                                func_L01_003F2278(temp_a0_9, 0);
                                (*(s32 *)((u8 *)(temp_s2) + (0x1C))) = -1;
                            }
                        }
                    }
                    break;
                case 2:                             /* switch 2 */
                    temp_v0_9 = D_L01_001A4BE0_00344D68.f1430;
                    if (temp_v0_9 != 0) {
                        D_L01_001A4BE0_00344D68.fBD8 = temp_v0_9;
                    }
                    if ((func_0038CB00(temp_s2 + 2) != 0) || ((*(s16 *)((u8 *)(temp_s2) + (0))) != 0)) {
                        func_003A52A0_00344D68(0, 0, arg0);
                        func_L01_00345C08(arg0);
                        *(f32 *)((u8 *)temp_s2 + 4) = 1.0f / ((struct WeaponRow *)((u8 *)D_L01_002C5600_00344D68 + D_001425C0[0x6F] * 0xF0))->shots_per_second;
                        (*(u8 *)((u8 *)(arg0) + (0x20))) = 3U;
                    }
                    break;
                case 3:                             /* switch 2 */
                    if (func_L01_0040E050(temp_s2 + 4) != 0) {
                        (*(u8 *)((u8 *)(arg0) + (0x20))) = 1U;
                    }
                    break;
                }
                if ((*(s32 *)((u8 *)(temp_s2) + (0x14))) != 0) {
                    if (func_0038CAD0(temp_s2 + 0x14) != 0) {
                        temp_a0_10 = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
                        if (temp_a0_10 >= 0) {
                            func_L01_00424D88(temp_a0_10);
                        }
                        (*(s32 *)((u8 *)(temp_s2) + (0x10))) = -1;
                    } else {
                        if ((*(s32 *)((u8 *)(temp_s2) + (0x10))) == -1) {
                            (*(s32 *)((u8 *)(temp_s2) + (0x10))) = func_L01_00424B88(10.0f, 0.0f, arg0 + 0x10, 0xFF0000FF);
                        }
                        if ((*(s32 *)((u8 *)(temp_s2) + (0x10))) >= 0) {
                            if (D_L01_001A4BE0_00344D68.f2874 == 1) {
                                func_003C2F58((s32)arg0, 1, &sp10);
                                func_0038CF68(&sp20, arg0 + 0xD0, -1.5f);
                            } else {
                                func_003C2F58((s32)arg0, 1, &sp10);
                                func_0038CF68(&sp20, (void *)&D_L01_001A4BE0_00344D68.f6F0, 1.5f);
                            }
                            vec_add_ab(D_L01_001F1B50 + ((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5), &sp10, &sp20);
                            {
                                u8 *eb = D_L01_001F1B50 - 0x10;
                                *(f32 *)(eb + ((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5) + 0x1C) = 10.0f;
                                temp_f0_2 = (f32) (*(s32 *)((u8 *)(temp_s2) + (0x14))) / 25.0f;
                                *(f32 *)(eb + ((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5)) = temp_f0_2;
                                *(f32 *)(eb + ((*(s32 *)((u8 *)(temp_s2) + (0x10))) << 5) + 4) = temp_f0_2 * 0.7f;
                                ix = (*(s32 *)((u8 *)(temp_s2) + (0x10)));
                                *(s32 *)(eb + (ix << 5) + 8) = 0;
                            }
                        }
                    }
                }
    }
}
/* localdecomp:end func_L01_00344D68 */

/* localdecomp:start func_L01_00345C08 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00345C08;
extern u8 D_001425C0[];
extern u8 D_001A4BE0[];
#define G_345C08 (*(GS_4BE0 *)&D_001A4BE0)
#define ROW_345C08 (*(struct WeaponRow *)((u8 *)D_L01_002C5600_00344D68 + D_001425C0[0x6F] * 0xF0))
extern u8 D_L01_001E2DC0[];
extern u8 D_L01_001E2A40[];
extern u8 D_001A57B8[];
extern u8 D_L01_001D66B0[] __attribute__((section(".sdata")));

extern s32 D_L01_001DAFEC;
void func_L01_00345C08(void *arg) {
    u8 *self = arg;
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern s32 func_L01_00424B88(f32, f32, void *, s32);
    extern void func_L01_004CAC78(void *, void *, f32, f32, f32);
    extern void func_L01_00457588(u8 *, void *, void *, f32);
    extern void func_L01_00446780(u8 *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_00346CC8(u8 *, u8 *, s32, s32);
    extern void func_L01_0037D920(u8 *, void *, void *, void *, s32, s32, s32, f32);
    extern void func_00382580(void *, f32, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
    extern u8 *func_L01_0046B458(void *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind, s32 spin, void *velocity, f32 unk, s32 delay);
    extern u8 *func_L01_00470C78(u8 *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
    Vec_00345C08 q10, q20, q30, q40, q50;
    u8 *v = *(u8 **)(self + 0x68);
    u8 *fp, *t, *r;
    f32 f20, f;
    s32 mode, w, tier;
    s32 c16, c17;

    f20 = ROW_345C08.shot_speed * 0.020000001415610313f;
    if (G_345C08.f2874 == 1) {
        func_003C2F58((s32)self, 1, &q10);
        func_0038CF68(&q20, self + 0xD0, -f20);
    } else if (G_345C08.f16B0 != 0) {
        func_003C2F58((s32)self, 1, &q10);
        func_0038CF68(&q20, D_L01_001E2DC0, f20);
    } else {
        func_003C2F58((s32)self, 1, &q10);
        func_0038CF68(&q20, &G_345C08.f6F0, f20);
    }
    fp = (u8 *)&q20;
    mode = 0;
    *(s32 *)(v + 0x10) = func_L01_00424B88(10.0f, 0.0f, &q10, 0xFF0000FF);
    *(s32 *)(v + 0x14) = 0x19;
    w = G_345C08.f25C4;
    if (w == 1 || w == 0x1D) {
        if (G_345C08.f25E5 != 0) {
            mode = 2;
            func_L01_004CAC78(fp, &q10, f20, 128.0f, 0.3490658402442932f);
            goto have_flag;
        }
    }
    if (G_345C08.fBD8 != 0) func_L01_00457588((u8 *)G_345C08.fBD8, &q10, fp, f20);
have_flag:
    if (D_L01_001DAFEC != 0) {
        t = *(u8 **)(v + 0x2C);
        if ((t != 0 && G_345C08.f16B0 != 0) ||
            (G_345C08.fBD8 != 0 && G_345C08.f16B0 == 0)) {
            if (t != 0) q30 = *(Vec_00345C08 *)(t + 0x10);
            else q30 = *(Vec_00345C08 *)D_001A57B8;
            vec_sub_ab(&q40, &q30, &q10);
            func_0038CF68(&q50, fp, 1.0f);
            f = func_0038CE68(&q50, &q40);
            func_0038CE20(fp, &q50, f + 3.0f);
            mode = 2;
        }
    }
    func_0038CE20(&q30, self + 0xD0, -1.5f);
    vec_add_ab(&q30, &q30, self + 0x10);
    func_0038CE20(&q40, self + 0xC0, 0.2750000059604645f);
    vec_add_ab(&q30, &q30, &q40);
    func_L01_00446780(self, &q10, 0x10000, 0, 1, 0, 1.5f, ROW_345C08.damage, 1.0f);
    r = func_L01_00346CC8((u8 *)&q10, fp, *(s32 *)(v + 0x18), mode);
    if (r != 0) *(u8 **)(r + 0xB8) = self;

    w = G_345C08.f25C4;
    if ((w != 1 && w != 0x1D) || G_345C08.f25E5 == 0) {
        c16 = 0xBF204080;
        c17 = 0xBF2040A0;
        tier = ROW_345C08.level;
        if (tier == 0) {
            {
            s32 cnt;
            for (cnt = 0; cnt < 10; cnt++) {
                    func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                    func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0x80408020, 0xFF00, 0, 0);
            }
            }
            c16 = 0xBF408020;
            c17 = 0xBF406020;
        }
        if (ROW_345C08.level == 1) {
            {
            s32 cnt;
            for (cnt = 0; cnt < 10; cnt++) {
                    func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                    func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0x80804020, 0xFF0000, 0, 0);
            }
            }
            c16 = 0xBF804020;
            c17 = 0xBF604020;
        }
        if (ROW_345C08.level == 2) {
            c16 = 0xBF804020;
            c17 = 0xBF204080;
            {
            s32 cnt;
            for (cnt = 0; cnt < 10; cnt++) {
                    func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                    func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1432A0, 0xFF, 0, 0);
            }
            }
        }
        if (ROW_345C08.level == 3) {
            c16 = 0xBF204080;
            c17 = 0xBF2040A0;
            {
            s32 cnt;
            for (cnt = 0; cnt < 12; cnt++) {
                    func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                    func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1414A0, 0xFF, 0, 0);
            }
            }
        }
        if (ROW_345C08.level >= 4) {
            c16 = 0xBF804020;
            c17 = 0xBF604020;
            {
            s32 cnt;
            for (cnt = 0; cnt < 14; cnt++) {
                    func_00382580(&q50, 0.10000000894069672f, 0.20000001788139343f);
                    func_L01_00474078(&q10, &q50, (func_00382498(10, 25) * 5 + 2) / 6, 0.07500000298023224f, 0.25f, 0.5f, 0.5f, 0xBF1414A0, 0xFF, 0, 0);
            }
            }
        }
        func_L01_0046B458(&q10, 0xE, 5.25f, 0.10000000149011612f, c16, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(&q10, 0xE, 3.75f, 0.10000000149011612f, c17, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(&q10, 0xE, 2.625f, 0.10000000149011612f, 0xC0FFFFFF, 2, 1, D_L01_001D66B0, 0.0f, 1);
        func_L01_0046B458(&q10, 0xE, 1.875f, 0.10000000149011612f, 0xB0FFFFFF, 2, -1, D_L01_001D66B0, 0.0f, 1);
        func_L01_00470C78((u8 *)&q10, 0x11, 1.0800000429153442f, 0.8400000333786011f, 0x46787878, 2, 2, D_L01_001D66B0, 0, 2, 6, 1);
        func_L01_00470C78((u8 *)&q10, 0x11, 2.0400002002716064f, 0.8400000333786011f, 0x46787878, 2, -1, D_L01_001D66B0, 1, 2, 6, 1);
        func_L01_00470C78((u8 *)&q10, 0x11, 2.4000000953674316f, 1.8000000715255737f, 0x2D787878, 2, 1, D_L01_001D66B0, 1, 2, 6, 1);
    } else {
            if (G_345C08.f16B0 != 0 || w == 0x1D) {
                struct WeaponRow *row = &ROW_345C08;
                func_L01_0037D920(self, D_L01_001E2A40, fp, D_L01_001E2A40 + 0x380,
                                  (row->level >= 3) ? 0x110000 : 0x10000, 0, 1, row->damage);
            }
    }
}
/* localdecomp:end func_L01_00345C08 */

/* localdecomp:start func_L01_00346620 */
extern void func_003C2F58(s32 a, s32 b, void *c);
extern void func_L01_00346668(f32 *, f32, f32, f32, f32);

void func_L01_00346620(s32 a) {
    f32 v[4];
    ((void (*)(s32, s32, f32 *))func_003C2F58)(a, 1, v);
    func_L01_00346668(v, 1.0f, 0.0f, 0.0f, 0.9f);
}
/* localdecomp:end func_L01_00346620 */

/* localdecomp:start func_L01_00346668 */
__asm__(".extern D_L01_001DD2C0, 4");
__asm__(".extern D_L01_001DD2C4, 4");
__asm__(".extern D_L01_001DD2C8, 4");
__asm__(".extern D_L01_001DD2CC, 4");
__asm__(".extern D_L01_001DD2D0, 4");
__asm__(".extern D_L01_001DD2D4, 4");
__asm__(".extern D_L01_001DD2D8, 4");
__asm__(".extern D_L01_001DD2DC, 4");
__asm__(".extern D_L01_001DD2E0, 4");
__asm__(".extern D_L01_001DD2E4, 4");
__asm__(".extern D_L01_001DD2E8, 4");
__asm__(".extern D_L01_001DD2EC, 4");
__asm__(".extern D_L01_001DD2F0, 4");
__asm__(".extern D_L01_001DD2F4, 4");
__asm__(".extern D_L01_001DD2F8, 4");
__asm__(".extern D_L01_001DD2FC, 4");
__asm__(".extern D_L01_001DD300, 4");
__asm__(".extern D_L01_001DD304, 4");
extern s32 D_L01_001DD2C0;
extern s32 D_L01_001DD2C4;
extern s32 D_L01_001DD2C8;
extern s32 D_L01_001DD2CC;
extern s32 D_L01_001DD2D0;
extern s32 D_L01_001DD2D4;
extern s32 D_L01_001DD2D8;
extern s32 D_L01_001DD2DC;
extern s32 D_L01_001DD2E0;
extern s32 D_L01_001DD2E4;
extern s32 D_L01_001DD2E8;
extern s32 D_L01_001DD2EC;
extern s32 D_L01_001DD2F0;
extern s32 D_L01_001DD2F4;
extern s32 D_L01_001DD2F8;
extern s32 D_L01_001DD2FC;
extern s32 D_L01_001DD300;
extern s32 D_L01_001DD304;
extern s32 D_L39_00240300;
extern s32 D_L39_00240304;
extern s32 D_L39_002413A0;
extern void func_L01_004C5E28(void);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, long c, long d);

/* flux_scope_draw: the Flux Rifle's scope over the screen: texture 0x46 as four mirrored
   quarter-screen quads into the frame's alpha, the shading quarter in its texture, then the
   frame drawn over the whole screen where that alpha allows (the lens). */
void func_L01_00346668(f32 *v, f32 x, f32 y, f32 z, f32 w)
{
    s32 width;
    s32 height;
    long tex;

    func_L01_004C5E28();
    height = D_L39_00240304;
    width = D_L39_00240300;
    /* drawn into a frame of its own: its size */
    if (D_L39_002413A0 != 0) {
        D_L01_001DD304 = -1;
        D_L01_001DD2F4 = 0xEC;
        D_L01_001DD2F8 = 0xF0;
        width = D_L01_001DD2FC;
        height = D_L01_001DD300;
    }
    func_003A9440(0x47, 0x513F1);
    /* the scope's top-left quarter, mirrored into each quarter */
    func_0038B4D0(0, 0, (s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(width, 0, -(s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(0, height, (s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0x7F, 0x7F, 0x50101010,
                  func_00389598(0x46));
    func_0038B4D0(width, height, -(s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0x7F, 0x7F,
                  0x50101010, func_00389598(0x46));
    /* the shading quarter, the same way */
    func_003A9440(0x42, (long)D_L01_001DD2CC | ((long)D_L01_001DD2D0 << 2) | ((long)D_L01_001DD2D4 << 4)
                  | ((long)D_L01_001DD2D8 << 6) | (0x80L << 32));
    tex = func_00389598(D_L01_001DD2C0);
    func_0038B4D0(0, 0, (s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0xFF, 0xFF, D_L01_001DD2C4,
                  tex);
    func_0038B4D0(width, 0, -(s32)(width * 0.5f), (s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    func_0038B4D0(0, height, (s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    func_0038B4D0(width, height, -(s32)(width * 0.5f), -(s32)(height * 0.5f), 0, 0, 0xFF, 0xFF,
                  D_L01_001DD2C4, tex);
    /* the frame over the whole screen where the alpha allows: the lens */
    func_003A9440(0x42, (long)D_L01_001DD2DC | ((long)D_L01_001DD2E0 << 2) | ((long)D_L01_001DD2E4 << 4)
                  | ((long)D_L01_001DD2E8 << 6) | (0x80L << 32));
    func_0038B4D0(0, 0, width, height, D_L01_001DD2EC, D_L01_001DD2F0, D_L01_001DD2F4, D_L01_001DD2F8,
                  D_L01_001DD2C8, func_00389598(D_L01_001DD304));
}
/* localdecomp:end func_L01_00346668 */

/* localdecomp:start func_L01_00346998 */
extern void func_003C2F58(s32 a, s32 b, void *c);
extern s32 func_L01_004C7A18(f32 h, void *a, void *b, void *c, void *d, void *e, s32 f, s32 g);
extern u8 D_001A4BE0[];
extern u8 *D_001D52FC;
extern void func_L01_004C7438(void *a, void *b, s32 i, s32 j, f32 f0, f32 f1, f32 f2, f32 f3);
extern s32 func_0038CAD0(void *p);
extern s32 func_L01_005118D0(s32 i, s32 n);
extern s32 func_L01_005119E0(s32 i);
extern void func_L01_004EA7D8(s32 i);
extern void func_L01_004EAA80(void);
extern void func_003A52A0(s32, s32, void *);
extern u8 *func_L01_0032C7A0(void *a, void *b);
extern void func_L01_00346C18(u8 *self);
extern void func_L01_00404A10_00346998(void *, u8 *);

void func_L01_00346998(u8 *self) {
    u8 a[16];
    u8 b[16];
    u8 *st = *(u8 **)(self + 0x68);
    s32 ready;
    u8 *shot;

    func_003C2F58((s32)self, 0, a);
    func_L01_004C7438(b, a, 0, 0, 1.5f, 11.0f, 0.3f, 0.0044f);
    *(s32 *)(st + 0x24) = func_L01_004C7A18(0.0044f, a, b, st, st + 0x10, self, 0, (s32)(st + 0x2C));
    ready = 1;
    if ((*(G_00346998 *)&D_001A4BE0).f25C4 == 29) {
        if (!func_0038CAD0(&(*(G_00346998 *)&D_001A4BE0).f28BC)) ready = 0;
    } else {
        (*(G_00346998 *)&D_001A4BE0).f28BC = 33;
    }
    switch (self[0x20]) {
    case 0:
        self[0x20] = 1;
        *(s32 *)(st + 0x28) = 1;
        *(s32 *)(st + 0x24) = 0;
    case 1:
        if ((*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210) &&
            !(*(G_00346998 *)&D_001A4BE0).b25ED && ready && *(s32 *)(st + 0x28) != 0) {
            if (func_L01_005118D0(-1, 1)) {
                func_L01_004EA7D8(-1);
                self[0x20] = 2;
                *(s32 *)(st + 0x20) = 17;
            } else {
                func_003A52A0(2, 0, self);
            }
        } else if (!func_L01_005119E0(-1) &&
                   (*(s32 *)(D_001D52FC + 0x1A4) & (*(G_00346998 *)&D_001A4BE0).f1210)) {
            func_003A52A0(2, 0, self);
        }
        break;
    case 2:
        if (func_0038CAD0(st + 0x20) || (*(G_00346998 *)&D_001A4BE0).f170 > 0.0f) {
            func_003A52A0(0, 0, self);
            shot = func_L01_0032C7A0(a, b);
            *(u8 **)(shot + 0xB8) = self;
            func_L01_004EAA80();
            self[0x20] = 3;
            *(s32 *)(st + 0x20) = 8;
        }
        break;
    case 3:
        if (func_0038CAD0(st + 0x20)) self[0x20] = 1;
        break;
    }
    func_L01_00404A10_00346998(func_L01_00346C18, self);
}
/* localdecomp:end func_L01_00346998 */

/* localdecomp:start func_L01_00346C18 */
extern void func_L01_004C70A8(u8 *, u8 *, s32, s32, float);

extern s32 func_L01_004CB018(s32);
extern s32 func_L01_004CB2D8(void);
extern s32 D_L01_00277080[];

void func_L01_00346C18(u8 *self) {
    Vars3462F0 *v = *(Vars3462F0 **)(self + 104);

    if (v->target != 0) {
        if ((u32)(func_L01_004CB018(v->target) - 1) < 2) {
            v->visible = 0;
        } else if (v->active == 0 || (D_L01_00277080[0] >= 9 && func_L01_004CB2D8() == 0)) {
            v->visible = 0;
        } else {
            v->visible = 1;
        }
    }
    if (v->active != 0 && v->visible != 0) {
        ((void (*)(void *, void *, s32, s32, f32))func_L01_004C70A8)(v, v->pos, 0, 1, 1.0f);
    }
}
/* localdecomp:end func_L01_00346C18 */

/* localdecomp:start func_L01_00346CC8 */
__asm__(".extern D_L01_001DD310, 4");
__asm__(".extern D_L01_001DD314, 4");
__asm__(".extern D_L01_001DD318, 4");
__asm__(".extern D_L01_001DD320, 4");
__asm__(".extern D_L01_001DD3A8, 4");
__asm__(".extern D_L01_001DD3AC, 4");
__asm__(".extern D_L01_001DD3B0, 4");
__asm__(".extern D_L01_001DD3B4, 4");
__asm__(".extern D_L01_001DD308, 4");
__asm__(".extern D_L01_001DD30C, 4");
__asm__(".extern D_L01_001DD32C, 4");
__asm__(".extern D_L01_001DD330, 4");
__asm__(".extern D_L01_001DD334, 4");
__asm__(".extern D_L01_001DD338, 4");
__asm__(".extern D_L01_001DD360, 4");
__asm__(".extern D_L01_001DD364, 4");
__asm__(".extern D_L01_001DD368, 4");
__asm__(".extern D_L01_001DD378, 4");
__asm__(".extern D_L01_001DD37C, 4");
__asm__(".extern D_L01_001DD388, 4");
__asm__(".extern D_L01_001DD38C, 4");
__asm__(".extern D_L01_001DD3BC, 4");
__asm__(".extern D_L01_001DD3C0, 4");
extern f32 D_L01_001DD310;
extern f32 D_L01_001DD314;
extern f32 D_L01_001DD318;
extern f32 D_L01_001DD320;
extern f32 D_L01_001DD3A8;
extern f32 D_L01_001DD3AC;
extern f32 D_L01_001DD3B0;
extern f32 D_L01_001DD3B4;
extern s32 D_L01_001DD308;
extern s32 D_L01_001DD30C;
extern s32 D_L01_001DD32C;
extern s32 D_L01_001DD330;
extern s32 D_L01_001DD334;
extern s32 D_L01_001DD338;
extern s32 D_L01_001DD360;
extern s32 D_L01_001DD364;
extern s32 D_L01_001DD368;
extern s32 D_L01_001DD378;
extern s32 D_L01_001DD37C;
extern s32 D_L01_001DD388;
extern s32 D_L01_001DD38C;
extern s32 D_L01_001DD3BC;
extern s32 D_L01_001DD3C0;
extern u8 D_001425C0[];
extern s32 D_L01_001E1A04;
extern u8 D_L01_001E29C0[];
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00346CC8;

/* Spawns a shot of the current weapon level (tier tables set per level) at a0 heading a1. */
u8 *func_L01_00346CC8(u8 *a0, u8 *a1, s32 a2, s32 a3) {
    extern s32 func_L01_00457458(s32, s32);
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_004CABD8(void *, void *, void *);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00347640(u8 *, void *);
    extern void func_L01_00348A98(u8 *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern s32 func_L01_003476D8(u8 *, void *);
    Vec_00346CC8 tmp, tmp2;
    Vec_00346CC8 *pos;
    u8 *o, *v;
    struct WeaponRow *row;
    s32 c, life, n;
    f32 f;

    if (a2 == -1) return 0;
    if (func_L01_00457458(0xC04, a2) == 0) return 0;
    o = func_003C24B0(0xCF7, 0x80);
    if (o != 0) {
        v = *(u8 **)(o + 0x68);
        c = D_L01_002C5600_00344D68[D_001425C0[0x6F]].level;
        if (c == 0) {
            D_L01_001DD310 = 0.10000000149011612f;
            D_L01_001DD314 = 1.0f;
            D_L01_001DD318 = 1.0f;
            D_L01_001DD320 = 0.30000001192092896f;
            D_L01_001DD32C = 0x408000;
            D_L01_001DD330 = 0x10FF10;
            D_L01_001DD334 = 0xFF00FF00;
            D_L01_001DD338 = 0x80408000;
            D_L01_001DD360 = 0x404010;
            D_L01_001DD364 = 0x7FFF00;
            D_L01_001DD368 = 0x40;
            D_L01_001DD378 = 0x7FFF00;
            D_L01_001DD37C = 0xFF7F00;
            D_L01_001DD388 = 0x20FFFF;
            D_L01_001DD38C = 0xFF00;
        } else if (c == 1) {
            D_L01_001DD310 = 0.15000000596046448f;
            D_L01_001DD314 = 3.0f;
            D_L01_001DD318 = 3.0f;
            D_L01_001DD320 = 0.44999998807907104f;
            D_L01_001DD32C = 0x804000;
            D_L01_001DD330 = 0xFF1010;
            D_L01_001DD334 = -0x100;
            D_L01_001DD338 = 0x80404000;
            D_L01_001DD360 = 0x804020;
            D_L01_001DD364 = 0x804020;
            D_L01_001DD368 = 0x40;
            D_L01_001DD378 = 0x804020;
            D_L01_001DD37C = 0x804020;
            D_L01_001DD388 = 0x7F7F7F;
            D_L01_001DD38C = 0x804020;
        } else if (c == 2) {
            D_L01_001DD310 = 0.20000000298023224f;
            D_L01_001DD314 = 4.0f;
            D_L01_001DD318 = 4.0f;
            D_L01_001DD320 = 0.44999998807907104f;
            D_L01_001DD32C = 0xFF8040;
            D_L01_001DD330 = 0xFF8040;
            D_L01_001DD334 = -0x100;
            D_L01_001DD338 = 0x80404000;
            D_L01_001DD360 = 0xFF2080;
            D_L01_001DD364 = 0xFF2080;
            D_L01_001DD368 = 0x40;
            D_L01_001DD378 = 0xFF2040;
            D_L01_001DD37C = 0xFF2040;
            D_L01_001DD388 = 0xFF2040;
            D_L01_001DD38C = 0xFF7F00;
            D_L01_001DD3BC = 0xFF8040;
            D_L01_001DD3C0 = 0xFF4020;
            D_L01_001E1A04 = 0x36;
            D_L01_001DD3A8 = 0.30000001192092896f;
            D_L01_001DD3AC = 0.5f;
            D_L01_001DD3B0 = 0.75f;
            D_L01_001DD3B4 = 1.25f;
        } else if (c == 3) {
            D_L01_001DD310 = 0.20000000298023224f;
            D_L01_001DD314 = 5.0f;
            D_L01_001DD318 = 5.0f;
            D_L01_001DD320 = 0.44999998807907104f;
            D_L01_001DD32C = 0x4080;
            D_L01_001DD330 = 0x1010FF;
            D_L01_001DD334 = 0xFF00FFFF;
            D_L01_001DD338 = 0x80004040;
            D_L01_001DD360 = 0x104040;
            D_L01_001DD364 = 0xFF;
            D_L01_001DD368 = 0x40;
            D_L01_001DD378 = 0x4040;
            D_L01_001DD37C = 0xFF;
            D_L01_001DD388 = 0xFFFF;
            D_L01_001DD38C = 0xFF;
            D_L01_001DD3BC = 0x307F7F;
            D_L01_001DD3C0 = 0x30307F;
            D_L01_001E1A04 = 0x36;
            D_L01_001DD3A8 = 0.30000001192092896f;
            D_L01_001DD3AC = 0.5f;
            D_L01_001DD3B0 = 0.75f;
            D_L01_001DD3B4 = 1.25f;
        } else if (c >= 4) {
            D_L01_001DD310 = 0.20000000298023224f;
            D_L01_001DD314 = 5.0f;
            D_L01_001DD318 = 5.0f;
            D_L01_001DD320 = 0.44999998807907104f;
            D_L01_001DD32C = 0x4080;
            D_L01_001DD330 = 0x1010FF;
            D_L01_001DD334 = 0xFF00FFFF;
            D_L01_001DD338 = 0x80004040;
            D_L01_001DD360 = 0x104040;
            D_L01_001DD364 = 0xFF;
            D_L01_001DD368 = 0x40;
            D_L01_001DD378 = 0x4040;
            D_L01_001DD37C = 0xFF;
            D_L01_001DD388 = 0xFFFF;
            D_L01_001DD38C = 0xFF;
            D_L01_001DD3BC = 0x307F7F;
            D_L01_001DD3C0 = 0x30307F;
            D_L01_001E1A04 = 9;
            D_L01_001DD3A8 = 0.30000001192092896f;
            D_L01_001DD3AC = 0.5f;
            D_L01_001DD3B0 = 0.75f;
            D_L01_001DD3B4 = 1.25f;
        }
        *(s16 *)(o + 0x32) = o[0x30] = 0xFF;
        o[0x31] = 1;
        pos = (Vec_00346CC8 *)(o + 0x10);
        *pos = *(Vec_00346CC8 *)a0;
        o[0x20] = 0;
        func_L01_004CABD8(v, a1, a0);
        row = &D_L01_002C5600_00344D68[D_001425C0[0x6F]];
        f = row->shot_speed * 0.020000001415610313f;
        *(s16 *)(v + 0x1A) = a2;
        n = (s32)(128.0f / f);
        life = (n * 5 + 2) / 6;
        *(s32 *)(v + 0x10) = life;
        *(f32 *)(v + 0x14) = 1.0f / (f32)life;
        {
            char *p = func_L01_00457480(0xC04, a2);
            *(s16 *)(v + 0x22) = (D_L01_001DD30C * 5 + 2) / 6;
            *(char **)(v + 0x1C) = p;
        }
        *(s16 *)(v + 0x20) = 0;
        *(s32 *)(v + 0x28) = a3;
        *(f32 *)(v + 0x24) = 1.0f / (f32)*(s16 *)(v + 0x22);
        func_003C5180(pos, &tmp, 1);
        func_0038CE20(&tmp, &tmp, -1.0f);
        func_L01_00347640(o, &tmp);
        if ((u32)D_L01_001DD308 >= 4) D_L01_001DD308 = 0;
        {
            s32 next = (D_L01_001DD308 + 1) % 3;
            *(s16 *)(v + 0x18) = D_L01_001DD308;
            D_L01_001DD308 = next;
        }
        func_L01_00348A98(o);
        if (a3 == 1) {
            *(Vec_00346CC8 *)(v + 0x40) = *(Vec_00346CC8 *)D_L01_001E29C0;
            func_0038CF68(v + 0x30, D_L01_001E29C0 + 0x20, func_0038CEA8(a1));
        }
        if (a3 == 2) {
            *(Vec_00346CC8 *)&tmp2 = *(Vec_00346CC8 *)a0;
            vec_add_ab(pos, a0, a1);
            if (func_L01_003476D8(o, &tmp2)) o[0x20] = a3;
        }
    }
    return o;
}
/* localdecomp:end func_L01_00346CC8 */

/* localdecomp:start func_L01_00347348 */
extern S_00341C10 D_L01_002C5600[];
#include "vu0.h"
extern u8 D_0014262F[];
void func_L01_00347348(u8 *self) {
    extern s32 func_L01_00457458(s32, s32);
    extern void func_L01_00348168(Obj *obj);
    extern void func_L01_00348258(u8 *shot, s128_00341C10 *pos);
    extern void func_L01_003493C8(u8 *, void *);
    extern s32 func_L01_003476D8(u8 *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    vu0_v4 previous;
    vu0_v4 point;
    u8 *vars = *(u8 **)(self + 0x68);
    s32 level = (D_0014262F[0] + D_L01_002C5600)->b;
    s32 i;
    f32 upper;
    if (!func_L01_00457458(0xC04, *(s16 *)(vars + 0x1A))) {
        func_003C2880((Obj *)self);
        return;
    }
    if (self[0x20] == 2) {
        func_L01_004CAB30(self + 0x10, self + 0x10);
        func_L01_00348168((Obj *)self);
        return;
    }
    if (*(s32 *)(vars + 0x28) == 1) {
        *(vu0_q *)&previous = *(vu0_q *)(vars + 0x40);
    } else {
        *(vu0_q *)&previous = *(vu0_q *)(self + 0x10);
    }
    vec_add_ab(self + 0x10, self + 0x10, vars);
    if (*(s32 *)(vars + 0x28) == 1) vec_add_ab(vars + 0x40, vars + 0x40, vars + 0x30);
    if (self[0x20] == 0) self[0x20] = 1;
    for (i = 0; i < 4; i++) {
        func_0038CDF8(&point, &previous, self + 0x10, i * 0.25f);
        func_L01_00348258(self, (s128_00341C10 *)&point);
    }
    if (level >= 2) {
        func_L01_003493C8(self, self + 0x10);
        func_0038CDF8(&point, &previous, self + 0x10, 0.5f);
        func_L01_003493C8(self, &point);
    }
    if (*(f32 *)(self + 0x10) < 2.0f || *(f32 *)(self + 0x10) > 1021.0f ||
        *(f32 *)(self + 0x14) < 2.0f || *(f32 *)(self + 0x14) > 1021.0f ||
        *(f32 *)(self + 0x18) < 2.0f || *(f32 *)(self + 0x18) > 1021.0f) {
        if (*(f32 *)(self + 0x10) < 5.0f) *(f32 *)(self + 0x10) = 5.0f;
        if (*(f32 *)(self + 0x14) < 5.0f) *(f32 *)(self + 0x14) = 5.0f;
        if (*(f32 *)(self + 0x18) < 5.0f) *(f32 *)(self + 0x18) = 5.0f;
        upper = 1016.0f;
        if (upper < *(f32 *)(self + 0x10)) *(f32 *)(self + 0x10) = upper;
        if (upper < *(f32 *)(self + 0x14)) *(f32 *)(self + 0x14) = upper;
        if (upper < *(f32 *)(self + 0x18)) *(f32 *)(self + 0x18) = upper;
        self[0x20] = 2;
    } else if (func_L01_003476D8(self, &previous) || func_0038CAD0(vars + 0x10)) {
        self[0x20] = 2;
    } else {
        func_L01_00348168((Obj *)self);
    }
}
/* localdecomp:end func_L01_00347348 */

/* localdecomp:start func_L01_00347640 */
extern void func_0038CF68(void *out, void *in, f32 s);
extern void func_0038CE90(void *dst, void *a, void *b);
void func_L01_00347640(u8 *a0, void *a1) {
    f32 one = 1.0f;
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 192, *(void **)(a0 + 104));
    func_0038CE90(a0 + 208, a0 + 192, a1);
    ((void (*)(f32 s, void *dst, void *src))func_0038CF68)(one, a0 + 208, a0 + 208);
    func_0038CE90(a0 + 224, a0 + 208, a0 + 192);
}
/* localdecomp:end func_L01_00347640 */

/* localdecomp:start func_L01_003476D8 */
extern S_00341C10 D_L01_002C5600[];
typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 b18, b19;
    u16 classid;
    f32 radius;
    s32 mode;
} Ray_003476D8;
typedef struct { u8 pad[0x6C]; f32 radius; u8 rest[0x80]; } Row_003476D8;
extern u8 D_0014262F[];
extern vu0_v4 D_L01_001EAA20[];
extern s32 D_001A71A0[];
s32 func_L01_003476D8(u8 *m, vu0_v4 *dest) {
    extern void func_0038CF68(void *out, void *in, f32 s);
    extern s32 func_003D3CB0(void *, void *, s32, s32, void *);
    extern void func_L01_00347838(u8 *, void *);
    extern s32 func_L01_00446720(void *);
    Ray_003476D8 ray;
    vu0_v4 pos, delta;
    vu0_v4 *hit;
    u8 *vars = *(u8 **)(m + 0x68);
    ray.owner = m;
    ray.flags = 0x10000;
    ray.radius = ((Row_003476D8 *)D_L01_002C5600)[D_0014262F[0]].radius;
    ray.mode = 1;
    *(vu0_q *)&ray.dir = *(vu0_q *)vars;
    func_0038CF68(&ray, &ray, 1.0f);
    ray.dir.w = 5627.925f;
    ray.classid = *(u16 *)(m + 0xAA);
    ray.b18 = 1;
    ray.b19 = 1;
    if (*(s32 *)(vars + 0x28) == 1) *(vu0_q *)&pos = *(vu0_q *)(vars + 0x40);
    else *(vu0_q *)&pos = *(vu0_q *)(m + 0x10);
    if (!func_003D3CB0(dest, &pos, 0, D_001A71A0[0], &ray)) return 0;
    vec_sub_ba(&delta, dest, &pos);
    func_0038CF68(&delta, &delta, 0.25f);
    hit = D_L01_001EAA20;
    vec_add_ab(&delta, &delta, hit);
    func_L01_00347838(m, &delta);
    if (*(void **)((u8 *)hit - 8) == 0 || func_L01_00446720(*(void **)((u8 *)hit - 8))) return 1;
    return 0;
}
/* localdecomp:end func_L01_003476D8 */

/* localdecomp:start func_L01_00347838 */
extern S_00341C10 D_L01_002C5600_00347838[];
typedef struct { u8 pad[0x70]; f32 f70; u8 rest[0x7C]; } Row_00347838;
extern vu0_v4 D_L01_001E29C0_00347838;
extern f32 D_L01_001D66B0_00347838;
extern u8 D_001425C0[];
extern void func_003C5180(void *, void *, s32);
extern void func_L01_0044AF78_00347838(void *, void *, void *, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_003303B8_00347838(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00470668_00347838(void *, void *, s32, f32);
extern void func_003D4D00(void *, s32, s32, void *, f32);
extern void func_L01_0046B458_00347838(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78_00347838(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);

void func_L01_00347838(u8 *m, void *pos) {
    vu0_v4 p;
    vu0_v4 dir;
    Ray_003476D8 ray;
    u8 *vars = *(u8 **)(m + 0x68);
    vu0_v4 *pp;

    p = *(vu0_v4 *)pos;
    pp = &p;
    if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b != 0) {
        s32 i;
        u8 *hero;
        if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b > 2) {
            func_003C5180(pp, &dir, 1);
            func_L01_0044AF78_00347838(m, &dir, pp, 0.0f, 0.0f, 10, 3, 16, -1, 1, 1, -1, 0, 0x1010001,
                              4.0f, 2.0f, 9.0f, 1.0f, 15.0f);
        }
        if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b == 1) {
            func_L01_003303B8_00347838(pp, 0, 40, 20, 30, 40, 0, 0, 0.2f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000,
                              0xFF8F00, 0xFF6430, 0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        }
        if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b == 2) {
            func_L01_003303B8_00347838(pp, 0, 40, 20, 30, 40, 0, 2, 0.3f, 0.0f, 0.0f, 0.0f,
                              0, 1, 0, 0, 0, 0, 0x10000, 0, 0x388EFF, 0xF7637F, 0xFF7F00, 0xFF2000,
                              0xFF8F00, 0x3064FF, 0x7FFFA060, 0x28FF007F, 0xFF647F, 0);
        }
        if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b == 3) {
            func_L01_003303B8_00347838(pp, 0, 40, 20, 30, 40, 50, 2, 0.4f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x110000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                              0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        if ((D_001425C0[0x6F] + D_L01_002C5600_00347838)->b > 3) {
            func_L01_003303B8_00347838(pp, 0, 40, 20, 30, 40, 50, 2, 0.5f, 0.0f, 0.0f, 0.0f,
                              0, 0, 0, 0, 0, 0, 0x110000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                              0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
        vec_sub_ba(&dir, &D_L01_001E29C0_00347838, m + 0x10);
        func_0038CF68(&dir, &dir, func_003824E0(0.1f, 0.2f));
        for (i = 0; i < 2; i++) {
            dir.x += func_003824E0(-0.05f, 0.05f);
            dir.y += func_003824E0(-0.05f, 0.05f);
            dir.z += func_003824E0(-0.05f, 0.05f);
            func_L01_00470668_00347838(&p, &dir, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584f);
        }
        ray.flags = 0x1010000;
        ray.mode = 1;
        ray.owner = m;
        ray.radius = ((Row_00347838 *)D_L01_002C5600_00347838)[D_001425C0[0x6F]].f70;
        *(vu0_q *)&ray.dir = *(vu0_q *)vars;
        func_0038CF68(&ray, &ray, 1.0f);
        ray.dir.w = 5627.925f;
        ray.b18 = 3;
        ray.b19 = 2;
        ray.classid = *(u16 *)(m + 0xAA);
        hero = D_001A4BE0;
        func_003D4D00(&p, 1, *(s32 *)(hero + 0x25C0), &ray, 2.0f);
    } else {
        s32 i;
        vec_sub_ba(&dir, &D_L01_001E29C0_00347838, &p);
        func_0038CF68(&dir, &dir, func_003824E0(0.075f, 0.15f));
        for (i = 0; i < 10; i++) {
            dir.x += func_003824E0(-0.05f, 0.05f);
            dir.y += func_003824E0(-0.05f, 0.05f);
            dir.z += func_003824E0(-0.05f, 0.05f);
            func_L01_00470668_00347838(&p, &dir, (func_00382498(25, 40) * 5 + 2) / 6, 0.00584f);
        }
        func_L01_0046B458_00347838(&p, 0x11, 5.25f, 0.1f, 0xBF408020, 2, 1, &D_L01_001D66B0_00347838, 0.0f, 1);
        func_L01_0046B458_00347838(&p, 0x11, 3.75f, 0.1f, 0xBF40A020, 2, -1, &D_L01_001D66B0_00347838, 0.0f, 1);
        func_L01_0046B458_00347838(&p, 0x11, 2.625f, 0.1f, 0xC0FFFFFF, 2, 1, &D_L01_001D66B0_00347838, 0.0f, 1);
        func_L01_0046B458_00347838(&p, 0x11, 1.875f, 0.1f, 0xB0FFFFFF, 2, -1, &D_L01_001D66B0_00347838, 0.0f, 1);
        func_L01_00470C78_00347838(&p, 0x19, 1.08f, 0.84000003f, 0x46787878, 2, 2, &D_L01_001D66B0_00347838, 0, 2, 6, 1);
        func_L01_00470C78_00347838(&p, 0x19, 2.0400002f, 0.84000003f, 0x46787878, 2, -1, &D_L01_001D66B0_00347838, 1, 2, 6, 1);
        func_L01_00470C78_00347838(&p, 0x19, 2.4f, 1.8000001f, 0x2D787878, 2, 1, &D_L01_001D66B0_00347838, 1, 2, 6, 1);
    }
}
/* localdecomp:end func_L01_00347838 */

/* localdecomp:start func_L01_00348160 */
void func_L01_00348160(void) {

}
/* localdecomp:end func_L01_00348160 */

/* localdecomp:start func_L01_00348168 */
extern void func_L01_003481F8(O_347888 *o);

extern int func_L01_00348500(Obj *);
extern int func_L01_00348C88(Obj *);
extern int func_L01_00349538(Obj *);
extern void func_L01_00404A10_00348168(void (*)(void), Obj *);

void func_L01_00348168(Obj *obj) {
    int a = func_L01_00348500(obj);
    int b = func_L01_00348C88(obj);
    int c = func_L01_00349538(obj);

    if (a == 0 && b == 0 && c == 0) {
        if (obj->b32 == 2) {
            func_003C2880(obj);
        }
    } else {
        func_L01_00404A10_00348168(((void (*)(void))func_L01_003481F8), obj);
    }
}
/* localdecomp:end func_L01_00348168 */

/* localdecomp:start func_L01_003481F8 */
extern s32 func_L01_00457458(s32, s32);
extern void func_L01_00348620(O_347888 *);
extern void func_L01_00348E30(O_347888 *);
extern void func_L01_003495F0(O_347888 *);
void func_L01_003481F8(O_347888 *o) {
    if (func_L01_00457458(3076, o->x68->x1A) == 0) {
        ((void (*)(O_347888 *))func_003C2880)(o);
    } else {
        func_L01_00348620(o);
        func_L01_00348E30(o);
        func_L01_003495F0(o);
    }
}
/* localdecomp:end func_L01_003481F8 */

/* localdecomp:start func_L01_00348258 */
typedef int s128_00348258 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    f32 angle;  /* 0x20 */
    f32 width;  /* 0x24 */
    f32 spin;   /* 0x28 */
    f32 drift;  /* 0x2C */
} TrailPoint_00348258;
typedef struct {
    u8 pad0[0x18];
    s16 trail;  /* 0x18: its slot in the trail list */
    s16 id;     /* 0x1A */
    u8 pad1C[4];
    s16 points; /* 0x20: points laid so far */
} FluxVars_00348258;

__asm__(".extern D_L01_001DD314, 4");
__asm__(".extern D_L01_001DD318, 4");
__asm__(".extern D_L01_001DD31C, 4");
__asm__(".extern D_L01_001DD320, 4");
__asm__(".extern D_L01_001DD324, 4");
__asm__(".extern D_L01_001DD328, 4");
extern f32 D_L01_001DD314;
extern f32 D_L01_001DD318;
extern f32 D_L01_001DD31C;
extern f32 D_L01_001DD320;
extern f32 D_L01_001DD324;
extern f32 D_L01_001DD328;
extern char *func_L01_00457480(s32, s32);
extern f32 func_L01_0044AE78(f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00348380(TrailPoint_00348258 *points, s32 count);

/* flux_shot_trail: a per-step call of the Flux Rifle shot that lays its trail: the next
   point of its list at pos, its angle from n x 40 degrees (D_L01_001DD31C), a spin of 1 to
   1 degree (D_L01_001DD314, D_L01_001DD318), width 0.3 (D_L01_001DD320) and a drift of
   0.01-0.5 either way (D_L01_001DD324, D_L01_001DD328) x 0.02. */
void func_L01_00348258(u8 *shot, s128_00348258 *pos)
{
    FluxVars_00348258 *vars = *(FluxVars_00348258 **)(shot + 0x68);
    u32 lists;
    TrailPoint_00348258 **list;
    s32 n;

    if (vars == 0) {
        return;
    }
    lists = (u32)func_L01_00457480(0xC04, vars->id);
    if (lists == 0) {
        return;
    }
    n = vars->points;
    /* the shot's own list among them */
    list = (TrailPoint_00348258 **)(vars->trail * 4 + lists);
    *(s128_00348258 *)(*list)[n].pos = *pos;
    (*list)[n].angle = func_L01_0044AE78(n * (D_L01_001DD31C * 0.017453292f));
    (*list)[n].spin = func_003824E0(D_L01_001DD314, D_L01_001DD318) * 0.017453292f;
    (*list)[n].width = D_L01_001DD320;
    (*list)[n].drift = func_L01_00443A18(D_L01_001DD324, D_L01_001DD328) * 0.020000001f;
    func_L01_00348380(*list, n);
    vars->points++;
}
/* localdecomp:end func_L01_00348258 */

/* localdecomp:start func_L01_00348380 */
#include "vu0.h"
extern s32 D_L01_001D673C;
extern f32 D_L01_001DD310;
__asm__(".extern D_L01_001DD310, 4");
void func_L01_00348380(TrailPoint_00348258 *points, s32 count) {
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D850(void *, void *, void *);
    vu0_v4 axis;
    vu0_v4 result;
    vu0_v4 delta;
    vu0_v4 rotation;
    f32 one = 1.0f;
    *(vu0_q *)&axis = 0;
    axis.z = one;
    if (D_L01_001D673C) func_003C5180(&axis, points[count].pos, 1);
    if ((f32)count == 0.0f || fabs_asm(points[count].angle) < 0.00001f) {
        func_0038CE20(&result, &axis, points[count].width);
    } else {
        vec_sub_ba(&delta, points[count].pos, points[count - 1].pos);
        func_0038CF68(&rotation, &delta, one);
        func_003C4840(&rotation, &rotation, points[count].angle);
        func_0038D850(&result, &axis, &rotation);
        func_0038CE20(&result, &result, points[count].width);
    }
    vec_add_ba(points[count].pad0, points[count].pos, &result);
    *(f32 *)(points[count].pad0 + 12) = D_L01_001DD310;
}
/* localdecomp:end func_L01_00348380 */

/* localdecomp:start func_L01_00348500 */
__asm__(".extern D_L01_001DD340, 4");
extern float D_L01_001DD340;
__asm__(".extern D_L01_001DD344, 4");
extern float D_L01_001DD344;

int func_L01_00348500(Obj *arg0)
{
    extern char *func_L01_00457480(int, int);
    extern float func_0038DAB8(float, float);
    extern void func_L01_00348380(TrailPoint_00348258 *, s32);
    extern int func_0038CB00(char *);
    char *moby = (char *)arg0;
    char *state;
    char *table;
    char *base;
    char *rec;
    int index;
    int count;
    int i = 0;
    float value;

    state = *(char **)(moby + 0x68);
    table = func_L01_00457480(0xC04, *(short *)(state + 0x1A));
    index = *(short *)(state + 0x18);
    base = *(char **)(table + index * 4);
    count = *(short *)(state + 0x20);
    if (count > 0) {
        rec = base;
        do {
            *(float *)(rec + 0x20) = func_0038DAB8(*(float *)(rec + 0x20), *(float *)(rec + 0x28));
            func_L01_00348380((TrailPoint_00348258 *)base, i);
            rec += 0x30;
            i++;
        } while (i < count);
    }
    value = D_L01_001DD340;
    if (value > 7.0f) {
        D_L01_001DD340 = 0.0f;
    } else if (value < -7.0f) {
        D_L01_001DD340 = 0.0f;
    }
    D_L01_001DD340 = D_L01_001DD340 - D_L01_001DD344;
    if (D_L01_001DD340 <= -4.0f) {
        D_L01_001DD340 = D_L01_001DD340 + 4.0f;
    }
    return func_0038CB00(state + 0x22) == 0;
}
/* localdecomp:end func_L01_00348500 */
