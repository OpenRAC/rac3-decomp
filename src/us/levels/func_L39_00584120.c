#include "common.h"

/* NTSC-U counterpart of func_L39_00584E70 (src/levels/shared/L39_00584698.c) */
typedef struct {
    s32 w[2];
    s32 w8;
    u8 padC[0x1C - 0xC];
    s16 f1C;
    s16 f1E;
    s16 f20;
    s16 f22;
    s16 f24;
    s16 f26;
    s16 f28;
    u8 pad2A[2];
    s32 f2C;
    u8 pad30[0x370 - 0x30];
    s32 f370;
    s32 f374;
    f32 f378;
    f32 f37C;
    s32 f380;
    f32 f384;
    s32 f388;
} S_00584698;
extern S_00584698 D_L39_0025C700;
extern f32 D_L39_0024BAD0;

/* localdecomp:start func_L39_00584120 */
typedef struct {
    u8 pad0[0x18];
    s32 type;
    s32 count;
    u8 pad20[4];
    s32 end;
} T_00584E70;
extern T_00584E70 D_L39_0025CA90[];
extern s32 D_L39_001FC5D4[];
extern s32 D_001D6D80_sda_00584120;
__asm__(".extern D_001D6D80_sda_00584120, 4");
extern void func_L39_005883C8(s32);
extern void func_L39_005FACC0(s32, s32, s32, s32);
extern void func_L01_003FDF60(void);
extern void func_L01_003FDD18(s32, f32);
extern void func_L01_003FD600(s32, f32);
extern void func_00384C98(void);
extern void func_L39_00589FE8(s32, s32, s32, s32);
void func_L39_00584120(void) {
    s32 i;
    s32 a;
    s32 j;
    s32 k;
    s32 b;
    f32 f;
    if (D_L39_0025C700.f26 != 0) {
        func_L39_005883C8(0);
        func_L39_005FACC0(D_L39_0025C700.w[(s16)(D_L39_0025C700.f1C ^ 1)] + 0x10, D_L39_001FC5D4[0], 0x200, 0x1A0);
        func_L01_003FDF60();
        switch (D_L39_0025CA90[D_L39_0025C700.f22].type) {
        case 0:
            for (i = 0; i < D_L39_0025CA90[D_L39_0025C700.f22].count; i++) {
                a = D_L39_0025C700.f2C;
                b = D_001D6D80_sda_00584120;
                if (a < b) {
                    f = (f32)a / (f32)b;
                } else if (D_L39_0025CA90[D_L39_0025C700.f22].end - b < a) {
                    f = (f32)(D_L39_0025CA90[D_L39_0025C700.f22].end - a) / (f32)b;
                } else {
                    f = 1.0f;
                }
                func_L01_003FDD18(i, f);
            }
            break;
        case 1:
        case 2:
            k = 0;
            while (k < D_L39_0025CA90[D_L39_0025C700.f22].count) {
                j = k + 1;
                func_L01_003FD600(k, 1.0f - ((f32)D_L39_0025C700.f2C - (f32)(D_L39_0025CA90[D_L39_0025C700.f22].count - j) * (f32)D_L39_0025C700.f370) / (f32)D_L39_0025C700.f374);
                k = j;
            }
            break;
        }
        func_00384C98();
    }
    func_L39_00589FE8(0, 0, 0, (s32)(D_L39_0024BAD0 * 128.0f));
}
/* localdecomp:end func_L39_00584120 */
