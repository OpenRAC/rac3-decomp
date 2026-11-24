#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { char p[0x444]; int f444; char q[0x470-0x448]; u128_t v; } B;
typedef struct { char p[0x10]; u128_t v; char q[0x68-0x20]; B *b; } A;

/* localdecomp:start func_L19_003C0938 */
extern void func_L19_003C2628(void *, void *, int, float);

void func_L19_003C0938(char *m) {
    func_L19_003C2628(m, m + 0x10, 3, *(float *)(m + 0xF8));
}
/* localdecomp:end func_L19_003C0938 */

/* localdecomp:start func_L19_003C0960 */
typedef struct { f32 x, y, z, w; } V_3C0960 __attribute__((aligned(16)));
__asm__(".extern D_L19_001DE83C, 4");
__asm__(".extern D_L19_001DE844, 4");
__asm__(".extern D_L19_001DE848, 4");
__asm__(".extern D_L19_001DE84C, 4");
__asm__(".extern D_L19_001DE850, 4");
__asm__(".extern D_L19_001DE854, 4");
__asm__(".extern D_L19_001DE858, 4");
__asm__(".extern D_L19_001DE85C, 4");
__asm__(".extern D_L19_001DE860, 4");
__asm__(".extern D_L19_001DE870, 4");
__asm__(".extern D_L19_001DE878, 4");
extern f32 D_L19_001DE83C;
extern s32 D_L19_001DE844;
extern f32 D_L19_001DE848;
extern f32 D_L19_001DE84C;
extern f32 D_L19_001DE850;
extern f32 D_L19_001DE854;
extern f32 D_L19_001DE858;
extern f32 D_L19_001DE85C;
extern f32 D_L19_001DE860;
extern f32 D_L19_001DE870;
extern s32 D_L19_001DE878;
extern u8 *D_L19_0021D500[];
extern u8 D_001A4C60[];
extern u8 *D_001A73E8[];
extern s32 func_L01_0044C108(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_003C2880(void *);
extern void func_L19_003C1F18(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L19_003C2A98(u8 *);
extern s32 func_L01_004561E0(void *);
extern u8 *func_00382348(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L01_004395E0(u8 *);
extern void func_L01_0045AA30(void *, void *);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L19_003C0938(char *);
extern void func_003C4C18(void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382468(s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L19_003C2628(void *, void *, int, float);
typedef void (*Move_3C0960)(void *, void *, f32, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038DB48(f32);
extern void func_L19_003C27A8(u8 *);
extern void func_L19_003C0910(char *);
extern s32 func_L01_00454370(void *, void *);
extern void func_L19_003C2A20(void *);
extern void func_L19_003C2930(void *);
extern void func_L19_003C29D0(A *);

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0xA];
    u8 f3E;
    u8 pad3F[0x31];
    f32 f70;
    f32 f74;
    u8 pad78[0x7C];
    u8 *fF4;
    u8 padF8[0x4];
    s32 fFC;
    u8 pad100[0x10];
    f32 f110;
    f32 f114;
    f32 f118;
    u8 pad11C[0x44];
    V_3C0960 f160;
    u8 pad170[0x20];
    f32 f190;
    f32 f194;
    u8 pad198[0x88];
    V_3C0960 f220;
    u8 *f230;
    s16 f234;
    u8 pad236[0x1DE];
    s16 f414;
    s16 f416;
    u8 pad418[0x4];
    s32 f41C;
    u8 pad420[0x10];
    s32 f430;
    s32 f434;
    s32 f438;
    f32 f43C;
    u8 pad440[0x8];
    f32 f448;
    u8 pad44C[0xC];
    s32 f458;
    s32 f45C;
    V_3C0960 f460;
    V_3C0960 f470;
} P_3C0960;
void func_L19_003C0960(u8 *obj) {
    P_3C0960 *p;
    V_3C0960 v10;
    V_3C0960 v20;
    V_3C0960 v30;
    V_3C0960 v40;

    if (func_L01_0044C108(obj + 0x10) == 0)
        return;
    p = *(P_3C0960 **)(obj + 0x68);
    if (obj[0x20] == 0 && func_0038CF38(obj + 0x10, D_001A4C60) < 9.0f) {
        func_003C2880(obj);
        return;
    }
    func_L19_003C1F18(obj);
    if (obj == 0 || obj[0x20] == 0xFE || obj[0x20] == 0xFD)
        return;
    if (obj[0x20] != 0x10) {
        switch (obj[0x95]) {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
            if (p->f234 == 1) {
                func_L01_004450F0(obj, 9, 6);
                func_L19_003C2A98(obj);
            }
            break;
        case 5:
            if (func_L01_004561E0(obj) != 0)
                p->f416 = 500;
            if (p->f234 == 1) {
                func_L01_004450F0(obj, 9, 6);
                func_L19_003C2A98(obj);
            }
            if (p->f416 <= 0)
                func_L01_004450F0(obj, 6, 4);
            break;
        case 6:
            if (p->f234 == 0)
                func_L01_004450F0(obj, 8, 5);
            if (p->f230 != 0) {
                u8 *q = func_00382348(p->f230);
                if (q != 0)
                    q[0x31] = 0xFF;
            }
            break;
        case 7:
            if (func_L01_004561E0(obj) != 0)
                func_L19_003C2A98(obj);
            break;
        }
    }
    switch (obj[0x20]) {
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(obj, 1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) &= 0xEFFF;
            p->f3E = 3;
            if (obj[0x43] != 2)
                func_003C3A10(obj, 2, 0, 0);
        }
        if (p->f234 == 1) {
            func_L19_003C2A98(obj);
            func_L01_004450F0(obj, 3, -1);
        }
        func_L19_003C0910((char *)obj);
        break;
    case 3:
        if (func_L01_004561B8(obj) != 0)
            p->f414 = (func_00382498(0x1E, 0x5A) * 5 + 2) / 6;
        if (p->f414 <= 0)
            func_L01_004450F0(obj, 4, -1);
        break;
    case 4: {
        s32 i;
        f32 d;
        f32 t;
        f32 a;
        f32 r;
        f32 h;
        s32 n;
        s32 k;
        if (func_L01_004561B8(obj) != 0) {
            *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
            *(u16 *)(obj + 0x34) |= 0x1000;
            if (obj[0x43] != 3)
                func_003C3A10(obj, 3, 0, 0);
        }
        if (obj[0x43] == 3 && obj[0x42] == obj[0x43]) {
            d = func_L01_004395E0(obj);
            qzero(&v10);
            t = 1.0f - (d - 0.0f) / 10.0f;
            v10.z = D_L19_001DE85C * t * t;
            ((s32 (*)(void *, void *))func_L01_0045AA30)(obj, &v10);
            for (i = 0; i < D_L19_001DE844; i++) {
                a = func_00382538();
                v20.x = func_0038D098(a) * p->f70;
                v20.y = func_0038D0B0(a) * p->f70;
                v20.z = 0.0f;
                vec_add_ba(&v20, &v20, obj + 0x10);
                v20.z = v20.z + p->f70;
                r = func_003824E0(0.5f, 2.0f) * 0.020000001f;
                v30.x = func_0038D098(a) * r;
                v30.y = func_0038D0B0(a) * r;
                v30.z = 0.0f;
                h = func_003824E0(0.01f, 0.25f);
                qzero(&v40);
                v30.z = v10.z * h;
                v30.w = 0.05f;
                v40.z = -0.020000001f;
                v40.w = 0.05f;
                n = (func_00382498(4, 0xC) * 5 + 2) / 6;
                k = (func_00382498(0x14, 0x46) * 5 + 2) / 6;
                func_L01_00463378(&v20, &v30, &v40, -1, -1, n, k, (func_00382498(0x1E, 0x2D) * 5 + 2) / 6, 0x10060);
            }
            if (10.0f <= d) {
                p->f448 = 0.0f;
                p->f3E = 1;
                if (obj[0x43] != 4)
                    func_003C3A10(obj, 4, 0, 0);
            }
        } else if (obj[0x43] == 4 && obj[0x42] == obj[0x43]) {
            qzero(&v10);
            p->f448 = p->f448 - 0.002f;
            v10.z = p->f448;
            ((s32 (*)(void *, void *))func_L01_0045AA30)(obj, &v10);
            if (*(f32 *)(obj + 0x18) <= p->f470.z + 0.05f) {
                *(f32 *)(obj + 0x18) = p->f470.z;
                if (obj[0x43] != 5)
                    func_003C3A10(obj, 5, 0, 0);
            }
        }
        if (obj[0x43] == 5 && func_L01_0044E1B8(obj, 28.0f) != 0) {
            func_L01_004450F0(obj, 9, 6);
            func_L19_003C0910((char *)obj);
        }
        break;
    }
    case 5: {
        s32 i;
        s32 col;
        s32 n;
        if (func_L01_004561B8(obj) != 0) {
            if (obj[0x43] != 6)
                func_003C3A10(obj, 6, 0, 0);
            p->fFC = 0;
        }
        v10 = *(V_3C0960 *)(obj + 0x10);
        *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), 0.25132743f);
        func_L19_003C0938((char *)obj);
        for (i = 0; i < 2; i++) {
            qzero(&v20);
            func_003C4C18(&v20, 0.010000001f);
            qzero(&v30);
            v20.w = 0.5f;
            func_003C4C18(&v30, 0.002f);
            qzero(&v40);
            v30.w = 0.75f;
            func_003C4C18(&v40, 0.25f);
            vec_add_ab(&v40, &v40, obj + 0x10);
            col = func_0038DBD8(0x60202020, 0x60707070, func_003824E0(0.0f, 1.0f));
            n = ((func_00382468(0xF) + 0x1E) * 5 + 2) / 6;
            func_L01_00463378(&v40, &v20, &v30, col, 0x30707070, 8, n, ((func_00382468(0xF) + 5) * 5 + 2) / 6, -1);
        }
        if (p->f448 < 0.0f && p->fFC != 0) {
            *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
            *(f32 *)(obj + 0xF4) = 0.0f;
            p->f3E = 1;
            func_L01_004450F0(obj, 6, 4);
        }
        break;
    }
    case 6:
        if (func_L01_004561B8(obj) != 0 || (obj[0x43] == 1 && (obj[0x60] & 2) && obj[0x42] == obj[0x43])) {
            if (obj[0x43] != 0)
                func_003C3A10(obj, 0, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x48))[0x10]), 8);
            p->f414 = (func_00382498(0xB4, 0x168) * 5 + 2) / 6;
        }
        if (p->f414 == 0) {
            p->f414 = -1;
            if (obj[0x43] != 1)
                func_003C3A10(obj, 1, 0, 8);
        }
        if (p->f434 != 0)
            func_L01_004450F0(obj, 7, 4);
        func_L19_003C0910((char *)obj);
        break;
    case 7: {
        f32 a;
        u8 *path;
        s32 n;
        if (func_L01_004561B8(obj) != 0) {
            if (obj[0x43] != 9)
                func_003C3A10(obj, 9, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x6C))[0x10]), 8);
            p->f414 = (func_00382498(0x168, 0x1E0) * 5 + 2) / 6;
            p->f460 = *(V_3C0960 *)(obj + 0x10);
        }
        if (p->f414 == 0) {
            p->f414 = -1;
            if (obj[0x43] != 1)
                func_003C3A10(obj, 1, 0, 8);
        }
        if (obj[0x43] == 1) {
            if ((obj[0x60] & 2) && obj[0x42] == obj[0x43]) {
                if (obj[0x42] != 9)
                    func_003C3A10(obj, 9, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x6C))[0x10]), 8);
                p->f414 = (func_00382498(0x168, 0x1E0) * 5 + 2) / 6;
            }
            func_L19_003C0910((char *)obj);
            break;
        }
        ((Move_3C0960)func_L19_003C2628)(obj, &p->f460,
                                         func_0038D160(p->f460.x - *(f32 *)(obj + 0x10), p->f460.y - *(f32 *)(obj + 0x14)), 1);
        if (func_L01_0040E570(obj + 0x10, &p->f460) < D_L19_001DE83C * D_L19_001DE83C) {
            if (p->f430 >= 0) {
                path = D_L19_0021D500[p->f430];
                n = p->f438;
                p->f460 = *(V_3C0960 *)(path + n * 16 + 0x10);
                p->f438 = n + 1;
                if (n + 1 >= *(s32 *)path)
                    p->f438 = 0;
            } else {
                a = func_00382538();
                p->f460.x = func_0038D098(a) * p->f43C;
                p->f460.y = func_0038D0B0(a) * p->f43C;
                p->f460.z = 0.0f;
                vec_add_ab(&p->f460, &p->f460, &p->f470);
            }
        }
        break;
    }
    case 8:
        if (func_L01_004561B8(obj) != 0 || p->f414 <= 0) {
            if (obj[0x43] != 1)
                func_003C3A10(obj, 1, 0, 5);
        }
        if (obj[0x43] == 1 && (obj[0x60] & 2) && obj[0x42] == obj[0x43]) {
            if (obj[0x42] != 0)
                func_003C3A10(obj, 0, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x48))[0x10]), 5);
            p->f414 = (func_00382498(0x3C, 0xB4) * 5 + 2) / 6;
        }
        func_L19_003C0910((char *)obj);
        break;
    case 9: {
        f32 a;
        u8 *q;
        if (func_L01_004561B8(obj) != 0) {
            if (obj[0x43] != 10)
                func_003C3A10(obj, 10, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x70))[0x10]), 5);
        }
        a = func_0038D160(*(f32 *)(obj + 0x10) - p->f220.x, *(f32 *)(obj + 0x14) - p->f220.y);
        p->f460.x = func_0038D098(a) * D_L19_001DE870;
        p->f460.y = func_0038D0B0(a) * D_L19_001DE870;
        p->f460.z = 0.0f;
        vec_add_ab(&p->f460, &p->f460, &p->f220);
        ((Move_3C0960)func_L19_003C2628)(obj, &p->f460, 0.0f, 2);
        q = p->fF4;
        if (q != 0 && *(s16 *)(q + 0xAA) == 0x1C13) {
            switch (func_00382468(3)) {
            case 0:
                func_L01_004450F0(obj, 0xB, -1);
                break;
            case 1:
                func_L01_004450F0(obj, 0xC, -1);
                break;
            case 2:
                func_L01_004450F0(obj, 0xD, -1);
                break;
            }
        }
        if (func_L01_0040E570(obj + 0x10, &p->f460) < D_L19_001DE83C * D_L19_001DE83C)
            func_L01_004450F0(obj, 10, -1);
        break;
    }
    case 10:
        if (func_L01_004561B8(obj) != 0) {
            p->f41C = 4;
            p->f458 = D_L19_001DE878;
            p->f45C = 0;
            if (obj[0x43] != 0)
                func_003C3A10(obj, 0, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x48))[0x10]), p->f458 >> 1);
        }
        if (p->f458 <= 0 && p->f41C == 4) {
            p->f41C = 1;
            if (obj[0x43] != 0xC)
                func_003C3A10(obj, 0xC, 0, 5);
        }
        if (p->f45C == 0 && obj[0x43] == 0xC && (obj[0x60] & 2) && obj[0x42] == obj[0x43]) {
            p->f41C = 2;
            if (obj[0x43] != 0xD)
                func_003C3A10(obj, 0xD, 0, 0);
        }
        if ((obj[0x43] == 0xD && func_L01_0044E1B8(obj, 40.0f) != 0) ||
            (p->f45C != 0 && obj[0x43] == 0xC && (obj[0x60] & 2) && obj[0x42] == obj[0x43])) {
            if (func_L01_0040E570(obj + 0x10, &p->f220) < D_L19_001DE860) {
                p->f41C = 3;
                if (obj[0x43] != 0xE)
                    func_003C3A10(obj, 0xE, 0, 7);
                func_L01_004450F0(obj, 0xB, -1);
            } else {
                func_L01_004450F0(obj, 9, -1);
            }
        }
        func_L19_003C27A8(obj);
        func_L19_003C0910((char *)obj);
        break;
    case 11: {
        f32 a;
        f32 r;
        if (func_L01_004561B8(obj) != 0) {
            if (obj[0x43] != 0xE)
                func_003C3A10(obj, 0xE, 0, 5);
            p->f460 = *(V_3C0960 *)(obj + 0x10);
            obj[0xBC] = 0;
        }
        if (func_L01_0044E1B8(obj, 6.0f) != 0) {
            p->f448 = D_L19_001DE848;
            p->f110 = func_0038D098(*(f32 *)(obj + 0xF8)) * -D_L19_001DE84C;
            p->f114 = func_0038D0B0(*(f32 *)(obj + 0xF8)) * -D_L19_001DE84C;
            p->f118 = 0.0f;
            obj[0xBC] = 3;
        }
        if (func_L01_0044E1B8(obj, 20.0f) != 0) {
            *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
            p->f448 = 0.0f;
            p->f460 = *(V_3C0960 *)(obj + 0x10);
            obj[0xBC] = 0;
        }
        if (func_L01_0044E1B8(obj, 28.0f) != 0) {
            a = func_0038D160(*(f32 *)(obj + 0x10) - p->f220.x, *(f32 *)(obj + 0x14) - p->f220.y);
            r = *(f32 *)(p->f230 + 0xF8);
            if (D_L19_001DE860 < func_L01_0040E570(obj + 0x10, D_001A4C60))
                func_L01_004450F0(obj, 9, -1);
            else if (func_0038DB48(r - a) < 0.0f)
                func_L01_004450F0(obj, 0xC, -1);
            else
                func_L01_004450F0(obj, 0xD, -1);
        }
        ((Move_3C0960)func_L19_003C2628)(obj, &p->f460, *(f32 *)(obj + 0xF8), obj[0xBC]);
        break;
    }
    case 12:
    case 13: {
        f32 a;
        V_3C0960 *pv;
        if (func_L01_004561B8(obj) != 0) {
            a = func_0038DB48(*(f32 *)(obj + 0xF8) + (obj[0x20] == 0xD ? -1.5707964f : 1.5707964f));
            pv = &v10;
            v10 = *(V_3C0960 *)(obj + 0x10);
            v10.z = v10.z + 0.1f;
            v20.x = func_0038D098(a) * D_L19_001DE858;
            v20.y = func_0038D0B0(a) * D_L19_001DE858;
            v20.z = v10.z;
            if (func_003D3CB0(pv, &v20, 0, obj, 0) != 0) {
                func_L01_004450F0(obj, 9, -1);
            } else {
                if (obj[0x43] != (obj[0x20] == 0xD ? 7 : 8))
                    func_003C3A10(obj, obj[0x20] == 0xD ? 7 : 8, 0, 5);
                p->f460 = *(V_3C0960 *)(obj + 0x10);
                obj[0xBC] = 0;
            }
        }
        if (func_L01_0044E1B8(obj, 6.0f) != 0) {
            p->f448 = D_L19_001DE850;
            a = func_0038DB48(*(f32 *)(obj + 0xF8) + (obj[0x20] == 0xD ? -1.5707964f : 1.5707964f));
            p->f110 = func_0038D098(a) * D_L19_001DE854;
            p->f114 = func_0038D0B0(a) * D_L19_001DE854;
            p->f118 = 0.0f;
            obj[0xBC] = 3;
        }
        if (func_L01_0044E1B8(obj, 23.0f) != 0) {
            *(f32 *)(obj + 0x18) = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
            p->f448 = 0.0f;
            p->f460 = *(V_3C0960 *)(obj + 0x10);
            obj[0xBC] = 0;
        }
        if (func_L01_0044E1B8(obj, 42.0f) != 0)
            func_L01_004450F0(obj, 9, -1);
        ((Move_3C0960)func_L19_003C2628)(obj, &p->f460, *(f32 *)(obj + 0xF8), obj[0xBC]);
        break;
    }
    case 14:
        if (func_L01_004561B8(obj) != 0 && obj[0x43] != 0xB)
            func_003C3A10(obj, 0xB, 0, 5);
        if (func_L01_0044E1B8(obj, 36.0f) != 0)
            func_L01_004450F0(obj, 9, -1);
        ((Move_3C0960)func_L19_003C2628)(obj, obj + 0x10,
                                         func_0038D160(p->f220.x - *(f32 *)(obj + 0x10), p->f220.y - *(f32 *)(obj + 0x14)), 0);
        break;
    case 15:
        if (func_L01_004561B8(obj) != 0) {
            if (D_001A73E8[0] == obj) {
                if (obj[0x43] != 0xF)
                    func_003C3A10(obj, 0xF, 0, 5);
            } else {
                p->f414 = func_00382498(0xC, 0x32);
                if (obj[0x43] != 0)
                    func_003C3A10(obj, 0, func_00382468((*(u8 **)(*(u8 **)(obj + 0x24) + 0x48))[0x10]), 5);
            }
            *(f32 *)(obj + 0x48) = 1.0f;
        }
        if (p->f414 <= 0 && obj[0x43] == 0)
            func_003C3A10(obj, 0xF, 0, 5);
        if (func_L01_0044E1B8(obj, 70.0f) != 0)
            func_L01_004450F0(obj, 6, 4);
        ((Move_3C0960)func_L19_003C2628)(obj, obj + 0x10,
                                         func_0038D160(p->f220.x - *(f32 *)(obj + 0x10), p->f220.y - *(f32 *)(obj + 0x14)), 0);
        break;
    case 16: {
        s32 n;
        if (p->f30 <= 0.0f) {
            p->f190 = p->f70 * 3.0f;
            p->f194 = p->f74 * 3.0f;
        }
        n = func_L01_00454370(obj, &p->f160);
        if (n & 1) {
            func_L01_004450F0(obj, 0x11, 7);
        } else if (n & 2) {
            if (obj[0x95] == 6)
                func_L01_004450F0(obj, 10, -1);
            else
                func_L01_004450F0(obj, 8, 5);
        }
        break;
    }
    case 17:
        if (func_L01_004561B8(obj) != 0)
            func_L19_003C2A20(obj);
        break;
    }
    func_L19_003C2930(obj);
    if (p->f30 <= 0.0f && obj[0x20] != 0x10 && obj[0x20] != 1 && obj[0x20] != 0x11) {
        func_L19_003C2A20(obj);
        func_L19_003C29D0((A *)obj);
    }
}
/* localdecomp:end func_L19_003C0960 */

