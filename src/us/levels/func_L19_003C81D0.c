#include "common.h"

/* NTSC-U counterpart of func_L19_003CA288 (src/levels/19_thran_asteroid_belt/L19_003C9F00.c) */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C9F00;
typedef struct { u8 pad[0x30]; V_3C9F00 v; u8 pad2[0x40]; } P_3C9F00;
extern P_3C9F00 *D_L19_001DF800_003C81D0;

/* localdecomp:start func_L19_003C81D0 */
extern s32 D_001A7430[];
extern u8 D_001A30B0[];
extern s32 func_L01_00452EC8(u8 *);
extern s32 func_0039FE80(s32, s32, u8 *);
extern void func_0039FB08(s32);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_0040BB20(void *);
extern void func_003BF838(u8 *, void *, void *, void *);

void func_L19_003C81D0(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    V_3C9F00 pos;
    V_3C9F00 f0;
    V_3C9F00 t;

    if (v == 0 || D_001A7430[0] <= 0)
        return;
    pos = *(V_3C9F00 *)(obj + 0x10);
    f0 = *(V_3C9F00 *)(obj + 0xF0);
    switch (obj[0x20]) {
    case 0: {
        s32 id;
        *(V_3C9F00 *)(v + 0x150) = pos;
        *(s32 *)(v + 0x144) = -1;
        id = *(s32 *)(v + 0x130);
        if (id != -1) {
            *(V_3C9F00 *)(v + 0x160) = D_L19_001DF800_003C81D0[id].v;
            func_L01_00441FB8(obj, 1, -1);
        } else {
            func_L01_00441FB8(obj, 3, -1);
        }
        break;
    }
    case 1:
        if (func_L01_00452EC8(obj) != 0) {
            s32 id;
            u8 *e;
            id = *(s32 *)(v + 0x144);
            if (id == -1 || (e = D_001A30B0 + (id << 7), *(u8 **)(e + 0xDC) != obj) || e[0xD0] == 0)
                *(s32 *)(v + 0x144) = func_0039FE80(0, 4, obj);
        }
        if (func_00388800(obj + 0x10, v + 0x160) <= 0.88f) {
            t = *(V_3C9F00 *)(v + 0x150);
            *(V_3C9F00 *)(v + 0x150) = *(V_3C9F00 *)(v + 0x160);
            *(V_3C9F00 *)(v + 0x160) = t;
            *(f32 *)(v + 0x13C) = *(f32 *)(v + 0x138);
            func_L01_00441FB8(obj, 2, -1);
        } else {
            vec_sub_ba(&t, v + 0x160, obj + 0x10);
            func_00388830(&t, &t, *(f32 *)(v + 0x134) * 0.016666668f);
            vec_add_ba(obj + 0x10, &t, obj + 0x10);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj) != 0) {
            s32 id;
            u8 *e;
            id = *(s32 *)(v + 0x144);
            if (id != -1 && (e = D_001A30B0 + (id << 7), *(u8 **)(e + 0xDC) == obj) && e[0xD0] != 0)
                func_0039FB08(id);
            *(s32 *)(v + 0x144) = -1;
        }
        if (func_L01_0040BB20(v + 0x13C) != 0)
            func_L01_00441FB8(obj, 1, -1);
        break;
    }
    vec_sub_ba(&t, obj + 0x10, &pos);
    func_003BF838(v + 0x30, &t, &f0, obj + 0xF0);
}
/* localdecomp:end func_L19_003C81D0 */
