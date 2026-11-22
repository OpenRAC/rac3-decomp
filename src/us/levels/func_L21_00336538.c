#include "common.h"

/* NTSC-U counterpart of func_L21_00336EF0 (src/levels/21_obani_draco/L21_00336EF0.c): 60 Hz timers (120, 60.0f, 60, 180, 300, 600) */
/* localdecomp:start func_L21_00336538 */
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 pad4[4];
    u8 f8;
    u8 f9;
    u8 fA;
    u8 padB[5];
    u8 f10;
    u8 f11;
    u8 f12;
    u8 pad13[5];
    u8 f18;
    u8 f19;
    s16 f1A;
    u8 pad1C[4];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad30[0x28];
    s32 f58;
    s32 f5C;
    u8 pad60[0x18];
    s16 f78;
    u8 f7A;
    u8 pad7B[2];
    u8 f7D;
    u8 pad7E;
    u8 f7F;
    u8 pad80[0x4C];
    s32 fCC;
    s32 fD0;
    s32 fD4;
    s32 fD8;
} V_00336538;

typedef struct {
    s32 (*f0)(u8 *, s32);
    s32 (*f4)(u8 *);
    u8 pad8[0xC];
    void (*f14)(u8 *, s32);
    u8 pad18[4];
    s32 (*f1C)(u8 *);
    u8 pad20[0x10];
    s32 (*f30)(u8 *);
    u8 pad34[0xC];
    s32 (*f40)(u8 *);
} VT_00336538;

typedef struct {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x14];
    s16 f3C;
    u8 pad3E[0xA];
    s16 f48;
    u8 pad4A[0x22];
    s32 f6C;
    u8 pad70[6];
    s16 f76;
    u8 pad78[0x1C];
    s32 f94;
    s16 f98;
    u8 pad9A[4];
    s16 f9E;
} S_00336538;

