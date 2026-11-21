/* functional: medium. VU0 vadd.xyz done as plain C (file lacks -mvu0-use-vf0-vf2; w preserved so equivalent); 292 diff; callee arg meanings (0038D000 = vec*matrix, 0038CF68 = normalize/scale) inferred from use; no gate coverage */
#include "vu0.h"
typedef struct { u8 p0[0x20]; u8 *f20; f32 f24; f32 f28; s32 f2C; u8 p30[0x10]; s32 f40[4]; } S_L01_002E68E0_00423068;
typedef struct { u8 p0[0x34]; s32 f34; u8 p38[0x18]; S_L01_002E68E0_00423068 *f50; u8 p54[0x14C]; u8 *list[1]; } G_00423068;
extern G_00423068 D_L01_001E6D80;
extern S_L01_002E68E0_00423068 D_L01_002E68E0;
extern u8 D_L01_001D6B00[];
extern u8 D_L01_001D6B40[];
extern u8 D_L01_001D6B80[];
extern f32 D_L01_001D6B94;
extern u8 D_L01_001D6AF5;
__asm__(".extern D_L01_001D6B94, 4");
__asm__(".extern D_L01_001D6AF5, 1");
extern void func_0038D308(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00404808(void *, s32);
extern void func_L01_00423530(void *, s32);
extern void func_L01_004234E8(void *, s32);
extern void func_L01_00423580(void);
extern void func_L01_00423690(void);

/* light/shadow projector setup: builds the 4 corner rays of the light frustum from the light a0
   (fov/size at 0x34), then the projected quads for object a4 into D_L01_002E68E0's buffer, queueing
   the draw callbacks; flag says whether the shadow state D_L01_001E6D80.f50 is kept */
void func_L01_00423068(u8 *a0, s32 *a1, s32 a2, s32 a3, u8 *a4, s32 a5, s32 a6) {
    s128 mtx[3] __attribute__((aligned(16)));
    s32 flag;
    s32 limit;
    s32 i;
    s32 cnt;
    s32 off;
    f32 f21;
    f32 f20;
    f32 sz;
    u8 *dst;
    u8 *tbl;
    vu0_v4 q __attribute__((aligned(16)));
    vu0_v4 tmp __attribute__((aligned(16)));
    S_L01_002E68E0_00423068 *s;

    limit = D_L01_001E6D80.f34;
    flag = 1;
    if (limit < (*(s32 *)(a0 + 0x38) * 5 + 2) / 6) {
        flag = 0;
    } else if ((*(s32 *)(a0 + 0x3C) * 5 + 2) / 6 < limit) {
        flag = 0;
    } else {
        f21 = -1.0f;
        s = &D_L01_002E68E0;
        if (s->f20 == 0) {
            s->f20 = D_L01_001D6B00;
        }
        func_0038D308(mtx, a0 + 0x20);
        off = a6 * 4;
        for (i = 0; i < 4; i++) {
            sz = *(f32 *)(a0 + 0x34);
            qzero(&q);
            q.y = sz;
            if (i < 2) {
                q.y = -sz;
            }
            if ((i & 1) == 0) {
                q.z = -1.0f;
            } else {
                q.z = 1.0f;
            }
            tmp = q;
            func_0038D000(D_L01_001D6B40 + i * 16, &tmp, mtx);
            if (f21 < 0.0f) {
                q = *(vu0_v4 *)(D_L01_001D6B40 + i * 16);
                func_0038CF68(&q, &q, 1.0f);
                f21 = 1.0f / fabs_asm(q.z);
            }
        }
        sz = *(f32 *)(a0 + 0x34);
        s->f24 = D_L01_001D6B94;
        s->f28 = 1.0f / sz;
        *(vu0_v4 *)s = *(vu0_v4 *)(a0 + 0x10);
        func_0038D000(D_L01_001D6B80, a0, mtx);
        if (a4 == 0) {
            a4 = D_L01_001E6D80.list[*(s32 *)(a0 + 0x40)];
        }
        f20 = *(f32 *)(a4 + 0x2C) / *(f32 *)(*(u8 **)(a4 + 0x24) + 0x24);
        for (i = 3, cnt = 0; i >= 0; i--, cnt++) {
            func_0038CF68(&tmp, D_L01_001D6B40 + cnt * 16, *(f32 *)(a0 + 0x30) * f21);
            dst = s->f20 + a6 * 64 + cnt * 16;
            func_0038D000(dst, &tmp, a4 + 0xC0);
            func_0038CE20(dst, dst, f20);
            ((f32 *)dst)[0] += ((f32 *)(a4 + 0x10))[0];
            ((f32 *)dst)[1] += ((f32 *)(a4 + 0x10))[1];
            ((f32 *)dst)[2] += ((f32 *)(a4 + 0x10))[2];
            ((f32 *)dst)[0] += ((f32 *)D_L01_001D6B80)[0];
            ((f32 *)dst)[1] += ((f32 *)D_L01_001D6B80)[1];
            ((f32 *)dst)[2] += ((f32 *)D_L01_001D6B80)[2];
        }
        if (a1 != 0) {
            if (limit < (a1[0] * 5 + 2) / 6) {
            } else if ((a1[1] * 5 + 2) / 6 < limit) {
            } else {
                func_L01_004234E8(s->f20 + a6 * 64, (s32)a1);
                func_L01_00404808((void *)func_L01_00423580, 0);
                if (a1[5] == 0) {
                    flag = 0;
                }
            }
        }
        if (a2 != 0 && a3 != 0) {
            func_L01_00423530(s->f20, a2);
            func_L01_00404808((void *)func_L01_00423690, 0);
            if (D_L01_001D6AF5 != 0) {
                flag = 0;
            }
        }
    }
    if (flag != 0 && *(s32 *)(a0 + 0x44) >= 0) {
        D_L01_001E6D80.f50 = &D_L01_002E68E0;
        for (i = 0; i < 4; i++) {
            s32 v = *(s32 *)(a0 + 0x44 + i * 4);
            if (v >= 0) {
                D_L01_001E6D80.f50->f40[i] = (s32)D_L01_001E6D80.list[v];
            } else {
                D_L01_001E6D80.f50->f40[i] = 0;
            }
        }
        D_L01_001E6D80.f50->f2C = a5;
    } else {
        D_L01_001E6D80.f50 = 0;
    }
}
