#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L01_003AF290);

/* localdecomp:start func_L01_003B0498 */
typedef struct { u8 p0[0x18]; f32 f18; } T18;
typedef struct { u8 p0[0x98]; s32 f98; u8 p9C[0xE]; s16 hAA; } R;
typedef struct { u8 p0[0x18]; f32 f18; u8 p1C[4]; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[0x3D]; u8 b6F; u8 p70[0x25]; u8 b95; u8 p96[0x12]; u8 bA8; } O;
typedef struct {
    u8 p0[0x3E]; u8 b3E; u8 p3F[0x20]; u8 b5F; u8 p60[6]; s16 h66; u8 p68[0x198 - 0x68]; s16 h198; u8 p19A[0x2C0 - 0x19A];
    s32 f2C0; f32 f2C4; s32 f2C8; f32 f2CC; u8 p2D0[0x10]; s32 f2E0; s32 f2E4; u8 p2E8[0x10];
    s32 f2F8; u8 p2FC[0x4C]; s32 f348; u8 p34C[8]; s32 f354;
} P;
extern s32 D_L01_001D6694_0498;
__asm__(".extern D_L01_001D6694_0498, 16");
extern s16 D_L01_001A4DBC_0498[];
extern u8 D_L01_001E2A40[];
extern u8 *D_L01_001E001C_0498;
__asm__(".extern D_L01_001E001C_0498, 16");
extern T18 *D_L01_0021F6C0[];
extern s16 *D_L01_0021DE20[];
extern u32 D_00142BA0[];
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern s32 func_L01_003B08A0(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 (**func_L01_0043B568(s32, s32, s32))(void *);
extern s32 func_L01_004BA800(void);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_003B1128(void *);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L01_003B0498(O *a0) {
    P *p = *(P **)((u8 *)a0 + 0x68);
    s32 ok;
    if (a0->b20 == 0 && func_L01_003B08A0(a0) != 0) return 1;
    if (D_L01_001D6694_0498 == 2) D_L01_001A4DBC_0498[0] = 0x3C;
    if (a0->b31 != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, (u8 *)a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0->b6F = 0x16;
        }
    }
    ok = 1;
    if (p->f354 != -1) {
        s32 (**v)(void *) = func_L01_0043B568(0xF6E, 0, 4);
        if (v != 0) {
            u32 i = (*v)(D_001E001C_sda + (p->f354 << 8));
            if ((D_00142BA0[i >> 2] & (1 << (i & 0x1F))) == 0) {
                ok = 0;
            } else if (func_L01_004BA800() != 0) {
                ok = 0;
            } else {
                p->f354 = -1;
                p->f2F8 = 0;
            }
        } else {
            ok = 0;
        }
    }
    if (ok) {
        if (func_L01_00452FB0(a0, (u8 *)p + 0x160, 0, 0, 0) != 0) {
            if (p->h66 < 5) p->h66 = p->h66 + 1;
        }
        if (p->b3E == 2) func_L01_003B1128(a0);
    } else {
        a0->bA8 = 0xFF;
        p->h198 = 0;
    }
    {
        s32 k = p->f348;
        if (k != -1) a0->f18 = D_L01_0021F6C0[k]->f18;
    }
    if (p->f2E0 != -1) {
        R *r = (R *)(D_001E001C_sda + (p->f2E0 << 8));
        func_L01_0044FD88(a0, r, 1, 0);
        r->f98 = 0;
    }
    if (p->f2E4 != -1) {
        s32 n = 0;
        s16 *q = D_L01_0021DE20[p->f2E4];
        while ((p->f2E4 & 0xFF) != 0xFF && p->f2E4 <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[p->f2E4])) {
            R *r = (R *)(D_L01_001E001C_0498 + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            if (r->hAA == 0x16BD || r->hAA == 0x16E4) {
                func_L01_0044FD88(a0, r, n + 2, 0);
                n++;
                r->f98 = 0;
            }
            q++;
        }
    }
    if (p->b5F != 0) func_L01_00456BD0(a0, 5);
    else func_L01_00456BD0(a0, 3);
    if (p->b5F != 0) {
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 3, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 3, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
    } else {
        if (a0->b95 == 0) func_L01_00456C98(a0, p->f2C0, 0, 0, 0, 0, 1, 0, 0, 0, p->f2C4, 10.0f, 1.0f);
        else func_L01_00456C98(a0, p->f2C8, 0, 0, 0, 0, 1, 0, 0, 0, p->f2CC, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L01_003B0498 */

/* localdecomp:start func_L01_003B08A0 */
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[0x10]; u8 b30; u8 p31[0x37]; u8 *p68;
    u8 p6C[0x10]; s16 h7C; u8 p7E[0x1A]; s32 w98; s32 w9C; u8 pA0[0x50]; vu0_v4 rot;
} M_3B08A0;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[3]; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 b44; u8 p45[0x13]; u8 b58; u8 p59; u8 b5A; u8 p5B[9]; u8 b64; u8 p65; s16 h66;
    u8 p68[8]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0;
    f32 fA4; s32 wA8; u8 pAC[0xC4]; u8 b170; u8 b171; u8 b172; u8 p173[9]; s32 w17C; s32 w180;
    u8 p184[0xC]; f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0xF4]; f32 f2D0; u8 p2D4[0x1C];
    s32 w2F0; s16 h2F4; u8 p2F6[0x1A]; vu0_v4 v310; vu0_v4 v320; u8 p330[0x14]; s32 w344;
    s32 w348; s32 w34C; s32 w350;
} P_3B08A0;
extern f32 func_00382538(void);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
s32 func_L01_003B08A0(void *arg) {
    M_3B08A0 *m = arg;
    P_3B08A0 *p = (P_3B08A0 *)m->p68;
    p->f2D0 = func_00382538();
    m->b30 = 0x32;
    m->h7C = 0x1F;
    p->b1A8 = 0xFF;
    p->w17C = 0;
    p->w180 = 0;
    p->f190 = 0.5f;
    p->b1D7 = 1;
    p->f194 = 0.5f;
    p->b171 = 2;
    p->b172 = 2;
    p->b1D8 = 2;
    p->b1DA = 0;
    p->f7C = 1.0f;
    p->fA4 = 1.0f;
    p->b170 = 0xD;
    p->f19C = 0.15f;
    p->b1D9 = 2;
    p->b1DB = 0xFF;
    p->f70 = 0.9f;
    p->f74 = 0.05f;
    p->f78 = 0.5f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 4;
    p->f9C = 0.00392f;
    func_L01_0045BD78(m, 0.0024f, 0.16000001f, 0.010053097f, 0.25132743f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 4;
        p->f30 = 4.0f;
    }
    if (p->b44 == 0) p->b44 = 1;
    p->f40 = 0.75f;
    p->b39 = 1;
    p->b3E = 3;
    p->b3F = 0;
    p->b64 = 0;
    p->h66 = 0;
    if (p->w2F0 != -1) {
        p->h2F4 = 0;
        m->w98 = 0;
        m->pos.z -= 5.0f;
    }
    if (p->w348 != -1) {
        vu0_v4 *b = (vu0_v4 *)D_L01_0021F6C0[p->w348];
        vu0_v4 up;
        vu0_v4 d;
        vu0_v4 out;
        m->pos = b[1];
        *(vu0_q *)&up = 0;
        up.z = 1.0f;
        if (p->w34C == 0) vec_sub_ba(&d, &b[*(s32 *)b], &b[1]);
        else vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_0038CE90(&out, &d, &up);
        m->rot.z = func_0038D160(out.x, out.y);
        p->v320 = m->rot;
        vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_0038CF68(&d, &d, func_0038CEA8(&d) * 0.5f);
        vec_add_ba(&d, &b[*(s32 *)b], &d);
        m->pos = d;
    }
    p->v310 = m->pos;
    func_L01_004450F0(m, 1, 0);
    if (p->w344 != -1) func_L01_004450F0(m, 0xB, -1);
    if (p->w350 == 0) m->w9C |= 0x80;
    return 0;
}
/* localdecomp:end func_L01_003B08A0 */

