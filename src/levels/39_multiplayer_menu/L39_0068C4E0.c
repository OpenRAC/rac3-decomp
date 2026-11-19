#include "common.h"

/* localdecomp:start func_L39_0068C4E0 */
typedef struct {
    u8 pad0[0x1D];
    u8 key[0x20];
    u8 name[0x13];
    u8 flags;
    u8 pad51[0x1F0 - 0x51];
} S_0068C4E0;
typedef struct {
    u8 pad0[0x30];
    u8 *p30;
    u8 pad34[0x4];
    u8 *p38;
    u8 pad3C[0x18];
    u8 *p54;
} G_0068C4E0;

extern S_0068C4E0 D_001FC6B0_0068C4E0[];
__asm__(".extern D_L39_0024D760, 16");
extern G_0068C4E0 *D_L39_0024D760;
__asm__(".extern D_001DC204_sda, 4");
extern void *D_001DC204_sda;
extern void func_0011D534(void *, s32, s32);
void func_00120D28(s32, s32, s32);
extern s32 func_00120884(void *);
extern char *func_00381FF0(s32);
extern s32 func_L39_00687450(void *, char *, void *, s32, s32, s32, s32);
extern s32 func_L39_006872E8(void *, s32, char *, s32, s32, f32);
extern void func_L39_00689AC8(void *, char *);
extern s32 func_L39_006CCD08(void *, void *, s32);
extern s32 func_L39_006DE030(void *);
extern s32 func_L39_006CEA18(void *, s32);
extern void func_L39_006D2EF0(void *, s32, s32);
extern void func_L39_0059A660(s32, s32);

s32 func_L39_0068C4E0(u8 *arg0, s32 arg1)
{
    u8 buf[0x11];
    u8 *key = D_001FC6B0_0068C4E0[arg1].key;
    u8 *p;
    s32 r;
    void *ui;

    (*(s32 *)(arg0 + 0x338))++;
    func_0011D534(buf, 0, 0x11);
    if (D_001FC6B0_0068C4E0[arg1].flags & 1) {
        func_00120D28((s32)buf, (s32)D_001FC6B0_0068C4E0[arg1].name, 0x10);
    } else {
        while (!func_00120884(buf)) {
            ui = D_001DC204_sda;
            func_L39_00687450(ui, func_00381FF0(0x1183), buf, 3, 0x11, 0, 0);
            if (!func_00120884(buf)) {
                ui = D_001DC204_sda;
                func_L39_006872E8(ui, 0, func_00381FF0(0x1B9E), 4, 0, 0.6f);
            }
        }
    }
    func_L39_00689AC8(arg0, func_00381FF0(0xF76));
    r = func_L39_006CCD08(D_L39_0024D760->p30, key, (s32)buf);
    do {
        if (r) {
            arg0[0x2B9] = 1;
            func_L39_006DE030(D_L39_0024D760->p54);
            func_L39_006CEA18(D_L39_0024D760->p38, 1);
            p = D_L39_0024D760->p38;
            if (*(s32 *)p >= 0 && p[0x34]) {
                func_L39_006D2EF0(p, -1, -1);
            }
            func_L39_0059A660(arg1, 0);
            func_L39_00689AC8(arg0, func_00381FF0(0xF77));
        } else {
            switch (*(s32 *)(D_L39_0024D760->p30 + 0x6C)) {
            case -0x3E6:
                func_L39_00689AC8(arg0, func_00381FF0(0x12D5));
                break;
            case -0x3D2:
                func_L39_00689AC8(arg0, func_00381FF0(0x12D0));
                break;
            default:
                func_L39_00689AC8(arg0, func_00381FF0(0xF78));
                break;
            }
        }
    } while (0);
    (*(s32 *)(arg0 + 0x338))--;
    return r;
}
/* localdecomp:end func_L39_0068C4E0 */

LINKER_REMNANT("asm/levels", func_L39_0068C708);
