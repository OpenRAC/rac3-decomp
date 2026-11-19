/* functional: high. Retail layout differs only in register allocation (181 differing instruction positions at L01); switch cases 0..5 of jump table (case 0 and >=6 give 0) read from the L02 copy of the table. */
extern u8 D_L01_001E2480_003F22D8[];
extern float func_0038D098(float);

s32 func_L01_003F22D8(s32 *out, u8 *ent) {
    s32 A[2];
    s32 B[2];
    s32 C[2];
    s32 count = 0;
    s32 grp = 0;
    s32 i;
    s32 k;
    if (ent != 0) {
        if (ent[0x557] == 0xFF) {
            return 0;
        }
        grp = ent[0x54C] * 4 + ent[0x557];
    }
    for (i = 1; i >= 0; i--) {
        A[1 - i] = 0;
        B[1 - i] = 0;
        out[1 - i] = 0;
        C[1 - i] = 0;
    }
    for (i = 0; i < 8; i++) {
        u8 *p = D_L01_001E2480_003F22D8 + grp * 128 + i * 16;
        s32 val;
        s32 rem;
        s32 phase;
        s32 idx;
        s32 *dst;
        if (p[0] == 0) continue;
        count++;
        if (p[1] == 0) {
            u16 life = *(u16 *)(p + 6);
            *(u16 *)(p + 6) = life - 1;
            if ((s16)life <= 0) {
                p[0] = 0;
            }
        }
        if (*(s16 *)(p + 4) != 0) {
            *(s16 *)(p + 4) = *(s16 *)(p + 4) - 1;
            continue;
        }
        phase = *(u16 *)(p + 8) + 1;
        rem = (s16)phase % (*(s16 *)(p + 0xA) + *(s16 *)(p + 0xC));
        *(u16 *)(p + 8) = phase;
        val = 0;
        switch (p[0]) {
        case 0:
            break;
        case 1:
            if (rem < *(s16 *)(p + 0xA)) val = p[0xE] + p[0xF];
            else val = p[0xF];
            break;
        case 2:
            if (rem < *(s16 *)(p + 0xA)) {
                val = p[0xE] * rem / *(s16 *)(p + 0xA) + p[0xF];
            } else {
                val = p[0xE] * (*(s16 *)(p + 0xC) + *(s16 *)(p + 0xA) - rem) / *(s16 *)(p + 0xC) + p[0xF];
            }
            break;
        case 3:
            if (rem < *(s16 *)(p + 0xA)) {
                val = p[0xE] * rem / *(s16 *)(p + 0xA) + p[0xF];
            }
            break;
        case 4:
            if (rem >= *(s16 *)(p + 0xA)) {
                val = p[0xE] * (*(s16 *)(p + 0xC) + *(s16 *)(p + 0xA) - rem) / *(s16 *)(p + 0xC) + p[0xF];
            }
            break;
        case 5: {
            float arg, f, e;
            if (rem < *(s16 *)(p + 0xC)) {
                arg = (float)rem * 3.1415927f / (float)*(s16 *)(p + 0xC);
            } else {
                arg = 3.1415927f - (float)(rem - *(s16 *)(p + 0xC)) * 3.1415927f / (float)*(s16 *)(p + 0xA);
            }
            f = func_0038D098(arg);
            e = (float)p[0xE];
            val = (s32)((f * e + e) * 0.5f) + p[0xF];
            if (val >= 0x100) val = 0xFF;
            break;
        }
        default:
            break;
        }
        idx = p[2];
        if (p[3] != 0) {
            A[idx] += val;
            B[idx]++;
        } else {
            out[idx] += val;
            C[idx]++;
        }
    }
    for (k = 1; k >= 0; k--) {
        s32 *o = &out[1 - k];
        s32 *a = &A[1 - k];
        s32 *b = &B[1 - k];
        s32 *c = &C[1 - k];
        if (*c != 0) {
            *o = *o / *c;
        }
        if (*b != 0) {
            s32 q = *a / *b;
            s32 ov = *o;
            *a = q;
            *o = ov * q / 0xFF;
        }
    }
    return count;
}
