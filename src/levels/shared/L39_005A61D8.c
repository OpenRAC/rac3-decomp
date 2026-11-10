#include "common.h"

/* localdecomp:start func_L39_005A61D8 */
/* The memory-card state machine (the frontbin's func_0039C410 with four more states, 32 to 35,
   and rac2's func_00298F00). Needs @ps2as: retail builds D_2412DC's address with lui/addiu although
   gcc treats the sized word as small data (Ps2EeAs learns the size only at the end of the file),
   which keeps it one insn until reload and gives the 0x258 chain $v0 in state 23. In a run of
   independent zero stores sched1 emits the last first, so the source order is state, cur, busy
   (and sub before index in states 32 and 34). */
extern struct { u8 pad[0x64C]; s32 f64C; s32 pad650[4]; s32 f660; s32 f664; } D_1F0A00;
extern s32 func_L39_0059A218();
extern void func_L39_005A8CC8(void);
extern u8 D_L39_00499348[], D_L39_004995D8[];
typedef struct {
    s32 port;  s32 slot;  s32 type;  s32 free;
    s32 f10;   s32 f14;   s16 f18;   s16 f1A;   s32 f1C;
    s32 f20;   s32 f24;   s32 f28;   s32 f2C;   s32 f30;
    u8 p34[0x18]; s32 f4C; u8 p50[0x18]; s32 f68; u8 p6C[0x18]; s32 f84; u8 p88[0x18];
} McCard_005A61D8;
typedef struct {
    McCard_005A61D8 c[2];
    s32 f140, f144, f148, f14C, f150, f154, f158, f15C, f160, f164, f168, f16C, f170, f174, f178, f17C, f180, f184, f188;
} McState_005A61D8;
typedef struct { u8 p0[0x10]; s32 size; u8 p14[0xC]; u8 name[0x20]; } McDirEntry_005A61D8;
typedef struct { s32 type; s32 size; u8 d[0x40]; } McRecord_005A61D8;
typedef struct { u8 p0[0x48]; s32 f48; } McFlags_005A61D8;
extern McState_005A61D8 D_1A43E0;
extern McFlags_005A61D8 D_1A4610;
extern McDirEntry_005A61D8 D_L39_00268C40[];
extern u8 D_L39_00268C60[];
extern char D_2411F8[], D_241210[], D_241228[], D_24123D[], D_241248[], D_24125D[], D_241268[];
extern char D_24127D[], D_241298[], D_2412AD[], D_2412B8[];
extern u32 D_2412DC;
extern char D_L39_002430F8[], D_L39_00243100[], D_L39_00243108[], D_L39_00243110[], D_L39_00243130[], D_L39_00243150[];
extern char D_L39_00243170[], D_L39_00243190[], D_L39_002431B0[], D_L39_002431D0[];
__asm__(".extern D_001D79B8_sda, 4");
extern s32 D_001D79B8_sda;
extern s16 D_225664[];
extern u8 D_21E260[], D_21E268[], D_224260[];
extern s32 func_13B838(s32, s32 *, s32 *);
extern s32 func_13B958(s32, s32, s32 *, s32 *, s32 *);
extern s32 func_13BC30(s32, s32);
extern s32 func_13BE30(s32, s32);
extern s32 func_13BAD8(s32, s32, char *, s32, s32, void *);
extern s32 func_11D534(s32, s32, s32);
extern s32 func_1205B0(u8 *, char *);
extern s32 func_120B70(u8 *, char *, s32);
extern void func_1206F4();
extern s32 func_120048();
extern s32 func_13B1F8(s32, s32, char *, s32);
extern s32 func_13B5A8(s32, void *, s32);
extern s32 func_13B6C0(s32, void *, s32);
extern s32 func_13B358(s32);
extern s32 func_13B320(s32, s32, char *);
extern s32 func_13BD00(s32, s32, char *);
extern s32 func_13B418(s32, s32, s32);
extern s32 func_L39_005C29A0(s32, s32, s32);
extern s32 func_0039E7C8();
extern s32 func_0039E788();
extern void func_L39_005A88B0();
extern s32 func_L39_005A8968();

