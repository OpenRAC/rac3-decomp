/* functional: high. RC2 CBC encrypt/decrypt over a buffer with chaining vector (RC2_cbc_encrypt shape); retail is -O0 style byte macros, C written with loops: same bytes in/out, same calls to the block functions, same partial-block handling. */
extern void func_L39_004E6030(u64 *data, void *schedule);
extern void func_L39_004E7E58(u64 *data, void *schedule);

void func_L39_004E52B0(u8 *in, u8 *out, long length, void *schedule, u8 *iv, s32 enc) {
    u64 tin0, tin1;
    u64 tout0, tout1;
    u64 xor0, xor1;
    u64 tin[2];
    long l;
    s32 i;
    s32 n;

    l = length;
    if (enc) {
        tout0 = iv[0] | ((u64)iv[1] << 8) | ((u64)iv[2] << 16) | ((u64)iv[3] << 24);
        tout1 = iv[4] | ((u64)iv[5] << 8) | ((u64)iv[6] << 16) | ((u64)iv[7] << 24);
        for (l -= 8; l >= 0; l -= 8) {
            tin0 = in[0] | ((u64)in[1] << 8) | ((u64)in[2] << 16) | ((u64)in[3] << 24);
            tin1 = in[4] | ((u64)in[5] << 8) | ((u64)in[6] << 16) | ((u64)in[7] << 24);
            in += 8;
            tin[0] = tin0 ^ tout0;
            tin[1] = tin1 ^ tout1;
            func_L39_004E6030(tin, schedule);
            tout0 = tin[0];
            tout1 = tin[1];
            for (i = 0; i < 4; i++) {
                out[i] = (u8)(tout0 >> (8 * i));
                out[4 + i] = (u8)(tout1 >> (8 * i));
            }
            out += 8;
        }
        if (l != -8) {
            /* last partial block of l + 8 bytes, zero padded */
            n = (s32)l + 8;
            tin0 = 0;
            tin1 = 0;
            for (i = 0; i < n; i++) {
                if (i < 4) {
                    tin0 |= (u64)in[i] << (8 * i);
                } else {
                    tin1 |= (u64)in[i] << (8 * (i - 4));
                }
            }
            tin[0] = tin0 ^ tout0;
            tin[1] = tin1 ^ tout1;
            func_L39_004E6030(tin, schedule);
            tout0 = tin[0];
            tout1 = tin[1];
            for (i = 0; i < 4; i++) {
                out[i] = (u8)(tout0 >> (8 * i));
                out[4 + i] = (u8)(tout1 >> (8 * i));
            }
        }
        for (i = 0; i < 4; i++) {
            iv[i] = (u8)(tout0 >> (8 * i));
            iv[4 + i] = (u8)(tout1 >> (8 * i));
        }
    } else {
        xor0 = iv[0] | ((u64)iv[1] << 8) | ((u64)iv[2] << 16) | ((u64)iv[3] << 24);
        xor1 = iv[4] | ((u64)iv[5] << 8) | ((u64)iv[6] << 16) | ((u64)iv[7] << 24);
        for (l -= 8; l >= 0; l -= 8) {
            tin0 = in[0] | ((u64)in[1] << 8) | ((u64)in[2] << 16) | ((u64)in[3] << 24);
            tin[0] = tin0;
            tin1 = in[4] | ((u64)in[5] << 8) | ((u64)in[6] << 16) | ((u64)in[7] << 24);
            tin[1] = tin1;
            in += 8;
            func_L39_004E7E58(tin, schedule);
            tout0 = xor0 ^ tin[0];
            tout1 = xor1 ^ tin[1];
            for (i = 0; i < 4; i++) {
                out[i] = (u8)(tout0 >> (8 * i));
                out[4 + i] = (u8)(tout1 >> (8 * i));
            }
            out += 8;
            xor0 = tin0;
            xor1 = tin1;
        }
        if (l != -8) {
            tin0 = in[0] | ((u64)in[1] << 8) | ((u64)in[2] << 16) | ((u64)in[3] << 24);
            tin[0] = tin0;
            tin1 = in[4] | ((u64)in[5] << 8) | ((u64)in[6] << 16) | ((u64)in[7] << 24);
            tin[1] = tin1;
            func_L39_004E7E58(tin, schedule);
            tout0 = xor0 ^ tin[0];
            tout1 = xor1 ^ tin[1];
            n = (s32)l + 8;
            for (i = 0; i < n; i++) {
                if (i < 4) {
                    out[i] = (u8)(tout0 >> (8 * i));
                } else {
                    out[i] = (u8)(tout1 >> (8 * (i - 4)));
                }
            }
            xor0 = tin0;
            xor1 = tin1;
        }
        for (i = 0; i < 4; i++) {
            iv[i] = (u8)(xor0 >> (8 * i));
            iv[4 + i] = (u8)(xor1 >> (8 * i));
        }
    }
}
