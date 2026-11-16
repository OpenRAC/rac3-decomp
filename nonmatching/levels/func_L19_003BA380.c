/* NTSC-U draft (Claude wave C4): C of func_L19_003B86C0, the NTSC-U twin of func_L19_003BA380, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L19_003B86C0", whose code is not the PAL one).
 * Worker's note: flags: MATCH with '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (286/286 words, check_native.py MATCH, name_conflicts clean, no jump table, no divs row needed). The PAL file's flag line is STD without them (vec_sub_ba from vu0.h ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003B86C0 */
typedef union { u8 b[0x2A00]; } Hero_3B86C0;
extern Hero_3B86C0 D_001A4BE0;
extern s32 D_001DF240_sda;
extern s32 D_001DF758_sda;
__asm__(".extern D_001DF758_sda, 4");
extern u8 *D_L19_001DF71C_003B86C0;
__asm__(".extern D_L19_001DF71C_003B86C0, 16");
extern u8 *D_L19_0021C260_003B86C0[];
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L19_003FC550(void *, void *, void *, void *, void *, s32, s32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L19_003ACF88(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003BD360(void *);

void func_L19_003B86C0(u8 *o) {
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    u16 *lst;
    u8 *obj;
    s32 cnt;
    s32 col;
    u16 t;
    u8 st;

    st = o[0x20];
    if (st == 0) {
        *(u16 *)(o + 0x34) |= 0x10;
        func_L01_00441FB8(o, 1, -1);
    } else if (st == 1) {
        if (o[0x31] != 0 && func_0037E1D8(0x3C) == 0) {
            func_0039FE80(0, 0, o);
            *(vu0_q *)&v30 = 0;
            *(vu0_q *)&v10 = 0;
            *(vu0_q *)&v20 = 0;
            *(vu0_q *)&v40 = 0;
            v10.y = -0.4f;
            v10.z = 11.44f;
            v20.z = 15.67f;
            v30.x = -2.0f;
            v30.y = -3.5f;
            v10.w = 1.0f;
            v20.y = -0.5f;
            v20.w = 1.0f;
            v30.z = 2.0f;
            v30.w = 1.0f;
            v40.x = 2.0f;
            v40.y = -0.5f;
            v40.w = 1.0f;
            func_L19_003FC550(o, &v10, &v20, &v30, &v40, 5, 0);
        }
        cnt = D_001DF240_sda;
        col = func_003894A0(0xA0000080, 0x40000040, func_00388978((f32)(cnt % 60) / 60.0f * 6.2831855f - 3.1415927f) * 0.5f + 0.5f);
        *(s32 *)(o + 0x78) = col;
        if (func_L01_00444358(o, -1, 0) != 0) {
            func_L01_00441FB8(o, 2, -1);
        }
    } else if (st == 2) {
        if (func_L01_00452EC8(o) != 0) {
            func_0039FE80(1, 0, o);
            t = *(u16 *)(o + 0x34) & 0xFFEF;
            *(vu0_q *)&v10 = 0;
            *(u16 *)(o + 0x34) = t;
            v10.y = -0.4f;
            v10.z = 11.44f;
            v10.w = 1.0f;
            *(vu0_q *)&v20 = 0;
            v20.y = -0.5f;
            v20.z = 15.67f;
            v20.w = 1.0f;
            *(vu0_q *)&v30 = 0;
            v30.x = -4.0f;
            v30.y = -7.0f;
            v30.z = 4.0f;
            v30.w = 1.0f;
            *(vu0_q *)&v40 = 0;
            v40.x = 4.0f;
            v40.y = -0.5f;
            v40.z = -1.0f;
            v40.w = 1.0f;
            func_L19_003FC550(o, &v10, &v20, &v30, &v40, 0x28, 0);
            if (o[0x21] != 0xFF) {
                lst = (u16 *)D_L19_0021C260_003B86C0[o[0x21]];
                while (o[0x21] != 0xFF && D_001DF758_sda >= o[0x21] && lst != 0 && (((s16 *)lst)[-1] >= 0 || lst == (u16 *)D_L19_0021C260_003B86C0[o[0x21]])) {
                    obj = D_L19_001DF71C_003B86C0 + ((*lst & 0x7FFF) << 8);
                    if (obj == 0) {
                        break;
                    }
                    if (*(s16 *)(obj + 0xAA) == 0x1A8E) {
                        func_L19_003ACF88(obj);
                        lst++;
                    } else {
                        lst++;
                        if (*(s16 *)(obj + 0xAA) == 0x1A77) {
                            *(s32 *)(*(u8 **)(obj + 0x68) + 0xC) = 1;
                        }
                    }
                }
            }
            vec_sub_ba(&v10, o + 0x10, D_001A4BE0.b + 0x80);
            func_00388830(&v10, &v10, 0.06666667f);
            func_L01_0044ED60(o, 0xFF, &v10, 1.0f, 2.0f, 0.5f, 1.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
        }
        if (*(u16 *)(o + 0x96) >= 0x79) {
            func_003BD360(o);
            return;
        }
    }
    *(u16 *)(o + 0x96) = *(u16 *)(o + 0x96) + 1;
}
/* localdecomp:end func_L19_003B86C0 */
