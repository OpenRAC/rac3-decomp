/* functional: high. NTSC draft adapted to PAL (addresses, callees, key table D_L40_002410C0, hash D_L40_00247EC8 all re-read); retail shares one stack buffer across the three counter updates and zero_ reads its stale upper half, kept via one shared buf; 338 diff (layout) */
/* localdecomp:start func_L40_00434418 */
typedef union { u8 b[8]; u16 h[4]; u32 w[2]; } B_434418;
typedef struct { s32 a, valid; s16 item; u8 kind, pad; } E_434418;
typedef struct {
    s32 pad0, stamp, last, player;
    u8 pad10[0x20]; s32 values[8]; u8 flags[8]; E_434418 entries[8];
} P_434418;
extern s32 D_001A5CD0[];
extern s32 D_001A6A80[];
extern u8 D_L40_00240410, D_L40_00240418, D_L40_00240420;
__asm__(".extern D_L40_00240410, 16");
__asm__(".extern D_L40_00240418, 16");
__asm__(".extern D_L40_00240420, 16");
extern u8 D_L40_002410C0[];
extern u8 D_001D59B0_sda;
extern u32 D_L40_00247EC8;
__asm__(".extern D_L40_00247EC8, 16");
extern u8 D_L40_00247B48[];
extern void func_L39_00662B18(void *, void *, s32);
extern s32 func_L40_00449B20(s32);
extern s32 func_L40_0044A430(s32);
extern void *func_0011D534(void *, s32, s32);
extern void func_00196208(void);
extern void func_L01_00436660(void *, s32, s32);

/* encrypted byte counter: 8 bytes scattered in D_L40_002410C0, keyed by the counter's own address */
static __inline__ u32 get_434418(u8 *q, B_434418 *buf) {
    s32 n, k, m, i;
    u8 *d;
    u32 a;
    if (*q == 0) return 0;
    n = *q; k = ((u32)q - n) & 7; m = n + 1; d = buf->b;
    for (i = 0; i < 40; i += 5) *d++ = D_L40_002410C0[((k + i) & 7) * 4 + m];
    buf->w[0] ^= (u32)q;
    buf->w[1] ^= buf->w[0];
    a = buf->w[1] >> 16;
    buf->w[1] ^= a;
    buf->w[1] = ~(buf->w[1] | a);
    return buf->w[1];
}

static __inline__ void set_434418(u8 *q, u32 value, B_434418 *buf) {
    u32 hk = (u32)q;
    u32 key;
    s32 k, m, i, t;
    u8 *d;
    if (*q == 0) {
        *q = D_001D59B0_sda = D_L40_002410C0[0] + 1;
    } else {
        t = *q; *q = D_L40_002410C0[1]; D_L40_002410C0[1] = t;
    }
    key = ((u32 *)D_L40_002410C0)[(hk * D_L40_00247EC8) & 7];
    k = ((u32)q - *q) & 7;
    buf->w[0] = (u32)q ^ key;
    value = ~value;
    buf->w[1] = ((value & 0xFFFF) | (value << 16)) ^ key;
    m = *q + 1; d = buf->b;
    for (i = 0; i < 40; i += 5) D_L40_002410C0[((k + i) & 7) * 4 + m] = *d++;
}

static __inline__ void zero_434418(u8 *q, B_434418 *buf) {
    u32 hk = (u32)q;
    u32 key;
    s32 k, m, i, t;
    u8 *d;
    if (*q == 0) {
        *q = D_001D59B0_sda = D_L40_002410C0[0] + 1;
    } else {
        t = *q; *q = D_L40_002410C0[1]; D_L40_002410C0[1] = t;
    }
    key = ((u32 *)D_L40_002410C0)[(hk * D_L40_00247EC8) & 7];
    k = ((u32)q - *q) & 7;
    buf->b[4] = 0;
    buf->w[0] = (u32)q ^ key;
    buf->w[1] = ((buf->w[1] & 0xFFFF) | (buf->w[1] << 16)) ^ key;
    m = *q + 1; d = buf->b;
    for (i = 0; i < 24; i += 3) D_L40_002410C0[((k + i) & 7) * 4 + m] = *d++;
}

void func_L40_00434418(u8 *m, s32 *msg) {
    u8 b[16];
    s32 item, value;
    P_434418 *p = *(P_434418 **)(m + 0x68);
    s32 state = msg[0] & 15;
    s32 index, result;
    B_434418 buf;
    if (state == 1) {
        func_L39_00662B18(msg, &value, 4);
        p->values[((u32)msg[0] >> 10) & 7] = value;
        p->flags[((u32)msg[0] >> 10) & 7] = 1;
    } else if (state == 0) {
        index = (u32)msg[0] >> 10;
        func_L39_00662B18(msg, &item, 4);
        index &= 7;
        func_L39_00662B18(msg, b, 1);
        p->stamp = msg[1] + ((u32)msg[0] >> 13);
        if (index != D_001A5CD0[2]) {
            if (!b[0]) result = func_L40_00449B20(item);
            else result = func_L40_0044A430(item);
            if (result) {
                func_0011D534(&p->entries[index], 0, 12);
                p->entries[index].a = 0;
                p->entries[index].valid = 1;
                p->entries[index].item = result;
                p->entries[index].kind = b[0];
            }
            p->player = index;
            p->last = D_001A5CD0[0x128 / 4];
        }
    } else if (state == 2) {
        set_434418(&D_L40_00240410, get_434418(&D_L40_00240410, &buf) + 1, &buf);
        set_434418(&D_L40_00240418, get_434418(&D_L40_00240418, &buf) + 1, &buf);
        zero_434418(&D_L40_00240420, &buf);
        func_00196208();
        if (D_001A6A80[2]) func_L01_00436660(D_L40_00247B48, 500, 0);
    }
}
/* localdecomp:end func_L40_00434418 */
