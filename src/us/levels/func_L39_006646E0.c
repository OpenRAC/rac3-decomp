#include "common.h"

/* NTSC-U counterpart of func_L39_00666FB8 (src/levels/shared/L39_00666F88.c): only the addresses differ (the core global at 0x1A5E50) */
/* localdecomp:start func_L39_006646E0 */
extern s32 D_L39_00246378;
extern char D_L39_00337800[];
#include "vu0.h"
typedef int Q_006646E0 __attribute__((mode(TI)));
typedef struct {
    s32 w0;
    u8 pad4[0x10];
    void *w14;
    u8 pad18[8];
    Q_006646E0 q20;
    u8 pad30[0x110 - 0x30];
    void *w110;
    u8 pad114[0x1F0 - 0x114];
    Q_006646E0 q1F0, q200;
    u8 pad210[0x230 - 0x210];
    Q_006646E0 q230, q240, q250, q260;
    u8 pad270[0x290 - 0x270];
    Q_006646E0 q290, q2A0, q2B0, q2C0;
    s32 w2D0;
    u8 pad2D4[0x2E0 - 0x2D4];
    s32 w2E0;
    u8 pad2E4[0x2F4 - 0x2E4];
    s32 w2F4, w2F8;
    s16 h2FC;
    u8 pad2FE[0x304 - 0x2FE];
    s16 h304;
    u8 pad306[0x314 - 0x306];
    f32 f314;
    s32 w318;
    u8 pad31C[0x340 - 0x31C];
} O_006646E0;
typedef struct { u8 pad[0x10]; Q_006646E0 q10; u8 pad20[0xB2 - 0x20]; u16 hB2; u8 padB4[0xF0 - 0xB4]; Q_006646E0 qF0; } A_006646E0;
typedef struct { u8 pad[0x28]; } T_006646E0;
typedef struct { u8 pad[0x128]; s32 w128; } G_006646E0;
extern char D_L39_002463A0_006646E0[] __attribute__((section(".sdata")));
extern T_006646E0 D_L39_0049C880[];
extern G_006646E0 D_001A5E50;
extern void func_L39_0061C568(void *, void *, s32);
O_006646E0 *func_L39_006646E0(s32 a0, A_006646E0 *a1, u32 a2, s32 a3, s32 a4, f32 f)
{
  O_006646E0 *o;
  s32 n = D_L39_00246378;
  s32 id;
  o = (O_006646E0 *)(n * sizeof(O_006646E0));
  o = (O_006646E0 *)((char *)o + (u32)D_L39_00337800);
  o->w14 = D_L39_002463A0_006646E0;
  o->f314 = f;
  o->h2FC = a0;
  id = n + 1;
  id |= 0x3000000;
  o->w0 = id;
  o->w2D0 = (s32) a1;
  o->h304 = a1->hB2;
  o->w2F4 = a3;
  o->w2F8 = a4;
  o->q290 = a1->q10;
  o->q2A0 = a1->qF0;
  o->q250 = a1->q10;
  o->q260 = a1->qF0;
  o->w110 = &D_L39_0049C880[a0];
  o->q1F0 = a1->q10;
  o->q200 = a1->qF0;
  o->q230 = a1->q10;
  o->q240 = a1->qF0;
  o->w318 = 0;
  qzero(&o->q2B0);
  qzero(&o->q2C0);
  o->w2E0 = D_001A5E50.w128;
  func_L39_0061C568(&o->q20, &a1->q10, D_001A5E50.w128);
  D_L39_00246378 = D_L39_00246378 + 1;
  return o;
}
/* localdecomp:end func_L39_006646E0 */
