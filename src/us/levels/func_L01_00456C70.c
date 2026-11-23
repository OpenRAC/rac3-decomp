#include "common.h"

/* NTSC-U counterpart of func_L01_00459F60 (src/levels/shared/L01_004596E8.c): the fade-in limit 1.1f and step 0.05f in place of 1.12f/0.06f; data moved */
/* localdecomp:start func_L01_00456C70 */
typedef struct {
    u8 pad0[0x5E];
    s16 h5E;
} S_459F60;

/* The WAD table (as func_L01_00423238 reads it): the level entries of 0x14C bytes from 0x9250 */
typedef struct { s32 sector; s32 size; u8 pad8[0x14C - 0x8]; } Level_459F60;
typedef struct {
    u8 pad0[0x921C];
    s32 base;                  /* 0x921C */
    u8 pad9220[0x9250 - 0x9220];
    Level_459F60 levels[1];    /* 0x9250 */
} Wad_459F60;
extern s32 D_L01_001D6690;
extern s32 D_L01_001D6694;
extern s32 D_L01_001D668C;
extern s32 D_L01_001D6674;
extern f32 D_L01_001D6720;
extern u8 D_L01_001D672D;
extern s32 D_001D545C;
extern s32 D_001D4CEC;
extern s32 D_001A7430[];
extern u8 D_00160C40[];
extern s16 D_0016C5A6[];
extern s16 D_001CCFD4[];
extern s32 D_L01_001D7DBC;
extern s32 D_L01_001D7DC0;
extern s32 D_L01_001D7DC4;
extern u8 *D_L01_001D7DCC;
extern s32 D_L01_001D9760;
extern s32 D_L01_001D9958;
extern s32 D_L01_001D9AA4;
extern s32 D_L01_001D9AAC;
/* a one-element .sdata array: gcc then cannot tell its stores from D_L01_001D6720, and reloads
   D_L01_001D6720 after the clamp as retail does */
extern f32 D_L01_001DF9D0[1] __attribute__((section(".sdata")));
extern s32 D_L01_001DFBC4;
extern s32 D_L01_001DFBD4;
extern s32 D_L01_001E10F0;
extern S_459F60 D_L01_001E6E00;
extern f32 D_L01_001E76B0[];
extern s32 D_L01_001EA9CC[];

extern void func_L01_004C5038(void);
extern void func_L01_0047AD08(void);
extern void func_L01_00413728(void);
extern void func_003A3508(void);
extern void func_L01_004B6188(void);
extern void func_0037E568(s32, s32, s32, f32, f32, f32, f32);
extern void func_003830E8(void);
extern void func_L01_004A93C0(void);
extern void func_L01_004B81F8(void);
extern void func_L01_0049FCE8(void);
extern void func_L01_004C5C08(void);
extern void func_L01_00420340_00456C70(void);
extern void func_L01_00457240(s32);
extern s32 func_L01_00413670_00456C70(void);
extern void func_L01_0047A568(s32);
extern void func_L01_00413788(s32, s32);
extern void func_003A3368(s32);
extern void func_L01_0045BF98(s32);
extern void func_0039D6C8(s32);
extern s32 func_003A3220(s32);
extern void func_003A3B00(void);
extern void func_0039D510(s32, s32, s32);
extern void func_003BEBF8(void *, f32, f32);
extern void func_L01_004B5C78(s32);
extern void func_L01_004A91D8(s32);
extern s32 func_0038E5B8();
extern void func_L01_004A9350(void);
extern void func_L01_004A9148(void);
extern void func_L01_004B7948(s32);
extern void func_L01_0049FC48(s32, s32);
extern void func_L01_004C5950(void);
extern void func_003ADC70(s32);
extern void func_L01_00420320_00456C70(void);

