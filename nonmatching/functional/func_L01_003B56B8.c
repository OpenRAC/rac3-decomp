/* functional: medium. Same reads, writes and the final call; retail keeps array bases/limits in registers (larger frame) so allocation differs. Stores to wBC/wB0/wB4/wC8/wCC/wB8 keep retail values. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern void func_L01_004450F0(s32, s32, s32);

void func_L01_003B56B8(u8 *m, u8 *s) {
    s32 *A = (s32 *)(s + 0x100);
    s32 *B = (s32 *)(s + 0xD0);
    s32 *C = (s32 *)(s + 0xE0);
    s32 total = 0;
    s32 sum = 0;
    s32 i;
    s32 idx;
    s32 w;
    u16 *p;
    u8 *n;
    f32 r;

    m[48] = 255;
    w = *(s32 *)(s + 16);
    *(s32 *)(s + 0xBC) = w;
    if (*(s32 *)(s + 48) >= 0) {
        *(s32 *)(s + 0xBC) = w + *(s32 *)(s + 48);
    } else {
        *(s32 *)(s + 0xBC) = -1;
    }
    idx = *(s32 *)(s + 4);
    if (idx != -1) {
        p = D_L01_0021DE20[idx];
        while ((idx & 0xFF) != 255 && idx <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[idx])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            p++;
            total++;
        }
    }
    *(s32 *)(s + 0xB0) = total;
    if (*(s32 *)(s + 8) != -1) {
        total += 1;
    }
    *(s32 *)(s + 0xC8) = 0;
    *(s32 *)(s + 0xCC) = 0;
    *(s32 *)(s + 0xB4) = total;
    for (i = 0; i < 4; i++) {
        A[i] = 0;
        if (B[i] != -1) {
            p = D_L01_0021DE20[B[i]];
            while ((B[i] & 0xFF) != 255 && B[i] <= D_L01_001E0058 && p != 0
                   && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[B[i]])) {
                n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
                if (n == 0) {
                    break;
                }
                A[i] += 1;
                p++;
            }
            sum += A[i];
            if (*(s32 *)(s + 0xC8) < i) {
                B[*(s32 *)(s + 0xC8)] = B[i];
                B[i] = -1;
                A[*(s32 *)(s + 0xC8)] = A[i];
                A[i] = 0;
            }
            *(s32 *)(s + 0xC8) += 1;
        }
        if (C[i] != -1) {
            sum += 1;
            if (*(s32 *)(s + 0xCC) < i) {
                C[*(s32 *)(s + 0xCC)] = C[i];
                C[i] = -1;
            }
            *(s32 *)(s + 0xCC) += 1;
        }
    }
    *(s32 *)(s + 0xB8) = sum;
    if (*(f32 *)(s + 12) < 0.0f) {
        if (sum == 0) {
            *(f32 *)(s + 12) = 1.0f;
        } else {
            r = (f32)total / (f32)(total + sum);
            *(f32 *)(s + 12) = r;
            if (1.0f < r) {
                *(f32 *)(s + 12) = 1.0f;
            } else if (r < 0.0f) {
                *(f32 *)(s + 12) = 0.0f;
            }
        }
    } else if (1.0f < *(f32 *)(s + 12)) {
        *(f32 *)(s + 12) = 1.0f;
    }
    if (*(f32 *)(s + 20) < 0.0f) {
        if (sum == 0) {
            *(f32 *)(s + 20) = 1.0f;
        } else {
            r = (f32)total / (f32)(total + sum);
            *(f32 *)(s + 20) = r;
            if (1.0f < r) {
                *(f32 *)(s + 20) = 1.0f;
            } else if (r < 0.0f) {
                *(f32 *)(s + 20) = 0.0f;
            }
        }
    } else if (1.0f < *(f32 *)(s + 20)) {
        *(f32 *)(s + 20) = 1.0f;
    }
    *(s32 *)(s + 0x78) = 0;
    *(s32 *)(s + 0x54) = 0;
    *(s32 *)(s + 0x58) = 0;
    func_L01_004450F0((s32)m, 1, -1);
}
