#include "common.h"

/* localdecomp:start func_L39_00677510 */
typedef struct {
    u8 pad0[12];
    s32 f0C;
    u8 pad10[0x30];
    char labels[32][32];
} MenuText;

extern MenuText D_L39_00352DE0;

extern f32 D_L39_0024682C;
__asm__(".extern D_L39_0024682C, 4");
extern f32 D_L39_00246830;
__asm__(".extern D_L39_00246830, 4");
extern f32 D_L39_00246838;
__asm__(".extern D_L39_00246838, 4");
extern f32 D_L39_0024683C;
__asm__(".extern D_L39_0024683C, 4");
extern f32 D_L39_00246860;
__asm__(".extern D_L39_00246860, 4");
extern s32 D_L39_00240480;
extern s32 D_L39_00240484;
void func_L39_00677510(void) {
    extern void func_L01_00410590(unsigned long, char *, s32, f32, f32, f32);
    extern void func_L39_00593950(s32, s32, unsigned long, s32, s32);
    s32 x = (s32)(D_L39_0024683C * (f32)D_L39_00240480);
    s32 w = (s32)((D_L39_0024683C + D_L39_00246830) * (f32)D_L39_00240480);
    f32 top = D_L39_0024682C;
    f32 h = (f32)D_L39_00240484;
    s32 y;
    s32 i;
    i = 0;
    if (D_L39_00352DE0.pad0[0] == 0) {
        y = (s32)((top + D_L39_00246838 * (f32)i) * h);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[21], -1, (f32)x, (f32)y, D_L39_00246860);
        func_L39_00593950(w, y, 0x8066CCFFUL, (s32)D_L39_00352DE0.labels[D_L39_00352DE0.f0C], -1);
    }
    i = 1;
    if (D_L39_00352DE0.pad0[1] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[22], -1, (f32)x, (f32)y, D_L39_00246860);
        func_L39_00593950(w, y, 0x8066CCFFUL, (s32)D_L39_00352DE0.labels[10], -1);
    }
    i = 2;
    if (D_L39_00352DE0.pad0[2] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[23], -1, (f32)x, (f32)y, D_L39_00246860);
        func_L39_00593950(w, y, 0x8066CCFFUL, (s32)D_L39_00352DE0.labels[12], -1);
    }
    i = 3;
    if (D_L39_00352DE0.pad0[3] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[24], -1, (f32)x, (f32)y, D_L39_00246860);
        func_L39_00593950(w, y, 0x8066CCFFUL, (s32)D_L39_00352DE0.labels[11], -1);
    }
    i = 4;
    if (D_L39_00352DE0.pad0[4] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[13], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 5;
    if (D_L39_00352DE0.pad0[5] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[14], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 6;
    if (D_L39_00352DE0.pad0[6] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[15], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 7;
    if (D_L39_00352DE0.pad0[7] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[16], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 8;
    if (D_L39_00352DE0.pad0[8] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[17], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 9;
    if (D_L39_00352DE0.pad0[9] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[18], -1, (f32)x, (f32)y, D_L39_00246860);
    }
    i = 10;
    if (D_L39_00352DE0.pad0[10] == 0) {
        y = (s32)((D_L39_0024682C + D_L39_00246838 * (f32)i) * (f32)D_L39_00240484);
        func_L01_00410590(0x8066CCFFUL, D_L39_00352DE0.labels[19], -1, (f32)x, (f32)y, D_L39_00246860);
    }
}
/* localdecomp:end func_L39_00677510 */
