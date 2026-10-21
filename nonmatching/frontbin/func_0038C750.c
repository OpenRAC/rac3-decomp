/* Near miss of func_0038C750 with its file's own flags: tools/check.py reports 58 diff
   (the version it replaces: 123).
   What differs: 58 diffs, all inside the accesses to D_001D9D1C / D_001DA050: retail emits
   `lui $X,%hi(S)` + `lw $X,%lo(S)($X)` (hi part coalesced into the load's destination) and
   `lui $at,%hi(S)` + `sw $v,%lo(S)($at)`, ours emits `lui $Y,%hi(S)` + `lw $X,%lo(S)($Y)` /
   `sw $v,%lo(S)($Y)`, i.e. the same two-instruction form but with a separate scratch register
   for the hi part (and a slightly different lui schedule); retail's pairs are SN Ps2EeAs
   expanding %gp_rel of sized scalars (which the default assembler keeps gp-relative), so the C
   has to make the compiler emit %hi/%lo itself - done via per-access...
*/

/* US draft of func_0038C750 (rac3-uya-decomp func_00388018, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0038C750 */
typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
__asm__(".extern D_001D5880, 4");
extern f32 D_001D5880;
extern s32 D_001D9D1C_0038C750_a[];
extern s32 D_001D9D1C_0038C750_b[];
extern S_388018 D_00225900_0038C750;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_0038D2D0_0038C750(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_003A9338(s32, u32);
extern void func_003A9740(void);
extern s32 D_001DA050_0038C750_a[];
extern s32 D_001DA050_0038C750_b[];
extern s32 D_001DA050_0038C750_c[];
extern s32 D_001DA050_0038C750_d[];
extern s32 D_001DA050_0038C750_e[];
extern s32 D_001DA050_0038C750_f[];
extern s32 D_001DA050_0038C750_g[];
void func_0038C750(void) {
    f32 m[12];
    f32 v[4];
    u8 *p;
    u8 *q;
    u8 *d;
    S_388018 *s;
    func_0038D2D0_0038C750(m, 1024.0f);
    func_0038CE20(v, D_00222400, -1024.0f);
    v[3] = 1.0f;
    if (D_001D9D1C_0038C750_a[0] != 8) {
        func_003A9338((s32)D_0010F500, D_0010F4F0[0]);
        D_001D9D1C_0038C750_b[0] = 8;
    }
    *(s32 *)(D_001DA050_0038C750_a[0] + 0) = 0x10000000;
    *(s32 *)(D_001DA050_0038C750_b[0] + 4) = 0;
    *(s32 *)(D_001DA050_0038C750_c[0] + 8) = 0x11000000;
    *(s32 *)(D_001DA050_0038C750_d[0] + 0xC) = 0x1000404;
    p = (u8 *)D_001DA050_0038C750_e[0];
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x1C) = 0x6C0C43A4;
    q = p + 0x20;
    func_0038D640(q, (u8 *)D_00222400 - 0x100, m);
    *(f32 *)(q + 0x38) += D_001D5880;
    q = p + 0x60;
    func_0038D640(q, (u8 *)D_00222400 - 0x80, m);
    *(f32 *)(q + 0x38) += D_001D5880;
    s = &D_00225900_0038C750;
    *(s32 *)(p + 0xA0) = 0x8000;
    *(s32 *)(p + 0xA4) = 0x303EC000;
    *(s32 *)(p + 0xA8) = 0x412;
    *(f32 *)(p + 0xAC) = s->f220;
    *(u128_t *)(p + 0xB0) = s->q190;
    *(u128_t *)(p + 0xC0) = s->q1A0;
    *(f32 *)(p + 0xD0) = s->f23C;
    *(f32 *)(p + 0xD4) = s->f238;
    *(s32 *)(p + 0xE0) = 0x3000000;
    *(s32 *)(p + 0xE4) = 0x20001D2;
    *(s32 *)(p + 0xE8) = 0x15000000;
    *(s32 *)(p + 0xD8) = 0;
    *(s32 *)(p + 0xDC) = 0;
    *(s32 *)(p + 0xEC) = 0;
    q = p + 0xF0;
    d = (u8 *)D_001DA050_0038C750_f[0];
    *(s32 *)d |= ((q - d) >> 4) - 1;
    D_001DA050_0038C750_g[0] = (s32)q;
    D_001D5330[2] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    D_001D5330[4] = (long)s->f240 | ((long)s->f244 << 16) | ((long)s->f248 << 32) | ((long)s->f24C << 48);
    func_003A9740();
}
/* localdecomp:end func_0038C750 */
