#include "common.h"
#include "vu0.h"

typedef struct {u8 a[0x19E0];int f19E0;short f19E4;u8 b[0x25C0-0x19E6];u8 *f25C0;int f25C4;u8 c[0x280C-0x25C8];int f280C;} Hero;

/* localdecomp:start func_L09_003C6758 */
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_003D00C0(void);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern void func_L01_004EA040(void);
extern void func_L09_003C6188(void *);
extern void func_00388BD0(void *, void *);
extern void func_L01_00441FB8(void *, int, int);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388770(void *);
extern void func_003888F0(void *, void *, void *);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern vu0_v4 D_L09_001D9BA0 __attribute__((section(".sdata")));
__asm__(".extern D_L09_001D9BA0, 16");
extern f32 D_L09_001E2338[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001E2338, 16");
extern vu0_v4 D_L09_001DE910[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE910, 4");
extern u8 D_L09_001E9940[];
extern f32 D_L09_001DEA08[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DEA08, 16");
extern f32 D_L09_001DE9F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE9F8, 16");
extern Hero D_001A4BE0[];

/* the vehicle's four probe offsets */
static __inline__ vu0_v4 *probe_003C6758(s32 i) {
    return &D_L09_001DE910[i];
}

/* the last collision query's result */
static __inline__ u8 *coll_003C6758(void) {
    return D_L09_001E9940;
}

/* the probes' ground depths in the vehicle's state */
static __inline__ f32 *depth_003C6758(u8 *h) {
    return (f32 *)(h + 0x6B0);
}

void func_L09_003C6758(u8 *h) {
    vu0_v4 start, end, force, sample, gravity, local;
    s32 i;
    s32 offset;
    s32 was;
    u8 *params;
    u8 *body;
    f32 total;

    total = 0.0f;
    params = *(u8 **)(h + 0x6D0);
    was = h[0x713];
    body = *(u8 **)(params + 0x100);
    func_003886E8(&gravity, &D_L09_001D9BA0, -0.002f);
    qzero(&force);
    if (*(s32 *)(h + 0x7A8)) {
        *(f32 *)(body + 0x18) += *(f32 *)(h + 0x7A4);
        *(s32 *)(h + 0x7A8) = 0;
    }
    h[0x713] = 0;
    *(s16 *)(params + 0x128) = 1;
    for (i = 0, offset = 0; i < 4; offset += 4, i++) {
        s32 material, type;
        f32 distance, depth, fraction, strength;
        u8 *obj;
        u8 *coll;
        *(vu0_q *)&sample = *(vu0_q *)probe_003C6758(i);
        func_003888C8(&start, &sample, body + 0xC0);
        vec_add_ab(&start, &start, body + 0x10);
        *(vu0_q *)&end = *(vu0_q *)&start;
        start.z += 1.5f;
        end.z -= D_L09_001E2338[i];
        if (func_003CE740(&start, &end, 0xC24, body, 0)) {
            material = func_003D00C0();
            type = -1;
            coll = coll_003C6758();
            obj = *(u8 **)(coll + 0x18);
            if (obj) {
                type = *(s16 *)(obj + 0xAA);
            }
            if (type >= 0) {
                if (type == 0x1ADE) {
                    goto missed;
                }
                if (type == 0x1BAE) {
                    func_L01_00443938(obj, body, 1, coll + 0x20, params + 0xC0,
                                      *(f32 *)(params + 0x138) / *(f32 *)(*(u8 **)(h + 0x720) + 0xC) * 40.0f + 60.0f);
                }
            }
            if (!*(u8 **)(coll_003C6758() + 0x18) || type != 0x10C4) {
                if (material == 1 || material == 13 || material == 3 || material == 11) {
                    if (*(f32 *)(params + 0x130) > 0.0f) {
                        *(u16 *)(h + 0x710) |= 8;
                        if (D_001A4BE0[0].f19E0 == (s32)body) {
                            u8 *p;
                            D_001A4BE0[0].f280C = 0;
                            D_001A4BE0[0].f19E4 = -1;
                            D_001A4BE0[0].f19E0 = 0;
                            p = D_001A4BE0[0].f25C0;
                            *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
                            func_L01_004EA040();
                        }
                        func_L09_003C6188(body);
                        *(vu0_q *)(body + 0x10) = *(vu0_q *)(params + 0xE0);
                        *(vu0_q *)(body + 0xF0) = *(vu0_q *)(params + 0xF0);
                        func_00388BD0(body + 0xC0, body + 0xF0);
                        func_L01_00441FB8(body, 1, -1);
                        return;
                    }
                }
            }
            *(vu0_q *)&sample = *(vu0_q *)(D_L09_001E9940 + 0x40);
            func_00388830(&force, &sample, 1.0f);
            if (force.z < 0.707f) {
                continue;
            }
            if (h[0x715] == 1 && *(s16 *)(h + 0x71A) >= 0x2E && material == 5) {
                h[0x713] = 1;
            }
            *(s16 *)(params + 0x128) = 0;
            vec_sub_ba(&sample, D_L09_001E9940 + 0x20, &start);
            distance = func_00388770(&sample) - 1.5f;
            if (distance < 0.0f) {
                *(f32 *)(body + 0x18) -= distance;
                distance = 0.0f;
            }
            depth = *(f32 *)((u8 *)D_L09_001DEA08 + offset) - distance;
            func_003888F0(&local, &force, params);
            strength = D_L09_001E2338[i] - distance;
            fraction = strength / D_L09_001E2338[i];
            strength *= 0.025f;
            if (h[0x713] && i >= 2 && *(s16 *)(h + 0x71A) >= 0x2E) {
                strength *= 0.5f;
            }
            func_003886E8(&sample, &local, strength);
            vec_add_ba(h + 0x660 + i * 16, h + 0x660 + i * 16, &sample);
            func_003886E8(&sample, &D_L09_001D9BA0, strength * (fraction * 0.275f * fraction));
            vec_add_ab(h + 0x6A0, h + 0x6A0, &sample);
            *(f32 *)((u8 *)depth_003C6758(h) + offset) = depth;
        } else {
        missed:
            if (!was || *(s16 *)(params + 0x12A) >= 11) {
                vec_add_ab(h + 0x660 + i * 16, h + 0x660 + i * 16, &gravity);
            }
            func_003BEBF8((f32 *)(h + 0x6B0) + i, *(f32 *)((u8 *)D_L09_001DE9F8 + offset), 0.033333335f);
        }
        total += D_L09_001E2338[i] - *(f32 *)((u8 *)depth_003C6758(h) + offset);
    }
    if (was && *(s16 *)(params + 0x128) && *(s16 *)(params + 0x12A) < 0x2D) {
        h[0x713] = 1;
    }
    if (*(s16 *)(h + 0x754) == 0) {
        *(s32 *)(h + 0x7A8) = 1;
        func_003BEBF8((f32 *)(h + 0x7A4), (1.0f - total * 0.25f / D_L09_001E2338[0]) * -0.8f, 0.033333335f);
        *(f32 *)(body + 0x18) -= *(f32 *)(h + 0x7A4);
    }
}
/* localdecomp:end func_L09_003C6758 */
