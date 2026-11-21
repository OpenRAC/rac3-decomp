#include "common.h"

/* NTSC-U counterpart of func_L40_0040CF88 (src/levels/shared/L40_0040A4D0.c) */
#include "vu0.h"
extern u8 *D_L40_002485DC;
#include "vu0.h"
extern s32 D_L40_002412AC[] __attribute__((section(".sdata")));
extern void func_L39_00669B68(s32 uid);
extern void func_L01_00441FB8(u8 *m, s32 state, s32 a2);
extern s32 func_L40_0053C768(u8 *m);
extern s32 D_L40_002412AC[] __attribute__((section(".sdata")));
extern s32 func_L40_0053C768(u8 *m);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L39_00669B68(s32);
extern s32 func_L40_0040C8B8(u8 *m, u8 *mb, s32 uid, s32 a3, s32 torso_hits);
extern void func_L01_00441FB8(u8 *m, s32 a1, s32 a2);

/* localdecomp:start func_L40_0040C8B8 */
__asm__(".extern D_L40_002485DC, 4");
extern u8 *D_L40_002485DC; /* the moby array */
extern void func_L01_004479A8(u8 *m);
extern void func_L39_00669B68(s32 uid);
extern u8 *func_L01_00444358(u8 *m, s32 kind, s32 a2);
extern u8 *func_L39_0061B038(u8 *m);
extern void func_003883C8(void *p);
extern void func_003BF4F8(u8 *m, void *mb);
extern f32 func_L01_004443B0(u8 *m, u8 *hit);
extern s32 func_L40_0053C768(u8 *m);
extern void func_L01_00452B20(u8 *m, u8 *x, u8 *tv);

typedef struct {
    u8 pad[0x1C];
    s32 (*same_team)(u8 *g, s32 team);
} GuberVt_40CF88;

/* The Ranger's damage: take the hit on the legs or the torso unless it is friendly fire,
   apply it to the health, die at 0 health or after 200 frames of it. */
s32 func_L40_0040C8B8(u8 *m, u8 *mb, s32 uid, s32 a3, s32 torso_hits) {
    u8 *v = *(u8 **)(m + 0x68);
    u8 *tv;
    u8 *x;
    u8 *hit;
    u8 *src;
    u8 *g;
    f32 dmg;
    f32 hv;
    s32 k;

    *(u8 **)(v + 0x2A0) = 0;
    tv = *(u8 **)(v + 0x0);
    x = *(u8 **)(v + 0x20);
    func_L01_004479A8(m);
    if (*(f32 *)(v + 0x30) <= 0.0f) {
        *(s32 *)(v + 0x2CC) += 1;
    }
    if (*(s32 *)(v + 0x2CC) > 200) {
        func_L39_00669B68(uid);
    }
    if (torso_hits) {
        hit = func_L01_00444358(m, 1, 0);
    } else {
        hit = func_L01_00444358(m, 0x10000, 0);
    }
    if (hit == 0) {
        if (torso_hits) {
            hit = func_L01_00444358(*(u8 **)(v + 0x270), 1, 0);
        } else {
            hit = func_L01_00444358(*(u8 **)(v + 0x270), 0x10000, 0);
        }
        if (hit == 0) {
            goto done;
        }
        *(u8 *)(*(u8 **)(v + 0x270) + 0xA8) = 0xFF;
    }
    if (*(u8 **)(hit + 0x20) != 0 && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1849 && *(u8 **)(*(u8 **)(hit + 0x20) + 0x68) != 0) {
        if (*(s32 *)(*(u8 **)(*(u8 **)(hit + 0x20) + 0x68) + 0x2C) == *(s32 *)(v + 0x2F0)) {
            hit = 0;
        }
    }
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        src = *(u8 **)(hit + 0x20);
        while (*(u8 **)(src + 0xB8) != 0) {
            src = *(u8 **)(src + 0xB8);
        }
        g = func_L39_0061B038(src);
        if (g != 0 && (*(GuberVt_40CF88 **)(g + 0x14))->same_team(g, *(s32 *)(v + 0x2F0))) {
            hit = 0;
            *(u8 *)(m + 0xA8) = 0xFF;
        }
        if (hit != 0) {
            *(u8 **)(v + 0x2A0) = src;
        }
    }
done:
    func_003883C8(v + 0x36);
    if (hit != 0) {
        if (*(s16 *)(v + 0x36) != 0) {
            hit = 0;
            *(u8 *)(m + 0xA8) = 0xFF;
        }
        if (hit != 0) {
            *(u8 *)(v + 0x167) = 0xC8;
            func_003BF4F8(m, v + 0x160);
            hv = *(f32 *)(hit + 0x2C);
            if (*(f32 *)(mb + 0xA8) != 0.0f && *(u8 **)(hit + 0x20) != 0 && *(s16 *)(m + 0xAA) == *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA)) {
                *(f32 *)(hit + 0x2C) = hv * *(f32 *)(mb + 0xA8);
            }
            *(s16 *)(v + 0x36) = 10;
            if (*(u8 **)(hit + 0x20) != 0 && *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x108F) {
                *(s16 *)(v + 0x36) = 0x3C;
            }
        }
    }
    dmg = func_L01_004443B0(m, hit);
    *(u8 *)(m + 0xA8) = 0xFF;
    *(f32 *)tv -= dmg;
    if (*(f32 *)(v + 0x30) <= 0.0f && func_L40_0053C768(m) != 0) {
        func_L01_00441FB8(m, *(u8 *)(mb + 0x10), *(u8 *)(mb + 0x48));
    }
    if (x != 0) {
        func_L01_00452B20(m, x, tv);
    }
    if (dmg == 0.0f) {
        return 0;
    }
    *(s16 *)(mb + 0x70) = -1;
    if (hit != 0 && *(u8 **)(hit + 0x20) != 0) {
        *(s16 *)(mb + 0x70) = (*(u8 **)(hit + 0x20) - D_L40_002485DC) >> 8;
    }
    k = *(s16 *)(tv + 4) * *(f32 *)(mb + 0x58) <= 0.0f ? 90 : 300;
    if (*(u8 *)(mb + 0x77) == 0) {
        if (k < abs_asm(D_L40_002412AC[0] - *(s32 *)(mb + 0x44))) {
            return 0;
        }
    } else {
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L40_0040C8B8 */
