#include "common.h"

/* declared by functions of L39_0056B080.c, which this file was cut from */
typedef struct {
    u8 pad0[0x100];
    f32 f100;
    f32 f104;
    u8 pad108[0x1A0 - 0x108];
    s32 w1A0;
} Pad_0056B080;
typedef struct {
    u8 pad0[0x40];
    u8 pos[0x10];
    u8 pad50[0xF0 - 0x50];
    u8 *wF0;
    s32 wF4;
    s32 wF8;
    s32 wFC;
    s32 w100;
    s32 w104;
    u8 pad108[0x11C - 0x108];
    s32 w11C;
    u8 pad120[0x126 - 0x120];
    s16 h126;
    u8 pad128[0x12C - 0x128];
    u8 b12C;
    u8 pad12D[0x133 - 0x12D];
    u8 b133;
    Pad_0056B080 *p134;
    u8 pad138[0x144 - 0x138];
    s32 w144;
    f32 f148;
    u8 pad14C[0x2B0 - 0x14C];
} St_0056B080;
typedef struct {
    u8 pad0[0x108];
    f32 f108[6];
    u8 pad120[0x144 - 0x120];
    struct {
        u8 *w144;
        s32 w148;
    } s144;
    u8 pad14C[4];
    St_0056B080 st;
    void (*fn400)(s32);
    u8 pad404[0x460 - 0x404];
} Ent_0056B080;
extern Ent_0056B080 D_L39_0024DE80[];
extern s32 D_L39_0024B858[] __attribute__((section(".sdata")));

/* localdecomp:start func_L39_0056B940 */
#include "vu0.h"
extern void func_0038D590(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern vu0_v4 D_L39_0025F760;

void func_L39_0056B940(s32 idx, s32 flag) {
    Ent_0056B080 *ent = &D_L39_0024DE80[idx];
    u8 *H = (u8 *)&ent->st;
    u8 *P = *(u8 **)((u8 *)ent + 0x50);
    u8 *st = *(u8 **)(P + 0x70);
    u8 *e = st + 0x180;
    u8 *sb = st + 0x60;
    vu0_v4 v00;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    f32 m60[12];
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    f32 mC0[12];
    vu0_v4 vF0;
    f32 len;
    f32 len2;

    if (flag != 0) {
        v50.x = -*(f32 *)(e + 0x2C);
        v50.y = 0.0f;
        v50.z = *(f32 *)(e + 0x30);
        v50.w = 0.0f;
        func_0038D590(m60, H);
        func_0038D000(&v40, &v50, *(u8 **)(sb + 0xE0) + 0xC0);
        vec_add_ba(P + 0x30, sb, &v40);
        func_0038CE20(&v10, *(u8 **)(sb + 0xE0) + 0xE0, *(f32 *)(sb + 0xD0));
        vec_add_ab(&v30, sb, &v10);
        if (func_003D3CB0(&v30, P + 0x30, D_L39_0024B858[idx], *(s32 *)(H + 0xF0), 0) != 0) {
            vec_sub_ba(&v90, &D_L39_0025F760, &v30);
            len = func_0038CEA8(&v90);
            if (len <= 2.5f) {
                vB0.x = *(f32 *)(e + 0x2C);
                vB0.y = 0.0f;
                vB0.z = *(f32 *)(e + 0x30);
                vB0.w = 0.0f;
                func_0038D590(mC0, H);
                func_0038D000(&vA0, &vB0, *(u8 **)(sb + 0xE0) + 0xC0);
                vec_add_ba(P + 0x30, sb, &vA0);
                func_0038CE20(&v10, *(u8 **)(sb + 0xE0) + 0xE0, *(f32 *)(sb + 0xD0));
                vec_add_ab(&v30, sb, &v10);
                if (func_003D3CB0(&v30, P + 0x30, D_L39_0024B858[idx], *(s32 *)(H + 0xF0), 0) != 0) {
                    vec_sub_ba(&vF0, &D_L39_0025F760, &v30);
                    len2 = func_0038CEA8(&vF0);
                    if (len2 == 0.0f) {
                        *(vu0_q *)(P + 0x30) = *(vu0_q *)&v30;
                    } else {
                        func_0038CE20(&vF0, &vF0, (len2 - 0.5f) / len2);
                        vec_add_ab(P + 0x30, &v30, &vF0);
                    }
                }
            } else {
                func_0038CE20(&v90, &v90, (len - 0.5f) / len);
                vec_add_ab(P + 0x30, &v30, &v90);
            }
        }
    }
    {
        f32 *a = (f32 *)(P + 0x30);
        f32 *b = (f32 *)(P + 0x64);
        b[0] = a[0];
        b[1] = a[1];
        b[2] = a[2];
    }
    *(vu0_q *)&v00 = *(vu0_q *)((u8 *)ent + 0x90);
    func_0038CF68(&v10, &v00, *(f32 *)(sb + 0xD0));
    vec_add_ab(&v30, &v10, sb);
    vec_sub_ba(&v20, &v30, P + 0x30);
    func_0038CF68(P, &v20, 1.0f);
    *(vu0_q *)(P + 0x20) = *(vu0_q *)&v00;
    func_0038CE90(P + 0x10, P, P + 0x20);
    func_0038CF68(P + 0x10, P + 0x10, 1.0f);
    func_0038CE90(P + 0x20, P + 0x10, P);
    *(vu0_q *)(P + 0x40) = *(vu0_q *)P;
}
/* localdecomp:end func_L39_0056B940 */
