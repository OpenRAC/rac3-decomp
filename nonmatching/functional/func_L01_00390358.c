/* functional: high. 437 diff but same 442 instruction count and same 0xB0 frame (register/scheduling only); all float constants and immediates cross-checked against retail by opcode/immediate histogram. Names for unnamed globals follow D_<addr> (D_00142DE0, D_00142660, D_001426E0, D_001BBE90, D_001D60E0/D8, D_001D545C, D_001DAA34); func_L01_003016B0/00468678/0046B288 declared with u8* returns here (file may declare them void/s32). Note jal delay slots that are nops were rechecked in raw asm */
#include "common.h"
#include "vu0.h"
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_00390358;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00390358;
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_001D7BE0;
__asm__(".extern D_001D545C, 4");
extern s32 D_001D545C;
__asm__(".extern D_001DAA34, 4");
extern f32 D_001DAA34;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 *D_L01_001EEA80[];
extern u8 D_00142DE0[];
extern u8 D_00142660[];
extern u8 D_001426E0[];
extern u8 D_001BBE90[];
extern u8 D_001D60E0[];
extern u8 D_001D60D8[];
extern f32 D_L01_002F1600[];
extern s32 D_001D673C;
extern s32 func_L01_004CB2D8(void);
void func_L01_00390358(u8 *obj) {
    extern void func_L01_004C7D98(void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00390AB8(u8 *, void *, void *);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern u8 *func_00382348(void *);
    extern s32 func_003C4B50(void *);
    extern s32 func_L01_00444350(void);
    extern s32 func_L01_004006C8(u8 *, s32, s32);
    extern s32 func_L01_0041A4F0(void);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern u8 *func_L01_00468678(void *, void *, f32, f32, s32);
    extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    Vec_00390358 a, c, b;
    u8 *vars = *(u8 **)(obj + 0x68);
    u8 *pos = obj + 0x10;
    s32 n, i;
    u8 *p;
    switch (obj[0x20]) {
    case 0: {
        u8 **list;
        func_L01_004C7D98(pos, &a);
        func_L01_0040E790(&c, vars, &a);
        func_0038CF68(&c, &c, 0.040000002f);
        func_L01_00390AB8(obj, &c, &a);
        n = func_003D4D00(pos, 0, 5.0f, obj, 0);
        if (n > 0) {
            list = D_L01_001EEA80;
            for (; n != 0; n--, list++) {
                u8 *info = func_00382348(*list);
                u8 *e;
                s32 h, damage, dmg, mm;
                if (info == 0) continue;
                e = *list;
                if (e == 0) continue;
                if (*(u8 **)(e + 0x24) == 0) continue;
                if ((*(u8 **)(e + 0x24))[0x46] != 5) continue;
                if (e == ((Hero_00390358 *)D_001A4BE0)->moby) continue;
                h = *(s16 *)(e + 0xAA);
                if (h == 0x188A) continue;
                if (h == 0x1886) continue;
                if (func_003C4B50(e) != 0) continue;
                info[0x2F] = 1;
                {
                    f32 gun = *(f32 *)(D_L01_002C5600 + D_001425C0[0x37] * 240 + 0x6C);
                    *(s32 *)(info + 0x38) = (s32)(gun / *(f32 *)info * 600.0f);
                }
                if (info[0x35] != 0) continue;
                h = *(s16 *)(e + 0xAA);
                if (h == 0x19DF || h == 0x19F1 || h == 0x1BC5 || h == 0x1A18 || h == 0x1A1C ||
                    h == 0x1A1F || h == 0x1A13 || h == 0x1666 || h == 0x1AFD || h == 0x1A0A ||
                    h == 0x16CB || h == 0x1BD9) continue;
                if ((u32)D_L01_001D7BE0 < 0x29) {
                    if (D_L01_001D7BE0 == 9) continue;
                    *(s32 *)(D_00142DE0 + 0xDC) += func_L01_00444350();
                } else {
                    s32 q, k, idx2, r;
                    u8 *table;
                    if (D_L01_001D7BE0 == 9) continue;
                    q = (*(s32 *)(D_00142660 + 0x38) + 0x31) / 0x32;
                    k = D_001D545C;
                    idx2 = (((s32)(*(u16 *)(e + 0xB2) << 16)) >> 17) + (k << 10);
                    {
                        u8 bt = D_001BBE90[idx2];
                        s32 bit = (*(u16 *)(e + 0xB2) & 1) ? ((bt >> 4) & 8) : (bt & 8);
                        table = bit ? D_001D60E0 : D_001D60D8;
                    }
                    r = func_L01_004006C8(table, *(u16 *)(e + 0xB6), *(s16 *)(e + 0xB2));
                    r <<= D_001A4BE0[0x28C8];
                    if (func_L01_0041A4F0() != 0) {
                        f32 scale;
                        mm = D_001D545C;
                        if (mm == 7 && D_001426E0[0x7B] != 0) scale = D_001DAA34;
                        else scale = D_L01_002F1600[mm];
                        r = (s32)((f32)r * scale);
                    }
                    *(s32 *)(D_00142DE0 + 0xDC) += r + q;
                }
            }
        }
        func_L01_00446780(obj, pos, 0x8000000, 0, 1, 0, 2.5f, 1.0f, 1.0f);
        func_L01_004450F0(obj, 1, -1);
        break;
    }
    case 1: {
        s32 type = *(s32 *)(vars + 0x18);
        if (type == 0x39 || type == 0x36 || type == 0x32) {
            f32 r = func_003824E0(3.5f, 4.5f);
            p = func_L01_003016B0(pos, 5, r, 1.05f);
            if (p != 0) func_L01_0043B9E8(p, 0x52, 0xD1, 5);
        }
        n = 1;
        do {
            f32 sp;
            func_L01_004C7D98(pos, &a);
            func_0038CF68(&a, &a, -1.0f);
            {
                /* a = obj pos + a (vadd.xyz) */
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(a) : "m"(a), "m"(*(vu0_v4 *)pos) : "vf1", "vf2");
            }
            qzero(&b);
            b.f[0] = func_003824E0(-1.1f, 1.1f);
            b.f[1] = func_003824E0(-1.1f, 1.1f);
            b.f[2] = func_003824E0(0.5f, 1.0f);
            c = b;
            func_0038CF68(&c, &c, func_003824E0(0.004f, 0.012000001f));
            sp = func_003824E0(0.05f, 0.15f);
            p = func_L01_00468678(&a, &c, sp * 210000.0f, *(f32 *)(D_001A4BE0 + 0x88) + 1.0f, (s32)0x8810D162);
            if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
            n--;
        } while (n >= 0);
        if (D_001D673C == 0 && func_L01_004CB2D8() == 0) {
            i = 0;
            do {
                f32 angle = func_00382538();
                f32 radius = func_003824E0(0.0f, 2.5f);
                f32 size = func_003824E0(0.0f, 1.5f);
                f32 life = func_003824E0(3.0f, 5.0f);
                s32 alpha = func_00382498(100, 160);
                a.f[0] = func_0038D098(angle) * radius;
                a.f[1] = func_0038D0B0(angle) * radius;
                a.f[2] = 0.0f;
                __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(a) : "m"(a), "m"(*(vu0_v4 *)pos) : "vf1", "vf2");
                p = func_L01_0046B288(&a, 0x5005D152, 0x5D152, alpha, size, life);
                if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
                i--;
            } while (i >= 0);
        }
        if (func_0038CAD0(vars + 0x18) != 0) func_003C2880(obj);
        break;
    }
    }
}
