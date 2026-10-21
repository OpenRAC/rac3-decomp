/* US draft of func_003F1F28 (rac3-uya-decomp func_003EC960, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003F1F28 */
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003ABDD8(u8 *, s32);
extern void func_003A4A78(f32, f32, f32, s32, f32 *, f32 *);
void func_003F1F28(O_3EC960 *a, f32 *b, f32 *out) {
    struct { s32 st[2]; f32 w[2]; } v;
    f32 one, cx, cy, sx, sy, dx, dy;
    f32 w0, w1;
    s32 r;
    v.st[0] = 0;
    v.st[1] = 0;
    func_003EDB40(a, &v.st[0], &v.st[1]);
    one = 1.0f;
    cx = a->f10;
    cy = a->f14;
    cx = (b[2] - b[0]) * cx + b[0];
    cy = (b[3] - b[1]) * cy + b[1];
    sy = 2.0f;
    sx = sy;
    dy = 0.0f;
    dx = dy;
    v.w[0] = one;
    v.w[1] = one;
    if (func_003EDAF8(a, 0x100)) {
        out[0] = dy;
        out[3] = one;
        out[2] = one;
        out[1] = dy;
        return;
    }
    if (v.st[0] != 3) {
        if (v.st[0] == 1) {
            sx = 2.0f;
            dx = 1.0f;
        } else {
            sx = 2.0f;
            dx = -1.0f;
        }
    }
    if (v.st[1] != 3) {
        if (v.st[1] == 2) {
            sy = 2.0f;
            dy = -1.0f;
        } else {
            sy = 2.0f;
            dy = 1.0f;
        }
    }
    r = func_003ABDD8(a->f44, a->f40);
    func_003A4A78(a->f18, a->f1C, a->f3C, r, &v.w[0], &v.w[1]);
    w0 = v.w[0] / D_001D9698;
    w1 = v.w[1] / D_001D969C;
    v.w[0] = w0;
    v.w[1] = w1;
    out[0] = cx - w0 / sx + dx * w0 / sx;
    out[1] = cy - w1 / sy + dy * w1 / sy;
    out[2] = out[0] + w0;
    out[3] = out[1] + w1;
}
/* localdecomp:end func_003F1F28 */
