#include "common.h"
#include "vu0.h"

typedef struct { u8 p0[0x18]; f32 f18; } T18;
typedef struct { u8 p0[0x98]; s32 f98; u8 p9C[0xE]; s16 hAA; } R;
typedef struct { u8 p0[0x18]; f32 f18; u8 p1C[4]; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[0x3D]; u8 b6F; u8 p70[0x25]; u8 b95; u8 p96[0x12]; u8 bA8; } O;
typedef struct {
    u8 p0[0x3E]; u8 b3E; u8 p3F[0x20]; u8 b5F; u8 p60[6]; s16 h66; u8 p68[0x198 - 0x68]; s16 h198; u8 p19A[0x2C0 - 0x19A];
    s32 f2C0; f32 f2C4; s32 f2C8; f32 f2CC; u8 p2D0[0x10]; s32 f2E0; s32 f2E4; u8 p2E8[0x10];
    s32 f2F8; u8 p2FC[0x4C]; s32 f348; u8 p34C[8]; s32 f354;
} P;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 b20;
    u8 pad21[0x3];
    u8 *p24;
    u8 pad28[0x1B];
    u8 b43;
    u8 pad44[0x1C];
    u8 b60;
    u8 pad61[0x7];
    void *p68;
    u8 pad6C[0x29];
    u8 b95;
    u8 pad96[0x2];
    s32 s98;
    u8 pad9C[0x24];
    vu0_v4 vC0;
    f32 fD0;
    f32 fD4;
    u8 padD8[0x1C];
    f32 fF4;
    f32 fF8;
} AO;
typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x32];
    s16 h66;
    u8 pad68[0x3C];
    f32 fA4;
    s32 fA8;
    u8 padAC[0x78];
    u8 b124;
    u8 pad125[0xF];
    s32 s134;
    u8 pad138[0x28];
    u8 b160;
    u8 pad161[0xBF];
    vu0_v4 v220;
    s32 s230;
    s16 h234;
    u8 pad236[0x6E];
    f32 f2A4;
    f32 f2A8;
    u8 pad2AC[0x18];
    f32 f2C4;
    u8 pad2C8[0x20];
    f32 f2E8;
    f32 f2EC;
    s32 s2F0;
    s16 h2F4;
    s16 h2F6;
    s32 s2F8;
    f32 f2FC;
    vu0_v4 v300;
    u8 pad310[0x8];
    f32 f318;
    u8 pad31C[0xC];
    f32 f328;
    u8 pad32C[0x4];
    s16 h330;
    s16 h332;
    s32 s334;
    s32 s338;
    f32 f33C;
    s32 s340;
    s32 s344;
    s32 s348;
    s32 s34C;
    u8 pad350[0x4];
    s32 s354;
    s32 s358;
} AP;

typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; u8 *f68; u8 p6C[0x29]; u8 b95; u16 h96; } S_0C60_O;
typedef struct { u8 pad0[0x25C0]; s32 x25C0; } DH;
typedef struct { s32 n; s32 p4[3]; } Q16;