INCLUDE_ASM("asm/levels", func_L19_003C1F18);

INCLUDE_ASM("asm/levels", func_L19_003C2388);

/* localdecomp:start func_L19_003C2628 */
typedef struct { f32 x, y, z, w; } V_3C2628 __attribute__((aligned(16)));
__asm__(".extern D_L19_001DE800, 4");
__asm__(".extern D_L19_001DE840, 4");
__asm__(".extern D_L19_001DE808, 8");
__asm__(".extern D_L19_001DE820, 8");
extern s32 D_L19_001DE800;
extern f32 D_L19_001DE840;
extern f32 D_L19_001DE808[2];
extern f32 D_L19_001DE820[2];
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045AA10(void *, f32);
extern s32 func_L01_0045BD10(void *, f32);
extern void func_L01_0045A748(void *, void *);
extern void func_L01_0045AA30(void *, void *);

void func_L19_003C2628(void *objp, void *a5, int state, float fv) {
    u8 *obj = objp;
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C2628 v;
    f32 s;

    if (state != *(s32 *)(p + 0x418)) {
        if (state == 2)
            *(f32 *)(obj + 0x48) = D_L19_001DE840;
        if (D_L19_001DE800 != 0)
            *(f32 *)(obj + 0x48) = 0.1f;
        s = *(f32 *)(obj + 0x48);
        func_L01_0045BD78(obj, D_L19_001DE820[state] * s, D_L19_001DE808[state] * s, s * 0.0050265486f, s * 0.12566371f);
        if (state == 3)
            *(s32 *)(p + 0xA8) = 0x514;
        else
            *(s32 *)(p + 0xA8) = 0;
    }
    *(s32 *)(p + 0x418) = state;
    switch (state) {
    case 0:
        func_L01_0045AA10(obj, fv);
        func_L01_0045BD10(obj, fv);
        break;
    case 1:
    case 2:
        func_L01_0045A748(obj, a5);
        break;
    case 3:
        v = *(V_3C2628 *)(p + 0x110);
        v.z = *(f32 *)(p + 0x448);
        *(f32 *)(p + 0x448) = *(f32 *)(p + 0x448) - (*(f32 *)(p + 0x9C) + *(f32 *)(p + 0x9C));
        func_L01_0045AA30(obj, &v);
        break;
    }
}
/* localdecomp:end func_L19_003C2628 */

