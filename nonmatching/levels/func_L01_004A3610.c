/* Round 23 W5 near miss: loop registers now match retail (s0 = dst, s1 = src via separate dst/src locals set after the memcpy); remaining: retail's `andi $v0,$a1,0xff` after the lbu (QImode pseudo with a zero-extended copy used for the compares and the table index), `addu v0,i,dst` operand order, and the tail's float-load / store scheduling (lwc1 hoisted, f4C/f50 stores swapped) with the file's flags. 91 raw diffs (was 113); check with --no-context. */
#include "common.h"

/* localdecomp:start func_L01_004A3610 */
typedef int u128_004A3610 __attribute__((mode(TI)));
typedef struct {
    s32 valid;
    u8 pad04[0xC];
    u128_004A3610 q10;
    u128_004A3610 q20;
    s32 w30;
    s32 w34;
    s32 w38;
    u8 b3C, b3D, b3E, b3F, b40, b41;
    u8 pad42[2];
    f32 f44, f48, f4C, f50;
    s32 w54;
    s32 w58;
    s32 w5C;
    u8 data60[0x404];
    u8 data464[0x800];
    s32 wC64;
    s32 wC68;
    u8 padC6C[4];
} Ckpt_004A3610;
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    u8 pad25C4[0x25E4 - 0x25C4];
    u8 b25E4;
    u8 pad25E5[0x287A - 0x25E5];
    s16 h287A;
} Hero_004A3610;
typedef struct {
    u8 pad0[0x38];
    s32 w38;
    s32 w3C;
} Sub_004A3610;
typedef struct {
    u8 pad0[0x40];
    u8 b40, b41, b42;
    u8 pad43[0xB4 - 0x43];
    s32 wB4;
} Tab_004A3610;
typedef struct {
    u8 pad0[0x48];
    s16 h48;
} Flg_004A3610;

extern Hero_004A3610 D_001A4BE0;
extern Ckpt_004A3610 D_L01_00236B90;
extern Ckpt_004A3610 D_L01_00237800;
extern Tab_004A3610 D_001A30B0;
extern Flg_004A3610 D_001CCFD0;
extern s32 D_L01_001D545C;
__asm__(".extern D_L01_001D545C, 16");
extern s32 D_L01_001F3F40[];
extern u8 D_L01_001DF9E4;
__asm__(".extern D_L01_001DF9E4, 16");
extern u8 D_L01_001DF9E5;
__asm__(".extern D_L01_001DF9E5, 16");
extern u8 D_L01_001DF9E6;
__asm__(".extern D_L01_001DF9E6, 16");
extern f32 D_L01_001DF9E8;
__asm__(".extern D_L01_001DF9E8, 16");
extern f32 D_L01_001DF9EC;
__asm__(".extern D_L01_001DF9EC, 16");
extern f32 D_L01_001DF9F0;
__asm__(".extern D_L01_001DF9F0, 16");
extern f32 D_L01_001DF9F4;
__asm__(".extern D_L01_001DF9F4, 16");
extern u8 D_001BBC40[];
extern u8 D_001BBE90[];
extern void func_0038CC88(void *, void *, s32);
extern s32 func_0039EC28(s32, s32, void *);

void func_L01_004A3610(u128_004A3610 *a0, u128_004A3610 *a1) {
    s32 i;
    s32 idx;
    u8 b;
    s32 m;
    u8 *p;
    u8 *dst;
    u8 *src;
    Ckpt_004A3610 *s;
    if (D_001A4BE0.b25E4 == 4) {
        return;
    }
    func_0038CC88(D_L01_00237800.data60, D_L01_00236B90.data60, 0x404);
    dst = D_L01_00237800.data60 + 0x404;
    src = D_L01_00236B90.data60 + 0x404;
    idx = D_L01_001D545C;
    m = idx * 16 - 2;
    for (i = 0; i < 0x7FF; i++, src++) {
        b = *src;
        if (b == 0) continue;
        if (b != 1 && (D_001BBC40[b + m] & 0x80) == 0) continue;
        dst[i] = b;
        if (i & 1) {
            p = D_001BBE90 + ((i >> 1) + (idx << 10));
            if (((*p >> 4) & 7) != 7) *p += 0x10;
        } else {
            p = D_001BBE90 + ((i >> 1) + (idx << 10));
            if ((*p & 7) != 7) *p += 1;
        }
    }
    D_L01_00237800.valid = 1;
    s = &D_L01_00237800;
    s->q10 = *a0;
    s->q20 = *a1;
    s->w30 = *(s32 *)(D_001A4BE0.p25C0 + 0x38);
    s->w34 = *(s32 *)(D_001A4BE0.p25C0 + 0x3C);
    s->w54 = D_001A4BE0.b25E4;
    s->w58 = (s32)D_001A4BE0.p25C0;
    s->w5C = D_001A4BE0.h287A;
    s->w38 = D_001A30B0.wB4;
    s->b3C = D_001A30B0.b40;
    s->b3D = D_001A30B0.b41;
    s->b3E = D_001A30B0.b42;
    s->wC64 = D_001CCFD0.h48;
    s->wC68 = D_L01_001F3F40[0];
    s->b3F = D_L01_001DF9E4;
    s->b40 = D_L01_001DF9E5;
    s->b41 = D_L01_001DF9E6;
    s->f44 = D_L01_001DF9E8;
    s->f48 = D_L01_001DF9EC;
    s->f4C = D_L01_001DF9F0;
    s->f50 = D_L01_001DF9F4;
    func_0039EC28(0, -1, s);
}
/* localdecomp:end func_L01_004A3610 */
