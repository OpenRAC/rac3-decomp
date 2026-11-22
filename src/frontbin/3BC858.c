#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern s32 D_001D9D1C;
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_12C908(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
extern s32 func_003BD4B8();
extern void func_003BC858(void);


typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BC858;
extern s32 D_001D99A4;
extern s32 D_001D4BC4;
extern s32 D_001D9BC8;
extern f32 D_001D8CF0;
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389370(void);
extern void func_0038AE20(s32, s32, s32, s32);
/* localdecomp:start func_003BC858 */
/* func_003BC858 log: the boot_elf twin func_003BCC10's C, callees renamed through the pairs table. */
__asm__(".extern D_001D8CF0, 4");
void func_003BC858(void) {
    f32 rotation, y, size;
    if ((D_142430_003BC858.f15C == 15 || D_142430_003BC858.f15C == 16) ||
        D_142430_003BC858.f164 == 15 || D_001D99A4 != 0) {
        size = 272.0f;
        func_00389240(1);
        func_003A9440(0x42, 0x8000000044UL);
        func_003A9440(0x47, 0x3004B);
        func_0038B4D0(0x2C, D_001D4BC4 - 96, 64, 64, 0, 0, 64, 64, 0x80808080UL, func_00389598(3));
        rotation = (f32)(D_001D9BC8 % 55) * -6.2831855f / 55.0f;
        y = (f32)((D_001D4BC4 - 64) << 4);
        func_00397638(1216.0f, y, size, size, rotation, 64, 64, func_00389598(4));
        func_00389370();
        if ((D_142430_003BC858.f15C == 15 || D_142430_003BC858.f15C == 16) ||
            D_142430_003BC858.f164 == 15) {
            D_001D99A4 = 25;
        } else {
            D_001D99A4--;
        }
    }
    func_003A9440(0x42, 0x8000000044UL);
    func_0038AE20(0, 0, 0, (s32)(D_001D8CF0 * 128.0f));
}
/* localdecomp:end func_003BC858 */

typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCA48;
extern s32 (*D_001D8CB8)();
extern s32 D_001D8CD4;
extern void (*D_001D8CBC)(s32);
extern s32 D_001D5B94;
extern s32 D_001D9D00;
extern void func_003CD058();
extern void func_003CD350();
/* localdecomp:start func_003BCA48 */
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c_003BCA48;
extern S_16C580c_003BCA48 D_16C580_003BCE00;
__asm__(".extern D_001D8CB8_003BCA48, 4");
__asm__(".extern D_001D8CD4_003BCA48, 4");
__asm__(".extern D_001D8CBC_003BCA48, 4");
extern s32 (*D_001D8CB8_003BCA48)();
extern s32 D_001D8CD4_003BCA48;
extern void (*D_001D8CBC_003BCA48)(s32);
extern s32 D_001D5B94_003BCA48;
extern s32 D_001D9D00_003BCA48;
extern void func_003CD058_003BCA48();
extern void func_003CD350_003BCA48();
s32 func_003BCA48(s32 a) {
    s32 r;
    D_001D5B94_003BCA48 = 6;
    D_16C580_003BCE00.f22++;
    r = D_001D8CB8_003BCA48(a);
    if (D_001D8CD4_003BCA48 & 4) { func_003CD058_003BCA48(); }
    if (D_001D8CD4_003BCA48 & 0x10) { func_003CD350_003BCA48(); }
    if (D_001D8CBC_003BCA48 != 0) { D_001D8CBC_003BCA48(a); }
    D_001D9D00_003BCA48++;
    return r;
}
/* localdecomp:end func_003BCA48 */

extern s32 D_001D9348;
extern s32 D_001D9364;
extern s32 D_001D9C10;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001A1ED0_3B7618[];
extern u8 D_00100AE0[];
extern u8 D_002FDC00[];
extern void func_003A9440(s32, unsigned long);
extern void func_003873C0();
extern void func_003861F0();
extern void func_003CF0F0();
extern void func_003A9C70(s32);
extern void func_003A96D8();
extern void func_00389240(s32);
extern void func_00389E28();
extern void func_00389370();
extern void func_003A9678();
extern void func_003C3860();
extern void func_00389DB0();
extern void func_11F0A0(s32);
extern void func_003CD3D8();
extern void func_003A8F90();
extern void func_003A92F0(s32);
extern void func_003D0180();
extern void func_003CF050();
extern void func_003C31B0();
extern void func_00389F68();
extern void func_003864C0(s32);
extern void func_003D85C0_003BCAF8(s32);
extern void func_003D8640();
extern void func_003D9260_003BCAF8(s32);
/* localdecomp:start func_003BCAF8 */
__asm__(".extern D_001D8CD4, 4");
extern s32 D_001D9348;
extern s32 D_001D9364;
extern s32 D_001D9C10;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001A1ED0_3B7618[];
extern u8 D_00100AE0[];
extern u8 D_002FDC00[];
extern void func_003A9440(s32, unsigned long);
extern void func_003BCD50();
extern void func_003873C0();
extern void func_003861F0();
extern void func_003CF0F0();
extern void func_003A9C70(s32);
extern void func_003A96D8();
extern void func_00389240(s32);
extern void func_00389E28();
extern void func_00389370();
extern void func_003A9678();
extern void func_003C3860();
extern void func_00389DB0();
extern void func_11F0A0(s32);
extern void func_003CD3D8();
extern void func_003A8F90();
extern void func_003A92F0(s32);
extern void func_003D0180();
extern void func_003CF050();
extern void func_003C31B0();
extern void func_00389F68();
extern void func_003864C0(s32);
extern void func_003D85C0_003BCAF8(s32);
extern void func_003D8640();
extern void func_003D9260_003BCAF8(s32);
void func_003BCAF8(void) {
    D_001D9348 = 0;
    func_003873C0();
    func_003861F0();
    if (D_001D8CD4 & 1) func_003BCD50();
    if (D_001D8CD4 & 2) {
        func_003CF0F0();
        func_003A9C70(0x2010000);
    }
    if (D_001D9C10) {
        func_003A96D8();
        func_00389240(1);
        func_00389E28();
        func_00389370();
        func_003A9678();
    }
    if (D_001D8CD4 & 0xC) {
        func_003C3860();
        func_003A9C70(0x2080000);
    }
    func_00389240(1);
    if (D_001D9C08) func_00389DB0();
    func_003A96D8();
    func_003A9440(8, 5);
    func_003A9440(0x47, 0x53001);
    func_11F0A0(0);
    func_003CD3D8();
    D_001D9D1C = 9;
    func_003A9440(0x47, 0x5360B);
    func_003A8F90(D_00100AE0);
    func_11F0A0(0);
    if (D_001D8CD4 & 2) {
        func_003A92F0(2);
        func_003D0180(D_002FDC00);
        func_003CF050();
    }
    if (D_001D8CD4 & 0xC) {
        func_003A92F0(0x10);
        func_003C31B0();
    }
    func_00389370();
    if (D_001D9C0C) {
        func_00389240(1);
        func_003A9440(0x4E, (D_001A1ED0_3B7618[2] >> 13) | 0x31000000 | 0x100000000UL);
        func_003A96D8();
        func_00389F68();
        func_003A9440(0x4E, 0x31000000 | (D_001A1ED0_3B7618[2] >> 13));
        func_00389370();
    }
    func_003864C0(0);
    if (D_001D9348) {
        func_003D85C0_003BCAF8(0);
        func_003D8640();
    }
    if (D_001D9364) {
        func_003D9260_003BCAF8(0);
        D_001D9364 = 0;
    }
}
/* localdecomp:end func_003BCAF8 */

/* localdecomp:start func_003BCD50 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_003BCD50(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003BCD50 */

typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D5B94;
extern s32 D_001D9D2C;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001D9D04;
extern u8 D_00227480[];
extern S_2276C0_3B78C8 D_00227640;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_0038CB78();
extern void func_003C2D88();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_13CF40(s32);
extern void func_003A2750(s32);
extern void func_0038A238(s32);
extern void func_0039A150(void);
extern void func_13CDF0(s32);
extern void func_003A9AD0(void);
/* localdecomp:start func_003BCDA8 */
/* func_003BCDA8 (PAL, boot_elf). Based on the US draft of rac3-uya-decomp func_003BD088,
   commit 13cf5c5, names moved to PAL addresses where known. Matches with the source
   file's own flags; the only PAL difference from the US draft was the argument of
   func_0038A238_003BCDA8 (5 here, 6 in the US). */


typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8_003BCDA8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8_003BCDA8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8_003BCDA8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8_003BCDA8;
extern s32 D_001D5B94_003BCDA8;
extern s32 D_001D9D2C_003BCDA8;
extern s32 D_001D4CEC_003BCDA8;
extern s32 D_001D545C_003BCDA8;
extern s32 D_001D9D04_003BCDA8;
extern u8 D_00227480_003BCDA8[];
extern S_2276C0_3B78C8_003BCDA8 D_00227640_003BCDA8;
extern S_1A30B0_3B78C8_003BCDA8 D_1A30B0_003BCDA8;
extern S_142430_3B78C8_003BCDA8 D_142430_003BCDA8;
extern S_1CCFD0_3B78C8_003BCDA8 D_1CCFD0_003BCDA8;
extern void func_0038CB78_003BCDA8();
extern void func_003C2D88_003BCDA8();
extern void func_11F0A0_003BCDA8();
extern void func_13CF80_003BCDA8(s32, s32, s32, s32, s32);
extern void func_13CA28_003BCDA8(void);
extern void func_003A5430_003BCDA8(void);
extern void func_003A1C28_003BCDA8(void);
extern void func_13BF00_003BCDA8(s32);
extern void func_13BED0_003BCDA8(void);
extern void func_0039C410_003BCDA8(void);
extern void func_0039ADE0_003BCDA8(void);
extern s32 func_13CF40_003BCDA8(s32);
extern void func_003A2750_003BCDA8(s32);
extern void func_0038A238_003BCDA8(s32);
extern void func_0039A150_003BCDA8(void);
extern void func_13CDF0_003BCDA8(s32);
extern void func_003A9AD0_003BCDA8(void);
void func_003BCDA8(void) {
    s32 i;
    func_0038CB78_003BCDA8(D_00227480_003BCDA8, -1, 0x80);
    D_00227640_003BCDA8.f10 |= 0x80000000;
    D_001D5B94_003BCDA8 = 6;
    func_003C2D88_003BCDA8();
    func_11F0A0_003BCDA8(0);
    func_13CF80_003BCDA8(2, 0, 0, 0, 0);
    func_13CA28_003BCDA8();
    func_13B620();
    func_003A5430_003BCDA8();
    func_003A1C28_003BCDA8();
    D_1CCFD0_003BCDA8.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0_003BCDA8.f90[i] != 0) {
            func_13BF00_003BCDA8(D_1A30B0_003BCDA8.f90[i]);
            func_13BED0_003BCDA8();
            D_001D9D2C_003BCDA8 = 0;
            D_1A30B0_003BCDA8.f90[i] = 0;
        }
    }
    while (D_142430_003BCDA8.f15C >= 3 || D_142430_003BCDA8.f164 >= 0) {
        func_0039C410_003BCDA8();
        func_0039ADE0_003BCDA8();
    }
    if (D_142430_003BCDA8.f17C != 0) D_142430_003BCDA8.f17C = 0;
    if (D_142430_003BCDA8.f18 >= 0) D_142430_003BCDA8.f18 = -1;
    D_001D4CEC_003BCDA8 &= ~0x200;
    func_13CF40_003BCDA8(0);
    D_1CCFD0_003BCDA8.f7 = 0;
    func_003A2750_003BCDA8(1);
    do {} while (((s32 (*)(void))func_13B620)());
    D_1CCFD0_003BCDA8.f7 = 1;
    func_0038A238_003BCDA8(5);
    D_001D545C_003BCDA8 = D_001D9D04_003BCDA8;
    func_0039A150_003BCDA8();
    func_13CDF0_003BCDA8(0);
    D_1CCFD0_003BCDA8.f7 = 0;
    func_003A9AD0_003BCDA8();
}
/* localdecomp:end func_003BCDA8 */

