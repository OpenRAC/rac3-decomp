#include "common.h"

/* NTSC-U counterpart of func_L19_003553A0 (src/levels/shared/L19_003553A0.c): 0.0198676 -> 0.0166667; 0.0733038 -> 0.0610865 */
#include "vu0.h"

/* localdecomp:start func_L19_003543A8 */
typedef struct {
    s32 id0;
    s32 id1;
    s32 id2;
    s32 id3;
    s32 count;
    s32 flag;
    s32 pad18;
    u8 *other;
    u8 pad20[4];
    f32 timer;
} V_003553A0;

extern u8 *D_L19_001DF71C_003543A8;
__asm__(".extern D_L19_001DD704, 4");
extern f32 D_L19_001DD704;
__asm__(".extern D_L19_001DD700, 4");
extern f32 D_L19_001DD700;
__asm__(".extern D_L19_001DD6FC, 4");
extern f32 D_L19_001DD6FC;
__asm__(".extern D_L19_001DD6F8, 4");
extern s32 D_L19_001DD6F8;
extern u8 D_L19_001E2100_003543A8[];
extern void func_L01_00441FB8_003543A8(void *, s32, s32);
extern void func_L01_00452F40(void *, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern u8 *func_L19_0045A428(u8 *, u8 *, s32, s32, u8, s16, u8, f32);
extern void func_L01_004026A0_003543A8(void *, void *);
extern void func_L01_0044EB38(void *, void *, s32, s32, f32);
extern void func_L19_003547B8(u8 *);

void func_L19_003543A8(u8 *self) {
    V_003553A0 *v = *(V_003553A0 **)(self + 0x68);
    s32 id;
    u8 *m;
    u8 st;
    u8 *cam;
    f32 pos[4] __attribute__((aligned(16)));

    switch (self[0x20]) {
    case 0:
        if (v->flag != 0) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x41;
        }
        v->timer = 1.0f;
        if (v->id2 == -1 && v->id3 == -1) {
            func_L01_00441FB8_003543A8(self, 2, -1);
        } else {
            func_L01_00441FB8_003543A8(self, 1, -1);
        }
    case 1:
        id = v->id2;
        if (id == -1 || (m = (u8 *)((id << 8) + (s32)D_L19_001DF71C_003543A8), m[0x20] == 0xFE) || m[0x20] == 0xFD) {
            id = v->id3;
            if (id == -1 || (m = (u8 *)((id << 8) + (s32)D_L19_001DF71C_003543A8), m[0x20] == 0xFE) || m[0x20] == 0xFD) {
                func_L01_00441FB8_003543A8(self, 2, -1);
            }
        }
        break;
    case 3:
        if (v->other == 0 || ((st = v->other[0x20]) != 0xFE && st != 0xFD)) {
            break;
        }
        if (v->id0 != -1) {
            func_L01_00452F40(D_L19_001DF71C_003543A8 + (v->id0 << 8), 1);
        }
        if (v->id1 != -1) {
            func_L01_00452F40(D_L19_001DF71C_003543A8 + (v->id1 << 8), 1);
        }
        func_003BEBF8(&v->timer, 0.0f, 0.0166666675f);
        if (v->timer <= 0.0f) {
            func_L01_00441FB8_003543A8(self, 4, -1);
        }
        break;
    }
    if (self[0x31] != 0 && v->timer > 0.0f) {
        if (v->count != 0) {
            cam = D_L19_001E2100_003543A8;
            pos[0] = func_00388960(func_00389380(1.5707964f, *(f32 *)(cam + 0x18))) * D_L19_001DD704;
            pos[1] = func_00388978(func_00389380(1.5707964f, *(f32 *)(cam + 0x18))) * D_L19_001DD704;
            pos[2] = 0.0f;
            vec_add_ba(pos, pos, self + 0x10);
            pos[2] += D_L19_001DD700;
            func_L19_0045A428((u8 *)pos, self, v->count + 2, D_L19_001DD6F8, 0x20, 2, 0xFF, D_L19_001DD6FC);
        }
        if (v->timer > 0.0f) {
            func_L01_004026A0_003543A8(func_L19_003547B8, self);
        }
    }
    if (self[0x31] != 0) {
        func_L01_0044EB38(self, (u8 *)v + 0x20, 0x80909090, 0x80404040, 0.061086528f);
    }
}
/* localdecomp:end func_L19_003543A8 */
