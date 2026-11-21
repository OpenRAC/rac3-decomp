/* PAL near miss: 31 aligned rows with --as ps2as (the file's line lacks @ps2as; the default assembler counted 347 at first) plus a divs_nops row `func_L30_00357570 2` (retail has two nops before the one div.s; the draft before had 41 rows with neither: the row alone took it from 39 to 31 together with the changes below). Needs both for the count: `@ps2as` on the file's text_parts line, and the row. The file's other block func_L30_00357B88 (C) has to be re-checked with @ps2as when this lands. Contains a `switch` (jump table): the level build has to confirm it.
 * What moved it from 41: `.extern X, 4` hints for the three $gp names, func_L30_00357B88 called with m (its C takes an unused pointer), `u32 v` for the shifted score bytes, a scalar `f32 D_L30_001E1444` with `.extern D_L30_001E1444, 16` (retail's `lui $at; swc1 f0, 0x1444($at)`; the array form made `lui $v0; swc1 0x1444($v0)`), `D_00142660.value = 0` as the last of the nine zero stores (the scheduler moves the last store of a group to the front, so retail's order needs it last in the source) and the three byte stores of the score in the order 0x56, 0x55, 0x57.
 * Left (about 31 rows): (1) case 4's `D_001426E0[D_001D545C + 44]` maximum: retail loads D into $v0, computes the +0x2c sum into $v1 BEFORE the range test and reuses $v0 for D-30 (score in $a0, address in $a1); here D is in $a0 and the sum is made in place after the test (13 rows). Tried: `n = D + 44` before the test (the sum lands in the beqz delay slot, D in $v1), `n = D + 44; (u32)(n - 74) < 6` (same, 33), `n = D - 30` with `[n + 74]` (47), `u8 *p` locals, `&&`, `>= 30 && < 36`, a score local, operand order (31-48). (2) the two $gp loads of case 5 (retail `lw $v1, 0x1224($gp)` first, then `lw $v0, 0x1208($gp)`: the pair is swapped here; locals and a swapped source order only move the loads). (3) the quad copy: the two lui's and their registers ($v0 = source, $v1 = D_001A4BE0 in retail) and `lq $a1` ($a0 here). */