extern s32 func_L21_00337200(void *arg0);
extern void func_L21_00337238(void *arg0);
extern void func_L21_003376D8(void *arg0);
extern void func_L21_00337798(void *arg0);
extern void func_L21_00337820(void *arg0);
extern void func_L21_003379F0(void *arg0, s32 count);
extern void func_L21_00337C80(void *arg0, s32 arg1);
extern void func_L21_00337DF8(void *arg0);
extern void func_L21_00338148(u8 *arg0);
extern s32 func_L21_00338268(void *arg0);
extern s32 func_L21_00338310(void *arg0, u8 *arg1);
extern s32 func_L21_00338380(void);
extern s32 func_L21_003383A8_00336538(void *arg0, u8 *arg1);
extern void func_L21_003386D0(void *arg0);
extern s32 func_L21_003A8618(void *arg0);
extern s32 func_L21_003A8640(void *arg0);
extern void func_L01_0035FC40(void *);
extern s32 func_003883C8(void *);
extern void func_00399F90(void);
extern VT_00336538 *func_L01_00438488(s32, s32, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
void func_L01_00441FB8(s32, s32, s32);
extern void func_L01_00442038(u8 *a, u8 v);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L01_00452EF0(void *);
extern void func_L01_00452F40(u8 *, s32);
extern void func_L01_00456808(void);
extern void func_0039C710(void);
extern void func_L01_0045BE58(s32, s32);
extern void func_0039CBA0(void);
extern void func_0039DAE0(s32, s32);
extern s32 func_L01_004B6C68(void);

extern u8 *const D_L21_001DEE1C;
__asm__(".extern D_L21_001DEE1C, 16");
extern const s32 D_L21_001DEE58;
extern u16 *D_L21_0021B8E0[];
extern u8 D_001A4C60[];
extern S_00336538 D_001CCFD0;
extern s32 D_00142668[];
extern s32 D_001A7430[];
extern u8 D_001426E0[];
typedef struct {
    u8 pad0[0x1DC];
    s16 f1DC;
    u8 pad1DE[0x25C4 - 0x1DE];
    s32 f25C4;
    u8 pad25C8[0x2850 - 0x25C8];
    s32 f2850;
} G_00336538;
extern G_00336538 D_001A4BE0;
extern s32 D_L21_001D6694;
extern s32 D_L21_001D6690;
extern s32 D_L21_001E06D4;
__asm__(".extern D_L21_001E06D4, 4");
extern f32 D_L21_001E06D0;
__asm__(".extern D_L21_001E06D0, 4");
extern f32 D_L21_001DEA30;

void func_L21_00336538(u8 *arg0) {
    V_00336538 *v;
    VT_00336538 *fn;
    u8 *base;
    u8 *m;
    u16 *p;
    s32 n;
    f32 f;

    if (func_L21_00337200(arg0)) {
        return;
    }
    v = *(V_00336538 **)(arg0 + 0x68);
    base = 0;
    fn = 0;
    if (arg0[0x20] != 8) {
        base = D_L21_001DEE1C + (v->f24 << 8);
        fn = func_L01_00438488(0x1BC5, 0, 0x44);
        if (base == 0) {
            return;
        }
        if (fn == 0) {
            return;
        }
        func_L21_00337238(arg0);
    }

    switch (arg0[0x20]) {
    case 1:
        if (v->f20 == -1) {
            break;
        }
        if (!func_0037E0F0(D_001A4C60, v->f20, 0)) {
            break;
        }
        if ((D_001CCFD0.f3C != -1 ? D_001CCFD0.f3C : D_001CCFD0.f48) != v->fD8) {
            func_L01_0045BE58(v->fD8, -1);
        }
        D_001A7430[0] = D_00142668[0];
        if (D_001426E0[0xD5] & 1) {
            func_L01_00456808();
        }
        if (v->f58 != -1) {
            for (p = D_L21_0021B8E0[v->f58];
                 (v->f58 & 0xFF) != 0xFF && v->f58 <= D_L21_001DEE58 && p != 0 &&
                 ((s16)p[-1] >= 0 || p == D_L21_0021B8E0[v->f58]);) {
                m = D_L21_001DEE1C + ((*p++ & 0x7FFF) << 8);
                if (m == 0) {
                    break;
                }
                *(u16 *)(m + 0x34) |= 2;
            }
            {
            u16 *q;
            u8 *e;
            q = D_L21_0021B8E0[v->f28];
            while ((v->f28 & 0xFF) != 0xFF && v->f28 <= D_L21_001DEE58 && q != 0 &&
                   ((s16)q[-1] >= 0 || q == D_L21_0021B8E0[v->f28])) {
                e = D_L21_001DEE1C + ((*q & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                *(u8 **)(e + 0xB8) = arg0;
                q++;
            }
            }
            *(u8 **)(base + 0xB8) = arg0;
            {
            u16 *q;
            u8 *e;
            q = D_L21_0021B8E0[v->f2C];
            while ((v->f2C & 0xFF) != 0xFF && v->f2C <= D_L21_001DEE58 && q != 0 &&
                   ((s16)q[-1] >= 0 || q == D_L21_0021B8E0[v->f2C])) {
                e = D_L21_001DEE1C + ((*q & 0x7FFF) << 8);
                if (e == 0) {
                    break;
                }
                *(s32 *)(*(u8 **)(e + 0x68) + 0x58) = 1;
                q++;
            }
            }
        }
        func_L01_00441FB8((s32)arg0, 2, -1);
        break;
    case 2:
        if (func_L01_00452EC8(arg0)) {
            func_L21_003386D0(arg0);
            v->f78 = 120;
            fn->f14(base, v->f2);
        }
        if (func_003883C8(&v->f78)) {
            func_L21_00337798(arg0);
            func_L21_003379F0(arg0, v->f0);
            func_L21_00337C80(arg0, v->f1);
            func_L21_00337DF8(arg0);
            func_L21_00338148(arg0);
            if (func_L21_00338268(arg0)) {
                func_L01_00441FB8((s32)arg0, 3, -1);
            }
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(arg0)) {
            func_L21_003386D0(arg0);
            v->f78 = (f32)func_0037E208(0x2D, 0x37) * 60.0f;
            fn->f14(base, v->f2);
        }
        if (fn->f30(base)) {
            v->f19 = 0;
            func_L21_003376D8(arg0);
        } else if (fn->f40(base)) {
            if (v->f19 < v->f3) {
                v->f19++;
                fn->f0(base, 1);
            } else if (v->f19 % 2) {
                v->f19++;
                fn->f4(base);
            } else {
                func_L21_00337798(arg0);
            }
        }
        if (!func_L21_003A8640(base)) {
            if (func_003883C8(&v->f78) || func_L21_00338310(arg0, &v->f2) ||
                ((s32 (*)(void *))func_L21_00338380)(arg0)) {
                func_L01_00441FB8((s32)arg0, 4, -1);
            }
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(arg0)) {
            v->f7D = 0;
            func_L21_003386D0(arg0);
            fn->f14(base, v->fA);
        }
        func_L21_00337798(arg0);
        func_L21_003379F0(arg0, v->f8);
        func_L21_00337C80(arg0, v->f9);
        func_L21_00337DF8(arg0);
        func_L21_00338148(arg0);
        if (func_L21_00338268(arg0)) {
            func_L01_00441FB8((s32)arg0, 5, -1);
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        break;
    case 5:
        if (func_L01_00452EC8(arg0)) {
            func_L21_003386D0(arg0);
            v->f78 = (f32)func_0037E208(0x2D, 0x37) * 60.0f;
            arg0[0xBC] = 1;
            fn->f14(base, v->fA);
        }
        if (func_L01_00452EC8(arg0)) {
            v->f78 = func_0037E208(0x2D, 0x37);
        }
        if (fn->f30(base)) {
            v->f19 = 0;
            func_L21_003376D8(arg0);
        } else if (fn->f40(base)) {
            n = func_L21_003383A8_00336538(arg0, &v->fA);
            if (v->f19 < n) {
                v->f19++;
                fn->f0(base, arg0[0xBC]);
            } else if (v->f19 % 2) {
                v->f19++;
                fn->f4(base);
            } else {
                arg0[0xBC]++;
                if (arg0[0xBC] >= 3) {
                    arg0[0xBC] = 1;
                }
                func_L21_00337798(arg0);
            }
        }
        if (func_003883C8(&v->f78) || ((s32 (*)(void *))func_L21_00338380)(arg0)) {
            func_L01_00441FB8((s32)arg0, 6, -1);
        }
        if (!func_L21_003A8640(base) && func_L21_00338310(arg0, &v->fA)) {
            func_L01_00441FB8((s32)arg0, 7, -1);
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        break;
    case 6:
        if (func_L01_00452EC8(arg0)) {
            v->f7D = 0;
            func_L21_003386D0(arg0);
        }
        func_L21_003379F0(arg0, v->f10);
        func_L21_00337C80(arg0, v->f11);
        func_L21_00337DF8(arg0);
        func_L21_00338148(arg0);
        if (!func_L21_003A8640(base) && func_L21_00338310(arg0, &v->fA)) {
            if (func_L21_00338268(arg0)) {
                func_L01_00441FB8((s32)arg0, 7, -1);
            } else {
                func_L21_00337798(arg0);
            }
            break;
        }
        if (v->f7A == 0 || fn->f1C(base) == 2) {
            if (fn->f30(base)) {
                v->f18 = 0;
                func_L21_003376D8(arg0);
            } else if (fn->f40(base)) {
                fn->f4(base);
            }
        } else {
            func_L21_00337798(arg0);
        }
        if (func_L21_00338268(arg0)) {
            func_L01_00441FB8((s32)arg0, 5, -1);
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(arg0)) {
            func_L21_003386D0(arg0);
            arg0[0xBC] = 0;
            v->f18 = 0;
            fn->f14(base, v->f12);
        }
        if (func_L21_003A8618(base)) {
            func_L01_00441FB8((s32)arg0, 8, -1);
        }
        n = fn->f1C(base);
        if (n == 0) {
            v->f19 = 0;
            v->f7F = 0;
            func_L21_00337820(arg0);
            break;
        }
        if (n == 2) {
            func_L21_00337798(arg0);
            break;
        }
        if (fn->f40(base)) {
            n = func_L21_003383A8_00336538(arg0, &v->f12);
            if (v->f19 < n) {
                v->f19 += fn->f0(base, arg0[0xBC]);
            } else if (v->f7F == 0) {
                v->f7F = fn->f0(base, 3);
            } else {
                if (((s32 (*)(void *))func_L21_00338380)(arg0)) {
                    fn->f4(base);
                }
                arg0[0xBC]++;
                if (v->f18 < arg0[0xBC]) {
                    arg0[0xBC] = 0;
                }
                v->f18++;
                if (v->f18 >= 3) {
                    v->f18 = 0;
                }
                func_L21_00337798(arg0);
            }
        }
        break;
    case 8:
        if (func_L01_00452EC8(arg0)) {
            v->f78 = 60;
            arg0[0xBC] = 0;
        }
        if (arg0[0xBC] == 0) {
            if (func_003883C8(&v->f78) && arg0[0x95] == 0 &&
                D_001A4BE0.f2850 > 0 && D_001A4BE0.f25C4 != 0x79) {
                arg0[0xBC] = 1;
                D_001A4BE0.f1DC = 180;
                func_L01_00452F40(D_L21_001DEE1C + (v->f5C << 8), 1);
                func_0039CBA0();
            }
        } else if (D_L21_001D6694 != 2 && D_L21_001D6690 != 2 && !func_L01_004B6C68()) {
            if (v->f58 != -1) {
                for (p = D_L21_0021B8E0[v->f58];
                     (v->f58 & 0xFF) != 0xFF && v->f58 <= D_L21_001DEE58 && p != 0 &&
                     ((s16)p[-1] >= 0 || p == D_L21_0021B8E0[v->f58]);) {
                    m = D_L21_001DEE1C + ((*p++ & 0x7FFF) << 8);
                    if (m == 0) {
                        break;
                    }
                    *(u16 *)(m + 0x34) &= ~2;
                }
            }
            n = 1;
            do {
                D_001426E0[0x2D] = n;
            } while (0);
            func_00399F90();
            if ((D_001CCFD0.f3C != -1 ? D_001CCFD0.f3C : D_001CCFD0.f48) != v->fD4) {
                func_L01_0045BE58(v->fD4, -1);
            }
        }
        break;
    }

    switch (arg0[0x95]) {
    case 1:
        if (func_L01_00452EF0(arg0)) {
            v->f1A = 300;
        } else if (func_003883C8(&v->f1A)) {
            func_L01_00442038(arg0, 0);
        }
        if (D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) {
            func_0039DAE0(v->fCC + 2000, (s32)base);
        }
        if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 7000) {
            func_0039C710();
            func_L01_00442038(arg0, 2);
        }
        break;
    case 2:
        if (func_L01_00452EF0(arg0)) {
            v->f1A = 600;
        }
        if ((D_001CCFD0.f6C == 0 && D_001CCFD0.f24 == -1 && D_001CCFD0.f94 == 0) ||
            func_003883C8(&v->f1A)) {
            func_L01_00442038(arg0, 0);
        }
        break;
    }

    func_L01_0035FC40(arg0);
    if (D_L21_001E06D4 == 0) {
        D_L21_001E06D4 = 1;
        D_L21_001E06D0 = D_L21_001DEA30;
    }
    if (v->fD0 == -1 || !func_0037E0F0(D_001A4C60, v->fD0, 0)) {
        f = D_L21_001E06D0;
    } else {
        f = 1000.0f;
    }
    D_L21_001DEA30 = f;
}
/* localdecomp:end func_L21_00336538 */
