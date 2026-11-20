/* functional: high. Not byte-exact (about 730 words differ: SN saves registers with sq giving a 0x1d0 frame vs 0x190 here, float constants pooled, 0.16 literal rounds one ulp low); all 56 calls match retail in order and arguments. Written from the PAL assembly with no draft; parameters follow the EABI split (ints $4-$11 then stack: obj, unused, pos, sparks, clouds, puffs, slot_id, slot_flag, bursts, mul, type, req_flags; floats f12-f18: radius, req_f, light_range, glow_scale, light_dist, size, shock_scale), matching the L01_003B84E8.c caller. Unwritten fields of the 0x30-byte collision request (rec) are left as retail leaves them. D_L01_001E2A40/D_L01_002E9C40/D_L01_002E9C90 are accessed as byte blobs with the offsets retail uses. */
#include "vu0.h"

static void v3sub_0044AF78(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] - pb[0], y = pa[1] - pb[1], z = pa[2] - pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v3add_0044AF78(void *d, void *a, void *b) {
    f32 *pd = (f32 *)d, *pa = (f32 *)a, *pb = (f32 *)b;
    f32 x = pa[0] + pb[0], y = pa[1] + pb[1], z = pa[2] + pb[2];
    pd[0] = x; pd[1] = y; pd[2] = z;
}
static void v4copy_0044AF78(void *d, void *s) {
    f32 *pd = (f32 *)d, *ps = (f32 *)s;
    f32 x = ps[0], y = ps[1], z = ps[2], w = ps[3];
    pd[0] = x; pd[1] = y; pd[2] = z; pd[3] = w;
}
static f32 fabs_0044AF78(f32 x) { return x < 0.0f ? -x : x; }
extern s32 func_L01_00446748(u8 *, s32, s32, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u32 func_L01_00448D88(u32, s32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void *func_L01_00465738(void *, void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void *func_L01_00464690(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void *func_L01_00464210(void *, void *, s32, s32, s32, f32);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_002F9578(u8 *, u8 *, vu0_v4 *, s32, s32, s32, s32, s32, f32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern char *func_L01_003006C0(void *, void *, s32, void *);
extern f32 D_L01_001DFB4C;
extern f32 D_L01_001DFB50;
extern vu0_v4 D_L01_001E29C0[];
extern u8 D_L01_001E2A40[];
extern u8 D_001A3190[];
extern u8 D_L01_001D7BF8[];
extern u8 D_L01_001D7C10[];
extern u8 D_L01_002E9C40[];
extern u8 D_L01_002E9C90[];

typedef struct {
    u32 c[6];
} ColorTable_0044AF78;

void func_L01_0044AF78(u8 *obj, void *unused, vu0_v4 *pos, f32 radius, f32 req_f, f32 light_range, s32 sparks,
                       s32 clouds, s32 puffs, f32 glow_scale, f32 light_dist, s32 slot_id, s32 slot_flag,
                       f32 size, f32 shock_scale, s32 bursts, s32 mul, s32 type, s32 req_flags) {
    vu0_v4 up;
    vu0_v4 delta;
    vu0_v4 dir;
    ColorTable_0044AF78 tblA;
    ColorTable_0044AF78 tblB;
    vu0_v4 vel;
    f32 dist;
    f32 closeness;
    s32 i, n, c1, c2, r1, r2, k, hi;
    vu0_v4 rec_v[3];
    u8 *rec = (u8 *)rec_v;
    s32 r, g, b, ex, ex2;
    f32 t, speed, ang, pitch, cloud;

    *(vu0_q *)&up = 0;
    up.z = size * 0.16f;
    if (mul == -1 && 1.7f < D_L01_001DFB50 + D_L01_001DFB4C) {
        mul = 1;
    }
    if (pos == 0) {
        if (obj == 0) {
            return;
        }
        pos = (vu0_v4 *)(obj + 0x10);
    }
    if (0.0f < radius) {
        func_L01_00446748(rec, (s32)obj, req_flags, req_f);
        rec[0x18] = 2;
        *(u16 *)(rec + 0x1A) = *(u16 *)(obj + 0xAA);
        rec[0x19] = 1;
        func_003D4D00(pos, 0x10, obj, rec, radius);
    }
    if (sparks > 0) {
        n = sparks;
        do {
            n--;
            pitch = func_003824E0(0.2617993950843811f, 1.3962633609771729f);
            ang = func_00382538();
            t = func_003824E0(7.0f, 10.5f);
            func_00382760(&delta, size * (t * 0.020000001415610313f), ang, pitch);
            delta.z += 0.06000000238418579f;
            c1 = func_L01_00448D88(0x4F007FFF, type);
            c2 = func_L01_00448D88(0x1F00007F, type);
            r1 = func_00382498(0x32, 0x64);
            func_L01_00465738(pos, &delta, c1, c2, r1 - mul * 10, 1, -1, -1, 0, size * 40000.0f);
        } while (n != 0);
    }
    v3sub_0044AF78(&delta, &D_L01_001E29C0[0], pos);
    dist = func_0038CEA8(&delta);
    if (bursts != 0) {
        *(vu0_q *)&dir = 0;
        dir.x = func_003824E0(-1.0f, 1.0f);
        dir.y = func_003824E0(-1.0f, 1.0f);
        dir.z = func_003824E0(-1.0f, 1.0f);
        *(vu0_q *)&vel = *(vu0_q *)&dir;
        if (dist < 14.0f) {
            delta.z += dist * 0.5f;
            func_0038CF68(&vel, &vel, (dist / 5.0f) * 0.020000001415610313f);
            func_0038CF68(&delta, &delta, (dist + dist) * 0.020000001415610313f);
            v3add_0044AF78(&vel, &vel, &delta);
            func_L01_0040E6B8(&vel, &vel, 0.20000001788139343f);
            func_L01_002FB660(pos, &vel, func_00382498(50, 75), 0, 0, 0);
        }
        bursts--;
        if (bursts > 0) {
            i = 0;
            do {
                k = 1;
                pitch = func_003824E0(0.2617993950843811f, 1.3089969158172607f);
                ang = func_00382538();
                t = func_003824E0(7.0f, 10.5f);
                func_00382760(&dir, size * (t * 0.020000001415610313f), ang, pitch);
                hi = i % 3;
                dir.z += 0.04000000283122063f;
                i++;
                if (hi != 0) {
                    k = 0;
                }
                func_L01_002FB660(pos, &dir, func_00382498(0x32, 0x4B), k, 0, 0);
            } while (i < bursts);
        }
    }
    n = clouds;
    if (dist < (f32)clouds + (f32)clouds) {
        n = (s32)dist / 2;
    }
    closeness = 0.0f;
    if (dist < 7.0f) {
        closeness = 7.0f - dist;
    }
    if (n > 0) {
        do {
            n--;
            t = func_003824E0(8.0f, 10.0f);
            speed = t * 0.020000001415610313f;
            cloud = closeness * 0.020000001415610313f;
            tblA = *(ColorTable_0044AF78 *)D_L01_001D7BF8;
            tblB = *(ColorTable_0044AF78 *)D_L01_001D7C10;
            speed = (speed - cloud) * size;
            c1 = func_L01_00448D88(tblA.c[func_00382468(6)], type);
            c2 = func_L01_00448D88(tblB.c[func_00382468(6)], type);
            t = size * 400000.0f;
            r1 = func_00382498(12, 17);
            r2 = func_00382498(0x19, 0x25);
            func_L01_00464690(pos, &up, c1, c2, r1 - mul * 3, r2 - mul * 5, 0, 0, t, speed);
            r1 = func_00382498(4, 8);
            r2 = func_00382498(12, 17);
            func_L01_00464690(pos, &up, 0x7FFFFFFF, 0xFFFFFF, r1 - mul * 2, r2 - mul * 3, 0, 0, t, speed * 0.5f);
        } while (n != 0);
    }
    if (puffs > 0) {
        n = puffs;
        do {
            tblA = *(ColorTable_0044AF78 *)D_L01_001D7BF8;
            tblB = *(ColorTable_0044AF78 *)D_L01_001D7C10;
            *(vu0_q *)&dir = 0;
            n--;
            dir.x = func_003824E0(-1.0f, 1.0f);
            dir.y = func_003824E0(-1.0f, 1.0f);
            dir.z = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)&vel = *(vu0_q *)&dir;
            func_0038CF68(&vel, &vel, size * (func_003824E0(0.0f, 3.0f) * 0.020000001415610313f));
            c1 = func_L01_00448D88(tblA.c[func_00382468(6)], type);
            c2 = func_L01_00448D88(tblB.c[func_00382468(6)], type);
            func_L01_00464210(pos, &vel, c1, c2, func_00382498(0x19, 0x25) - mul * 5, 200000.0f);
        } while (n != 0);
    }
    if (obj != 0) {
        if (0.0f < light_range) {
            r = 0x96;
            g = 0x96;
            b = 0x96;
            ex = 0x7F;
            ex2 = 0x7F;
            i = 0;
            if (type != 0) {
                if (type & 4) {
                    r = 0x23;
                    g = 0;
                    b = 0xFA;
                    ex = 0x20;
                    ex2 = 0;
                    i = 0x64;
                } else {
                    r = 0x46;
                    b = 0x46;
                    ex = 0x3C;
                }
            }
            if (D_L01_001DFB4C < 0.949999988079071f) {
                if (light_dist < dist) {
                    func_L01_002F9578(obj, (u8 *)pos, &up, 0xD, r, g, b, 0x20, light_range);
                    func_L01_002F9578(obj, (u8 *)pos, &up, 0x12, ex & 0xFF, ex2 & 0xFF, i + 0x50, 0x20, light_range);
                }
            }
            func_L01_002F9578(obj, (u8 *)pos, &up, 0x19, ex & 0xFF, ex2 & 0xFF, i, 0x30, light_range);
        }
        if (0.0f < glow_scale) {
            func_L01_002F9578(obj, (u8 *)pos, &up, 0x16, 0xFF, 0xFF, 0xFF, 0x20, glow_scale);
        }
    }
    if (slot_flag != 0) {
        *(vu0_q *)&delta = *(vu0_q *)pos;
        delta.w = 2.0f;
        if (func_0038DC20(&delta, 10.0f) != -1) {
            if (dist < 20.0f) {
                *(f32 *)(D_L01_001E2A40 + 0x20) = 0.4000000059604645f - dist * 0.017500000074505806f;
            } else {
                *(f32 *)(D_L01_001E2A40 + 0x20) = 0.050000011920928955f;
            }
            *(s32 *)(D_L01_001E2A40 + 0x28) = 0x15;
            *(s32 *)(D_L01_001E2A40 + 0x2C) = 0;
        }
    }
    if (obj != 0 && slot_id != -1) {
        k = func_003A52A0(slot_id, 0, obj);
        if (k != -1) {
            u8 *base = D_001A3190 + (k << 7) - 0xE0;
            *(vu0_q *)(base + 0xE0) = *(vu0_q *)pos;
            *(s32 *)(base + 0xDC) = 0;
            *(s32 *)(base + 0x118) = 0;
        }
    }
    if (shock_scale != 0.0f && mul == 0) {
        *(vu0_q *)&delta = *(vu0_q *)pos;
        delta.w = shock_scale;
        if (func_0038DC20(&delta, 100.0f) != -1) {
            if (0.0f < shock_scale) {
                *(f32 *)(D_L01_002E9C40 + 0x20) = shock_scale;
                *(f32 *)(D_L01_002E9C40 + 0x24) = shock_scale;
                *(f32 *)(D_L01_002E9C40 + 0x28) = shock_scale;
            } else {
                *(f32 *)(D_L01_002E9C40 + 0x20) = 15.0f;
                *(f32 *)(D_L01_002E9C40 + 0x24) = 15.0f;
                *(f32 *)(D_L01_002E9C40 + 0x28) = 15.0f;
            }
            if (type != 0) {
                func_L01_003006C0(D_L01_002E9C90, pos, 0, 0);
            } else {
                func_L01_003006C0(D_L01_002E9C40, pos, 0, 0);
            }
        }
    }
}
