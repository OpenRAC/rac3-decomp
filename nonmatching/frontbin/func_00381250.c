/* func_00381250 (PAL frontbin, src/frontbin/381140.c, flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as): the front end's main loop. Plain-C draft written 2026-11-22 from
   the assembly, starting from Flavius's functional draft (nonmatching/functional/func_00381250.c,
   609 differences with the same line). Near miss: 121 differences (tools/check.py, PAL frontbin),
   also 121 with --no-context. NTSC-U: config/us/map.tsv says its copy differs (not carried).
   What got it from 609 to 121: `.extern X, 4` hints for the globals retail reaches through $gp
   outside delay slots (Ps2EeAs is single-pass); D_001D5738 / D_001D5758 declared as 8-byte objects
   so gcc emits one `la` that Ps2EeAs turns into `addiu $gp` (Matching-Patterns l.433); the EE timer
   1 count at its literal address; the mode switch's bodies in retail's order (0, 1, 3, 2, 4, 5, 6,
   10, 8, 9); the idx >= 0 arm first; the image offset at +0x58 read before the two global stores;
   the heap header read before D_001D99A0 is set; 32.0f in a local across func_00381FF0 (one saved
   float, $f20, as retail). The init block's stores are in the order a hill-climb over single-line
   moves found closest (sched is backwards, so source order is not retail's store order).
   Blockers: (1) `D_001D4B50 = img + 0x10;` before `jal func_00398E50`: retail keeps the store out
   of the delay slot as `lui $at; sw` and leaves a `nop` (the "store that gcc pulls into a delay
   slot" class, see func_00396C18's row); a scalar goes into the slot (and Ps2EeAs uses $gp there),
   an unsized or 16-byte array gives the split form, also in the slot. Its one-word shift moves the
   two alignment `nop`s and most of the remaining count. (2) The init block's store schedule (about
   20 words). (3) `lw; dsrl 6; andi 1` for the D_00142BA4 bit test: u32 and s32 shifts, an
   `unsigned long` cast and u32/s32 bitfields give srl/sra; a 64-bit bitfield gives ld. (4) idx in
   $a1 with `bltz` where retail has $a0 and `bltzl`; small sll/addu orders at the 0x80808080 call
   and at the end. */
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_00381250;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227580_00381250;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_00381250;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_00381250;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_00381250;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_00381250;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_00381250;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_31CC80_00381250;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_00381250;
typedef struct { s32 a; s32 b; } E_00381250;

