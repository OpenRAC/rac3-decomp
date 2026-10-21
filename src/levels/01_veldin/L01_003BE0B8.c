#include "common.h"

/* localdecomp:start func_L01_003BE0B8 */
/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */
typedef struct { s32 w0; f32 f4; s32 w8; f32 fc; s32 w10; s32 w14; u8 pad18[0x60 - 0x18]; f32 f60; f32 f64; } SrcData;
typedef struct {
    u8 pad0[0x2f0]; s32 w2f0; f32 f2f4; s32 w2f8;
    u8 pad2fc[0x320 - 0x2fc]; s32 w320;
    u8 pad324[0x334 - 0x324]; f32 f334; f32 f338;
} DstData;
typedef struct { u8 pad0[0x43]; u8 b43; } X;
extern void func_003C3A10(void *, s32, s32, s32);
void func_L01_003BE0B8(void *a0, SrcData *a1) {
    SrcData *s;
    DstData *d;
    s = *(SrcData **)((u8 *)a1 + 0x68);
    d = *(DstData **)((u8 *)a0 + 0x68);
    d->w2f0 = s->w0;
    if (s->f4 > 0.0f) d->f2f4 = s->f4;
    d->w2f8 = s->w8;
    if (s->fc > 0.0f) d->f2f4 = s->fc;
    d->w320 = s->w14;
    if (s->f60 > 0.0f) d->f334 = s->f60;
    else d->f334 = 15.0f;
    if (s->f64 > 0.0f) d->f338 = s->f64;
    else d->f338 = 100.0f;
    if (((X *)a0)->b43 != 1) func_003C3A10(a0, 1, 0, 0);
}
/* localdecomp:end func_L01_003BE0B8 */