/* game_mode_apply: leaves the old game mode (D_L01_001D6694) for the one asked for (D_L01_001D6690). */
/* game_mode_apply */
void func_L01_00456C70(void) {
    s32 prev;
    s32 next;
    s32 stay;

    func_L01_004C5038();
    prev = D_L01_001D6694;
    next = D_L01_001D6690;
    D_L01_001D668C = prev;
    if (next == -2) {
        return;
    }
    if (D_L01_001D7DBC > 0) {
        D_L01_001D7DBC = D_L01_001D7DBC - 1;
        return;
    }
    if (!((prev == 0 && (D_001D4CEC & 1)) || (prev == 4 && next == 0))) {
        if (D_001A7430[0] == 0) {
            return;
        }
    }
    switch (D_L01_001D6694) {
    case 3:
        if (D_L01_001D6690 != 4 || D_L01_001D7DC0 == 8) {
            func_L01_0047AD08();
        }
        break;
    case 4:
        func_L01_00413728();
        break;
    case 1:
        func_003A3508();
        D_L01_001E76B0[0] = 0.62f;
        func_0037E568(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003830E8();
        break;
    case 2:
        func_L01_004B6188();
        D_L01_001E76B0[0] = 0.62f;
        func_0037E568(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_003830E8();
        break;
    case 6:
        if (D_L01_001D7DC0 != 4) {
            func_L01_004A93C0();
        }
        break;
    case 5:
        func_L01_004B81F8();
        break;
    case 7:
        func_L01_0049FCE8();
        break;
    case 8:
        func_L01_004C5C08();
        break;
    case 9:
        func_L01_00420340_00456C70();
        break;
    case 0: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
        break;
    }
    stay = 0;
    func_L01_00457240(10);
    switch (D_L01_001D6690) {
    case 3: {
        s32 k = D_L01_001D668C;
        if (k != 4 || func_L01_00413670_00456C70() == 8 || (D_L01_001D668C == k && func_L01_00413670_00456C70() == 11) || D_L01_001D672D != 0) {
            func_L01_0047A568(D_L01_001D7DC0);
        }
        stay = 0;
    }
    case 0:
        stay = 0;
        break;
    case 4:
        func_L01_00413788(D_L01_001D7DC0, D_L01_001D7DC4);
        break;
    case 1:
        stay = 0;
        func_003A3368(D_L01_001D7DC4);
        break;
    case 2:
        if (D_L01_001D6694 - 1 >= 2U) {
            if (D_L01_001E6E00.h5E == 0) {
                D_L01_001E6E00.h5E = 1;
                if (D_L01_001DF9D0[0] > D_L01_001D6720) {
                    D_L01_001D6720 = D_L01_001DF9D0[0];
                }
                func_L01_0045BF98(0);
                func_0039D6C8(0);
                if (D_L01_001D6720 < 0.25f) {
                    s32 idx = func_003A3220(D_L01_001D7DC0);
                    if (((Wad_459F60 *)D_00160C40)->levels[idx].size > 0) {
                        if (D_001CCFD4[0] != 0) {
                            func_0039D6C8(1);
                        }
                        func_003A3B00();
                        D_L01_001E10F0 -= 0x1000;
                        func_0039D510(D_L01_001EA9CC[0] + D_L01_001E10F0, ((Wad_459F60 *)D_00160C40)->levels[idx].sector + ((Wad_459F60 *)D_00160C40)->base, 1);
                    }
                }
            }
            func_003BEBF8(&D_L01_001D6720, 1.1f, 0.050000004f);
            D_L01_001DF9D0[0] = D_L01_001D6720;
            if (1.0f < D_L01_001D6720) {
                D_L01_001DF9D0[0] = 1.0f;
            }
            if (D_L01_001D6720 >= 1.1f) {
                stay = 0;
                D_L01_001D6720 = 1.0f;
                func_L01_004B5C78(D_L01_001D7DC0);
            } else {
                stay = 1;
            }
        } else {
            func_L01_004B5C78(D_L01_001D7DC0);
        }
        break;
    case 6:
        if (D_L01_001D9AAC != 0) {
            D_0016C5A6[0] = 1;
            D_L01_001D9958 = 0;
            D_L01_001D9AAC = 0;
        }
        if (D_L01_001D9AA4 != 0) {
            D_L01_001DFBC4 = 6;
            func_L01_004A91D8(6);
            D_L01_001D9AA4 = 0;
        } else if (D_L01_001D7DC0 == 5) {
            func_0038E5B8(D_L01_001D7DC4, 1);
        } else if (D_L01_001D7DC0 == 6) {
            func_L01_004A9350();
        } else if (D_L01_001D7DC0 == 3) {
            func_L01_004A91D8(D_001D545C);
        } else {
            if (D_L01_001D668C == 3) {
                if (D_L01_001D6674 != 0) {
                    D_L01_001D6674 = 0;
                    D_L01_001D7DC4 = D_L01_001DFBC4;
                }
                func_L01_004A91D8(D_L01_001D7DC4);
            } else {
                func_L01_004A9148();
            }
            D_L01_001DFBD4 = 1;
        }
        break;
    case 5:
        func_L01_004B7948(D_L01_001D7DC0);
        break;
    case 7:
        {
            s32 alt = D_L01_001D9760;
            s32 mode = D_L01_001D7DC0;
            func_L01_0049FC48(mode ? mode : alt, D_L01_001D7DC4);
        }
        break;
    case 8:
        func_L01_004C5950();
        break;
    case 18:
        func_003ADC70(D_L01_001D7DC0);
        break;
    case 9:
        func_L01_00420320_00456C70();
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        break;
    }
    if (stay == 0) {
        if (D_L01_001D7DCC != 0) {
            *D_L01_001D7DCC = 1;
        }
        D_L01_001D6694 = D_L01_001D6690;
        D_L01_001D6690 = -2;
        D_L01_001D7DCC = 0;
    }
}
/* localdecomp:end func_L01_00456C70 */
