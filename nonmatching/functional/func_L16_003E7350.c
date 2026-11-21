/* functional: medium. Written from the retail asm (no draft): all branches, gp slots (D_L16_001DF4F4..538, 560, 5A0) and callee arguments traced by hand; vadd.xyz is written as plain float adds (retail leaves w alone, and w holds the angle/life here: preserved or restored as retail does); the 32x repeated colour store at the end is kept as retail has it (idempotent). Needs the file's @ps2as/vu0 flags only for byte matching. Types are local to this snippet (E/St_003E7350): they duplicate E_003E7C00/St_003E7C00 later in the file, so the lead should reuse those and drop mine when landing. */
#include "common.h"
#include "vu0.h"

/* Kerwan lightning-bolt ring: 32 entries of 0xB0 bytes in D_002A3830, starting at st->first. */
extern f32 D_L16_001DF4F4;
__asm__(".extern D_L16_001DF4F4, 4");
extern s32 D_L16_001DF4F8;
__asm__(".extern D_L16_001DF4F8, 4");
extern s32 D_L16_001DF4FC;
__asm__(".extern D_L16_001DF4FC, 4");
extern s32 D_L16_001DF500;
__asm__(".extern D_L16_001DF500, 4");
extern s32 D_L16_001DF504;
__asm__(".extern D_L16_001DF504, 4");
extern s32 D_L16_001DF508;
__asm__(".extern D_L16_001DF508, 4");
extern f32 D_L16_001DF510;
__asm__(".extern D_L16_001DF510, 4");
extern f32 D_L16_001DF514;
__asm__(".extern D_L16_001DF514, 4");
extern f32 D_L16_001DF518;
__asm__(".extern D_L16_001DF518, 4");
extern f32 D_L16_001DF51C;
__asm__(".extern D_L16_001DF51C, 4");
extern f32 D_L16_001DF520;
__asm__(".extern D_L16_001DF520, 4");
extern s32 D_L16_001DF524;
__asm__(".extern D_L16_001DF524, 4");
extern f32 D_L16_001DF528;
__asm__(".extern D_L16_001DF528, 4");
extern f32 D_L16_001DF52C;
__asm__(".extern D_L16_001DF52C, 4");
extern f32 D_L16_001DF530;
__asm__(".extern D_L16_001DF530, 4");
extern f32 D_L16_001DF534;
__asm__(".extern D_L16_001DF534, 4");
extern f32 D_L16_001DF538;
__asm__(".extern D_L16_001DF538, 4");
extern s32 D_L16_001DF560;
__asm__(".extern D_L16_001DF560, 4");
extern s32 D_L16_001DF5A0;
__asm__(".extern D_L16_001DF5A0, 4");
extern vu0_v4 D_L16_001E98E0;

typedef struct {
    vu0_v4 p0;          /* position; p0.w (entry +0xC) is the angle / life */
    vu0_v4 p1;          /* second point; p1.w (entry +0x1C) is the second angle */
    s32 c20, c24, c28, c2C;
    u8 pad30[0xB0 - 0x30];
} Ent_003E7350;
extern Ent_003E7350 D_002A3830[];

typedef struct {
    f32 scale;
    u8 pad4[0x14];
    f32 size;
    s32 first;
    u8 pad20[0x10];
    vu0_v4 off;
} St_003E7350;

