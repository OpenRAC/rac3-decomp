#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003BCDF8);

/* localdecomp:start func_L01_003BD608 */
typedef struct { u8 p0[0x43]; u8 b43; u8 p44[0x54]; s32 f98; u8 p9C[0xE]; s16 hAA; } R_BD608;
typedef struct { u8 p0[0x324]; s32 f324; s32 f328; } P_BD608;
extern u8 *D_L01_001E001C_a;
__asm__(".extern D_L01_001E001C_a, 16");
extern u8 *D_L01_001E001C_b;
__asm__(".extern D_L01_001E001C_b, 16");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern s16 *D_L01_0021DE20[];
extern void func_00444D90(void *, s32, s32, s32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
void func_L01_003BD608(void *a0, P_BD608 *p) {
    R_BD608 *r;
    s16 *q;
    s32 i;
    if (p->f324 != -1) {
        r = (R_BD608 *)(D_L01_001E001C_a + (p->f324 << 8));
        if (r->b43 != 5) func_00444D90(r, 5, 0, 6);
        func_L01_0044FD88(a0, r, 1, 0);
        r->f98 = 0;
    }
    if (p->f328 != -1) {
        i = 0;
        q = D_L01_0021DE20[p->f328];
        while ((p->f328 & 0xFF) != 0xFF && p->f328 <= D_001E0058_sda && q != 0 && (q[-1] >= 0 || q == D_L01_0021DE20[p->f328])) {
            r = (R_BD608 *)(D_L01_001E001C_b + ((*(u16 *)q & 0x7FFF) << 8));
            if (r == 0) break;
            switch (r->hAA) {
            case 0x16BD:
                if (r->b43 != 0) func_00444D90(r, 0, 0, 6);
                break;
            case 0x16E4:
                if (r->b43 != 5) func_00444D90(r, 5, 0, 6);
                break;
            }
            if (r->hAA == 0x16BD || r->hAA == 0x16E4) {
                func_L01_0044FD88(a0, r, i + 2, 0);
                i++;
                r->f98 = 0;
            }
            q++;
        }
    }
}
/* localdecomp:end func_L01_003BD608 */

/* localdecomp:start func_L01_003BD7D8 */
typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;
typedef struct { char p0[0x18]; float f18; } B;
typedef struct S {
    char p0[0x30]; float f30; char p1[0xa]; unsigned char b3e; char p2[0x20]; unsigned char b5f; char p3[6]; short h66;
    char p4[0xf8]; char r160[0x190]; int w2f0; float f2f4; int w2f8; float f2fc; char p6[0x20]; int w320;
} S;
extern B *D_L01_0021F6C0[];
extern int func_L01_003BD9A8(void *);
extern int func_L01_00452FB0(A *, void *, int, int, int);
extern void func_L01_003BD608(void *, P_BD608 *);
extern void func_L01_003BDC88(A *, int);
extern void func_L01_00456BD0(A *, int);
extern void func_L01_00456C98(A *, int, int, int, int, int, int, int, int, int, float, float, float);
int func_L01_003BD7D8(A *a) {
    S *s = (S *)a->p68;
    if (a->b20 == 0 && func_L01_003BD9A8(a)) return 1;
    if (func_L01_00452FB0(a, s->r160, 0, 0, 0)) {
        if (s->h66 < 3) s->h66++;
    }
    if (0.0f < s->f30) func_L01_003BD608(a, s);
    if (s->b3e == 2) func_L01_003BDC88(a, 1);
    if (s->b5f) func_L01_00456BD0(a, 5); else func_L01_00456BD0(a, 3);
    if (s->w320 != -1) a->f18 = D_L01_0021F6C0[s->w320]->f18;
    if (s->b5f) {
        if (a->b95 == 0) func_L01_00456C98(a, s->w2f0, 0, 0, 0, 0, 3, 0, 0, 0, s->f2f4, 10.0f, 1.0f);
        else func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 3, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    } else {
        func_L01_00456C98(a, s->w2f8, 0, 0, 0, 0, 1, 0, 0, 0, s->f2fc, 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L01_003BD7D8 */

/* localdecomp:start func_L01_003BD9A8 */
#include "vu0.h"
typedef struct { u8 p0[0x24]; f32 f24; } C_BD9A8;
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[4]; C_BD9A8 *p24; u8 p28[4]; f32 f2C;
    u8 p30[0x13]; u8 b43; u8 p44[0x24]; u8 *p68; u8 p6C[0x10]; s16 h7C;
    u8 p7E[0x72]; vu0_v4 rot;
} M_BD9A8;
typedef struct {
    u8 p0[0x30]; f32 f30; s16 h34; u8 p36[2]; u8 b38; u8 b39; u8 p3A[4]; u8 b3E; u8 b3F; f32 f40;
    u8 p44[0x14]; u8 b58; u8 p59; u8 b5A; u8 p5B[3]; u8 b5E; u8 b5F; u8 p60[4]; u8 b64;
    u8 p65[0xB]; f32 f70; f32 f74; f32 f78; f32 f7C; f32 f80; u8 p84[0x18]; f32 f9C; f32 fA0;
    u8 pA4[4]; s32 wA8; u8 pAC[0xC4]; u8 b170; u8 b171; u8 b172; u8 p173[0x1D];
    f32 f190; f32 f194; u8 p198[4]; f32 f19C; u8 p1A0[8]; u8 b1A8; u8 p1A9[0x2E];
    u8 b1D7; u8 b1D8; u8 b1D9; u8 b1DA; u8 b1DB; u8 p1DC[0x64]; s32 w240; u8 p244[0xA];
    u8 b24E; u8 b24F; u8 p250[0xB0]; f32 f300; u8 p304[0xC]; vu0_v4 v310; s32 w320;
    u8 p324[8]; s16 h32C; s16 h32E; s32 w330; f32 f334; f32 f338;
} P_BD9A8;
typedef struct { void (*f0)(void *); } V_BD9A8;
extern f32 func_00382538(void);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void *func_L01_0043B548(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
int func_L01_003BD9A8(void *arg) {
    M_BD9A8 *m = arg;
    P_BD9A8 *p = (P_BD9A8 *)m->p68;
    m->f2C = m->p24->f24;
    p->f300 = func_00382538();
    m->h7C = 0x1F;
    p->f190 = 0.5f;
    p->b1D7 = 1;
    p->b171 = 2;
    p->b1A8 = 0xFF;
    p->b172 = 2;
    p->b1D8 = 2;
    p->b1D9 = 2;
    p->b1DA = 0;
    p->f194 = 0.5f;
    p->f7C = 1.0f;
    p->b170 = 8;
    p->f19C = 0.15f;
    p->b1DB = 0xFF;
    p->f70 = 0.9f;
    p->f74 = 0.05f;
    p->f78 = 0.5f;
    p->f80 = 0.7853982f;
    p->fA0 = 0.34906584f;
    p->wA8 |= 4;
    p->f9C = 0.00392f;
    func_L01_0045BD78(m, p->f338 * 0.00040000002f, p->f334 * 0.020000001f,
                      p->f338 * 0.017453292f * 0.00040000002f, p->f334 * 0.017453292f * 0.020000001f);
    p->b58 = 0x14;
    p->b5A = 0xE;
    if (p->h34 == 0) {
        p->h34 = 4;
        p->f30 = 4.0f;
    }
    p->f40 = 0.75f;
    p->b38 = 2;
    p->b39 = 1;
    p->b3E = 1;
    p->b3F = 0;
    p->b64 = 0;
    if (p->w320 != -1) {
        vu0_v4 *b = (vu0_v4 *)D_L01_0021F6C0[p->w320];
        vu0_v4 up;
        vu0_v4 d;
        vu0_v4 out;
        m->pos = b[1];
        *(vu0_q *)&up = 0;
        up.z = 1.0f;
        if (p->h32E == 0) vec_sub_ba(&d, &b[*(s32 *)b], &b[1]);
        else vec_sub_ab(&d, &b[1], &b[*(s32 *)b]);
        func_0038CE90(&out, &d, &up);
        m->rot.z = func_0038D160(out.x, out.y);
        p->v310 = m->rot;
    }
    p->b5E = 0;
    p->b5F = 0;
    p->h32C = 0;
    p->w330 = 0;
    if (p->w240 > 0) {
        V_BD9A8 *r = func_L01_0043B548(0x19E1, 0x6C);
        p->w240 = -1;
        if (m->b43 != 1) func_003C3A10(m, 1, 0, 0);
        p->b24E = 7;
        p->b24F = 2;
        r->f0(m);
    } else {
        func_L01_004450F0(m, 1, 0);
    }
    return 0;
}
/* localdecomp:end func_L01_003BD9A8 */

/* localdecomp:start func_L01_003BDC88 */
typedef struct { void (*f0)(void *); void (*f4)(void *); s32 p8, pC; void (*f10)(void *); } V_BDC88;
typedef struct { char p0[0x240]; s32 f240; char p1[0xE0]; s32 f324; s32 f328; } O_BDC88;
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");
extern s16 *D_L01_0021DE20[];
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
extern void *func_L01_0043B548(s32, s32);
extern s32 func_L01_0043B930(s32);
extern s32 func_L01_0043B960(s32);
extern void func_L01_00439300(void *);
void func_L01_003BDC88(A *a, int flag) {
    O_BDC88 *o = (O_BDC88 *)a->p68;
    V_BDC88 *v;
    s16 *p;
    if (o->f240) {
        v = func_L01_0043B548(0x19E1, 0x6C);
        if (o->f324 != -1) {
            v->f10(D_L01_001E001C + (o->f324 << 8));
            o->f324 = -1;
        }
        if (o->f328 != -1) {
            if (func_L01_0043B960(o->f328)) {
                while (!func_L01_0043B930(o->f328)) {
                    v->f10(D_L01_001E001C + ((*D_L01_0021DE20[o->f328] & 0x7FFF) << 8));
                }
                o->f328 = -1;
            } else {
                p = D_L01_0021DE20[o->f328];
                while ((o->f328 & 0xFF) != 0xFF && o->f328 <= D_001E0058_sda && p && (p[-1] >= 0 || p == D_L01_0021DE20[o->f328])) {
                    u8 *r = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
                    if (!r) break;
                    v->f10(r);
                    p++;
                }
                o->f328 = -1;
            }
        }
        v->f0(a);
        if (flag) v->f4(a);
    } else {
        if (o->f324 != -1) func_L01_00439300(D_001E001C_sda + (o->f324 << 8));
        if (o->f328 != -1) {
            p = D_L01_0021DE20[o->f328];
            while ((o->f328 & 0xFF) != 0xFF && o->f328 <= D_001E0058_sda && p && (p[-1] >= 0 || p == D_L01_0021DE20[o->f328])) {
                u8 *r = D_L01_001E001C + ((*(u16 *)p & 0x7FFF) << 8);
                if (!r) break;
                func_L01_00439300(r);
                p++;
            }
        }
        func_L01_00439300(a);
    }
}
/* localdecomp:end func_L01_003BDC88 */
