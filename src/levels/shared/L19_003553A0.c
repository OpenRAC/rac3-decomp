#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003553A0 */
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

extern u8 *D_L19_001DF71C_003553A0;
__asm__(".extern D_L19_001DD6C4, 4");
extern f32 D_L19_001DD6C4;
__asm__(".extern D_L19_001DD6C0, 4");
extern f32 D_L19_001DD6C0;
__asm__(".extern D_L19_001DD6BC, 4");
extern f32 D_L19_001DD6BC;
__asm__(".extern D_L19_001DD6B8, 4");
extern s32 D_L19_001DD6B8;
extern u8 D_L19_001E2100[];
extern void func_L01_004450F0_003553A0(void *, s32, s32);
extern void func_L01_00456230(void *, s32);
extern f32 func_003C4138(f32 *, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern u8 *func_L19_0045E1A8(u8 *, u8 *, s32, s32, u8, s16, u8, f32);
extern void func_L01_00404A10_003553A0(void *, void *);
extern void func_L01_00451DB8(void *, void *, s32, s32, f32);
extern void func_L19_003557B0(u8 *);

void func_L19_003553A0(u8 *self) {
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
            func_L01_004450F0_003553A0(self, 2, -1);
        } else {
            func_L01_004450F0_003553A0(self, 1, -1);
        }
    case 1:
        id = v->id2;
        if (id == -1 || (m = (u8 *)((id << 8) + (s32)D_L19_001DF71C_003553A0), m[0x20] == 0xFE) || m[0x20] == 0xFD) {
            id = v->id3;
            if (id == -1 || (m = (u8 *)((id << 8) + (s32)D_L19_001DF71C_003553A0), m[0x20] == 0xFE) || m[0x20] == 0xFD) {
                func_L01_004450F0_003553A0(self, 2, -1);
            }
        }
        break;
    case 3:
        if (v->other == 0 || ((st = v->other[0x20]) != 0xFE && st != 0xFD)) {
            break;
        }
        if (v->id0 != -1) {
            func_L01_00456230(D_L19_001DF71C_003553A0 + (v->id0 << 8), 1);
        }
        if (v->id1 != -1) {
            func_L01_00456230(D_L19_001DF71C_003553A0 + (v->id1 << 8), 1);
        }
        func_003C4138(&v->timer, 0.0f, 0.019867551f);
        if (v->timer <= 0.0f) {
            func_L01_004450F0_003553A0(self, 4, -1);
        }
        break;
    }
    if (self[0x31] != 0 && v->timer > 0.0f) {
        if (v->count != 0) {
            cam = D_L19_001E2100;
            pos[0] = func_0038D098(func_0038DAB8(1.5707964f, *(f32 *)(cam + 0x18))) * D_L19_001DD6C4;
            pos[1] = func_0038D0B0(func_0038DAB8(1.5707964f, *(f32 *)(cam + 0x18))) * D_L19_001DD6C4;
            pos[2] = 0.0f;
            vec_add_ba(pos, pos, self + 0x10);
            pos[2] += D_L19_001DD6C0;
            func_L19_0045E1A8((u8 *)pos, self, v->count + 2, D_L19_001DD6B8, 0x20, 2, 0xFF, D_L19_001DD6BC);
        }
        if (v->timer > 0.0f) {
            func_L01_00404A10_003553A0(func_L19_003557B0, self);
        }
    }
    if (self[0x31] != 0) {
        func_L01_00451DB8(self, (u8 *)v + 0x20, 0x80909090, 0x80404040, 0.073303834f);
    }
}
/* localdecomp:end func_L19_003553A0 */