#include "common.h"
/* localdecomp:start func_L30_00357570 */
typedef int Q_00357570 __attribute__((mode(TI)));
typedef struct State_00357570 {
    u8 pad0[0xD0];
    f32 ratio;
    s32 waiting;
    s32 timer, timer2;
    s32 e0, score;
    u8 padE8[0x50];
    void *buffer;
    s32 countdown;
} State_00357570;
typedef struct Moby_00357570 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x47];
    State_00357570 *data;
    u8 pad6C[0x28];
    u8 mode;
} Moby_00357570;
typedef struct Save_00357570 {
    u8 pad0[0x60];
    s32 a,b,c,d;
    u16 time, value;
    u8 e,f,g;
} Save_00357570;
typedef struct Stats_00357570 {
    u8 pad0[0x84];
    f32 value;
    u8 pad88[0x1A8C];
    s32 score, time, code;
} Stats_00357570;
extern s32 D_001D545C;
extern s32 D_L30_001E1428;
__asm__(".extern D_L30_001E1428, 16");
__asm__(".extern D_001DDAD4_sda, 4");
__asm__(".extern D_001DDAB8_sda, 4");
__asm__(".extern D_001DDADC_sda, 4");
extern s32 D_001A66D8[];
extern u8 D_001426E0[];
extern Save_00357570 D_00142660;
extern u8 D_001A71D2[];
extern s32 D_001DDAD4_sda, D_001DDAB8_sda, D_001DDADC_sda;
extern u8 D_L30_001E2240[], D_L30_001E1440[];
extern f32 D_L30_001E1444;
__asm__(".extern D_L30_001E1444, 16");
extern Stats_00357570 D_001A4BE0;
extern s32 D_L30_002E47F4[];
void func_L30_00357570(Moby_00357570 *m) {
    State_00357570 *d = m->data;
    u32 v;
    s32 n;
    void func_L30_0035B758(Moby_00357570 *);
    void func_L30_00358258(Moby_00357570 *);
    void func_L30_00358210(Moby_00357570 *);
    void func_L01_003EA9B8(Moby_00357570 *);
    void func_L01_003EDD80(Moby_00357570 *);
    void func_L01_003EE640(Moby_00357570 *);
    void func_L01_003F19B0(Moby_00357570 *);
    void func_L30_00359A08(Moby_00357570 *);
    void func_L30_00358380(Moby_00357570 *);
    void func_L01_003609D0(Moby_00357570 *);
    void func_L01_003DF8B8(Moby_00357570 *);
    void func_L30_003593A0(Moby_00357570 *);
    void func_L30_003595C0(Moby_00357570 *);
    void func_L30_003596E8(Moby_00357570 *);
    void func_L30_00359808(Moby_00357570 *);
    void func_L30_00359980(Moby_00357570 *);
    void func_L30_00359E20(Moby_00357570 *);
    void func_L30_003586A8(Moby_00357570 *);
    void func_L30_0035B780(Moby_00357570 *);
    void func_L30_00358618(Moby_00357570 *);
    void func_L01_003B84E8(Moby_00357570 *);
    void func_L01_003D4C00(Moby_00357570 *);
    void func_L01_003E32E8(Moby_00357570 *);
    void func_L30_00359058(Moby_00357570 *);
    void func_L01_003E32F0(Moby_00357570 *);
    void func_L30_00359418(Moby_00357570 *);
    void func_L01_003EBF38(Moby_00357570 *);
    void func_L30_00359648(Moby_00357570 *);
    void func_L01_003EE638(Moby_00357570 *);
    void func_L30_00359760(Moby_00357570 *);
    void func_L01_003EE648(Moby_00357570 *);
    void func_L30_00359878(Moby_00357570 *);
    void func_L01_003F1F08(Moby_00357570 *);
    void func_L30_00359D78(Moby_00357570 *);
    void func_L30_00358A18(Moby_00357570 *);
    void func_L30_00358DA8(Moby_00357570 *);
    s32 func_L01_004561B8(Moby_00357570 *);
    s32 func_0038CAD0(s32 *);
    void func_L30_0034D088(s32,s32,s32);
    void func_0038A238(s32);
    s32 func_L30_00358360(Moby_00357570 *);
    extern void func_L30_00357B88(void *);
    void func_L30_004CF4B0(s32,s32);
    void func_003A1C28(void);
    void func_003A1930(void *,s32,s32);
    void func_L01_00404A10(void (*)(Moby_00357570 *), Moby_00357570 *);
    s32 func_L30_00357C78(s32);
    void func_L22_0041FCC8(s32,s32);
    s32 func_L01_004BA800(void);
    void func_L01_004450F0(Moby_00357570 *,s32,s32);
    switch (m->state) {
    case 1:
        func_L01_004561B8(m);
        func_L30_0035B758(m);
        func_L30_00358258(m);
        if (func_0038CAD0(&d->timer2)) func_L30_00358210(m);
        if (D_001D545C == 32) func_L01_003EA9B8(m);
        if (D_001D545C == 33) func_L01_003EDD80(m);
        if (D_001D545C == 34) func_L01_003EE640(m);
        if (D_001D545C == 35) func_L01_003F19B0(m);
        if (D_001D545C == 36) func_L30_00359A08(m);
        break;
    case 2:
        D_001A66D8[0] = 1;
        func_L30_0034D088(0,d->score,36000);
        break;
    case 0:
        func_L30_00358380(m);
        if (m->mode != 6) func_L01_003609D0(m);
        if (D_001D545C == 30) func_L01_003DF8B8(m);
        if (D_001D545C == 31) func_L30_003593A0(m);
        if (D_001D545C == 32) func_L30_003595C0(m);
        if (D_001D545C == 33) func_L30_003596E8(m);
        if (D_001D545C == 34) func_L30_00359808(m);
        if (D_001D545C == 35) func_L30_00359980(m);
        if (D_001D545C == 36) func_L30_00359E20(m);
        if (d->waiting) func_L01_004450F0(m,7,-1);
        else func_L01_004450F0(m,6,-1);
        break;
    case 4:
        if ((u32)(D_001D545C - 30) < 6) {
            if (D_001426E0[D_001D545C + 44] < d->score)
                D_001426E0[D_001D545C + 44] = d->score;
        }
        D_00142660.e = 0;
        D_00142660.f = 0;
        D_00142660.g = 0;
        D_00142660.d = 0;
        D_00142660.c = 0;
        D_00142660.b = 0;
        D_00142660.a = 0;
        D_00142660.time = 0;
        D_00142660.value = 0;
        func_0038A238(13);
        D_001A71D2[0] = 1;
        break;
    case 5:
        if (func_L01_004561B8(m)) {
            D_L30_001E1428 = func_L30_00358360(m);
            func_L30_00357B88(m);
            func_L30_004CF4B0(116,1);
            d->timer2 = D_001DDAD4_sda;
            d->timer = D_001DDAB8_sda;
            func_003A1C28();
            func_003A1930(d->buffer,0,1024);
        }
        *(Q_00357570 *)D_L30_001E1440 = *(Q_00357570 *)D_L30_001E2240;
        D_L30_001E1444 = D_001A4BE0.value;
        func_0038CAD0(&d->timer2);
        func_0038CAD0(&d->timer);
        d->ratio = 1.0f - (f32)d->timer / (f32)D_001DDAB8_sda;
        func_L01_00404A10(func_L30_00358A18,m);
        if (*(long *)&d->timer == 0) {
            if (D_001D545C == 31) D_001426E0[11] = 1;
            D_001426E0[0x54] |= 1 << (D_001D545C - 30);
            D_001A4BE0.time = func_L30_00358360(m);
            D_001A4BE0.score = d->score;
            D_001A4BE0.code = func_L30_00357C78(d->score);
            v = func_L30_00357C78(D_001A4BE0.score);
            D_001426E0[0x56] = v >> 8;
            D_001426E0[0x55] = v;
            D_001426E0[0x57] = v >> 16;
            if (D_001A4BE0.score >= 100) D_001426E0[0x53] |= 1 << (D_001D545C - 30);
            func_L01_004450F0(m,8,-1);
        }
        break;
    case 6:
        func_L01_004561B8(m);
        if (!D_L30_002E47F4[0]) func_L22_0041FCC8(D_001DDADC_sda,0x341);
        if (!func_0038CAD0(&d->countdown)) func_L01_00404A10(func_L30_00358DA8,m);
        n = D_00142660.time + 1;
        if (n > 35999) n = 35999;
        D_00142660.time = n;
        func_L30_003586A8(m);
        func_L30_0035B780(m);
        func_L30_00358618(m);
        if (D_001D545C == 30) { func_L01_003B84E8(m); func_L01_003D4C00(m); }
        else if (D_001D545C == 31) { func_L01_003E32E8(m); func_L30_00359058(m); }
        else if (D_001D545C == 32) { func_L01_003E32F0(m); func_L30_00359418(m); }
        else if (D_001D545C == 33) { func_L01_003EBF38(m); func_L30_00359648(m); }
        else if (D_001D545C == 34) { func_L01_003EE638(m); func_L30_00359760(m); }
        else if (D_001D545C == 35) { func_L01_003EE648(m); func_L30_00359878(m); }
        else if (D_001D545C == 36) { func_L01_003F1F08(m); func_L30_00359D78(m); }
        D_00142660.value = func_L30_00358360(m);
        break;
    case 7:
        if (!func_L01_004BA800()) {
            d->waiting = 0;
            func_L01_004450F0(m,6,-1);
        }
        break;
    case 8:
        v = func_L30_00358360(m);
        func_L30_0034D088(1,d->score,v);
        break;
    }
}
/* localdecomp:end func_L30_00357570 */
