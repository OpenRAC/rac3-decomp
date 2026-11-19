/* functional: medium. 380 diff words: register/stack layout and scalar code instead of lqc2/sqc2 (file flags have no VU0). Dead decrypts of the +0x19E4/+0x19E7 move descriptors omitted (their only output is a stack buffer overwritten before use); every branch read against the .s. Returns 1 (ok/within range) or -1 (moved too far, clamped when arg1==0xF). */
typedef int q128_0062AE10 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0062AE10;
extern u8 D_L39_004997E0[];
extern q128_0062AE10 D_L39_0025F770[];
extern s32 D_L39_0025F740[];
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00632180(void *, void *, s32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern s32 func_L01_003FC480(void *, s32, void *, f32, f32);
extern s32 func_L01_003FDCA0(void *, s32, f32);

/* decodes the 8 bytes keyed by the field's own address; returns the 16-bit result (0 if the field is empty) */
static u32 dec3_0062AE10(u32 *buf, u8 *p) {
    u32 n = *p;
    u32 x, hi;
    if (n == 0) {
        return 0;
    } else {
        u8 *b = (u8 *)buf;
        s32 k = ((s32)p - (s32)n) & 7;
        s32 j;
        for (j = 0; j < 8; j++) {
            b[j] = D_L39_004997E0[n + 1 + ((k + j * 3) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        x = buf[1] ^ buf[0];
        hi = x >> 16;
        x = ((x ^ hi) << 16) + 1;
        buf[1] = hi / x;
        return buf[1] & 0xFFFF;
    }
}

s32 func_L39_0062AE10(Obj *obj_, s32 arg1) {
    u8 *obj = (u8 *)obj_;
    V4_0062AE10 saved, v10, delta;
    u32 buf[2];
    u8 *pos;
    s32 flag, mask, cnt, r, c;
    u32 m, n;
    f32 z, d;

    pos = obj + 0xA0;
    if (dec3_0062AE10(buf, obj + 0x313) != 0) {
        return 1;
    }
    saved = *(V4_0062AE10 *)pos;
    v10.x = v10.y = v10.z = v10.w = 0.0f;
    d = func_0038CE68(obj + 0x40, obj + 0x250);
    flag = (-0.92f < d) ? 1 : 0;

    m = obj[0x1A06];
    if (m == 0 && *(s16 *)(obj + 0x33E) == 0 && flag == 0) {
        v10.z = *(f32 *)(obj + 0x1E4);
    } else {
        if (m == 1 || *(s16 *)(obj + 0x33E) != 0) {
            z = 0.6f;
        } else {
            z = *(f32 *)(obj + 0x1E4);
        }
        func_L39_00632180(obj, &v10, 0, 0.0f, 0.0f, z);
    }
    ((V4_0062AE10 *)pos)->x += v10.x;
    ((V4_0062AE10 *)pos)->y += v10.y;
    ((V4_0062AE10 *)pos)->z += v10.z;

    /* collision flag mask: 0xD when the move descriptor at +0x19E4 is 0x7E, or 0x90 followed by 0x7E at +0x19E7 */
    c = 0;
    n = obj[0x19E4];
    if (n == 0x7E) {
        c = 0xD;
    } else if (n == 0x90 && obj[0x19E7] == 0x7E) {
        c = 0xD;
    }
    mask = (c << 8) | 0x24;

    cnt = 0;
    do {
        if (m == 0 && flag == 0) {
            f32 f13 = *(f32 *)(obj + 0x1E0) - *(f32 *)(obj + 0x1E4);
            if (f13 < 0.05f) {
                f13 = 0.05f;
            }
            r = func_L01_003FC480(pos, mask, *(void **)(obj + 0x2524), *(f32 *)(obj + 0x1F4), f13);
        } else {
            r = func_L01_003FB640(pos, mask, *(f32 *)(obj + 0x1F4), *(void **)(obj + 0x2524));
        }
        n = obj[0x312] ? dec3_0062AE10((u32 *)&delta, obj + 0x312) : 0;
        if (n == 0) {
            r |= func_L01_003FDCA0(pos, 0, *(f32 *)(obj + 0x1F4));
        }
        if (r == 0) {
            break;
        }
        cnt++;
        *(q128_0062AE10 *)pos = D_L39_0025F770[0];
        *(q128_0062AE10 *)(obj + 0x1C0) = D_L39_0025F770[1];
        obj[0x216] = 1;
        *(q128_0062AE10 *)(obj + 0x1D0) = D_L39_0025F770[-1];
        *(s32 *)(obj + 0x1FC) = D_L39_0025F740[0x18 / 4];
    } while (cnt < 8);

    ((V4_0062AE10 *)pos)->x -= v10.x;
    ((V4_0062AE10 *)pos)->y -= v10.y;
    ((V4_0062AE10 *)pos)->z -= v10.z;
    delta.x = ((V4_0062AE10 *)pos)->x - saved.x;
    delta.y = ((V4_0062AE10 *)pos)->y - saved.y;
    delta.z = ((V4_0062AE10 *)pos)->z - saved.z;
    delta.w = ((V4_0062AE10 *)pos)->w;
    if (*(f32 *)(obj + 0x1F4) * 1.5f < func_0038CEA8(&delta)) {
        if (arg1 != 0xF) {
            return -1;
        }
        if (delta.x > 512.0f) {
            delta.x = 512.0f;
        } else if (delta.x < -512.0f) {
            delta.x = -512.0f;
        }
        if (delta.y > 512.0f) {
            delta.y = 512.0f;
        } else if (delta.y < -512.0f) {
            delta.y = -512.0f;
        }
        if (delta.z > 512.0f) {
            delta.z = 512.0f;
        } else if (delta.z < -512.0f) {
            delta.z = -512.0f;
        }
        func_0038CF68(&delta, &delta, *(f32 *)(obj + 0x1F4));
        ((V4_0062AE10 *)pos)->x = saved.x + delta.x;
        ((V4_0062AE10 *)pos)->y = saved.y + delta.y;
        ((V4_0062AE10 *)pos)->z = saved.z + delta.z;
        ((V4_0062AE10 *)pos)->w = saved.w;
        return -1;
    }
    return 1;
}
