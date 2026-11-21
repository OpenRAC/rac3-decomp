#include "common.h"

/* NTSC-U counterpart of func_L07_003C0710 (src/levels/07_annihilation_nation/L07_003C0710.c) */
/* localdecomp:start func_L07_003BEDC0 */
typedef struct { u8 kind; u8 pad[35]; } Entry_003C0710;
extern Entry_003C0710 D_L07_002BC920_003BEDC0[];
extern s32 D_L07_002D3270 __attribute__((section(".data")));
extern u8 *D_001D52FC;
extern s32 D_L07_001D6694_003BEDC0;
extern u8 D_L07_001D6678_003BEDC0[4];
extern s32 D_L07_001F2140_003BEDC0 __attribute__((section(".data")));
extern char *D_L07_001DF41C_003BEDC0;
__asm__(".extern D_L07_001DF41C_003BEDC0, 16");
extern char *D_L07_001DF500_003BEDC0;
__asm__(".extern D_L07_001DF500_003BEDC0, 16");
extern s16 D_001A4DBC __attribute__((section(".data")));
extern f32 D_L07_001DED50_003BEDC0;
extern s32 D_00142C30[];
extern s32 D_L07_001DE5A0_003BEDC0;
__asm__(".extern D_L07_001DE5A0_003BEDC0, 4");
extern s32 D_L07_001DE5B0_003BEDC0;
__asm__(".extern D_L07_001DE5B0_003BEDC0, 4");
extern s32 func_L01_004B6C68(void);
extern void func_L07_003BF298(u8 *);
extern void func_L07_003BFAF8(u8 *);
extern s32 func_L07_003C0408(u8 *);
extern s32 func_L01_0044F2E8(s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003C0478(s32);
extern void func_003A2F98(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004759A8(s32);
extern void func_L01_00477B88(void);
extern void func_L01_004780F8(void);
extern s32 func_003883C8(void *);
extern void func_0039BEC0(s32, s32, s32, s32, s32);
extern void func_L01_004282C0(s32, s32);
extern s32 func_L04_003782E0(void *);
extern void func_L07_003BF7E8();
extern s32 func_L07_00334128(void *);
extern void func_L01_00441FB8(s32, s32, s32);
extern u8 func_L07_003BFAE0(s32);
extern void func_L07_003BF588(u8 *, s32);
extern void func_L01_00402768(void *, void *);
extern void func_L07_003C0568(void);
extern void func_L01_00452F40(char *, s32);
extern void func_L01_0045BE58(s32, s32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9588(s32, void *, void *, s32, s32, s32);
extern void func_L07_003BF5F0(u8 *);
void func_L07_003BEDC0(u8 *obj) {
    u8 *p;
    s32 r;
    char *q;
    s32 busy;
    if (func_L01_004B6C68()) return;
    if (obj[0x20] == 0) func_L07_003BF298(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        func_L07_003BFAF8(obj);
        if (func_L07_003C0408(obj)) {
            func_L01_0044F2E8(0, 12, 3144, 1, 0, 0, 0);
            if (D_L07_002D3270 == 12 && (*(s32 *)(D_001D52FC + 0x1A4) & 16)) {
                func_L07_003C0478((s32)obj);
                func_003A2F98(D_001D52FC);
            }
        }
        break;
    case 2:
        busy = D_L07_001D6694_003BEDC0;
        (*(u16 *)(obj + 0x96))++;
        if (busy == 0 && *(u16 *)(obj + 0x96) >= 2) func_L07_003C0478((s32)obj);
        break;
    case 3:
        func_L01_0044F2E8(0, 5, 0, 1, 0, 0, 0);
        if (func_L01_00452EC8(obj)) {
            D_L07_001D6678_003BEDC0[3] = 1;
            *(s16 *)(p + 0x34) = 55;
        }
        ((s32 (*)(void))func_L01_004759A8)();
        func_L01_00477B88();
        func_L01_004780F8();
        if (func_003883C8(p + 0x34)) {
            D_L07_001D6678_003BEDC0[3] = 0;
            func_0039BEC0(3, 1, 17, 0, 0);
        }
        break;
    case 4:
        break;
    case 5:
        if (D_L07_001F2140_003BEDC0) func_L01_004282C0(0, 0);
        if (func_L04_003782E0(D_L07_001DF41C_003BEDC0 + (*(s32 *)p << 8)) == 0)
            func_L07_003BF7E8(obj, p[0x38]);
        break;
    case 6:
        r = func_L07_00334128(D_L07_001DF41C_003BEDC0 + (*(s32 *)(p + 4) << 8));
        if (r == 4) break;
        if (r == 0) {
            func_L07_003BF7E8(obj, p[0x38]);
        } else {
            if (r == 1) *(s32 *)(p + 0x30) = -2;
            else if (r == 2 && p[0x38] == 19) *(s32 *)(p + 0x30) = -3;
            func_L01_00441FB8((s32)obj, 7, -1);
        }
        break;
    case 7:
        if (func_L01_00452EC8(obj)) {
            *(s16 *)(p + 0x34) = 0;
            *(s16 *)(p + 0x36) = 240;
        }
        D_001A4DBC = 5;
        if (func_003883C8(p + 0x36)) {
            if (!func_L07_003BFAE0(p[0x38]) || D_L07_002D3270 != 0) {
                *(s16 *)(p + 0x34) = 0;
            } else if (++*(s16 *)(p + 0x34) >= 10) func_L07_003BF588(obj, p[0x38]);
        } else func_L01_00402768(func_L07_003C0568, obj);
        break;
    case 8:
        D_001A4DBC = 5;
        if (D_L07_001DED50_003BEDC0 < 1.0f) D_L07_001DED50_003BEDC0 += 0.03f;
        else {
            D_L07_001DED50_003BEDC0 = 1.0f;
            if (D_L07_002BC920_003BEDC0[p[0x38]].kind == 0)
                func_L01_00452F40(D_L07_001DF41C_003BEDC0 + (*(s32 *)(p + 4) << 8), 1);
            if (D_L07_001F2140_003BEDC0 != 1) func_L01_004282C0(1, 0);
            func_L01_0045BE58(*(s32 *)(p + 0x1C), -1);
            if (*(void **)(p + 0x2C)) {
                q = D_L07_001DF500_003BEDC0 + (*(s32 *)(p + 0x18) << 7);
                func_L01_004F12C0(q + 0x30, q + 0x70, 116, 1);
                (*(void (**)(u8 *))(p + 0x2C))(obj);
                *(void **)(p + 0x2C) = 0;
                func_L01_00441FB8((s32)obj, 1, -1);
            } else {
                func_L01_004F12C0(obj + 0x10, obj + 0xF0, 116, 1);
                func_L01_003E9588(0, &D_L07_001DE5A0_003BEDC0, &D_L07_001DE5B0_003BEDC0, 0, 0, 0);
                func_L01_00441FB8((s32)obj, 9, -1);
            }
        }
        break;
    case 9:
        if (D_L07_001DED50_003BEDC0 <= 0.0f) {
            D_L07_001DED50_003BEDC0 = 0.0f;
            func_0039BEC0(3, 1, 17, 0, 0);
        } else D_L07_001DED50_003BEDC0 -= 0.1f;
        break;
    case 10:
        if ((D_00142C30[0] & 0x10000) && !func_L01_004B6C68()) {
            p[0x38] = 0;
            func_L07_003BF5F0(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003BEDC0 */