/* localdecomp:start func_L01_003B0BD8 */
extern void func_L01_00452310(void *m, s32 a, void *b, s32 c, s32 d, f32 x0, f32 x1, f32 x2,
                              f32 x3, f32 x4, u8 e, f32 x5, f32 x6, s32 f, s32 g);
extern void func_L01_004443E8(void *, s32, s32);
extern u8 D_L01_001D66B0[8];

void func_L01_003B0BD8(void *o) {
    func_L01_00452310(o, 0x1FFF, D_L01_001D66B0, 1, 25, 0.8f, 3.0f, 6.0f, 3.0f, 6.0f, 255, -1.0f, -1.0f, 180, 0);
    func_L01_004443E8(o, 0, 3);
}
/* localdecomp:end func_L01_003B0BD8 */

/* localdecomp:start func_L01_003B0C60 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_0C60_O;
extern f32 D_L01_001DE53C, D_L01_001DE540, D_L01_001DE544;
__asm__(".extern D_L01_001DE53C, 4");
__asm__(".extern D_L01_001DE540, 4");
__asm__(".extern D_L01_001DE544, 4");
extern s32 D_L01_001D6694_0C60;
__asm__(".extern D_L01_001D6694_0C60, 16");
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_0044EBA0(void *, void *, void *, f32, f32, f32);
extern void func_L01_00404808(void *, void *);
extern void func_L01_003B0F18(void *);
void func_L01_003B0C60(S_0C60_O *a0) {
    u8 *d = a0->f68;
    func_L01_0044E850(a0, d + 0x240, 0, 0.0432f, 0.43200004f);
    if (a0->h96 <= 0xFFFE) a0->h96 = a0->h96 + 1;
    func_L01_0044EBA0(a0, d + 0x2D8, d + 0x2DC, D_L01_001DE544 * 0.017453292f, D_L01_001DE53C * 0.017453292f * 0.020000001f, D_L01_001DE540 * 0.017453292f * 0.020000001f);
    if (D_L01_001D6694_0C60 == 0) {
        if (a0->b31 != 0) {
            if (a0->b95 != 0) func_L01_00404808(func_L01_003B0F18, a0);
        }
    }
}
/* localdecomp:end func_L01_003B0C60 */