/* localdecomp:start func_L19_003C27A8 */
typedef struct { f32 x, y, z, w; } V_3C27A8 __attribute__((aligned(16)));
extern u8 D_001A71C4[];
extern u8 *D_001A73E8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern f32 func_L01_004395E0(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_00446780(u8 *, void *, f32, s32, s32, s32, s32, f32, f32);

void func_L19_003C27A8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    V_3C27A8 a;
    V_3C27A8 b;
    V_3C27A8 c;
    f32 f;
    f32 f13;
    u8 r = 0;

    if (*(s32 *)(p + 0x41C) == 2) {
        func_003C2F58(obj, 1, (u8 *)&a);
        func_003C2F58(obj, 2, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 20.0f <= f;
    } else if (*(s32 *)(p + 0x41C) == 1) {
        func_003C2F58(obj, 3, (u8 *)&a);
        func_003C2F58(obj, 4, (u8 *)&b);
        f = func_L01_004395E0(obj);
        r = 9.0f <= f;
    }
    if (*(s32 *)(p + 0x45C) == 0 && D_001A73E8[0] == obj)
        *(s32 *)(p + 0x45C) = 1;
    if (r != 0) {
        vec_sub_ab(&c, &b, &a);
        func_0038CE20(&c, &c, 0.5f);
        f = func_0038CEA8(&c);
        vec_add_ab(&c, &c, &a);
        f13 = (f32)p[0x44];
        if (D_001A71C4[0] == 1)
            f13 = 1.0f;
        func_L01_00446780(obj, &c, f, 1, 0, 1, 0, f13, 1.0f);
    }
}
/* localdecomp:end func_L19_003C27A8 */

/* localdecomp:start func_L19_003C2930 */
s32 func_0038CAD0(s32);
void func_0038CB00(s32);
f32 func_L01_0040E548(void *, void *);
void func_L01_004472C0(void *);
extern u8 D_L19_001E2100[];

void func_L19_003C2930(void *arg0) {
    s32 temp_s1;
    u16 temp_v1;

    temp_s1 = *(s32 *)((u8 *)arg0 + 0x68);
    if (((*(u8 *)((u8 *)arg0 + 0x31)) != 0) && (func_L01_0040E548(D_L19_001E2100, arg0 + 0x10) < 1024.0f)) {
        func_L01_004472C0(arg0);
        *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
    }
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
    func_0038CB00(temp_s1 + 0x414);
    func_0038CB00(temp_s1 + 0x416);
    func_0038CAD0(temp_s1 + 0x458);
}
/* localdecomp:end func_L19_003C2930 */

/* localdecomp:start func_L19_003C29D0 */
extern void func_L01_004450F0(void *, int, int);
extern void func_003C2880(void *);
void func_L19_003C29D0(A *a) {
    B *b = a->b;
    if (b->f444 != 0) {
        a->v = b->v;
        func_L01_004450F0(a, 1, 1);
    } else {
        func_003C2880(a);
    }
}
/* localdecomp:end func_L19_003C29D0 */

/* localdecomp:start func_L19_003C2A20 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(void *, s32, void *);
extern u8 D_L19_003C29D0[];

void func_L19_003C2A20(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    if ((*(s32 *)((u8 *)temp_s0 + 0x444)) != 0) {
        *(s8 *)((u8 *)arg0 + 0x7F) = 0;
        *(u16 *)((u8 *)arg0 + 0xB6) = (u16) ((u16) (*(u16 *)((u8 *)arg0 + 0xB6)) >> 1);
        *(u16 *)((u8 *)arg0 + 0xB4) = (u16) ((s32) ((*(u16 *)((u8 *)arg0 + 0xB4)) << 0x10) >> 0x11);
    }
    func_L01_00315900(arg0, 0, D_L19_003C29D0);
}
/* localdecomp:end func_L19_003C2A20 */

/* localdecomp:start func_L19_003C2A98 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern void func_L01_004450F0(void *a0, s32 a1, s32 a2);

void func_L19_003C2A98(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    p = D_L19_0021C260[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L19_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[a0[0x21]])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != a0 && *(s16 *)(e + 0xAA) == 0x1C13) {
            if (e[0x20] == 2) {
                func_L01_004450F0(e, 3, e[0x95]);
            } else if (e[0x95] == 4) {
                if (e[0x20] != 0x10 && e[0x20] != 1 && e[0x20] != 0x11) {
                    func_L01_004450F0(e, 8, 5);
                }
            }
        }
        p++;
    }
}
/* localdecomp:end func_L19_003C2A98 */

/* localdecomp:start func_L19_003C2BC0 */
s32 func_L19_003C2BC0(void *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0 != 0) && ((*(s16 *)((u8 *)arg0 + 0xAA)) == 0x1C13)) {
        var_a1 = (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
    }
    return var_a1;
}
/* localdecomp:end func_L19_003C2BC0 */

