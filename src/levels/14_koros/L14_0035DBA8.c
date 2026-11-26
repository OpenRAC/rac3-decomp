#include "common.h"

/* localdecomp:start func_L14_0035DBA8 */
#include "vu0.h"
typedef struct {
    f32 v[5];
} S_35DBA8_f;
typedef struct {
    u8 b[4];
} S_35DBA8_b;
typedef struct {
    u8 pad[0x44];
    s32 time;
    s32 choice;
} Choice_35DBA8;
extern S_35DBA8_f D_L14_001DD720;
extern S_35DBA8_b D_L14_001DD738[];
extern S_35DBA8_b D_L14_001DD740[];
extern S_35DBA8_b D_L14_001DD748[];
extern S_35DBA8_b D_L14_001DD750[];
__asm__(".extern D_L14_001DD6E4, 4");
extern s32 D_L14_001DD6E4;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L14_0035DA48(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L14_0035DBA8(void *arg0, void *target) {
    u8 *a0 = arg0;
    S_35DBA8_f thr = D_L14_001DD720;
    S_35DBA8_b l0 = D_L14_001DD738[0];
    S_35DBA8_b l1 = D_L14_001DD740[0];
    S_35DBA8_b l2 = D_L14_001DD748[0];
    S_35DBA8_b l3 = D_L14_001DD750[0];
    u8 *table[4] = { l0.b, l1.b, l2.b, l3.b };
    vu0_v4 v;
    u8 *s;
    u8 *sel;
    f32 f;
    s32 i;
    s32 j;
    s32 d;
    s32 b;
    u16 mask;
    s = *(u8 **)(a0 + 0x68);
    vec_sub_ba(&v, target, a0 + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    f = fabs_asm(func_0038D0C8(func_0038CE68(&v, a0 + 0xD0)) - 1.5707964f);
    if (0.0f < func_0038CE68(&v, a0 + 0xC0)) {
        f = 6.2831855f - f;
    }
    d = 4 - (s32)(*(f32 *)s / (f32)*(s16 *)(s + 4) * 4.0f);
    f += 0.7853982f;
    sel = l1.b;
    i = 0;
    do {
        mask = *(u16 *)(a0 + 0x7C);
loop:
        if (i < 4) {
            j = i++;
            if (!(thr.v[j] < f)) goto loop;
            if (!(f <= thr.v[i])) goto loop;
            sel = table[j];
        }
    } while (0);
    for (j = 0; j < 4; j++) {
        b = sel[j];
        if ((mask >> b) & 1) {
            if (d + *(s16 *)(s + 0x36) >= 5) {
                func_L14_0035DA48(a0, b);
                func_L01_004450F0(a0, 2, -1);
                ((Choice_35DBA8 *)s)->choice = b;
                ((Choice_35DBA8 *)s)->time = (D_L14_001DD6E4 * 5 + 2) / 6;
                return;
            }
        }
    }
}
/* localdecomp:end func_L14_0035DBA8 */

/* localdecomp:start func_L14_0035DE68 */
void func_L14_0035DBA8(void *, void *);
void func_L01_004450F0(void *, s32, s32);

void func_L14_0035DE68(void *arg0, void *arg1) {
    f32 *temp_v0;
    f32 temp_f0;

    temp_v0 = *(f32 **)((u8 *)arg0 + 0x68);
    temp_f0 = *temp_v0 - (*(f32 *)((u8 *)arg1 + 0x2C));
    *temp_v0 = temp_f0;
    if ((temp_f0 > 0.0f) && ((*(u16 *)((u8 *)arg0 + 0x7C)) != 0)) {
        func_L14_0035DBA8(arg0, arg1);
        return;
    }
    *(u16 *)((u8 *)arg0 + 0x7C) = 0U;
    func_L01_004450F0(arg0, 3, -1);
}
/* localdecomp:end func_L14_0035DE68 */

/* localdecomp:start func_L14_0035DED8 */
void func_L14_0035D670(u8 *a0, s32 a1);
void func_L14_0035DE68(void *a0, void *a1);
void func_L01_00439880(u8 *a0, u16 *a1, s32 *a2);
void func_L01_004450F0(void *a0, s32 a1, s32 a2);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CAD0(void *);
void func_L14_0035DED8(u8 *a0) {
    u16 tmp;
    s32 tmp2;
    u8 *s = *(u8 **)(a0 + 0x68);
    s32 p;
    switch (a0[0x20]) {
    case 0:
        func_L01_00439880(a0, &tmp, &tmp2);
        *(u16 *)(a0 + 0x7C) = tmp;
        *(f32 *)s = *(s32 *)(s + 0x40);
        *(u16 *)(s + 4) = *(u16 *)(s + 0x40);
        *(u16 *)(s + 0x36) = tmp2;
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        p = func_L01_00447490(a0, 1, 1);
        if (p != 0) {
            func_L14_0035DE68(a0, (void *)p);
        }
        break;
    case 2:
        func_L14_0035D670(a0, *(s32 *)(s + 0x48));
        if (func_0038CAD0(s + 0x44) != 0) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L14_0035DED8 */

/* localdecomp:start func_L14_0035DFE0 */
extern u8 D_L14_001D66B0;
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L01_00429840(void *, void *, s32, s32, u8 *, u32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00451E78(void *, s32, f32);
extern void func_003C2880(void *);
void func_L14_0035DFE0(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0) != 0) {
        func_003A52A0(0, 0, a0);
        func_L01_00451FE0(a0, 0xF, &D_L14_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        func_L01_00429840(a0, a0 + 0x10, 5, 0, &D_L14_001D66B0, 0x463C5028, 0, 0xD0, 4.0f, 8.0f, 1.5f, 2.5f);
        func_L01_00451E78(a0, 1, 0.0f);
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L14_0035DFE0 */
