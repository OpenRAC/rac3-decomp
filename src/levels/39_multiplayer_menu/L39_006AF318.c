#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

/* localdecomp:start func_L39_006AF318 */
typedef struct {
    u8 pad0[0x1C];
    void (*f1C)(void *, s32, s32);
    u8 pad20[0x40 - 0x20];
    void (*f40)(void *, s32);
    u8 pad44[0xB8 - 0x44];
    void (*fB8)(void *, s32);
    u8 padBC[0xC0 - 0xBC];
    void (*fC0)(void *, u8 *);
} VT_006AF318;
typedef struct {
    u8 pad0[0x60];
    VT_006AF318 *vt;
} OBJ_006AF318;
typedef struct {
    u8 pad0[0x54];
    void *f54;
} G_006AF318;
__asm__(".extern D_L39_0024D760, 16");
extern G_006AF318 *D_L39_0024D760;
extern s32 func_00381FF0(s32);
extern void func_L01_0040FDE0(s32);
extern void func_L39_0067F100(s32);
extern void func_L39_0068A9B8(s32);
extern void func_L39_00689BD8(void *, s32);
extern void func_L39_00689D28(void *, s32);
extern void func_L39_00689DB8(void *, s32);
extern void func_L39_00689E58(void *, s32, u32, f32, f32);
extern void func_L39_00689B80(void *);
extern void func_L39_0068A6D0(void *, s32, f32, f32, f32, f32, u32);
extern void func_L39_0068A7B8(void *, s32, u32, f32, f32, f32, f32);
extern void func_L39_0068AAB8(void *);
extern u8 *func_L39_006DDE00(void *, s32);
extern s32 func_00120884(u8 *);

void func_L39_006AF318(u8 *self) {
    OBJ_006AF318 *obj;
    u8 *text;
    s32 len;
    s32 i;

    func_L01_0040FDE0(0);
    func_L39_0067F100(0x350000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(self, func_00381FF0(0xFFA));
    func_L39_00689D28(self, func_00381FF0(0x1399));
    func_L39_00689E58(self, func_00381FF0(0x1924), 0x706EC8FF, 0.7f, 1.0f);
    func_L39_00689DB8(self, func_00381FF0(0x139A));
    func_L39_00689B80(self);
    func_L39_0068A6D0(self, 0, 0.5f, 0.235f, 0.82f, 0.185f, 0x332299DE);
    func_L39_0068A6D0(self, 1, 0.5f, 0.6f, 0.82f, 0.52f, 0x332299DE);
    func_L39_0068A7B8(self, 0, 0x331465B7, 0.5f, 0.36000004f, 0.48f, 0.78f);
    func_L39_0068AAB8(self);
    obj = *(OBJ_006AF318 **)(self + 0x114);
    obj->vt->fB8(*(OBJ_006AF318 **)(self + 0x114), func_00381FF0(0x117C));
    (*(OBJ_006AF318 **)(self + 0x114))->vt->f1C(*(OBJ_006AF318 **)(self + 0x114), 2, 0);
    (*(OBJ_006AF318 **)(self + 0x114))->vt->f40(*(OBJ_006AF318 **)(self + 0x114), 1);
    text = func_L39_006DDE00(D_L39_0024D760->f54, 0);
    if (text != 0) {
        len = func_00120884(text);
        for (i = 0; i < len; i++) {
            if (text[i + 1] == '\n') {
                text[i] = ' ';
                text[i + 1] = 1;
                i++;
            }
        }
        (*(OBJ_006AF318 **)(self + 0x114))->vt->fC0(*(OBJ_006AF318 **)(self + 0x114), text);
    }
    *(s32 *)(self + 0x2A8) = 0;
}
/* localdecomp:end func_L39_006AF318 */
