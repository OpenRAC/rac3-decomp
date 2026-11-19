/* functional: high. Spawns a 0x40-byte particle (kind 0xB) with a random direction scaled by f13 offset from a1; same reads/writes/calls/order as retail; vector add done in plain C (xyz only, w left from the random-vector quad = 0) and quad copies as struct copies. */
/* localdecomp:start func_L39_005C6E90 */
typedef struct { f32 x, y, z, w; } L39V4_5C6E90;

extern f32 D_L39_0024BB48;
extern f32 D_L39_0024BB4C;
extern u8 *D_L39_00296844;

extern s32 func_L39_005B4398(s32);
extern f32 func_L39_005B4410(f32, f32);
extern void *func_003CD108(s32);
extern s32 func_0019D510(void);
extern void func_0038CF68(void *, void *, f32);

void *func_L39_005C6E90(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3, f32 f12, f32 f13) {
    u8 *o;
    u8 *p;
    L39V4_5C6E90 r, w;
    L39V4_5C6E90 *src;

    if (t0 == 0) {
        return 0;
    }
    if (0.85f < D_L39_0024BB48 || 0.85f < D_L39_0024BB4C) {
        if (func_L39_005B4398(3) == 0) {
            return 0;
        }
    }
    if (0.9f < D_L39_0024BB48 || 0.9f < D_L39_0024BB4C) {
        if (func_L39_005B4398(2) == 0) {
            return 0;
        }
    }
    if (1.0f < D_L39_0024BB48 || 1.0f < D_L39_0024BB4C) {
        if (func_L39_005B4398(1) == 0) {
            return 0;
        }
    }
    o = func_003CD108(0xB);
    if (o != 0) {
        *(L39V4_5C6E90 *)(o + 0x10) = *(L39V4_5C6E90 *)a0;
        *(s32 *)(o + 4) = a2;
        o[9] = 0xA4;
        o[3] = func_L39_005B4398(100) < 20 ? 0x44 : 0x48;
        o[1] = 0;
        p = o + 0x20;
        *(s32 *)(o + 0xC) = 0;
        o[8] = func_0019D510();
        o[2] = *D_L39_00296844;
        r.x = 0.0f;
        r.y = 0.0f;
        r.z = 0.0f;
        r.w = 0.0f;
        r.x = func_L39_005B4410(-1.0f, 1.0f);
        r.y = func_L39_005B4410(-1.0f, 1.0f);
        r.z = func_L39_005B4410(-1.0f, 1.0f);
        w = r;
        func_0038CF68(&w, &w, f13);
        src = (L39V4_5C6E90 *)a1;
        ((L39V4_5C6E90 *)(o + 0x20))->x = src->x + w.x;
        ((L39V4_5C6E90 *)(o + 0x20))->y = src->y + w.y;
        ((L39V4_5C6E90 *)(o + 0x20))->z = src->z + w.z;
        *(f32 *)(p + 0xC) = f13 * 0.75f;
        *(s16 *)(o + 0xA) = t0;
        p[0x19] = t3;
        p[0x1B] = t0;
        p[0x18] = t1;
        *(f32 *)(p + 0x1C) = f12;
        *(s32 *)(p + 0x10) = a2;
        *(s32 *)(p + 0x14) = a3;
        p[0x1A] = t2;
    }
    return o;
}
/* localdecomp:end func_L39_005C6E90 */
