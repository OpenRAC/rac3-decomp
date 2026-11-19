/* functional: high. Allocates a 0x40-byte effect object (func_003CD108(0x40)) and fills it: kind byte 0x21, position quad from a0, velocity quad from a1 at +0x20, life/colour fields from the arguments, brightness byte random in 0..255; same writes/calls in retail order (the +0xC store is in the call's delay slot, so it precedes the call). */
/* localdecomp:start func_L39_005CE670 */
typedef struct { f32 x, y, z, w; } L39V4_5CE670;

extern u8 *D_L39_00296918;
extern void *func_003CD108(s32);
extern f32 func_L39_005B4410(f32, f32);

void *func_L39_005CE670(void *a0, void *a1, s32 a2, s32 a3, s32 t0, s32 t1, f32 f12, f32 f13, f32 f14) {
    u8 *o;
    u8 *q;

    o = func_003CD108(0x40);
    if (o != 0) {
        o[9] = 0x21;
        q = o + 0x20;
        *(L39V4_5CE670 *)(o + 0x10) = *(L39V4_5CE670 *)a0;
        o[3] = t1 != 0 ? 0x48 : 0x44;
        o[1] = 0;
        o[2] = D_L39_00296918[1];
        *(s32 *)(o + 4) = a3;
        *(f32 *)(o + 0xC) = f12 * 210000.0f;
        o[8] = (s32)func_L39_005B4410(0.0f, 255.0f);
        *(s16 *)(o + 0xA) = a2;
        *(L39V4_5CE670 *)q = *(L39V4_5CE670 *)a1;
        *(s32 *)(q + 0x18) = t0;
        *(f32 *)(q + 0x10) = f13;
        *(f32 *)(q + 0x14) = f14;
    }
    return o;
}
/* localdecomp:end func_L39_005CE670 */