/* localdecomp:start func_L01_003AF290 */
extern s32 func_L01_003B0498(O *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445130(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern s32 func_L01_0045BDE8(void *, s32);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_0045AA30(void *, void *);
extern void func_L01_00448890(void *, void *, f32, f32, f32, f32, s32);
extern void func_L01_00446BC8(void *, void *, s32, void *, f32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L01_003B0E00(u8 *, void *);
extern void func_L01_003B0C60(S_0C60_O *);
extern void func_L01_003B1128(void *);
extern void func_L01_0040D338(void *o, s32 n, s32 *arr, f32 sc);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C4360(void *, f32, f32, f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern u8 D_001426E1[];
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001DE520_sda;
__asm__(".extern D_001DE520_sda, 4");
extern DH D_001A4BE0_3AF290;
extern Q16 *D_L01_0021F6C0_3AF290[];

void func_L01_003AF290(AO *o) {
    AP *p = (AP *)o->p68;
    vu0_v4 a, b, c, d, e;
    Q16 *q, *q11, *q12;
    u8 *k, *m;
    s32 h6, i, t, t1, t2, t3, t4, t5, r, u;
    u8 bb;
    f32 f20, f21, f, fa, fn;

    if (func_L01_003B0498((O *)o) != 0) return;
    i = p->s334;
    if (i == -1 || *(void **)((m = D_001A30B0 + (i << 7)) + 0xDC) != o || m[0xD0] == 0)
        p->s334 = func_003A52A0(1, 4, o);
    switch (o->b95) {
    case 0:
        if (o->b20 == 0xD) break;
        if (func_L01_004561E0(o) != 0 || o->b20 == 3) {
            if (o->b20 != 0xB) func_L01_004450F0(o, 2, -1);
        }
        u = p->s2F0;
        if (u != -1 && p->h2F4 == 0) {
            if (o->b20 == 9) break;
            if (func_L01_00456500(D_001A4C60, u) == 0) break;
            if (D_001D545C_sda == 1 && D_001426E1[0] == 0) break;
            p->fA8 &= ~0x400;
            func_L01_004450F0(o, 9, -1);
            break;
        }
        if (p->h234 != 1 && p->s358 == 0) break;
        p->fA8 &= ~0x400;
        if (p->s348 != -1) func_L01_004450F0(o, 1, 2);
        else func_L01_004450F0(o, 1, 1);
        break;
    case 1:
        if (o->b20 == 0xD) break;
        if (func_L01_004561E0(o) != 0 || o->b20 == 1) {
            func_L01_004450F0(o, 4, -1);
            if (p->s340 != -1 && p->h2F4 == 0) func_L01_004450F0(o, 0xC, -1);
        }
        if (p->s358 != 0 && p->h234 != 1)
            func_L01_00456C98(o, -1, 0, 0, 0, 0, 1, 0, 0, 0, 100.0f, 10.0f, 1.0f);
        if (p->h234 == 1) {
            if (o->b20 == 0xC) break;
            if (func_0038CF38(&o->v10, &p->v220) < 10.0f) {
                func_L01_00445130(o, 7, -1);
                break;
            }
            if (o->b20 == 5) {
                func_L01_004450F0(o, 6, -1);
                break;
            }
            if (o->b20 == 8) func_L01_004450F0(o, 1, 0);
            break;
        }
        if (o->b20 == 4 || o->b20 == 5 || o->b20 == 8) func_L01_004450F0(o, 1, 0);
        break;
    case 2:
        if (o->b20 == 0xD) break;
        if (func_L01_004561E0(o) != 0 || o->b20 == 1) func_L01_00445130(o, 6, -1);
        if (p->s348 != -1 && p->s354 == -1) {
            a.x = func_0038D098(func_0038D160(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
            a.y = func_0038D0B0(func_0038D160(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
            f20 = o->fD0 * a.x + o->fD4 * a.y;
            a.z = 0.0f;
            if (p->s34C != 0) f20 = -f20;
            f21 = a.z;
            q = D_L01_0021F6C0_3AF290[p->s348];
            k = (u8 *)(q + 1);
            if (!(f21 < f20)) k += (q->n - 1) * 16;
            b = *(vu0_v4 *)k;
            vec_sub_ba(&b, &b, &o->v10);
            if (p->fA4 < func_0038CEA8(&b)) {
                fa = f20 / func_0038CEA8(&a);
                if (!(f21 < f20)) fa = -fa;
                func_003C4360(&p->f33C, fa, 0.040000003f, 0.040000003f, 0.6f);
                func_0038CF68(&b, &b, p->f33C);
                c = o->v10;
                func_L01_0045AA30(o, &b);
                vec_sub_ba(&c, &o->v10, &c);
                vec_add_ab(&p->v300, &p->v300, &c);
            }
            func_L01_00448890(&o->fF8, &p->b124, p->f328, 0.040000003f, 0.040000003f, 2.0000002f, 0);
            if (func_0038DBA0(o->fF8, p->f328) < 0.034906585f) {
                if (func_0038CE68(&o->vC0, &a) < 0.0f)
                    func_L01_00446BC8(o, 0, 0x10000, &o->v10, 500.0f);
            }
        }
        if (p->s358 != 0 && p->h234 != 1)
            func_L01_00456C98(o, -1, 0, 0, 0, 0, 1, 0, 0, 0, 100.0f, 10.0f, 1.0f);
        if (p->h234 == 1) {
            if (o->b20 != 0xC) {
                if (func_0038CF38(&o->v10, &p->v220) < 10.0f) {
                    func_L01_00445130(o, 7, -1);
                    break;
                }
                if (o->b20 == 5) {
                    func_L01_004450F0(o, 6, -1);
                    break;
                }
                if (o->b20 != 8) break;
                func_L01_004450F0(o, 1, 0);
                break;
            }
        }
        if (o->b20 == 4 || o->b20 == 5 || o->b20 == 8) func_L01_004450F0(o, 1, 0);
        break;
    }
    switch (o->b20) {
    case 2:
        if (o->b43 != 1) func_003C3A10(o, 1, 0, 8);
        if (!(o->b60 & 2)) break;
        func_L01_004450F0(o, 3, -1);
        break;
    case 11:
        if (func_L01_004561B8(o) != 0) {
            p->fA8 |= 0x400;
            if (o->b43 != 1) func_003C3A10(o, 1, 0, 8);
        }
        if (func_L01_0045BDE8(o, p->s344) == 0) break;
        q11 = D_L01_0021F6C0_3AF290[p->s344];
        f20 = func_0038CF38(&o->v10, q11 + 1);
        if (func_0038CF38(&o->v10, q11 + q11->n) < f20) func_L01_0045C150(o, q11, 0, q11->n - 1);
        else func_L01_0045C150(o, q11, q11->n - 1, 0);
        break;
    case 4:
        if (func_L01_004561B8(o) != 0) {
            if (o->b43 != 1) func_003C3A10(o, 1, 0, 8);
            func_L01_0045BD78(o, 0.0024f, 0.080000006f, 0.0012566372f, 0.03490659f);
        }
        func_L01_0045BD10(o, func_0038D160(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
        if (func_0038DBA0(o->fF8, func_0038D160(p->v220.x - o->v10.x, p->v220.y - o->v10.y)) < 0.017453292f)
            func_L01_004450F0(o, 5, -1);
        break;
    case 12:
        if (func_L01_004561B8(o) != 0) {
            p->fA8 |= 0x400;
            if (o->b43 != 1) func_003C3A10(o, 1, 0, 8);
            if (p->s134 == 0) {
                q12 = D_L01_0021F6C0_3AF290[p->s340];
                f20 = func_0038CF38(&o->v10, q12 + 1);
                if (func_0038CF38(&o->v10, q12 + q12->n) < f20) func_L01_0045C150(o, q12, 0, 0);
                else func_L01_0045C150(o, q12, q12->n - 1, 0);
            }
        }
        if (func_L01_0045BDE8(o, p->s340) != 0) {
            p->h2F4 = 1;
            func_L01_004450F0(o, 1, -1);
        }
        break;
    case 6:
        r = func_L01_004561B8(o);
        if (r != 0) {
            if (o->b43 != 0) func_003C3A10(o, 0, 0, 8);
            p->h330 = 10;
            p->h332 = 20;
            p->v300 = p->v220;
            p->f2E8 = -2.0f;
            p->f2EC = -0.2617994f;
            p->s2F8 = 330;
            p->f2FC = 0.003030303f;
            p->h2F6 = 1;
            t1 = p->s338;
            if (t1 == -1 || *(void **)((m = D_001A30B0 + (t1 << 7)) + 0xDC) != o || m[0xD0] == 0)
                p->s338 = func_003A52A0(0, 4, o);
        }
        d = (vu0_v4){0.0f, 0.0f, 1.0f, 0.0f};
        f21 = (f32)p->s2F8 * p->f2FC;
        func_003C2F58(o, 0, &a);
        if (p->s358 == 0) {
            vec_sub_ab(&b, &p->v300, &a);
        } else {
            f = func_0038D160(o->vC0.x, o->vC0.y);
            b.x = func_0038D098(f) * p->f2C4;
            f = func_0038D160(o->vC0.x, o->vC0.y);
            b.y = func_0038D0B0(f) * p->f2C4;
            b.z = 0.0f;
            vec_add_ba(&p->v300, &b, &o->v10);
        }
        if (p->f2C4 < func_0038CEA8(&b)) {
            func_0038CF68(&b, &b, p->f2C4);
            vec_add_ba(&b, &b, &o->v10);
            b.z = p->v300.z;
            b.z = func_003C3D30(&b, 0, 0, 0.5f);
            vec_sub_ba(&b, &b, &o->v10);
        }
        f = func_0038CEA8(&b);
        func_0038CF68(&b, &b, f + p->f2E8);
        vec_add_ba(&c, &o->v10, &b);
        c.z = p->v300.z;
        c.z = func_003C3D30(&c, 0, 0, 0.5f);
        vec_sub_ab(&c, &c, &o->v10);
        func_0038D890(&c, &c, &d, p->f2EC);
        e = c;
        vec_add_ba(&e, &e, &o->v10);
        func_0038CF68(&c, &c, 0.70000005f);
        f = func_0038D160(func_0038CF38(&e, &a), a.z - e.z);
        f20 = func_0038DB00(f, o->fF4);
        f = func_0038DB00(func_0038D160(e.x - a.x, e.y - a.y), o->fF8);
        if (1.5707964f < f20) f20 = 1.5707964f;
        else if (f20 < 0.0f) f20 = 0.0f;
        if (1.5707964f < f) f = 1.5707964f;
        else if (f < -1.5707964f) f = -1.5707964f;
        p->f2A4 = f20;
        p->f2A8 = f;
        if (func_0038CAD0(&p->s2F8) != 0) {
            t2 = p->s338;
            if (t2 != -1 && *(void **)((m = D_001A30B0 + (t2 << 7)) + 0xDC) == o && m[0xD0] != 0)
                func_003A4F28(t2);
            p->s338 = -1;
            func_L01_004450F0(o, 8, -1);
        } else {
            f = func_003C3BE8(8.0f, -2.0f, f21);
            h6 = p->h2F6;
            fn = p->f2EC + (f32)h6 * 0.005f;
            p->f2E8 = f;
            p->f2EC = fn;
            if (0.2617994f < fabs_asm(fn)) p->h2F6 = -h6;
        }
        if (func_0038CB00(&p->h332) == 0) break;
        func_L01_003B0E00((u8 *)o, (void *)0);
        p->h332 = 5;
        break;
    case 7:
        if (func_L01_004561B8(o) != 0) {
            if (o->b43 != 0) func_003C3A10(o, 0, 0, 8);
            p->h330 = 10;
            p->h332 = 5;
            t3 = p->s338;
            if (t3 == -1 || *(void **)((m = D_001A30B0 + (t3 << 7)) + 0xDC) != o || m[0xD0] == 0)
                p->s338 = func_003A52A0(0, 4, o);
        }
        if (func_L01_0040E570(&o->v10, &p->v220) < 81.0f) {
            func_L01_0045BD78(o, 0.0024f, 0.080000006f, 0.02792527f, 1.3962635f);
            if (p->s230 == D_001A4BE0_3AF290.x25C0) {
                func_0038CE20(&a, (u8 *)&D_001A4BE0_3AF290 + 0x110, 10.0f);
                vec_add_ab(&p->v220, (u8 *)&D_001A4BE0_3AF290 + 0x80, &a);
            }
        } else {
            func_L01_0045BD78(o, 0.0024f, 0.080000006f, 0.0069813174f, 0.34906587f);
        }
        if (p->s348 == -1)
            func_L01_0045BD10(o, func_0038D160(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
        func_003C2F58(o, 0, &a);
        f20 = func_0038DB00(func_0038D160(func_0038CF38(&p->v220, &a), a.z - p->v220.z), o->fF4);
        f = func_0038DB00(func_0038D160(p->v220.x - a.x, p->v220.y - a.y), o->fF8);
        p->f2A4 = f20;
        p->f2A8 = f;
        if (func_0038CB00(&p->h332) == 0) break;
        func_L01_003B0E00((u8 *)o, (void *)1);
        p->h332 = 5;
        if (p->h330-- > 0) break;
        t4 = p->s338;
        if (t4 != -1 && *(void **)((m = D_001A30B0 + (t4 << 7)) + 0xDC) == o && m[0xD0] != 0)
            func_003A4F28(t4);
        p->s338 = -1;
        func_L01_004450F0(o, 8, -1);
        break;
    case 9:
        if (func_L01_004561B8(o) != 0) p->h332 = 60;
        if (func_0038CB00(&p->h332) != 0) {
            o->s98 = *(s32 *)(o->p24 + 0x10);
            p->h2F4 = 1;
            func_L01_004450F0(o, 10, -1);
        } else {
            *(f32 *)((u8 *)o + 0x18) = func_003C3BE8(p->f318 + 5.0f, p->f318, (f32)p->h332 / 60.0f);
        }
        break;
    case 13:
        if (func_L01_004561B8(o) != 0) func_003A52A0(3, 0, o);
        r = func_L01_00454370(o, (u8 *)p + 0x160);
        t5 = p->s338;
        if (t5 != -1) {
            if (*(void **)((m = D_001A30B0 + (t5 << 7)) + 0xDC) == o && m[0xD0] != 0)
                func_003A4F28(t5);
            p->s338 = -1;
        }
        if ((r & 1) || p->f30 <= 0.0f) {
            func_L01_003B1128(o);
            return;
        }
        if (r & 2) func_L01_004450F0(o, 1, o->b95);
        break;
    }
    if (o->b95 != 0) func_L01_0040D338(o, p->h66, &D_001DE520_sda, 1.0f);
    func_L01_003B0C60((S_0C60_O *)o);
}
/* localdecomp:end func_L01_003AF290 */


/* localdecomp:start func_L01_003B0498 */
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