/* localdecomp:start func_L19_003C2BF0 */
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L19_003C2BF0(u8 *obj, u128_t *a1, f32 *v) {
    u8 *p;
    u8 *t;
    u16 flags;
    f32 f;

    qzero(obj + 0xF0);
    p = *(u8 **)(obj + 0x68);
    *(u128_t *)(obj + 0x10) = *a1;
    *(u128_t *)(p + 0x110) = *(u128_t *)v;
    *(f32 *)(obj + 0xF8) = func_0038D160(v[0], v[1]);
    *(s32 *)(p + 0x118) = 0;
    *(f32 *)(p + 0x448) = v[2];
    p[0x60] = 0;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34);
    *(s16 *)(p + 0x198) = 0;
    p[0x5E] = 0;
    p[0x5F] = 0;
    *(s32 *)(p + 0x68) = 0;
    p[0x3E] = 3;
    t = *(u8 **)(obj + 0x24);
    f = *(f32 *)(t + 0x24);
    flags = *(u16 *)(obj + 0x34) & 0xFFBE;
    *(u16 *)(obj + 0x34) = flags;
    *(f32 *)(obj + 0x2C) = f;
    *(u16 *)(obj + 0x34) = flags | (*(u16 *)(t + 0x44) & 0x1000);
    *(s32 *)(obj + 0x98) = *(s32 *)(t + 0x10);
    func_L01_004450F0(obj, 5, 3);
}
/* localdecomp:end func_L19_003C2BF0 */

