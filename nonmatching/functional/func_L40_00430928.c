/* functional: high. PAL near-miss draft re-read against asm: found and fixed an inverted test (active = decoded==0x31, draft had it reversed); all branches, decode loops, globals and offsets checked */
/* localdecomp:start func_L40_00430928 */
typedef unsigned int Q_00430928 __attribute__((mode(TI)));
extern u8 *D_L40_00241640;
extern u8 *D_L40_00249330[];
extern u8 D_L40_003BFE20[];
extern u8 *D_L40_00248500;
extern u8 *D_L40_0024845C;
extern s32 *D_L40_00357470 __attribute__((section(".data")));
extern f32 D_001DC2C0_sda;
__asm__(".extern D_001DC2C0_sda, 4");
__asm__(".extern D_L40_00241640, 16");
__asm__(".extern D_L40_00248500, 16");
__asm__(".extern D_L40_0024845C, 16");
__asm__(".extern D_L40_00357470, 16");
void func_L40_00430928(u8 *m) {
    extern void func_003C2880(void);
    extern u8 *func_L39_0066C828(void *, s32, s32);
    extern void func_0038D308(void *, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L40_00430170(void *);
    extern void func_L40_00430198(void *);
    extern s32 func_L40_004300D8(void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern s32 func_L40_004305B0(void *);
    extern void func_L40_00430100(void *, s32, s32);
    extern s32 func_00381FF0(s32);
    extern void func_L01_00436660(s32, s32, s32);
    union { Q_00430928 q; u32 w[4]; f32 f[4]; } local;
    u8 *s = *(u8 **)(m + 0x68);
    u8 *p, *r;
    s32 i, flag;
    s32 mode = *(s32 *)(D_L40_00241640 + 0x180);
    f32 distance;
    if (mode != 1) {
        func_003C2880();
        return;
    }
    switch (m[0x20]) {
    case 0:
        r = func_L39_0066C828(m, -1, 1);
        flag = 0;
        if (*(s16 *)(m + 0xAA) == 0x1C2F) flag = mode;
        *(s16 *)(s + 0x16) = 0;
        *(s16 *)(s + 0x14) = flag;
        *(s32 *)(r + 0x28) = flag;
        m[0x30] = 0xFF;
        *(Q_00430928 *)s = *(Q_00430928 *)(m + 0x10);
        *(Q_00430928 *)(s + 0x20) = *(Q_00430928 *)(m + 0xF0);
        *(s32 *)(s + 0x10) = -1;
        *(u16 *)(m + 0x34) |= 0x100;
        local.q = *(Q_00430928 *)(s + 0x20);
        local.f[1] += -1.5707964f;
        func_0038D308(m + 0xC0, &local);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1: {
        u8 **pp;
        i = 7;
        pp = D_L40_00249330;
        for (; i >= 0; i--, pp++) {
            u8 *player = *pp;
            if (player && *(u8 **)(player + 0x251C) == m) *(u8 **)(player + 0x251C) = 0;
        }
        break;
    }
    case 2:
        p = D_L40_00249330[*(s32 *)(s + 0x10)];
        if (p == 0) {
            if (!func_L40_00430170(m)) func_L40_00430198(m);
            return;
        }
        if (!p[0x1A14]) return;
        if (!func_L40_00430170(m)) {
            u8 active;
            s32 decoded;
            {
                u8 *enc = p + 0x19E6;
                s32 result = 0;
                if (*enc) {
                    u32 n = *enc + 1;
                    u32 start = ((u32)enc - *enc) & 7;
                    u8 *out = (u8 *)&local;
                    s32 j = 0;
                    do {
                        *out++ = D_L40_003BFE20[n + ((start + j) & 7) * 255];
                        j += 5;
                    } while (j < 40);
                    local.w[0] ^= (u32)enc;
                    local.w[1] ^= local.w[0];
                    result = local.w[1];
                }
                decoded = result;
            }
            if ((decoded ^ 0x14) == 0) goto reset;
            {
                u8 *enc = p + 0x19E4;
                s32 result = 0;
                if (*enc) {
                    u32 n = *enc + 1;
                    u32 start = ((u32)enc - *enc) & 7;
                    u8 *out = (u8 *)&local;
                    s32 j = 0;
                    do {
                        *out++ = D_L40_003BFE20[n + ((start + j) & 7) * 255];
                        j += 5;
                    } while (j < 40);
                    local.w[0] ^= (u32)enc;
                    local.w[1] ^= local.w[0];
                    result = local.w[1];
                }
                decoded = result;
            }
            if ((decoded ^ 0x7A) == 0) goto reset;
            active = 0;
            if (*(u8 **)(p + 0x2530) && (*(u8 **)(p + 0x2530))[0x27B]) {
{
                u8 *enc = p + 0x19E4;
                s32 result = 0;
                if (*enc) {
                    u32 n = *enc + 1;
                    u32 start = ((u32)enc - *enc) & 7;
                    u8 *out = (u8 *)&local;
                    s32 j = 0;
                    do {
                        *out++ = D_L40_003BFE20[n + ((start + j) & 7) * 255];
                        j += 5;
                    } while (j < 40);
                    local.w[0] ^= (u32)enc;
                    local.w[1] ^= local.w[0];
                    result = local.w[1];
                }
                decoded = result;
            }
                if ((decoded ^ 0x31) == 0) active = 1; else active = 0;
            }
            if (active || !*(u8 **)(p + 0x251C) ||
                (*(u8 **)(p + 0x2528) && *(u8 **)(*(u8 **)(p + 0x2528) + 0x2D8) == p)) {
reset:
                func_L40_00430198(m);
            }
        }
        if (func_L40_004300D8(m)) return;
        distance = D_001DC2C0_sda * D_001DC2C0_sda;
        if (func_L01_0040E548(m + 0x10, D_L40_00248500 + (*(s32 *)(s + 0x18) << 7) + 0x30) < distance) {
            if (*(s16 *)(s + 0x14) == 0) r = D_L40_0024845C + (D_L40_00357470[1] << 8);
            else r = D_L40_0024845C + (D_L40_00357470[0] << 8);
            if (*(s8 *)(D_L40_00241640 + 0x196) == 1 || func_L40_004305B0(r)) {
                func_L40_00430100(m, 1, s[0x10]);
            } else {
                p = D_L40_00249330[*(s32 *)(s + 0x10)];
                if (p && p[0x1A14]) func_L01_00436660(func_00381FF0(0x1709), -1, p[0x24C9]);
            }
        }
        break;
    }
}
/* localdecomp:end func_L40_00430928 */
