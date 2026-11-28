/* func_L30_00357570 (Claude wave 14 retry r82, 2026-11-28). Replaces the earlier draft of this function (Codex wave 7 near miss). */
#include "common.h"
/* PAL near miss (wave 14 retry r82): 9 diffs with the file's line and the injected divs row 'func_L30_00357570 2'
 * (r67's near measures 27 there). Changed against r67: (1) two callee return types follow their matched definitions,
 * s32 func_L30_00359980(u8 *) (L30_00359980.c) and s32 func_L30_004CF4B0(s32, s32) (L30_004CF4B0.c), so those calls
 * set $v0 (27 -> 23); (2) case 4 computes the record index into its own local before the range test,
 * slot = D_001D545C + 44 (found with the permuter): sched1 then issues the add before D - 30, D dies at the sub and
 * the registers are retail's ($v0 D, $v1 slot, $a1 the address; 23 -> 9). Still differs (case 5, quad copy at the
 * join): retail materialises D_L30_001E2240 before D_001A4BE0 (s3) and loads the quad into $a1; here the D_001A4BE0
 * lui wins the sched2 tie (one more forward dependence: E1440's lui reuses $v1) and the quad goes to $a0, which also
 * changes the beqz delay-slot filler (lui $v1, 0x1a instead of lui $v0, 0x1e). Has a jump table: the level build
 * must confirm it. */
/* PAL near miss (wave 14, r67): 27 diffs with the file's line (now @ps2as) and an injected divs row 'func_L30_00357570 2'
 * (the previous draft measures 32 there, 200 without the row). Fixed against it: four callees were the wrong catalogue
 * twins of the empty 8-byte stubs / the 44-byte stub, whose level-30 places are not the ones retail calls:
 * case 1 D==35 is func_L01_004D8BB0 (L30 0x00359870), case 0 mode!=6 is func_L01_003B0F18 (0x00359EF8), case 0 D==30
 * is func_L01_004D8A68 (0x00359048), case 6 D==36 is func_L01_004E27A0 (0x00359A00); and D_001A4BE0.value is read into a
 * local before the quad copy (case 5 registers now retail's:  for D_L30_001E2240,  for D_001A4BE0).
 * Still differs: (1) case 4: retail computes D+44 into  before the range test with D in  (the sub reuses D's
 * register); here D stays in  and the sum lands in the beqz delay slot (6 forms tried: n before the test, a local g,
 * n-74 test, pointer local, n += 44 inside); (2) case 5's two  loads get / swapped (4 orders/locals tried);
 * (3) the two lui's of the quad copy are in swapped order. */
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
    s32 slot;
    void func_L30_0035B758(Moby_00357570 *);
    void func_L30_00358258(Moby_00357570 *);
    void func_L30_00358210(Moby_00357570 *);
    void func_L01_003EA9B8(Moby_00357570 *);
    void func_L01_003EDD80(Moby_00357570 *);
    void func_L01_003EE640(Moby_00357570 *);
    void func_L01_004D8BB0(Moby_00357570 *);
    void func_L30_00359A08(Moby_00357570 *);
    void func_L30_00358380(Moby_00357570 *);
    void func_L01_003B0F18(Moby_00357570 *);
    void func_L01_004D8A68(Moby_00357570 *);
    void func_L30_003593A0(Moby_00357570 *);
    void func_L30_003595C0(Moby_00357570 *);
    void func_L30_003596E8(Moby_00357570 *);
    void func_L30_00359808(Moby_00357570 *);
    s32 func_L30_00359980(Moby_00357570 *);
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
    void func_L01_004E27A0(Moby_00357570 *);
    void func_L30_00359D78(Moby_00357570 *);
    void func_L30_00358A18(Moby_00357570 *);
    void func_L30_00358DA8(Moby_00357570 *);
    s32 func_L01_004561B8(Moby_00357570 *);
    s32 func_0038CAD0(s32 *);
    void func_L30_0034D088(s32,s32,s32);
    void func_0038A238(s32);
    s32 func_L30_00358360(Moby_00357570 *);
    extern void func_L30_00357B88(void *);
    s32 func_L30_004CF4B0(s32,s32);
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
        if (D_001D545C == 35) func_L01_004D8BB0(m);
        if (D_001D545C == 36) func_L30_00359A08(m);
        break;
    case 2:
        D_001A66D8[0] = 1;
        func_L30_0034D088(0,d->score,36000);
        break;
    case 0:
        func_L30_00358380(m);
        if (m->mode != 6) func_L01_003B0F18(m);
        if (D_001D545C == 30) func_L01_004D8A68(m);
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
        slot = D_001D545C + 44;
        if ((u32)(D_001D545C - 30) < 6) {
            if (D_001426E0[slot] < d->score)
                D_001426E0[slot] = d->score;
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
        {
            f32 v0 = D_001A4BE0.value;
            *(Q_00357570 *)D_L30_001E1440 = *(Q_00357570 *)D_L30_001E2240;
            D_L30_001E1444 = v0;
        }
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
        else if (D_001D545C == 36) { func_L01_004E27A0(m); func_L30_00359D78(m); }
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
