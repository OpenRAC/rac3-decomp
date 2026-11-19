/* functional: medium. 297 diff words: register/stack layout (retail frame 0x40 vs 0x50) and the 8-byte decrypt loop as a static helper; read of every branch done against the .s (types 5/7 join the same path; 6 and 8 identical except stack slots). Dead decrypt bytes sp[4..7] kept as retail leaves them in the later message. */
typedef int q128_00620638 __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
extern u8 *D_L39_0024CE20[] __attribute__((section(".sdata")));
extern u8 D_L39_00352940[];
extern void func_L39_00662B18(void *, void *, s32);
extern u8 *func_00382348(void *);
extern void func_L01_00511158(void *, void *, void *, f32);
extern void func_L39_00629290(void *);
extern void func_L39_00628760(void *);
extern void func_L39_0057B4C0(s32, s32);
extern s32 func_L39_00648840(void *, s32);
extern void func_L39_00648960(void *, s32);
extern s32 func_L39_0051DB38(void *, void *, s32);
extern s32 func_L39_00556448(void *, void *, s32);
extern s32 func_L39_00672118(s32);
extern void func_L39_00629550(void *, void *);

static u32 dec_00620638(u32 *buf, u8 *p) {
    u32 n = *p;
    if (n != 0) {
        u8 *b = (u8 *)buf;
        s32 k = ((s32)p - (s32)n) & 7;
        s32 j;
        for (j = 0; j < 8; j++) {
            b[j] = D_L39_004997E0[n + 1 + ((k + j * 5) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
    }
    return n;
}

void func_L39_00620638(u8 *obj, u32 *stream) {
    q128_00620638 qbuf;
    u8 sb[8];
    u8 *sp = (u8 *)&qbuf;
    u32 type = stream[0] & 0xF;
    u8 *r;
    u8 *p;
    s32 v;

    if (type == 6) {
        func_L39_00662B18(stream, &sb[2], 1);
        func_L39_00662B18(stream, &sb[3], 1);
        r = func_00382348(*(void **)(obj + 0x2524));
        if (r) {
            r[0xE] = 1;
        }
        p = *(u8 **)(obj + 0x2458);
        if (p) {
            v = sb[2] ? 2 : (sb[3] ? 3 : 1);
            *(s32 *)(*(u8 **)(p + 0x68) + 0x84) = v;
        }
        *(u8 **)(obj + 0x2458) = 0;
        return;
    }
    if (type == 8) {
        func_L39_00662B18(stream, &sb[4], 1);
        func_L39_00662B18(stream, &sb[5], 1);
        r = func_00382348(*(void **)(obj + 0x2524));
        if (r) {
            r[0xE] = 1;
        }
        p = *(u8 **)(obj + 0x2458);
        if (p) {
            v = sb[4] ? 2 : (sb[5] ? 3 : 1);
            *(s32 *)(*(u8 **)(p + 0x68) + 0x84) = v;
        }
        *(u8 **)(obj + 0x2458) = 0;
        return;
    }
    if (type == 5 || type == 7) {
        u32 n = dec_00620638((u32 *)sp, obj + 0x19E6);
        s32 skip = 0;
        s32 i;
        u32 base;
        u8 *obj2;
        u8 *cnt;

        if (n == 0x14) {
            return;
        }
        if (*(u8 **)(obj + 0x2530) != 0 && (*(u8 **)(obj + 0x2530))[0x27B] != 0) {
            n = dec_00620638((u32 *)sp, obj + 0x19E4);
            if (n == 0x31) {
                skip = 1;
            }
        }
        if (skip) {
            return;
        }
        func_L39_00662B18(stream, &sb[0], 1);
        func_L39_00662B18(stream, &sb[1], 1);
        r = func_00382348(*(void **)(obj + 0x2524));
        r[0xE] = 3;
        if (obj[0x1A14] != 0) {
            q128_00620638 saved = *(q128_00620638 *)(obj + 0xA0);
            qbuf = saved;
            func_L01_00511158(obj, obj + 0xA0, obj + 0xA0, 0.7f);
            func_L39_00629290(obj);
            *(q128_00620638 *)(obj + 0xA0) = qbuf;
        }
        func_L39_00628760(obj);
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(obj + 0x14) + 0x34))(obj, 0x31, 1, 0, 1);
        (*(u8 **)(obj + 0x2530))[0x27B] = 1;
        obj[0x1A06] = 0;
        *(s32 *)(obj + 0x2450) = 0;
        if (obj[0x1A14] != 0) {
            func_L39_0057B4C0(obj[0x24C9], 1);
        }
        obj[0x1A0A] = 1;
        *(s32 *)(obj + 0xB0) = 0;
        *(s32 *)(obj + 0xB4) = 0;
        base = stream[1] + (stream[0] >> 13) + sb[1] * 1000;
        if ((stream[0] & 0xF) == 5) {
            if (func_L39_00648840(obj, 0x18) == 0) {
                func_L39_00648960(obj, 0x18);
            }
            *(s32 *)(obj + 0x2458) = func_L39_0051DB38(*(void **)(obj + 0x2524), obj, base);
        } else {
            if (func_L39_00648840(obj, 0x17) == 0) {
                func_L39_00648960(obj, 0x17);
            }
            *(s32 *)(obj + 0x2458) = func_L39_00556448(*(void **)(obj + 0x2524), obj, base);
        }
        r = func_00382348(*(void **)(obj + 0x2524));
        if (r) {
            r[0xE] = 3;
        }
        i = func_L39_00672118(9);
        cnt = D_L39_00352940 + 0x7A + *(s32 *)(obj + 0x2544) * 0x24 + i * 4;
        *(u16 *)cnt = *(u16 *)cnt + 1;
        if (sb[0] == 0xFF) {
            return;
        }
        cnt = D_L39_00352940 + 0x78 + sb[0] * 0x24 + i * 4;
        *(u16 *)cnt = *(u16 *)cnt + 1;
        obj2 = D_L39_0024CE20[sb[0]];
        if (obj2 == 0) {
            return;
        }
        if (obj2[0x1A14] == 0) {
            return;
        }
        sp[1] = 0x39;
        sp[2] = obj[0x2544];
        sp[3] = 9;
        *(s32 *)(sp + 8) = *(s32 *)obj2;
        sp[0] = obj2[0x2544];
        func_L39_00629550(obj2, sp);
    }
}
