/* functional: high. vsub.xyz written as plain float subtraction (d.xyz = e.xyz - p.xyz, w set to 1.0 as retail does before the call); same reads, calls and order as retail, different register allocation and frame. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003F7350;
extern u8 *D_L01_001DF840;
__asm__(".extern D_L01_001DF840, 16");
extern f32 func_0038CED8(void *);
extern s32 func_L01_003F7490(void *pos, void *e, f32 r);

u8 *func_L01_003F7350(void *pos, f32 radius) {
    V4_003F7350 p;
    V4_003F7350 d;
    s32 xi;
    s32 yi;
    u8 *grid;
    u8 *cell;
    u8 *e;
    s32 off;
    s32 i;
    void *pp = &p;
    p = *(V4_003F7350 *)pos;
    xi = (s32)(p.x * 0.0625f);
    yi = (s32)(p.y * 0.0625f);
    if (xi < 0 || yi < 0 || xi >= 0x41 || yi >= 0x41) {
        return 0;
    }
    grid = D_L01_001DF840;
    off = *(s32 *)(grid + ((yi * 64 + xi) << 2));
    if (off == 0) {
        return 0;
    }
    cell = grid + off;
    if (*(s32 *)cell <= 0) {
        return 0;
    }
    e = cell + 0x10;
    for (i = 0; i < *(s32 *)cell; i++) {
        f32 len;
        d.x = ((f32 *)e)[0] - p.x;
        d.y = ((f32 *)e)[1] - p.y;
        d.z = ((f32 *)e)[2] - p.z;
        d.w = 1.0f;
        len = func_0038CED8(&d);
        if (len < *(f32 *)(e + 0xC) + radius) {
            if (func_L01_003F7490(pp, e, radius) != 0) {
                return e;
            }
        }
        e += 0x30;
    }
    return 0;
}