/* localdecomp:start func_L19_003C2CC8 */
typedef struct { f32 x, y, z, w; } V_3C2CC8 __attribute__((aligned(16)));
typedef struct { u8 pad[0xD0]; u8 fD0; u8 padD1[0xB]; void *fDC; u8 padE0[0x20]; } M_3C2CC8;

__asm__(".extern D_L19_001DE880, 4");
__asm__(".extern D_L19_001DE884, 4");
__asm__(".extern D_L19_001DE888, 4");
__asm__(".extern D_L19_001DE88C, 4");
__asm__(".extern D_L19_001DE890, 4");
__asm__(".extern D_L19_001DE894, 4");
__asm__(".extern D_L19_001DE898, 4");
__asm__(".extern D_L19_001DE89C, 4");
__asm__(".extern D_L19_001DE8A0, 4");
__asm__(".extern D_L19_001DE8A4, 4");
__asm__(".extern D_L19_001DF240_003C2CC8, 4");
extern s32 D_L19_001DE880;
extern s32 D_L19_001DE884;
extern f32 D_L19_001DE888;
extern s32 D_L19_001DE88C;
extern f32 D_L19_001DE890;
extern f32 D_L19_001DE894;
extern f32 D_L19_001DE898;
extern f32 D_L19_001DE89C;
extern f32 D_L19_001DE8A0;
extern f32 D_L19_001DE8A4;
extern s32 D_L19_001DF240_003C2CC8;
extern s32 D_L19_001DF240;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];

