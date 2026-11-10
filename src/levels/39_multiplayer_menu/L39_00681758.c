#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* localdecomp:start func_L39_00681758 */
extern u8 D_L39_0047BA80[];
extern S_00683550 *func_L39_0067EE40(void *, void *);
extern void func_00120D28(s32, s32, s32);

typedef struct {
    u8 pad0[0x48];
    s32 f48;
    s32 *f4C;
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    f32 f64;
} Src_00681758;

void *func_L39_00681758(u8 *self, Src_00681758 *src) {
    s32 i;

    func_L39_0067EE40(self, src);
    *(void **)(self + 0x60) = D_L39_0047BA80;
    *(s32 *)(self + 0x10170) = -1;
    *(s32 *)(self + 0x10174) = -1;
    *(s32 *)(self + 0x10178) = -1;
    *(s32 *)(self + 0x64) = src->f48;
    if (src->f64 > 0.0f) {
        *(s32 *)(self + 0x48) = 1;
    }
    *(f32 *)(self + 0x4C) = src->f64;
    *(f32 *)(self + 0x105A0) = 1.0f;
    if (*(s32 *)(self + 0x64) > 0x100) {
        *(s32 *)(self + 0x64) = 0x100;
    }
    for (i = 0; i < *(s32 *)(self + 0x64); i++) {
        if (src->f4C[i] != 0) {
            func_00120D28((s32)(self + 0x68 + i * 0x100), src->f4C[i], 0x100);
            self[0x68 + i * 0x100 + 0xFF] = 0;
        } else {
            self[0x68 + i * 0x100] = 0;
        }
    }
    if (src->f50 != 0) {
        func_00120D28((s32)(self + 0x10068), src->f50, 0x100);
    } else {
        self[0x10068] = 0;
    }
    *(s32 *)(self + 0x1057C) = src->f54;
    *(s32 *)(self + 0x10168) = src->f58;
    *(s32 *)(self + 0x10580) = src->f5C;
    self[0x10584] = 0;
    self[0x10585] = 0;
    *(s32 *)(self + 0x1059C) = src->f60;
    return self;
}
/* localdecomp:end func_L39_00681758 */