void func_L39_005A61D8(void) {
    s32 found[4];
    char path[0x40];
    s32 t;

    if (D_1A43E0.f154 != 0) {
        D_1A43E0.f154 = func_13B838(1, &D_1A43E0.f140, &D_1A43E0.f144) == 0;
        return;
    }
    D_1A43E0.f154 = 1;
    switch (D_1A43E0.f15C) {
    case 0:
        if ((u32)D_1A43E0.f180 >= 2) D_1A43E0.f180 = 0;
        if (func_13B958(D_1A43E0.c[D_1A43E0.f180].port, D_1A43E0.c[D_1A43E0.f180].slot, &D_1A43E0.c[D_1A43E0.f180].type, &D_1A43E0.c[D_1A43E0.f180].free, &D_1A43E0.c[D_1A43E0.f180].f14) == 0) D_1A43E0.f15C = 1;
        break;
    case 1:
        if (D_1A43E0.f144 != 0) {
            D_1A43E0.c[D_1A43E0.f180].f18 = -4;
            D_1A43E0.c[D_1A43E0.f180].f10 = D_1A43E0.f144;
            D_1A43E0.c[D_1A43E0.f180].f24 = -1;
            D_1A43E0.c[D_1A43E0.f180].f20 = 0;
            D_1A43E0.c[D_1A43E0.f180].f30 = -1;
            D_1A43E0.c[D_1A43E0.f180].f4C = -1;
            D_1A43E0.c[D_1A43E0.f180].f68 = -1;
            D_1A43E0.c[D_1A43E0.f180].f84 = -1;
            D_1A43E0.c[D_1A43E0.f180].f1C = 0;
        }
        D_1A43E0.f180++;
        if (D_1A43E0.f168 < D_1A43E0.f180 && D_1A43E0.f164 >= 0) {
            D_1A43E0.f15C = 2;
            if (D_1A43E0.f168 >= 0) {
                if (D_1A43E0.c[D_1A43E0.f168].f10 == 0 || D_1A43E0.f164 == 0x18) {
                    D_1A43E0.f14C = D_1A43E0.f168;
                    D_1A43E0.f15C = D_1A43E0.f164;
                    D_1A43E0.f16C = 0;
                } else {
                    D_1A43E0.f16C = 0x271A;
                }
            } else {
                D_1A43E0.f16C = 0x271A;
            }
            D_1A43E0.f164 = -1;
            D_1A43E0.f168 = -1;
        } else {
            if (D_1A43E0.f180 < 2) D_1A43E0.f15C = 0; else D_1A43E0.f15C = 2;
            D_1A43E0.f154 = 0;
        }
        break;
    case 2:
        D_1A43E0.f184++;
        if (D_1A43E0.f164 >= 0 || D_1A43E0.f184 > 10) {
            D_1A43E0.f184 = 0;
            D_1A43E0.f180 = 0;
            D_1A43E0.f15C = 0;
        }
        D_1A43E0.f154 = 0;
        break;
    case 3:
        if (D_1A43E0.c[D_1A43E0.f14C].f14 == 0) {
            if (func_13BC30(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot) == 0) D_1A43E0.f15C = 4;
        } else {
            D_1A43E0.f154 = 0;
            D_1A43E0.f15C = 2;
        }
        break;
    case 4:
        if (D_1A43E0.f144 != 0) {
            D_1A43E0.f16C = 1;
            D_1A43E0.f170 = D_1A43E0.f14C;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        D_1A43E0.f15C = 0;
        D_1A43E0.f14C = 0;
        D_1A43E0.f154 = 0;
        break;
    case 5:
        if (D_1A43E0.c[D_1A43E0.f14C].f14 == 0) {
            if (func_13BE30(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot) == 0) D_1A43E0.f15C = 6;
        } else {
            D_1A43E0.f154 = 0;
            D_1A43E0.f15C = 2;
        }
        break;
    case 6:
        if (D_1A43E0.f144 != 0) {
            D_1A43E0.f16C = 2;
            D_1A43E0.f170 = D_1A43E0.f14C;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        D_1A43E0.f15C = 0;
        D_1A43E0.f14C = 0;
        D_1A43E0.f154 = 0;
        break;
    case 7:
        if (func_13BAD8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_241210, 0, 0xB, D_L39_00268C40) == 0) {
            D_1A43E0.f160 = 0;
            D_1A43E0.f15C = 8;
        }
        break;
    case 8:
        switch (D_1A43E0.f160) {
        case 0:
            if (D_1A43E0.f144 > 0) {
                s32 i, total, fa, fb, fc, fd, n, total2;
                fa = 0;
                func_11D534((s32)found, 0, 0x10);
                fb = 0;
                fc = 0;
                fd = 0;
                i = 0;
                total = 0;
                for (; i < D_1A43E0.f144; i++) {
                    McDirEntry_005A61D8 *de = &D_L39_00268C40[i];
                    total += (u32)(de->size + 0x3FF) >> 10;
                    if (func_1205B0(D_L39_00268C40[i].name, D_24123D) == 0) fa = 1;
                    if (func_1205B0(D_L39_00268C40[i].name, D_24125D) == 0) fb = 1;
                    if (func_1205B0(D_L39_00268C40[i].name, D_24127D) == 0) fc = 1;
                    if (func_1205B0(D_L39_00268C40[i].name, D_2412AD) == 0) fd = 1;
                    if (func_120B70(D_L39_00268C40[i].name, D_L39_002430F8, 4) == 0 && func_120B70(D_L39_00268C40[i].name + 5, D_L39_00243100, 4) == 0) {
                        n = de->name[4] - '0';
                        if (n >= 0) {
                            if (n < 4) found[n] = 1;
                        }
                    }
                }
                total2 = total + 1;
                total = total2 + (D_1A43E0.f144 + 1) / 2;
                if ((total == 0x257 || total == 0x258) && D_1A43E0.f144 == 10 && fa && fb && fc && fd
                    && found[0] && found[1] && found[2] && found[3]) {
                    D_1A43E0.c[D_1A43E0.f14C].f20 = 0;
                    D_1A43E0.c[D_1A43E0.f14C].f18 = -1;
                    D_1A43E0.f160 = 1;
                    D_1A43E0.f154 = 0;
                    break;
                }
                D_1A43E0.c[D_1A43E0.f14C].f20 = total;
                D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
            } else {
                D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
                if (D_1A43E0.f144 == -2) {
                    D_1A43E0.f16C = 3;
                    D_1A43E0.f170 = D_1A43E0.f14C;
                } else if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
                } else if (D_1A43E0.f144 != -4) {
                    D_1A43E0.f16C = 4;
                    D_1A43E0.f170 = D_1A43E0.f14C;
                }
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        case 1:
            func_120048(path, D_2412B8, 0);
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, path, 1) == 0) D_1A43E0.f160++;
            break;
        case 2:
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f158 = D_1A43E0.f144;
                D_1A43E0.f160 = 3;
            } else {
                D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -7) D_1A43E0.f16C = 0x2710;
                else if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x2711;
                else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x2712;
                else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x2713;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 3;
                else D_1A43E0.f16C = 4;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 3:
            D_1A43E0.f178 = 8;
            if (func_13B5A8(D_1A43E0.f158, &D_1A43E0.c[D_1A43E0.f14C].f28, 8) == 0) D_1A43E0.f160 = 4;
            break;
        case 4:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                D_1A43E0.c[D_1A43E0.f14C].f24 = 0;
                if (D_1A43E0.c[D_1A43E0.f14C].f28 != func_0039E6A8(D_L39_00499348)) D_1A43E0.c[D_1A43E0.f14C].f24++;
                if (D_1A43E0.c[D_1A43E0.f14C].f2C != func_0039E6A8(D_L39_004995D8)) D_1A43E0.c[D_1A43E0.f14C].f24++;
                D_1A43E0.f154 = 0;
                D_1A43E0.f160 = 5;
            } else {
                D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x2716;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x2711;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x2714;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x2715;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 3;
                    else D_1A43E0.f16C = 4;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 5:
            if (func_13B358(D_1A43E0.f158) == 0) {
                D_1A43E0.f154 = 0;
                D_1A43E0.f15C = 0x15;
            }
            break;
        }
        break;
    case 9:
        D_1A43E0.f15C = 10;
        D_1A43E0.f188 = 6;
        D_1A43E0.f160 = 0;
        D_1A43E0.c[D_1A43E0.f14C].f18 = 0;
    case 10:
        switch (D_1A43E0.f160) {
        case 0:
            if (D_1A43E0.c[D_1A43E0.f14C].free + D_1A43E0.c[D_1A43E0.f14C].f20 >= 0x258) {
                D_1A43E0.f160 = 1;
            } else {
                D_1A43E0.f16C = 7;
                D_1A43E0.f170 = D_1A43E0.f14C;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 1:
            if (func_13B320(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_2411F8) == 0) D_1A43E0.f160 = 2;
            break;
        case 2:
            if (D_1A43E0.f144 == 0 || D_1A43E0.f144 == -4) {
                D_1A43E0.f160 = 3;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 7;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 6;
                else D_1A43E0.f16C = 0xD;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
                D_1A43E0.f154 = 0;
            }
            break;
        case 3: {
            s32 *ptr;
            ((s32 (*)())func_L39_0059A218)(D_1F0A00.f664 << 11, &ptr);
            ((void (*)(s32, s32, s32))func_L39_005C29A0)((s32)ptr, D_1F0A00.f660 + D_1F0A00.f64C, D_1F0A00.f664);
            D_1A43E0.f160 = 4;
            D_1A43E0.f154 = 0;
            break;
        }
        case 4:
            if (D_225664[0] == 0) D_1A43E0.f160 = 5;
            D_1A43E0.f154 = 0;
            break;
        case 5: case 9: case 13: case 17: case 22:
            switch (D_1A43E0.f160) {
            case 5: func_1206F4(found, D_241228); break;
            case 9: func_1206F4(found, D_241248); break;
            case 22: func_1206F4(found, D_241268); break;
            case 13: func_1206F4(found, D_241298); break;
            case 17: func_120048(found, D_2412B8, D_1A43E0.c[D_1A43E0.f14C].f18); break;
            }
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 0x203) == 0) {
                D_1A43E0.f158 = -1;
                D_1A43E0.f160++;
            }
            break;
        case 6: case 10: case 14: case 18: case 23:
            if (D_1A43E0.f144 >= 0) {
                s32 *ptr;
                if (D_1A43E0.f158 < 0) D_1A43E0.f158 = D_1A43E0.f144;
                ((s32 (*)())func_L39_0059A218)(D_1F0A00.f664 << 11, &ptr);
                switch (D_1A43E0.f160) {
                case 6:
                    D_1A43E0.f178 = 0x3C4;
                    D_1A43E0.f174 = (s32)ptr + ptr[0];
                    D_1A43E0.f188++;
                    break;
                case 10:
                    D_1A43E0.f178 = ptr[3];
                    D_1A43E0.f174 = (s32)ptr + ptr[2];
                    D_1A43E0.f188 += (D_1A43E0.f178 + 0x3FF) >> 10;
                    break;
                case 23:
                    D_1A43E0.f178 = (0x258 - D_1A43E0.f188) << 10;
                    D_1A43E0.f174 = (s32)&D_2412DC;
                    break;
                case 14: {
                    s32 n = func_0039E7C8(D_21E260, 0, &D_001D79B8_sda);
                    D_1A43E0.f174 = (s32)D_21E260;
                    D_1A43E0.f178 = n;
                    D_1A43E0.f188 += (D_1A43E0.f178 + 0x3FF) >> 10;
                    break;
                }
                case 18: {
                    s32 n = func_0039E6A8(D_L39_00499348);
                    n += func_0039E6A8(D_L39_004995D8) * 0x25;
                    D_1A43E0.f178 = n + 8;
                    D_1A43E0.f174 = (s32)ptr + ptr[4];
                    D_1A43E0.f188 += (D_1A43E0.f178 + 0x3FF) >> 10;
                    break;
                }
                }
                if (func_13B6C0(D_1A43E0.f158, (void *)D_1A43E0.f174, D_1A43E0.f178) == 0) D_1A43E0.f160++;
            } else {
                D_1A43E0.f16C = 0xA;
                D_1A43E0.f170 = D_1A43E0.f14C;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
                D_1A43E0.f154 = 0;
            }
            break;
        case 7: case 11: case 15: case 19: case 24:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                if (func_13B358(D_1A43E0.f158) == 0) D_1A43E0.f160++;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0xB;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 8;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 7;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 6;
                    else D_1A43E0.f16C = 0xD;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 8: case 12: case 16: case 20:
            if (D_1A43E0.f144 == 0) {
                D_1A43E0.f160++;
            } else {
                D_1A43E0.f16C = 0xC;
                D_1A43E0.f170 = D_1A43E0.f14C;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 21:
            if (++D_1A43E0.c[D_1A43E0.f14C].f18 < 4) D_1A43E0.f160 = 0x11;
            else D_1A43E0.f160++;
            D_1A43E0.f154 = 0;
            break;
        case 25:
            D_1A43E0.c[D_1A43E0.f14C].f28 = func_0039E6A8(D_L39_00499348);
            D_1A43E0.c[D_1A43E0.f14C].f2C = func_0039E6A8(D_L39_004995D8);
            D_1A43E0.c[D_1A43E0.f14C].f18 = -1;
            D_1A43E0.c[D_1A43E0.f14C].f24 = 0;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            break;
        }
        break;
    case 11:
        D_1A43E0.f15C = 12;
        D_1A43E0.f160 = 0;
        D_1A43E0.c[D_1A43E0.f14C].f18 = -2;
    case 12:
        switch (D_1A43E0.f160) {
        case 0:
            if (func_13BAD8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_241210, 0, 1, D_L39_00268C40) == 0) D_1A43E0.f160 = 1;
            break;
        case 1:
            if (D_1A43E0.f144 == 1) {
                func_120048(found, D_L39_00243108, D_2411F8, D_L39_00268C60);
                if (func_13BD00(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found) == 0) D_1A43E0.f160 = 2;
                break;
            }
            if (D_1A43E0.f144 == 0) {
                D_1A43E0.f160 = 3;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x10;
                else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0xF;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0xE;
                else D_1A43E0.f16C = 0x12;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 2:
            if (func_13BAD8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_241210, 1, 1, D_L39_00268C40) == 0) D_1A43E0.f160 = 1;
            break;
        case 3:
            if (func_13BD00(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_2411F8) == 0) D_1A43E0.f160 = 4;
            break;
        case 4:
            if (D_1A43E0.f144 != 0) {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -6) D_1A43E0.f16C = 0x11;
                else if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x10;
                else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0xF;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0xE;
                else D_1A43E0.f16C = 0x12;
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        break;
    case 21:
        D_1A43E0.f15C = 0x16;
        D_1A43E0.c[D_1A43E0.f14C].f1A = -1;
        D_1A43E0.f150 = 0;
        break;
    case 22:
        D_1A43E0.c[D_1A43E0.f14C].f1A++;
        if (D_1A43E0.c[D_1A43E0.f14C].f1A < 4) {
            D_1A43E0.f160 = 0;
            D_1A43E0.f15C = 0x17;
        } else {
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
        }
        break;
    case 13:
        if (D_1A43E0.c[D_1A43E0.f14C].f18 < 0) {
            D_1A43E0.f16C = 0x13;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        D_1A43E0.f150 = 0;
        D_1A43E0.f160 = 0;
        D_1A43E0.f15C = 14;
    case 14:
    case 23:
        switch (D_1A43E0.f160) {
        case 0:
            if (D_1A43E0.f15C == 0x17) func_120048(found, D_2412B8, D_1A43E0.c[D_1A43E0.f14C].f1A);
            else func_120048(found, D_2412B8, D_1A43E0.c[D_1A43E0.f14C].f18);
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 1) == 0) D_1A43E0.f160++;
            break;
        case 1:
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f158 = D_1A43E0.f144;
                D_1A43E0.f160 = 2;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -7) D_1A43E0.f16C = 0x14;
                else if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x15;
                else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x16;
                else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x17;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x18;
                else D_1A43E0.f16C = 0x1C;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 2:
            D_1A43E0.f178 = 8;
            if (func_13B5A8(D_1A43E0.f158, &D_1A43E0.c[D_1A43E0.f14C].f28, 8) == 0) D_1A43E0.f160 = 3;
            break;
        case 3:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                D_1A43E0.f154 = 0;
                D_1A43E0.f160 = 4;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x1B;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x15;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x19;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x1A;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x18;
                    else D_1A43E0.f16C = 0x1C;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 4:
            D_1A43E0.f178 = D_1A43E0.c[D_1A43E0.f14C].f28;
            if (func_13B5A8(D_1A43E0.f158, D_21E260, D_1A43E0.f178) == 0) D_1A43E0.f160 = 5;
            break;
        case 5:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                if (D_1A43E0.f15C == 0x17) {
                    func_L39_005A88B0(D_21E260, D_1A43E0.f14C, D_1A43E0.c[D_1A43E0.f14C].f1A);
                    D_1A43E0.f160 = 8;
                } else {
                    D_1A43E0.c[D_1A43E0.f14C].f24 = ((s32 (*)())func_L39_005A8968)(D_21E260, D_21E260 + D_1A43E0.f144, 0, D_L39_00499348);
                    D_1A43E0.f160 = 6;
                }
                D_1A43E0.f154 = 0;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x1B;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x15;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x19;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x1A;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x18;
                    else D_1A43E0.f16C = 0x1C;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 6:
            D_1A43E0.f178 = D_1A43E0.c[D_1A43E0.f14C].f2C;
            if (func_13B5A8(D_1A43E0.f158, D_224260, D_1A43E0.f178) == 0) D_1A43E0.f160 = 7;
            break;
        case 7:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                D_1A43E0.c[D_1A43E0.f14C].f24 += ((s32 (*)())func_L39_005A8968)(D_224260, D_224260 + D_1A43E0.f144, D_1A43E0.f150, D_L39_004995D8);
                D_1A43E0.f150++;
                if (D_1A43E0.f150 < 0x25) D_1A43E0.f160 = 6;
                else D_1A43E0.f160 = 8;
                D_1A43E0.f154 = 0;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x1B;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x15;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x19;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x1A;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x18;
                    else D_1A43E0.f16C = 0x1C;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 8:
            if (func_13B358(D_1A43E0.f158) == 0) {
                if (D_1A43E0.f15C == 0x17) {
                    D_1A43E0.f154 = 0;
                    D_1A43E0.f15C = 0x16;
                } else {
                    func_L39_005A8CC8();
                    if (D_1A43E0.c[D_1A43E0.f14C].f24 != 0) D_1A43E0.f16C = 0x1C;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                }
            }
            break;
        }
        break;
    case 15:
        if (D_1A43E0.c[D_1A43E0.f14C].f24 != 0) {
            D_1A43E0.f16C = 0x2717;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        if (D_1A43E0.c[D_1A43E0.f14C].f18 < 0) {
            D_1A43E0.f16C = 0x1D;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        D_1A43E0.f160 = 0;
        D_1A43E0.f15C = 0x10;
    case 16:
        switch (D_1A43E0.f160) {
        case 0:
            func_120048(found, D_2412B8, D_1A43E0.c[D_1A43E0.f14C].f18);
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 2) == 0) D_1A43E0.f160 = 1;
            break;
        case 1:
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f158 = D_1A43E0.f144;
                D_1A43E0.f160 = 2;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 == -7) D_1A43E0.f16C = 0x1E;
                else if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x1F;
                else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x20;
                else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x21;
                else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x22;
                else D_1A43E0.f16C = 0x26;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            D_1A43E0.f154 = 0;
            break;
        case 2:
            if (func_13B418(D_1A43E0.f158, 8, 0) == 0) D_1A43E0.f160 = 3;
            break;
        case 3:
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f160 = 4;
            } else if (func_13B358(D_1A43E0.f158) == 0) {
                D_1A43E0.f16C = 0x26;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
                D_1A43E0.f154 = 0;
            }
            break;
        case 4:
            if (func_13B6C0(D_1A43E0.f158, D_21E260, func_0039E6A8(D_L39_00499348)) == 0) D_1A43E0.f160 = 5;
            break;
        case 5:
            if (D_1A43E0.f144 == func_0039E6A8(D_L39_00499348)) {
                D_1A43E0.f160 = 6;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x25;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x1F;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x23;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x24;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x22;
                    else D_1A43E0.f16C = 0x26;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 6:
            if (func_13B418(D_1A43E0.f158, D_1A43E0.c[0].f28 + 8 + D_1A43E0.f150 * D_1A43E0.c[0].f2C, 0) == 0) D_1A43E0.f160 = 7;
            break;
        case 7:
            if (D_1A43E0.f144 == D_1A43E0.c[0].f28 + 8 + D_1A43E0.f150 * D_1A43E0.c[0].f2C) {
                D_1A43E0.f160 = 8;
            } else if (func_13B358(D_1A43E0.f158) == 0) {
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
                D_1A43E0.f154 = 0;
            }
            break;
        case 8:
            if (func_13B6C0(D_1A43E0.f158, D_224260, func_0039E6A8(D_L39_004995D8)) == 0) D_1A43E0.f160 = 9;
            break;
        case 9:
            if (D_1A43E0.f144 == func_0039E6A8(D_L39_004995D8)) {
                D_1A43E0.f160 = 0xA;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0x25;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -5) D_1A43E0.f16C = 0x1F;
                    else if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x23;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x24;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x18;
                    else D_1A43E0.f16C = 0x1C;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 10:
            if (func_13B358(D_1A43E0.f158) == 0) {
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
            }
            break;
        }
        break;
    case 17: {
        s32 *ptr;
        ((s32 (*)())func_L39_0059A218)(D_1F0A00.f664 << 11, &ptr);
        ((void (*)(s32, s32, s32))func_L39_005C29A0)((s32)ptr, D_1F0A00.f660 + D_1F0A00.f64C, D_1F0A00.f664);
        D_1A43E0.f160 = 0x12;
        D_1A43E0.f154 = 0;
        break;
    }
    case 18:
        if (D_225664[0] == 0) {
            s32 *ptr;
            ((s32 (*)())func_L39_0059A218)(D_1F0A00.f664 << 11, &ptr);
            D_1A43E0.f160 = 0x13;
            D_1A43E0.f174 = (s32)ptr + ptr[4];
        }
        D_1A43E0.f154 = 0;
        break;
    case 19:
        if (D_1A43E0.c[D_1A43E0.f14C].f24 != 0) {
            D_1A43E0.f16C = 0x2718;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        if (D_1A43E0.c[D_1A43E0.f14C].f18 < 0) {
            D_1A43E0.f16C = 0x27;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        D_1A43E0.f150 = 0;
        D_1A43E0.f160 = 0;
        D_1A43E0.f15C = 0x14;
    case 20:
        switch (D_1A43E0.f160) {
        case 0:
            func_120048(found, D_2412B8, D_1A43E0.c[D_1A43E0.f14C].f18);
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 2) == 0) D_1A43E0.f160 = 1;
            break;
        case 1:
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f158 = D_1A43E0.f144;
                t = func_0039E6A8(D_L39_00499348);
                t += func_0039E6A8(D_L39_004995D8) * 0x25;
                D_1A43E0.f178 = t + 8;
                if (func_13B6C0(D_1A43E0.f158, (void *)D_1A43E0.f174, D_1A43E0.f178) == 0) D_1A43E0.f160 = 2;
            } else {
                D_1A43E0.f16C = 0x2B;
                D_1A43E0.f170 = D_1A43E0.f14C;
                D_1A43E0.f15C = 0;
                D_1A43E0.f14C = 0;
                D_1A43E0.f154 = 0;
            }
            break;
        case 2:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                if (func_13B358(D_1A43E0.f158) == 0) D_1A43E0.f160 = 3;
            } else {
                D_1A43E0.f170 = D_1A43E0.f14C;
                if (D_1A43E0.f144 >= 0) {
                    D_1A43E0.f16C = 0xB;
                    if (func_13B358(D_1A43E0.f158) == 0) {
                        D_1A43E0.f15C = 0;
                        D_1A43E0.f14C = 0;
                        D_1A43E0.f154 = 0;
                    }
                } else {
                    if (D_1A43E0.f144 == -4) D_1A43E0.f16C = 0x28;
                    else if (D_1A43E0.f144 == -3) D_1A43E0.f16C = 0x29;
                    else if (D_1A43E0.f144 == -2) D_1A43E0.f16C = 0x2A;
                    else D_1A43E0.f16C = 0x2D;
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
            }
            break;
        case 3:
            if (D_1A43E0.f144 != 0) {
                D_1A43E0.f16C = 0x2C;
                D_1A43E0.f170 = D_1A43E0.f14C;
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        break;
    case 32:
        D_1A43E0.f15C = 33;
        D_1A43E0.f160 = 0;
        D_1A43E0.f150 = 0;
    case 33:
        switch (D_1A43E0.f160) {
        case 0:
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_241298, 1) == 0) {
                D_1A43E0.f160 = 1;
            }
            break;
        case 1:
            if (D_1A43E0.f144 >= 0) {
                s32 n;

                D_1A43E0.f158 = D_1A43E0.f144;
                D_1A43E0.f174 = (s32)D_21E260;
                n = func_0039E6A8(&D_001D79B8_sda);
                D_1A43E0.f178 = n;
                if (func_13B5A8(D_1A43E0.f158, (void *)D_1A43E0.f174, n) == 0) {
                    D_1A43E0.f160 = 2;
                }
                break;
            }
            D_1A43E0.f16C = 0x2E;
            D_1A43E0.f170 = D_1A43E0.f14C;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        case 2:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                if (func_13B358(D_1A43E0.f158) == 0) {
                    D_1A43E0.f160 = 3;
                }
                break;
            }
            D_1A43E0.f170 = D_1A43E0.f14C;
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f16C = 0x2F;
                if (func_13B358(D_1A43E0.f158) == 0) {
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
                break;
            }
            if (D_1A43E0.f144 == -5) {
                D_1A43E0.f16C = 0x30;
            } else if (D_1A43E0.f144 == -4) {
                D_1A43E0.f16C = 0x31;
            } else if (D_1A43E0.f144 == -3) {
                D_1A43E0.f16C = 0x32;
            } else if (D_1A43E0.f144 == -2) {
                D_1A43E0.f16C = 0x33;
            } else {
                D_1A43E0.f16C = 0x34;
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        case 3:
            if (D_1A43E0.f144 != 0) {
                D_1A43E0.f16C = 0x35;
                D_1A43E0.f170 = D_1A43E0.f14C;
            } else {
                D_1A43E0.c[D_1A43E0.f14C].f24 = func_L39_005A8968(D_21E260, D_21E260 + D_1A43E0.f178, 0, &D_001D79B8_sda);
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        break;

    case 34:
        D_1A43E0.f15C = 35;
        D_1A43E0.f160 = 0;
        D_1A43E0.f150 = 0;
    case 35:
        switch (D_1A43E0.f160) {
        case 0:
            if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, D_241298, 2) == 0) {
                D_1A43E0.f160 = 1;
            }
            break;
        case 1:
            if (D_1A43E0.f144 >= 0) {
                s32 n;

                D_1A43E0.f158 = D_1A43E0.f144;
                n = func_0039E6A8(&D_001D79B8_sda) + 8;
                D_1A43E0.f178 = n;
                if (func_13B6C0(D_1A43E0.f158, (void *)D_1A43E0.f174, n) == 0) {
                    D_1A43E0.f160 = 2;
                }
                break;
            }
            D_1A43E0.f16C = 0x36;
            D_1A43E0.f170 = D_1A43E0.f14C;
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        case 2:
            if (D_1A43E0.f144 == D_1A43E0.f178) {
                if (func_13B358(D_1A43E0.f158) == 0) {
                    D_1A43E0.f160 = 3;
                }
                break;
            }
            D_1A43E0.f170 = D_1A43E0.f14C;
            if (D_1A43E0.f144 >= 0) {
                D_1A43E0.f16C = 0x37;
                if (func_13B358(D_1A43E0.f158) == 0) {
                    D_1A43E0.f15C = 0;
                    D_1A43E0.f14C = 0;
                    D_1A43E0.f154 = 0;
                }
                break;
            }
            if (D_1A43E0.f144 == -4) {
                D_1A43E0.f16C = 0x38;
            } else if (D_1A43E0.f144 == -3) {
                D_1A43E0.f16C = 0x39;
            } else if (D_1A43E0.f144 == -2) {
                D_1A43E0.f16C = 0x3A;
            } else {
                D_1A43E0.f16C = 0x3B;
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        case 3:
            if (D_1A43E0.f144 != 0) {
                D_1A43E0.f16C = 0x3C;
                D_1A43E0.f170 = D_1A43E0.f14C;
            }
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
            break;
        }
        break;
    case 24:
        D_1A43E0.f15C = 0x19;
        D_1A43E0.f160 = 0;
        D_1A43E0.c[D_1A43E0.f14C].f1C = 1;
    case 25: {
        s32 q = D_1A43E0.f160 / 5;
        s32 m = D_1A43E0.f160 % 5;
        switch (q) {
        case 0: func_120048(found, D_L39_00243110, m); break;
        case 1: func_120048(found, D_L39_00243130, m); break;
        case 2: func_120048(found, D_L39_00243150, m); break;
        case 3: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_1A43E0.f15C = 0x1C;
            D_1A43E0.f154 = 0;
        } else if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 1) == 0) {
            D_1A43E0.f15C = 0x1A;
        }
        break;
    }
    case 26:
        if (D_1A43E0.f144 >= 0) {
            D_1A43E0.f158 = D_1A43E0.f144;
            if (func_13B5A8(D_1A43E0.f158, D_21E260, 0x2800) == 0) D_1A43E0.f15C = 0x1B;
        } else {
            D_1A43E0.f154 = 0;
            D_1A43E0.f15C = 0x19;
            D_1A43E0.f160 = (D_1A43E0.f160 / 5 + 1) * 5;
        }
        break;
    case 27:
        if (D_1A43E0.f144 >= 0x2800) {
            McRecord_005A61D8 *ent;
            if (func_13B358(D_1A43E0.f158) != 0) return;
            if (func_0039E788(D_21E268) != 0) {
                ent = (McRecord_005A61D8 *)(D_21E268 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        D_1A4610.f48 |= 0x40;
                        if (ent->d[0x1F] != 0) {
                            D_1A4610.f48 |= 1;
                            D_1A43E0.c[D_1A43E0.f14C].f1C++;
                        }
                        break;
                    }
                    ent = (McRecord_005A61D8 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_1A43E0.f160++;
        } else {
            D_1A43E0.f160 = (D_1A43E0.f160 / 5 + 1) * 5;
        }
        D_1A43E0.f15C = 0x19;
        D_1A43E0.f154 = 0;
        break;
    case 28:
        D_1A43E0.f15C = 0x1D;
        D_1A43E0.f160 = 0;
        D_1A43E0.c[D_1A43E0.f14C].f1C++;
    case 29:
        switch (D_1A43E0.f160 / 5) {
        case 0: func_120048(found, D_L39_00243170, D_1A43E0.f160 % 4); break;
        case 1: func_120048(found, D_L39_00243190, D_1A43E0.f160 % 4); break;
        case 2: func_120048(found, D_L39_002431B0, D_1A43E0.f160 % 4); break;
        case 3: func_120048(found, D_L39_002431D0, D_1A43E0.f160 % 4); break;
        case 4: *(u8 *)found = 0; break;
        }
        if (*(u8 *)found == 0) {
            D_1A43E0.f15C = 0;
            D_1A43E0.f14C = 0;
            D_1A43E0.f154 = 0;
        } else if (func_13B1F8(D_1A43E0.c[D_1A43E0.f14C].port, D_1A43E0.c[D_1A43E0.f14C].slot, (char *)found, 1) == 0) {
            D_1A43E0.f15C = 0x1E;
        }
        break;
    case 30:
        if (D_1A43E0.f144 >= 0) {
            D_1A43E0.f158 = D_1A43E0.f144;
            if (func_13B5A8(D_1A43E0.f158, D_21E260, 0x2800) == 0) D_1A43E0.f15C = 0x1F;
        } else {
            D_1A43E0.f154 = 0;
            D_1A43E0.f15C = 0x1D;
            D_1A43E0.f160 = (D_1A43E0.f160 / 5 + 1) * 5;
        }
        break;
    case 31:
        if (D_1A43E0.f144 >= 0x2800) {
            McRecord_005A61D8 *ent;
            if (func_13B358(D_1A43E0.f158) != 0) return;
            if (func_0039E788(D_21E268) != 0) {
                ent = (McRecord_005A61D8 *)(D_21E268 + 8);
                while (ent->type != -1) {
                    if (ent->type == 10) {
                        u8 *d = ent->d;
                        D_1A4610.f48 |= 0x80;
                        if (d[0x29] != 0) { D_1A4610.f48 |= 2; D_1A43E0.c[D_1A43E0.f14C].f1C++; }
                        if (d[0x1D] != 0) { D_1A4610.f48 |= 4; D_1A43E0.c[D_1A43E0.f14C].f1C++; }
                        if (d[0x25] != 0) { D_1A4610.f48 |= 8; D_1A43E0.c[D_1A43E0.f14C].f1C++; }
                        if (d[0x2D] != 0) { D_1A4610.f48 |= 0x10; D_1A43E0.c[D_1A43E0.f14C].f1C++; }
                        if (d[0x1C] != 0) { D_1A4610.f48 |= 0x20; D_1A43E0.c[D_1A43E0.f14C].f1C++; }
                        break;
                    }
                    ent = (McRecord_005A61D8 *)((u8 *)ent + ((ent->size + 3) / 4 * 4 + 8));
                }
            }
            D_1A43E0.f160++;
        } else {
            D_1A43E0.f160 = (D_1A43E0.f160 / 5 + 1) * 5;
        }
        D_1A43E0.f15C = 0x1D;
        D_1A43E0.f154 = 0;
        break;
    }
}
/* localdecomp:end func_L39_005A61D8 */

/* localdecomp:start func_L39_005A8658 */
void func_0013AF60();

void func_L39_005A8658(void) {
    func_0013AF60();
}
/* localdecomp:end func_L39_005A8658 */