/* localdecomp:start func_L01_003B0D48 */
typedef struct { u8 p0[0x21]; u8 b21; } O_0D48;
typedef struct { u8 p0[0x68]; u8 *f68; u8 p6C[0x3E]; s16 hAA; } R_0D48;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_0D48;
__asm__(".extern D_L01_001E001C_0D48, 16");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
void func_L01_003B0D48(O_0D48 *a0) {
    if (a0->b21 != 0xFF) {
        s16 *q = D_L01_0021DE20[a0->b21];
        while (a0->b21 != 0xFF && a0->b21 <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[a0->b21])) {
            R_0D48 *r = (R_0D48 *)(D_L01_001E001C_0D48 + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            if (r->hAA == 0x194C) *(s32 *)(r->f68 + 0xD24) = 1;
            q++;
        }
    }
}
/* localdecomp:end func_L01_003B0D48 */

/* localdecomp:start func_L01_003B0E00 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B0E00;
extern V4_3B0E00 D_L01_001E29C0;
extern void func_0043A778(void *, s32, void *);
extern void func_0040E620(void *dst, void *src, f32 s);
extern void func_003CCC20(void *, void *, void *, void *, f32);

void func_L01_003B0E00(u8 *a0, void *a1) {
    V4_3B0E00 v0;
    V4_3B0E00 v10;
    V4_3B0E00 v20;
    V4_3B0E00 v30;
    u8 *p = *(u8 **)(a0 + 0x68);
    func_0043A778(a0, 12, &v0);
    func_0043A778(a0, 11, &v10);
    vec_sub_ba(&v20, &D_L01_001E29C0, &v10);
    func_0040E620(&v20, &v20, 0.5f);
    vec_add_ba(&v20, &v20, &v10);
    vec_sub_ab(&v30, &v10, &v0);
    func_0040E620(&v30, &v30, 0.70000005f);
    func_003CCC20(a0, &v20, &v30, a1, *(s32 *)(p + 0x354) == -1 ? (f32)p[0x44] : 0.0f);
}
/* localdecomp:end func_L01_003B0E00 */
