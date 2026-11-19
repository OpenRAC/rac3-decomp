/* functional: high. No draft; written from asm incl. the buffer not being re-zeroed between lines (kept). 139 diff words scheduling; mode>=2 leaves width unchanged as in retail */
extern s32 D_L01_001D55E8[];
extern void *func_0011A264(void *, s32, s32);
extern void func_0038E150(s32);
extern s32 func_L01_00412708(u8 *, s32);
extern s32 func_L01_00412750(u8 *, s32);

void func_L01_004CDC38(u8 *obj, s32 mode, s32 w, f32 x, f32 y) {
    u8 buf[0x100];
    u8 *p88 = obj + 0x88;
    u8 **table = (u8 **)(obj + 0x1B8);
    s32 maxw = 1;
    s32 n = 0;
    s32 i = 0;
    s32 none = 1;
    s32 saved;

    **(f32 **)(obj + 0x0) = x;
    *(f32 *)(*(u8 **)(obj + 0x0) + 4) = y;
    *(s32 *)(obj + 0x198) = w;
    *(s32 *)(obj + 0x1A4) = mode;
    obj[0x187] = 0;
    *(s32 *)(obj + 0x190) = 1;
    *(s32 *)(obj + 0x1B4) = 0;
    func_0011A264(buf, 0, 0x100);
    func_0011A264(table, 0, 0x78);
    saved = D_L01_001D55E8[0];
    table[*(s32 *)(obj + 0x190) - 1] = p88;
    func_0038E150(1);
    if (obj[0x88] != 0) {
        u8 *cur = p88;
        u8 *next = obj + 0x89;
        u8 c = *cur;
        for (;;) {
            if (c == 1) {
                *cur = 0;
                buf[n] = 0;
                none = 0;
                table[*(s32 *)(obj + 0x190)] = next;
                *(s32 *)(obj + 0x190) = *(s32 *)(obj + 0x190) + 1;
                if (*(s32 *)(obj + 0x1A4) == 1) {
                    maxw = func_L01_00412708(buf, -1);
                } else if (*(s32 *)(obj + 0x1A4) == 0) {
                    maxw = func_L01_00412750(buf, -1);
                }
                n = 0;
                if (*(s32 *)(obj + 0x1B4) < maxw) {
                    *(s32 *)(obj + 0x1B4) = maxw;
                }
            } else {
                buf[n] = c;
                n++;
            }
            i++;
            next++;
            if (i >= 255) break;
            cur++;
            if (*cur == 0) break;
            c = *cur;
        }
    }
    if (none != 0) {
        if (*(s32 *)(obj + 0x1A4) == 1) {
            *(s32 *)(obj + 0x1B4) = func_L01_00412708(buf, -1);
        } else if (*(s32 *)(obj + 0x1A4) == 0) {
            *(s32 *)(obj + 0x1B4) = func_L01_00412750(buf, -1);
        }
    } else {
        if (*(s32 *)(obj + 0x1A4) == 1) {
            maxw = func_L01_00412708(buf, -1);
        } else if (*(s32 *)(obj + 0x1A4) == 0) {
            maxw = func_L01_00412750(buf, -1);
        }
        if (*(s32 *)(obj + 0x1B4) < maxw) {
            *(s32 *)(obj + 0x1B4) = maxw;
        }
    }
    func_0038E150(saved);
    **(f32 **)(obj + 0x4) = 1.0f;
}