extern s32 func_L01_0044C108(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_00404808(void (*)(u8 *), u8 *);
extern void func_L19_003C3B60(u8 *);
extern void *func_L01_00447490(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L19_003C3788(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_L19_003C3998(u8 *);
extern void func_L19_003C3898(void *);
extern void func_003A4F28(s32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern void func_0038D750(void *, s32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L19_003C3A78(u8 *);
extern void func_L19_003C2BF0(u8 *, u128_t *, f32 *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C6FB0(void *, s32 *, s32 *, s32 *);
extern void func_L01_00448248(void *, s32, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern s32 func_L01_003303B8(u8 *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);

void func_L19_003C2CC8(u8 *obj) {
    u8 *p;
    u8 *e;
    u8 *s;
    s32 z, y, x;
    V_3C2CC8 v90;
    V_3C2CC8 va0;
    V_3C2CC8 vb0;
    V_3C2CC8 vc0;
    s32 i;
    s32 col;
    f32 r;
    f32 w;
    f32 q;
    f32 q2;

    if (func_L01_0044C108(obj + 0x10) != 0) {
        if (obj[0x20] == 0 && func_0038CF38(obj + 0x10, D_001A4C60) < 9.0f) {
            func_003C2880(obj);
            return;
        }
        p = *(u8 **)(obj + 0x68);
        if (D_L19_001DE880 != 0)
            func_L01_00404808(func_L19_003C3B60, obj);
        e = func_L01_00447490(obj, 0x1170000, 0);
        if (e != 0) {
            if (D_L19_001DF240_003C2CC8 >= *(s32 *)(p + 0xA4)) {
                func_003A52A0(2, 0, obj);
                *(f32 *)(p + 0x30) = *(f32 *)(p + 0x30) - *(f32 *)(e + 0x2C);
                if (*(f32 *)(p + 0x30) <= 0.0f)
                    func_L01_004450F0(obj, 5, -1);
                p[0x77] = 0xFF;
                func_003C4A40(obj, p + 0x70);
                *(s32 *)(p + 0xA4) = D_L19_001DF240 + D_L19_001DE884;
            }
            obj[0xA8] = 0xFF;
        }
        if (obj[0x20] != 5)
            func_L01_0044ABD0(obj, p + 0x70);
        if (obj[0x20] == 0)
            func_L19_003C3788(obj);
        switch (obj[0x20]) {
        case 1:
            if ((D_L19_001DF240 & 0x1F) == (((s32)obj >> 8) & 0x1F)) {
                if ((*(s32 *)(p + 0x88) == -1 || func_00382380(D_001A4C60, *(s32 *)(p + 0x88), 0)) &&
                    (*(s32 *)(p + 0x8C) == -1 || func_L01_00445AD0(*(s32 *)(p + 0x8C), -1, 0) == 0))
                    func_L01_004450F0(obj, 2, -1);
            }
            break;
        case 2:
            if (func_L01_004561B8(obj) != 0) {
                if (*(s32 *)(p + 0x90) < 10)
                    *(s32 *)(p + 0x94) = (s32)((f32)*(s32 *)(p + 0x90) * 50.0f);
                else
                    *(s32 *)(p + 0x94) = (*(s32 *)(p + 0x90) * 5 + 2) / 6;
            }
            func_0038CAD0((s32)(p + 0x94));
            if (*(s32 *)(p + 0x98) != 0 && *(s32 *)(p + 0x94) <= 0 &&
                (D_L19_001DF240 & 0xF) == (((s32)obj >> 8) & 0xF) && func_L19_003C3998(obj) > 0)
                func_L01_004450F0(obj, 3, -1);
            break;
        case 3:
            if (func_L01_004561B8(obj) != 0) {
                if (*(s32 *)(p + 0xA0) == -1 ||
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC != obj ||
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 == 0)
                    *(s32 *)(p + 0xA0) = func_003A52A0(1, 4, obj);
                func_L19_003C3898(obj);
            }
            func_L01_00448890(p + 0xB0, *(f32 *)(p + 0xAC), p + 0xA8, 0.00062831858f, 0.00062831858f, 0.031415928f, 0);
            func_0038D750(p + 0xD0, 2, *(f32 *)(p + 0xB0));
            func_L01_00448890(p + 0xBC, *(f32 *)(p + 0xB8), p + 0xB4, 0.00062831858f, 0.00062831858f, 0.031415928f, 0);
            func_0038D750(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
            if (*(u16 *)(obj + 0x96) >= 0x3D && __builtin_fabsf(*(f32 *)(p + 0xB4)) < 0.00034906587f &&
                __builtin_fabsf(*(f32 *)(p + 0xA8)) < 0.00034906587f) {
                if (*(s32 *)(p + 0xA0) != -1 &&
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                    ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                    func_003A4F28(*(s32 *)(p + 0xA0));
                *(s32 *)(p + 0xA0) = -1;
                func_L01_004450F0(obj, 4, -1);
            }
            break;
        case 4:
            if (func_L01_004561B8(obj) != 0) {
                if (obj[0x43] != 1)
                    func_003C3A10(obj, 1, 0, 0);
                *(s32 *)(p + 0x98) = *(s32 *)(p + 0x98) - 1;
            }
            if (func_L01_0044E1B8(obj, 8.0f) != 0) {
                func_00382760(&v90, D_L19_001DE888, func_0038DAB8(*(f32 *)(obj + 0xF8), *(f32 *)(p + 0xB0)), *(f32 *)(p + 0xBC));
                func_003C2F58(obj, 2, (u8 *)&va0);
                s = func_L19_003C3A78(obj);
                if (s != 0) {
                    func_L19_003C2BF0(s, (u128_t *)&va0, (f32 *)&v90);
                    func_003A52A0(0, 0, obj);
                    for (i = 0; i < D_L19_001DE88C; i++) {
                        func_0038CE20(&vb0, &v90, func_003824E0(D_L19_001DE8A0, D_L19_001DE8A4));
                        r = func_00382538();
                        func_00382760(&vc0, D_L19_001DE89C, r, func_00382538());
                        vec_add_ab(&vb0, &vb0, &vc0);
                        w = func_003824E0(D_L19_001DE890, D_L19_001DE894);
                        qzero(&vc0);
                        vb0.w = w;
                        vc0.w = w + D_L19_001DE898;
                        col = func_0038DBD8(0x60202020, 0x60707070, func_003824E0(0.0f, 1.0f));
                        func_L01_00463378(&va0, &vb0, &vc0, col, 0x30707070, 4, ((func_00382468(0x1E) + 0x1E) * 5 + 2) / 6, 4, -1);
                    }
                }
            }
            if ((obj[0x60] & 2) && obj[0x42] == obj[0x43]) {
                if (obj[0x42] != 0)
                    func_003C3A10(obj, 0, 0, 0);
                func_L01_004450F0(obj, 2, -1);
            }
            break;
        case 5:
            if (*(s32 *)(p + 0xA0) != -1 &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                func_003A4F28(*(s32 *)(p + 0xA0));
            *(s32 *)(p + 0xA0) = -1;
            if (-0.2617994f < *(f32 *)(p + 0xBC)) {
                func_L01_00448890(p + 0xBC, -1.5707964f, p + 0xB4, 0.00062831858f, 0.00062831858f, 0.031415928f, 0);
                func_0038D750(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
            }
            if (*(u16 *)(obj + 0x96) < 0x320) {
                V_3C2CC8 *pv = &v90;
                qzero(&v90);
                v90.z = func_003824E0(0.020000001f, 0.030000001f);
                qzero(&va0);
                v90.w = 0.1f;
                va0.w = 0.2f;
                q = func_00382538();
                q2 = func_003824E0(-0.15f, 0.15f);
                vb0.x = func_0038D098(q) * q2;
                vb0.y = func_0038D0B0(q) * q2;
                vb0.z = 0.5f;
                vec_add_ba(&vb0, &vb0, obj + 0x10);
                func_L01_00463378(&vb0, pv, &va0, 0x75000000, 0x60404040,
                                  (func_00382498(5, 10) * 5 + 2) / 6, (func_00382498(0x3C, 0x64) * 5 + 2) / 6,
                                  (func_00382498(0x14, 0x28) * 5 + 2) / 6, -1);
            }
            func_003C6FB0(obj, &x, &y, &z);
            func_L01_00448248(&x, 0, 2);
            func_L01_00448248(&z, 0, 2);
            func_L01_00448248(&y, 0, 2);
            func_L01_0043B9E8(obj, x, y, z);
            if (*(f32 *)(p + 0x30) < -1.0f)
                func_L01_004450F0(obj, 6, -1);
            break;
        case 6:
            qzero(&v90);
            if (*(s32 *)(p + 0xA0) != -1 &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fDC == obj &&
                ((M_3C2CC8 *)(D_001A30B0 + (*(s32 *)(p + 0xA0) << 7)))->fD0 != 0)
                func_003A4F28(*(s32 *)(p + 0xA0));
            *(s32 *)(p + 0xA0) = -1;
            func_003A52A0(3, 0, obj);
            func_L01_003303B8(obj + 0x10, 1.0f, 0, 8, 8, 8, 8, 10, 2, 0.0f, 0.0f, 2.0f,
                              0, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00451FE0(obj, 0xFFFD, &v90, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, 0xB4, 0, 0, 0x23, 0, 3,
                              -1.0f, -1.0f, 1.0f, 1.0f);
            func_L01_004443E8((s32)obj, 0, 3);
            func_003C2880(obj);
            return;
        }
        if (*(u16 *)(obj + 0x96) < 0xFFFF)
            *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
    }
}
/* localdecomp:end func_L19_003C2CC8 */

/* localdecomp:start func_L19_003C3788 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L19_003C3898(void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D750(void *, s32, f32);

void func_L19_003C3788(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    f32 f0;
    f32 f1;

    p[0x58] = 10;
    p[0x5A] = 4;
    *(f32 *)(p + 0x40) = 0.5f;
    p[0x3E] = 3;
    p[0x39] = 0;
    p[0x63] = 0;
    p[0x3F] = 0;
    p[0x64] = 0;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 10;
        *(f32 *)(p + 0x30) = 10.0f;
    }
    *(s32 *)(p + 0x9C) = 0;
    *(s32 *)(p + 0xA8) = 0;
    *(s32 *)(p + 0xB4) = 0;
    *(s32 *)(p + 0xAC) = 0;
    *(s32 *)(p + 0xA0) = -1;
    func_L19_003C3898(obj);
    func_L01_0043A430(obj, 0, p + 0xC0);
    func_L01_0043A430(obj, 1, p + 0x100);
    f0 = *(f32 *)(p + 0xAC);
    f1 = *(f32 *)(p + 0xB8);
    *(f32 *)(p + 0xB0) = f0;
    *(f32 *)(p + 0xBC) = f1;
    func_0038D750(p + 0xD0, 2, f0);
    func_0038D750(p + 0x110, 1, 1.5707964f - *(f32 *)(p + 0xBC));
    func_L01_004450F0(obj, 1, -1);
}
/* localdecomp:end func_L19_003C3788 */

/* localdecomp:start func_L19_003C3898 */
typedef struct { f32 x, y, z, w; } V_3C3898 __attribute__((aligned(16)));
typedef struct { u8 pad[0x12]; s16 h12; u8 pad2[0xC]; s32 *x20; u8 pad3[0xC]; } E_3C3898;
typedef struct { u8 pad[0x20]; E_3C3898 e[1]; } T_3C3898;
typedef struct { u8 pad[0x30]; V_3C3898 v; u8 pad2[0x40]; } P_3C3898;
typedef struct { u8 pad[0x84]; s32 x84; u8 pad2[0x14]; s32 x9C; u8 pad3[0xC]; f32 xAC; u8 pad4[8]; f32 xB8; } Q_3C3898;
extern T_3C3898 *D_L19_001DF34C;
extern P_3C3898 *D_L19_001DF800;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_003824E0(f32, f32);

void func_L19_003C3898(void *objp) {
    u8 *obj = objp;
    Q_3C3898 *p = *(Q_3C3898 **)(obj + 0x68);
    E_3C3898 *e = &D_L19_001DF34C->e[p->x84];
    V_3C3898 v;
    f32 a;

    if (e->h12 == 1) {
        p->x9C = 0;
        v = D_L19_001DF800[e->x20[0]].v;
    } else {
        P_3C3898 *tab = D_L19_001DF800;
        s32 n = (p->x9C + 1) % e->h12;

        p->x9C = n;
        v = tab[e->x20[n]].v;
    }
    a = func_0038D160(v.x - *(f32 *)(obj + 0x10), v.y - *(f32 *)(obj + 0x14));
    p->xAC = func_0038DB48(a - *(f32 *)(obj + 0xF8));
    p->xB8 = func_003824E0(0.5235988f, 1.0471976f);
}
/* localdecomp:end func_L19_003C3898 */

/* localdecomp:start func_L19_003C3998 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern s32 func_L19_003C2BC0(void *a);

s32 func_L19_003C3998(u8 *object) {
    u8 *o = *(u8 **)(object + 0x68);
    s32 count;
    u16 *p;
    u8 *e;
    if (*(s32 *)(o + 0x80) < 0)
        return 0;
    count = 0;
    p = D_L19_0021C260[*(s32 *)(o + 0x80)];
    while ((*(s32 *)(o + 0x80) & 0xFF) != 0xFF && D_L19_001DF758 >= *(s32 *)(o + 0x80) && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[*(s32 *)(o + 0x80)])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            break;
        p++;
        if (func_L19_003C2BC0(e))
            count++;
    }
    return count;
}
/* localdecomp:end func_L19_003C3998 */

/* localdecomp:start func_L19_003C3A78 */
extern u16 *D_L19_0021C260[];
extern u8 *D_L19_001DF71C;
__asm__(".extern D_L19_001DF71C, 16");
extern s32 D_L19_001DF758;
extern s32 func_L19_003C2BC0(void *e);

u8 *func_L19_003C3A78(u8 *object) {
    u16 *p;
    u8 *e;
    u8 *vars = *(u8 **)(object + 0x68);
    if (*(s32 *)(vars + 0x80) < 0)
        return 0;
    p = D_L19_0021C260[*(s32 *)(vars + 0x80)];
    while ((*(s32 *)(vars + 0x80) & 0xFF) != 0xFF && *(s32 *)(vars + 0x80) <= D_L19_001DF758 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L19_0021C260[*(s32 *)(vars + 0x80)])) {
        e = D_L19_001DF71C + ((*p & 0x7FFF) << 8);
        if (e == 0)
            return 0;
        if (func_L19_003C2BC0(e) != 0)
            return e;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L19_003C3A78 */

/* localdecomp:start func_L19_003C3B60 */
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);

void func_L19_003C3B60(u8 *self) {
    V_3C3898 base;
    V_3C3898 p;
    u8 *v = *(u8 **)(self + 0x68);
    E_3C3898 *e;

    func_003C2F58(self, 0, (u8 *)&base);
    p.x = func_0038D098(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC))) * 10.0f;
    p.y = func_0038D0B0(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC))) * 10.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.025f, 1.0f, 0.0f, 0x60000080, 0x60000080, 0x60000080, 0x60000080);
    p.x = func_0038D098(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xB0))) * 5.0f;
    p.y = func_0038D0B0(func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xB0))) * 5.0f;
    p.z = 0.0f;
    vec_add_ba(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.1f, 1.0f, 0.0f, 0x40000040, 0x40000040, 0x40000040, 0x40000040);
    func_00382760(&p, 10.0f, func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC)), *(f32 *)(v + 0xB8));
    vec_add_ab(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.025f, 1.0f, 0.0f, 0x60008000, 0x60008000, 0x60008000, 0x60008000);
    func_00382760(&p, 5.0f, func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(v + 0xAC)), *(f32 *)(v + 0xBC));
    vec_add_ab(&p, &p, &base);
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.1f, 1.0f, 0.0f, 0x40004000, 0x40004000, 0x40004000, 0x40004000);
    e = (E_3C3898 *)((u8 *)D_L19_001DF34C->e + *(s32 *)(v + 0x84) * 0x30);
    p = D_L19_001DF800[e->x20[*(s32 *)(v + 0x9C)]].v;
    func_L01_0040A8C0(&base, &p, 0x16, 1, 0.05f, 1.0f, 0.0f, 0x60808080, 0x60808080, 0x60808080, 0x60808080);
}
/* localdecomp:end func_L19_003C3B60 */