extern S_1A1ED0_00381250 D_001A1ED0;
extern S_227580_00381250 D_00227580_00381250;
extern S_1CCFD0_00381250 D_001CCFD0;
extern S_16C580_00381250 D_0016C580;
extern S_160C40_00381250 D_00160C40;
extern S_143950_00381250 D_00143950;
extern S_142430_00381250 D_00142430;
extern S_31CC80_00381250 D_0031CC80;
extern u8 D_001D5BDC;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D4B64;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
extern void *D_001D4B50[];
extern s32 D_001A7430[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D5B8C;
extern s32 D_001D9D08;
extern s32 D_001D9BC8;
extern s32 D_001D5B9C;
extern s32 D_001D9D2C;
extern u8 D_0031CCD0[];
extern void *D_001D99A0;
extern s32 D_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_001D5750;
extern s32 D_001D574C;
extern s32 D_001D5738[2];
extern E_00381250 D_001D5758[1];
extern E_00381250 D_001D575C[];
extern S_pad_00381250 *D_001D52FC;
extern s32 D_001D5680;
extern s32 D_001D5684;
extern s32 D_001D5688;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern u32 D_00142BA4[];
extern s32 D_001D9D04;
extern f32 D_001D9D0C;
extern u8 D_001D5570[];

/* Ps2EeAs reaches these through $gp only if it knows their size before the use. */
__asm__(".extern D_001D5750, 4");
__asm__(".extern D_001D574C, 4");
__asm__(".extern D_001D5738, 8");
__asm__(".extern D_001D5758, 8");
__asm__(".extern D_001D5680, 4");
__asm__(".extern D_001D5684, 4");
__asm__(".extern D_001D5688, 4");
__asm__(".extern D_001D568C, 4");
__asm__(".extern D_001D5690, 4");

extern void func_003A8630(void);
extern void func_003A1330(void);
extern void func_003A9050(void);
extern void func_00397EA8(void);
extern void func_00387268(void);
extern void func_003A9108(void);
extern void func_003A9A40(void);
extern void func_0039A6E0(void);
extern s32 func_003A2598(u8 *, s32, s32);
extern void func_00392260(s32, s32, s32);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00387F68(void);
extern s32 func_12C908(s32);
extern void func_00392290(void);
extern s32 func_003A2750(s32);
extern void func_003A0760(u8 *, u8 *);
extern void func_003A11F0(u8 *, s32);
extern void func_00398E50(void);
extern void func_003A0D48(void);
extern void func_003811E8(void);
extern void func_003B2E50(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_00381080(void);
extern void func_003A3B70(void);
extern void func_00381D88(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void func_0038E150(s32);
extern void func_003B3050(void);
extern void func_003B3088();
extern void func_003A9830(u8 *, s32, s32, s32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003BB0B0(void);
extern s32 func_003E8528(s32, s32 *);
extern s32 func_003E6FE8();
extern s32 func_003E84B0(s32);
extern void *func_003B4FD0();
extern void func_003E6FE0(void *);
extern s32 func_003E8440(void *);
extern void func_003A4288(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00389240(s32);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389370(void);
extern void func_003A8B10(void);
extern void func_003A1F30();
extern void func_003B3910(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern void func_00388138(void);
extern void func_003A78B8(void);

void func_00381250(void) {
    u8 *img;
    u8 *dst;
    u8 *lang;
    u8 *heap;
    s32 *p;
    s32 i;
    s32 state;
    s32 idx;
    s32 cnt;
    s32 mode;
    s32 handle;

    D_001D5BDC = 1;
    func_003A8630();
    func_003A1330();
    func_003A9050();
    func_00397EA8();

    D_001D4BB0 = D_001A1ED0.fC;
    D_001D4BB4 = D_001A1ED0.fC;
    D_001A1ED0.f28 = 0x60000;
    D_001A1ED0.f38 = 0x160000;
    D_001A1ED0.f3C = 0x1D0000;
    D_001A1ED0.f34 = 0xF0000;
    D_001A1ED0.f2C = 0x70000;
    D_001A1ED0.f30 = 0xB0000;
    D_001A1ED0.f24 = 0;
    D_001D4B64 = D_00227580_00381250.f78;
    D_0016C580.f18 = -1;
    D_001CCFD0.f3C = -1;
    D_001D4B90 = -1;
    D_001D4BA0 = -1;
    D_001D4B60 = -1;
    D_0016C580.f30 = -1;
    D_001CCFD0.f24 = -1;
    D_001CCFD0.f41 = 0;
    D_001CCFD0.f42 = 0;
    D_001CCFD0.f43 = 0;
    D_001CCFD0.f44 = 0;
    D_001CCFD0.f4E = 0;
    D_001CCFD0.f6C = 0;
    D_001CCFD0.f76 = 0;
    D_001CCFD0.fBC = 0;
    D_001CCFD0.fC6 = 0;
    D_001A1ED0.f40 = 0x1E0000;
    D_001CCFD0.f40 = 0x20;
    func_00387268();
    func_003A9108();
    func_003A9A40();
    func_0039A6E0();

    img = D_00227580_00381250.f18 + 0x400000;
    func_003A2598(img, D_00160C40.f688 + D_00160C40.f64C, D_00160C40.f68C);
    dst = img + 0x200000;
    func_00392260(0, 0, 0);
    func_003922B8();
    func_00392350(0);
    func_00387F68();
    D_001A7430[0] = 1;
    D_001CCFD0.f7 = 0;
    D_001D5B90 = -2;
    D_001D5B94 = 0;
    D_001D5B8C = 0;
    D_001D9D08 = 0;
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392290();
    D_001D9BC8 = 0;
    func_12C908(0);
    func_00392290();
    func_003A2750(1);
    func_003A0760(img + *(s32 *)(img + 0x60), dst);
    func_003A11F0(dst, 0);
    lang = img + *(s32 *)(img + 0x58);
    D_001D5B9C = 0x13;
    D_001D9D2C = (s32)D_0031CCD0;
    dst += 0x32000;
    func_003A0760(lang, dst);
    p = (s32 *)(img + 0x28);
    for (i = 5; i >= 0; i--) {
        *p -= 0x10;
        p += 2;
    }
    D_001D4B50[0] = img + 0x10;
    func_00398E50();

    lang = 0;
    switch (D_00143950.fB7) {
    case 0:
    case 1:
        lang = img + *(s32 *)(img + 0x00);
        break;
    case 2:
        lang = img + *(s32 *)(img + 0x08);
        break;
    case 3:
        lang = img + *(s32 *)(img + 0x10);
        break;
    case 4:
        lang = img + *(s32 *)(img + 0x18);
        break;
    case 5:
        lang = img + *(s32 *)(img + 0x20);
        break;
    }
    func_003A0760(lang, D_00227580_00381250.f18);

    heap = D_00227580_00381250.f18;
    D_0031CC80.f2C = *(u32 *)heap >> 4;
    D_001D99A0 = heap;
    for (i = 0; i < D_0031CC80.f2C; i++) {
        *(s32 *)(heap + i * 16) += (s32)heap;
    }
    func_003A0D48();
    func_003811E8();
    func_003B2E50();

    while (D_001D5B74 == 0) {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        func_003A91D0();
        func_003A9150();
        func_003923D0();
        func_00392748(1);
        func_00381080();
        func_003922B8();
        func_00392350(0);
        state = D_001D5B94;
        handle = 0;
        D_001D4BB0 = D_001A1ED0.fC;
        switch (state + 1) {
        case 0:
        case 1:
            func_003A3B70();
            idx = D_001D5750;
            if (idx >= 0) {
                if (idx > 0 && (D_001D52FC->f1A4 & 4)) {
                    D_001D5750 = idx - 1;
                } else {
                    idx = D_001D5750 + 1;
                    if (D_001D5758[idx].a > 0 && (D_001D52FC->f1A4 & 8)) {
                        D_001D5750 = idx;
                    }
                }
            } else {
                if ((D_001D52FC->f1A0 & 0x600) != 0x600) {
                    D_001D574C = 0;
                } else if (D_001D52FC->f1A4 != 0) {
                    if ((D_001D52FC->f1A4 & D_001D5738[D_001D574C]) == D_001D5738[D_001D574C]) {
                        D_001D574C++;
                        if (D_001D5738[D_001D574C] == -1) {
                            D_001D5750 = 0;
                        }
                    } else {
                        D_001D574C = 0;
                    }
                }
            }
            if (D_001D52FC->f1A0 != 0 || D_00142430.f15C >= 3 || D_00142430.f164 >= 0) {
                D_001D5688 = 0;
            }
            if (D_001D568C != 0) {
                func_00381D88();
            } else {
                cnt = D_001D5680;
                if (cnt < 0) {
                    cnt = 0;
                }
                D_001D5680 = --cnt;
                if (cnt <= 0 && (D_001D52FC->f1A0 & 0xF) == 0xF) {
                    D_001D568C = 1;
                    D_001D5690 = 9;
                    D_001D5680 = 0;
                    D_001D5694 = 0;
                } else {
                    if (func_13D3C8() == 7) {
                        func_13D3C0(5);
                        D_00227400[0] = 1;
                        D_001D4D40 = 1;
                        func_00392B20(D_00227400, 0);
                        func_00392C78(D_00227400);
                        func_13D3C0(9);
                        D_001D5688 = 0;
                    } else if (D_001D5688++ > 6000) {
                        if (func_13D3C8() == 0) {
                            func_13D3C0(5);
                        }
                    }
                    mode = func_13D3C8();
                    func_0038E150(0);
                    func_003B3050();
                    func_003B3088(0);
                    switch (mode) {
                    case 0:
                        func_003A9830(dst + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_0038AE20(0, 0, 0, 0x60);
                        break;
                    case 1:
                        func_13D3C0(2);
                        break;
                    case 3:
                        if (!(((unsigned long)D_00142BA4[0] >> 6) & 1)) {
                            break;
                        }
                    case 2:
                        func_13D3C0(4);
                        break;
                    case 4:
                        D_001D9D04 = 1;
                        D_001D5B74 = 1;
                        func_13D3C0(0);
                        break;
                    case 5:
                        func_003BB0B0();
                        func_13D3C0(6);
                        break;
                    case 6:
                        func_003A9830(dst + 0x10, D_001A1ED0.f4, 0x200, 0x1A0);
                        func_0038AE20(0, 0, 0, 0x60);
                        func_003E8528(D_001D5684, &handle);
                        if (handle == 0 || func_003E6FE8(handle) == 0) {
                            func_13D3C0(7);
                        }
                        break;
                    case 7:
                        break;
                    case 10:
                        func_003E8528(D_001D5684, &handle);
                        if (handle != 0 && func_003E6FE8(handle) != 0) {
                            func_003E84B0(D_001D5684);
                        }
                        func_13D3C0(8);
                        break;
                    case 8:
                        func_003E8528(D_001D5684, &handle);
                        if (handle == 0 || func_003E6FE8(handle) == 0) {
                            func_003E6FE0(func_003B4FD0());
                            D_001D5684 = func_003E8440(func_003B4FD0());
                            func_13D3C0(0);
                        }
                        D_001D5688 = 0;
                        break;
                    case 9:
                        D_001D5688 = 0;
                        func_13D3C0(10);
                        break;
                    }
                }
            }
            func_003A4288();
            if (D_001D568C == 0 || D_001D5690 != 9) {
                func_00387F68();
                func_003A9440(0x47, 0x33001);
                func_00389240(0);
                func_003B30E8();
                func_003B3158(0);
                func_003B3120();
                if (D_001D5750 >= 0) {
                    f32 sz = 32.0f;
                    s32 tex = func_00381FF0(D_001D575C[D_001D5750].a);
                    func_0038E7E8(sz, sz, 1.0f, 0x80808080, tex, -1, 1.0f, 0, 0, 0x80000000, 0.0f, 0.0f);
                }
                func_00389370();
            }
            break;
        case 2:
            func_003A8B10();
            break;
        case 4:
        case 5:
        case 19:
            func_003A3B70();
            func_003A2750(0);
            func_003A1F30();
            func_003B3910();
            break;
        }

        D_001D9D08++;
        func_003A4288();
        func_0039C410();
        func_0039ADE0();
        func_003A92F0(1);
        D_001D9D0C = (f32)*(volatile u32 *)0x10000800 / (D_00143950.f0 != 0 ? 11520.0f : 9600.0f);
        func_00388138();
        func_003A0D48();
        if (D_001D5B94 != state) {
            D_001D9D08 = 0;
        }
        D_001D9BC8++;
        func_12C908(0);
    }

    if (D_001D5750 >= 0) {
        idx = D_001D5758[D_001D5750].a;
        if (D_001D5570[idx] != 0) {
            D_001D9D04 = idx;
        }
    }
    func_003A78B8();
}
