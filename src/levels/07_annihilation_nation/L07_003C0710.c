#include "common.h"

typedef struct { u8 pad0[0x68]; struct { u8 pad[4]; s32 idx; } *p68; } O_B;

/* localdecomp:start func_L07_003C0710 */
typedef struct { u8 kind; u8 pad[35]; } Entry_003C0710;
extern Entry_003C0710 D_L07_002BC920_003C0710[];
extern s32 D_L07_002D32B0 __attribute__((section(".data")));
extern u8 *D_001D52FC;
extern s32 D_L07_001D6694;
extern u8 D_L07_001D6678[4];
extern s32 D_L07_001F2140 __attribute__((section(".data")));
extern char *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern char *D_L07_001DF500;
__asm__(".extern D_L07_001DF500, 16");
extern s16 D_001A4DBC __attribute__((section(".data")));
extern f32 D_L07_001DED50;
extern s32 D_00142C30[];
extern s32 D_L07_001DE560;
__asm__(".extern D_L07_001DE560, 4");
extern s32 D_L07_001DE570;
__asm__(".extern D_L07_001DE570, 4");
extern s32 func_L01_004BA800(void);
extern void func_L07_003C0BE8(u8 *);
extern void func_L07_003C1448(u8 *);
extern s32 func_L07_003C1D58(u8 *);
extern s32 func_L01_00452560(s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003C1DC8(s32);
extern void func_003A2CD8(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00479200(s32);
extern void func_L01_0047B3D8(void);
extern void func_L01_0047B948(void);
extern s32 func_0038CB00(void *);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_L01_0042B068(s32, s32);
extern s32 func_L04_003796E0(void *);
extern void func_L07_003C1138();
extern s32 func_L07_00334868(void *);
extern void func_L01_004450F0(s32, s32, s32);
extern u8 func_L07_003C1430(s32);
extern void func_L07_003C0ED8(u8 *, s32);
extern void func_L01_00404AD8(void *, void *);
extern void func_L07_003C1EB8(void);
extern void func_L01_00456230(char *, s32);
extern void func_L01_0045F1E8(s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L07_003C0F40(u8 *);
void func_L07_003C0710(u8 *obj) {
    u8 *p;
    s32 r;
    char *q;
    s32 busy;
    if (func_L01_004BA800()) return;
    if (obj[0x20] == 0) func_L07_003C0BE8(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 1:
        func_L07_003C1448(obj);
        if (func_L07_003C1D58(obj)) {
            func_L01_00452560(0, 12, 3144, 1, 0, 0, 0);
            if (D_L07_002D32B0 == 12 && (*(s32 *)(D_001D52FC + 0x1A4) & 16)) {
                func_L07_003C1DC8((s32)obj);
                func_003A2CD8(D_001D52FC);
            }
        }
        break;
    case 2:
        busy = D_L07_001D6694;
        (*(u16 *)(obj + 0x96))++;
        if (busy == 0 && *(u16 *)(obj + 0x96) >= 2) func_L07_003C1DC8((s32)obj);
        break;
    case 3:
        func_L01_00452560(0, 5, 0, 1, 0, 0, 0);
        if (func_L01_004561B8(obj)) {
            D_L07_001D6678[3] = 1;
            *(s16 *)(p + 0x34) = 46;
        }
        ((s32 (*)(void))func_L01_00479200)();
        func_L01_0047B3D8();
        func_L01_0047B948();
        if (func_0038CB00(p + 0x34)) {
            D_L07_001D6678[3] = 0;
            func_003A0EC0(3, 1, 17, 0, 0);
        }
        break;
    case 4:
        break;
    case 5:
        if (D_L07_001F2140) func_L01_0042B068(0, 0);
        if (func_L04_003796E0(D_L07_001DF41C + (*(s32 *)p << 8)) == 0)
            func_L07_003C1138(obj, p[0x38]);
        break;
    case 6:
        r = func_L07_00334868(D_L07_001DF41C + (*(s32 *)(p + 4) << 8));
        if (r == 4) break;
        if (r == 0) {
            func_L07_003C1138(obj, p[0x38]);
        } else {
            if (r == 1) *(s32 *)(p + 0x30) = -2;
            else if (r == 2 && p[0x38] == 19) *(s32 *)(p + 0x30) = -3;
            func_L01_004450F0((s32)obj, 7, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(obj)) {
            *(s16 *)(p + 0x34) = 0;
            *(s16 *)(p + 0x36) = 200;
        }
        D_001A4DBC = 4;
        if (func_0038CB00(p + 0x36)) {
            if (!func_L07_003C1430(p[0x38]) || D_L07_002D32B0 != 0) {
                *(s16 *)(p + 0x34) = 0;
            } else if (++*(s16 *)(p + 0x34) >= 10) func_L07_003C0ED8(obj, p[0x38]);
        } else func_L01_00404AD8(func_L07_003C1EB8, obj);
        break;
    case 8:
        D_001A4DBC = 4;
        if (D_L07_001DED50 < 1.0f) D_L07_001DED50 += 0.036000002175569534f;
        else {
            D_L07_001DED50 = 1.0f;
            if (D_L07_002BC920_003C0710[p[0x38]].kind == 0)
                func_L01_00456230(D_L07_001DF41C + (*(s32 *)(p + 4) << 8), 1);
            if (D_L07_001F2140 != 1) func_L01_0042B068(1, 0);
            func_L01_0045F1E8(*(s32 *)(p + 0x1C), -1);
            if (*(void **)(p + 0x2C)) {
                q = D_L07_001DF500 + (*(s32 *)(p + 0x18) << 7);
                func_L01_004F50C8(q + 0x30, q + 0x70, 116, 1);
                (*(void (**)(u8 *))(p + 0x2C))(obj);
                *(void **)(p + 0x2C) = 0;
                func_L01_004450F0((s32)obj, 1, -1);
            } else {
                func_L01_004F50C8(obj + 0x10, obj + 0xF0, 116, 1);
                func_L01_003EB438(0, &D_L07_001DE560, &D_L07_001DE570, 0, 0, 0);
                func_L01_004450F0((s32)obj, 9, -1);
            }
        }
        break;
    case 9:
        if (D_L07_001DED50 <= 0.0f) {
            D_L07_001DED50 = 0.0f;
            func_003A0EC0(3, 1, 17, 0, 0);
        } else D_L07_001DED50 -= 0.12000000476837158f;
        break;
    case 10:
        if ((D_00142C30[0] & 0x10000) && !func_L01_004BA800()) {
            p[0x38] = 0;
            func_L07_003C0F40(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003C0710 */
