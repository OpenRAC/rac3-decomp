#include "common.h"

typedef struct { char p0[0x18]; float f18; char p1[4]; unsigned char b20; char p2[0x47]; char *p68; char p3[0x29]; unsigned char b95; } A;

/* localdecomp:start func_L01_003BCDF8 */
#include "vu0.h"
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 b20; u8 p21[0x22]; u8 b43; u8 p44[0x1C]; u8 b60; u8 p61[7]; u8 *vars;
    u8 p6C[0x29]; u8 b95; u8 p96[2]; s32 w98; u8 p9C[0x34]; f32 fD0; f32 fD4; u8 pD8[0x1C]; f32 fF4;
    f32 fF8;
} M_3BCDF8;
typedef struct {
    u8 p0[0x30]; f32 f30; u8 p34[0x32]; s16 h66; u8 p68[0xBC]; u8 v124[4]; u8 p128[0x38]; u8 v160[0xC0];
    f32 f220; f32 f224; f32 f228; u8 p22C[8]; s16 h234; u8 p236[0x9E]; f32 f2D4; u8 p2D8[0x40]; f32 f318;
    u8 p31C[4]; s32 w320; u8 p324[8]; s16 h32C; u8 p32E[2]; f32 f330; f32 f334; f32 f338; u8 p33C[0]; s16 h33C; s16 h33E;
} V_3BCDF8;
typedef struct { u8 p0[0x80]; } E_3BCDF8;
extern E_3BCDF8 D_001A30B0_003BCDF8[];
extern u8 *D_L01_0021F6C0_003BCDF8[];
__asm__(".extern D_L01_001DEA20, 8");
extern s32 D_L01_001DEA20[2];
extern int func_L01_003BD7D8(A *);
extern void func_L01_003BDC88(A *, int);
extern void func_L01_003BDF10();
extern void func_L01_003BDF98();
extern void func_L01_003BE2B0();
extern void func_L01_0040D338(void *, s32, void *, f32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445130(void *, s32, s32);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_003C4360(void *, f32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038DB00(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);
void func_L01_003BCDF8(M_3BCDF8 *self) {
    V_3BCDF8 *p = (V_3BCDF8 *)self->vars;
    s32 st;
    s32 r;
    s32 i1, i2, i3, i4, i5;
    f32 f20, f21, f12;
    u8 *e;
    u8 *t;
    u8 *ent;
    vu0_v4 sp90, spA0, spB0, spC0;

    if (func_L01_003BD7D8((A *)self)) {
        func_L01_003BDC88((A *)self, 1);
        return;
    }
    i1 = p->h33C;
    if (i1 == -1 || *(void **)((ent = (u8 *)&D_001A30B0_003BCDF8[i1]) + 0xDC) != self || *(u8 *)(ent + 0xD0) == 0) {
        p->h33C = func_003A52A0(1, 4, self);
    }
    st = self->b95;
    switch (st) {
    case 0:
        if (self->b20 != 8) {
            if (func_L01_004561E0(self) != 0 || self->b20 == 3) {
                func_L01_004450F0(self, 2, -1);
            }
            if (p->h234 == 1) {
                func_L01_004450F0(self, 1, 1);
            }
        }
        break;
    case 1:
        if (self->b20 != 8) {
            func_L01_004561E0(self);
            if (p->h234 == st) {
                func_L01_00445130(self, 4, -1);
            } else {
                i2 = p->h33E;
                if (i2 != -1) {
                    ent = (u8 *)&D_001A30B0_003BCDF8[i2];
                    if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                        func_003A4F28(i2);
                    }
                    p->h33E = -1;
                }
                func_L01_004450F0(self, 1, 0);
            }
        }
        break;
    default:
        break;
    }
    switch (self->b20) {
    case 2:
        if (self->b43 != 1) {
            func_003C3A10(self, 1, 0, 8);
        }
        if (p->w320 != -1) {
            sp90.x = func_0038D098(func_0038D160(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.y = func_0038D0B0(func_0038D160(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.z = 0;
            *(vu0_q *)&spA0 = *(vu0_q *)(D_L01_0021F6C0_003BCDF8[p->w320] + 0x10);
            vec_sub_ab(&spA0, &spA0, &self->pos);
            f12 = func_0038CEA8(&spA0);
            func_003C4360(&p->f330, f12, p->f338 * 0.00040000002f, p->f338 * 0.00040000002f, p->f334 * 0.020000002f);
            func_0038CF68(&spA0, &spA0, p->f330);
            func_L01_0045AA30(self, &spA0);
        }
        if (self->b60 & 2) {
            func_L01_004450F0(self, 3, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(self)) {
            if (self->b43 != 0) {
                func_003C3A10(self, 0, 0, 8);
            }
            p->h32C = 5;
            i3 = p->h33E;
            if (i3 == -1 || *(void **)((ent = (u8 *)&D_001A30B0_003BCDF8[i3]) + 0xDC) != self || *(u8 *)(ent + 0xD0) == 0) {
                p->h33E = func_003A52A0(0, 4, self);
            }
        }
        if (p->w320 != -1) {
            sp90.x = func_0038D098(func_0038D160(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.y = func_0038D0B0(func_0038D160(p->f220 - self->pos.x, p->f224 - self->pos.y));
            sp90.z = 0;
            f20 = self->fD0 * sp90.x + self->fD4 * sp90.y;
            f21 = sp90.z;
            e = D_L01_0021F6C0_003BCDF8[p->w320];
            t = e + 0x10;
            if (!(f21 < f20)) {
                t = t + (*(s32 *)e - 1) * 16;
            }
            *(vu0_q *)&spA0 = *(vu0_q *)t;
            vec_sub_ab(&spA0, &spA0, &self->pos);
            {
                f32 q = f20 / func_0038CEA8(&sp90);
                if (!(f21 < f20)) q = -q;
                func_003C4360(&p->f330, q, p->f338 * 0.00040000002f, p->f338 * 0.00040000002f, p->f334 * 0.020000002f);
            }
            func_0038CF68(&spA0, &spA0, p->f330);
            func_L01_0045AA30(self, &spA0);
        }
        func_L01_00448890(&self->fF8, p->f318, 0.040000003f, 0.040000003f, 2.0000002f, &p->v124, 0);
        func_003C2F58(self, 0, &sp90);
        f12 = func_0038DB00(func_0038D160(func_0038CF38(&p->f220, &sp90), sp90.z - p->f228), self->fF4);
        if (1.5707964f < f12) {
            f12 = 1.5707964f;
        } else if (f12 < 0.0f) {
            f12 = 0.0f;
        }
        p->f2D4 = f12;
        if (func_0038CB00(&p->h32C)) {
            func_003C2F58(self, 0xC, &spA0);
            func_003C2F58(self, 0xB, &spB0);
            vec_sub_ab(&spC0, &spB0, &spA0);
            func_0038CF68(&spC0, &spC0, 0.70000005f);
            func_L01_003BE2B0(self, 0);
            p->h32C = 5;
        }
        break;
    case 8:
        if (func_L01_004561B8(self)) {
            if (p->h66 < 3) {
                p->h66++;
            }
        }
        r = func_L01_00454370(self, p->v160);
        i4 = p->h33E;
        if (i4 != -1) {
            ent = (u8 *)&D_001A30B0_003BCDF8[i4];
            if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                func_003A4F28(i4);
            }
            p->h33E = -1;
        }
        if ((r & 1) || p->f30 <= 0.0f) {
            i5 = p->h33C;
            if (i5 != -1) {
                ent = (u8 *)&D_001A30B0_003BCDF8[i5];
                if (*(void **)(ent + 0xDC) == self && *(u8 *)(ent + 0xD0) != 0) {
                    func_003A4F28(i5);
                }
            }
            p->h33C = -1;
            func_003A52A0(2, 0, self);
            self->w98 = 0;
            func_L01_003BDF10(self);
            func_L01_003303B8((u8 *)&self->pos, 0, 0x19, 0x14, 0x14, 0x14, 0x14, 0, 1.25f, 0.0f, 0.0f, 2.0f, 0, 1, 0, 0, 0, 1, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_003BDC88((A *)self, 1);
            return;
        }
        if (r & 2) {
            func_L01_004450F0(self, 1, 0);
        }
        break;
    default:
        break;
    }
    if (self->b95 != 0) {
        func_L01_0040D338(self, p->h66, D_L01_001DEA20, 1.0f);
    }
    func_L01_003BDF98(self);
}
/* localdecomp:end func_L01_003BCDF8 */

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
