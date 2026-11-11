#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* localdecomp:start func_L39_006A5F30 */
typedef struct S_006A5F30 {
    s32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7[0x11];
} S_006A5F30;

typedef struct G_006A5F30 {
    s32 f0;
    s32 f4;
    u8 pad8[0x160];
    u8 f168;
    u8 pad169[0x4DB];
    s32 f644[8];
    struct { u8 b; u8 pad[3]; } f664[8];
} G_006A5F30;

extern G_006A5F30 D_001A5CD0;
extern s32 D_L39_00241640;
extern s32 D_L39_00240640;
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_006A5F30(void) {
    S_006A5F30 s;
    s32 i;

    if (D_L39_00241640 != 0) {
        if (D_001A5CD0.f168 != 0) {
            for (i = 0; i < 7; i++) {
                s32 *p = &D_001A5CD0.f644[i];

                if (*p != -1) {
                    s.f6 = *(u8 *)(p + 8);
                    s.f0 = 0;
                    s.f5 = 0;
                    s.f4 = 0;
                    func_0014AD08(0x50, D_001A5CD0.f4, *p, D_L39_00240640, 0x20, &s);
                    *p = -1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006A5F30 */
