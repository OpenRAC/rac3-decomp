/* functional: medium. No draft; written from PAL asm, compiles (219 diff, layout only); func_L01_00451F60 gets the loop counter as 3rd arg (retail leaves it in a2, prototype unknown); rotation helper arg y -= pi/2 done before func_0038D308 */
/* localdecomp:start func_L40_004301D8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *D_L40_00249330[];
extern u8 D_L40_00357260[];
extern s32 D_001A5DF8[];
extern s32 *D_L40_00241120;
extern void func_L39_00662B18(void *, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_0063D240(void *, s32);
extern void func_0038D308(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_L39_005F3488(s32, s32, void *, s32);
extern void func_L01_00451F60(s32, s32, s32);

void func_L40_004301D8(u8 *m, u32 *msg) {
    u8 *pv = *(u8 **)(m + 0x68);
    s32 eff = -1;
    s32 snd = -1;
    s32 flag = 1;
    s32 idx;
    s32 i;
    u8 *e;
    u8 *c;
    u8 b[8] __attribute__((aligned(4)));
    f32 tmp[4] __attribute__((aligned(16)));
    s32 id;

    switch (msg[0] & 0xF) {
    case 0:
        func_L39_00662B18(msg, &id, 4);
        func_L01_004450F0(m, 2, -1);
        *(s32 *)(pv + 0x10) = id;
        e = D_L40_00249330[id];
        if (e != 0) {
            e[0x1A0E] = 1;
            *(u8 **)(e + 0x251C) = m;
        }
        eff = (*(s16 *)(pv + 0x14) == 0) ? 0x1412 : 0x1411;
        snd = 0;
        break;
    case 1:
        func_L39_00662B18(msg, &b[0], 1);
        func_L39_00662B18(msg, &b[1], 1);
        *(u128_t *)(m + 0x10) = *(u128_t *)pv;
        *(u128_t *)(m + 0xF0) = *(u128_t *)(pv + 0x20);
        idx = *(s32 *)(pv + 0x10);
        if (idx >= 0) {
            e = D_L40_00249330[idx];
            if (e != 0) {
                func_L39_0063D240(e, 1);
            }
        }
        *(s32 *)(pv + 0x10) = -1;
        if (b[0] != 0) {
            snd = 3;
            if (b[1] != 0xFF) {
                c = D_L40_00357260 + 0x48 + b[1];
                if (*c < 0xFE) {
                    *c = *c + 1;
                }
            }
            if (*(s16 *)(pv + 0x14) == 0) {
                eff = 0x13D5;
                *(s32 *)(*(u8 **)(D_L40_00357260 + 0x210) + 0xC) += 1;
            } else {
                eff = 0x13D6;
                *(s32 *)(*(u8 **)(D_L40_00357260 + 0x210) + 0x8) += 1;
            }
        } else {
            if (b[1] != 0xFF) {
                snd = 2;
                c = D_L40_00357260 + 0x50 + b[1];
                if (*c < 0xFE) {
                    *c = *c + 1;
                }
            }
            eff = (*(s16 *)(pv + 0x14) == 0) ? 0x1415 : 0x1416;
        }
        *(u128_t *)tmp = *(u128_t *)(pv + 0x20);
        tmp[1] = tmp[1] + -1.5707964f;
        func_0038D308(m + 0xC0, tmp);
        *(s32 *)(pv + 0x1C) = D_001A5DF8[0];
        func_L01_004450F0(m, 1, -1);
        break;
    case 2:
        func_L39_00662B18(msg, tmp, 0x10);
        snd = 1;
        func_L01_004450F0(m, 1, -1);
        *(u128_t *)(m + 0x10) = *(u128_t *)tmp;
        idx = *(s32 *)(pv + 0x10);
        if (idx >= 0) {
            e = D_L40_00249330[idx];
            if (e != 0) {
                func_L39_0063D240(e, 1);
                if (0.99f < func_0038CEA8(*(u8 **)(e + 0x2524) + 0xC0)
                    && 0.99f < func_0038CEA8(*(u8 **)(e + 0x2524) + 0xD0)) {
                    flag = 0;
                    *(u128_t *)(m + 0xC0) = *(u128_t *)(*(u8 **)(e + 0x2524) + 0xE0);
                    *(u128_t *)(m + 0xD0) = *(u128_t *)(*(u8 **)(e + 0x2524) + 0xD0);
                    *(u128_t *)(m + 0xE0) = *(u128_t *)(*(u8 **)(e + 0x2524) + 0xC0);
                }
            }
        }
        eff = (*(s16 *)(pv + 0x14) == 0) ? 0x1414 : 0x1413;
        if (flag != 0) {
            *(u128_t *)tmp = *(u128_t *)(pv + 0x20);
            tmp[1] = tmp[1] + -1.5707964f;
            func_0038D308(m + 0xC0, tmp);
        }
        *(s32 *)(pv + 0x10) = -1;
        *(s32 *)(pv + 0x1C) = D_001A5DF8[0];
        break;
    default:
        break;
    }
    if (snd >= 0) {
        func_L39_005F3488(snd, 0x110, m, 0x1C2F);
    }
    if (eff >= 0 && *D_L40_00241120 > 0) {
        i = 0;
        do {
            func_L01_00451F60(eff, -1, i);
            i++;
        } while (i < *D_L40_00241120);
    }
}
/* localdecomp:end func_L40_004301D8 */
