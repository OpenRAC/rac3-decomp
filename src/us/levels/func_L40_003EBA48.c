#include "common.h"

/* NTSC-U counterpart of func_L40_003EBEA0 (src/levels/shared/L40_003EBB98.c) */
extern s32 D_001A5F78[];
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);

/* localdecomp:start func_L40_003EBA48 */
extern s32 D_L40_002412AC;
extern s32 D_001A5F78[];
extern s32 func_L40_0053BEB0(s32, void *, s32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_L40_0053B8F8(void *, s32, s32, s32, f32, f32, f32);
extern u8 *func_L39_0061AA60(s32);
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32,s32,s32,s32,u8 *);
void func_L40_003EBA48(u8 *m) {
    u8 *v, *net, *p, *q, *msg;
    s32 uid, selected, valid;
    f32 pos[4];
    if (!m) return;
    net = *(u8 **)(m + 0x90);
    uid = *(s32 *)net;
    v = *(u8 **)(m + 0x68);
    if ((D_L40_002412AC & 8) != (((s32)m >> 8) & 8)) return;
    selected = -1;
    valid = 0;
    if (*(s32 *)(v + 0x2B0) == -1) goto choose;
    {
        if (func_L40_0053BEB0(*(s32 *)(v + 0x2B0), pos, -1, 0)) {
            if (func_00388800(m + 0x10, pos) < *(f32 *)(v + 0x244) * 3.5f) {
                selected = *(s32 *)(v + 0x2B0);
                valid = 1;
            }
            if (m[0x20] == 1 && *(u16 *)(m + 0x96) > 300) valid = 0;
        }
    }
    if (!valid) {
choose:
        selected = func_L40_0053B8F8(m, *(s32 *)(v + 0x2AC), 0, 0, *(f32 *)(v + 0x244) * 3.0f, -1.0f, 3.0f);
    }
    if (selected == -1) return;
    p = func_L39_0061AA60(selected);
    if (p && (p[3] & 15) == 0) {
        q = *(u8 **)(p + 0x2528);
        if (q && *(s16 *)(*(u8 **)(q + 0x2D0) + 0xAA) == 0x107E) selected = -1;
    }
    if (selected != -1 && *(s32 *)(v + 0x2B0) != selected) {
        msg = func_L39_006699B0();
        if (msg) {
            s32 n = func_L39_00669978(1, uid, D_001A5F78[0] + 500, selected, msg);
            *(s32 *)(v + 0x2B0) = selected;
            *(s32 *)msg = n;
        }
    }
}
/* localdecomp:end func_L40_003EBA48 */
