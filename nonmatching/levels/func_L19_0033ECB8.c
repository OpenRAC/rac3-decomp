/* func_L19_0033ECB8: 122 diff with -mvu0-use-vf0-vf2 @ps2as on L19_0033ECB8.c (it holds only this function; the file has neither flag now, so this draft does not compile with its current flags). A four-state mover between v->x70 and v->x80. Left: retail cross-jumps state 0's func_L01_004450F0(obj, 1, -1) into state 1's (obj, 2, -1) call and keeps state 3's (obj, 2, -1) apart; here state 1's call merges with state 3's instead, which shifts every later block. */
#include "vu0.h"
typedef struct { u8 pad[0x30]; vu0_v4 v; u8 pad2[0x40]; } P_33ECB8;
typedef struct {
    u8 pad0[0x70];
    vu0_v4 x70;
    vu0_v4 x80;
    s32 x90;
    s32 x94;
    s32 x98;
    s32 x9C;
    s32 xA0;
    s32 xA4;
} V_33ECB8;
__asm__(".extern D_L19_001DD204, 4");
extern f32 D_L19_001DD204;
extern P_33ECB8 *D_L19_001DF800;
extern u8 D_001A30B0[];
extern s32 func_L01_00456250(u8 *);
extern f32 func_003C3D30(void *, s32, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C4DA8(u8 *, void *, void *, void *);

void func_L19_0033ECB8(u8 *obj) {
    V_33ECB8 *v = *(V_33ECB8 **)(obj + 0x68);
    u8 *p = obj + 0x10;
    vu0_v4 save;
    vu0_v4 d;

    save = *(vu0_v4 *)(obj + 0x10);
    if (obj[0x21] != 0xFF)
        v->x98 = func_L01_00456250(obj);
    switch (obj[0x20]) {
    case 0:
        v->x9C = -1;
        v->x70 = *(vu0_v4 *)(obj + 0x10);
        v->x80 = *(vu0_v4 *)(obj + 0x10);
        if (v->xA4 != -1)
            v->x80 = D_L19_001DF800[v->xA4].v;
        else
            v->x80.z = func_003C3D30(p, 0, 0, 0.5f)
                + D_L19_001DD204 * *(f32 *)(obj + 0x2C) / *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
        v->x94 = (f32)v->x94 * 50.0f;
        v->x98 = v->x90;
        if (v->x98 != 0) {
            *(vu0_v4 *)(obj + 0x10) = v->x70;
            v->xA0 = v->x94;
        } else {
            *(vu0_v4 *)(obj + 0x10) = v->x80;
            v->xA0 = 0;
        }
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (v->x98 != 0) {
            if (v->xA0 < v->x94)
                func_L01_004450F0(obj, 2, -1);
        } else if (v->xA0 > 0) {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 2: {
        s32 id;
        s32 n;
        u8 *s;

        id = v->x9C;
        if (id == -1 || (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
            v->x9C = func_003A52A0(0, 4, obj);
        n = v->xA0 + 1;
        v->xA0 = n;
        vec_sub_ba(&d, &v->x70, &v->x80);
        func_0038CE20(&d, &d, (f32)n / (f32)v->x94);
        vec_add_ba(obj + 0x10, &d, &v->x80);
        if (v->x98 == 0) {
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 3, -1);
        } else if (v->x94 < v->xA0) {
            v->xA0 = v->x94;
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
    case 3: {
        s32 id;
        u8 *s;

        if (*(u16 *)(obj + 0x96) >= 0x33) {
            id = v->x9C;
            if (id == -1 || (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) != obj) || s[0xD0] == 0)
                v->x9C = func_003A52A0(0, 4, obj);
            func_0038CAD0(&v->xA0);
            vec_sub_ba(&d, &v->x70, &v->x80);
            func_0038CE20(&d, &d, (f32)v->xA0 / (f32)v->x94);
            vec_add_ba(obj + 0x10, &d, &v->x80);
        }
        if (v->x98 != 0) {
            func_L01_004450F0(obj, 2, -1);
        } else if (v->xA0 <= 0) {
            v->xA0 = 0;
            id = v->x9C;
            if (id != -1 && (s = D_001A30B0 + (id << 7), *(u8 **)(s + 0xDC) == obj) && s[0xD0] != 0)
                func_003A4F28(id);
            v->x9C = -1;
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
    }
    if (*(u16 *)(obj + 0x96) < 0xFFFF)
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    vec_sub_ba(&d, obj + 0x10, &save);
    func_003C4DA8((u8 *)v + 0x30, &d, obj + 0xF0, obj + 0xF0);
}