extern u8 D_001D5571;
s32 func_003A7618_003BCF80(s32);
extern s32 D_001D9D04;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];
/* localdecomp:start func_003BCF80 */
extern u8 D_001D5571_003BCF80;
s32 func_003A7618_003BCF80(s32);                         /* extern */
extern s32 D_001D9D04_003BCF80;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0_003BCF80;
extern S_001CCFD0_003B7AA0_003B7AA0_003BCF80 D_001CCFD0_003BCF80[];

void func_003BCF80(void) {
    if (D_001D9D04_003BCF80 == 1) {
        if (D_001D5571_003BCF80 == 0) {
            D_001CCFD0_003BCF80->f7 = 0;
            if ((func_003A7618_003BCF80(1) == 0) && (func_003A7618_003BCF80(2) == 0) && (func_003A7618_003BCF80(3) == 0) && (func_003A7618_003BCF80(4) == 0) && (func_003A7618_003BCF80(5) == 0)) {
                func_003A7618_003BCF80(6);
            }
            D_001CCFD0_003BCF80->f7 = 1;
        }
    }
}
/* localdecomp:end func_003BCF80 */

/* localdecomp:start func_003BD030 */
/* func_003BD030: scene/mode switch, the frontbin twin of boot_elf func_003BD3E8. */
#include "vu0.h"
typedef struct { s16 from, to; s32 row, arg0, arg1; } Rule_003BD030;
typedef struct {
    s32 value;
    void (*init)(s32, s32);
    s32 (*step)();
    void (*event)(s32);
    void (*render)(void);
    void (*finish)(void);
} Callbacks_003BD030;
typedef struct {
    u8 pad0[0x20]; s16 mode; s16 index;
    u8 pad24[8]; s16 zero; s16 value;
    u8 pad30[0x34]; s32 slot;
} State_003BD030;
typedef struct {
    u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C;
    u8 p240[0x10]; s32 f250; s32 f254; s32 f258;
} Display_003BD030;
extern u8 D_00227480[];
extern S_2276C0_3B78C8 D_00227640;
extern s32 D_001D5B94;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];
extern S_1A30B0_3B78C8 D_1A30B0;
extern s32 D_001D9D2C;
extern s32 D_001D545C;
extern s32 D_001D9D04;
extern State_003BD030 D_16C580;
extern s32 D_001D6E90;
extern s32 D_001D8CE8, D_001D8CEC;
extern Rule_003BD030 D_0037FCB8[];
extern s32 D_001D8CC8, D_001D8CCC;
extern Callbacks_003BD030 D_0037FBE0[];
extern void (*D_001D8CB4)(s32, s32);
extern s32 (*D_001D8CB8)();
extern void (*D_001D8CBC)(s32);
extern void (*D_001D8CC0)(void);
extern void (*D_001D8CC4)(void);
extern Display_003BD030 D_00225900;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern vu0_v4 D_00222650;
extern s32 D_001D4B4C;
extern s32 D_001D4B48;
extern u8 D_002D2100[];
extern void func_0038CB78();
extern void func_003C2D88(void);
extern void func_11F0A0(s32);
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_003A5430(void);
extern void func_003A1C28(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003BCAF8(void);
extern void func_00392260(s32, s32, s32);
extern void func_13D310(s32, u8 *);
extern void func_003BE0C0();
extern void func_003BCF80(void);
__asm__(".extern D_001D8CE8, 4");
__asm__(".extern D_001D8CEC, 4");
__asm__(".extern D_001D8CC8, 4");
__asm__(".extern D_001D8CCC, 4");
__asm__(".extern D_001D8CB4, 4");
__asm__(".extern D_001D8CB8, 4");
__asm__(".extern D_001D8CBC, 4");
__asm__(".extern D_001D8CC0, 4");
__asm__(".extern D_001D8CC4, 4");
__asm__(".extern D_001D9C4C, 16");
s32 func_003BD030(void) {
    Rule_003BD030 *rule;
    Callbacks_003BD030 *cb;
    Display_003BD030 *disp;
    s32 i, from, to, row;

    func_0038CB78(D_00227480, -1, 0x80);
    D_001D5B94 = 6;
    D_00227640.f10 |= 0x80000000;
    func_003C2D88();
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620();
    func_003A5430();
    func_003A1C28();
    D_001CCFD0[0].f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0.f90[i] != 0) {
            func_13BF00(D_1A30B0.f90[i]);
            func_13BED0();
            D_001D9D2C = 0;
            D_1A30B0.f90[i] = 0;
        }
    }
    from = D_001D545C;
    to = D_001D9D04;
    D_16C580.mode = 2;
    D_16C580.value = -1;
    D_16C580.index = -1;
    D_16C580.zero = 0;
    D_16C580.slot = -1;
    D_001D6E90 = 0;
    D_001D8CE8 = from;
    D_001D8CEC = to;
    rule = D_0037FCB8;
    i = 0;
    do {
        if (rule->from == -1 && rule->to == to) break;
        if (rule->from == from && (rule->to == -1 || rule->to == to)) break;
        i++;
        rule++;
    } while (i < 51);
    row = 8;
    D_001D8CCC = 0;
    D_001D8CC8 = 0;
    if (i < 51) {
        D_001D8CCC = rule->arg1;
        D_001D8CC8 = rule->arg0;
        row = rule->row;
    }
    cb = &D_0037FBE0[row];
    D_001D8CC0 = func_003BCAF8;
    D_001D8CB4 = 0;
    D_001D8CB8 = 0;
    D_001D8CBC = 0;
    D_001D8CC4 = 0;
    if (cb->init) D_001D8CB4 = cb->init;
    if (cb->step) D_001D8CB8 = cb->step;
    if (cb->event) D_001D8CBC = cb->event;
    if (cb->render) D_001D8CC0 = cb->render;
    if (cb->finish) D_001D8CC4 = cb->finish;
    disp = &D_00225900;
    disp->f258 = 16;
    disp->f250 = 0;
    disp->f254 = 0;
    disp->f228 = 0;
    disp->f22C = 524288.0f;
    disp->f238 = 255.0f;
    disp->f23C = 128.0f;
    {
        s32 value = cb->value;
        D_16C580.value = value;
    }
    D_001D9C44 = disp->f250;
    D_001D9C45 = disp->f254;
    D_001D9C46 = disp->f258;
    D_001D9C48 = disp->f228;
    D_001D9C4C = disp->f22C;
    D_001D9C50 = disp->f238;
    D_001D9C54 = disp->f23C;
    func_00392260(0, 0, 0);
    D_00227640.f10 |= 0x80000000;
    qzero(&D_00222650);
    D_00222650.z = -1.0f;
    D_001D4B4C = 1;
    D_001D545C = D_001D9D04;
    D_001D4B48 = 0;
    func_13D310(D_001D9D04, D_002D2100);
    func_003BE0C0();
    func_003BCF80();
    if (D_001D8CB4) D_001D8CB4(D_001D8CC8, D_001D8CCC);
    return 1;
}
/* localdecomp:end func_003BD030 */

typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7EB0;
typedef struct { u8 p0[7]; u8 f7; } S_1CCFD0_3B7EB0;
extern u8 D_001D8CD1;
extern s32 D_001DA1F0;
extern void (*D_001D8CC4)(void);
extern S_142430_3B7EB0 D_142430_003BD390;
extern S_1CCFD0_3B7EB0 D_1CCFD0_003BD390;
extern void func_11F0A0();
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern s32 func_0039A1E0(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003A9AD0(void);
extern void func_00387EF0(void);
/* localdecomp:start func_003BD390 */
__asm__(".extern D_001D8CD1, 1");
__asm__(".extern D_001DA1F0, 4");
__asm__(".extern D_001D8CC4, 4");
extern s32 D_001D4B48;
void func_003BD390(void) {
    s32 r;
    (&D_001D4B48)[1] = 0;
    if (D_001D8CD1 == 0) {
        do {
            func_11F0A0(0);
            func_12C908(0);
            func_0039C410();
            func_0039ADE0();
            r = D_001D8CD1 = func_0039A1E0() != 0;
        } while (r == 0);
    }
    while (D_142430_003BD390.f15C != 2 || D_142430_003BD390.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C410();
        func_0039ADE0();
    }
    if (D_001DA1F0 != 0) func_13BF00(D_001DA1F0);
    do {} while (func_13B620());
    func_13BED0();
    func_13CF40(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    { S_1CCFD0_3B7EB0 *c = &D_1CCFD0_003BD390; c->f7 = 0; }
    func_003A9AD0();
    if (D_001D8CC4 != 0) D_001D8CC4();
    func_00387EF0();
}
/* localdecomp:end func_003BD390 */

extern u8 D_001D5BDC;
extern s32 D_001D9D04;
extern u8 D_001D8CD0;
extern u8 D_001D8CD1;
extern s32 D_001D9D54;
extern s32 D_001D9BC8;
extern s32 D_001D6E90;
extern s32 D_001D4B48;
extern u8 D_001D8CF4;
extern f32 D_001D8CF0;
extern void func_0039EC28(s32, s32);
extern void func_003BCDA8(void);
extern s32 func_003BD030(void);
extern void func_00387EF0(void);
extern void func_003A3B70(void);
extern s32 func_003BCA48(s32);
extern void func_00387218(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern s32 func_0039A1E0(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_003BE200(void);
extern void func_00392748(s32);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_0038A238(s32);
extern void func_003BD390(void);
/* localdecomp:start func_003BD4B8 */
__asm__(".extern D_001D8CD0_003BD4B8, 1");
__asm__(".extern D_001D8CD1_003BD4B8, 1");
__asm__(".extern D_001D9D54_003BD4B8, 4");
__asm__(".extern D_001D8CF4_003BD4B8, 1");
__asm__(".extern D_001D8CF0_003BD4B8, 4");
extern u8 D_001D5BDC_003BD4B8;
extern s32 D_001D9D04_003BD4B8;
extern u8 D_001D8CD0_003BD4B8;
extern u8 D_001D8CD1_003BD4B8;
extern s32 D_001D9D54_003BD4B8;
extern s32 D_001D9BC8_003BD4B8;
extern s32 D_001D6E90_003BD4B8;
extern s32 D_001D4B48_003BD4B8;
extern u8 D_001D8CF4_003BD4B8;
extern f32 D_001D8CF0_003BD4B8;
extern void func_0039EC28_003BD4B8(s32, s32);
extern void func_003BCDA8_003BD4B8(void);
extern void func_003BD030_003BD4B8(void);
extern void func_00387EF0_003BD4B8(void);
extern void func_003A3B70_003BD4B8(void);
extern s32 func_003BCA48_003BD4B8(s32);
extern void func_00387218_003BD4B8(void);
extern void func_003BC800_003BD4B8(void);
extern void func_0039C410_003BD4B8(void);
extern void func_0039ADE0_003BD4B8(void);
extern void func_003A92F0_003BD4B8(s32);
extern s32 func_0039A1E0_003BD4B8(void);
extern void func_003A91D0_003BD4B8(void);
extern void func_003A9150_003BD4B8(void);
extern void func_003923D0_003BD4B8(void);
extern void func_003BE200_003BD4B8(void);
extern void func_00392748_003BD4B8(s32);
extern void func_003922B8_003BD4B8(void);
extern void func_00392350_003BD4B8(s32);
extern void func_0038A238_003BD4B8(s32);
extern void func_003BD390_003BD4B8(void);
s32 func_003BD4B8(void) {
    s32 r;
    if (D_001D5BDC_003BD4B8 == 0) func_0039EC28_003BD4B8(0, D_001D9D04_003BD4B8);
    if (D_001D9D04_003BD4B8 < 0) {
        func_003BCDA8_003BD4B8();
        return 1;
    }
    r = 0;
    func_003BD030_003BD4B8();
    D_001D8CD0_003BD4B8 = 0;
    D_001D8CD1_003BD4B8 = 0;
    for (;;) {
        func_003A91D0_003BD4B8();
        func_003A9150_003BD4B8();
        func_003923D0_003BD4B8();
        if (D_001D8CF4_003BD4B8 != 0) func_003BE200_003BD4B8();
        else func_00392748_003BD4B8(1);
        func_003922B8_003BD4B8();
        func_00392350_003BD4B8(0);
        if (r != 0) break;
        func_00387EF0_003BD4B8();
        func_003A3B70_003BD4B8();
        r = func_003BCA48_003BD4B8(D_001D8CD0_003BD4B8);
        D_001D9D54_003BD4B8 = 0;
        func_00387218_003BD4B8();
        func_003BC800_003BD4B8();
        func_0039C410_003BD4B8();
        func_0039ADE0_003BD4B8();
        func_003A92F0_003BD4B8(1);
        func_12C908(0);
        D_001D9BC8_003BD4B8++;
        if (D_001D6E90_003BD4B8 == 0) D_001D8CD1_003BD4B8 = func_0039A1E0_003BD4B8() != 0;
        D_001D8CD0_003BD4B8 = D_001D4B48_003BD4B8 >= 2;
    }
    func_003A92F0_003BD4B8(1);
    func_12C908(0);
    if (D_001D8CF0_003BD4B8 > 0.0f) func_0038A238_003BD4B8(2);
    func_003BD390_003BD4B8();
    return 1;
}
/* localdecomp:end func_003BD4B8 */
