/* functional: high. 105 diffs (branch layout of the digit loop); behaviour traced instruction by instruction; the 64-bit multiplies are written as (s32)((u64)x*k) to match retail's multu. */
typedef struct Out_0050F358 {
    char pad0[8];
    u16 f8;
    u16 fA;
    s32 fC;
} Out_0050F358;

s32 func_L39_0050F358(Out_0050F358 *out, u8 *str, u32 len, u32 *pos, u32 mode) {
    u32 i = *pos;
    u32 start = i;
    u32 val = 0;
    s32 ret = 0;
    u32 n;
    u32 m;

    if (i < len) {
        do {
            u8 c = str[i];
            if ((u8)(c - '0') < 10) {
                val = val * 10 + (c - '0');
            } else {
                if (c != '+' && c != '-' && c != 'Z') {
                    return 0x804;
                }
                break;
            }
            i++;
        } while (i < len);
    }
    n = i - start;
    if (n >= 7) {
        return 0x804;
    }
    if (n < 6) {
        do {
            val *= 10;
            n++;
        } while (n < 6);
    }
    *pos = i;
    if (mode == 2) {
        m = (s32)((u64)(val % 1000000) * 60);
        out->fA = m / 60;
        out->fC = m % 60;
    } else if (mode < 3) {
        if (mode == 1) {
            m = (s32)((u64)(val % 1000000) * 3600);
            out->f8 = m / 60;
            out->fA = m % 60;
        } else {
            ret = 0x804;
        }
    } else if (mode == 3) {
        out->fC = val;
    } else {
        ret = 0x804;
    }
    return ret;
}