extern void func_L01_0040C7A0(void *, void *);
extern void func_L01_0040C8A0(void *, void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L16_003E7350(u8 *obj, vu0_v4 *delta, s32 init) {
    St_003E7350 *st = *(St_003E7350 **)(obj + 0x68);
    Ent_003E7350 *e;
    vu0_v4 v, v2, w0, w1;
    f32 scale = D_L16_001DF4F4;
    f32 lim, ang, r, s, a, b;
    s32 i, j, k, need, miss, col1, col2;

    if (obj[0x20] == 2) {
        if (init) {
            for (i = 0; i < 32; i++) {
                e = &D_002A3830[st->first + i];
                func_L01_0040C7A0(e, &D_L16_001DF560);
                a = (f32)i * 3.1415927f;
                a = a + a;
                e->p0.w = func_0038DB48(a * 0.03125f);
                a = (f32)(i + 1) * 3.1415927f;
                a = a + a;
                e->p1.w = func_0038DB48(a * 0.03125f);
            }
        }
        for (i = 0; i < 32; i++) {
            e = &D_002A3830[st->first + i];
            a = e->p0.w;
            b = e->p1.w;
            v.x = func_0038D098(a) * st->size;
            v.y = func_0038D0B0(a) * st->size;
            v.z = 0.0f;
            e->p0.x = *(f32 *)(obj + 0x10) + v.x;
            e->p0.y = *(f32 *)(obj + 0x14) + v.y;
            e->p0.z = *(f32 *)(obj + 0x18) + v.z;
            e->p0.w = a;
            v.x = func_0038D098(b) * st->size;
            v.y = func_0038D0B0(b) * st->size;
            v.z = 0.0f;
            e->p1.x = *(f32 *)(obj + 0x10) + v.x;
            e->p1.y = *(f32 *)(obj + 0x14) + v.y;
            e->p1.z = *(f32 *)(obj + 0x18) + v.z;
            e->p1.w = b;
        }
    } else {
        lim = scale * st->size;
        lim = lim * lim;
        for (i = 0; i < 32; i++) {
            e = &D_002A3830[st->first + i];
            need = 0;
            if (e->p0.w <= 0.0f) {
                e->p0.x += delta->x;
                e->p0.y += delta->y;
                e->p0.z += delta->z;
                e->p1.x += st->off.x;
                e->p1.y += st->off.y;
                e->p1.z += st->off.z;
                need = lim < func_L01_0040E570(e, &e->p1);
            } else {
                e->p0.x += delta->x;
                e->p0.y += delta->y;
                e->p0.z += delta->z;
                e->p1.x += delta->x;
                e->p1.y += delta->y;
                e->p1.z += delta->z;
                e->p0.w -= 1.0f;
                need = e->p0.w <= 0.0f;
            }
            if (init == 0 && need == 0)
                continue;

            r = func_00382538();
            s = func_00382538();
            func_00382760(&v, st->size * 0.5f * st->scale, r, s);
            v.x += *(f32 *)(obj + 0x10);
            v.y += *(f32 *)(obj + 0x14);
            v.z += *(f32 *)(obj + 0x18);
            func_00382760(&v2, scale * st->size * st->scale, r, s);
            v2.x += v.x;
            v2.y += v.y;
            v2.z += v.z;
            miss = func_00382468(D_L16_001DF508) == 0;
            if (miss && func_003D3CB0(&v, &v2, 0, 0, 0) != 0) {
                e->p0 = v;
                e->p1 = D_L16_001E98E0;
                e->p0.w = 0.0f;
                func_L01_0040C7A0(e, &D_L16_001DF560);
                if (D_L16_001DF524 > 0) {
                    j = 0;
                    do {
                        j++;
                        r = func_00382538();
                        s = func_003824E0(D_L16_001DF528, D_L16_001DF52C);
                        w0.x = func_0038D098(r) * s;
                        w0.y = func_0038D0B0(r) * s;
                        w0.z = func_003824E0(D_L16_001DF530, D_L16_001DF534);
                        w0.w = D_L16_001DF538;
                        w1 = w0;
                        w1.z -= 0.086f;
                        col1 = func_0038DBD8(0x80081620, 0x80102540, func_003824E0(0.0f, 1.0f));
                        col2 = func_0038DBD8(0x60081620, 0x60102540, func_003824E0(0.0f, 1.0f));
                        func_L01_00463378(&e->p1, &w0, &w1, col1, col2, 8, 0x1D, 6, 0x1003C);
                    } while (j < D_L16_001DF524);
                }
            } else {
                e->p0 = v;
                ang = func_003824E0(D_L16_001DF510, D_L16_001DF514);
                if (miss)
                    ang += D_L16_001DF518;
                else
                    ang += 0.0f;
                func_003C4098(&e->p1, &v, &v2, ang);
                e->p0.w = func_003824E0(D_L16_001DF51C, D_L16_001DF520);
                func_L01_0040C7A0(e, &D_L16_001DF5A0);
            }
            for (k = 31; k >= 0; k--) {
                if (st->size < 0.5f) {
                    e->c20 = D_L16_001DF500;
                    e->c24 = D_L16_001DF500;
                    e->c24 &= 0xFFFFFF;
                    e->c28 = D_L16_001DF504;
                    e->c2C = D_L16_001DF504;
                } else {
                    e->c20 = D_L16_001DF4F8;
                    e->c24 = D_L16_001DF4F8;
                    e->c24 &= 0xFFFFFF;
                    e->c28 = D_L16_001DF4FC;
                    e->c2C = D_L16_001DF4FC;
                }
                e->c2C &= 0xFFFFFF;
            }
        }
    }
    for (i = 0; i < 32; i++) {
        e = &D_002A3830[st->first + i];
        if (obj[0x20] == 2 || e->p0.w <= 0.0f)
            func_L01_0040C8A0(e, &D_L16_001DF560);
        else
            func_L01_0040C8A0(e, &D_L16_001DF5A0);
    }
}
