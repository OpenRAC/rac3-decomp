#include "common.h"

typedef struct { char pad[0xF0]; void (*fn)(void *); } VT;
typedef struct { char pad[0x60]; VT *vt; } Obj;

/* declared by functions of L39_0068B768.c, which this file was cut from */
extern s32 D_001DC3F4_sda;

/* declared by functions of L39_0068B950.c, which this file was cut from */
extern s32 func_00381FF0(s32);

/* localdecomp:start func_L39_0068BAD8 */
typedef struct { char pad[0x18]; s32 f18; } I_0068BAD8;
typedef struct { s32 f0; s32 n; I_0068BAD8 **arr; } L_0068BAD8;
typedef struct { u8 f0; char pad[0xC]; u8 fD; char pad2[6]; L_0068BAD8 list; } Q_0068BAD8;
typedef struct { char pad[0x28]; s32 f28; u8 f2C; } C_0068BAD8;
typedef struct { char pad[0x30]; C_0068BAD8 *f30; char pad2[0x44]; Q_0068BAD8 *f78; } G_0068BAD8;
typedef struct { char pad[0x30]; s32 *f30; char pad2[0x10]; s32 f44; char pad3[0x30]; s32 f78; } M_0068BAD8;
typedef struct { char pad[0x280]; u8 f280; char pad2[3]; s32 f284; } W_0068BAD8;
typedef struct { char pad[0x5E]; char name[0x12]; s32 f70; char pad1[0x100]; s32 f174; char pad2[0x16C]; u8 f2E4; } P_0068BAD8;
typedef struct { char pad[0x1D]; char name[0xCF]; u8 fEC; char pad2[0x103]; } E_0068BAD8;
typedef struct { s32 f0; s32 f4; u8 f8; char pad[0x1F]; } R_0068BAD8;
typedef struct {
    char pad[0x290]; s32 f290; char pad2[0x26]; u8 f2BA; u8 f2BB; char f2BC[0x30];
    s32 f2EC; char pad3[4]; char f2F4[0x40]; s32 f334; s32 f338;
} S_0068BAD8;

extern s32 D_001A43E0[];
extern P_0068BAD8 D_001A5CD0;
extern E_0068BAD8 D_001FC6B0[];
extern R_0068BAD8 D_001FD630[];
extern W_0068BAD8 *D_00247914;
__asm__(".extern D_00247914, 16");
extern M_0068BAD8 *D_0024D760;
__asm__(".extern D_0024D760, 16");
extern s32 D_0024D770;
__asm__(".extern D_0024D770, 16");
extern s32 D_0024D7A8;
__asm__(".extern D_0024D7A8, 16");
extern s32 D_001E205C_sda;
extern G_0068BAD8 *D_001E2050_sda;
extern W_0068BAD8 *D_001DC204_sda;
extern u8 D_001DC324_sda;

