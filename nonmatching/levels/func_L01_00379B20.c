/* Near miss (18 differing words of 365): func_L01_00379B20, holo_wall_draw_v1 in open-rac-engine.
 * Needs the file built with split addresses (it is, since 2026-11-14). Everything matches except the three
 * full-alpha fades (the ones that scale by (f32)al): retail keeps al in $v1 and a >> 7 in $a0, this C gets
 * $a0 and $v1 (the 47.0f/143.0f fades have them this way round in retail too, and match). Tried: a >>= 7,
 * no a variable, a ?: for the clamp, a separate 0x7F local for the conversion (same bytes or worse); a
 * function-level a (al right, then rgb $a0 and a $a1); the shared inline of holo_hit_draw_v3 (folds 127.0f
 * and hoists 143.0f). */
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];       /* 0x10 */
    u8 pad20[0x68 - 0x20];
    u8 *state;        /* 0x68 */
} M_379B20;

typedef struct {
    u8 pad0[0x34];
    f32 roll34;
    f32 roll38;
    f32 roll3c;
    u8 pad40[4];
    f32 roll44;
    f32 roll48;
    f32 roll4c;
} W_379B20;

extern f32 D_L01_001DDB14;   /* near distance of the fade-in */
extern f32 D_L01_001DDB18;   /* far distance of the fade-in */
extern f32 D_L01_001DDB1C;
extern f32 D_L01_001DDB20;
extern s32 D_L01_001DDB44;
extern s32 D_L01_001DDB48;
extern s32 D_L01_001DDB4C;
extern s32 D_L01_001DDB50;
extern s32 D_L01_001DDB54;
extern u8 D_L01_001E29C0[];
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);

/* holo_wall_draw_v1: draw the standing Holo Shield's wall (V1-V2) */
void func_L01_00379B20(M_379B20 *obj) {
    f32 *q1, *q2, *q3;
    W_379B20 *w = (W_379B20 *)obj->state;
    f32 dist;
    f32 t;
    f32 fade1;
    f32 fade2;
    u32 ca, cb, cc, cd;
    unsigned long a;
    u8 b;
    s32 al;
    u32 rgb;

    w->roll44 = func_0038DAB8(w->roll44, func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    w->roll34 = func_0038DAB8(w->roll34, func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    w->roll48 = func_0038DAB8(w->roll48, func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    w->roll38 = func_0038DAB8(w->roll38, func_003824E0(1.5f, 2.5f) * 0.017453292f);
    w->roll4c = func_0038DAB8(w->roll4c, func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    w->roll3c = func_0038DAB8(w->roll3c, func_003824E0(0.5f, 1.5f) * 0.017453292f);
    dist = func_L01_0040E570(obj->pos, D_L01_001E29C0);
    if (dist < D_L01_001DDB18) {
        t = (dist - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    } else {
        t = 1.0f;
    }
    fade1 = t < 0.0f ? 0.0f : t;
    if (dist < D_L01_001DDB20) {
        t = (dist - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    } else {
        t = 1.0f;
    }
    fade2 = t < 0.0f ? 0.0f : t;
    if (D_L01_001DDB44 != 0) {
        func_L01_0037BE80(obj, obj->pos, 71, 72, 0x8FFF0032, 1.0f, 1.0f, 1.7f, w->roll44, w->roll34, 0.0f, 0);
    }
    if (fade1 > 0.0f && D_L01_001DDB48 != 0) {
        ca = 0x2F804020;
        if (fade1 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fade1 * 47.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            ca = (al << 24) | 0x804020;
        }
        q1 = obj->pos;
        func_L01_0037BCF8(obj, q1, 27, ca, 1, 1.15f, 0.0f, w->roll34);
        func_L01_0037BCF8(obj, q1, 27, ca, 1, 1.15f, 0.0f, w->roll38);
    }
    if (fade2 > 0.0f && D_L01_001DDB4C != 0) {
        cb = 0x7FFF0032;
        if (fade2 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)((f32)al * fade2);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cb = (al << 24) | 0xFF0032;
        }
        q2 = obj->pos;
        func_L01_0037BCF8(obj, q2, 76, cb, 1, 0.5f, 0.0f, -w->roll38);
        cb = 0x7F300505;
        if (fade2 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)((f32)al * fade2);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cb = (al << 24) | 0x300505;
        }
        func_L01_0037BCF8(obj, q2, 76, cb, 1, 0.2f, 0.0f, w->roll38);
    }
    if (fade1 > 0.0f && D_L01_001DDB50 != 0) {
        cc = 0x8F804020;
        if (fade1 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fade1 * 143.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cc = (al << 24) | 0x804020;
        }
        q3 = obj->pos;
        func_L01_0037BE80(obj, q3, 71, 72, cc, 1.0f, 1.0f, 1.7f, w->roll48, w->roll38, 0.05f, 0);
        cc = 0x8F20207F;
        if (fade1 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)(fade1 * 143.0f);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cc = (al << 24) | 0x20207F;
        }
        func_L01_0037BE80(obj, q3, 71, 72, cc, 1.0f, 1.0f, 1.7f, w->roll4c, w->roll3c, 0.1f, 0);
    }
    if (fade2 > 0.0f && D_L01_001DDB54 != 0) {
        cd = 0x7F204080;
        if (fade2 != 1.0f) {
            s32 al = 0x7F;
            u8 b = (s32)((f32)al * fade2);
            unsigned long a = b;
            if ((a >> 7) == 0) {
                al = b;
            }
            cd = (al << 24) | 0x204080;
        }
        func_L01_0037BCF8(obj, obj->pos, 75, cd, 0, 0.6f, 0.0f, w->roll34);
    }
}
