/* Near miss of func_003F22E0 with its file's own flags: tools/check.py reports 46 diff
   (the version it replaces: 53).
   What differs: the C is done: it now compiles to retail byte for byte except the 12 `nop`s
   retail pads in front of its six `div.s` (2 before each) - gcc never emits them,
   tools/asm_filter.py re-inserts them from config/boot_elf/divs_nops.txt, whose line still
   carries the NTSC name (`func_003F2120 2 2 2 2 2 2`) instead of the PAL `func_003F22E0`, so
   the PAL function gets no padding (that one config line, outside work/, is all that is left);
   the two real PAL fixes are in the C: the callee is func_003AA380 (US func_003AA238) and the
   constants are loaded %hi/%lo (lui $at,0x1e / lwc1 -0x6968($at)) by using...
*/

/* PAL candidate for func_003F22E0 (boot_elf/text/3F1FB0.c).
   Started from the US draft (rac3-uya-decomp func_003F2120), which the US
   matched only with the single-function @ps2as override.  Two PAL changes:

   - The callee is func_003AA380 in PAL (the US address of func_003AA238).
   - The two constants are loaded with %hi/%lo in retail.  A plain
     `extern f32 D_001D9698;` is small (-G8), so gcc addresses it through
     $gp and the default assembler keeps one word; retail expands the load
     into lui/%lo.  Declaring the constants as arrays (unknown size) keeps
     gcc on the %hi/%lo path, the same trick the neighbouring func_003F2158
     uses with its D_*_003F2158[] aliases.

   The compiled code is now byte-identical to retail except for the 12 `nop`s
   retail pads in front of its six `div.s` (2 each).  gcc never emits them and
   neither assembler keeps them; tools/asm_filter.py puts them back from
   config/boot_elf/divs_nops.txt, whose entry still carries the NTSC name
   (func_003F2120 2 2 2 2 2 2) instead of the PAL one, so the PAL function
   gets no padding.  With the line `func_003F22E0 2 2 2 2 2 2` in that table
   the function matches (544 bytes). */

typedef struct { u8 p0[0x10]; f32 f10; f32 f14; f32 f18; f32 f1C; u8 p1[0x1C]; f32 f3C; s32 f40; u8 *f44; } O_3EC960;
extern s32 func_003AC190(u8 *, s32);
extern void func_003AA380(f32, f32, f32, s32, f32 *, f32 *);
void func_003F22E0(O_3EC960 *a, f32 *b, f32 *out) {
    struct { s32 st[2]; f32 w[2]; } v;
    f32 one, cx, cy, sx, sy, dx, dy;
    f32 w0, w1;
    s32 r;
    v.st[0] = 0;
    v.st[1] = 0;
    func_003EDEF8(a, &v.st[0], &v.st[1]);
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
    if (func_003EDEB0(a, 0x100)) {
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
    r = func_003AC190(a->f44, a->f40);
    func_003AA380(a->f18, a->f1C, a->f3C, r, &v.w[0], &v.w[1]);
    w0 = v.w[0] / D_001D9698_003F2158[0];
    w1 = v.w[1] / D_001D969C_003F2158[0];
    v.w[0] = w0;
    v.w[1] = w1;
    out[0] = cx - w0 / sx + dx * w0 / sx;
    out[1] = cy - w1 / sy + dy * w1 / sy;
    out[2] = out[0] + w0;
    out[3] = out[1] + w1;
}