extern s32 func_L39_0068B8B0(void);
extern void func_L39_0068C918(S_0068BAD8 *);
extern s32 func_00381FF0(s32);
extern s32 func_L39_006878A0(W_0068BAD8 *, s32, s32, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_006872E8(W_0068BAD8 *, s32, s32, s32, s32, f32);
extern void func_L39_0068CBE8(S_0068BAD8 *, s32);
extern void func_L01_004981E0(s32, s32);
extern s32 func_L39_0068C210(S_0068BAD8 *);
extern s32 func_L39_0068C4E0(S_0068BAD8 *, s32);
extern void func_L39_006DF018(void);
extern void func_L39_006DF118(void);
extern s32 func_001206F4(char *, char *);
extern s32 func_L39_006D7018(s32);
extern s32 func_L39_006D8E30(G_0068BAD8 *);
extern s32 func_00198578(void);
extern char *func_001375B0(char *, char *, s32);
extern s32 func_L39_0067EB98(void);
extern void func_L39_0068B478(char *);
extern void func_L39_00689AC8(S_0068BAD8 *, char *);
extern s32 func_L39_0067EBD0(void);
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern void func_L39_006D6E30(s32, s32, s32 *);
extern s32 func_L39_006877B0(W_0068BAD8 *, s32);


static __inline__ u8 swap_0068BAD8(W_0068BAD8 *w, u8 v) { u8 o = w->f280; w->f280 = v; return o; }

s32 func_L39_0068BAD8(Obj *a, s32 *state) {
    S_0068BAD8 *p = (S_0068BAD8 *)a;
    s32 buf[100];
    s32 buf2[100];

    if (D_001A43E0[0x57] >= 3) goto done;
    if (D_001A43E0[0x59] >= 0) goto done;
    if (func_L39_0068B8B0() != 0) goto done;
    func_L39_0068C918(p);
    if (p->f338 == 0 && p->f2BB == 0) {
        s32 s;
        do { s = *state; } while (0);
        if (s == 7) {
            s32 idx = p->f290 - 1;
            s = idx == p->f334;
            if (!s && D_001A43E0[2] == 2) {
                W_0068BAD8 *m = D_00247914;
                s32 r = func_L39_006878A0(m, func_00381FF0(0x1923), func_00381FF0(0x1255), 1);
                if (r != 0) {
                    if (r != 1) goto done;
                    func_L39_00688340(4, 0, 0);
                    m = D_00247914;
                    r = func_L39_006872E8(m, func_00381FF0(0x1255), func_00381FF0(0x1031), 0x43, 0, 0.6f);
                    if (r == 0x40) goto done;
                    if (r == 1) func_L39_0068CBE8(p, idx);
                    goto done;
                }
            }
            func_L39_00688340(4, 0, 0);
            func_L01_004981E0(idx, s);
            D_00247914->f284 = 0x1D;
            goto done;
        }
        if (s == 6 && D_001A5CD0.f174 == 0) {
            s32 idx = p->f290 - 1;
            s32 off = idx * 0x1F0;
            if (((E_0068BAD8 *)((char *)D_001FC6B0 + off))->fEC != 0) {
                s32 i;
                func_L39_00688340(4, 0, 0);
                if (func_L39_0068C210(p) == 0) goto done;
                if (func_L39_0068C4E0(p, idx) == 0) goto done;
                p->f338++;
                func_L39_006DF018();
                func_L39_006DF118();
                func_001206F4(D_001A5CD0.name, D_001FC6B0[idx].name);
                if (func_L39_006D7018(D_0024D760->f78)) p->f2BB = 1;
                for (i = 0; i < 11; i++) {
                    D_001FD630[i].f0 = -1;
                    D_001FD630[i].f4 = 0;
                    D_001FD630[i].f8 = 0;
                }
                p->f338--;
                D_0024D770 = 0;
                D_0024D7A8 = 0;
                D_001E205C_sda = 0;
                goto done;
            }
            func_L39_00688340(5, 0, 0);
            {
                W_0068BAD8 *m = D_00247914;
                func_L39_006872E8(m, func_00381FF0(0x1EBF), 0, 4, 0, 0.6f);
            }
        } else if (s == 5) {
            func_L39_00688340(0x17, 0, 0);
            if (D_001A5CD0.f174 == 0) {
                W_0068BAD8 *m = D_00247914;
                s32 r = func_L39_006872E8(m, func_00381FF0(0xF5F), func_00381FF0(0x1031), 3, 0, 0.6f);
                if (r == 1) {
                    s32 old = swap_0068BAD8(D_00247914, r);
                    p->f338++;
                    if (D_001A5CD0.f2E4 == r) func_L39_006D8E30(D_001E2050_sda);
                    func_00198578();
                    D_00247914->f280 = old;
                    func_001375B0(p->f2BC, p->f2F4, 0x40);
                    if (p->f2EC != 5) {
                        p->f2BA = r;
                        func_L39_0067EB98();
                    } else {
                        D_001DC204_sda->f284 = 0x18;
                    }
                }
            } else {
                D_001DC324_sda = 1;
                return 1;
            }
            goto done;
        }
    }
    if (p->f2BA) {
        func_001375B0(p->f2BC, p->f2F4, 0x40);
        func_L39_0068B478(p->f2F4);
        func_L39_00689AC8(p, p->f2F4);
        if (p->f2EC != 5) {
            if (func_L39_0067EBD0() < 30001) goto done;
        }
        p->f2BA = 0;
        D_00247914->f284 = 0x18;
        goto done;
    }
    if (p->f2BB) {
        Q_0068BAD8 *q = D_001E2050_sda->f78;
        if (q->f0 == 0) {
            s32 v = 0;
            s32 found;
            p->f2BB = 0;
            found = func_L39_006D6E50(D_0024D760->f44, *D_0024D760->f30, 0, buf);
            if (found == 1) {
                L_0068BAD8 *l;
                s32 i;
                v = buf[0];
                l = q->fD ? &q->list : 0;
                found = 0;
                for (i = 0; i < l->n; i++) {
                    s32 x = l->arr[i]->f18;
                    if ((u32)(x - 0x28) < 0x3C && v == x) {
                        found = 1;
                        break;
                    }
                }
            }
            if (v == 0 || !found) {
                s32 h;
                goto test;
                do {
                    v = func_L39_006877B0(D_001DC204_sda, 0);
                test:;
                } while ((u32)(v - 0x28) >= 0x3C);
                h = D_0024D760->f44;
                if (func_L39_006D6E50(h, *D_0024D760->f30, 0, buf2)) {
                    buf2[0] = v;
                    func_L39_006D6E30(h, 0, buf2);
                }
            }
            if (v) {
                D_001E2050_sda->f30->f28 = v;
                D_001A5CD0.f70 = v;
                if (D_001E2050_sda->f30->f2C == 0) D_001DC204_sda->f284 = 0x14;
                else D_001DC204_sda->f284 = 2;
            }
        }
    }
    if (p->f338 != 0 || p->f2BB != 0) {
done:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0068BAD8 */
