/* func_L39_00673EF0: near miss (Opus L39 Sets, 2026-11-08). Adds weapon id to the first free slot of an
   8-byte protected list (pool D_L39_00483A00, stride 0xD1), 672 bytes, 15 places, file
   src/levels/shared/L39_00672828.c. Uses Ent_00673B68 from func_L39_00673B68 in the same file (context).
   Stock checker 21 rows; aligned 88.1% exact, 98.8% opcodes. SetB matches (key; k; b[4] = v; w[0]; w[1]).
   Left: (1) in both DecB loops retail loads 0xD1 into a register before the table base (t4/t1 swapped
   here); index forms D[x*209 + m], D[m + x*209], a 2-D array and (D + m)[x] all give this order.
   (2) the second loop's DecB reads *q twice in retail (`lbu $v1, ($a3); beqz $v1; move $v0, $zero;
   lbu $v0, ($a3)`), the first loop once with a copy; continue/while/break forms and an
   `if (*q != 0) {...} return 0` DecB variant did not reproduce it. */
typedef union Buf_00673EF0 {
    u8 b[8];
    u32 w[2];
} Buf_00673EF0;

extern u8 D_L39_00483A00[];
extern u8 D_L39_00483A01[];
extern u32 D_L39_0024B9C8;
extern Ent_00673B68 D_L39_0049C890[];

static inline u8 DecB_00673EF0(u8 *q) {
    Buf_00673EF0 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.b[4];
}

static inline void SetB_00673EF0(u8 *q, u8 v) {
    u8 *hk = q;
    Buf_00673EF0 buf;
    u32 key;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        *q = ++D_L39_00483A00[0];
    } else {
        s32 t = *q;
        *q = D_L39_00483A01[0];
        D_L39_00483A01[0] = t;
    }
    key = ((u32 *)D_L39_00483A00)[((u32)hk * D_L39_0024B9C8) % 418];
    k = ((u32)q - *q) & 7;
    buf.b[4] = v;
    buf.w[0] = (u32)q ^ key;
    buf.w[1] = ((buf.w[1] & 0xFFFF) | (buf.w[1] << 16)) ^ key;
    m = *q + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        D_L39_00483A00[((k + i) & 7) * 209 + m] = *d++;
    }
}

typedef struct Rec_00673EF0 {
    u8 pad0[0x1A32];
    u8 a1A32[8];
} Rec_00673EF0;

typedef struct Own_00673EF0 {
    u8 pad0[0x368];
    Rec_00673EF0 *p368;
} Own_00673EF0;

void func_L39_00673EF0(Own_00673EF0 *g, s32 id) {
    u8 v;
    s32 i;

    if ((D_L39_0049C890 + id)->b8 == 0) {
        return;
    }
    v = id;
    for (i = 0; i < 8; i++) {
        if (DecB_00673EF0(&g->p368->a1A32[i]) == v) {
            return;
        }
    }
    for (i = 0; i < 8; i++) {
        if (DecB_00673EF0(&g->p368->a1A32[i]) == 0) {
            SetB_00673EF0(&g->p368->a1A32[i], v);
            return;
        }
    }
}
