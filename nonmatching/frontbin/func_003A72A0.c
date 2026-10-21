/* Near miss of func_003A72A0 with its file's own flags: tools/check.py reports 20 diff
   (the US draft it started from: 59).
   What differs: 20 diff left (was 59): retail materialises the float constant 0.63f inline as
   `lui $at,0x3f21 / ori $at,$at,0x47ae / mtc1 $at,$f0` and stores it with `swc1`, but with
   this file's flags (default ee-as, split addresses) gcc 2.95.3 puts float constants in a
   .lit4 pool (`lwc1 $f0,-0x4000($gp)`) and only builds them inline for FP arithmetic, so plain
   C can at best give `lui/ori` + an integer `sw` of the same bits (1 word short, no
   mtc1/sw_c1); the other difference is that gcc splits the lui/addiu pair of the D_001D9BD0
   base and pulls its lui into the preceding loop's branch delay slot,...
*/

/* US draft of func_003A72A0 (rac3-uya-decomp func_003A1E48, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A72A0 */
typedef struct { u8 p0[0x24]; s32 f24; u8 p28[0x44]; s32 f6C; u8 p70[6]; u16 f76; u8 p78[0x1C]; s32 f94; u8 p98[6]; u16 f9E; } S_3A1E48a;
typedef struct { u8 p0[0xC]; u8 bC; u8 pD[0x3B]; s32 f48[1]; } S_3A1E48c;
typedef struct { u8 p0[0x24]; S_3A1E48c *f24; } S_3A1E48d;
typedef struct { u8 p0[0x44]; s16 n44; u8 p46[0x15A]; S_3A1E48d *e[1]; } S_3A1E48b;
typedef struct { u8 p0[0x34]; u16 h34; } S_3A1E48e;
extern S_3A1E48a D_001CCFD0_003A72A0;
extern u8 D_00225900_003A72A0[];
extern S_3A1E48b D_00225700_003A72A0;
extern u8 D_001A4BE0_003A72A0[];
/* Unsized alias: retail reaches this table through lui/addiu, not $gp. */
extern s32 D_001D9BD0_003A72A0[];
extern void func_0038A238(s32);
extern s32 func_003A4288(void);
extern s32 func_12C908(s32);
extern s32 func_13B620(void);
extern void func_003873C0();
extern void func_003C2880(s32 p);
void func_003A72A0(void) {
    s32 i;
    if ((u16)(D_001CCFD0_003A72A0.f76 - 6) >= 2) D_001CCFD0_003A72A0.f76 = 5;
    if ((u16)(D_001CCFD0_003A72A0.f9E - 6) >= 2) D_001CCFD0_003A72A0.f9E = 5;
    func_0038A238(0xC);
    while (D_001CCFD0_003A72A0.f6C != 0 || D_001CCFD0_003A72A0.f24 != -1 || D_001CCFD0_003A72A0.f94 != 0) {
        func_003A4288();
        func_12C908(0);
    }
    while (func_13B620() != 0) {
    }
    {
    s32 j;
    /* Retail reaches these three through lui/lo, not $gp: a literal address keeps
       gcc from putting them in small data. */
    *(s32 *)0x1D9BDC = 0;
    *(s32 *)0x1D9BE0 = 0;
    for (j = 0; j >= 0; j--) D_001D9BD0_003A72A0[j] = 0;
    }
    {
    u8 *q = D_00225900_003A72A0;
    /* 0.63f = 0x3F2147AE: retail builds the constant inline (lui/ori/mtc1). */
    union { u32 i; f32 f; } bits;
    bits.i = 0x3F2147AE;
    *(f32 *)(q + 0xB0) = bits.f;
    }
    func_003873C0();
    for (i = 0; i < D_00225700_003A72A0.n44; i++) {
        S_3A1E48d *p = D_00225700_003A72A0.e[i];
        if (p) {
            p->f24->bC--;
            p->f24->f48[p->f24->bC] = 0;
            func_003C2880((s32)p);
            D_00225700_003A72A0.e[i] = 0;
        }
    }
    {
        u8 *q = D_001A4BE0_003A72A0;
        if (*(s32 *)(q + 0x12A0)) {
            func_003C2880(*(s32 *)(q + 0x12A0));
            *(s32 *)(q + 0x12A0) = 0;
        }
    }
    {
        S_3A1E48e *e = *(S_3A1E48e **)0x1D9DD8;
        if (e) e->h34 &= ~1;
    }
}
/* localdecomp:end func_003A72A0 */
