#include "common.h"

/* NTSC-U counterpart of func_L01_003AF290 (src/levels/01_veldin/L01_003AF290.c) */
#include "vu0.h"
typedef struct { u8 p0[0x18]; f32 f18; u8 p1C[4]; u8 b20; u8 p21[0x10]; u8 b31; u8 p32[0x3D]; u8 b6F; u8 p70[0x25]; u8 b95; u8 p96[0x12]; u8 bA8; } O;
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

/* localdecomp:start func_L01_003ADAC0 */
extern s32 func_L01_003AECC8(O *);
extern s32 func_L01_00452EF0(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FF8(void *, s32, s32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458A08(void *, f32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00458E48(void *, void *, s32, s32);
extern void func_L01_00457728(void *, void *);
extern void func_L01_00445758(void *, void *, f32, f32, f32, f32, s32);
extern void func_L01_00443A90(void *, void *, s32, void *, f32);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00451078(void *, void *);
extern void func_L01_003AF630(u8 *, void *);
extern void func_L01_003AF490(S_0C60_O *);
extern void func_L01_003AF958(void *);
extern void func_L01_0040AE68(void *o, s32 n, s32 *arr, f32 sc);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_003BE6A8(f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_003BEE20(void *, f32, f32, f32, f32);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern f32 func_00388800(void *, void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00388A28(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389468(f32, f32);
extern u8 D_001A30B0[];
extern u8 D_001A4C60[];
extern u8 D_001426E1[];
extern s32 D_001D545C_sda_003ADAC0;
__asm__(".extern D_001D545C_sda_003ADAC0, 4");
extern s32 D_001DE560_sda;
__asm__(".extern D_001DE560_sda, 4");
extern DH D_001A4BE0_3AF290;
extern Q16 *D_L01_0021F740_3AF290[];

void func_L01_003ADAC0(AO *o) {
    AP *p = (AP *)o->p68;
    vu0_v4 a, b, c, d, e;
    Q16 *q, *q11, *q12;
    u8 *k, *m;
    s32 h6, i, t, t1, t2, t3, t4, t5, r, u;
    u8 bb;
    f32 f20, f21, f, fa, fn;

    if (func_L01_003AECC8((O *)o) != 0) return;
    i = p->s334;
    if (i == -1 || *(void **)((m = D_001A30B0 + (i << 7)) + 0xDC) != o || m[0xD0] == 0)
        p->s334 = func_0039FE80(1, 4, o);
    switch (o->b95) {
    case 0:
        if (o->b20 == 0xD) break;
        if (func_L01_00452EF0(o) != 0 || o->b20 == 3) {
            if (o->b20 != 0xB) func_L01_00441FB8(o, 2, -1);
        }
        u = p->s2F0;
        if (u != -1 && p->h2F4 == 0) {
            if (o->b20 == 9) break;
            if (func_L01_00453210(D_001A4C60, u) == 0) break;
            if (D_001D545C_sda_003ADAC0 == 1 && D_001426E1[0] == 0) break;
            p->fA8 &= ~0x400;
            func_L01_00441FB8(o, 9, -1);
            break;
        }
        if (p->h234 != 1 && p->s358 == 0) break;
        p->fA8 &= ~0x400;
        if (p->s348 != -1) func_L01_00441FB8(o, 1, 2);
        else func_L01_00441FB8(o, 1, 1);
        break;
    case 1:
        if (o->b20 == 0xD) break;
        if (func_L01_00452EF0(o) != 0 || o->b20 == 1) {
            func_L01_00441FB8(o, 4, -1);
            if (p->s340 != -1 && p->h2F4 == 0) func_L01_00441FB8(o, 0xC, -1);
        }
        if (p->s358 != 0 && p->h234 != 1)
            func_L01_004539A8(o, -1, 0, 0, 0, 0, 1, 0, 0, 0, 100.0f, 10.0f, 1.0f);
        if (p->h234 == 1) {
            if (o->b20 == 0xC) break;
            if (func_00388800(&o->v10, &p->v220) < 10.0f) {
                func_L01_00441FF8(o, 7, -1);
                break;
            }
            if (o->b20 == 5) {
                func_L01_00441FB8(o, 6, -1);
                break;
            }
            if (o->b20 == 8) func_L01_00441FB8(o, 1, 0);
            break;
        }
        if (o->b20 == 4 || o->b20 == 5 || o->b20 == 8) func_L01_00441FB8(o, 1, 0);
        break;
    case 2:
        if (o->b20 == 0xD) break;
        if (func_L01_00452EF0(o) != 0 || o->b20 == 1) func_L01_00441FF8(o, 6, -1);
        if (p->s348 != -1 && p->s354 == -1) {
            a.x = func_00388960(func_00388A28(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
            a.y = func_00388978(func_00388A28(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
            f20 = o->fD0 * a.x + o->fD4 * a.y;
            a.z = 0.0f;
            if (p->s34C != 0) f20 = -f20;
            f21 = a.z;
            q = D_L01_0021F740_3AF290[p->s348];
            k = (u8 *)(q + 1);
            if (!(f21 < f20)) k += (q->n - 1) * 16;
            b = *(vu0_v4 *)k;
            vec_sub_ba(&b, &b, &o->v10);
            if (p->fA4 < func_00388770(&b)) {
                fa = f20 / func_00388770(&a);
                if (!(f21 < f20)) fa = -fa;
                func_003BEE20(&p->f33C, fa, 0.027777778f, 0.027777778f, 0.5f);
                func_00388830(&b, &b, p->f33C);
                c = o->v10;
                func_L01_00457728(o, &b);
                vec_sub_ba(&c, &o->v10, &c);
                vec_add_ab(&p->v300, &p->v300, &c);
            }
            func_L01_00445758(&o->fF8, &p->b124, p->f328, 0.027777778f, 0.027777778f, 1.6666667f, 0);
            if (func_00389468(o->fF8, p->f328) < 0.034906585f) {
                if (func_00388730(&o->vC0, &a) < 0.0f)
                    func_L01_00443A90(o, 0, 0x10000, &o->v10, 500.0f);
            }
        }
        if (p->s358 != 0 && p->h234 != 1)
            func_L01_004539A8(o, -1, 0, 0, 0, 0, 1, 0, 0, 0, 100.0f, 10.0f, 1.0f);
        if (p->h234 == 1) {
            if (o->b20 != 0xC) {
                if (func_00388800(&o->v10, &p->v220) < 10.0f) {
                    func_L01_00441FF8(o, 7, -1);
                    break;
                }
                if (o->b20 == 5) {
                    func_L01_00441FB8(o, 6, -1);
                    break;
                }
                if (o->b20 != 8) break;
                func_L01_00441FB8(o, 1, 0);
                break;
            }
        }
        if (o->b20 == 4 || o->b20 == 5 || o->b20 == 8) func_L01_00441FB8(o, 1, 0);
        break;
    }
    switch (o->b20) {
    case 2:
        if (o->b43 != 1) func_003BE4F0(o, 1, 0, 10);
        if (!(o->b60 & 2)) break;
        func_L01_00441FB8(o, 3, -1);
        break;
    case 11:
        if (func_L01_00452EC8(o) != 0) {
            p->fA8 |= 0x400;
            if (o->b43 != 1) func_003BE4F0(o, 1, 0, 10);
        }
        if (func_L01_00458AE0(o, p->s344) == 0) break;
        q11 = D_L01_0021F740_3AF290[p->s344];
        f20 = func_00388800(&o->v10, q11 + 1);
        if (func_00388800(&o->v10, q11 + q11->n) < f20) func_L01_00458E48(o, q11, 0, q11->n - 1);
        else func_L01_00458E48(o, q11, q11->n - 1, 0);
        break;
    case 4:
        if (func_L01_00452EC8(o) != 0) {
            if (o->b43 != 1) func_003BE4F0(o, 1, 0, 10);
            func_L01_00458A70(o, 0.0016666667f, 0.06666667f, 0.0008726647f, 0.029088823f);
        }
        func_L01_00458A08(o, func_00388A28(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
        if (func_00389468(o->fF8, func_00388A28(p->v220.x - o->v10.x, p->v220.y - o->v10.y)) < 0.017453292f)
            func_L01_00441FB8(o, 5, -1);
        break;
    case 12:
        if (func_L01_00452EC8(o) != 0) {
            p->fA8 |= 0x400;
            if (o->b43 != 1) func_003BE4F0(o, 1, 0, 10);
            if (p->s134 == 0) {
                q12 = D_L01_0021F740_3AF290[p->s340];
                f20 = func_00388800(&o->v10, q12 + 1);
                if (func_00388800(&o->v10, q12 + q12->n) < f20) func_L01_00458E48(o, q12, 0, 0);
                else func_L01_00458E48(o, q12, q12->n - 1, 0);
            }
        }
        if (func_L01_00458AE0(o, p->s340) != 0) {
            p->h2F4 = 1;
            func_L01_00441FB8(o, 1, -1);
        }
        break;
    case 6:
        r = func_L01_00452EC8(o);
        if (r != 0) {
            if (o->b43 != 0) func_003BE4F0(o, 0, 0, 10);
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
                p->s338 = func_0039FE80(0, 4, o);
        }
        d = (vu0_v4){0.0f, 0.0f, 1.0f, 0.0f};
        f21 = (f32)p->s2F8 * p->f2FC;
        func_003BDA38(o, 0, &a);
        if (p->s358 == 0) {
            vec_sub_ab(&b, &p->v300, &a);
        } else {
            f = func_00388A28(o->vC0.x, o->vC0.y);
            b.x = func_00388960(f) * p->f2C4;
            f = func_00388A28(o->vC0.x, o->vC0.y);
            b.y = func_00388978(f) * p->f2C4;
            b.z = 0.0f;
            vec_add_ba(&p->v300, &b, &o->v10);
        }
        if (p->f2C4 < func_00388770(&b)) {
            func_00388830(&b, &b, p->f2C4);
            vec_add_ba(&b, &b, &o->v10);
            b.z = p->v300.z;
            b.z = func_003BE7F0(&b, 0, 0, 0.5f);
            vec_sub_ba(&b, &b, &o->v10);
        }
        f = func_00388770(&b);
        func_00388830(&b, &b, f + p->f2E8);
        vec_add_ba(&c, &o->v10, &b);
        c.z = p->v300.z;
        c.z = func_003BE7F0(&c, 0, 0, 0.5f);
        vec_sub_ab(&c, &c, &o->v10);
        func_00389158(&c, &c, &d, p->f2EC);
        e = c;
        vec_add_ba(&e, &e, &o->v10);
        func_00388830(&c, &c, 0.5833334f);
        f = func_00388A28(func_00388800(&e, &a), a.z - e.z);
        f20 = func_003893C8(f, o->fF4);
        f = func_003893C8(func_00388A28(e.x - a.x, e.y - a.y), o->fF8);
        if (1.5707964f < f20) f20 = 1.5707964f;
        else if (f20 < 0.0f) f20 = 0.0f;
        if (1.5707964f < f) f = 1.5707964f;
        else if (f < -1.5707964f) f = -1.5707964f;
        p->f2A4 = f20;
        p->f2A8 = f;
        if (func_00388398(&p->s2F8) != 0) {
            t2 = p->s338;
            if (t2 != -1 && *(void **)((m = D_001A30B0 + (t2 << 7)) + 0xDC) == o && m[0xD0] != 0)
                func_0039FB08(t2);
            p->s338 = -1;
            func_L01_00441FB8(o, 8, -1);
        } else {
            f = func_003BE6A8(8.0f, -2.0f, f21);
            h6 = p->h2F6;
            fn = p->f2EC + (f32)h6 * 0.005f;
            p->f2E8 = f;
            p->f2EC = fn;
            if (0.2617994f < fabs_asm(fn)) p->h2F6 = -h6;
        }
        if (func_003883C8(&p->h332) == 0) break;
        func_L01_003AF630((u8 *)o, (void *)0);
        p->h332 = 5;
        break;
    case 7:
        if (func_L01_00452EC8(o) != 0) {
            if (o->b43 != 0) func_003BE4F0(o, 0, 0, 10);
            p->h330 = 10;
            p->h332 = 5;
            t3 = p->s338;
            if (t3 == -1 || *(void **)((m = D_001A30B0 + (t3 << 7)) + 0xDC) != o || m[0xD0] == 0)
                p->s338 = func_0039FE80(0, 4, o);
        }
        if (func_L01_0040C040(&o->v10, &p->v220) < 81.0f) {
            func_L01_00458A70(o, 0.0016666667f, 0.06666667f, 0.019392548f, 1.1635529f);
            if (p->s230 == D_001A4BE0_3AF290.x25C0) {
                func_003886E8(&a, (u8 *)&D_001A4BE0_3AF290 + 0x110, 10.0f);
                vec_add_ab(&p->v220, (u8 *)&D_001A4BE0_3AF290 + 0x80, &a);
            }
        } else {
            func_L01_00458A70(o, 0.0016666667f, 0.06666667f, 0.004848137f, 0.29088822f);
        }
        if (p->s348 == -1)
            func_L01_00458A08(o, func_00388A28(p->v220.x - o->v10.x, p->v220.y - o->v10.y));
        func_003BDA38(o, 0, &a);
        f20 = func_003893C8(func_00388A28(func_00388800(&p->v220, &a), a.z - p->v220.z), o->fF4);
        f = func_003893C8(func_00388A28(p->v220.x - a.x, p->v220.y - a.y), o->fF8);
        p->f2A4 = f20;
        p->f2A8 = f;
        if (func_003883C8(&p->h332) == 0) break;
        func_L01_003AF630((u8 *)o, (void *)1);
        p->h332 = 5;
        if (p->h330-- > 0) break;
        t4 = p->s338;
        if (t4 != -1 && *(void **)((m = D_001A30B0 + (t4 << 7)) + 0xDC) == o && m[0xD0] != 0)
            func_0039FB08(t4);
        p->s338 = -1;
        func_L01_00441FB8(o, 8, -1);
        break;
    case 9:
        if (func_L01_00452EC8(o) != 0) p->h332 = 60;
        if (func_003883C8(&p->h332) != 0) {
            o->s98 = *(s32 *)(o->p24 + 0x10);
            p->h2F4 = 1;
            func_L01_00441FB8(o, 10, -1);
        } else {
            *(f32 *)((u8 *)o + 0x18) = func_003BE6A8(p->f318 + 5.0f, p->f318, (f32)p->h332 / 60.0f);
        }
        break;
    case 13:
        if (func_L01_00452EC8(o) != 0) func_0039FE80(3, 0, o);
        r = func_L01_00451078(o, (u8 *)p + 0x160);
        t5 = p->s338;
        if (t5 != -1) {
            if (*(void **)((m = D_001A30B0 + (t5 << 7)) + 0xDC) == o && m[0xD0] != 0)
                func_0039FB08(t5);
            p->s338 = -1;
        }
        if ((r & 1) || p->f30 <= 0.0f) {
            func_L01_003AF958(o);
            return;
        }
        if (r & 2) func_L01_00441FB8(o, 1, o->b95);
        break;
    }
    if (o->b95 != 0) func_L01_0040AE68(o, p->h66, &D_001DE560_sda, 1.0f);
    func_L01_003AF490((S_0C60_O *)o);
}
/* localdecomp:end func_L01_003ADAC0 */
