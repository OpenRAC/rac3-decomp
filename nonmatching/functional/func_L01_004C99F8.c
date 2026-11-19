/* functional: medium. from scratch; compiles in context; case order from sibling jump table; no unresolved semantics known */
#include "common.h"
/* localdecomp:start func_L01_004C99F8 */
typedef int Q_004C99F8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x76]; s16 h76; u8 pad78[0x20]; s16 h98; u8 pad9A[4]; s16 h9E; } S_004C99F8;
typedef struct { u8 pad0[0x140]; f32 f140, f144, f148; u8 pad14C[4]; u8 q150[16]; u8 mat160[1]; } W_004C99F8;
typedef struct { u8 pad0[0xF0]; u8 qF0[16]; } Obj_004C99F8;
extern S_004C99F8 D_001CCFD0;
extern W_004C99F8 D_L01_001E2880;
extern s16 D_001E1100_sda;
extern s16 D_L01_001E1100[];
extern s16 D_L01_001E1102[];
extern s16 D_L01_001E110E[];
extern s16 D_L01_001E1136[];
extern f32 D_L01_001E1104[];
extern f32 D_L01_001E7630[];
extern u8 D_L01_001E110D[];
extern u8 D_L01_001E1134[];
extern u8 D_L01_001E1135[];
extern u8 *D_L01_001E1130[];
extern s16 D_001A4DC0[];
extern s32 D_001DAFE4_sda, D_001DAFE8_sda, D_001DB004_sda, D_001DB008_sda, D_001DB00C_sda, D_001DB010_sda, D_001D8188_sda;
extern u8 D_001425C0[];
void func_L01_004C99F8(void) {
    extern s32 func_0038CB00(void *);
    extern void func_0038D278(void *);
    extern f32 func_0038D0B0(f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_003873C0(void);
    extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
    extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
    extern s32 func_003A1798(void);
    extern void func_L01_00404AD8(void *, void *);
    extern void func_L01_00418C90(s32, s32);
    extern void func_L01_00419318(s32);
    extern void func_L01_0044CD60(s32);
    extern void func_L01_004B14C8(s32);
    extern void func_L01_004C99A0(void);
    extern void func_L01_004CA088(u8 *);
    extern u8 *func_L01_004CA270(u8 *);
    extern void func_L01_004CA478(u8 *);
    extern void func_L01_004CA3F0(void);
    extern void func_L01_004CA6A8(void);
    extern void func_L01_004CB388(u8 *, s32, s32);
    u8 *obj;
    s32 v, n;
    f32 t, c;
    switch (D_L01_001E1100[0]) {
    case 0:
        if (func_0038CB00(D_L01_001E1102)) {
            s32 ready = D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58;
            if (D_001DAFE4_sda && !ready) {
                v = D_001DAFE8_sda;
                D_001DAFE8_sda = v + 1;
                if (v < 16) goto idle;
            }
            if (ready && D_001DAFE4_sda) {
                func_003A1798();
                D_001DAFE4_sda = 0;
            }
            D_L01_001E2880.f144 = 25.0f;
            D_L01_001E2880.f148 = 900.0f;
            D_001DAFE8_sda = 0;
            D_L01_001E2880.f140 = 25.0f;
            func_0038D278(D_L01_001E2880.mat160);
            v = D_001DB008_sda;
            obj = D_L01_001E1130[0];
            D_L01_001E1100[0] = 1;
            *(f32 *)&D_L01_001E2880.q150[0] = 0.0f;
            *(f32 *)&D_L01_001E2880.q150[8] = 0.0f;
            *(f32 *)&D_L01_001E2880.q150[4] = 0.0f;
            D_L01_001E110E[0] = 0;
            D_L01_001E1102[0] = (v * 5 + 2) / 6;
            *(Q_004C99F8 *)(obj + 0xF0) = *(Q_004C99F8 *)D_L01_001E2880.q150;
            if (D_L01_001E1135[0]) *(f32 *)(obj + 0xF4) = func_0038DAB8(*(f32 *)(obj + 0xF4), -1.5707963705062866f);
            c = 0.5550146698951721f;
            t = func_0038D0B0(c);
            t = t / func_0038D098(c);
            D_L01_001E7630[0] = t;
            func_003873C0();
            *(u16 *)(obj + 0x34) &= 0xFFBE;
            return;
        }
    idle:
        func_L01_00404AD8(func_L01_004CA3F0, 0);
        return;
    case 1:
        func_L01_004CA088(D_L01_001E1130[0]);
        if (!func_0038CB00(D_L01_001E1102)) return;
        v = D_001DB00C_sda;
        D_L01_001E1100[0] = 2;
        D_L01_001E1134[0] = 0;
        D_L01_001E1102[0] = (v * 5 + 2) / 6;
        D_L01_001E1104[0] = 1.0f / (f32)D_L01_001E1102[0];
        return;
    case 2:
        obj = D_L01_001E1130[0];
        func_L01_004CA088(obj);
        func_L01_004CA478(obj);
        if (!func_0038CB00(D_L01_001E1102)) return;
        D_L01_001E1102[0] = 2;
        D_L01_001E1100[0] = 3;
        D_L01_001E1136[0] = 0x80;
        func_L01_00404AD8(func_L01_004CA6A8, 0);
        return;
    case 3:
        obj = D_L01_001E1130[0];
        func_L01_00404AD8(func_L01_004CA6A8, 0);
        if (!func_0038CB00(D_L01_001E1102)) return;
        D_L01_001E1100[0] = 4;
        D_L01_001E1102[0] = 10;
        obj = func_L01_004CA270(obj);
        n = D_L01_001E1108;
        D_L01_001E1130[0] = obj;
        func_L01_004CB388(obj, n, D_L01_002C5600[D_001425C0[n]].b + 1);
        return;
    case 4:
        if (D_L01_001E1130[0]) func_L01_004CA088(D_L01_001E1130[0]);
        func_L01_00404AD8(func_L01_004CA6A8, 0);
        D_L01_001E1136[0] = (s32)((f32)D_L01_001E1102[0] / 12.0f * 128.0f);
        if (!func_0038CB00(D_L01_001E1102)) return;
        v = D_001DB010_sda;
        D_L01_001E1136[0] = 0;
        D_L01_001E1100[0] = 5;
        D_L01_001E1102[0] = (v * 5 + 2) / 6;
        return;
    case 5:
        if (D_L01_001E1130[0]) func_L01_004CA088(D_L01_001E1130[0]);
        if (!func_0038CB00(D_L01_001E1102)) return;
        D_L01_001E1102[0] = 2;
        D_001E1100_sda = 6;
        return;
    case 6:
        if (D_L01_001E1130[0]) func_L01_004CA088(D_L01_001E1130[0]);
        func_L01_00404AD8(func_L01_004CA3F0, 0);
        if (!func_0038CB00(D_L01_001E1102)) return;
        v = D_001DB004_sda;
        D_L01_001E110D[0] = 1;
        D_L01_001E110E[0] = 1;
        D_L01_001E1102[0] = 0;
        n = (v * 5 + 2) / 6;
        D_L01_001E1104[0] = 1.0f / (f32)n;
        D_001A4DC0[0] = ((v + 5) * 5 + 2) / 6;
        func_L01_004C99A0();
        v = D_L01_001E1108;
        D_L01_001E1130[0] = 0;
        func_L01_00418C90(v, 0);
        if ((u16)(D_001CCFD0.h76 - 6) >= 2) D_001CCFD0.h76 = 5;
        if ((u16)(D_001CCFD0.h9E - 6) >= 2) D_001CCFD0.h9E = 5;
        func_L01_00419318(D_L01_001E1108);
        func_L01_0044CD60(D_L01_001E1108);
        D_001E1100_sda = 7;
        return;
    case 7:
        v = D_001DB004_sda;
        n = D_L01_001E1102[0];
        D_L01_001E1102[0] = n + 1;
        if ((s16)n < (v * 5 + 2) / 6) {
            func_L01_00404AD8(func_L01_004CA3F0, 0);
            return;
        }
        func_003A0EC0(0, 2, 0, 0, 0);
        func_00382810(0, 0, 3, 1.1100293397903442f, 0.0049999998882412910f, 0.20000000298023224f, 0.0f);
        D_001D8188_sda = 0xE0;
        func_L01_004B14C8(1);
        return;
    default:
        return;
    }
}
/* localdecomp:end func_L01_004C99F8 */
