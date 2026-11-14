#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_0032A4B0 */
typedef struct {
    s32 ids[5];
    s32 w14;
    u8 b18;
    u8 b19;
    u8 pad1A[6];
    vu0_v4 v20;
    vu0_v4 v30;
} St_0032A4B0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 pad21[0x13];
    u16 h34;
    u8 pad36[0x32];
    St_0032A4B0 *p68;
} Obj_0032A4B0;

extern u8 *D_001DFC1C_sda;
__asm__(".extern D_001DFC1C_sda, 4");
extern u8 *D_001DFD00_sda;
__asm__(".extern D_001DFD00_sda, 4");
extern vu0_v4 D_L05_001E2780;
extern void func_L05_0032A910(void *);
extern s32 func_L01_00452F60(void *);
extern void func_L05_0032AD10(void *);
extern void func_L01_00452F40(void *, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_L05_0032A970(void *, void *, void *, f32);
extern void func_L05_0032AA00(void *, void *, s32);
extern void func_003BD360(void *);

void func_L05_0032A4B0(Obj_0032A4B0 *a) {
    St_0032A4B0 *s;
    vu0_v4 w0;
    vu0_v4 w10;
    vu0_v4 w20;
    vu0_v4 w30;
    u8 *ent;
    u8 *child;
    f32 k;
    s32 i;
    s32 j;

    s = a->p68;
    func_L05_0032A910(a);
    switch (a->b20) {
    case 0:
        break;
    case 1:
        if (func_L01_00452F60(a) != 0) {
            for (i = 0; i < 5; i++) {
                if (s->ids[i] != -1) {
                    child = D_001DFC1C_sda;
                    child += s->ids[i] << 8;
                    *(u16 *)(child + 0x34) |= 0x100;
                    func_L05_0032AD10(child);
                    func_L01_00452F40(child, 1);
                }
            }
            func_0039FE80(1, 0, a);
            func_L01_00441FB8(a, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(a) != 0 && s->w14 != -1) {
            ent = (u8 *)((s->w14 << 7) + (s32)D_001DFD00_sda);
            vec_sub_ba(&s->v20, ent + 0x30, (u8 *)a + 0x10);
            s->v20.z = 0.0f;
            func_00388830(&s->v20, &s->v20, 1.0f);
            vec_sub_ba(&w0, &D_L05_001E2780, (u8 *)a + 0x10);
            w0.z = 0.0f;
            func_00388830(&w0, &w0, 1.0f);
            if (0.707f < func_00388730(&s->v20, &w0)) {
                func_00388758(&w10, &w0, &s->v20);
                w20 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
                w20.z = 1.0f;
                if (0.0f < w10.z) {
                    func_00388758(&w30, &w20, &w0);
                } else {
                    func_00388758(&w30, &w0, &w20);
                }
                vec_add_ab(&s->v20, &w30, &w0);
            }
            func_00388830(&s->v20, &s->v20, 0.10833334f);
            func_00388758(&s->v30, &s->v20, (u8 *)a + 0xE0);
        }
        if (s->b18 != 0) {
        w10 = (vu0_v4){0.0f, 0.0f, 0.0f, 0.0f};
        k = 0.027634382f;
        w10.x = s->v20.x;
        w10.y = s->v20.y;
        w0 = w10;
        w10 = s->v20;
        if (15.5f < a->v10.z) {
            func_L05_0032A970(a, a, &w10, k);
            if (a->v10.z <= 19.5f && !(s->b19 & 0x20)) {
                func_L05_0032AA00(a, a, 5);
            }
        }
        for (j = 0; j < 5; j++) {
            vec_add_ab(&w10, &w10, &w0);
            k = k * 0.85f;
            if (s->ids[j] != -1) {
                child = D_001DFC1C_sda + (s->ids[j] << 8);
                if (*(f32 *)(child + 0x18) <= 19.5f && (((s->b19 >> j) ^ 1) & 1)) {
                    func_L05_0032AA00(a, child, j);
                }
                if (*(f32 *)(child + 0x18) <= 15.5f) {
                    if ((s->b19 >> j) & 1) {
                        s->b18 = s->b18 & ~(1 << j);
                        func_003BD360(child);
                    }
                } else {
                    func_L05_0032A970(a, child, &w10, k);
                }
            }
        }
        s->v20.z = s->v20.z - 0.0027222224f;
        s->v20.x = s->v20.x * 0.98f;
        s->v20.y = s->v20.y * 0.98f;
        if (s->v20.z < -0.19f) {
            s->v20.z = -0.19f;
        }
        } else {
            func_L01_00441FB8(a, 3, -1);
        }
        break;
    case 3:
        func_003BD360(a);
        break;
    }
}
/* localdecomp:end func_L05_0032A4B0 */
