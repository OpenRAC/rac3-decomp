/* func_L39_0064EA40: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 33648 bytes (8412 instrs), places: 15 levels (39..53), file: src/levels/shared/L39_0064EA40.c, flags: -O2 -G8
     -fopt-stack -mno-check-zero-division (222 inline float constants: needs @ps2as; the file's flag line has none)
   Step 0: one function (prologue -0xC0, one epilogue jr $ra at 0x656DA8). Switch: `if (cmd < 0x91) switch (cmd)`
     through jtbl_0047AE40, 145 cases, each a big body, then a shared tail. 41 lq/sq (128-bit moves: plain TI C), 0 COP2.
     Signature: s32 f(u8 *g /*$s1*/, u32 cmd /*$s4*/, s32 a2 /*$s7*/, s32 a3, s32 a4 /*sp+0x40*/).
   rac2 twin: none (best opcode 0.087 to func_L11_002D22C8; callfp.out mapped=1/47). It is the multiplayer-menu state
     machine (a command dispatcher) with ~75 inlined anti-tamper get/set copies + ~130 get-loops.
     Prior attempt (GIVEUP, partial draft below): ~/RACSwarm/rac3-api/jobs/func_L39_0064EA40/RESULTS.md.
   Anti-tamper scheme ("protected values"): level 39-53 code (multiplayer menu, 15 places) keeps game-state
     bytes as a 1-byte handle h in the struct; the value lives permuted/XOR-ed in the pool D_L39_004997E0
     (stride 0xFF; D_L39_00480760 stride 0xC1; D_L39_00483A00 stride 0xD1) keyed by D_L39_0024B9C8 * (u32)h % 0x1FE.
     The GET shape that MATCHES retail is the one proven in func_L39_0065D0A0 (landing/queue): see its
     Dec_/Dec2_ helpers: `if (*q==0) return 0; n=*q; k=((u32)q-n)&7; m=n+1; d=buf.b; for (i=0;i<40;i+=5)
     *d++ = pool[m + ((k+i)&7)*255]; a=buf.w[0]^(u32)q; b=buf.w[1]^a;` (32-bit var) and, for u16 vars, step 3,
     i<24, table 00483A00 stride 209 (`pool[((k+i)&7)*209+m]`), `buf.w[1]=(b>>16)/(((b^(b>>16))<<16)+1); return buf.h[2]`.
     Comparisons go through `static inline s32 DecEq(q,v){return Dec(q)==v;}` (xori/beql form). ps2as profile is
     needed for such files' inline float constants.
   Draft: the prior job's partial func.c (compiles; prologue through the first ~480 retail rows; helpers pv_prep/set/get as
     static inline): 8275 diff of 8413 rows because the 145 case bodies are missing. NOT extended by me: the get/set
     helper shapes in it are the older (pre-0065D0A0) ones, replace them with the Dec forms above first.
   Left for Opus: (1) switch to Dec/DecEq/Set shapes from func_L39_0065D0A0 and the Set shape from func_L39_00640738
     (queued draft); (2) mechanical body per case from m2c (m2c fails on the raw-delay-slot words: restore the `.word ..
     /* sq .. */` instructions to text first, see below); (3) split into the 145 case bodies by retail address, check
     them in order; this is a many-hours target: treat it as a family of ~40 recurring idioms, solve each once.
   Tool note: worker w6's scratch had m2c2.py (asm with .word-hidden lq/sq restored and jump tables appended) producing
     4207 lines of m2c for this function; recreate with the recipe: un-hide `.word 0x... /* op args */` into `op args`,
     add `.L<addr>:` labels at every jump-table target, append `glabel jtbl_X` + `.word .L<addr>` rows (entries inside the
     function's address range) from asm/levels/<level>/data/data.data.s.
*/
/* PARTIAL DRAFT (prologue .. call of func_L39_0062CB60 only; the switch dispatch and the
   145 case bodies are not written). See RESULTS.md. */
extern u8 D_L39_004997E0[];
extern u8 D_L39_004997E1[];
extern u32 D_L39_0024B9C8[];

extern s32 func_L39_00637310(void);
extern void func_L39_00635DE8(u8 *g);
extern void func_L01_0044E740(u8 *p);
extern void func_L01_003F1F60(u32 p);
extern void func_L39_0062CB60(u8 *g, u32 a1, u32 v);

/* handle bookkeeping of a protected variable whose handle byte lives at *p */
static __inline__ void pv_prep_0064EA40(u8 *p)
{
    u8 t;
    if (*p == 0) {
        t = D_L39_004997E0[0] + 1;
        D_L39_004997E0[0] = t;
        *p = t;
    } else {
        t = *p;
        *p = D_L39_004997E1[0];
        D_L39_004997E1[0] = t;
    }
}

/* store val (stride 5 variant) */
static __inline__ void pv_set_0064EA40(u8 *p, u32 val)
{
    u32 buf[2];
    u8 *bb = (u8 *)buf;
    u32 idx, k;
    s32 i;

    pv_prep_0064EA40(p);
    idx = *p;
    k = ((u32 *)D_L39_004997E0)[(D_L39_0024B9C8[0] * (u32)p) % 0x1FE];
    buf[1] = val ^ k;
    buf[0] = (u32)p ^ k;
    for (i = 0; i < 40; i += 5) {
        D_L39_004997E0[idx + 1 + ((((u32)p - idx) + i) & 7) * 255] = *bb++;
    }
}

/* load (stride 5 variant), 0 if the handle is unset */
static __inline__ u32 pv_get_0064EA40(u8 *p)
{
    u32 buf[2];
    u8 *bb = (u8 *)buf;
    u32 idx, v = 0;
    s32 i;

    if (*p != 0) {
        idx = *p;
        for (i = 0; i < 40; i += 5) {
            *bb++ = D_L39_004997E0[idx + 1 + ((((u32)p - idx) + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        v = buf[1];
    }
    return v;
}

s32 func_L39_0064EA40(u8 *g, u32 a1, s32 a2, s32 a3, s32 a4)
{
    u32 v, flag;
    u32 s44, s48, s4C, s50, s54;

    if (a3 == 0 && func_L39_00637310() == 0) {
        return 0;
    }
    s44 = *(u32 *)(g + 0x2524);
    func_L39_00635DE8(g);
    pv_prep_0064EA40(g + 0x19E4);
    s54 = a1 < 0x91;
    pv_set_0064EA40(g + 0x19E4, a1);
    if (g[0x19E5] != 0) {
        s48 = pv_get_0064EA40(g + 0x19E5);
    } else {
        s48 = 0;
    }
    pv_set_0064EA40(g + 0x19E5, 0);
    s4C = g[0x1A0E];
    s50 = g[0x1A13];
    if (g[0x1A0A] == 1) {
        g[0x1A0A] = 0;
    }
    g[0x1A0C] = 0;
    g[0x24FE] = 0;
    g[0x24FF] = 0;
    g[0x2500] = 0;
    *(u32 *)(*(u32 *)(g + 0x2524) + 0x9C) = 0;
    /* 0x1A18: stride-3 variant, u8 value 0 (not written here) */
    g[0x1A0E] = 0;
    g[0x1A0B] = 0;
    if (*(u32 *)(g + 0x2D0) != 0) {
        g[0x1A13] = 0;
    }
    func_L01_0044E740(g + 0x1630);
    v = pv_get_0064EA40(g + 0x19E4);
    if (v == 0x66) {
        *(u32 *)(g + 0x13D4) = 0;
    }
    flag = 0;
    if (pv_get_0064EA40(g + 0x19E4) == 1 || pv_get_0064EA40(g + 0x19E4) == 0x1D
        || g[0x24FE] != 0 || g[0x2500] != 0) {
        flag = 1;
    }
    if (flag == 0) {
        g[0x24FD] = 0;
    }
    if (*(s16 *)(g + 0x32E) == 0) {
        func_L01_003F1F60(*(u32 *)(g + 0x2534));
    }
    v = pv_get_0064EA40(g + 0x19E7);
    v = pv_get_0064EA40(g + 0x19E4);
    func_L39_0062CB60(g, 0, v);
    return 0;
}
