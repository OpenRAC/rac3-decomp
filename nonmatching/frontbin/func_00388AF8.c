/* US draft of func_00388AF8 (rac3-uya-decomp func_00384420, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00388AF8 */
__asm__(".extern D_001D58D0, 4");
__asm__(".extern D_001D5884, 1");

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;

extern C_00384420 *D_001DA5F0;
extern s32 D_001D9BC4;
extern s32 D_001D9D1C;
extern s32 D_001D9348;
extern s32 D_001D934C;
extern s32 D_001D9C10_00388AF8;
extern s32 D_001D9C14_00388AF8;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C08_00388AF8;
extern s32 D_001D9C0C_00388AF8;
extern s32 D_001D9364;
extern s32 D_001D9368;
extern s32 D_001D9C38_00388AF8;
extern volatile s32 D_001D9EC0;
extern s32 D_001D52F0;
extern P_00384420 D_00222480_00388AF8[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9BD0;
extern f32 D_001D9BD8[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D10;
extern s32 D_001D9D50_00388AF8;
extern u8 D_002FDC00[];
extern u8 D_003064C0[];
extern Q_00384420 D_00225AA0;
extern Q_00384420 D_00334EC0;

extern void func_00392350(s32);
extern void func_003861F0(void);
extern void func_003C2DC0(void);
extern void func_00387218(void);
extern void func_00387F68(void);
extern void func_0038C9B0(void);
extern void func_003CF0F0(void);
extern void func_003A9C70_00388AF8(s32);
extern void func_003D9CF0(void);
extern void func_003A96D8(void);
extern void func_00389240(s32);
extern void func_00389E28(void);
extern void func_00389370(void);
extern void func_003A9678(void);
extern void func_003DEF28(void);
extern void func_0038AD40_00388AF8(u8 *);
extern void func_00389EA0(void);
extern void func_003886B0(void);
extern void func_003C3860(void);
extern void func_00389DB0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00385020(void);
extern void func_0038A058(void);
extern void func_11F0A0(s32);
extern void func_003CD3D8(void);
extern void func_00389F68(void);
extern void func_003D85C0_00388AF8(s32);
extern void func_003D8640(void);
extern void func_003D9260_00388AF8(s32);
extern void func_00389FE0(void);
extern void func_00385D28(s32);
extern void func_003926E8(void);
extern s32 func_003A0EA8(s32);
extern void func_0038A948(void);
extern void func_003A9CA8_00388AF8(s32);
extern void func_003AF660(void);
extern void func_00396838(void);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern void func_00381D60(void);
extern void func_00385E40(void);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_0038ABC0(void);
extern void func_003A8F90_00388AF8(void *);
extern void func_003A92F0(s32);
extern void func_003D0180(void *);
extern void func_003CF050(void);
extern void func_003DD768(void);
extern void func_003D9C30(void);
extern void func_003E0B10(void *);
extern void func_003DEE20(void);
extern void func_003C31B0(void);
extern void func_003864C0(s32);

void func_00388AF8(s32 arg0) {
    s32 t;
    s32 t2;
    f32 d, n;
    u128_00384420 *src, *dst;

    if (D_001DA5F0 == 0 || D_001DA5F0->x4 != 0 || ((*(u8 *)&D_001D9BC4 ^ 1) & 1)) {
        func_00392350(0);
    }
    func_003861F0();
    func_003C2DC0();
    func_00387218();
    func_00387F68();
    D_001D9D1C = -1;
    D_001D9348 = 0;
    D_001D934C = 0;
    if (D_001DA5F0 != 0 && (D_001D9BC4 & 1)) {
        func_0038C9B0();
    }
    if (D_001D9BC4 & 2) {
        func_003CF0F0();
    }
    func_003A9C70_00388AF8(0x2010000);
    if (D_001D9BC4 & 4) {
        func_003D9CF0();
    }
    func_003A9C70_00388AF8(0x2020000);
    if ((D_001D9BC4 & 0x20) && D_001D9C10_00388AF8 != 0) {
        func_003A96D8();
        func_00389240(1);
        func_00389E28();
        func_00389370();
        func_003A9678();
    }
    if (D_001D9BC4 & 8) {
        func_003DEF28();
    }
    func_003A9C70_00388AF8(0x2040000);
    if (D_001D58D0) {
        func_0038AD40_00388AF8(&D_001D58D0);
    }
    if ((D_001D9BC4 & 0x20) && D_001D9C14_00388AF8 != 0) {
        func_003A96D8();
        func_00389240(1);
        func_00389EA0();
        func_00389370();
        func_003A9678();
    }
    if (D_001D9BC4 & 0x10) {
        if (D_001D5B94 == 2) {
            func_003886B0();
        } else {
            func_003C3860();
        }
    }
    func_003A9C70_00388AF8(0x2080000);
    func_00389240(0);
    if (D_001D9BC4 & 0x20) {
        func_003A96D8();
        if (D_001D9C08_00388AF8 != 0) {
            func_00389DB0();
        }
        func_003A9440(0x42, 0x8000000048);
        func_00385020();
        func_003A96D8();
        func_0038A058();
        func_003A9440(8, 5);
        func_003A96D8();
        func_003A9440(0x47, 0x53001);
        func_11F0A0(0);
        func_003CD3D8();
        D_001D9D1C = 9;
        func_003A9440(0x47, 0x5360B);
        if (D_001D9C0C_00388AF8 != 0) {
            func_003A96D8();
            func_00389F68();
        }
        func_00389370();
        if (D_001D9348 != 0) {
            func_003D85C0_00388AF8(0);
            if (D_001D9348 != 0) {
                func_003D8640();
            }
        }
        if (D_001D9364 != 0) {
            func_003D9260_00388AF8(0);
        }
        t2 = D_001D9364;
        D_001D9364 = 0;
        D_001D9368 = t2;
        func_00389240(0);
        if (D_001D9C38_00388AF8 != 0) {
            func_003A96D8();
            func_00389FE0();
        }
        func_003A9440(0x42, 0x8000000044);
        func_00385D28(arg0);
        func_00389370();
    }
    func_003926E8();
    func_00389240(0);
    func_003A96D8();
    if ((D_001D9BC4 & 0x180) && func_003A0EA8(3) == 0) {
        func_003A9440(0x47, 0x33001);
        func_0038A948();
        if (D_001D9BC4 & 0x80) {
            func_003A9CA8_00388AF8(0);
            func_003AF660();
            t = D_001D9EC0;
            func_00396838();
            D_001D9EC0 = t;
            func_003B30E8();
            func_003B3158(D_001D52F0);
            func_003B3120();
            func_00381D60();
        }
    }
    if (D_001D5B94 == 2) {
        func_00385E40();
    }
    func_00389370();
    if (D_001D9BC4 & 0x40) {
        func_003A9440(0x42, 0x8000000044);
        if (((P_00384420 *)((u8 *)D_00222480_00388AF8 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_0038AE20(D_001D5780, D_001D5781, D_001D5782, D_001D5783);
        }
        if (D_001D9BD0 > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD0 > 1.0f) {
                D_001D9BD0 = 1.0f;
            }
            func_0038AE20(0, 0, 0, D_001D9BD0 * 128.0f);
        }
        if (D_001D9BD8[0] > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD8[0] > 1.0f) {
                D_001D9BD8[0] = 1.0f;
            }
            func_0038AE20(0xFF, 0xFF, 0xFF, D_001D9BD8[arg0] * 128.0f);
        }
        if (D_001D5884 && D_001D58B8 != 0) {
            func_0038ABC0();
        }
    }
    func_003A8F90_00388AF8(D_100AE0);
    func_11F0A0(0);
    n = *(volatile u32 *)0x10000800;
    D_001D9D10 = n / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_003A92F0(2);
    if (D_001D9BC4 & 2) {
        func_003D0180(D_002FDC00);
        func_003CF050();
    }
    func_003A92F0(4);
    if (D_001D9BC4 & 4) {
        src = (u128_00384420 *)&D_00225AA0;
        dst = (u128_00384420 *)&D_00334EC0;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003DD768();
        func_003D9C30();
    }
    func_003A92F0(8);
    if (D_001D9BC4 & 8) {
        func_003E0B10(D_003064C0);
        func_003DEE20();
    }
    func_003A92F0(0x10);
    if (D_001D9BC4 & 0x10) {
        func_003C31B0();
    }
    func_003864C0(arg0);
    D_001D9D50_00388AF8 = 0;
}
/* localdecomp:end func_00388AF8 */
