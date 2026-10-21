/* US draft of func_003E3E40 (rac3-uya-decomp func_003DE8F0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E3E40 */
__asm__(".extern D_001D9550, 4");
__asm__(".extern D_001D9558, 4");

typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;

extern s32 D_001D9550;
extern f32 D_001D9558;
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern s32 D_00142668[];
extern s32 D_001DA7E8[2];
extern char D_001D9560[];

extern R_3DE8F0 *func_00382348(M_3DE8F0 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern s32 func_003E3E30(s32);
extern void func_003E5070(f32 *, f32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7B80_003E3E40(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);

void func_003E3E40(void) {
    s32 ammo, max, max2, d0, d1, d2, hund, color;
    f32 fammo, fmax, w2, x, t, b, v;
    f32 x0, y, x1;
    f32 sum;
    R_3DE8F0 *r;
    s16 h;

    ammo = D_1A4BE0->x2850;
    if ((D_1A4BE0->x25E4 ^ 1) == 0) {
        max = 4;
    } else {
        max = D_00142668[0];
    }
    max2 = max;
    if (D_1A4BE0->x25C4 == 0x31 && D_1A4BE0->x19E0 != 0) {
        h = D_1A4BE0->x19E0->xAA;
        if ((h == 0x1A17 || h == 0x107E) && (r = func_00382348(D_1A4BE0->x19E0)) != 0) {
            max2 = 100;
            ammo = r->f0 * 100.0f / r->h4;
        }
    }
    fammo = ammo;
    fmax = max2;
    if (!D_142CA0->x20) {
        f32 w;
        w = fammo / fmax * 0.230333f;
        func_003E5070(&w, 0.230333f);
        func_003E81F0(0x9000A, 0.230333f - w, 0.049333f);
        func_003E73B8(0x9000A, 0.61558104f, 0.0739995f);
        func_003E81F0(0x9000B, w, 0.049333f);
        func_003E73B8(0x9000B, 0.385248f, 0.0739995f);
        func_003E7A18(0x90008, 0);
    } else {
        f32 w;
        w = fammo / fmax * 0.226833f;
        func_003E5070(&w, 0.226833f);
        func_003E81F0(0x9000A, 0.226833f - w, 0.049333f);
        func_003E73B8(0x9000A, 0.587748f, 0.0739995f);
        func_003E81F0(0x9000B, w, 0.049333f);
        func_003E73B8(0x9000B, 0.360915f, 0.0739995f);
        func_003E7A18(0x90008, 1);
        func_003E73B8(0x90008, 0.598917f, 0.074f);
    }
    w2 = 0.09f;
    d0 = func_003E3E30(ammo % 10);
    d1 = func_003E3E30(ammo / 10 % 10);
    hund = ammo / 100 % 10 != 0;
    d2 = func_003E3E30(ammo / 100 % 10);
    func_003E7E48(0x90003, d0);
    func_003E7E48(0x90004, d1);
    func_003E7E48(0x90005, d2);
    func_003E7838(0x90005, 1, hund);
    if (hund) {
        w2 = 0.135f;
    }
    func_11B2E8(D_001DA7E8, D_001D9560, max2);
    x0 = 0.0f;
    x1 = 0.0f;
    func_003E7B80_003E3E40(0x90006, &x0, &y, &x1, &y);
    sum = w2 + (x1 - x0);
    t = 0.5f;
    if (D_142CA0->x20) {
        t = 0.475f;
    }
    x = t - sum * 0.5f;
    if (hund) {
        func_003E73B8(0x90005, x, 0.074f);
        x += 0.045f;
    }
    func_003E73B8(0x90004, x, 0.074f);
    x += 0.045f;
    func_003E73B8(0x90003, x, 0.074f);
    func_003E73B8(0x90006, x + 0.045f, 0.069f);
    if (fammo < fmax * 0.15f) {
        b = D_001D9558 + 0.05f;
        D_001D9558 = b;
        if (b >= 2.0f) {
            D_001D9558 = b - 2.0f;
        }
        D_001D9550++;
    } else {
        if (D_001D9558 > 1.0f) {
            D_001D9558 = 2.0f - D_001D9558;
        }
        D_001D9558 = D_001D9558 * 0.95f;
    }
    v = D_001D9558 > 1.0f ? 2.0f - D_001D9558 : D_001D9558;
    color = func_0038DBD8(0x8066CCFF, 0x60202080, (1.0f - func_0038D098(v * 3.1415927f)) * 0.5f);
    func_003E7D70(0x90003, color);
    func_003E7D70(0x90004, color);
    func_003E7D70(0x90005, color);
    func_003E7D70(0x90006, color);
}
/* localdecomp:end func_003E3E40 */
